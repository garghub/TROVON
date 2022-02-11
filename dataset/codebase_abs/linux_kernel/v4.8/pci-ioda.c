void F_1 ( const struct V_1 * V_2 , const char * V_3 ,
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
static inline bool F_11 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
return ( V_28 -> V_29 >= V_26 -> V_30 . V_31 &&
V_28 -> V_29 < ( V_26 -> V_30 . V_31 + V_26 -> V_30 . V_32 ) ) ;
}
static inline bool F_12 ( unsigned long V_33 )
{
unsigned long V_9 = ( V_34 | V_35 ) ;
return ( V_33 & V_9 ) == V_9 ;
}
static struct V_1 * F_13 ( struct V_25 * V_26 , int V_36 )
{
V_26 -> V_30 . V_37 [ V_36 ] . V_26 = V_26 ;
V_26 -> V_30 . V_37 [ V_36 ] . V_21 = V_36 ;
return & V_26 -> V_30 . V_37 [ V_36 ] ;
}
static void F_14 ( struct V_25 * V_26 , int V_36 )
{
if ( ! ( V_36 >= 0 && V_36 < V_26 -> V_30 . V_38 ) ) {
F_15 ( L_7 ,
V_39 , V_36 , V_26 -> V_40 -> V_41 ) ;
return;
}
if ( F_16 ( V_36 , V_26 -> V_30 . V_42 ) )
F_17 ( L_8 ,
V_39 , V_36 , V_26 -> V_40 -> V_41 ) ;
F_13 ( V_26 , V_36 ) ;
}
static struct V_1 * F_18 ( struct V_25 * V_26 )
{
long V_2 ;
for ( V_2 = V_26 -> V_30 . V_38 - 1 ; V_2 >= 0 ; V_2 -- ) {
if ( ! F_16 ( V_2 , V_26 -> V_30 . V_42 ) )
return F_13 ( V_26 , V_2 ) ;
}
return NULL ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_43 = V_2 -> V_21 ;
F_20 ( V_2 -> V_11 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_21 ( V_43 , V_26 -> V_30 . V_42 ) ;
}
static int F_22 ( struct V_25 * V_26 )
{
const char * V_44 ;
struct V_27 * V_28 ;
T_3 V_45 ;
V_45 = F_23 ( V_26 -> V_46 ,
V_47 ,
V_26 -> V_30 . V_48 ,
V_26 -> V_30 . V_31 ,
0 ,
V_26 -> V_30 . V_32 ) ;
if ( V_45 != V_49 ) {
V_44 = L_9 ;
goto V_50;
}
V_45 = F_24 ( V_26 -> V_46 ,
V_47 ,
V_26 -> V_30 . V_48 ,
V_51 ) ;
if ( V_45 != V_49 ) {
V_44 = L_10 ;
goto V_50;
}
V_28 = & V_26 -> V_40 -> V_52 [ 1 ] ;
if ( V_26 -> V_30 . V_53 == 0 )
V_28 -> V_29 += ( 2 * V_26 -> V_30 . V_54 ) ;
else if ( V_26 -> V_30 . V_53 == ( V_26 -> V_30 . V_38 - 1 ) )
V_28 -> V_55 -= ( 2 * V_26 -> V_30 . V_54 ) ;
else
F_15 ( L_11 ,
V_26 -> V_30 . V_53 ) ;
return 0 ;
V_50:
F_15 ( L_12 ,
V_45 , V_44 , V_26 -> V_30 . V_48 ) ;
F_24 ( V_26 -> V_46 ,
V_47 ,
V_26 -> V_30 . V_48 ,
V_56 ) ;
return - V_57 ;
}
static void F_25 ( struct V_58 * V_11 ,
unsigned long * V_59 )
{
struct V_60 * V_40 = F_26 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_27 * V_28 ;
T_4 V_62 , V_63 , V_29 , V_55 ;
int V_64 , V_65 ;
V_62 = V_26 -> V_30 . V_31 ;
V_63 = V_26 -> V_30 . V_54 ;
for ( V_65 = 0 ; V_65 <= V_66 ; V_65 ++ ) {
V_28 = & V_11 -> V_27 [ V_65 ] ;
if ( ! V_28 -> V_67 || ! F_11 ( V_26 , V_28 ) )
continue;
V_29 = F_27 ( V_28 -> V_29 - V_62 , V_63 ) ;
V_55 = F_28 ( V_28 -> V_55 - V_62 , V_63 ) ;
for ( V_64 = V_29 / V_63 ; V_64 < V_55 / V_63 ; V_64 ++ ) {
if ( V_59 )
F_29 ( V_64 , V_59 ) ;
else
F_14 ( V_26 , V_64 ) ;
}
}
}
static int F_30 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
unsigned long V_62 , V_70 = V_26 -> V_30 . V_54 ;
T_5 V_45 ;
V_62 = V_26 -> V_30 . V_31 +
V_68 * V_71 * V_70 ;
V_45 = F_23 ( V_26 -> V_46 ,
V_47 , V_68 , V_62 , 0 ,
V_71 * V_70 ) ;
if ( V_45 != V_49 ) {
F_15 ( L_13 ,
V_45 , V_26 -> V_40 -> V_41 , V_68 ) ;
goto V_50;
}
V_45 = F_24 ( V_26 -> V_46 ,
V_47 , V_68 ,
V_51 ) ;
if ( V_45 != V_49 ) {
F_15 ( L_14 ,
V_45 , V_26 -> V_40 -> V_41 , V_68 ) ;
goto V_50;
}
}
V_28 = & V_26 -> V_40 -> V_52 [ 1 ] ;
if ( V_26 -> V_30 . V_53 == 0 )
V_28 -> V_29 += ( 2 * V_26 -> V_30 . V_54 ) ;
else if ( V_26 -> V_30 . V_53 == ( V_26 -> V_30 . V_38 - 1 ) )
V_28 -> V_55 -= ( 2 * V_26 -> V_30 . V_54 ) ;
else
F_31 ( 1 , L_15 ,
V_26 -> V_30 . V_53 , V_26 -> V_40 -> V_41 ) ;
return 0 ;
V_50:
for ( ; V_68 >= 0 ; V_68 -- )
F_24 ( V_26 -> V_46 ,
V_47 , V_68 , V_56 ) ;
return - V_57 ;
}
static void F_32 ( struct V_72 * V_19 ,
unsigned long * V_59 ,
bool V_73 )
{
struct V_58 * V_11 ;
F_33 (pdev, &bus->devices, bus_list) {
F_25 ( V_11 , V_59 ) ;
if ( V_73 && V_11 -> V_74 )
F_32 ( V_11 -> V_74 ,
V_59 , V_73 ) ;
}
}
static struct V_1 * F_34 ( struct V_72 * V_19 , bool V_73 )
{
struct V_60 * V_40 = F_26 ( V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_1 * V_75 , * V_2 ;
unsigned long V_76 , * V_42 ;
int V_65 ;
if ( F_35 ( V_19 ) )
return NULL ;
V_76 = F_28 ( V_26 -> V_30 . V_38 / 8 , sizeof( unsigned long ) ) ;
V_42 = F_36 ( V_76 , V_77 ) ;
if ( ! V_42 ) {
F_15 ( L_16 ,
V_39 ) ;
return NULL ;
}
F_32 ( V_19 , V_42 , V_73 ) ;
if ( F_37 ( V_42 , V_26 -> V_30 . V_38 ) ) {
F_38 ( V_42 ) ;
return NULL ;
}
V_75 = NULL ;
V_65 = - 1 ;
while ( ( V_65 = F_39 ( V_42 , V_26 -> V_30 . V_38 , V_65 + 1 ) ) <
V_26 -> V_30 . V_38 ) {
V_2 = & V_26 -> V_30 . V_37 [ V_65 ] ;
V_26 -> V_30 . V_78 [ V_2 -> V_21 ] = V_2 -> V_21 ;
if ( ! V_75 ) {
V_2 -> V_9 |= V_79 ;
F_40 ( & V_2 -> V_80 ) ;
V_75 = V_2 ;
} else {
V_2 -> V_9 |= V_81 ;
V_2 -> V_82 = V_75 ;
F_41 ( & V_2 -> V_83 , & V_75 -> V_80 ) ;
}
if ( V_26 -> type == V_84 ) {
T_5 V_45 ;
V_45 = F_42 ( V_26 -> V_46 ,
V_2 -> V_21 , V_47 ,
V_2 -> V_21 / V_71 ,
V_2 -> V_21 % V_71 ) ;
if ( V_45 != V_49 )
F_15 ( L_17 ,
V_39 , V_45 , V_26 -> V_40 -> V_41 ,
V_2 -> V_21 ) ;
}
}
F_38 ( V_42 ) ;
return V_75 ;
}
static void T_2 F_43 ( struct V_25 * V_26 )
{
struct V_60 * V_40 = V_26 -> V_40 ;
struct V_85 * V_86 = V_40 -> V_86 ;
struct V_27 * V_87 ;
T_6 V_88 [ 2 ] , V_65 ;
const T_6 * V_28 ;
T_7 V_89 ;
if ( V_26 -> type != V_84 && V_26 -> type != V_90 ) {
F_10 ( L_18 ) ;
return;
}
if ( ! F_44 ( V_91 ) ) {
F_10 ( L_19 ) ;
return;
}
V_28 = F_45 ( V_86 , L_20 , NULL ) ;
if ( ! V_28 ) {
F_10 ( L_21 ,
V_86 -> V_92 ) ;
return;
}
if ( F_46 ( V_86 , L_22 ,
V_88 , 2 ) ) {
V_88 [ 0 ] = 0 ;
V_88 [ 1 ] = 16 ;
}
if ( V_88 [ 1 ] > 63 ) {
F_15 ( L_23 ,
V_39 , V_88 [ 1 ] , V_26 -> V_40 -> V_41 ) ;
V_88 [ 1 ] = 63 ;
}
if ( V_88 [ 1 ] <= V_88 [ 0 ] ) {
F_15 ( L_24 ,
V_39 , V_26 -> V_40 -> V_41 ) ;
return;
}
V_87 = & V_40 -> V_52 [ 1 ] ;
V_87 -> V_93 = V_86 -> V_92 ;
V_87 -> V_29 = F_47 ( V_86 , V_28 + 2 ) ;
V_87 -> V_55 = V_87 -> V_29 + F_48 ( V_28 + 4 , 2 ) - 1 ;
V_87 -> V_9 = ( V_94 | V_34 | V_35 ) ;
V_89 = F_48 ( V_28 , 2 ) ;
V_40 -> V_95 [ 1 ] = V_87 -> V_29 - V_89 ;
V_26 -> V_30 . V_32 = F_49 ( V_87 ) ;
V_26 -> V_30 . V_54 = V_26 -> V_30 . V_32 / V_26 -> V_30 . V_38 ;
V_26 -> V_30 . V_31 = V_89 ;
F_10 ( L_25 ,
V_87 -> V_29 , V_87 -> V_55 , V_89 , V_88 [ 0 ] ,
V_88 [ 0 ] + V_88 [ 1 ] - 1 ) ;
V_26 -> V_30 . V_96 = ( unsigned long ) - 1 ;
V_88 [ 1 ] -- ;
V_26 -> V_30 . V_48 = V_88 [ 0 ] + V_88 [ 1 ] ;
F_10 ( L_26 , V_26 -> V_30 . V_48 ) ;
for ( V_65 = V_88 [ 0 ] ; V_65 < V_88 [ 1 ] ; V_65 ++ )
F_21 ( V_65 , & V_26 -> V_30 . V_96 ) ;
if ( V_26 -> type == V_84 )
V_26 -> V_97 = F_30 ;
else
V_26 -> V_97 = F_22 ;
V_26 -> V_98 = F_32 ;
V_26 -> V_99 = F_34 ;
}
static void F_50 ( struct V_25 * V_26 , int V_36 )
{
struct V_1 * V_2 = & V_26 -> V_30 . V_37 [ V_36 ] ;
struct V_1 * V_100 ;
T_3 V_45 ;
if ( V_2 -> V_9 & V_81 ) {
V_2 = V_2 -> V_82 ;
if ( F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_79 ) ) )
return;
V_36 = V_2 -> V_21 ;
}
V_45 = F_51 ( V_26 -> V_46 ,
V_36 ,
V_101 ) ;
if ( V_45 != V_49 ) {
F_15 ( L_27 ,
V_39 , V_45 , V_26 -> V_40 -> V_41 , V_36 ) ;
return;
}
if ( ! ( V_2 -> V_9 & V_79 ) )
return;
F_33 (slave, &pe->slaves, list) {
V_45 = F_51 ( V_26 -> V_46 ,
V_100 -> V_21 ,
V_101 ) ;
if ( V_45 != V_49 )
F_15 ( L_27 ,
V_39 , V_45 , V_26 -> V_40 -> V_41 ,
V_100 -> V_21 ) ;
}
}
static int F_52 ( struct V_25 * V_26 , int V_36 , int V_102 )
{
struct V_1 * V_2 , * V_100 ;
T_3 V_45 ;
V_2 = & V_26 -> V_30 . V_37 [ V_36 ] ;
if ( V_2 -> V_9 & V_81 ) {
V_2 = V_2 -> V_82 ;
F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_79 ) ) ;
V_36 = V_2 -> V_21 ;
}
V_45 = F_53 ( V_26 -> V_46 , V_36 , V_102 ) ;
if ( V_45 != V_49 ) {
F_15 ( L_28 ,
V_39 , V_45 , V_102 , V_26 -> V_40 -> V_41 , V_36 ) ;
return - V_57 ;
}
if ( ! ( V_2 -> V_9 & V_79 ) )
return 0 ;
F_33 (slave, &pe->slaves, list) {
V_45 = F_53 ( V_26 -> V_46 ,
V_100 -> V_21 ,
V_102 ) ;
if ( V_45 != V_49 ) {
F_15 ( L_28 ,
V_39 , V_45 , V_102 , V_26 -> V_40 -> V_41 ,
V_100 -> V_21 ) ;
return - V_57 ;
}
}
return 0 ;
}
static int F_54 ( struct V_25 * V_26 , int V_36 )
{
struct V_1 * V_100 , * V_2 ;
T_8 V_103 , V_104 ;
T_9 V_105 ;
T_3 V_45 ;
if ( V_36 < 0 || V_36 >= V_26 -> V_30 . V_38 )
return V_106 ;
V_2 = & V_26 -> V_30 . V_37 [ V_36 ] ;
if ( V_2 -> V_9 & V_81 ) {
V_2 = V_2 -> V_82 ;
F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_79 ) ) ;
V_36 = V_2 -> V_21 ;
}
V_45 = F_55 ( V_26 -> V_46 , V_36 ,
& V_104 , & V_105 , NULL ) ;
if ( V_45 != V_49 ) {
F_15 ( L_29
L_30 ,
V_39 , V_45 ,
V_26 -> V_40 -> V_41 , V_36 ) ;
return V_107 ;
}
if ( ! ( V_2 -> V_9 & V_79 ) )
return V_104 ;
F_33 (slave, &pe->slaves, list) {
V_45 = F_55 ( V_26 -> V_46 ,
V_100 -> V_21 ,
& V_103 ,
& V_105 ,
NULL ) ;
if ( V_45 != V_49 ) {
F_15 ( L_29
L_30 ,
V_39 , V_45 ,
V_26 -> V_40 -> V_41 , V_100 -> V_21 ) ;
return V_107 ;
}
if ( V_103 > V_104 )
V_104 = V_103 ;
}
return V_104 ;
}
struct V_1 * F_56 ( struct V_58 * V_12 )
{
struct V_60 * V_40 = F_26 ( V_12 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_108 * V_109 = F_57 ( V_12 ) ;
if ( ! V_109 )
return NULL ;
if ( V_109 -> V_21 == V_110 )
return NULL ;
return & V_26 -> V_30 . V_37 [ V_109 -> V_21 ] ;
}
static int F_58 ( struct V_25 * V_26 ,
struct V_1 * V_67 ,
struct V_1 * V_111 ,
bool V_112 )
{
const char * V_44 = V_112 ? L_31 : L_32 ;
T_10 V_113 = V_112 ? V_114 :
V_115 ;
struct V_1 * V_100 ;
long V_45 ;
V_45 = F_59 ( V_26 -> V_46 , V_67 -> V_21 ,
V_111 -> V_21 , V_113 ) ;
if ( V_45 != V_49 ) {
F_60 ( V_111 , L_33 ,
V_45 , V_44 ) ;
return - V_116 ;
}
if ( ! ( V_111 -> V_9 & V_79 ) )
return 0 ;
F_33 (slave, &child->slaves, list) {
V_45 = F_59 ( V_26 -> V_46 , V_67 -> V_21 ,
V_100 -> V_21 , V_113 ) ;
if ( V_45 != V_49 ) {
F_60 ( V_100 , L_33 ,
V_45 , V_44 ) ;
return - V_116 ;
}
}
return 0 ;
}
static int F_61 ( struct V_25 * V_26 ,
struct V_1 * V_2 ,
bool V_112 )
{
struct V_1 * V_100 ;
struct V_58 * V_11 = NULL ;
int V_117 ;
if ( V_112 ) {
F_53 ( V_26 -> V_46 , V_2 -> V_21 ,
V_118 ) ;
if ( V_2 -> V_9 & V_79 ) {
F_33 (slave, &pe->slaves, list)
F_53 ( V_26 -> V_46 ,
V_100 -> V_21 ,
V_118 ) ;
}
}
V_117 = F_58 ( V_26 , V_2 , V_2 , V_112 ) ;
if ( V_117 )
return V_117 ;
if ( V_2 -> V_9 & V_79 ) {
F_33 (slave, &pe->slaves, list) {
V_117 = F_58 ( V_26 , V_100 , V_2 , V_112 ) ;
if ( V_117 )
return V_117 ;
}
}
if ( V_2 -> V_9 & ( V_14 | V_13 ) )
V_11 = V_2 -> V_15 -> V_119 ;
else if ( V_2 -> V_9 & V_10 )
V_11 = V_2 -> V_11 -> V_19 -> V_119 ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
V_11 = V_2 -> V_18 ;
#endif
while ( V_11 ) {
struct V_108 * V_109 = F_57 ( V_11 ) ;
struct V_1 * V_67 ;
if ( V_109 && V_109 -> V_21 != V_110 ) {
V_67 = & V_26 -> V_30 . V_37 [ V_109 -> V_21 ] ;
V_117 = F_58 ( V_26 , V_67 , V_2 , V_112 ) ;
if ( V_117 )
return V_117 ;
}
V_11 = V_11 -> V_19 -> V_119 ;
}
return 0 ;
}
static int F_62 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_58 * V_67 ;
T_10 V_120 , V_121 , V_122 ;
T_5 V_45 ;
long V_123 , V_20 ;
if ( V_2 -> V_15 ) {
int V_124 ;
V_121 = V_125 ;
V_122 = V_126 ;
V_67 = V_2 -> V_15 -> V_119 ;
if ( V_2 -> V_9 & V_14 )
V_124 = V_2 -> V_15 -> V_127 . V_55 - V_2 -> V_15 -> V_127 . V_29 + 1 ;
else
V_124 = 1 ;
switch( V_124 ) {
case 1 : V_120 = V_128 ; break;
case 2 : V_120 = V_129 ; break;
case 4 : V_120 = V_130 ; break;
case 8 : V_120 = V_131 ; break;
case 16 : V_120 = V_132 ; break;
case 32 : V_120 = V_133 ; break;
default:
F_63 ( & V_2 -> V_15 -> V_12 , L_34 ,
V_124 ) ;
V_120 = V_128 ;
}
V_123 = V_2 -> V_20 + ( V_124 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_67 = V_2 -> V_18 ;
else
#endif
V_67 = V_2 -> V_11 -> V_19 -> V_119 ;
V_120 = V_128 ;
V_121 = V_134 ;
V_122 = V_135 ;
V_123 = V_2 -> V_20 + 1 ;
}
for ( V_20 = V_2 -> V_20 ; V_20 < V_123 ; V_20 ++ )
V_26 -> V_30 . V_136 [ V_20 ] = V_110 ;
while ( V_67 ) {
struct V_108 * V_109 = F_57 ( V_67 ) ;
if ( V_109 && V_109 -> V_21 != V_110 ) {
V_45 = F_59 ( V_26 -> V_46 , V_109 -> V_21 ,
V_2 -> V_21 , V_115 ) ;
}
V_67 = V_67 -> V_19 -> V_119 ;
}
F_53 ( V_26 -> V_46 , V_2 -> V_21 ,
V_118 ) ;
V_45 = F_59 ( V_26 -> V_46 , V_2 -> V_21 ,
V_2 -> V_21 , V_115 ) ;
if ( V_45 )
F_60 ( V_2 , L_35 , V_45 ) ;
V_45 = F_64 ( V_26 -> V_46 , V_2 -> V_21 , V_2 -> V_20 ,
V_120 , V_121 , V_122 , V_137 ) ;
if ( V_45 )
F_65 ( V_2 , L_36 , V_45 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
#ifdef F_5
V_2 -> V_18 = NULL ;
#endif
return 0 ;
}
static int F_66 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_58 * V_67 ;
T_10 V_120 , V_121 , V_122 ;
long V_45 , V_123 , V_20 ;
if ( V_2 -> V_15 ) {
int V_124 ;
V_121 = V_125 ;
V_122 = V_126 ;
V_67 = V_2 -> V_15 -> V_119 ;
if ( V_2 -> V_9 & V_14 )
V_124 = V_2 -> V_15 -> V_127 . V_55 - V_2 -> V_15 -> V_127 . V_29 + 1 ;
else
V_124 = 1 ;
switch( V_124 ) {
case 1 : V_120 = V_128 ; break;
case 2 : V_120 = V_129 ; break;
case 4 : V_120 = V_130 ; break;
case 8 : V_120 = V_131 ; break;
case 16 : V_120 = V_132 ; break;
case 32 : V_120 = V_133 ; break;
default:
F_63 ( & V_2 -> V_15 -> V_12 , L_34 ,
V_124 ) ;
V_120 = V_128 ;
}
V_123 = V_2 -> V_20 + ( V_124 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_67 = V_2 -> V_18 ;
else
#endif
V_67 = V_2 -> V_11 -> V_19 -> V_119 ;
V_120 = V_128 ;
V_121 = V_134 ;
V_122 = V_135 ;
V_123 = V_2 -> V_20 + 1 ;
}
V_45 = F_64 ( V_26 -> V_46 , V_2 -> V_21 , V_2 -> V_20 ,
V_120 , V_121 , V_122 , V_138 ) ;
if ( V_45 ) {
F_65 ( V_2 , L_36 , V_45 ) ;
return - V_116 ;
}
if ( V_26 -> type != V_139 )
F_61 ( V_26 , V_2 , true ) ;
for ( V_20 = V_2 -> V_20 ; V_20 < V_123 ; V_20 ++ )
V_26 -> V_30 . V_136 [ V_20 ] = V_2 -> V_21 ;
if ( V_26 -> type != V_84 ) {
V_2 -> V_140 = 0 ;
goto V_141;
}
V_2 -> V_140 = V_2 -> V_21 ;
V_45 = F_67 ( V_26 -> V_46 , V_2 -> V_140 , V_2 -> V_21 ) ;
if ( V_45 != V_49 ) {
F_65 ( V_2 , L_37 ,
V_45 , V_2 -> V_140 ) ;
V_2 -> V_140 = - 1 ;
} else {
V_45 = F_68 ( V_26 -> V_46 ,
V_2 -> V_140 , V_142 ) ;
if ( V_45 ) {
F_65 ( V_2 , L_38 ,
V_45 , V_2 -> V_140 ) ;
V_2 -> V_140 = - 1 ;
}
}
V_141:
return 0 ;
}
static int F_69 ( struct V_58 * V_12 , int V_143 )
{
struct V_108 * V_109 = F_57 ( V_12 ) ;
int V_65 ;
struct V_27 * V_87 , V_144 ;
T_4 V_76 ;
T_11 V_145 ;
if ( ! V_12 -> V_146 )
return - V_23 ;
V_145 = V_109 -> V_145 ;
for ( V_65 = 0 ; V_65 < V_147 ; V_65 ++ ) {
V_87 = & V_12 -> V_27 [ V_65 + V_148 ] ;
if ( ! V_87 -> V_9 || ! V_87 -> V_67 )
continue;
V_76 = F_70 ( V_12 , V_65 + V_148 ) ;
V_144 . V_9 = V_87 -> V_9 ;
V_144 . V_29 = V_87 -> V_29 + ( V_76 * V_143 ) ;
V_144 . V_55 = V_144 . V_29 + ( V_76 * V_145 ) - 1 ;
if ( V_144 . V_55 > V_87 -> V_55 ) {
F_63 ( & V_12 -> V_12 , L_39 ,
V_65 , & V_144 , V_87 , V_145 , V_143 ) ;
return - V_149 ;
}
}
for ( V_65 = 0 ; V_65 < V_147 ; V_65 ++ ) {
V_87 = & V_12 -> V_27 [ V_65 + V_148 ] ;
if ( ! V_87 -> V_9 || ! V_87 -> V_67 )
continue;
V_76 = F_70 ( V_12 , V_65 + V_148 ) ;
V_144 = * V_87 ;
V_87 -> V_29 += V_76 * V_143 ;
F_71 ( & V_12 -> V_12 , L_40 ,
V_65 , & V_144 , V_87 , ( V_143 > 0 ) ? L_41 : L_42 ,
V_145 , V_143 ) ;
F_72 ( V_12 , V_65 + V_148 ) ;
}
return 0 ;
}
static struct V_1 * F_73 ( struct V_58 * V_12 )
{
struct V_60 * V_40 = F_26 ( V_12 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_108 * V_109 = F_57 ( V_12 ) ;
struct V_1 * V_2 ;
if ( ! V_109 ) {
F_74 ( L_43 ,
F_75 ( V_12 ) ) ;
return NULL ;
}
if ( V_109 -> V_21 != V_110 )
return NULL ;
V_2 = F_18 ( V_26 ) ;
if ( ! V_2 ) {
F_76 ( L_44 ,
F_75 ( V_12 ) ) ;
return NULL ;
}
F_77 ( V_12 ) ;
V_109 -> V_150 = V_12 ;
V_109 -> V_21 = V_2 -> V_21 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_15 = NULL ;
V_2 -> V_140 = - 1 ;
V_2 -> V_20 = V_12 -> V_19 -> V_16 << 8 | V_109 -> V_151 ;
F_78 ( V_2 , L_45 ) ;
if ( F_66 ( V_26 , V_2 ) ) {
F_19 ( V_2 ) ;
V_109 -> V_21 = V_110 ;
V_2 -> V_11 = NULL ;
F_79 ( V_12 ) ;
return NULL ;
}
F_41 ( & V_2 -> V_83 , & V_26 -> V_30 . V_152 ) ;
return V_2 ;
}
static void F_80 ( struct V_72 * V_19 , struct V_1 * V_2 )
{
struct V_58 * V_12 ;
F_33 (dev, &bus->devices, bus_list) {
struct V_108 * V_109 = F_57 ( V_12 ) ;
if ( V_109 == NULL ) {
F_15 ( L_46 ,
F_75 ( V_12 ) ) ;
continue;
}
if ( V_109 -> V_21 != V_110 )
continue;
V_2 -> V_153 ++ ;
V_109 -> V_150 = V_12 ;
V_109 -> V_21 = V_2 -> V_21 ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_74 )
F_80 ( V_12 -> V_74 , V_2 ) ;
}
}
static struct V_1 * F_81 ( struct V_72 * V_19 , bool V_73 )
{
struct V_60 * V_40 = F_26 ( V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_1 * V_2 = NULL ;
unsigned int V_43 ;
V_43 = V_26 -> V_30 . V_136 [ V_19 -> V_16 << 8 ] ;
if ( V_43 != V_110 ) {
V_2 = & V_26 -> V_30 . V_37 [ V_43 ] ;
F_80 ( V_19 , V_2 ) ;
return NULL ;
}
if ( F_35 ( V_19 ) &&
V_26 -> V_30 . V_154 != V_110 )
V_2 = & V_26 -> V_30 . V_37 [ V_26 -> V_30 . V_154 ] ;
if ( ! V_2 && V_26 -> V_99 )
V_2 = V_26 -> V_99 ( V_19 , V_73 ) ;
if ( ! V_2 )
V_2 = F_18 ( V_26 ) ;
if ( ! V_2 ) {
F_76 ( L_47 ,
V_39 , F_4 ( V_19 ) , V_19 -> V_16 ) ;
return NULL ;
}
V_2 -> V_9 |= ( V_73 ? V_14 : V_13 ) ;
V_2 -> V_15 = V_19 ;
V_2 -> V_11 = NULL ;
V_2 -> V_140 = - 1 ;
V_2 -> V_20 = V_19 -> V_127 . V_29 << 8 ;
if ( V_73 )
F_78 ( V_2 , L_48 ,
V_19 -> V_127 . V_29 , V_19 -> V_127 . V_55 , V_2 -> V_21 ) ;
else
F_78 ( V_2 , L_49 ,
V_19 -> V_127 . V_29 , V_2 -> V_21 ) ;
if ( F_66 ( V_26 , V_2 ) ) {
F_19 ( V_2 ) ;
V_2 -> V_15 = NULL ;
return NULL ;
}
F_80 ( V_19 , V_2 ) ;
F_41 ( & V_2 -> V_83 , & V_26 -> V_30 . V_152 ) ;
return V_2 ;
}
static struct V_1 * F_82 ( struct V_58 * V_155 )
{
int V_43 , V_156 = false , V_45 ;
long V_20 ;
struct V_1 * V_2 ;
struct V_58 * V_157 ;
struct V_108 * V_158 ;
struct V_60 * V_40 = F_26 ( V_155 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
V_157 = F_83 ( V_155 ) ;
for ( V_43 = 0 ; V_43 < V_26 -> V_30 . V_38 ; V_43 ++ ) {
V_2 = & V_26 -> V_30 . V_37 [ V_43 ] ;
if ( ! V_2 -> V_11 )
continue;
if ( F_83 ( V_2 -> V_11 ) == V_157 ) {
F_71 ( & V_155 -> V_12 ,
L_50 , V_43 ) ;
F_77 ( V_155 ) ;
V_158 = F_57 ( V_155 ) ;
V_20 = V_155 -> V_19 -> V_16 << 8 | V_158 -> V_151 ;
V_158 -> V_150 = V_155 ;
V_158 -> V_21 = V_43 ;
V_26 -> V_30 . V_136 [ V_20 ] = V_2 -> V_21 ;
V_45 = F_64 ( V_26 -> V_46 , V_43 , V_20 ,
V_128 ,
V_134 ,
V_135 ,
V_138 ) ;
F_20 ( V_45 != V_49 ) ;
V_156 = true ;
break;
}
}
if ( ! V_156 )
return F_73 ( V_155 ) ;
else
return V_2 ;
}
static void F_84 ( struct V_72 * V_19 )
{
struct V_58 * V_11 ;
F_33 (pdev, &bus->devices, bus_list)
F_82 ( V_11 ) ;
}
static void F_85 ( void )
{
struct V_60 * V_40 , * V_159 ;
struct V_25 * V_26 ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_40 -> V_61 ;
if ( V_26 -> type == V_139 ) {
F_14 ( V_26 , 0 ) ;
F_84 ( V_40 -> V_19 ) ;
}
}
}
static int F_87 ( struct V_58 * V_11 , T_11 V_145 )
{
struct V_72 * V_19 ;
struct V_60 * V_40 ;
struct V_25 * V_26 ;
struct V_108 * V_109 ;
int V_65 , V_160 ;
int V_161 ;
V_19 = V_11 -> V_19 ;
V_40 = F_26 ( V_19 ) ;
V_26 = V_40 -> V_61 ;
V_109 = F_57 ( V_11 ) ;
if ( V_109 -> V_162 )
V_161 = V_145 ;
else
V_161 = 1 ;
for ( V_65 = 0 ; V_65 < V_147 ; V_65 ++ )
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
if ( V_109 -> V_163 [ V_160 ] [ V_65 ] == V_164 )
continue;
F_24 ( V_26 -> V_46 ,
V_47 , V_109 -> V_163 [ V_160 ] [ V_65 ] , 0 ) ;
F_21 ( V_109 -> V_163 [ V_160 ] [ V_65 ] , & V_26 -> V_30 . V_96 ) ;
V_109 -> V_163 [ V_160 ] [ V_65 ] = V_164 ;
}
F_38 ( V_109 -> V_163 ) ;
return 0 ;
}
static int F_88 ( struct V_58 * V_11 , T_11 V_145 )
{
struct V_72 * V_19 ;
struct V_60 * V_40 ;
struct V_25 * V_26 ;
struct V_108 * V_109 ;
unsigned int V_165 ;
struct V_27 * V_87 ;
int V_65 , V_160 ;
T_5 V_45 ;
int V_166 ;
T_4 V_76 , V_29 ;
int V_43 ;
int V_161 ;
V_19 = V_11 -> V_19 ;
V_40 = F_26 ( V_19 ) ;
V_26 = V_40 -> V_61 ;
V_109 = F_57 ( V_11 ) ;
V_166 = F_89 ( V_11 ) ;
if ( V_109 -> V_162 )
V_161 = V_145 ;
else
V_161 = 1 ;
V_109 -> V_163 = F_90 ( sizeof( * V_109 -> V_163 ) * V_161 , V_77 ) ;
if ( ! V_109 -> V_163 )
return - V_167 ;
for ( V_65 = 0 ; V_65 < V_161 ; V_65 ++ )
for ( V_160 = 0 ; V_160 < V_147 ; V_160 ++ )
V_109 -> V_163 [ V_65 ] [ V_160 ] = V_164 ;
for ( V_65 = 0 ; V_65 < V_147 ; V_65 ++ ) {
V_87 = & V_11 -> V_27 [ V_65 + V_148 ] ;
if ( ! V_87 -> V_9 || ! V_87 -> V_67 )
continue;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
do {
V_165 = F_91 ( & V_26 -> V_30 . V_96 ,
V_26 -> V_30 . V_48 + 1 , 0 ) ;
if ( V_165 >= V_26 -> V_30 . V_48 + 1 )
goto V_168;
} while ( F_16 ( V_165 , & V_26 -> V_30 . V_96 ) );
V_109 -> V_163 [ V_160 ] [ V_65 ] = V_165 ;
if ( V_109 -> V_162 ) {
V_76 = F_70 ( V_11 ,
V_148 + V_65 ) ;
V_29 = V_87 -> V_29 + V_76 * V_160 ;
} else {
V_76 = F_49 ( V_87 ) ;
V_29 = V_87 -> V_29 ;
}
if ( V_109 -> V_162 ) {
V_43 = V_109 -> V_169 [ V_160 ] ;
V_45 = F_42 ( V_26 -> V_46 ,
V_43 , V_47 ,
V_109 -> V_163 [ V_160 ] [ V_65 ] , 0 ) ;
}
V_45 = F_23 ( V_26 -> V_46 ,
V_47 ,
V_109 -> V_163 [ V_160 ] [ V_65 ] ,
V_29 ,
0 ,
V_76 ) ;
if ( V_45 != V_49 ) {
F_63 ( & V_11 -> V_12 , L_51 ,
V_165 , V_45 ) ;
goto V_168;
}
if ( V_109 -> V_162 )
V_45 = F_24 ( V_26 -> V_46 ,
V_47 , V_109 -> V_163 [ V_160 ] [ V_65 ] , 2 ) ;
else
V_45 = F_24 ( V_26 -> V_46 ,
V_47 , V_109 -> V_163 [ V_160 ] [ V_65 ] , 1 ) ;
if ( V_45 != V_49 ) {
F_63 ( & V_11 -> V_12 , L_52 ,
V_165 , V_45 ) ;
goto V_168;
}
}
}
return 0 ;
V_168:
F_87 ( V_11 , V_145 ) ;
return - V_149 ;
}
static void F_92 ( struct V_58 * V_12 , struct V_1 * V_2 )
{
struct V_170 * V_171 ;
T_5 V_45 ;
V_171 = V_2 -> V_172 . V_173 [ 0 ] ;
V_45 = F_93 ( & V_2 -> V_172 , 0 ) ;
if ( V_45 )
F_60 ( V_2 , L_53 , V_45 ) ;
F_94 ( V_2 , false ) ;
if ( V_2 -> V_172 . V_174 ) {
F_95 ( V_2 -> V_172 . V_174 ) ;
F_96 ( V_2 -> V_172 . V_174 ) ;
}
F_97 ( V_171 ) ;
F_98 ( V_171 , F_99 ( V_12 -> V_12 . V_175 ) ) ;
}
static void F_100 ( struct V_58 * V_11 )
{
struct V_72 * V_19 ;
struct V_60 * V_40 ;
struct V_25 * V_26 ;
struct V_1 * V_2 , * V_176 ;
struct V_108 * V_109 ;
V_19 = V_11 -> V_19 ;
V_40 = F_26 ( V_19 ) ;
V_26 = V_40 -> V_61 ;
V_109 = F_57 ( V_11 ) ;
if ( ! V_11 -> V_146 )
return;
F_86 (pe, pe_n, &phb->ioda.pe_list, list) {
if ( V_2 -> V_18 != V_11 )
continue;
F_92 ( V_11 , V_2 ) ;
F_101 ( & V_26 -> V_30 . V_177 ) ;
F_102 ( & V_2 -> V_83 ) ;
F_103 ( & V_26 -> V_30 . V_177 ) ;
F_62 ( V_26 , V_2 ) ;
F_19 ( V_2 ) ;
}
}
void F_104 ( struct V_58 * V_11 )
{
struct V_72 * V_19 ;
struct V_60 * V_40 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_108 * V_109 ;
struct V_178 * V_179 ;
T_11 V_145 , V_65 ;
V_19 = V_11 -> V_19 ;
V_40 = F_26 ( V_19 ) ;
V_26 = V_40 -> V_61 ;
V_109 = F_57 ( V_11 ) ;
V_179 = V_11 -> V_180 ;
V_145 = V_109 -> V_145 ;
F_100 ( V_11 ) ;
if ( V_26 -> type == V_90 ) {
if ( ! V_109 -> V_162 )
F_69 ( V_11 , - * V_109 -> V_169 ) ;
F_87 ( V_11 , V_145 ) ;
if ( V_109 -> V_162 ) {
for ( V_65 = 0 ; V_65 < V_145 ; V_65 ++ ) {
if ( V_109 -> V_169 [ V_65 ] == V_110 )
continue;
V_2 = & V_26 -> V_30 . V_37 [ V_109 -> V_169 [ V_65 ] ] ;
F_19 ( V_2 ) ;
}
} else
F_105 ( V_26 -> V_30 . V_42 , * V_109 -> V_169 , V_145 ) ;
F_38 ( V_109 -> V_169 ) ;
}
}
static void F_106 ( struct V_58 * V_11 , T_11 V_145 )
{
struct V_72 * V_19 ;
struct V_60 * V_40 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
int V_43 ;
T_11 V_181 ;
struct V_108 * V_109 ;
V_19 = V_11 -> V_19 ;
V_40 = F_26 ( V_19 ) ;
V_26 = V_40 -> V_61 ;
V_109 = F_57 ( V_11 ) ;
if ( ! V_11 -> V_146 )
return;
for ( V_181 = 0 ; V_181 < V_145 ; V_181 ++ ) {
if ( V_109 -> V_162 )
V_43 = V_109 -> V_169 [ V_181 ] ;
else
V_43 = * V_109 -> V_169 + V_181 ;
V_2 = & V_26 -> V_30 . V_37 [ V_43 ] ;
V_2 -> V_21 = V_43 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_140 = - 1 ;
V_2 -> V_20 = ( F_107 ( V_11 , V_181 ) << 8 ) |
F_108 ( V_11 , V_181 ) ;
F_78 ( V_2 , L_54 ,
V_40 -> V_41 , V_11 -> V_19 -> V_16 ,
F_6 ( F_108 ( V_11 , V_181 ) ) ,
F_7 ( F_108 ( V_11 , V_181 ) ) , V_43 ) ;
if ( F_66 ( V_26 , V_2 ) ) {
F_19 ( V_2 ) ;
V_2 -> V_11 = NULL ;
continue;
}
F_101 ( & V_26 -> V_30 . V_177 ) ;
F_41 ( & V_2 -> V_83 , & V_26 -> V_30 . V_152 ) ;
F_103 ( & V_26 -> V_30 . V_177 ) ;
F_109 ( V_26 , V_2 ) ;
}
}
int F_110 ( struct V_58 * V_11 , T_11 V_145 )
{
struct V_72 * V_19 ;
struct V_60 * V_40 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_108 * V_109 ;
int V_117 ;
T_11 V_65 ;
V_19 = V_11 -> V_19 ;
V_40 = F_26 ( V_19 ) ;
V_26 = V_40 -> V_61 ;
V_109 = F_57 ( V_11 ) ;
if ( V_26 -> type == V_90 ) {
if ( ! V_109 -> V_182 ) {
F_71 ( & V_11 -> V_12 , L_55
L_56 ) ;
return - V_183 ;
}
if ( V_109 -> V_162 && V_145 > V_26 -> V_30 . V_48 ) {
F_71 ( & V_11 -> V_12 , L_57 ) ;
return - V_149 ;
}
if ( V_109 -> V_162 )
V_109 -> V_169 = F_90 ( sizeof( * V_109 -> V_169 ) * V_145 ,
V_77 ) ;
else
V_109 -> V_169 = F_90 ( sizeof( * V_109 -> V_169 ) , V_77 ) ;
if ( ! V_109 -> V_169 )
return - V_167 ;
if ( V_109 -> V_162 )
for ( V_65 = 0 ; V_65 < V_145 ; V_65 ++ )
V_109 -> V_169 [ V_65 ] = V_110 ;
if ( V_109 -> V_162 ) {
for ( V_65 = 0 ; V_65 < V_145 ; V_65 ++ ) {
V_2 = F_18 ( V_26 ) ;
if ( ! V_2 ) {
V_117 = - V_149 ;
goto V_168;
}
V_109 -> V_169 [ V_65 ] = V_2 -> V_21 ;
}
} else {
F_101 ( & V_26 -> V_30 . V_184 ) ;
* V_109 -> V_169 = F_111 (
V_26 -> V_30 . V_42 , V_26 -> V_30 . V_38 ,
0 , V_145 , 0 ) ;
if ( * V_109 -> V_169 >= V_26 -> V_30 . V_38 ) {
F_103 ( & V_26 -> V_30 . V_184 ) ;
F_71 ( & V_11 -> V_12 , L_58 , V_145 ) ;
F_38 ( V_109 -> V_169 ) ;
return - V_149 ;
}
F_112 ( V_26 -> V_30 . V_42 , * V_109 -> V_169 , V_145 ) ;
F_103 ( & V_26 -> V_30 . V_184 ) ;
}
V_109 -> V_145 = V_145 ;
V_117 = F_88 ( V_11 , V_145 ) ;
if ( V_117 ) {
F_71 ( & V_11 -> V_12 , L_59 ) ;
goto V_168;
}
if ( ! V_109 -> V_162 ) {
V_117 = F_69 ( V_11 , * V_109 -> V_169 ) ;
if ( V_117 )
goto V_168;
}
}
F_106 ( V_11 , V_145 ) ;
return 0 ;
V_168:
if ( V_109 -> V_162 ) {
for ( V_65 = 0 ; V_65 < V_145 ; V_65 ++ ) {
if ( V_109 -> V_169 [ V_65 ] == V_110 )
continue;
V_2 = & V_26 -> V_30 . V_37 [ V_109 -> V_169 [ V_65 ] ] ;
F_19 ( V_2 ) ;
}
} else
F_105 ( V_26 -> V_30 . V_42 , * V_109 -> V_169 , V_145 ) ;
F_38 ( V_109 -> V_169 ) ;
return V_117 ;
}
int F_113 ( struct V_58 * V_11 )
{
F_104 ( V_11 ) ;
F_114 ( V_11 ) ;
return 0 ;
}
int F_115 ( struct V_58 * V_11 , T_11 V_145 )
{
F_116 ( V_11 ) ;
return F_110 ( V_11 , V_145 ) ;
}
static void F_117 ( struct V_25 * V_26 , struct V_58 * V_11 )
{
struct V_108 * V_109 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_109 || V_109 -> V_21 == V_110 )
return;
V_2 = & V_26 -> V_30 . V_37 [ V_109 -> V_21 ] ;
F_20 ( F_118 ( & V_11 -> V_12 ) != & V_185 ) ;
F_119 ( & V_11 -> V_12 , V_2 -> V_186 ) ;
F_120 ( & V_11 -> V_12 , V_2 -> V_172 . V_173 [ 0 ] ) ;
}
static int F_121 ( struct V_58 * V_11 , T_7 V_187 )
{
struct V_60 * V_40 = F_26 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_108 * V_109 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
T_12 V_188 ;
bool V_189 = false ;
if ( F_20 ( ! V_109 || V_109 -> V_21 == V_110 ) )
return - V_190 ; ;
V_2 = & V_26 -> V_30 . V_37 [ V_109 -> V_21 ] ;
if ( V_2 -> V_191 ) {
V_188 = V_2 -> V_186 + F_122 () - 1 ;
V_189 = ( V_187 >= V_188 ) ;
}
if ( V_189 ) {
F_71 ( & V_11 -> V_12 , L_60 ) ;
F_123 ( & V_11 -> V_12 , & V_192 ) ;
} else {
F_71 ( & V_11 -> V_12 , L_61 ) ;
F_123 ( & V_11 -> V_12 , & V_185 ) ;
}
* V_11 -> V_12 . V_187 = V_187 ;
F_124 ( V_11 , V_189 ) ;
return 0 ;
}
static T_7 F_125 ( struct V_58 * V_11 )
{
struct V_60 * V_40 = F_26 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_108 * V_109 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
T_7 V_55 , V_193 ;
if ( F_20 ( ! V_109 || V_109 -> V_21 == V_110 ) )
return 0 ;
V_2 = & V_26 -> V_30 . V_37 [ V_109 -> V_21 ] ;
if ( ! V_2 -> V_191 )
return F_126 ( & V_11 -> V_12 ) ;
V_55 = V_2 -> V_186 + F_122 () ;
V_193 = 1ULL << ( F_127 ( V_55 ) - 1 ) ;
V_193 += V_193 - 1 ;
return V_193 ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_72 * V_19 )
{
struct V_58 * V_12 ;
F_33 (dev, &bus->devices, bus_list) {
F_120 ( & V_12 -> V_12 , V_2 -> V_172 . V_173 [ 0 ] ) ;
F_119 ( & V_12 -> V_12 , V_2 -> V_186 ) ;
F_129 ( & V_12 -> V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_74 )
F_128 ( V_2 , V_12 -> V_74 ) ;
}
}
static inline T_13 T_14 * F_130 ( struct V_25 * V_26 ,
bool V_194 )
{
return V_194 ? ( T_13 T_14 * ) ( V_26 -> V_195 + 0x210 ) :
( V_26 -> V_196 + 0x210 ) ;
}
static void F_131 ( struct V_170 * V_171 ,
unsigned long V_68 , unsigned long V_197 , bool V_198 )
{
struct V_199 * V_200 = F_132 (
& V_171 -> V_201 , struct V_199 ,
V_202 ) ;
struct V_1 * V_2 = F_133 ( V_200 -> V_172 ,
struct V_1 , V_172 ) ;
T_13 T_14 * V_203 = F_130 ( V_2 -> V_26 , V_198 ) ;
unsigned long V_29 , V_55 , V_204 ;
V_29 = F_134 ( ( ( T_13 * ) V_171 -> V_205 ) + V_68 - V_171 -> V_206 ) ;
V_55 = F_134 ( ( ( T_13 * ) V_171 -> V_205 ) + V_68 - V_171 -> V_206 +
V_197 - 1 ) ;
V_29 |= ( 1ull << 63 ) ;
V_55 |= ( 1ull << 63 ) ;
V_204 = 16 ;
V_55 |= V_204 - 1 ;
F_135 () ;
while ( V_29 <= V_55 ) {
if ( V_198 )
F_136 ( F_137 ( V_29 ) , V_203 ) ;
else
F_138 ( F_137 ( V_29 ) , V_203 ) ;
V_29 += V_204 ;
}
}
static int F_139 ( struct V_170 * V_171 , long V_68 ,
long V_197 , unsigned long V_207 ,
enum V_208 V_209 ,
unsigned long V_210 )
{
int V_117 = F_140 ( V_171 , V_68 , V_197 , V_207 , V_209 ,
V_210 ) ;
if ( ! V_117 )
F_131 ( V_171 , V_68 , V_197 , false ) ;
return V_117 ;
}
static int F_141 ( struct V_170 * V_171 , long V_68 ,
unsigned long * V_211 , enum V_208 * V_209 )
{
long V_117 = F_142 ( V_171 , V_68 , V_211 , V_209 ) ;
if ( ! V_117 )
F_131 ( V_171 , V_68 , 1 , false ) ;
return V_117 ;
}
static void F_143 ( struct V_170 * V_171 , long V_68 ,
long V_197 )
{
F_144 ( V_171 , V_68 , V_197 ) ;
F_131 ( V_171 , V_68 , V_197 , false ) ;
}
void F_145 ( struct V_25 * V_26 , bool V_198 )
{
T_13 T_14 * V_203 = F_130 ( V_26 , V_198 ) ;
const unsigned long V_212 = V_213 ;
F_135 () ;
if ( V_198 )
F_136 ( F_137 ( V_212 ) , V_203 ) ;
else
F_138 ( F_137 ( V_212 ) , V_203 ) ;
}
static inline void F_146 ( struct V_1 * V_2 )
{
T_13 T_14 * V_203 = F_130 ( V_2 -> V_26 , false ) ;
unsigned long V_212 = V_214 | ( V_2 -> V_21 & 0xFF ) ;
F_135 () ;
F_138 ( F_137 ( V_212 ) , V_203 ) ;
}
static void F_147 ( struct V_1 * V_2 , bool V_198 ,
unsigned V_215 , unsigned long V_68 ,
unsigned long V_197 )
{
T_13 T_14 * V_203 = F_130 ( V_2 -> V_26 , V_198 ) ;
unsigned long V_29 , V_55 , V_204 ;
V_29 = V_216 ;
V_29 |= ( V_2 -> V_21 & 0xFF ) ;
V_55 = V_29 ;
V_29 |= ( V_68 << V_215 ) ;
V_55 |= ( ( V_68 + V_197 - 1 ) << V_215 ) ;
V_204 = ( 0x1ull << V_215 ) ;
F_135 () ;
while ( V_29 <= V_55 ) {
if ( V_198 )
F_136 ( F_137 ( V_29 ) , V_203 ) ;
else
F_138 ( F_137 ( V_29 ) , V_203 ) ;
V_29 += V_204 ;
}
}
static inline void F_148 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_26 -> V_217 == V_218 && V_26 -> V_196 )
F_146 ( V_2 ) ;
else
F_149 ( V_26 -> V_46 , V_219 ,
V_2 -> V_21 , 0 , 0 , 0 ) ;
}
static void F_150 ( struct V_170 * V_171 ,
unsigned long V_68 , unsigned long V_197 , bool V_198 )
{
struct V_199 * V_200 ;
F_151 (tgl, &tbl->it_group_list, next) {
struct V_1 * V_2 = F_133 ( V_200 -> V_172 ,
struct V_1 , V_172 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_215 = V_171 -> V_220 ;
if ( V_26 -> type == V_139 ) {
F_145 ( V_26 , V_198 ) ;
continue;
}
if ( V_26 -> V_217 == V_218 && V_26 -> V_196 )
F_147 ( V_2 , V_198 , V_215 ,
V_68 , V_197 ) ;
else if ( V_198 )
F_152 ( V_26 -> V_46 ,
V_221 ,
V_2 -> V_21 , 1u << V_215 ,
V_68 << V_215 , V_197 ) ;
else
F_149 ( V_26 -> V_46 ,
V_221 ,
V_2 -> V_21 , 1u << V_215 ,
V_68 << V_215 , V_197 ) ;
}
}
static int F_153 ( struct V_170 * V_171 , long V_68 ,
long V_197 , unsigned long V_207 ,
enum V_208 V_209 ,
unsigned long V_210 )
{
int V_117 = F_140 ( V_171 , V_68 , V_197 , V_207 , V_209 ,
V_210 ) ;
if ( ! V_117 )
F_150 ( V_171 , V_68 , V_197 , false ) ;
return V_117 ;
}
static int F_154 ( struct V_170 * V_171 , long V_68 ,
unsigned long * V_211 , enum V_208 * V_209 )
{
long V_117 = F_142 ( V_171 , V_68 , V_211 , V_209 ) ;
if ( ! V_117 )
F_150 ( V_171 , V_68 , 1 , false ) ;
return V_117 ;
}
static void F_155 ( struct V_170 * V_171 , long V_68 ,
long V_197 )
{
F_144 ( V_171 , V_68 , V_197 ) ;
F_150 ( V_171 , V_68 , V_197 , false ) ;
}
static void F_156 ( struct V_170 * V_171 )
{
F_97 ( V_171 ) ;
F_98 ( V_171 , L_62 ) ;
}
static int F_157 ( struct V_58 * V_12 , void * V_222 )
{
unsigned int * V_223 = ( unsigned int * ) V_222 ;
if ( V_12 -> V_224 != V_225 )
return 0 ;
if ( V_12 -> V_226 == V_227 ||
V_12 -> V_226 == V_228 ||
V_12 -> V_226 == V_229 )
* V_223 += 3 ;
else if ( ( V_12 -> V_226 >> 8 ) == V_230 )
* V_223 += 15 ;
else
* V_223 += 10 ;
return 0 ;
}
static unsigned int F_158 ( struct V_1 * V_2 )
{
unsigned int V_223 = 0 ;
#ifdef F_5
if ( ( V_2 -> V_9 & V_17 ) && V_2 -> V_18 ) {
F_157 ( V_2 -> V_18 , & V_223 ) ;
return V_223 ;
}
#endif
if ( ( V_2 -> V_9 & V_10 ) && V_2 -> V_11 ) {
F_157 ( V_2 -> V_11 , & V_223 ) ;
} else if ( ( V_2 -> V_9 & V_13 ) && V_2 -> V_15 ) {
struct V_58 * V_11 ;
F_33 (pdev, &pe->pbus->devices, bus_list)
F_157 ( V_11 , & V_223 ) ;
} else if ( ( V_2 -> V_9 & V_14 ) && V_2 -> V_15 ) {
F_159 ( V_2 -> V_15 , F_157 , & V_223 ) ;
}
return V_223 ;
}
static void F_160 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_231 * V_232 = NULL ;
struct V_170 * V_171 ;
unsigned int V_223 , V_233 = 0 ;
unsigned int V_234 , V_62 , V_235 , V_236 , V_65 ;
T_5 V_45 ;
void * V_237 ;
V_223 = F_158 ( V_2 ) ;
if ( ! V_223 )
return;
F_159 ( V_26 -> V_40 -> V_19 , F_157 ,
& V_233 ) ;
V_235 = ( V_223 * V_26 -> V_30 . V_238 ) / V_233 ;
if ( ! V_235 )
V_235 = 1 ;
do {
for ( V_62 = 0 ; V_62 <= V_26 -> V_30 . V_238 - V_235 ; V_62 ++ ) {
for ( V_236 = 0 , V_65 = V_62 ; V_65 < V_62 + V_235 ; V_65 ++ ) {
if ( V_26 -> V_30 . V_239 [ V_65 ] ==
V_110 )
V_236 ++ ;
}
if ( V_236 == V_235 )
goto V_240;
}
} while ( -- V_235 );
if ( ! V_235 ) {
F_60 ( V_2 , L_63 ) ;
return;
}
V_240:
V_171 = F_161 ( V_26 -> V_40 -> V_241 ) ;
F_162 ( & V_2 -> V_172 , V_26 -> V_40 -> V_41 ,
V_2 -> V_21 ) ;
F_163 ( V_26 -> V_40 -> V_241 , 0 , V_171 , & V_2 -> V_172 ) ;
F_78 ( V_2 , L_64 ,
V_223 , V_233 , V_62 , V_235 ) ;
F_78 ( V_2 , L_65 ,
V_62 * V_242 ,
( V_62 + V_235 ) * V_242 - 1 ) ;
V_234 = V_242 >> ( V_243 - 3 ) ;
V_232 = F_164 ( V_26 -> V_40 -> V_241 , V_77 ,
F_165 ( V_234 * V_235 ) ) ;
if ( ! V_232 ) {
F_65 ( V_2 , L_66 ) ;
goto V_50;
}
V_237 = F_166 ( V_232 ) ;
memset ( V_237 , 0 , V_234 * V_235 ) ;
for ( V_65 = 0 ; V_65 < V_235 ; V_65 ++ ) {
V_45 = F_167 ( V_26 -> V_46 ,
V_2 -> V_21 ,
V_62 + V_65 , 1 ,
F_134 ( V_237 ) + V_234 * V_65 ,
V_234 , V_244 ) ;
if ( V_45 ) {
F_65 ( V_2 , L_67
L_68 , V_45 ) ;
goto V_50;
}
}
for ( V_65 = V_62 ; V_65 < V_62 + V_235 ; V_65 ++ )
V_26 -> V_30 . V_239 [ V_65 ] = V_2 -> V_21 ;
F_168 ( V_171 , V_237 , V_234 * V_235 ,
V_62 * V_242 ,
V_243 ) ;
V_171 -> V_245 = & V_246 ;
V_2 -> V_172 . V_247 = V_171 -> V_206 << V_171 -> V_220 ;
V_2 -> V_172 . V_248 = V_171 -> V_249 << V_171 -> V_220 ;
F_169 ( V_171 , V_26 -> V_40 -> V_241 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_120 ( & V_2 -> V_11 -> V_12 , V_171 ) ;
F_129 ( & V_2 -> V_11 -> V_12 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_128 ( V_2 , V_2 -> V_15 ) ;
return;
V_50:
if ( V_232 )
F_170 ( V_232 , F_165 ( V_234 * V_235 ) ) ;
if ( V_171 ) {
F_171 ( V_171 , & V_2 -> V_172 ) ;
F_98 ( V_171 , L_62 ) ;
}
}
static long F_172 ( struct V_250 * V_172 ,
int V_251 , struct V_170 * V_171 )
{
struct V_1 * V_2 = F_133 ( V_172 , struct V_1 ,
V_172 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_5 V_45 ;
const unsigned long V_76 = V_171 -> V_252 ?
V_171 -> V_253 : V_171 -> V_249 ;
const T_15 V_254 = V_171 -> V_206 << V_171 -> V_220 ;
const T_15 V_255 = V_171 -> V_249 << V_171 -> V_220 ;
F_78 ( V_2 , L_69 , V_251 ,
V_254 , V_254 + V_255 - 1 ,
F_173 ( V_171 ) ) ;
V_45 = F_167 ( V_26 -> V_46 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_251 ,
V_171 -> V_252 + 1 ,
F_134 ( V_171 -> V_205 ) ,
V_76 << 3 ,
F_173 ( V_171 ) ) ;
if ( V_45 ) {
F_65 ( V_2 , L_70 , V_45 ) ;
return V_45 ;
}
F_163 ( V_26 -> V_40 -> V_241 , V_251 ,
V_171 , & V_2 -> V_172 ) ;
F_148 ( V_2 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , bool V_256 )
{
T_16 V_257 = ( V_2 -> V_21 << 1 ) + 1 ;
T_5 V_45 ;
F_78 ( V_2 , L_71 , V_256 ? L_41 : L_42 ) ;
if ( V_256 ) {
T_17 V_188 = F_122 () ;
V_188 = F_174 ( V_188 ) ;
V_45 = F_175 ( V_2 -> V_26 -> V_46 ,
V_2 -> V_21 ,
V_257 ,
V_2 -> V_186 ,
V_188 ) ;
} else {
V_45 = F_175 ( V_2 -> V_26 -> V_46 ,
V_2 -> V_21 ,
V_257 ,
V_2 -> V_186 ,
0 ) ;
}
if ( V_45 )
F_65 ( V_2 , L_72 , V_45 ) ;
else
V_2 -> V_191 = V_256 ;
}
static long F_176 ( struct V_250 * V_172 ,
int V_251 , T_18 V_258 , T_15 V_259 , T_18 V_260 ,
struct V_170 * * V_261 )
{
struct V_1 * V_2 = F_133 ( V_172 , struct V_1 ,
V_172 ) ;
int V_262 = V_2 -> V_26 -> V_40 -> V_241 ;
T_15 V_263 = V_251 ? V_2 -> V_186 : V_172 -> V_247 ;
long V_117 ;
struct V_170 * V_171 ;
V_171 = F_161 ( V_262 ) ;
if ( ! V_171 )
return - V_167 ;
V_117 = F_177 ( V_262 ,
V_263 , V_258 , V_259 ,
V_260 , V_171 ) ;
if ( V_117 ) {
F_98 ( V_171 , L_62 ) ;
return V_117 ;
}
V_171 -> V_245 = & V_264 ;
* V_261 = V_171 ;
return 0 ;
}
static long F_178 ( struct V_1 * V_2 )
{
struct V_170 * V_171 = NULL ;
long V_45 ;
const T_7 V_265 = F_179 ( F_180 () ) ;
const T_7 V_259 = F_181 ( ( T_7 ) V_2 -> V_172 . V_248 , V_265 ) ;
V_45 = F_176 ( & V_2 -> V_172 , 0 ,
V_243 ,
V_259 ,
V_266 , & V_171 ) ;
if ( V_45 ) {
F_65 ( V_2 , L_73 ,
V_45 ) ;
return V_45 ;
}
F_169 ( V_171 , V_2 -> V_26 -> V_40 -> V_241 ) ;
V_45 = F_172 ( & V_2 -> V_172 , 0 , V_171 ) ;
if ( V_45 ) {
F_65 ( V_2 , L_74 ,
V_45 ) ;
F_156 ( V_171 ) ;
return V_45 ;
}
if ( ! V_24 )
F_94 ( V_2 , true ) ;
if ( V_2 -> V_9 & V_10 )
F_120 ( & V_2 -> V_11 -> V_12 , V_171 ) ;
return 0 ;
}
static long F_93 ( struct V_250 * V_172 ,
int V_251 )
{
struct V_1 * V_2 = F_133 ( V_172 , struct V_1 ,
V_172 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
long V_117 ;
F_78 ( V_2 , L_75 , V_251 ) ;
V_117 = F_167 ( V_26 -> V_46 , V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_251 ,
0 , 0 ,
0 , 0 ) ;
if ( V_117 )
F_60 ( V_2 , L_76 , V_117 ) ;
else
F_148 ( V_2 ) ;
F_171 ( V_172 -> V_173 [ V_251 ] , V_172 ) ;
return V_117 ;
}
static unsigned long F_182 ( T_18 V_258 ,
T_15 V_259 , T_18 V_260 )
{
unsigned long V_267 = 0 ;
const unsigned V_268 = F_183 ( V_259 ) ;
unsigned V_269 = V_268 - V_258 ;
unsigned V_270 = V_269 + 3 ;
unsigned long V_271 = F_184 ( 0x1000UL , 1UL << V_270 ) ;
unsigned long V_272 ;
if ( ! V_260 || ( V_260 > V_273 ) ||
( V_259 > F_180 () ) ||
! F_185 ( V_259 ) )
return 0 ;
V_269 = ( V_269 + V_260 - 1 ) / V_260 ;
V_270 = V_269 + 3 ;
V_270 = F_186 ( unsigned , V_270 , V_274 ) ;
V_272 = 1UL << V_270 ;
for ( ; V_260 ; -- V_260 ) {
V_267 += F_28 ( V_271 , V_272 ) ;
V_271 /= V_272 ;
V_271 <<= 3 ;
V_271 = F_28 ( V_271 , V_272 ) ;
}
return V_267 ;
}
static void F_187 ( struct V_250 * V_172 )
{
struct V_1 * V_2 = F_133 ( V_172 , struct V_1 ,
V_172 ) ;
struct V_170 * V_171 = V_2 -> V_172 . V_173 [ 0 ] ;
F_94 ( V_2 , false ) ;
F_93 ( & V_2 -> V_172 , 0 ) ;
F_156 ( V_171 ) ;
}
static void F_188 ( struct V_250 * V_172 )
{
struct V_1 * V_2 = F_133 ( V_172 , struct V_1 ,
V_172 ) ;
F_178 ( V_2 ) ;
}
static int F_189 ( struct V_275 * V_12 , void * V_276 )
{
struct V_60 * V_40 ;
struct V_25 * V_26 ;
struct V_1 * * V_277 = V_276 ;
struct V_58 * V_11 = F_133 ( V_12 , struct V_58 , V_12 ) ;
struct V_108 * V_109 = F_57 ( V_11 ) ;
if ( ! V_109 || V_109 -> V_21 == V_110 )
return 0 ;
V_40 = F_26 ( V_11 -> V_19 ) ;
V_26 = V_40 -> V_61 ;
if ( V_26 -> type != V_139 )
return 0 ;
* V_277 = & V_26 -> V_30 . V_37 [ V_109 -> V_21 ] ;
return 1 ;
}
static struct V_1 * F_190 (
struct V_250 * V_172 )
{
struct V_1 * V_278 = NULL ;
int V_117 = F_191 ( V_172 -> V_174 , & V_278 ,
F_189 ) ;
F_96 ( ! V_117 || ! V_278 ) ;
return V_278 ;
}
static long F_192 ( struct V_250 * V_172 ,
int V_251 , struct V_170 * V_171 )
{
long V_117 = F_172 ( V_172 , V_251 , V_171 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_193 ( F_190 ( V_172 ) , V_251 , V_171 ) ;
if ( V_117 )
F_93 ( V_172 , V_251 ) ;
return V_117 ;
}
static long F_194 (
struct V_250 * V_172 ,
int V_251 )
{
long V_117 = F_93 ( V_172 , V_251 ) ;
if ( V_117 )
return V_117 ;
return F_195 ( F_190 ( V_172 ) , V_251 ) ;
}
static void F_196 ( struct V_250 * V_172 )
{
F_197 ( F_190 ( V_172 ) ) ;
F_187 ( V_172 ) ;
}
static void F_198 ( void )
{
struct V_60 * V_40 , * V_159 ;
struct V_25 * V_26 ;
struct V_1 * V_2 , * V_279 ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_40 -> V_61 ;
if ( V_26 -> type != V_139 )
continue;
F_33 (pe, &phb->ioda.pe_list, list) {
V_279 = F_199 ( V_2 ) ;
if ( V_279 )
V_279 -> V_172 . V_280 = & V_281 ;
}
}
}
static void F_198 ( void ) { }
static T_13 * F_200 ( int V_262 , unsigned V_215 ,
unsigned V_260 , unsigned long V_282 ,
unsigned long * V_283 , unsigned long * V_284 )
{
struct V_231 * V_232 = NULL ;
T_13 * V_237 , * V_159 ;
unsigned V_285 = F_186 ( unsigned , V_215 , V_274 ) - V_274 ;
unsigned long V_286 = 1UL << ( V_285 + V_274 ) ;
unsigned V_287 = 1UL << ( V_215 - 3 ) ;
long V_65 ;
V_232 = F_164 ( V_262 , V_77 , V_285 ) ;
if ( ! V_232 ) {
F_74 ( L_77 , V_285 ) ;
return NULL ;
}
V_237 = F_166 ( V_232 ) ;
memset ( V_237 , 0 , V_286 ) ;
* V_284 += V_286 ;
-- V_260 ;
if ( ! V_260 ) {
* V_283 += V_286 ;
return V_237 ;
}
for ( V_65 = 0 ; V_65 < V_287 ; ++ V_65 ) {
V_159 = F_200 ( V_262 , V_215 ,
V_260 , V_282 , V_283 , V_284 ) ;
if ( ! V_159 )
break;
V_237 [ V_65 ] = F_137 ( F_134 ( V_159 ) |
V_288 | V_289 ) ;
if ( * V_283 >= V_282 )
break;
}
return V_237 ;
}
static long F_177 ( int V_262 , T_15 V_263 ,
T_18 V_258 , T_15 V_259 , T_18 V_260 ,
struct V_170 * V_171 )
{
void * V_237 ;
unsigned long V_143 = 0 , V_290 , V_284 = 0 ;
const unsigned V_268 = F_183 ( V_259 ) ;
unsigned V_269 = V_268 - V_258 ;
unsigned V_270 = F_186 ( unsigned , V_269 + 3 , V_274 ) ;
const unsigned long V_271 = 1UL << V_270 ;
if ( ! V_260 || ( V_260 > V_273 ) )
return - V_23 ;
if ( ( V_259 > F_180 () ) || ! F_185 ( V_259 ) )
return - V_23 ;
V_269 = ( V_269 + V_260 - 1 ) / V_260 ;
V_290 = V_269 + 3 ;
V_290 = F_186 ( unsigned , V_290 , V_274 ) ;
V_237 = F_200 ( V_262 , V_290 ,
V_260 , V_271 , & V_143 , & V_284 ) ;
if ( ! V_237 )
return - V_167 ;
if ( V_143 < V_271 ) {
F_201 ( V_237 ,
1ULL << ( V_290 - 3 ) , V_260 - 1 ) ;
return - V_167 ;
}
F_168 ( V_171 , V_237 , V_271 , V_263 ,
V_258 ) ;
V_171 -> V_253 = 1ULL << ( V_290 - 3 ) ;
V_171 -> V_252 = V_260 - 1 ;
V_171 -> V_291 = V_284 ;
F_202 ( L_78 ,
V_259 , V_271 , V_263 ) ;
return 0 ;
}
static void F_201 ( T_13 * V_237 ,
unsigned long V_76 , unsigned V_3 )
{
const unsigned long V_292 = ( unsigned long ) V_237 &
~ ( V_288 | V_289 ) ;
if ( V_3 ) {
long V_65 ;
T_7 * V_159 = ( T_7 * ) V_292 ;
for ( V_65 = 0 ; V_65 < V_76 ; ++ V_65 ) {
unsigned long V_211 = F_203 ( V_159 [ V_65 ] ) ;
if ( ! ( V_211 & ( V_288 | V_289 ) ) )
continue;
F_201 ( F_204 ( V_211 ) , V_76 ,
V_3 - 1 ) ;
}
}
F_205 ( V_292 , F_165 ( V_76 << 3 ) ) ;
}
static void F_97 ( struct V_170 * V_171 )
{
const unsigned long V_76 = V_171 -> V_252 ?
V_171 -> V_253 : V_171 -> V_249 ;
if ( ! V_171 -> V_249 )
return;
F_201 ( ( T_13 * ) V_171 -> V_205 , V_76 ,
V_171 -> V_252 ) ;
}
static void F_109 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
T_5 V_45 ;
if ( ! F_158 ( V_2 ) )
return;
V_2 -> V_186 = 1ull << 59 ;
F_162 ( & V_2 -> V_172 , V_26 -> V_40 -> V_41 ,
V_2 -> V_21 ) ;
F_78 ( V_2 , L_79 ,
V_26 -> V_30 . V_293 ) ;
V_2 -> V_172 . V_247 = 0 ;
V_2 -> V_172 . V_248 = V_26 -> V_30 . V_293 ;
V_2 -> V_172 . V_294 =
V_295 ;
V_2 -> V_172 . V_296 = V_273 ;
V_2 -> V_172 . V_297 = V_298 | V_299 | V_300 ;
#ifdef F_206
V_2 -> V_172 . V_280 = & V_301 ;
#endif
V_45 = F_178 ( V_2 ) ;
if ( V_45 )
return;
if ( V_2 -> V_9 & V_10 )
F_129 ( & V_2 -> V_11 -> V_12 ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_128 ( V_2 , V_2 -> V_15 ) ;
}
static void F_207 ( struct V_302 * V_303 )
{
unsigned int V_304 = ( unsigned int ) F_208 ( V_303 ) ;
struct V_305 * V_306 = F_209 ( V_303 ) ;
struct V_25 * V_26 = F_133 ( V_306 , struct V_25 ,
V_30 . V_305 ) ;
T_5 V_45 ;
V_45 = F_210 ( V_26 -> V_46 , V_304 ) ;
F_211 ( V_45 ) ;
F_212 ( V_303 ) ;
}
void F_213 ( struct V_25 * V_26 , unsigned int V_307 )
{
struct V_302 * V_308 ;
struct V_305 * V_309 ;
if ( V_26 -> V_217 != V_218 )
return;
if ( ! V_26 -> V_30 . V_310 ) {
V_308 = F_214 ( V_307 ) ;
V_309 = F_209 ( V_308 ) ;
V_26 -> V_30 . V_310 = 1 ;
V_26 -> V_30 . V_305 = * V_309 ;
V_26 -> V_30 . V_305 . V_311 = F_207 ;
}
F_215 ( V_307 , & V_26 -> V_30 . V_305 ) ;
}
static int F_216 ( struct V_25 * V_26 , struct V_58 * V_12 ,
unsigned int V_312 , unsigned int V_307 ,
unsigned int V_313 , struct V_314 * V_315 )
{
struct V_1 * V_2 = F_56 ( V_12 ) ;
unsigned int V_316 = V_312 - V_26 -> V_317 ;
T_19 V_222 ;
int V_45 ;
if ( V_2 == NULL )
return - V_116 ;
if ( V_2 -> V_140 < 0 )
return - V_116 ;
if ( V_12 -> V_318 )
V_313 = 0 ;
V_45 = F_217 ( V_26 -> V_46 , V_2 -> V_21 , V_316 ) ;
if ( V_45 ) {
F_15 ( L_80 ,
F_75 ( V_12 ) , V_45 , V_316 ) ;
return - V_57 ;
}
if ( V_313 ) {
T_13 V_319 ;
V_45 = F_218 ( V_26 -> V_46 , V_2 -> V_140 , V_316 , 1 ,
& V_319 , & V_222 ) ;
if ( V_45 ) {
F_15 ( L_81 ,
F_75 ( V_12 ) , V_45 ) ;
return - V_57 ;
}
V_315 -> V_320 = F_203 ( V_319 ) >> 32 ;
V_315 -> V_321 = F_203 ( V_319 ) & 0xfffffffful ;
} else {
T_19 V_322 ;
V_45 = F_219 ( V_26 -> V_46 , V_2 -> V_140 , V_316 , 1 ,
& V_322 , & V_222 ) ;
if ( V_45 ) {
F_15 ( L_82 ,
F_75 ( V_12 ) , V_45 ) ;
return - V_57 ;
}
V_315 -> V_320 = 0 ;
V_315 -> V_321 = F_220 ( V_322 ) ;
}
V_315 -> V_222 = F_220 ( V_222 ) ;
F_213 ( V_26 , V_307 ) ;
F_202 ( L_83
L_84 ,
F_75 ( V_12 ) , V_313 ? L_85 : L_86 , V_312 , V_316 ,
V_315 -> V_320 , V_315 -> V_321 , V_222 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_221 ( struct V_25 * V_26 )
{
unsigned int V_124 ;
const T_19 * V_323 = F_45 ( V_26 -> V_40 -> V_86 ,
L_87 , NULL ) ;
if ( ! V_323 ) {
V_323 = F_45 ( V_26 -> V_40 -> V_86 , L_88 , NULL ) ;
}
if ( ! V_323 )
return;
V_26 -> V_317 = F_222 ( V_323 ) ;
V_124 = F_222 ( V_323 + 1 ) ;
if ( F_223 ( & V_26 -> V_324 , V_124 , V_26 -> V_40 -> V_86 ) ) {
F_74 ( L_89 ,
V_26 -> V_40 -> V_41 ) ;
return;
}
V_26 -> V_325 = F_216 ;
V_26 -> V_326 = 1 ;
F_10 ( L_90 ,
V_124 , V_26 -> V_317 ) ;
}
static void F_221 ( struct V_25 * V_26 ) { }
static void F_224 ( struct V_58 * V_11 )
{
struct V_60 * V_40 = F_26 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
const T_4 V_327 = V_26 -> V_30 . V_54 >> 2 ;
struct V_27 * V_87 ;
int V_65 ;
T_4 V_76 , V_328 ;
struct V_108 * V_109 ;
int V_329 , V_166 ;
if ( ! V_11 -> V_146 || V_11 -> V_330 )
return;
V_109 = F_57 ( V_11 ) ;
V_109 -> V_182 = 0 ;
V_109 -> V_162 = false ;
V_166 = F_89 ( V_11 ) ;
V_329 = V_26 -> V_30 . V_38 ;
V_328 = 0 ;
for ( V_65 = 0 ; V_65 < V_147 ; V_65 ++ ) {
V_87 = & V_11 -> V_27 [ V_65 + V_148 ] ;
if ( ! V_87 -> V_9 || V_87 -> V_67 )
continue;
if ( ! F_12 ( V_87 -> V_9 ) ) {
F_225 ( & V_11 -> V_12 , L_91
L_92 ,
V_65 , V_87 ) ;
goto V_331;
}
V_328 += F_70 ( V_11 ,
V_65 + V_148 ) ;
if ( V_328 > V_327 ) {
V_329 = F_174 ( V_166 ) ;
F_71 ( & V_11 -> V_12 ,
L_93 ,
V_328 , V_327 , V_329 ) ;
V_109 -> V_162 = true ;
break;
}
}
for ( V_65 = 0 ; V_65 < V_147 ; V_65 ++ ) {
V_87 = & V_11 -> V_27 [ V_65 + V_148 ] ;
if ( ! V_87 -> V_9 || V_87 -> V_67 )
continue;
V_76 = F_70 ( V_11 , V_65 + V_148 ) ;
if ( V_109 -> V_162 && ( V_76 < V_332 ) )
goto V_331;
F_226 ( & V_11 -> V_12 , L_94 , V_65 , V_87 ) ;
V_87 -> V_55 = V_87 -> V_29 + V_76 * V_329 - 1 ;
F_226 ( & V_11 -> V_12 , L_95 , V_87 ) ;
F_71 ( & V_11 -> V_12 , L_96 ,
V_65 , V_87 , V_329 ) ;
}
V_109 -> V_182 = V_329 ;
return;
V_331:
for ( V_65 = 0 ; V_65 < V_147 ; V_65 ++ ) {
V_87 = & V_11 -> V_27 [ V_65 + V_148 ] ;
V_87 -> V_9 = 0 ;
V_87 -> V_55 = V_87 -> V_29 - 1 ;
}
}
static void F_227 ( struct V_1 * V_2 ,
struct V_27 * V_87 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_333 V_334 ;
int V_68 ;
T_5 V_45 ;
if ( ! V_87 || ! V_87 -> V_9 || V_87 -> V_29 > V_87 -> V_55 )
return;
if ( V_87 -> V_9 & V_335 ) {
V_334 . V_29 = V_87 -> V_29 - V_26 -> V_30 . V_336 ;
V_334 . V_55 = V_87 -> V_55 - V_26 -> V_30 . V_336 ;
V_68 = V_334 . V_29 / V_26 -> V_30 . V_337 ;
while ( V_68 < V_26 -> V_30 . V_38 &&
V_334 . V_29 <= V_334 . V_55 ) {
V_26 -> V_30 . V_338 [ V_68 ] = V_2 -> V_21 ;
V_45 = F_42 ( V_26 -> V_46 ,
V_2 -> V_21 , V_339 , 0 , V_68 ) ;
if ( V_45 != V_49 ) {
F_74 ( L_97 ,
V_39 , V_45 , V_68 , V_2 -> V_21 ) ;
break;
}
V_334 . V_29 += V_26 -> V_30 . V_337 ;
V_68 ++ ;
}
} else if ( ( V_87 -> V_9 & V_94 ) &&
! F_11 ( V_26 , V_87 ) ) {
V_334 . V_29 = V_87 -> V_29 -
V_26 -> V_40 -> V_95 [ 0 ] -
V_26 -> V_30 . V_293 ;
V_334 . V_55 = V_87 -> V_55 -
V_26 -> V_40 -> V_95 [ 0 ] -
V_26 -> V_30 . V_293 ;
V_68 = V_334 . V_29 / V_26 -> V_30 . V_340 ;
while ( V_68 < V_26 -> V_30 . V_38 &&
V_334 . V_29 <= V_334 . V_55 ) {
V_26 -> V_30 . V_341 [ V_68 ] = V_2 -> V_21 ;
V_45 = F_42 ( V_26 -> V_46 ,
V_2 -> V_21 , V_342 , 0 , V_68 ) ;
if ( V_45 != V_49 ) {
F_74 ( L_98 ,
V_39 , V_45 , V_68 , V_2 -> V_21 ) ;
break;
}
V_334 . V_29 += V_26 -> V_30 . V_340 ;
V_68 ++ ;
}
}
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_58 * V_11 ;
int V_65 ;
F_96 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_33 (pdev, &pe->pbus->devices, bus_list) {
for ( V_65 = 0 ; V_65 <= V_66 ; V_65 ++ )
F_227 ( V_2 , & V_11 -> V_27 [ V_65 ] ) ;
if ( ! ( V_2 -> V_9 & V_14 ) || ! F_229 ( V_11 ) )
continue;
for ( V_65 = 0 ; V_65 < V_343 ; V_65 ++ )
F_227 ( V_2 ,
& V_11 -> V_27 [ V_344 + V_65 ] ) ;
}
}
static void F_230 ( void )
{
#ifdef F_231
struct V_60 * V_40 , * V_159 ;
struct V_25 * V_26 ;
char V_93 [ 16 ] ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_40 -> V_61 ;
V_26 -> V_345 = 1 ;
sprintf ( V_93 , L_99 , V_40 -> V_41 ) ;
V_26 -> V_346 = F_232 ( V_93 , V_347 ) ;
if ( ! V_26 -> V_346 )
F_76 ( L_100 ,
V_39 , V_40 -> V_41 ) ;
}
#endif
}
static void F_233 ( void )
{
F_85 () ;
F_198 () ;
F_230 () ;
#ifdef F_234
F_235 () ;
F_236 () ;
#endif
}
static T_4 F_237 ( struct V_72 * V_19 ,
unsigned long type )
{
struct V_58 * V_348 ;
struct V_60 * V_40 = F_26 ( V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
int V_349 = 0 ;
V_348 = V_19 -> V_119 ;
while ( V_348 ) {
if ( F_238 ( V_348 ) == V_350 ) {
V_349 ++ ;
if ( V_349 >= 2 )
return 1 ;
}
V_348 = V_348 -> V_19 -> V_119 ;
}
if ( V_26 -> V_30 . V_54 && F_12 ( type ) )
return V_26 -> V_30 . V_54 ;
if ( type & V_94 )
return V_26 -> V_30 . V_340 ;
return V_26 -> V_30 . V_337 ;
}
static void F_239 ( struct V_72 * V_19 ,
unsigned long type )
{
struct V_60 * V_40 = F_26 ( V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_58 * V_348 = V_19 -> V_119 ;
struct V_27 * V_28 , * V_351 ;
bool V_352 = false ;
int V_65 ;
if ( ! F_35 ( V_348 -> V_19 ) &&
! F_35 ( V_348 -> V_19 -> V_119 -> V_19 ) )
return;
for ( V_65 = 0 ; V_65 < V_343 ; V_65 ++ ) {
V_28 = & V_348 -> V_27 [ V_344 + V_65 ] ;
if ( ! V_28 -> V_9 || ! V_28 -> V_67 )
continue;
V_351 = NULL ;
if ( V_28 -> V_9 & type & V_335 )
V_351 = & V_40 -> V_353 ;
else if ( F_11 ( V_26 , V_28 ) &&
( type & V_35 ) &&
V_26 -> V_30 . V_54 )
V_351 = & V_40 -> V_52 [ 1 ] ;
else if ( V_28 -> V_9 & type & V_94 ) {
V_351 = & V_40 -> V_52 [ 0 ] ;
V_352 = true ;
}
V_28 -> V_29 = V_351 -> V_29 ;
V_28 -> V_55 = V_351 -> V_55 ;
if ( V_352 ) {
V_28 -> V_55 += 0x10000 ;
V_28 -> V_55 -= 0x100000 ;
}
}
}
static void F_240 ( struct V_72 * V_19 , unsigned long type )
{
struct V_60 * V_40 = F_26 ( V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_58 * V_348 = V_19 -> V_119 ;
struct V_1 * V_2 ;
bool V_73 = ( F_238 ( V_348 ) == V_350 ) ;
F_239 ( V_19 , type ) ;
if ( ! V_26 -> V_30 . V_354 ) {
V_2 = F_81 ( V_26 -> V_40 -> V_19 , false ) ;
if ( V_2 ) {
V_26 -> V_30 . V_154 = V_2 -> V_21 ;
V_26 -> V_30 . V_354 = true ;
}
}
if ( F_241 ( & V_19 -> V_355 ) )
return;
if ( V_26 -> V_98 )
V_26 -> V_98 ( V_19 , NULL , V_73 ) ;
V_2 = F_81 ( V_19 , V_73 ) ;
if ( ! V_2 )
return;
F_228 ( V_2 ) ;
switch ( V_26 -> type ) {
case V_84 :
F_160 ( V_26 , V_2 ) ;
break;
case V_90 :
F_109 ( V_26 , V_2 ) ;
break;
default:
F_15 ( L_101 ,
V_39 , V_26 -> V_40 -> V_41 , V_26 -> type ) ;
}
}
static T_4 F_242 ( struct V_58 * V_11 ,
int V_356 )
{
struct V_60 * V_40 = F_26 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_108 * V_109 = F_57 ( V_11 ) ;
T_4 V_357 ;
V_357 = F_70 ( V_11 , V_356 ) ;
if ( ! V_109 -> V_182 )
return V_357 ;
if ( V_109 -> V_162 )
return F_184 ( V_357 , ( T_4 ) V_26 -> V_30 . V_54 ) ;
return V_109 -> V_182 * V_357 ;
}
bool F_243 ( struct V_58 * V_12 )
{
struct V_60 * V_40 = F_26 ( V_12 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_108 * V_109 ;
if ( ! V_26 -> V_345 )
return true ;
V_109 = F_57 ( V_12 ) ;
if ( ! V_109 || V_109 -> V_21 == V_110 )
return false ;
return true ;
}
static long F_244 ( struct V_250 * V_172 ,
int V_251 )
{
struct V_1 * V_2 = F_133 ( V_172 ,
struct V_1 , V_172 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_358 ;
long V_45 ;
F_78 ( V_2 , L_75 , V_251 ) ;
for ( V_358 = 0 ; V_358 < V_26 -> V_30 . V_238 ; V_358 ++ ) {
if ( V_26 -> V_30 . V_239 [ V_358 ] != V_2 -> V_21 )
continue;
V_45 = F_167 ( V_26 -> V_46 , V_2 -> V_21 ,
V_358 , 0 , 0ul , 0ul , 0ul ) ;
if ( V_45 != V_49 ) {
F_60 ( V_2 , L_102 ,
V_45 , V_358 ) ;
return V_45 ;
}
V_26 -> V_30 . V_239 [ V_358 ] = V_110 ;
}
F_171 ( V_172 -> V_173 [ V_251 ] , V_172 ) ;
return V_49 ;
}
static void F_245 ( struct V_1 * V_2 )
{
unsigned int V_223 = F_158 ( V_2 ) ;
struct V_170 * V_171 = V_2 -> V_172 . V_173 [ 0 ] ;
T_5 V_45 ;
if ( ! V_223 )
return;
V_45 = F_244 ( & V_2 -> V_172 , 0 ) ;
if ( V_45 != V_49 )
return;
F_131 ( V_171 , V_171 -> V_206 , V_171 -> V_249 , false ) ;
if ( V_2 -> V_172 . V_174 ) {
F_95 ( V_2 -> V_172 . V_174 ) ;
F_20 ( V_2 -> V_172 . V_174 ) ;
}
F_205 ( V_171 -> V_205 , F_165 ( V_171 -> V_249 << 3 ) ) ;
F_98 ( V_171 , L_62 ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_170 * V_171 = V_2 -> V_172 . V_173 [ 0 ] ;
unsigned int V_223 = F_158 ( V_2 ) ;
#ifdef F_206
T_5 V_45 ;
#endif
if ( ! V_223 )
return;
#ifdef F_206
V_45 = F_93 ( & V_2 -> V_172 , 0 ) ;
if ( V_45 )
F_60 ( V_2 , L_53 , V_45 ) ;
#endif
F_94 ( V_2 , false ) ;
if ( V_2 -> V_172 . V_174 ) {
F_95 ( V_2 -> V_172 . V_174 ) ;
F_20 ( V_2 -> V_172 . V_174 ) ;
}
F_97 ( V_171 ) ;
F_98 ( V_171 , L_62 ) ;
}
static void F_247 ( struct V_1 * V_2 ,
unsigned short V_165 ,
unsigned int * V_359 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_358 ;
T_5 V_45 ;
for ( V_358 = 0 ; V_358 < V_26 -> V_30 . V_38 ; V_358 ++ ) {
if ( V_359 [ V_358 ] != V_2 -> V_21 )
continue;
if ( V_165 == V_47 )
V_45 = F_42 ( V_26 -> V_46 ,
V_26 -> V_30 . V_53 , V_165 ,
V_358 / V_71 ,
V_358 % V_71 ) ;
else
V_45 = F_42 ( V_26 -> V_46 ,
V_26 -> V_30 . V_53 , V_165 , 0 , V_358 ) ;
if ( V_45 != V_49 )
F_60 ( V_2 , L_103 ,
V_45 , V_165 , V_358 ) ;
V_359 [ V_358 ] = V_110 ;
}
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_26 -> type == V_84 ) {
F_247 ( V_2 , V_339 ,
V_26 -> V_30 . V_338 ) ;
F_247 ( V_2 , V_342 ,
V_26 -> V_30 . V_341 ) ;
F_247 ( V_2 , V_47 ,
V_26 -> V_30 . V_78 ) ;
} else if ( V_26 -> type == V_90 ) {
F_247 ( V_2 , V_342 ,
V_26 -> V_30 . V_341 ) ;
}
}
static void F_249 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_1 * V_100 , * V_159 ;
F_102 ( & V_2 -> V_83 ) ;
switch ( V_26 -> type ) {
case V_84 :
F_245 ( V_2 ) ;
break;
case V_90 :
F_246 ( V_2 ) ;
break;
default:
F_20 ( 1 ) ;
}
F_248 ( V_2 ) ;
F_62 ( V_2 -> V_26 , V_2 ) ;
if ( V_2 -> V_9 & V_79 ) {
F_86 (slave, tmp, &pe->slaves, list) {
F_102 ( & V_100 -> V_83 ) ;
F_19 ( V_100 ) ;
}
}
if ( V_26 -> V_30 . V_354 &&
V_26 -> V_30 . V_154 == V_2 -> V_21 )
V_26 -> V_30 . V_354 = false ;
else
F_19 ( V_2 ) ;
}
static void F_250 ( struct V_58 * V_11 )
{
struct V_60 * V_40 = F_26 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_40 -> V_61 ;
struct V_108 * V_109 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
if ( V_11 -> V_360 )
return;
if ( ! V_109 || V_109 -> V_21 == V_110 )
return;
V_2 = & V_26 -> V_30 . V_37 [ V_109 -> V_21 ] ;
V_109 -> V_21 = V_110 ;
F_20 ( -- V_2 -> V_153 < 0 ) ;
if ( V_2 -> V_153 == 0 )
F_249 ( V_2 ) ;
}
static void F_251 ( struct V_60 * V_40 )
{
struct V_25 * V_26 = V_40 -> V_61 ;
F_252 ( V_26 -> V_46 , V_361 ,
V_362 ) ;
}
static int F_253 ( struct V_58 * V_363 , T_7 V_187 )
{
F_254 ( & V_363 -> V_12 ,
L_104 ,
V_39 ) ;
return - V_364 ;
}
static void T_2 F_255 ( struct V_85 * V_365 ,
T_7 V_366 , int V_367 )
{
struct V_60 * V_40 ;
struct V_25 * V_26 ;
unsigned long V_76 , V_368 , V_369 , V_370 ;
unsigned long V_371 = 0 , V_372 = 0 ;
struct V_27 V_28 ;
const T_13 * V_373 ;
const T_19 * V_374 ;
int V_375 ;
unsigned int V_64 ;
T_7 V_376 ;
void * V_377 ;
long V_45 ;
if ( ! F_256 ( V_365 ) )
return;
F_10 ( L_105 ,
V_378 [ V_367 ] , F_99 ( V_365 ) ) ;
V_373 = F_45 ( V_365 , L_106 , NULL ) ;
if ( ! V_373 ) {
F_74 ( L_107 ) ;
return;
}
V_376 = F_257 ( V_373 ) ;
F_17 ( L_108 , V_376 ) ;
V_26 = F_258 ( sizeof( struct V_25 ) , 0 ) ;
V_26 -> V_40 = V_40 = F_259 ( V_365 ) ;
if ( ! V_26 -> V_40 ) {
F_74 ( L_109 ,
V_365 -> V_92 ) ;
F_260 ( F_134 ( V_26 ) , sizeof( struct V_25 ) ) ;
return;
}
F_261 ( & V_26 -> V_379 ) ;
V_374 = F_45 ( V_365 , L_110 , & V_375 ) ;
if ( V_374 && V_375 == 8 ) {
V_40 -> V_380 = F_220 ( V_374 [ 0 ] ) ;
V_40 -> V_381 = F_220 ( V_374 [ 1 ] ) ;
} else {
F_15 ( L_111 , V_365 -> V_92 ) ;
V_40 -> V_380 = 0 ;
V_40 -> V_381 = 0xff ;
}
V_40 -> V_61 = V_26 ;
V_26 -> V_366 = V_366 ;
V_26 -> V_46 = V_376 ;
V_26 -> type = V_367 ;
F_262 ( & V_26 -> V_30 . V_184 ) ;
if ( F_263 ( V_365 , L_112 ) )
V_26 -> V_217 = V_382 ;
else if ( F_263 ( V_365 , L_113 ) )
V_26 -> V_217 = V_218 ;
else if ( F_263 ( V_365 , L_114 ) )
V_26 -> V_217 = V_383 ;
else
V_26 -> V_217 = V_384 ;
F_264 ( V_40 , V_365 , ! V_40 -> V_41 ) ;
if ( ! F_265 ( V_365 , 0 , & V_28 ) ) {
V_26 -> V_195 = V_28 . V_29 ;
V_26 -> V_196 = F_266 ( V_28 . V_29 , F_49 ( & V_28 ) ) ;
if ( V_26 -> V_196 == NULL )
F_74 ( L_115 ) ;
}
V_26 -> V_30 . V_38 = 1 ;
V_374 = F_45 ( V_365 , L_116 , NULL ) ;
if ( V_374 )
V_26 -> V_30 . V_38 = F_222 ( V_374 ) ;
V_374 = F_45 ( V_365 , L_117 , NULL ) ;
if ( V_374 )
V_26 -> V_30 . V_53 = F_222 ( V_374 ) ;
for ( V_64 = 0 ; V_64 < F_267 ( V_26 -> V_30 . V_136 ) ; V_64 ++ )
V_26 -> V_30 . V_136 [ V_64 ] = V_110 ;
F_43 ( V_26 ) ;
V_26 -> V_30 . V_385 = F_49 ( & V_40 -> V_52 [ 0 ] ) ;
V_26 -> V_30 . V_385 += 0x10000 ;
V_26 -> V_30 . V_340 = V_26 -> V_30 . V_385 / V_26 -> V_30 . V_38 ;
V_26 -> V_30 . V_293 = V_40 -> V_52 [ 0 ] . V_29 - V_40 -> V_95 [ 0 ] ;
V_26 -> V_30 . V_386 = V_40 -> V_387 ;
V_26 -> V_30 . V_337 = V_26 -> V_30 . V_386 / V_26 -> V_30 . V_38 ;
V_26 -> V_30 . V_336 = 0 ;
V_26 -> V_30 . V_238 = V_26 -> V_30 . V_293 /
V_242 ;
V_76 = F_28 ( F_186 ( unsigned , V_26 -> V_30 . V_38 , 8 ) / 8 ,
sizeof( unsigned long ) ) ;
V_368 = V_76 ;
V_76 += V_26 -> V_30 . V_38 * sizeof( V_26 -> V_30 . V_78 [ 0 ] ) ;
V_369 = V_76 ;
V_76 += V_26 -> V_30 . V_38 * sizeof( V_26 -> V_30 . V_341 [ 0 ] ) ;
if ( V_26 -> type == V_84 ) {
V_371 = V_76 ;
V_76 += V_26 -> V_30 . V_38 * sizeof( V_26 -> V_30 . V_338 [ 0 ] ) ;
V_372 = V_76 ;
V_76 += V_26 -> V_30 . V_238 *
sizeof( V_26 -> V_30 . V_239 [ 0 ] ) ;
}
V_370 = V_76 ;
V_76 += V_26 -> V_30 . V_38 * sizeof( struct V_1 ) ;
V_377 = F_258 ( V_76 , 0 ) ;
V_26 -> V_30 . V_42 = V_377 ;
V_26 -> V_30 . V_78 = V_377 + V_368 ;
V_26 -> V_30 . V_341 = V_377 + V_369 ;
for ( V_64 = 0 ; V_64 < V_26 -> V_30 . V_38 ; V_64 ++ ) {
V_26 -> V_30 . V_78 [ V_64 ] = V_110 ;
V_26 -> V_30 . V_341 [ V_64 ] = V_110 ;
}
if ( V_26 -> type == V_84 ) {
V_26 -> V_30 . V_338 = V_377 + V_371 ;
for ( V_64 = 0 ; V_64 < V_26 -> V_30 . V_38 ; V_64 ++ )
V_26 -> V_30 . V_338 [ V_64 ] = V_110 ;
V_26 -> V_30 . V_239 = V_377 + V_372 ;
for ( V_64 = 0 ; V_64 < V_26 -> V_30 . V_238 ; V_64 ++ )
V_26 -> V_30 . V_239 [ V_64 ] = V_110 ;
}
V_26 -> V_30 . V_37 = V_377 + V_370 ;
F_14 ( V_26 , V_26 -> V_30 . V_53 ) ;
if ( V_26 -> V_30 . V_53 == 0 ) {
V_26 -> V_30 . V_154 = 1 ;
F_14 ( V_26 , V_26 -> V_30 . V_154 ) ;
} else if ( V_26 -> V_30 . V_53 == ( V_26 -> V_30 . V_38 - 1 ) ) {
V_26 -> V_30 . V_154 = V_26 -> V_30 . V_53 - 1 ;
F_14 ( V_26 , V_26 -> V_30 . V_154 ) ;
} else {
V_26 -> V_30 . V_154 = V_110 ;
}
F_40 ( & V_26 -> V_30 . V_152 ) ;
F_262 ( & V_26 -> V_30 . V_177 ) ;
V_26 -> V_30 . V_238 = V_26 -> V_30 . V_293 /
V_242 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_10 ( L_118 ,
V_26 -> V_30 . V_38 , V_26 -> V_30 . V_53 ,
V_26 -> V_30 . V_385 , V_26 -> V_30 . V_340 ) ;
if ( V_26 -> V_30 . V_32 )
F_10 ( L_119 ,
V_26 -> V_30 . V_32 , V_26 -> V_30 . V_54 ) ;
if ( V_26 -> V_30 . V_386 )
F_10 ( L_120 ,
V_26 -> V_30 . V_386 , V_26 -> V_30 . V_337 ) ;
V_26 -> V_40 -> V_280 = & V_388 ;
V_26 -> V_389 = F_54 ;
V_26 -> V_390 = F_50 ;
V_26 -> V_391 = F_52 ;
F_221 ( V_26 ) ;
V_392 . V_393 = F_233 ;
if ( V_26 -> type == V_139 ) {
V_40 -> V_394 = V_395 ;
} else {
V_26 -> V_396 = F_117 ;
V_40 -> V_394 = V_397 ;
}
#ifdef F_5
V_392 . V_398 = F_224 ;
V_392 . V_399 = F_242 ;
#endif
F_268 ( V_400 ) ;
V_45 = F_252 ( V_376 , V_361 , V_362 ) ;
if ( V_45 )
F_76 ( L_121 , V_45 ) ;
if ( F_269 () ) {
F_10 ( L_122 ) ;
F_270 ( V_40 , V_401 ) ;
F_270 ( V_40 , V_402 ) ;
}
if ( ! V_26 -> V_97 || V_26 -> V_97 ( V_26 ) )
V_40 -> V_52 [ 1 ] . V_9 = 0 ;
}
void T_2 F_271 ( struct V_85 * V_365 )
{
F_255 ( V_365 , 0 , V_90 ) ;
}
void T_2 F_272 ( struct V_85 * V_365 )
{
F_255 ( V_365 , 0 , V_139 ) ;
}
void T_2 F_273 ( struct V_85 * V_365 )
{
struct V_85 * V_403 ;
const T_13 * V_373 ;
T_7 V_366 ;
F_10 ( L_123 , V_365 -> V_92 ) ;
V_373 = F_45 ( V_365 , L_124 , NULL ) ;
if ( ! V_373 ) {
F_74 ( L_125 ) ;
return;
}
V_366 = F_257 ( V_373 ) ;
F_202 ( L_126 , V_366 ) ;
F_274 (np, phbn) {
if ( F_263 ( V_403 , L_127 ) )
F_255 ( V_403 , V_366 , V_84 ) ;
}
}
