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
T_3 V_37 ;
V_26 -> V_30 . V_38 [ V_36 ] . V_26 = V_26 ;
V_26 -> V_30 . V_38 [ V_36 ] . V_21 = V_36 ;
V_37 = F_14 ( V_26 -> V_39 , V_36 ,
V_40 ) ;
if ( V_37 != V_41 && V_37 != V_42 )
F_15 ( L_7 ,
V_43 , V_37 , V_26 -> V_44 -> V_45 , V_36 ) ;
return & V_26 -> V_30 . V_38 [ V_36 ] ;
}
static void F_16 ( struct V_25 * V_26 , int V_36 )
{
if ( ! ( V_36 >= 0 && V_36 < V_26 -> V_30 . V_46 ) ) {
F_15 ( L_8 ,
V_43 , V_36 , V_26 -> V_44 -> V_45 ) ;
return;
}
if ( F_17 ( V_36 , V_26 -> V_30 . V_47 ) )
F_18 ( L_9 ,
V_43 , V_36 , V_26 -> V_44 -> V_45 ) ;
F_13 ( V_26 , V_36 ) ;
}
static struct V_1 * F_19 ( struct V_25 * V_26 )
{
long V_2 ;
for ( V_2 = V_26 -> V_30 . V_46 - 1 ; V_2 >= 0 ; V_2 -- ) {
if ( ! F_17 ( V_2 , V_26 -> V_30 . V_47 ) )
return F_13 ( V_26 , V_2 ) ;
}
return NULL ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_48 = V_2 -> V_21 ;
F_21 ( V_2 -> V_11 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_22 ( V_48 , V_26 -> V_30 . V_47 ) ;
}
static int F_23 ( struct V_25 * V_26 )
{
const char * V_49 ;
struct V_27 * V_28 ;
T_3 V_37 ;
V_37 = F_24 ( V_26 -> V_39 ,
V_50 ,
V_26 -> V_30 . V_51 ,
V_26 -> V_30 . V_31 ,
0 ,
V_26 -> V_30 . V_32 ) ;
if ( V_37 != V_41 ) {
V_49 = L_10 ;
goto V_52;
}
V_37 = F_25 ( V_26 -> V_39 ,
V_50 ,
V_26 -> V_30 . V_51 ,
V_53 ) ;
if ( V_37 != V_41 ) {
V_49 = L_11 ;
goto V_52;
}
V_28 = & V_26 -> V_44 -> V_54 [ 1 ] ;
if ( V_26 -> V_30 . V_55 == 0 )
V_28 -> V_29 += ( 2 * V_26 -> V_30 . V_56 ) ;
else if ( V_26 -> V_30 . V_55 == ( V_26 -> V_30 . V_46 - 1 ) )
V_28 -> V_57 -= ( 2 * V_26 -> V_30 . V_56 ) ;
else
F_15 ( L_12 ,
V_26 -> V_30 . V_55 ) ;
return 0 ;
V_52:
F_15 ( L_13 ,
V_37 , V_49 , V_26 -> V_30 . V_51 ) ;
F_25 ( V_26 -> V_39 ,
V_50 ,
V_26 -> V_30 . V_51 ,
V_58 ) ;
return - V_59 ;
}
static void F_26 ( struct V_60 * V_11 ,
unsigned long * V_61 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_27 * V_28 ;
T_4 V_64 , V_65 , V_29 , V_57 ;
int V_66 , V_67 ;
V_64 = V_26 -> V_30 . V_31 ;
V_65 = V_26 -> V_30 . V_56 ;
for ( V_67 = 0 ; V_67 <= V_68 ; V_67 ++ ) {
V_28 = & V_11 -> V_27 [ V_67 ] ;
if ( ! V_28 -> V_69 || ! F_11 ( V_26 , V_28 ) )
continue;
V_29 = F_28 ( V_28 -> V_29 - V_64 , V_65 ) ;
V_57 = F_29 ( V_28 -> V_57 - V_64 , V_65 ) ;
for ( V_66 = V_29 / V_65 ; V_66 < V_57 / V_65 ; V_66 ++ ) {
if ( V_61 )
F_30 ( V_66 , V_61 ) ;
else
F_16 ( V_26 , V_66 ) ;
}
}
}
static int F_31 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
unsigned long V_64 , V_72 = V_26 -> V_30 . V_56 ;
T_5 V_37 ;
V_64 = V_26 -> V_30 . V_31 +
V_70 * V_73 * V_72 ;
V_37 = F_24 ( V_26 -> V_39 ,
V_50 , V_70 , V_64 , 0 ,
V_73 * V_72 ) ;
if ( V_37 != V_41 ) {
F_15 ( L_14 ,
V_37 , V_26 -> V_44 -> V_45 , V_70 ) ;
goto V_52;
}
V_37 = F_25 ( V_26 -> V_39 ,
V_50 , V_70 ,
V_53 ) ;
if ( V_37 != V_41 ) {
F_15 ( L_15 ,
V_37 , V_26 -> V_44 -> V_45 , V_70 ) ;
goto V_52;
}
}
V_28 = & V_26 -> V_44 -> V_54 [ 1 ] ;
if ( V_26 -> V_30 . V_55 == 0 )
V_28 -> V_29 += ( 2 * V_26 -> V_30 . V_56 ) ;
else if ( V_26 -> V_30 . V_55 == ( V_26 -> V_30 . V_46 - 1 ) )
V_28 -> V_57 -= ( 2 * V_26 -> V_30 . V_56 ) ;
else
F_32 ( 1 , L_16 ,
V_26 -> V_30 . V_55 , V_26 -> V_44 -> V_45 ) ;
return 0 ;
V_52:
for ( ; V_70 >= 0 ; V_70 -- )
F_25 ( V_26 -> V_39 ,
V_50 , V_70 , V_58 ) ;
return - V_59 ;
}
static void F_33 ( struct V_74 * V_19 ,
unsigned long * V_61 ,
bool V_75 )
{
struct V_60 * V_11 ;
F_34 (pdev, &bus->devices, bus_list) {
F_26 ( V_11 , V_61 ) ;
if ( V_75 && V_11 -> V_76 )
F_33 ( V_11 -> V_76 ,
V_61 , V_75 ) ;
}
}
static struct V_1 * F_35 ( struct V_74 * V_19 , bool V_75 )
{
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_1 * V_77 , * V_2 ;
unsigned long V_78 , * V_47 ;
int V_67 ;
if ( F_36 ( V_19 ) )
return NULL ;
V_78 = F_29 ( V_26 -> V_30 . V_46 / 8 , sizeof( unsigned long ) ) ;
V_47 = F_37 ( V_78 , V_79 ) ;
if ( ! V_47 ) {
F_15 ( L_17 ,
V_43 ) ;
return NULL ;
}
F_33 ( V_19 , V_47 , V_75 ) ;
if ( F_38 ( V_47 , V_26 -> V_30 . V_46 ) ) {
F_39 ( V_47 ) ;
return NULL ;
}
V_77 = NULL ;
V_67 = - 1 ;
while ( ( V_67 = F_40 ( V_47 , V_26 -> V_30 . V_46 , V_67 + 1 ) ) <
V_26 -> V_30 . V_46 ) {
V_2 = & V_26 -> V_30 . V_38 [ V_67 ] ;
V_26 -> V_30 . V_80 [ V_2 -> V_21 ] = V_2 -> V_21 ;
if ( ! V_77 ) {
V_2 -> V_9 |= V_81 ;
F_41 ( & V_2 -> V_82 ) ;
V_77 = V_2 ;
} else {
V_2 -> V_9 |= V_83 ;
V_2 -> V_84 = V_77 ;
F_42 ( & V_2 -> V_85 , & V_77 -> V_82 ) ;
}
if ( V_26 -> type == V_86 ) {
T_5 V_37 ;
V_37 = F_43 ( V_26 -> V_39 ,
V_2 -> V_21 , V_50 ,
V_2 -> V_21 / V_73 ,
V_2 -> V_21 % V_73 ) ;
if ( V_37 != V_41 )
F_15 ( L_18 ,
V_43 , V_37 , V_26 -> V_44 -> V_45 ,
V_2 -> V_21 ) ;
}
}
F_39 ( V_47 ) ;
return V_77 ;
}
static void T_2 F_44 ( struct V_25 * V_26 )
{
struct V_62 * V_44 = V_26 -> V_44 ;
struct V_87 * V_88 = V_44 -> V_88 ;
struct V_27 * V_89 ;
T_6 V_90 [ 2 ] , V_67 ;
const T_7 * V_28 ;
T_8 V_91 ;
if ( V_26 -> type != V_86 && V_26 -> type != V_92 ) {
F_10 ( L_19 ) ;
return;
}
if ( ! F_45 ( V_93 ) ) {
F_10 ( L_20 ) ;
return;
}
V_28 = F_46 ( V_88 , L_21 , NULL ) ;
if ( ! V_28 ) {
F_10 ( L_22 ,
V_88 ) ;
return;
}
if ( F_47 ( V_88 , L_23 ,
V_90 , 2 ) ) {
V_90 [ 0 ] = 0 ;
V_90 [ 1 ] = 16 ;
}
if ( V_90 [ 1 ] > 63 ) {
F_15 ( L_24 ,
V_43 , V_90 [ 1 ] , V_26 -> V_44 -> V_45 ) ;
V_90 [ 1 ] = 63 ;
}
if ( V_90 [ 1 ] <= V_90 [ 0 ] ) {
F_15 ( L_25 ,
V_43 , V_26 -> V_44 -> V_45 ) ;
return;
}
V_89 = & V_44 -> V_54 [ 1 ] ;
V_89 -> V_94 = V_88 -> V_95 ;
V_89 -> V_29 = F_48 ( V_88 , V_28 + 2 ) ;
V_89 -> V_57 = V_89 -> V_29 + F_49 ( V_28 + 4 , 2 ) - 1 ;
V_89 -> V_9 = ( V_96 | V_34 | V_35 ) ;
V_91 = F_49 ( V_28 , 2 ) ;
V_44 -> V_97 [ 1 ] = V_89 -> V_29 - V_91 ;
V_26 -> V_30 . V_32 = F_50 ( V_89 ) ;
V_26 -> V_30 . V_56 = V_26 -> V_30 . V_32 / V_26 -> V_30 . V_46 ;
V_26 -> V_30 . V_31 = V_91 ;
F_10 ( L_26 ,
V_89 -> V_29 , V_89 -> V_57 , V_91 , V_90 [ 0 ] ,
V_90 [ 0 ] + V_90 [ 1 ] - 1 ) ;
V_26 -> V_30 . V_98 = ( unsigned long ) - 1 ;
V_90 [ 1 ] -- ;
V_26 -> V_30 . V_51 = V_90 [ 0 ] + V_90 [ 1 ] ;
F_10 ( L_27 , V_26 -> V_30 . V_51 ) ;
for ( V_67 = V_90 [ 0 ] ; V_67 < V_90 [ 1 ] ; V_67 ++ )
F_22 ( V_67 , & V_26 -> V_30 . V_98 ) ;
if ( V_26 -> type == V_86 )
V_26 -> V_99 = F_31 ;
else
V_26 -> V_99 = F_23 ;
V_26 -> V_100 = F_33 ;
V_26 -> V_101 = F_35 ;
}
static void F_51 ( struct V_25 * V_26 , int V_36 )
{
struct V_1 * V_2 = & V_26 -> V_30 . V_38 [ V_36 ] ;
struct V_1 * V_102 ;
T_3 V_37 ;
if ( V_2 -> V_9 & V_83 ) {
V_2 = V_2 -> V_84 ;
if ( F_21 ( ! V_2 || ! ( V_2 -> V_9 & V_81 ) ) )
return;
V_36 = V_2 -> V_21 ;
}
V_37 = F_52 ( V_26 -> V_39 ,
V_36 ,
V_103 ) ;
if ( V_37 != V_41 ) {
F_15 ( L_28 ,
V_43 , V_37 , V_26 -> V_44 -> V_45 , V_36 ) ;
return;
}
if ( ! ( V_2 -> V_9 & V_81 ) )
return;
F_34 (slave, &pe->slaves, list) {
V_37 = F_52 ( V_26 -> V_39 ,
V_102 -> V_21 ,
V_103 ) ;
if ( V_37 != V_41 )
F_15 ( L_28 ,
V_43 , V_37 , V_26 -> V_44 -> V_45 ,
V_102 -> V_21 ) ;
}
}
static int F_53 ( struct V_25 * V_26 , int V_36 , int V_104 )
{
struct V_1 * V_2 , * V_102 ;
T_3 V_37 ;
V_2 = & V_26 -> V_30 . V_38 [ V_36 ] ;
if ( V_2 -> V_9 & V_83 ) {
V_2 = V_2 -> V_84 ;
F_21 ( ! V_2 || ! ( V_2 -> V_9 & V_81 ) ) ;
V_36 = V_2 -> V_21 ;
}
V_37 = F_14 ( V_26 -> V_39 , V_36 , V_104 ) ;
if ( V_37 != V_41 ) {
F_15 ( L_29 ,
V_43 , V_37 , V_104 , V_26 -> V_44 -> V_45 , V_36 ) ;
return - V_59 ;
}
if ( ! ( V_2 -> V_9 & V_81 ) )
return 0 ;
F_34 (slave, &pe->slaves, list) {
V_37 = F_14 ( V_26 -> V_39 ,
V_102 -> V_21 ,
V_104 ) ;
if ( V_37 != V_41 ) {
F_15 ( L_29 ,
V_43 , V_37 , V_104 , V_26 -> V_44 -> V_45 ,
V_102 -> V_21 ) ;
return - V_59 ;
}
}
return 0 ;
}
static int F_54 ( struct V_25 * V_26 , int V_36 )
{
struct V_1 * V_102 , * V_2 ;
T_9 V_105 , V_106 ;
T_10 V_107 ;
T_3 V_37 ;
if ( V_36 < 0 || V_36 >= V_26 -> V_30 . V_46 )
return V_108 ;
V_2 = & V_26 -> V_30 . V_38 [ V_36 ] ;
if ( V_2 -> V_9 & V_83 ) {
V_2 = V_2 -> V_84 ;
F_21 ( ! V_2 || ! ( V_2 -> V_9 & V_81 ) ) ;
V_36 = V_2 -> V_21 ;
}
V_37 = F_55 ( V_26 -> V_39 , V_36 ,
& V_106 , & V_107 , NULL ) ;
if ( V_37 != V_41 ) {
F_15 ( L_30
L_31 ,
V_43 , V_37 ,
V_26 -> V_44 -> V_45 , V_36 ) ;
return V_109 ;
}
if ( ! ( V_2 -> V_9 & V_81 ) )
return V_106 ;
F_34 (slave, &pe->slaves, list) {
V_37 = F_55 ( V_26 -> V_39 ,
V_102 -> V_21 ,
& V_105 ,
& V_107 ,
NULL ) ;
if ( V_37 != V_41 ) {
F_15 ( L_30
L_31 ,
V_43 , V_37 ,
V_26 -> V_44 -> V_45 , V_102 -> V_21 ) ;
return V_109 ;
}
if ( V_105 > V_106 )
V_106 = V_105 ;
}
return V_106 ;
}
struct V_1 * F_56 ( struct V_60 * V_12 )
{
struct V_62 * V_44 = F_27 ( V_12 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_12 ) ;
if ( ! V_111 )
return NULL ;
if ( V_111 -> V_21 == V_112 )
return NULL ;
return & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
}
static int F_58 ( struct V_25 * V_26 ,
struct V_1 * V_69 ,
struct V_1 * V_113 ,
bool V_114 )
{
const char * V_49 = V_114 ? L_32 : L_33 ;
T_11 V_115 = V_114 ? V_116 :
V_117 ;
struct V_1 * V_102 ;
long V_37 ;
V_37 = F_59 ( V_26 -> V_39 , V_69 -> V_21 ,
V_113 -> V_21 , V_115 ) ;
if ( V_37 != V_41 ) {
F_60 ( V_113 , L_34 ,
V_37 , V_49 ) ;
return - V_118 ;
}
if ( ! ( V_113 -> V_9 & V_81 ) )
return 0 ;
F_34 (slave, &child->slaves, list) {
V_37 = F_59 ( V_26 -> V_39 , V_69 -> V_21 ,
V_102 -> V_21 , V_115 ) ;
if ( V_37 != V_41 ) {
F_60 ( V_102 , L_34 ,
V_37 , V_49 ) ;
return - V_118 ;
}
}
return 0 ;
}
static int F_61 ( struct V_25 * V_26 ,
struct V_1 * V_2 ,
bool V_114 )
{
struct V_1 * V_102 ;
struct V_60 * V_11 = NULL ;
int V_119 ;
if ( V_114 ) {
F_14 ( V_26 -> V_39 , V_2 -> V_21 ,
V_40 ) ;
if ( V_2 -> V_9 & V_81 ) {
F_34 (slave, &pe->slaves, list)
F_14 ( V_26 -> V_39 ,
V_102 -> V_21 ,
V_40 ) ;
}
}
V_119 = F_58 ( V_26 , V_2 , V_2 , V_114 ) ;
if ( V_119 )
return V_119 ;
if ( V_2 -> V_9 & V_81 ) {
F_34 (slave, &pe->slaves, list) {
V_119 = F_58 ( V_26 , V_102 , V_2 , V_114 ) ;
if ( V_119 )
return V_119 ;
}
}
if ( V_2 -> V_9 & ( V_14 | V_13 ) )
V_11 = V_2 -> V_15 -> V_120 ;
else if ( V_2 -> V_9 & V_10 )
V_11 = V_2 -> V_11 -> V_19 -> V_120 ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
V_11 = V_2 -> V_18 ;
#endif
while ( V_11 ) {
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_69 ;
if ( V_111 && V_111 -> V_21 != V_112 ) {
V_69 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
V_119 = F_58 ( V_26 , V_69 , V_2 , V_114 ) ;
if ( V_119 )
return V_119 ;
}
V_11 = V_11 -> V_19 -> V_120 ;
}
return 0 ;
}
static int F_62 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_60 * V_69 ;
T_11 V_121 , V_122 , V_123 ;
T_5 V_37 ;
long V_124 , V_20 ;
if ( V_2 -> V_15 ) {
int V_125 ;
V_122 = V_126 ;
V_123 = V_127 ;
V_69 = V_2 -> V_15 -> V_120 ;
if ( V_2 -> V_9 & V_14 )
V_125 = V_2 -> V_15 -> V_128 . V_57 - V_2 -> V_15 -> V_128 . V_29 + 1 ;
else
V_125 = 1 ;
switch( V_125 ) {
case 1 : V_121 = V_129 ; break;
case 2 : V_121 = V_130 ; break;
case 4 : V_121 = V_131 ; break;
case 8 : V_121 = V_132 ; break;
case 16 : V_121 = V_133 ; break;
case 32 : V_121 = V_134 ; break;
default:
F_63 ( & V_2 -> V_15 -> V_12 , L_35 ,
V_125 ) ;
V_121 = V_129 ;
}
V_124 = V_2 -> V_20 + ( V_125 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_69 = V_2 -> V_18 ;
else
#endif
V_69 = V_2 -> V_11 -> V_19 -> V_120 ;
V_121 = V_129 ;
V_122 = V_135 ;
V_123 = V_136 ;
V_124 = V_2 -> V_20 + 1 ;
}
for ( V_20 = V_2 -> V_20 ; V_20 < V_124 ; V_20 ++ )
V_26 -> V_30 . V_137 [ V_20 ] = V_112 ;
while ( V_69 ) {
struct V_110 * V_111 = F_57 ( V_69 ) ;
if ( V_111 && V_111 -> V_21 != V_112 ) {
V_37 = F_59 ( V_26 -> V_39 , V_111 -> V_21 ,
V_2 -> V_21 , V_117 ) ;
}
V_69 = V_69 -> V_19 -> V_120 ;
}
F_14 ( V_26 -> V_39 , V_2 -> V_21 ,
V_40 ) ;
V_37 = F_59 ( V_26 -> V_39 , V_2 -> V_21 ,
V_2 -> V_21 , V_117 ) ;
if ( V_37 )
F_60 ( V_2 , L_36 , V_37 ) ;
V_37 = F_64 ( V_26 -> V_39 , V_2 -> V_21 , V_2 -> V_20 ,
V_121 , V_122 , V_123 , V_138 ) ;
if ( V_37 )
F_65 ( V_2 , L_37 , V_37 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
#ifdef F_5
V_2 -> V_18 = NULL ;
#endif
return 0 ;
}
static int F_66 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_60 * V_69 ;
T_11 V_121 , V_122 , V_123 ;
long V_37 , V_124 , V_20 ;
if ( V_2 -> V_15 ) {
int V_125 ;
V_122 = V_126 ;
V_123 = V_127 ;
V_69 = V_2 -> V_15 -> V_120 ;
if ( V_2 -> V_9 & V_14 )
V_125 = V_2 -> V_15 -> V_128 . V_57 - V_2 -> V_15 -> V_128 . V_29 + 1 ;
else
V_125 = 1 ;
switch( V_125 ) {
case 1 : V_121 = V_129 ; break;
case 2 : V_121 = V_130 ; break;
case 4 : V_121 = V_131 ; break;
case 8 : V_121 = V_132 ; break;
case 16 : V_121 = V_133 ; break;
case 32 : V_121 = V_134 ; break;
default:
F_63 ( & V_2 -> V_15 -> V_12 , L_35 ,
V_125 ) ;
V_121 = V_129 ;
}
V_124 = V_2 -> V_20 + ( V_125 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_69 = V_2 -> V_18 ;
else
#endif
V_69 = V_2 -> V_11 -> V_19 -> V_120 ;
V_121 = V_129 ;
V_122 = V_135 ;
V_123 = V_136 ;
V_124 = V_2 -> V_20 + 1 ;
}
V_37 = F_64 ( V_26 -> V_39 , V_2 -> V_21 , V_2 -> V_20 ,
V_121 , V_122 , V_123 , V_139 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_37 , V_37 ) ;
return - V_118 ;
}
if ( V_26 -> type != V_140 )
F_61 ( V_26 , V_2 , true ) ;
for ( V_20 = V_2 -> V_20 ; V_20 < V_124 ; V_20 ++ )
V_26 -> V_30 . V_137 [ V_20 ] = V_2 -> V_21 ;
if ( V_26 -> type != V_86 ) {
V_2 -> V_141 = 0 ;
goto V_142;
}
V_2 -> V_141 = V_2 -> V_21 ;
V_37 = F_67 ( V_26 -> V_39 , V_2 -> V_141 , V_2 -> V_21 ) ;
if ( V_37 != V_41 ) {
F_65 ( V_2 , L_38 ,
V_37 , V_2 -> V_141 ) ;
V_2 -> V_141 = - 1 ;
} else {
V_37 = F_68 ( V_26 -> V_39 ,
V_2 -> V_141 , V_143 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_39 ,
V_37 , V_2 -> V_141 ) ;
V_2 -> V_141 = - 1 ;
}
}
V_142:
return 0 ;
}
static int F_69 ( struct V_60 * V_12 , int V_144 )
{
struct V_110 * V_111 = F_57 ( V_12 ) ;
int V_67 ;
struct V_27 * V_89 , V_145 ;
T_4 V_78 ;
T_12 V_146 ;
if ( ! V_12 -> V_147 )
return - V_23 ;
V_146 = V_111 -> V_146 ;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_12 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || ! V_89 -> V_69 )
continue;
V_78 = F_70 ( V_12 , V_67 + V_149 ) ;
V_145 . V_9 = V_89 -> V_9 ;
V_145 . V_29 = V_89 -> V_29 + ( V_78 * V_144 ) ;
V_145 . V_57 = V_145 . V_29 + ( V_78 * V_146 ) - 1 ;
if ( V_145 . V_57 > V_89 -> V_57 ) {
F_63 ( & V_12 -> V_12 , L_40 ,
V_67 , & V_145 , V_89 , V_146 , V_144 ) ;
return - V_150 ;
}
}
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_12 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || ! V_89 -> V_69 )
continue;
V_78 = F_70 ( V_12 , V_67 + V_149 ) ;
V_145 = * V_89 ;
V_89 -> V_29 += V_78 * V_144 ;
F_71 ( & V_12 -> V_12 , L_41 ,
V_67 , & V_145 , V_89 , ( V_144 > 0 ) ? L_42 : L_43 ,
V_146 , V_144 ) ;
F_72 ( V_12 , V_67 + V_149 ) ;
}
return 0 ;
}
static struct V_1 * F_73 ( struct V_60 * V_12 )
{
struct V_62 * V_44 = F_27 ( V_12 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_12 ) ;
struct V_1 * V_2 ;
if ( ! V_111 ) {
F_74 ( L_44 ,
F_75 ( V_12 ) ) ;
return NULL ;
}
if ( V_111 -> V_21 != V_112 )
return NULL ;
V_2 = F_19 ( V_26 ) ;
if ( ! V_2 ) {
F_76 ( L_45 ,
F_75 ( V_12 ) ) ;
return NULL ;
}
F_77 ( V_12 ) ;
V_111 -> V_151 = V_12 ;
V_111 -> V_21 = V_2 -> V_21 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_15 = NULL ;
V_2 -> V_141 = - 1 ;
V_2 -> V_20 = V_12 -> V_19 -> V_16 << 8 | V_111 -> V_152 ;
F_78 ( V_2 , L_46 ) ;
if ( F_66 ( V_26 , V_2 ) ) {
F_20 ( V_2 ) ;
V_111 -> V_21 = V_112 ;
V_2 -> V_11 = NULL ;
F_79 ( V_12 ) ;
return NULL ;
}
F_42 ( & V_2 -> V_85 , & V_26 -> V_30 . V_153 ) ;
return V_2 ;
}
static void F_80 ( struct V_74 * V_19 , struct V_1 * V_2 )
{
struct V_60 * V_12 ;
F_34 (dev, &bus->devices, bus_list) {
struct V_110 * V_111 = F_57 ( V_12 ) ;
if ( V_111 == NULL ) {
F_15 ( L_47 ,
F_75 ( V_12 ) ) ;
continue;
}
if ( V_111 -> V_21 != V_112 )
continue;
V_2 -> V_154 ++ ;
V_111 -> V_151 = V_12 ;
V_111 -> V_21 = V_2 -> V_21 ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_76 )
F_80 ( V_12 -> V_76 , V_2 ) ;
}
}
static struct V_1 * F_81 ( struct V_74 * V_19 , bool V_75 )
{
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_1 * V_2 = NULL ;
unsigned int V_48 ;
V_48 = V_26 -> V_30 . V_137 [ V_19 -> V_16 << 8 ] ;
if ( V_48 != V_112 ) {
V_2 = & V_26 -> V_30 . V_38 [ V_48 ] ;
F_80 ( V_19 , V_2 ) ;
return NULL ;
}
if ( F_36 ( V_19 ) &&
V_26 -> V_30 . V_155 != V_112 )
V_2 = & V_26 -> V_30 . V_38 [ V_26 -> V_30 . V_155 ] ;
if ( ! V_2 && V_26 -> V_101 )
V_2 = V_26 -> V_101 ( V_19 , V_75 ) ;
if ( ! V_2 )
V_2 = F_19 ( V_26 ) ;
if ( ! V_2 ) {
F_76 ( L_48 ,
V_43 , F_4 ( V_19 ) , V_19 -> V_16 ) ;
return NULL ;
}
V_2 -> V_9 |= ( V_75 ? V_14 : V_13 ) ;
V_2 -> V_15 = V_19 ;
V_2 -> V_11 = NULL ;
V_2 -> V_141 = - 1 ;
V_2 -> V_20 = V_19 -> V_128 . V_29 << 8 ;
if ( V_75 )
F_78 ( V_2 , L_49 ,
V_19 -> V_128 . V_29 , V_19 -> V_128 . V_57 , V_2 -> V_21 ) ;
else
F_78 ( V_2 , L_50 ,
V_19 -> V_128 . V_29 , V_2 -> V_21 ) ;
if ( F_66 ( V_26 , V_2 ) ) {
F_20 ( V_2 ) ;
V_2 -> V_15 = NULL ;
return NULL ;
}
F_80 ( V_19 , V_2 ) ;
F_42 ( & V_2 -> V_85 , & V_26 -> V_30 . V_153 ) ;
return V_2 ;
}
static struct V_1 * F_82 ( struct V_60 * V_156 )
{
int V_48 , V_157 = false , V_37 ;
long V_20 ;
struct V_1 * V_2 ;
struct V_60 * V_158 ;
struct V_110 * V_159 ;
struct V_62 * V_44 = F_27 ( V_156 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
V_158 = F_83 ( V_156 ) ;
for ( V_48 = 0 ; V_48 < V_26 -> V_30 . V_46 ; V_48 ++ ) {
V_2 = & V_26 -> V_30 . V_38 [ V_48 ] ;
if ( ! V_2 -> V_11 )
continue;
if ( F_83 ( V_2 -> V_11 ) == V_158 ) {
F_71 ( & V_156 -> V_12 ,
L_51 , V_48 ) ;
F_77 ( V_156 ) ;
V_159 = F_57 ( V_156 ) ;
V_20 = V_156 -> V_19 -> V_16 << 8 | V_159 -> V_152 ;
V_159 -> V_151 = V_156 ;
V_159 -> V_21 = V_48 ;
V_26 -> V_30 . V_137 [ V_20 ] = V_2 -> V_21 ;
V_37 = F_64 ( V_26 -> V_39 , V_48 , V_20 ,
V_129 ,
V_135 ,
V_136 ,
V_139 ) ;
F_21 ( V_37 != V_41 ) ;
V_157 = true ;
break;
}
}
if ( ! V_157 )
return F_73 ( V_156 ) ;
else
return V_2 ;
}
static void F_84 ( struct V_74 * V_19 )
{
struct V_60 * V_11 ;
F_34 (pdev, &bus->devices, bus_list)
F_82 ( V_11 ) ;
}
static void F_85 ( void )
{
struct V_62 * V_44 , * V_160 ;
struct V_25 * V_26 ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_44 -> V_63 ;
if ( V_26 -> type == V_140 ) {
F_16 ( V_26 , 0 ) ;
F_84 ( V_44 -> V_19 ) ;
if ( V_26 -> V_161 == V_162 )
F_87 ( V_26 ) ;
}
}
}
static int F_88 ( struct V_60 * V_11 , T_12 V_146 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_110 * V_111 ;
int V_67 , V_163 ;
int V_164 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
if ( V_111 -> V_165 )
V_164 = V_146 ;
else
V_164 = 1 ;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ )
for ( V_163 = 0 ; V_163 < V_164 ; V_163 ++ ) {
if ( V_111 -> V_166 [ V_163 ] [ V_67 ] == V_167 )
continue;
F_25 ( V_26 -> V_39 ,
V_50 , V_111 -> V_166 [ V_163 ] [ V_67 ] , 0 ) ;
F_22 ( V_111 -> V_166 [ V_163 ] [ V_67 ] , & V_26 -> V_30 . V_98 ) ;
V_111 -> V_166 [ V_163 ] [ V_67 ] = V_167 ;
}
F_39 ( V_111 -> V_166 ) ;
return 0 ;
}
static int F_89 ( struct V_60 * V_11 , T_12 V_146 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_110 * V_111 ;
unsigned int V_168 ;
struct V_27 * V_89 ;
int V_67 , V_163 ;
T_5 V_37 ;
int V_169 ;
T_4 V_78 , V_29 ;
int V_48 ;
int V_164 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
V_169 = F_90 ( V_11 ) ;
if ( V_111 -> V_165 )
V_164 = V_146 ;
else
V_164 = 1 ;
V_111 -> V_166 = F_91 ( V_164 ,
sizeof( * V_111 -> V_166 ) ,
V_79 ) ;
if ( ! V_111 -> V_166 )
return - V_170 ;
for ( V_67 = 0 ; V_67 < V_164 ; V_67 ++ )
for ( V_163 = 0 ; V_163 < V_148 ; V_163 ++ )
V_111 -> V_166 [ V_67 ] [ V_163 ] = V_167 ;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || ! V_89 -> V_69 )
continue;
for ( V_163 = 0 ; V_163 < V_164 ; V_163 ++ ) {
do {
V_168 = F_92 ( & V_26 -> V_30 . V_98 ,
V_26 -> V_30 . V_51 + 1 , 0 ) ;
if ( V_168 >= V_26 -> V_30 . V_51 + 1 )
goto V_171;
} while ( F_17 ( V_168 , & V_26 -> V_30 . V_98 ) );
V_111 -> V_166 [ V_163 ] [ V_67 ] = V_168 ;
if ( V_111 -> V_165 ) {
V_78 = F_70 ( V_11 ,
V_149 + V_67 ) ;
V_29 = V_89 -> V_29 + V_78 * V_163 ;
} else {
V_78 = F_50 ( V_89 ) ;
V_29 = V_89 -> V_29 ;
}
if ( V_111 -> V_165 ) {
V_48 = V_111 -> V_172 [ V_163 ] ;
V_37 = F_43 ( V_26 -> V_39 ,
V_48 , V_50 ,
V_111 -> V_166 [ V_163 ] [ V_67 ] , 0 ) ;
}
V_37 = F_24 ( V_26 -> V_39 ,
V_50 ,
V_111 -> V_166 [ V_163 ] [ V_67 ] ,
V_29 ,
0 ,
V_78 ) ;
if ( V_37 != V_41 ) {
F_63 ( & V_11 -> V_12 , L_52 ,
V_168 , V_37 ) ;
goto V_171;
}
if ( V_111 -> V_165 )
V_37 = F_25 ( V_26 -> V_39 ,
V_50 , V_111 -> V_166 [ V_163 ] [ V_67 ] , 2 ) ;
else
V_37 = F_25 ( V_26 -> V_39 ,
V_50 , V_111 -> V_166 [ V_163 ] [ V_67 ] , 1 ) ;
if ( V_37 != V_41 ) {
F_63 ( & V_11 -> V_12 , L_53 ,
V_168 , V_37 ) ;
goto V_171;
}
}
}
return 0 ;
V_171:
F_88 ( V_11 , V_146 ) ;
return - V_150 ;
}
static void F_93 ( struct V_60 * V_12 , struct V_1 * V_2 )
{
struct V_173 * V_174 ;
T_5 V_37 ;
V_174 = V_2 -> V_175 . V_176 [ 0 ] ;
V_37 = F_94 ( & V_2 -> V_175 , 0 ) ;
if ( V_37 )
F_60 ( V_2 , L_54 , V_37 ) ;
F_95 ( V_2 , false ) ;
if ( V_2 -> V_175 . V_177 ) {
F_96 ( V_2 -> V_175 . V_177 ) ;
F_97 ( V_2 -> V_175 . V_177 ) ;
}
F_98 ( V_174 ) ;
}
static void F_99 ( struct V_60 * V_11 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * V_2 , * V_178 ;
struct V_110 * V_111 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
if ( ! V_11 -> V_147 )
return;
F_86 (pe, pe_n, &phb->ioda.pe_list, list) {
if ( V_2 -> V_18 != V_11 )
continue;
F_93 ( V_11 , V_2 ) ;
F_100 ( & V_26 -> V_30 . V_179 ) ;
F_101 ( & V_2 -> V_85 ) ;
F_102 ( & V_26 -> V_30 . V_179 ) ;
F_62 ( V_26 , V_2 ) ;
F_20 ( V_2 ) ;
}
}
void F_103 ( struct V_60 * V_11 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_110 * V_111 ;
T_12 V_146 , V_67 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
V_146 = V_111 -> V_146 ;
F_99 ( V_11 ) ;
if ( V_26 -> type == V_92 ) {
if ( ! V_111 -> V_165 )
F_69 ( V_11 , - * V_111 -> V_172 ) ;
F_88 ( V_11 , V_146 ) ;
if ( V_111 -> V_165 ) {
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ ) {
if ( V_111 -> V_172 [ V_67 ] == V_112 )
continue;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_172 [ V_67 ] ] ;
F_20 ( V_2 ) ;
}
} else
F_104 ( V_26 -> V_30 . V_47 , * V_111 -> V_172 , V_146 ) ;
F_39 ( V_111 -> V_172 ) ;
}
}
static void F_105 ( struct V_60 * V_11 , T_12 V_146 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
int V_48 ;
T_12 V_180 ;
struct V_110 * V_111 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
if ( ! V_11 -> V_147 )
return;
for ( V_180 = 0 ; V_180 < V_146 ; V_180 ++ ) {
if ( V_111 -> V_165 )
V_48 = V_111 -> V_172 [ V_180 ] ;
else
V_48 = * V_111 -> V_172 + V_180 ;
V_2 = & V_26 -> V_30 . V_38 [ V_48 ] ;
V_2 -> V_21 = V_48 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_141 = - 1 ;
V_2 -> V_20 = ( F_106 ( V_11 , V_180 ) << 8 ) |
F_107 ( V_11 , V_180 ) ;
F_78 ( V_2 , L_55 ,
V_44 -> V_45 , V_11 -> V_19 -> V_16 ,
F_6 ( F_107 ( V_11 , V_180 ) ) ,
F_7 ( F_107 ( V_11 , V_180 ) ) , V_48 ) ;
if ( F_66 ( V_26 , V_2 ) ) {
F_20 ( V_2 ) ;
V_2 -> V_11 = NULL ;
continue;
}
F_100 ( & V_26 -> V_30 . V_179 ) ;
F_42 ( & V_2 -> V_85 , & V_26 -> V_30 . V_153 ) ;
F_102 ( & V_26 -> V_30 . V_179 ) ;
F_108 ( V_26 , V_2 ) ;
}
}
int F_109 ( struct V_60 * V_11 , T_12 V_146 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_110 * V_111 ;
int V_119 ;
T_12 V_67 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
if ( V_26 -> type == V_92 ) {
if ( ! V_111 -> V_181 ) {
F_71 ( & V_11 -> V_12 , L_56
L_57 ) ;
return - V_182 ;
}
if ( V_111 -> V_165 && V_146 > V_26 -> V_30 . V_51 ) {
F_71 ( & V_11 -> V_12 , L_58 ) ;
return - V_150 ;
}
if ( V_111 -> V_165 )
V_111 -> V_172 = F_91 ( V_146 ,
sizeof( * V_111 -> V_172 ) ,
V_79 ) ;
else
V_111 -> V_172 = F_110 ( sizeof( * V_111 -> V_172 ) , V_79 ) ;
if ( ! V_111 -> V_172 )
return - V_170 ;
if ( V_111 -> V_165 )
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ )
V_111 -> V_172 [ V_67 ] = V_112 ;
if ( V_111 -> V_165 ) {
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ ) {
V_2 = F_19 ( V_26 ) ;
if ( ! V_2 ) {
V_119 = - V_150 ;
goto V_171;
}
V_111 -> V_172 [ V_67 ] = V_2 -> V_21 ;
}
} else {
F_100 ( & V_26 -> V_30 . V_183 ) ;
* V_111 -> V_172 = F_111 (
V_26 -> V_30 . V_47 , V_26 -> V_30 . V_46 ,
0 , V_146 , 0 ) ;
if ( * V_111 -> V_172 >= V_26 -> V_30 . V_46 ) {
F_102 ( & V_26 -> V_30 . V_183 ) ;
F_71 ( & V_11 -> V_12 , L_59 , V_146 ) ;
F_39 ( V_111 -> V_172 ) ;
return - V_150 ;
}
F_112 ( V_26 -> V_30 . V_47 , * V_111 -> V_172 , V_146 ) ;
F_102 ( & V_26 -> V_30 . V_183 ) ;
}
V_111 -> V_146 = V_146 ;
V_119 = F_89 ( V_11 , V_146 ) ;
if ( V_119 ) {
F_71 ( & V_11 -> V_12 , L_60 ) ;
goto V_171;
}
if ( ! V_111 -> V_165 ) {
V_119 = F_69 ( V_11 , * V_111 -> V_172 ) ;
if ( V_119 )
goto V_171;
}
}
F_105 ( V_11 , V_146 ) ;
return 0 ;
V_171:
if ( V_111 -> V_165 ) {
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ ) {
if ( V_111 -> V_172 [ V_67 ] == V_112 )
continue;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_172 [ V_67 ] ] ;
F_20 ( V_2 ) ;
}
} else
F_104 ( V_26 -> V_30 . V_47 , * V_111 -> V_172 , V_146 ) ;
F_39 ( V_111 -> V_172 ) ;
return V_119 ;
}
int F_113 ( struct V_60 * V_11 )
{
F_103 ( V_11 ) ;
F_114 ( V_11 ) ;
return 0 ;
}
int F_115 ( struct V_60 * V_11 , T_12 V_146 )
{
F_116 ( V_11 ) ;
return F_109 ( V_11 , V_146 ) ;
}
static void F_117 ( struct V_25 * V_26 , struct V_60 * V_11 )
{
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
F_21 ( F_118 ( & V_11 -> V_12 ) != & V_184 ) ;
F_119 ( & V_11 -> V_12 , V_2 -> V_185 ) ;
F_120 ( & V_11 -> V_12 , V_2 -> V_175 . V_176 [ 0 ] ) ;
}
static bool F_121 ( struct V_1 * V_2 )
{
unsigned short V_186 = 0 ;
struct V_60 * V_11 ;
if ( V_2 -> V_154 == 1 )
return true ;
if ( ! V_2 -> V_15 )
return true ;
F_34 (pdev, &pe->pbus->devices, bus_list) {
if ( ! V_186 ) {
V_186 = V_11 -> V_186 ;
continue;
}
if ( V_11 -> V_186 != V_186 )
return false ;
}
return true ;
}
static int F_122 ( struct V_1 * V_2 )
{
T_8 V_187 , V_188 , V_189 , V_190 ;
struct V_191 * V_192 ;
T_8 V_193 = 28 ;
T_13 * V_194 ;
T_3 V_37 ;
V_187 = F_123 ( F_124 () + ( 1ULL << 32 ) ) ;
V_189 = V_187 >> V_193 ;
V_188 = V_189 << 3 ;
if ( V_188 < V_195 )
V_188 = V_195 ;
V_192 = F_125 ( V_2 -> V_26 -> V_44 -> V_196 , V_79 ,
F_126 ( V_188 ) ) ;
if ( ! V_192 )
goto V_197;
V_194 = F_127 ( V_192 ) ;
if ( ! V_194 )
goto V_197;
memset ( V_194 , 0 , V_188 ) ;
for ( V_190 = 0 ; V_190 < F_124 () ; V_190 += ( 1 << V_193 ) ) {
V_194 [ ( V_190 + ( 1ULL << 32 ) ) >> V_193 ] =
F_128 ( V_190 | V_198 | V_199 ) ;
}
V_37 = F_129 ( V_2 -> V_26 -> V_39 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + 0 ,
1 ,
F_130 ( V_194 ) ,
V_188 ,
1 << V_193 ) ;
if ( V_37 == V_41 ) {
F_78 ( V_2 , L_61 ) ;
return 0 ;
}
V_197:
F_65 ( V_2 , L_62 ) ;
return - V_59 ;
}
static int F_131 ( struct V_60 * V_11 , T_8 V_200 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
T_14 V_201 ;
bool V_202 = false ;
T_3 V_37 ;
if ( F_21 ( ! V_111 || V_111 -> V_21 == V_112 ) )
return - V_203 ; ;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
if ( V_2 -> V_204 ) {
V_201 = V_2 -> V_185 + F_132 () - 1 ;
V_202 = ( V_200 >= V_201 ) ;
}
if ( V_202 ) {
F_71 ( & V_11 -> V_12 , L_63 ) ;
F_133 ( & V_11 -> V_12 , & V_205 ) ;
} else {
if ( V_200 >> 32 &&
V_200 > ( F_124 () + ( 1ULL << 32 ) ) &&
F_121 ( V_2 ) &&
V_26 -> V_161 == V_206 ) {
V_37 = F_122 ( V_2 ) ;
if ( V_37 )
return V_37 ;
F_119 ( & V_11 -> V_12 , ( 1ULL << 32 ) ) ;
F_133 ( & V_11 -> V_12 , & V_205 ) ;
} else if ( V_200 >> 32 && V_200 != F_134 ( 64 ) ) {
return - V_170 ;
} else {
F_71 ( & V_11 -> V_12 , L_64 ) ;
F_133 ( & V_11 -> V_12 , & V_184 ) ;
}
}
* V_11 -> V_12 . V_200 = V_200 ;
F_135 ( V_11 , V_202 ) ;
return 0 ;
}
static T_8 F_136 ( struct V_60 * V_11 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
T_8 V_57 , V_207 ;
if ( F_21 ( ! V_111 || V_111 -> V_21 == V_112 ) )
return 0 ;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
if ( ! V_2 -> V_204 )
return F_137 ( & V_11 -> V_12 ) ;
V_57 = V_2 -> V_185 + F_132 () ;
V_207 = 1ULL << ( F_138 ( V_57 ) - 1 ) ;
V_207 += V_207 - 1 ;
return V_207 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_74 * V_19 ,
bool V_208 )
{
struct V_60 * V_12 ;
F_34 (dev, &bus->devices, bus_list) {
F_120 ( & V_12 -> V_12 , V_2 -> V_175 . V_176 [ 0 ] ) ;
F_119 ( & V_12 -> V_12 , V_2 -> V_185 ) ;
if ( V_208 )
F_140 ( & V_12 -> V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_76 )
F_139 ( V_2 , V_12 -> V_76 ,
V_208 ) ;
}
}
static inline T_13 T_15 * F_141 ( struct V_25 * V_26 ,
bool V_209 )
{
return V_209 ? ( T_13 T_15 * ) ( V_26 -> V_210 + 0x210 ) :
( V_26 -> V_211 + 0x210 ) ;
}
static void F_142 ( struct V_173 * V_174 ,
unsigned long V_70 , unsigned long V_212 , bool V_213 )
{
struct V_214 * V_215 = F_143 (
& V_174 -> V_216 , struct V_214 ,
V_217 ) ;
struct V_1 * V_2 = F_144 ( V_215 -> V_175 ,
struct V_1 , V_175 ) ;
T_13 T_15 * V_218 = F_141 ( V_2 -> V_26 , V_213 ) ;
unsigned long V_29 , V_57 , V_219 ;
V_29 = F_130 ( ( ( T_13 * ) V_174 -> V_220 ) + V_70 - V_174 -> V_221 ) ;
V_57 = F_130 ( ( ( T_13 * ) V_174 -> V_220 ) + V_70 - V_174 -> V_221 +
V_212 - 1 ) ;
V_29 |= ( 1ull << 63 ) ;
V_57 |= ( 1ull << 63 ) ;
V_219 = 16 ;
V_57 |= V_219 - 1 ;
F_145 () ;
while ( V_29 <= V_57 ) {
if ( V_213 )
F_146 ( F_128 ( V_29 ) , V_218 ) ;
else
F_147 ( F_128 ( V_29 ) , V_218 ) ;
V_29 += V_219 ;
}
}
static int F_148 ( struct V_173 * V_174 , long V_70 ,
long V_212 , unsigned long V_222 ,
enum V_223 V_224 ,
unsigned long V_225 )
{
int V_119 = F_149 ( V_174 , V_70 , V_212 , V_222 , V_224 ,
V_225 ) ;
if ( ! V_119 )
F_142 ( V_174 , V_70 , V_212 , false ) ;
return V_119 ;
}
static int F_150 ( struct V_173 * V_174 , long V_70 ,
unsigned long * V_226 , enum V_223 * V_224 )
{
long V_119 = F_151 ( V_174 , V_70 , V_226 , V_224 ) ;
if ( ! V_119 )
F_142 ( V_174 , V_70 , 1 , false ) ;
return V_119 ;
}
static int F_152 ( struct V_173 * V_174 , long V_70 ,
unsigned long * V_226 , enum V_223 * V_224 )
{
long V_119 = F_151 ( V_174 , V_70 , V_226 , V_224 ) ;
if ( ! V_119 )
F_142 ( V_174 , V_70 , 1 , true ) ;
return V_119 ;
}
static void F_153 ( struct V_173 * V_174 , long V_70 ,
long V_212 )
{
F_154 ( V_174 , V_70 , V_212 ) ;
F_142 ( V_174 , V_70 , V_212 , false ) ;
}
static void F_155 ( struct V_25 * V_26 , bool V_213 )
{
T_13 T_15 * V_218 = F_141 ( V_26 , V_213 ) ;
const unsigned long V_227 = V_228 ;
F_145 () ;
if ( V_213 )
F_146 ( F_128 ( V_227 ) , V_218 ) ;
else
F_147 ( F_128 ( V_227 ) , V_218 ) ;
}
static inline void F_156 ( struct V_1 * V_2 )
{
T_13 T_15 * V_218 = F_141 ( V_2 -> V_26 , false ) ;
unsigned long V_227 = V_229 | ( V_2 -> V_21 & 0xFF ) ;
F_145 () ;
F_147 ( F_128 ( V_227 ) , V_218 ) ;
}
static void F_157 ( struct V_1 * V_2 , bool V_213 ,
unsigned V_230 , unsigned long V_70 ,
unsigned long V_212 )
{
T_13 T_15 * V_218 = F_141 ( V_2 -> V_26 , V_213 ) ;
unsigned long V_29 , V_57 , V_219 ;
V_29 = V_231 ;
V_29 |= ( V_2 -> V_21 & 0xFF ) ;
V_57 = V_29 ;
V_29 |= ( V_70 << V_230 ) ;
V_57 |= ( ( V_70 + V_212 - 1 ) << V_230 ) ;
V_219 = ( 0x1ull << V_230 ) ;
F_145 () ;
while ( V_29 <= V_57 ) {
if ( V_213 )
F_146 ( F_128 ( V_29 ) , V_218 ) ;
else
F_147 ( F_128 ( V_29 ) , V_218 ) ;
V_29 += V_219 ;
}
}
static inline void F_158 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_26 -> V_161 == V_206 && V_26 -> V_211 )
F_156 ( V_2 ) ;
else
F_159 ( V_26 -> V_39 , V_232 ,
V_2 -> V_21 , 0 , 0 , 0 ) ;
}
static void F_160 ( struct V_173 * V_174 ,
unsigned long V_70 , unsigned long V_212 , bool V_213 )
{
struct V_214 * V_215 ;
F_161 (tgl, &tbl->it_group_list, next) {
struct V_1 * V_2 = F_144 ( V_215 -> V_175 ,
struct V_1 , V_175 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_230 = V_174 -> V_233 ;
if ( V_26 -> V_161 == V_234 ) {
F_155 ( V_26 , V_213 ) ;
continue;
}
if ( V_26 -> V_161 == V_206 && V_26 -> V_211 )
F_157 ( V_2 , V_213 , V_230 ,
V_70 , V_212 ) ;
else
F_159 ( V_26 -> V_39 ,
V_235 ,
V_2 -> V_21 , 1u << V_230 ,
V_70 << V_230 , V_212 ) ;
}
}
void F_162 ( struct V_25 * V_26 , bool V_213 )
{
if ( V_26 -> V_161 == V_234 || V_26 -> V_161 == V_206 )
F_155 ( V_26 , V_213 ) ;
else
F_159 ( V_26 -> V_39 , V_236 , 0 , 0 , 0 , 0 ) ;
}
static int F_163 ( struct V_173 * V_174 , long V_70 ,
long V_212 , unsigned long V_222 ,
enum V_223 V_224 ,
unsigned long V_225 )
{
int V_119 = F_149 ( V_174 , V_70 , V_212 , V_222 , V_224 ,
V_225 ) ;
if ( ! V_119 )
F_160 ( V_174 , V_70 , V_212 , false ) ;
return V_119 ;
}
static int F_164 ( struct V_173 * V_174 , long V_70 ,
unsigned long * V_226 , enum V_223 * V_224 )
{
long V_119 = F_151 ( V_174 , V_70 , V_226 , V_224 ) ;
if ( ! V_119 )
F_160 ( V_174 , V_70 , 1 , false ) ;
return V_119 ;
}
static int F_165 ( struct V_173 * V_174 , long V_70 ,
unsigned long * V_226 , enum V_223 * V_224 )
{
long V_119 = F_151 ( V_174 , V_70 , V_226 , V_224 ) ;
if ( ! V_119 )
F_160 ( V_174 , V_70 , 1 , true ) ;
return V_119 ;
}
static void F_166 ( struct V_173 * V_174 , long V_70 ,
long V_212 )
{
F_154 ( V_174 , V_70 , V_212 ) ;
F_160 ( V_174 , V_70 , V_212 , false ) ;
}
static void F_167 ( struct V_173 * V_174 )
{
F_168 ( V_174 ) ;
}
static int F_169 ( struct V_60 * V_12 , void * V_237 )
{
unsigned int * V_238 = ( unsigned int * ) V_237 ;
if ( V_12 -> V_239 != V_240 )
return 0 ;
if ( V_12 -> V_241 == V_242 ||
V_12 -> V_241 == V_243 ||
V_12 -> V_241 == V_244 )
* V_238 += 3 ;
else if ( ( V_12 -> V_241 >> 8 ) == V_245 )
* V_238 += 15 ;
else
* V_238 += 10 ;
return 0 ;
}
static unsigned int F_170 ( struct V_1 * V_2 )
{
unsigned int V_238 = 0 ;
#ifdef F_5
if ( ( V_2 -> V_9 & V_17 ) && V_2 -> V_18 ) {
F_169 ( V_2 -> V_18 , & V_238 ) ;
return V_238 ;
}
#endif
if ( ( V_2 -> V_9 & V_10 ) && V_2 -> V_11 ) {
F_169 ( V_2 -> V_11 , & V_238 ) ;
} else if ( ( V_2 -> V_9 & V_13 ) && V_2 -> V_15 ) {
struct V_60 * V_11 ;
F_34 (pdev, &pe->pbus->devices, bus_list)
F_169 ( V_11 , & V_238 ) ;
} else if ( ( V_2 -> V_9 & V_14 ) && V_2 -> V_15 ) {
F_171 ( V_2 -> V_15 , F_169 , & V_238 ) ;
}
return V_238 ;
}
static void F_172 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_191 * V_246 = NULL ;
struct V_173 * V_174 ;
unsigned int V_238 , V_247 = 0 ;
unsigned int V_248 , V_64 , V_249 , V_250 , V_67 ;
T_5 V_37 ;
void * V_190 ;
V_238 = F_170 ( V_2 ) ;
if ( ! V_238 )
return;
F_171 ( V_26 -> V_44 -> V_19 , F_169 ,
& V_247 ) ;
V_249 = ( V_238 * V_26 -> V_30 . V_251 ) / V_247 ;
if ( ! V_249 )
V_249 = 1 ;
do {
for ( V_64 = 0 ; V_64 <= V_26 -> V_30 . V_251 - V_249 ; V_64 ++ ) {
for ( V_250 = 0 , V_67 = V_64 ; V_67 < V_64 + V_249 ; V_67 ++ ) {
if ( V_26 -> V_30 . V_252 [ V_67 ] ==
V_112 )
V_250 ++ ;
}
if ( V_250 == V_249 )
goto V_253;
}
} while ( -- V_249 );
if ( ! V_249 ) {
F_60 ( V_2 , L_65 ) ;
return;
}
V_253:
V_174 = F_173 ( V_26 -> V_44 -> V_196 ) ;
if ( F_21 ( ! V_174 ) )
return;
F_174 ( & V_2 -> V_175 , V_26 -> V_44 -> V_45 ,
V_2 -> V_21 ) ;
F_175 ( V_26 -> V_44 -> V_196 , 0 , V_174 , & V_2 -> V_175 ) ;
F_78 ( V_2 , L_66 ,
V_238 , V_247 , V_64 , V_249 ) ;
F_78 ( V_2 , L_67 ,
V_64 * V_254 ,
( V_64 + V_249 ) * V_254 - 1 ) ;
V_248 = V_254 >> ( V_255 - 3 ) ;
V_246 = F_125 ( V_26 -> V_44 -> V_196 , V_79 ,
F_126 ( V_248 * V_249 ) ) ;
if ( ! V_246 ) {
F_65 ( V_2 , L_68 ) ;
goto V_52;
}
V_190 = F_127 ( V_246 ) ;
memset ( V_190 , 0 , V_248 * V_249 ) ;
for ( V_67 = 0 ; V_67 < V_249 ; V_67 ++ ) {
V_37 = F_129 ( V_26 -> V_39 ,
V_2 -> V_21 ,
V_64 + V_67 , 1 ,
F_130 ( V_190 ) + V_248 * V_67 ,
V_248 , V_256 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_69
L_70 , V_37 ) ;
goto V_52;
}
}
for ( V_67 = V_64 ; V_67 < V_64 + V_249 ; V_67 ++ )
V_26 -> V_30 . V_252 [ V_67 ] = V_2 -> V_21 ;
F_176 ( V_174 , V_190 , V_248 * V_249 ,
V_64 * V_254 ,
V_255 ) ;
V_174 -> V_257 = & V_258 ;
V_2 -> V_175 . V_259 = V_174 -> V_221 << V_174 -> V_233 ;
V_2 -> V_175 . V_260 = V_174 -> V_261 << V_174 -> V_233 ;
F_177 ( V_174 , V_26 -> V_44 -> V_196 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_120 ( & V_2 -> V_11 -> V_12 , V_174 ) ;
F_140 ( & V_2 -> V_11 -> V_12 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_139 ( V_2 , V_2 -> V_15 , true ) ;
return;
V_52:
if ( V_246 )
F_178 ( V_246 , F_126 ( V_248 * V_249 ) ) ;
if ( V_174 ) {
F_179 ( V_174 , & V_2 -> V_175 ) ;
F_98 ( V_174 ) ;
}
}
static long F_180 ( struct V_262 * V_175 ,
int V_263 , struct V_173 * V_174 )
{
struct V_1 * V_2 = F_144 ( V_175 , struct V_1 ,
V_175 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_5 V_37 ;
const unsigned long V_78 = V_174 -> V_264 ?
V_174 -> V_265 : V_174 -> V_261 ;
const T_16 V_266 = V_174 -> V_221 << V_174 -> V_233 ;
const T_16 V_267 = V_174 -> V_261 << V_174 -> V_233 ;
F_78 ( V_2 , L_71 , V_263 ,
V_266 , V_266 + V_267 - 1 ,
F_181 ( V_174 ) ) ;
V_37 = F_129 ( V_26 -> V_39 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_263 ,
V_174 -> V_264 + 1 ,
F_130 ( V_174 -> V_220 ) ,
V_78 << 3 ,
F_181 ( V_174 ) ) ;
if ( V_37 ) {
F_65 ( V_2 , L_72 , V_37 ) ;
return V_37 ;
}
F_175 ( V_26 -> V_44 -> V_196 , V_263 ,
V_174 , & V_2 -> V_175 ) ;
F_158 ( V_2 ) ;
return 0 ;
}
void F_95 ( struct V_1 * V_2 , bool V_268 )
{
T_17 V_269 = ( V_2 -> V_21 << 1 ) + 1 ;
T_5 V_37 ;
F_78 ( V_2 , L_73 , V_268 ? L_42 : L_43 ) ;
if ( V_268 ) {
T_18 V_201 = F_132 () ;
V_201 = F_123 ( V_201 ) ;
V_37 = F_182 ( V_2 -> V_26 -> V_39 ,
V_2 -> V_21 ,
V_269 ,
V_2 -> V_185 ,
V_201 ) ;
} else {
V_37 = F_182 ( V_2 -> V_26 -> V_39 ,
V_2 -> V_21 ,
V_269 ,
V_2 -> V_185 ,
0 ) ;
}
if ( V_37 )
F_65 ( V_2 , L_74 , V_37 ) ;
else
V_2 -> V_204 = V_268 ;
}
static long F_183 ( struct V_262 * V_175 ,
int V_263 , T_19 V_270 , T_16 V_187 , T_19 V_271 ,
struct V_173 * * V_272 )
{
struct V_1 * V_2 = F_144 ( V_175 , struct V_1 ,
V_175 ) ;
int V_273 = V_2 -> V_26 -> V_44 -> V_196 ;
T_16 V_274 = V_263 ? V_2 -> V_185 : V_175 -> V_259 ;
long V_119 ;
struct V_173 * V_174 ;
V_174 = F_173 ( V_273 ) ;
if ( ! V_174 )
return - V_170 ;
V_174 -> V_257 = & V_275 ;
V_119 = F_184 ( V_273 ,
V_274 , V_270 , V_187 ,
V_271 , V_174 ) ;
if ( V_119 ) {
F_98 ( V_174 ) ;
return V_119 ;
}
* V_272 = V_174 ;
return 0 ;
}
static long F_185 ( struct V_1 * V_2 )
{
struct V_173 * V_174 = NULL ;
long V_37 ;
const T_8 V_276 = F_186 ( F_124 () ) ;
const T_8 V_187 = F_187 ( ( T_8 ) V_2 -> V_175 . V_260 , V_276 ) ;
V_37 = F_183 ( & V_2 -> V_175 , 0 ,
V_255 ,
V_187 ,
V_277 , & V_174 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_75 ,
V_37 ) ;
return V_37 ;
}
F_177 ( V_174 , V_2 -> V_26 -> V_44 -> V_196 ) ;
V_37 = F_180 ( & V_2 -> V_175 , 0 , V_174 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_76 ,
V_37 ) ;
F_98 ( V_174 ) ;
return V_37 ;
}
if ( ! V_24 )
F_95 ( V_2 , true ) ;
if ( V_2 -> V_9 & V_10 )
F_120 ( & V_2 -> V_11 -> V_12 , V_174 ) ;
return 0 ;
}
static long F_94 ( struct V_262 * V_175 ,
int V_263 )
{
struct V_1 * V_2 = F_144 ( V_175 , struct V_1 ,
V_175 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
long V_119 ;
F_78 ( V_2 , L_77 , V_263 ) ;
V_119 = F_129 ( V_26 -> V_39 , V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_263 ,
0 , 0 ,
0 , 0 ) ;
if ( V_119 )
F_60 ( V_2 , L_78 , V_119 ) ;
else
F_158 ( V_2 ) ;
F_179 ( V_175 -> V_176 [ V_263 ] , V_175 ) ;
return V_119 ;
}
static unsigned long F_188 ( T_19 V_270 ,
T_16 V_187 , T_19 V_271 )
{
unsigned long V_278 = 0 ;
const unsigned V_279 = F_189 ( V_187 ) ;
unsigned V_280 = V_279 - V_270 ;
unsigned V_281 = V_280 + 3 ;
unsigned long V_282 = F_190 ( 0x1000UL , 1UL << V_281 ) ;
unsigned long V_283 ;
if ( ! V_271 || ( V_271 > V_284 ) ||
( V_187 > F_124 () ) ||
! F_191 ( V_187 ) )
return 0 ;
V_280 = ( V_280 + V_271 - 1 ) / V_271 ;
V_281 = V_280 + 3 ;
V_281 = F_192 ( unsigned , V_281 , V_285 ) ;
V_283 = 1UL << V_281 ;
for ( ; V_271 ; -- V_271 ) {
V_278 += F_29 ( V_282 , V_283 ) ;
V_282 /= V_283 ;
V_282 <<= 3 ;
V_282 = F_192 (unsigned long,
tce_table_size, direct_table_size) ;
}
return V_278 ;
}
static void F_193 ( struct V_262 * V_175 )
{
struct V_1 * V_2 = F_144 ( V_175 , struct V_1 ,
V_175 ) ;
struct V_173 * V_174 = V_2 -> V_175 . V_176 [ 0 ] ;
F_95 ( V_2 , false ) ;
F_94 ( & V_2 -> V_175 , 0 ) ;
if ( V_2 -> V_15 )
F_139 ( V_2 , V_2 -> V_15 , false ) ;
F_98 ( V_174 ) ;
}
static void F_194 ( struct V_262 * V_175 )
{
struct V_1 * V_2 = F_144 ( V_175 , struct V_1 ,
V_175 ) ;
F_185 ( V_2 ) ;
if ( V_2 -> V_15 )
F_139 ( V_2 , V_2 -> V_15 , false ) ;
}
static int F_195 ( struct V_286 * V_12 , void * V_287 )
{
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * * V_288 = V_287 ;
struct V_60 * V_11 = F_144 ( V_12 , struct V_60 , V_12 ) ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return 0 ;
V_44 = F_27 ( V_11 -> V_19 ) ;
V_26 = V_44 -> V_63 ;
if ( V_26 -> type != V_140 )
return 0 ;
* V_288 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
return 1 ;
}
static struct V_1 * F_196 (
struct V_262 * V_175 )
{
struct V_1 * V_289 = NULL ;
int V_119 = F_197 ( V_175 -> V_177 , & V_289 ,
F_195 ) ;
F_97 ( ! V_119 || ! V_289 ) ;
return V_289 ;
}
static long F_198 ( struct V_262 * V_175 ,
int V_263 , struct V_173 * V_174 )
{
long V_119 = F_180 ( V_175 , V_263 , V_174 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_199 ( F_196 ( V_175 ) , V_263 , V_174 ) ;
if ( V_119 )
F_94 ( V_175 , V_263 ) ;
return V_119 ;
}
static long F_200 (
struct V_262 * V_175 ,
int V_263 )
{
long V_119 = F_94 ( V_175 , V_263 ) ;
if ( V_119 )
return V_119 ;
return F_201 ( F_196 ( V_175 ) , V_263 ) ;
}
static void F_202 ( struct V_262 * V_175 )
{
F_203 ( F_196 ( V_175 ) ) ;
F_193 ( V_175 ) ;
}
static void F_204 ( void )
{
struct V_62 * V_44 , * V_160 ;
struct V_25 * V_26 ;
struct V_1 * V_2 , * V_290 ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_44 -> V_63 ;
if ( V_26 -> type != V_140 )
continue;
F_34 (pe, &phb->ioda.pe_list, list) {
V_290 = F_205 ( V_2 ) ;
if ( V_290 )
V_290 -> V_175 . V_291 = & V_292 ;
}
}
}
static void F_204 ( void ) { }
static T_13 * F_206 ( int V_273 , unsigned V_230 ,
unsigned V_271 , unsigned long V_293 ,
unsigned long * V_294 , unsigned long * V_295 )
{
struct V_191 * V_246 = NULL ;
T_13 * V_190 , * V_160 ;
unsigned V_296 = F_192 ( unsigned , V_230 , V_285 ) - V_285 ;
unsigned long V_297 = 1UL << ( V_296 + V_285 ) ;
unsigned V_298 = 1UL << ( V_230 - 3 ) ;
long V_67 ;
V_246 = F_125 ( V_273 , V_79 , V_296 ) ;
if ( ! V_246 ) {
F_74 ( L_79 , V_296 ) ;
return NULL ;
}
V_190 = F_127 ( V_246 ) ;
memset ( V_190 , 0 , V_297 ) ;
* V_295 += V_297 ;
-- V_271 ;
if ( ! V_271 ) {
* V_294 += V_297 ;
return V_190 ;
}
for ( V_67 = 0 ; V_67 < V_298 ; ++ V_67 ) {
V_160 = F_206 ( V_273 , V_230 ,
V_271 , V_293 , V_294 , V_295 ) ;
if ( ! V_160 )
break;
V_190 [ V_67 ] = F_128 ( F_130 ( V_160 ) |
V_198 | V_199 ) ;
if ( * V_294 >= V_293 )
break;
}
return V_190 ;
}
static long F_184 ( int V_273 , T_16 V_274 ,
T_19 V_270 , T_16 V_187 , T_19 V_271 ,
struct V_173 * V_174 )
{
void * V_190 ;
unsigned long V_144 = 0 , V_299 , V_295 = 0 ;
const unsigned V_279 = F_189 ( V_187 ) ;
unsigned V_280 = V_279 - V_270 ;
unsigned V_281 = F_192 ( unsigned , V_280 + 3 , V_285 ) ;
const unsigned long V_282 = 1UL << V_281 ;
if ( ! V_271 || ( V_271 > V_284 ) )
return - V_23 ;
if ( ( V_187 > F_124 () ) || ! F_191 ( V_187 ) )
return - V_23 ;
V_280 = ( V_280 + V_271 - 1 ) / V_271 ;
V_299 = V_280 + 3 ;
V_299 = F_192 ( unsigned , V_299 , V_285 ) ;
if ( ( V_299 - 3 ) * V_271 + V_270 >= 60 )
return - V_23 ;
V_190 = F_206 ( V_273 , V_299 ,
V_271 , V_282 , & V_144 , & V_295 ) ;
if ( ! V_190 )
return - V_170 ;
if ( V_144 < V_282 ) {
F_207 ( V_190 ,
1ULL << ( V_299 - 3 ) , V_271 - 1 ) ;
return - V_170 ;
}
F_176 ( V_174 , V_190 , V_282 , V_274 ,
V_270 ) ;
V_174 -> V_265 = 1ULL << ( V_299 - 3 ) ;
V_174 -> V_264 = V_271 - 1 ;
V_174 -> V_300 = V_295 ;
F_208 ( L_80 ,
V_187 , V_282 , V_274 ) ;
return 0 ;
}
static void F_207 ( T_13 * V_190 ,
unsigned long V_78 , unsigned V_3 )
{
const unsigned long V_301 = ( unsigned long ) V_190 &
~ ( V_198 | V_199 ) ;
if ( V_3 ) {
long V_67 ;
T_8 * V_160 = ( T_8 * ) V_301 ;
for ( V_67 = 0 ; V_67 < V_78 ; ++ V_67 ) {
unsigned long V_226 = F_209 ( V_160 [ V_67 ] ) ;
if ( ! ( V_226 & ( V_198 | V_199 ) ) )
continue;
F_207 ( F_210 ( V_226 ) , V_78 ,
V_3 - 1 ) ;
}
}
F_211 ( V_301 , F_126 ( V_78 << 3 ) ) ;
}
static void F_168 ( struct V_173 * V_174 )
{
const unsigned long V_78 = V_174 -> V_264 ?
V_174 -> V_265 : V_174 -> V_261 ;
if ( ! V_174 -> V_261 )
return;
F_207 ( ( T_13 * ) V_174 -> V_220 , V_78 ,
V_174 -> V_264 ) ;
}
static void F_108 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
T_5 V_37 ;
if ( ! F_170 ( V_2 ) )
return;
V_2 -> V_185 = 1ull << 59 ;
F_174 ( & V_2 -> V_175 , V_26 -> V_44 -> V_45 ,
V_2 -> V_21 ) ;
F_78 ( V_2 , L_81 ,
V_26 -> V_30 . V_302 ) ;
V_2 -> V_175 . V_259 = 0 ;
V_2 -> V_175 . V_260 = V_26 -> V_30 . V_302 ;
V_2 -> V_175 . V_303 =
V_304 ;
V_2 -> V_175 . V_305 = V_284 ;
V_2 -> V_175 . V_306 = V_307 | V_308 | V_309 ;
#ifdef F_212
V_2 -> V_175 . V_291 = & V_310 ;
#endif
V_37 = F_185 ( V_2 ) ;
if ( V_37 )
return;
if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_139 ( V_2 , V_2 -> V_15 , true ) ;
}
T_5 F_213 ( struct V_311 * V_312 , unsigned int V_313 )
{
struct V_25 * V_26 = F_144 ( V_312 , struct V_25 ,
V_30 . V_311 ) ;
return F_214 ( V_26 -> V_39 , V_313 ) ;
}
static void F_215 ( struct V_314 * V_315 )
{
T_5 V_37 ;
unsigned int V_313 = ( unsigned int ) F_216 ( V_315 ) ;
struct V_311 * V_312 = F_217 ( V_315 ) ;
V_37 = F_213 ( V_312 , V_313 ) ;
F_218 ( V_37 ) ;
F_219 ( V_315 ) ;
}
void F_220 ( struct V_25 * V_26 , unsigned int V_316 )
{
struct V_314 * V_317 ;
struct V_311 * V_318 ;
if ( V_26 -> V_161 != V_206 )
return;
if ( ! V_26 -> V_30 . V_319 ) {
V_317 = F_221 ( V_316 ) ;
V_318 = F_217 ( V_317 ) ;
V_26 -> V_30 . V_319 = 1 ;
V_26 -> V_30 . V_311 = * V_318 ;
V_26 -> V_30 . V_311 . V_320 = F_215 ;
}
F_222 ( V_316 , & V_26 -> V_30 . V_311 ) ;
}
bool F_223 ( struct V_311 * V_312 )
{
return V_312 -> V_320 == F_215 ;
}
static int F_224 ( struct V_25 * V_26 , struct V_60 * V_12 ,
unsigned int V_321 , unsigned int V_316 ,
unsigned int V_322 , struct V_323 * V_324 )
{
struct V_1 * V_2 = F_56 ( V_12 ) ;
unsigned int V_325 = V_321 - V_26 -> V_326 ;
T_7 V_237 ;
int V_37 ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_141 < 0 )
return - V_118 ;
if ( V_12 -> V_327 )
V_322 = 0 ;
V_37 = F_225 ( V_26 -> V_39 , V_2 -> V_21 , V_325 ) ;
if ( V_37 ) {
F_15 ( L_82 ,
F_75 ( V_12 ) , V_37 , V_325 ) ;
return - V_59 ;
}
if ( V_322 ) {
T_13 V_328 ;
V_37 = F_226 ( V_26 -> V_39 , V_2 -> V_141 , V_325 , 1 ,
& V_328 , & V_237 ) ;
if ( V_37 ) {
F_15 ( L_83 ,
F_75 ( V_12 ) , V_37 ) ;
return - V_59 ;
}
V_324 -> V_329 = F_209 ( V_328 ) >> 32 ;
V_324 -> V_330 = F_209 ( V_328 ) & 0xfffffffful ;
} else {
T_7 V_331 ;
V_37 = F_227 ( V_26 -> V_39 , V_2 -> V_141 , V_325 , 1 ,
& V_331 , & V_237 ) ;
if ( V_37 ) {
F_15 ( L_84 ,
F_75 ( V_12 ) , V_37 ) ;
return - V_59 ;
}
V_324 -> V_329 = 0 ;
V_324 -> V_330 = F_228 ( V_331 ) ;
}
V_324 -> V_237 = F_228 ( V_237 ) ;
F_220 ( V_26 , V_316 ) ;
F_208 ( L_85
L_86 ,
F_75 ( V_12 ) , V_322 ? L_87 : L_88 , V_321 , V_325 ,
V_324 -> V_329 , V_324 -> V_330 , V_237 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_229 ( struct V_25 * V_26 )
{
unsigned int V_125 ;
const T_7 * V_332 = F_46 ( V_26 -> V_44 -> V_88 ,
L_89 , NULL ) ;
if ( ! V_332 ) {
V_332 = F_46 ( V_26 -> V_44 -> V_88 , L_90 , NULL ) ;
}
if ( ! V_332 )
return;
V_26 -> V_326 = F_230 ( V_332 ) ;
V_125 = F_230 ( V_332 + 1 ) ;
if ( F_231 ( & V_26 -> V_333 , V_125 , V_26 -> V_44 -> V_88 ) ) {
F_74 ( L_91 ,
V_26 -> V_44 -> V_45 ) ;
return;
}
V_26 -> V_334 = F_224 ;
V_26 -> V_335 = 1 ;
F_10 ( L_92 ,
V_125 , V_26 -> V_326 ) ;
}
static void F_229 ( struct V_25 * V_26 ) { }
static void F_232 ( struct V_60 * V_11 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
const T_4 V_336 = V_26 -> V_30 . V_56 >> 2 ;
struct V_27 * V_89 ;
int V_67 ;
T_4 V_78 , V_337 ;
struct V_110 * V_111 ;
int V_338 , V_169 ;
if ( ! V_11 -> V_147 || V_11 -> V_339 )
return;
V_111 = F_57 ( V_11 ) ;
V_111 -> V_181 = 0 ;
V_111 -> V_165 = false ;
V_169 = F_90 ( V_11 ) ;
V_338 = V_26 -> V_30 . V_46 ;
V_337 = 0 ;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || V_89 -> V_69 )
continue;
if ( ! F_12 ( V_89 -> V_9 ) ) {
F_233 ( & V_11 -> V_12 , L_93
L_94 ,
V_67 , V_89 ) ;
goto V_340;
}
V_337 += F_70 ( V_11 ,
V_67 + V_149 ) ;
if ( V_337 > V_336 ) {
V_338 = F_123 ( V_169 ) ;
F_71 ( & V_11 -> V_12 ,
L_95 ,
V_337 , V_336 , V_338 ) ;
V_111 -> V_165 = true ;
break;
}
}
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || V_89 -> V_69 )
continue;
V_78 = F_70 ( V_11 , V_67 + V_149 ) ;
if ( V_111 -> V_165 && ( V_78 < V_341 ) )
goto V_340;
F_234 ( & V_11 -> V_12 , L_96 , V_67 , V_89 ) ;
V_89 -> V_57 = V_89 -> V_29 + V_78 * V_338 - 1 ;
F_234 ( & V_11 -> V_12 , L_97 , V_89 ) ;
F_71 ( & V_11 -> V_12 , L_98 ,
V_67 , V_89 , V_338 ) ;
}
V_111 -> V_181 = V_338 ;
return;
V_340:
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
V_89 -> V_9 = 0 ;
V_89 -> V_57 = V_89 -> V_29 - 1 ;
}
}
static void F_235 ( struct V_1 * V_2 ,
struct V_27 * V_89 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_342 V_343 ;
int V_70 ;
T_5 V_37 ;
if ( ! V_89 || ! V_89 -> V_9 || V_89 -> V_29 > V_89 -> V_57 )
return;
if ( V_89 -> V_9 & V_344 ) {
V_343 . V_29 = V_89 -> V_29 - V_26 -> V_30 . V_345 ;
V_343 . V_57 = V_89 -> V_57 - V_26 -> V_30 . V_345 ;
V_70 = V_343 . V_29 / V_26 -> V_30 . V_346 ;
while ( V_70 < V_26 -> V_30 . V_46 &&
V_343 . V_29 <= V_343 . V_57 ) {
V_26 -> V_30 . V_347 [ V_70 ] = V_2 -> V_21 ;
V_37 = F_43 ( V_26 -> V_39 ,
V_2 -> V_21 , V_348 , 0 , V_70 ) ;
if ( V_37 != V_41 ) {
F_74 ( L_99 ,
V_43 , V_37 , V_70 , V_2 -> V_21 ) ;
break;
}
V_343 . V_29 += V_26 -> V_30 . V_346 ;
V_70 ++ ;
}
} else if ( ( V_89 -> V_9 & V_96 ) &&
! F_11 ( V_26 , V_89 ) ) {
V_343 . V_29 = V_89 -> V_29 -
V_26 -> V_44 -> V_97 [ 0 ] -
V_26 -> V_30 . V_302 ;
V_343 . V_57 = V_89 -> V_57 -
V_26 -> V_44 -> V_97 [ 0 ] -
V_26 -> V_30 . V_302 ;
V_70 = V_343 . V_29 / V_26 -> V_30 . V_349 ;
while ( V_70 < V_26 -> V_30 . V_46 &&
V_343 . V_29 <= V_343 . V_57 ) {
V_26 -> V_30 . V_350 [ V_70 ] = V_2 -> V_21 ;
V_37 = F_43 ( V_26 -> V_39 ,
V_2 -> V_21 , V_351 , 0 , V_70 ) ;
if ( V_37 != V_41 ) {
F_74 ( L_100 ,
V_43 , V_37 , V_70 , V_2 -> V_21 ) ;
break;
}
V_343 . V_29 += V_26 -> V_30 . V_349 ;
V_70 ++ ;
}
}
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_60 * V_11 ;
int V_67 ;
F_97 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_34 (pdev, &pe->pbus->devices, bus_list) {
for ( V_67 = 0 ; V_67 <= V_68 ; V_67 ++ )
F_235 ( V_2 , & V_11 -> V_27 [ V_67 ] ) ;
if ( ! ( V_2 -> V_9 & V_14 ) || ! F_237 ( V_11 ) )
continue;
for ( V_67 = 0 ; V_67 < V_352 ; V_67 ++ )
F_235 ( V_2 ,
& V_11 -> V_27 [ V_353 + V_67 ] ) ;
}
}
static int F_238 ( void * V_237 , T_8 V_227 )
{
struct V_62 * V_44 ;
struct V_25 * V_26 ;
T_3 V_119 ;
if ( V_227 != 1ULL )
return - V_23 ;
V_44 = (struct V_62 * ) V_237 ;
if ( ! V_44 || ! V_44 -> V_63 )
return - V_203 ;
V_26 = V_44 -> V_63 ;
V_119 = F_239 ( V_26 -> V_39 , V_26 -> V_354 ,
V_26 -> V_355 ) ;
if ( V_119 != V_41 )
return - V_59 ;
F_240 ( V_26 -> V_44 , V_26 -> V_354 ) ;
return 0 ;
}
static void F_241 ( void )
{
#ifdef F_242
struct V_62 * V_44 , * V_160 ;
struct V_25 * V_26 ;
char V_94 [ 16 ] ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_44 -> V_63 ;
V_26 -> V_356 = 1 ;
sprintf ( V_94 , L_101 , V_44 -> V_45 ) ;
V_26 -> V_357 = F_243 ( V_94 , V_358 ) ;
if ( ! V_26 -> V_357 ) {
F_76 ( L_102 ,
V_43 , V_44 -> V_45 ) ;
continue;
}
F_244 ( L_103 , 0200 , V_26 -> V_357 , V_44 ,
& V_359 ) ;
}
#endif
}
static void F_245 ( void )
{
F_85 () ;
F_204 () ;
F_241 () ;
#ifdef F_246
F_247 () ;
F_248 () ;
#endif
}
static T_4 F_249 ( struct V_74 * V_19 ,
unsigned long type )
{
struct V_60 * V_360 ;
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
int V_361 = 0 ;
V_360 = V_19 -> V_120 ;
while ( V_360 ) {
if ( F_250 ( V_360 ) == V_362 ) {
V_361 ++ ;
if ( V_361 >= 2 )
return 1 ;
}
V_360 = V_360 -> V_19 -> V_120 ;
}
if ( V_26 -> V_30 . V_56 && F_12 ( type ) )
return V_26 -> V_30 . V_56 ;
if ( type & V_96 )
return V_26 -> V_30 . V_349 ;
return V_26 -> V_30 . V_346 ;
}
static void F_251 ( struct V_74 * V_19 ,
unsigned long type )
{
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_60 * V_360 = V_19 -> V_120 ;
struct V_27 * V_28 , * V_363 ;
bool V_364 = false ;
int V_67 ;
if ( ! F_36 ( V_360 -> V_19 ) &&
! F_36 ( V_360 -> V_19 -> V_120 -> V_19 ) )
return;
for ( V_67 = 0 ; V_67 < V_352 ; V_67 ++ ) {
V_28 = & V_360 -> V_27 [ V_353 + V_67 ] ;
if ( ! V_28 -> V_9 || ! V_28 -> V_69 )
continue;
V_363 = NULL ;
if ( V_28 -> V_9 & type & V_344 )
V_363 = & V_44 -> V_365 ;
else if ( F_11 ( V_26 , V_28 ) &&
( type & V_35 ) &&
V_26 -> V_30 . V_56 )
V_363 = & V_44 -> V_54 [ 1 ] ;
else if ( V_28 -> V_9 & type & V_96 ) {
V_363 = & V_44 -> V_54 [ 0 ] ;
V_364 = true ;
}
V_28 -> V_29 = V_363 -> V_29 ;
V_28 -> V_57 = V_363 -> V_57 ;
if ( V_364 ) {
V_28 -> V_57 += 0x10000 ;
V_28 -> V_57 -= 0x100000 ;
}
}
}
static void F_252 ( struct V_74 * V_19 , unsigned long type )
{
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_60 * V_360 = V_19 -> V_120 ;
struct V_1 * V_2 ;
bool V_75 = ( F_250 ( V_360 ) == V_362 ) ;
F_251 ( V_19 , type ) ;
if ( ! V_26 -> V_30 . V_366 ) {
V_2 = F_81 ( V_26 -> V_44 -> V_19 , false ) ;
if ( V_2 ) {
V_26 -> V_30 . V_155 = V_2 -> V_21 ;
V_26 -> V_30 . V_366 = true ;
}
}
if ( F_253 ( & V_19 -> V_367 ) )
return;
if ( V_26 -> V_100 )
V_26 -> V_100 ( V_19 , NULL , V_75 ) ;
V_2 = F_81 ( V_19 , V_75 ) ;
if ( ! V_2 )
return;
F_236 ( V_2 ) ;
switch ( V_26 -> type ) {
case V_86 :
F_172 ( V_26 , V_2 ) ;
break;
case V_92 :
F_108 ( V_26 , V_2 ) ;
break;
default:
F_15 ( L_104 ,
V_43 , V_26 -> V_44 -> V_45 , V_26 -> type ) ;
}
}
static T_4 F_254 ( void )
{
return V_195 ;
}
static T_4 F_255 ( struct V_60 * V_11 ,
int V_368 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
T_4 V_369 ;
V_369 = F_70 ( V_11 , V_368 ) ;
if ( ! V_111 -> V_181 )
return V_369 ;
if ( V_111 -> V_165 )
return F_190 ( V_369 , ( T_4 ) V_26 -> V_30 . V_56 ) ;
return V_111 -> V_181 * V_369 ;
}
bool F_256 ( struct V_60 * V_12 )
{
struct V_62 * V_44 = F_27 ( V_12 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 ;
if ( ! V_26 -> V_356 )
return true ;
V_111 = F_57 ( V_12 ) ;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return false ;
return true ;
}
static long F_257 ( struct V_262 * V_175 ,
int V_263 )
{
struct V_1 * V_2 = F_144 ( V_175 ,
struct V_1 , V_175 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_370 ;
long V_37 ;
F_78 ( V_2 , L_77 , V_263 ) ;
for ( V_370 = 0 ; V_370 < V_26 -> V_30 . V_251 ; V_370 ++ ) {
if ( V_26 -> V_30 . V_252 [ V_370 ] != V_2 -> V_21 )
continue;
V_37 = F_129 ( V_26 -> V_39 , V_2 -> V_21 ,
V_370 , 0 , 0ul , 0ul , 0ul ) ;
if ( V_37 != V_41 ) {
F_60 ( V_2 , L_105 ,
V_37 , V_370 ) ;
return V_37 ;
}
V_26 -> V_30 . V_252 [ V_370 ] = V_112 ;
}
F_179 ( V_175 -> V_176 [ V_263 ] , V_175 ) ;
return V_41 ;
}
static void F_258 ( struct V_1 * V_2 )
{
unsigned int V_238 = F_170 ( V_2 ) ;
struct V_173 * V_174 = V_2 -> V_175 . V_176 [ 0 ] ;
T_5 V_37 ;
if ( ! V_238 )
return;
V_37 = F_257 ( & V_2 -> V_175 , 0 ) ;
if ( V_37 != V_41 )
return;
F_142 ( V_174 , V_174 -> V_221 , V_174 -> V_261 , false ) ;
if ( V_2 -> V_175 . V_177 ) {
F_96 ( V_2 -> V_175 . V_177 ) ;
F_21 ( V_2 -> V_175 . V_177 ) ;
}
F_211 ( V_174 -> V_220 , F_126 ( V_174 -> V_261 << 3 ) ) ;
F_98 ( V_174 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_173 * V_174 = V_2 -> V_175 . V_176 [ 0 ] ;
unsigned int V_238 = F_170 ( V_2 ) ;
#ifdef F_212
T_5 V_37 ;
#endif
if ( ! V_238 )
return;
#ifdef F_212
V_37 = F_94 ( & V_2 -> V_175 , 0 ) ;
if ( V_37 )
F_60 ( V_2 , L_54 , V_37 ) ;
#endif
F_95 ( V_2 , false ) ;
if ( V_2 -> V_175 . V_177 ) {
F_96 ( V_2 -> V_175 . V_177 ) ;
F_21 ( V_2 -> V_175 . V_177 ) ;
}
F_168 ( V_174 ) ;
F_98 ( V_174 ) ;
}
static void F_260 ( struct V_1 * V_2 ,
unsigned short V_168 ,
unsigned int * V_371 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_370 ;
T_5 V_37 ;
for ( V_370 = 0 ; V_370 < V_26 -> V_30 . V_46 ; V_370 ++ ) {
if ( V_371 [ V_370 ] != V_2 -> V_21 )
continue;
if ( V_168 == V_50 )
V_37 = F_43 ( V_26 -> V_39 ,
V_26 -> V_30 . V_55 , V_168 ,
V_370 / V_73 ,
V_370 % V_73 ) ;
else
V_37 = F_43 ( V_26 -> V_39 ,
V_26 -> V_30 . V_55 , V_168 , 0 , V_370 ) ;
if ( V_37 != V_41 )
F_60 ( V_2 , L_106 ,
V_37 , V_168 , V_370 ) ;
V_371 [ V_370 ] = V_112 ;
}
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_26 -> type == V_86 ) {
F_260 ( V_2 , V_348 ,
V_26 -> V_30 . V_347 ) ;
F_260 ( V_2 , V_351 ,
V_26 -> V_30 . V_350 ) ;
F_260 ( V_2 , V_50 ,
V_26 -> V_30 . V_80 ) ;
} else if ( V_26 -> type == V_92 ) {
F_260 ( V_2 , V_351 ,
V_26 -> V_30 . V_350 ) ;
}
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_1 * V_102 , * V_160 ;
F_101 ( & V_2 -> V_85 ) ;
switch ( V_26 -> type ) {
case V_86 :
F_258 ( V_2 ) ;
break;
case V_92 :
F_259 ( V_2 ) ;
break;
default:
F_21 ( 1 ) ;
}
F_261 ( V_2 ) ;
F_62 ( V_2 -> V_26 , V_2 ) ;
if ( V_2 -> V_9 & V_81 ) {
F_86 (slave, tmp, &pe->slaves, list) {
F_101 ( & V_102 -> V_85 ) ;
F_20 ( V_102 ) ;
}
}
if ( V_26 -> V_30 . V_366 &&
V_26 -> V_30 . V_155 == V_2 -> V_21 )
V_26 -> V_30 . V_366 = false ;
else
F_20 ( V_2 ) ;
}
static void F_263 ( struct V_60 * V_11 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
if ( V_11 -> V_372 )
return;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
V_111 -> V_21 = V_112 ;
F_21 ( -- V_2 -> V_154 < 0 ) ;
if ( V_2 -> V_154 == 0 )
F_262 ( V_2 ) ;
}
static void F_264 ( struct V_62 * V_44 )
{
struct V_25 * V_26 = V_44 -> V_63 ;
F_265 ( V_26 -> V_39 , V_373 ,
V_374 ) ;
}
static int F_266 ( struct V_60 * V_375 , T_8 V_200 )
{
F_267 ( & V_375 -> V_12 ,
L_107 ,
V_43 ) ;
return - V_376 ;
}
static void T_2 F_268 ( struct V_87 * V_377 ,
T_8 V_378 , int V_379 )
{
struct V_62 * V_44 ;
struct V_25 * V_26 ;
unsigned long V_78 , V_380 , V_381 , V_382 ;
unsigned long V_383 = 0 , V_384 = 0 ;
struct V_27 V_28 ;
const T_13 * V_385 ;
const T_7 * V_386 ;
int V_387 ;
unsigned int V_66 ;
T_8 V_388 ;
void * V_389 ;
long V_37 ;
if ( ! F_269 ( V_377 ) )
return;
F_10 ( L_108 , V_390 [ V_379 ] , V_377 ) ;
V_385 = F_46 ( V_377 , L_109 , NULL ) ;
if ( ! V_385 ) {
F_74 ( L_110 ) ;
return;
}
V_388 = F_270 ( V_385 ) ;
F_18 ( L_111 , V_388 ) ;
V_26 = F_271 ( sizeof( struct V_25 ) , 0 ) ;
V_26 -> V_44 = V_44 = F_272 ( V_377 ) ;
if ( ! V_26 -> V_44 ) {
F_74 ( L_112 ,
V_377 ) ;
F_273 ( F_130 ( V_26 ) , sizeof( struct V_25 ) ) ;
return;
}
F_274 ( & V_26 -> V_391 ) ;
V_386 = F_46 ( V_377 , L_113 , & V_387 ) ;
if ( V_386 && V_387 == 8 ) {
V_44 -> V_392 = F_228 ( V_386 [ 0 ] ) ;
V_44 -> V_393 = F_228 ( V_386 [ 1 ] ) ;
} else {
F_15 ( L_114 , V_377 ) ;
V_44 -> V_392 = 0 ;
V_44 -> V_393 = 0xff ;
}
V_44 -> V_63 = V_26 ;
V_26 -> V_378 = V_378 ;
V_26 -> V_39 = V_388 ;
V_26 -> type = V_379 ;
F_275 ( & V_26 -> V_30 . V_183 ) ;
if ( F_276 ( V_377 , L_115 ) )
V_26 -> V_161 = V_394 ;
else if ( F_276 ( V_377 , L_116 ) )
V_26 -> V_161 = V_206 ;
else if ( F_276 ( V_377 , L_117 ) )
V_26 -> V_161 = V_234 ;
else if ( F_276 ( V_377 , L_118 ) )
V_26 -> V_161 = V_162 ;
else
V_26 -> V_161 = V_395 ;
V_386 = F_46 ( V_377 , L_119 , NULL ) ;
if ( V_386 )
V_26 -> V_355 = F_230 ( V_386 ) ;
else
V_26 -> V_355 = V_396 ;
V_26 -> V_354 = F_271 ( V_26 -> V_355 , 0 ) ;
F_277 ( V_44 , V_377 , ! V_44 -> V_45 ) ;
if ( ! F_278 ( V_377 , 0 , & V_28 ) ) {
V_26 -> V_210 = V_28 . V_29 ;
V_26 -> V_211 = F_279 ( V_28 . V_29 , F_50 ( & V_28 ) ) ;
if ( V_26 -> V_211 == NULL )
F_74 ( L_120 ) ;
}
V_26 -> V_30 . V_46 = 1 ;
V_386 = F_46 ( V_377 , L_121 , NULL ) ;
if ( V_386 )
V_26 -> V_30 . V_46 = F_230 ( V_386 ) ;
V_386 = F_46 ( V_377 , L_122 , NULL ) ;
if ( V_386 )
V_26 -> V_30 . V_55 = F_230 ( V_386 ) ;
for ( V_66 = 0 ; V_66 < F_280 ( V_26 -> V_30 . V_137 ) ; V_66 ++ )
V_26 -> V_30 . V_137 [ V_66 ] = V_112 ;
F_44 ( V_26 ) ;
V_26 -> V_30 . V_397 = F_50 ( & V_44 -> V_54 [ 0 ] ) ;
V_26 -> V_30 . V_397 += 0x10000 ;
V_26 -> V_30 . V_349 = V_26 -> V_30 . V_397 / V_26 -> V_30 . V_46 ;
V_26 -> V_30 . V_302 = V_44 -> V_54 [ 0 ] . V_29 - V_44 -> V_97 [ 0 ] ;
V_26 -> V_30 . V_398 = V_44 -> V_399 ;
V_26 -> V_30 . V_346 = V_26 -> V_30 . V_398 / V_26 -> V_30 . V_46 ;
V_26 -> V_30 . V_345 = 0 ;
V_26 -> V_30 . V_251 = V_26 -> V_30 . V_302 /
V_254 ;
V_78 = F_29 ( F_192 ( unsigned , V_26 -> V_30 . V_46 , 8 ) / 8 ,
sizeof( unsigned long ) ) ;
V_380 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( V_26 -> V_30 . V_80 [ 0 ] ) ;
V_381 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( V_26 -> V_30 . V_350 [ 0 ] ) ;
if ( V_26 -> type == V_86 ) {
V_383 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( V_26 -> V_30 . V_347 [ 0 ] ) ;
V_384 = V_78 ;
V_78 += V_26 -> V_30 . V_251 *
sizeof( V_26 -> V_30 . V_252 [ 0 ] ) ;
}
V_382 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( struct V_1 ) ;
V_389 = F_271 ( V_78 , 0 ) ;
V_26 -> V_30 . V_47 = V_389 ;
V_26 -> V_30 . V_80 = V_389 + V_380 ;
V_26 -> V_30 . V_350 = V_389 + V_381 ;
for ( V_66 = 0 ; V_66 < V_26 -> V_30 . V_46 ; V_66 ++ ) {
V_26 -> V_30 . V_80 [ V_66 ] = V_112 ;
V_26 -> V_30 . V_350 [ V_66 ] = V_112 ;
}
if ( V_26 -> type == V_86 ) {
V_26 -> V_30 . V_347 = V_389 + V_383 ;
for ( V_66 = 0 ; V_66 < V_26 -> V_30 . V_46 ; V_66 ++ )
V_26 -> V_30 . V_347 [ V_66 ] = V_112 ;
V_26 -> V_30 . V_252 = V_389 + V_384 ;
for ( V_66 = 0 ; V_66 < V_26 -> V_30 . V_251 ; V_66 ++ )
V_26 -> V_30 . V_252 [ V_66 ] = V_112 ;
}
V_26 -> V_30 . V_38 = V_389 + V_382 ;
F_16 ( V_26 , V_26 -> V_30 . V_55 ) ;
if ( V_26 -> V_30 . V_55 == 0 ) {
V_26 -> V_30 . V_155 = 1 ;
F_16 ( V_26 , V_26 -> V_30 . V_155 ) ;
} else if ( V_26 -> V_30 . V_55 == ( V_26 -> V_30 . V_46 - 1 ) ) {
V_26 -> V_30 . V_155 = V_26 -> V_30 . V_55 - 1 ;
F_16 ( V_26 , V_26 -> V_30 . V_155 ) ;
} else {
V_26 -> V_30 . V_155 = V_112 ;
}
F_41 ( & V_26 -> V_30 . V_153 ) ;
F_275 ( & V_26 -> V_30 . V_179 ) ;
V_26 -> V_30 . V_251 = V_26 -> V_30 . V_302 /
V_254 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_10 ( L_123 ,
V_26 -> V_30 . V_46 , V_26 -> V_30 . V_55 ,
V_26 -> V_30 . V_397 , V_26 -> V_30 . V_349 ) ;
if ( V_26 -> V_30 . V_32 )
F_10 ( L_124 ,
V_26 -> V_30 . V_32 , V_26 -> V_30 . V_56 ) ;
if ( V_26 -> V_30 . V_398 )
F_10 ( L_125 ,
V_26 -> V_30 . V_398 , V_26 -> V_30 . V_346 ) ;
V_26 -> V_44 -> V_291 = & V_400 ;
V_26 -> V_401 = F_54 ;
V_26 -> V_402 = F_51 ;
V_26 -> V_403 = F_53 ;
F_229 ( V_26 ) ;
V_404 . V_405 = F_245 ;
if ( V_26 -> type == V_140 ) {
V_44 -> V_406 = V_407 ;
} else {
V_26 -> V_408 = F_117 ;
V_44 -> V_406 = V_409 ;
}
V_404 . V_410 = F_254 ;
#ifdef F_5
V_404 . V_411 = F_232 ;
V_404 . V_412 = F_255 ;
#endif
F_281 ( V_413 ) ;
V_37 = F_265 ( V_388 , V_373 , V_374 ) ;
if ( V_37 )
F_76 ( L_126 , V_37 ) ;
if ( F_282 () ) {
F_10 ( L_127 ) ;
F_283 ( V_44 , V_414 ) ;
F_283 ( V_44 , V_415 ) ;
}
if ( ! V_26 -> V_99 || V_26 -> V_99 ( V_26 ) )
V_44 -> V_54 [ 1 ] . V_9 = 0 ;
}
void T_2 F_284 ( struct V_87 * V_377 )
{
F_268 ( V_377 , 0 , V_92 ) ;
}
void T_2 F_285 ( struct V_87 * V_377 )
{
F_268 ( V_377 , 0 , V_140 ) ;
}
void T_2 F_286 ( struct V_87 * V_377 )
{
struct V_87 * V_416 ;
const T_13 * V_385 ;
T_8 V_378 ;
F_10 ( L_128 , V_377 ) ;
V_385 = F_46 ( V_377 , L_129 , NULL ) ;
if ( ! V_385 ) {
F_74 ( L_130 ) ;
return;
}
V_378 = F_270 ( V_385 ) ;
F_208 ( L_131 , V_378 ) ;
F_287 (np, phbn) {
if ( F_276 ( V_416 , L_132 ) )
F_268 ( V_416 , V_378 , V_86 ) ;
}
}
