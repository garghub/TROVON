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
V_88 -> V_94 ) ;
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
V_89 -> V_95 = V_88 -> V_94 ;
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
}
}
}
static int F_87 ( struct V_60 * V_11 , T_12 V_146 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_110 * V_111 ;
int V_67 , V_161 ;
int V_162 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
if ( V_111 -> V_163 )
V_162 = V_146 ;
else
V_162 = 1 ;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ )
for ( V_161 = 0 ; V_161 < V_162 ; V_161 ++ ) {
if ( V_111 -> V_164 [ V_161 ] [ V_67 ] == V_165 )
continue;
F_25 ( V_26 -> V_39 ,
V_50 , V_111 -> V_164 [ V_161 ] [ V_67 ] , 0 ) ;
F_22 ( V_111 -> V_164 [ V_161 ] [ V_67 ] , & V_26 -> V_30 . V_98 ) ;
V_111 -> V_164 [ V_161 ] [ V_67 ] = V_165 ;
}
F_39 ( V_111 -> V_164 ) ;
return 0 ;
}
static int F_88 ( struct V_60 * V_11 , T_12 V_146 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_110 * V_111 ;
unsigned int V_166 ;
struct V_27 * V_89 ;
int V_67 , V_161 ;
T_5 V_37 ;
int V_167 ;
T_4 V_78 , V_29 ;
int V_48 ;
int V_162 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
V_167 = F_89 ( V_11 ) ;
if ( V_111 -> V_163 )
V_162 = V_146 ;
else
V_162 = 1 ;
V_111 -> V_164 = F_90 ( sizeof( * V_111 -> V_164 ) * V_162 , V_79 ) ;
if ( ! V_111 -> V_164 )
return - V_168 ;
for ( V_67 = 0 ; V_67 < V_162 ; V_67 ++ )
for ( V_161 = 0 ; V_161 < V_148 ; V_161 ++ )
V_111 -> V_164 [ V_67 ] [ V_161 ] = V_165 ;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || ! V_89 -> V_69 )
continue;
for ( V_161 = 0 ; V_161 < V_162 ; V_161 ++ ) {
do {
V_166 = F_91 ( & V_26 -> V_30 . V_98 ,
V_26 -> V_30 . V_51 + 1 , 0 ) ;
if ( V_166 >= V_26 -> V_30 . V_51 + 1 )
goto V_169;
} while ( F_17 ( V_166 , & V_26 -> V_30 . V_98 ) );
V_111 -> V_164 [ V_161 ] [ V_67 ] = V_166 ;
if ( V_111 -> V_163 ) {
V_78 = F_70 ( V_11 ,
V_149 + V_67 ) ;
V_29 = V_89 -> V_29 + V_78 * V_161 ;
} else {
V_78 = F_50 ( V_89 ) ;
V_29 = V_89 -> V_29 ;
}
if ( V_111 -> V_163 ) {
V_48 = V_111 -> V_170 [ V_161 ] ;
V_37 = F_43 ( V_26 -> V_39 ,
V_48 , V_50 ,
V_111 -> V_164 [ V_161 ] [ V_67 ] , 0 ) ;
}
V_37 = F_24 ( V_26 -> V_39 ,
V_50 ,
V_111 -> V_164 [ V_161 ] [ V_67 ] ,
V_29 ,
0 ,
V_78 ) ;
if ( V_37 != V_41 ) {
F_63 ( & V_11 -> V_12 , L_52 ,
V_166 , V_37 ) ;
goto V_169;
}
if ( V_111 -> V_163 )
V_37 = F_25 ( V_26 -> V_39 ,
V_50 , V_111 -> V_164 [ V_161 ] [ V_67 ] , 2 ) ;
else
V_37 = F_25 ( V_26 -> V_39 ,
V_50 , V_111 -> V_164 [ V_161 ] [ V_67 ] , 1 ) ;
if ( V_37 != V_41 ) {
F_63 ( & V_11 -> V_12 , L_53 ,
V_166 , V_37 ) ;
goto V_169;
}
}
}
return 0 ;
V_169:
F_87 ( V_11 , V_146 ) ;
return - V_150 ;
}
static void F_92 ( struct V_60 * V_12 , struct V_1 * V_2 )
{
struct V_171 * V_172 ;
T_5 V_37 ;
V_172 = V_2 -> V_173 . V_174 [ 0 ] ;
V_37 = F_93 ( & V_2 -> V_173 , 0 ) ;
if ( V_37 )
F_60 ( V_2 , L_54 , V_37 ) ;
F_94 ( V_2 , false ) ;
if ( V_2 -> V_173 . V_175 ) {
F_95 ( V_2 -> V_173 . V_175 ) ;
F_96 ( V_2 -> V_173 . V_175 ) ;
}
F_97 ( V_172 ) ;
F_98 ( V_172 , F_99 ( V_12 -> V_12 . V_176 ) ) ;
}
static void F_100 ( struct V_60 * V_11 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * V_2 , * V_177 ;
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
F_92 ( V_11 , V_2 ) ;
F_101 ( & V_26 -> V_30 . V_178 ) ;
F_102 ( & V_2 -> V_85 ) ;
F_103 ( & V_26 -> V_30 . V_178 ) ;
F_62 ( V_26 , V_2 ) ;
F_20 ( V_2 ) ;
}
}
void F_104 ( struct V_60 * V_11 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_110 * V_111 ;
struct V_179 * V_180 ;
T_12 V_146 , V_67 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
V_180 = V_11 -> V_181 ;
V_146 = V_111 -> V_146 ;
F_100 ( V_11 ) ;
if ( V_26 -> type == V_92 ) {
if ( ! V_111 -> V_163 )
F_69 ( V_11 , - * V_111 -> V_170 ) ;
F_87 ( V_11 , V_146 ) ;
if ( V_111 -> V_163 ) {
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ ) {
if ( V_111 -> V_170 [ V_67 ] == V_112 )
continue;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_170 [ V_67 ] ] ;
F_20 ( V_2 ) ;
}
} else
F_105 ( V_26 -> V_30 . V_47 , * V_111 -> V_170 , V_146 ) ;
F_39 ( V_111 -> V_170 ) ;
}
}
static void F_106 ( struct V_60 * V_11 , T_12 V_146 )
{
struct V_74 * V_19 ;
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
int V_48 ;
T_12 V_182 ;
struct V_110 * V_111 ;
V_19 = V_11 -> V_19 ;
V_44 = F_27 ( V_19 ) ;
V_26 = V_44 -> V_63 ;
V_111 = F_57 ( V_11 ) ;
if ( ! V_11 -> V_147 )
return;
for ( V_182 = 0 ; V_182 < V_146 ; V_182 ++ ) {
if ( V_111 -> V_163 )
V_48 = V_111 -> V_170 [ V_182 ] ;
else
V_48 = * V_111 -> V_170 + V_182 ;
V_2 = & V_26 -> V_30 . V_38 [ V_48 ] ;
V_2 -> V_21 = V_48 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_141 = - 1 ;
V_2 -> V_20 = ( F_107 ( V_11 , V_182 ) << 8 ) |
F_108 ( V_11 , V_182 ) ;
F_78 ( V_2 , L_55 ,
V_44 -> V_45 , V_11 -> V_19 -> V_16 ,
F_6 ( F_108 ( V_11 , V_182 ) ) ,
F_7 ( F_108 ( V_11 , V_182 ) ) , V_48 ) ;
if ( F_66 ( V_26 , V_2 ) ) {
F_20 ( V_2 ) ;
V_2 -> V_11 = NULL ;
continue;
}
F_101 ( & V_26 -> V_30 . V_178 ) ;
F_42 ( & V_2 -> V_85 , & V_26 -> V_30 . V_153 ) ;
F_103 ( & V_26 -> V_30 . V_178 ) ;
F_109 ( V_26 , V_2 ) ;
}
}
int F_110 ( struct V_60 * V_11 , T_12 V_146 )
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
if ( ! V_111 -> V_183 ) {
F_71 ( & V_11 -> V_12 , L_56
L_57 ) ;
return - V_184 ;
}
if ( V_111 -> V_163 && V_146 > V_26 -> V_30 . V_51 ) {
F_71 ( & V_11 -> V_12 , L_58 ) ;
return - V_150 ;
}
if ( V_111 -> V_163 )
V_111 -> V_170 = F_90 ( sizeof( * V_111 -> V_170 ) * V_146 ,
V_79 ) ;
else
V_111 -> V_170 = F_90 ( sizeof( * V_111 -> V_170 ) , V_79 ) ;
if ( ! V_111 -> V_170 )
return - V_168 ;
if ( V_111 -> V_163 )
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ )
V_111 -> V_170 [ V_67 ] = V_112 ;
if ( V_111 -> V_163 ) {
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ ) {
V_2 = F_19 ( V_26 ) ;
if ( ! V_2 ) {
V_119 = - V_150 ;
goto V_169;
}
V_111 -> V_170 [ V_67 ] = V_2 -> V_21 ;
}
} else {
F_101 ( & V_26 -> V_30 . V_185 ) ;
* V_111 -> V_170 = F_111 (
V_26 -> V_30 . V_47 , V_26 -> V_30 . V_46 ,
0 , V_146 , 0 ) ;
if ( * V_111 -> V_170 >= V_26 -> V_30 . V_46 ) {
F_103 ( & V_26 -> V_30 . V_185 ) ;
F_71 ( & V_11 -> V_12 , L_59 , V_146 ) ;
F_39 ( V_111 -> V_170 ) ;
return - V_150 ;
}
F_112 ( V_26 -> V_30 . V_47 , * V_111 -> V_170 , V_146 ) ;
F_103 ( & V_26 -> V_30 . V_185 ) ;
}
V_111 -> V_146 = V_146 ;
V_119 = F_88 ( V_11 , V_146 ) ;
if ( V_119 ) {
F_71 ( & V_11 -> V_12 , L_60 ) ;
goto V_169;
}
if ( ! V_111 -> V_163 ) {
V_119 = F_69 ( V_11 , * V_111 -> V_170 ) ;
if ( V_119 )
goto V_169;
}
}
F_106 ( V_11 , V_146 ) ;
return 0 ;
V_169:
if ( V_111 -> V_163 ) {
for ( V_67 = 0 ; V_67 < V_146 ; V_67 ++ ) {
if ( V_111 -> V_170 [ V_67 ] == V_112 )
continue;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_170 [ V_67 ] ] ;
F_20 ( V_2 ) ;
}
} else
F_105 ( V_26 -> V_30 . V_47 , * V_111 -> V_170 , V_146 ) ;
F_39 ( V_111 -> V_170 ) ;
return V_119 ;
}
int F_113 ( struct V_60 * V_11 )
{
F_104 ( V_11 ) ;
F_114 ( V_11 ) ;
return 0 ;
}
int F_115 ( struct V_60 * V_11 , T_12 V_146 )
{
F_116 ( V_11 ) ;
return F_110 ( V_11 , V_146 ) ;
}
static void F_117 ( struct V_25 * V_26 , struct V_60 * V_11 )
{
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
F_21 ( F_118 ( & V_11 -> V_12 ) != & V_186 ) ;
F_119 ( & V_11 -> V_12 , V_2 -> V_187 ) ;
F_120 ( & V_11 -> V_12 , V_2 -> V_173 . V_174 [ 0 ] ) ;
}
static int F_121 ( struct V_60 * V_11 , T_8 V_188 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
T_13 V_189 ;
bool V_190 = false ;
if ( F_21 ( ! V_111 || V_111 -> V_21 == V_112 ) )
return - V_191 ; ;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
if ( V_2 -> V_192 ) {
V_189 = V_2 -> V_187 + F_122 () - 1 ;
V_190 = ( V_188 >= V_189 ) ;
}
if ( V_190 ) {
F_71 ( & V_11 -> V_12 , L_61 ) ;
F_123 ( & V_11 -> V_12 , & V_193 ) ;
} else {
F_71 ( & V_11 -> V_12 , L_62 ) ;
F_123 ( & V_11 -> V_12 , & V_186 ) ;
}
* V_11 -> V_12 . V_188 = V_188 ;
F_124 ( V_11 , V_190 ) ;
return 0 ;
}
static T_8 F_125 ( struct V_60 * V_11 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
T_8 V_57 , V_194 ;
if ( F_21 ( ! V_111 || V_111 -> V_21 == V_112 ) )
return 0 ;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
if ( ! V_2 -> V_192 )
return F_126 ( & V_11 -> V_12 ) ;
V_57 = V_2 -> V_187 + F_122 () ;
V_194 = 1ULL << ( F_127 ( V_57 ) - 1 ) ;
V_194 += V_194 - 1 ;
return V_194 ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_74 * V_19 )
{
struct V_60 * V_12 ;
F_34 (dev, &bus->devices, bus_list) {
F_120 ( & V_12 -> V_12 , V_2 -> V_173 . V_174 [ 0 ] ) ;
F_119 ( & V_12 -> V_12 , V_2 -> V_187 ) ;
F_129 ( & V_12 -> V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_76 )
F_128 ( V_2 , V_12 -> V_76 ) ;
}
}
static inline T_14 T_15 * F_130 ( struct V_25 * V_26 ,
bool V_195 )
{
return V_195 ? ( T_14 T_15 * ) ( V_26 -> V_196 + 0x210 ) :
( V_26 -> V_197 + 0x210 ) ;
}
static void F_131 ( struct V_171 * V_172 ,
unsigned long V_70 , unsigned long V_198 , bool V_199 )
{
struct V_200 * V_201 = F_132 (
& V_172 -> V_202 , struct V_200 ,
V_203 ) ;
struct V_1 * V_2 = F_133 ( V_201 -> V_173 ,
struct V_1 , V_173 ) ;
T_14 T_15 * V_204 = F_130 ( V_2 -> V_26 , V_199 ) ;
unsigned long V_29 , V_57 , V_205 ;
V_29 = F_134 ( ( ( T_14 * ) V_172 -> V_206 ) + V_70 - V_172 -> V_207 ) ;
V_57 = F_134 ( ( ( T_14 * ) V_172 -> V_206 ) + V_70 - V_172 -> V_207 +
V_198 - 1 ) ;
V_29 |= ( 1ull << 63 ) ;
V_57 |= ( 1ull << 63 ) ;
V_205 = 16 ;
V_57 |= V_205 - 1 ;
F_135 () ;
while ( V_29 <= V_57 ) {
if ( V_199 )
F_136 ( F_137 ( V_29 ) , V_204 ) ;
else
F_138 ( F_137 ( V_29 ) , V_204 ) ;
V_29 += V_205 ;
}
}
static int F_139 ( struct V_171 * V_172 , long V_70 ,
long V_198 , unsigned long V_208 ,
enum V_209 V_210 ,
unsigned long V_211 )
{
int V_119 = F_140 ( V_172 , V_70 , V_198 , V_208 , V_210 ,
V_211 ) ;
if ( ! V_119 )
F_131 ( V_172 , V_70 , V_198 , false ) ;
return V_119 ;
}
static int F_141 ( struct V_171 * V_172 , long V_70 ,
unsigned long * V_212 , enum V_209 * V_210 )
{
long V_119 = F_142 ( V_172 , V_70 , V_212 , V_210 ) ;
if ( ! V_119 )
F_131 ( V_172 , V_70 , 1 , false ) ;
return V_119 ;
}
static void F_143 ( struct V_171 * V_172 , long V_70 ,
long V_198 )
{
F_144 ( V_172 , V_70 , V_198 ) ;
F_131 ( V_172 , V_70 , V_198 , false ) ;
}
void F_145 ( struct V_25 * V_26 , bool V_199 )
{
T_14 T_15 * V_204 = F_130 ( V_26 , V_199 ) ;
const unsigned long V_213 = V_214 ;
F_135 () ;
if ( V_199 )
F_136 ( F_137 ( V_213 ) , V_204 ) ;
else
F_138 ( F_137 ( V_213 ) , V_204 ) ;
}
static inline void F_146 ( struct V_1 * V_2 )
{
T_14 T_15 * V_204 = F_130 ( V_2 -> V_26 , false ) ;
unsigned long V_213 = V_215 | ( V_2 -> V_21 & 0xFF ) ;
F_135 () ;
F_138 ( F_137 ( V_213 ) , V_204 ) ;
}
static void F_147 ( struct V_1 * V_2 , bool V_199 ,
unsigned V_216 , unsigned long V_70 ,
unsigned long V_198 )
{
T_14 T_15 * V_204 = F_130 ( V_2 -> V_26 , V_199 ) ;
unsigned long V_29 , V_57 , V_205 ;
V_29 = V_217 ;
V_29 |= ( V_2 -> V_21 & 0xFF ) ;
V_57 = V_29 ;
V_29 |= ( V_70 << V_216 ) ;
V_57 |= ( ( V_70 + V_198 - 1 ) << V_216 ) ;
V_205 = ( 0x1ull << V_216 ) ;
F_135 () ;
while ( V_29 <= V_57 ) {
if ( V_199 )
F_136 ( F_137 ( V_29 ) , V_204 ) ;
else
F_138 ( F_137 ( V_29 ) , V_204 ) ;
V_29 += V_205 ;
}
}
static inline void F_148 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_26 -> V_218 == V_219 && V_26 -> V_197 )
F_146 ( V_2 ) ;
else
F_149 ( V_26 -> V_39 , V_220 ,
V_2 -> V_21 , 0 , 0 , 0 ) ;
}
static void F_150 ( struct V_171 * V_172 ,
unsigned long V_70 , unsigned long V_198 , bool V_199 )
{
struct V_200 * V_201 ;
F_151 (tgl, &tbl->it_group_list, next) {
struct V_1 * V_2 = F_133 ( V_201 -> V_173 ,
struct V_1 , V_173 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_216 = V_172 -> V_221 ;
if ( V_26 -> type == V_140 ) {
F_145 ( V_26 , V_199 ) ;
continue;
}
if ( V_26 -> V_218 == V_219 && V_26 -> V_197 )
F_147 ( V_2 , V_199 , V_216 ,
V_70 , V_198 ) ;
else if ( V_199 )
F_152 ( V_26 -> V_39 ,
V_222 ,
V_2 -> V_21 , 1u << V_216 ,
V_70 << V_216 , V_198 ) ;
else
F_149 ( V_26 -> V_39 ,
V_222 ,
V_2 -> V_21 , 1u << V_216 ,
V_70 << V_216 , V_198 ) ;
}
}
static int F_153 ( struct V_171 * V_172 , long V_70 ,
long V_198 , unsigned long V_208 ,
enum V_209 V_210 ,
unsigned long V_211 )
{
int V_119 = F_140 ( V_172 , V_70 , V_198 , V_208 , V_210 ,
V_211 ) ;
if ( ! V_119 )
F_150 ( V_172 , V_70 , V_198 , false ) ;
return V_119 ;
}
static int F_154 ( struct V_171 * V_172 , long V_70 ,
unsigned long * V_212 , enum V_209 * V_210 )
{
long V_119 = F_142 ( V_172 , V_70 , V_212 , V_210 ) ;
if ( ! V_119 )
F_150 ( V_172 , V_70 , 1 , false ) ;
return V_119 ;
}
static void F_155 ( struct V_171 * V_172 , long V_70 ,
long V_198 )
{
F_144 ( V_172 , V_70 , V_198 ) ;
F_150 ( V_172 , V_70 , V_198 , false ) ;
}
static void F_156 ( struct V_171 * V_172 )
{
F_97 ( V_172 ) ;
F_98 ( V_172 , L_63 ) ;
}
static int F_157 ( struct V_60 * V_12 , void * V_223 )
{
unsigned int * V_224 = ( unsigned int * ) V_223 ;
if ( V_12 -> V_225 != V_226 )
return 0 ;
if ( V_12 -> V_227 == V_228 ||
V_12 -> V_227 == V_229 ||
V_12 -> V_227 == V_230 )
* V_224 += 3 ;
else if ( ( V_12 -> V_227 >> 8 ) == V_231 )
* V_224 += 15 ;
else
* V_224 += 10 ;
return 0 ;
}
static unsigned int F_158 ( struct V_1 * V_2 )
{
unsigned int V_224 = 0 ;
#ifdef F_5
if ( ( V_2 -> V_9 & V_17 ) && V_2 -> V_18 ) {
F_157 ( V_2 -> V_18 , & V_224 ) ;
return V_224 ;
}
#endif
if ( ( V_2 -> V_9 & V_10 ) && V_2 -> V_11 ) {
F_157 ( V_2 -> V_11 , & V_224 ) ;
} else if ( ( V_2 -> V_9 & V_13 ) && V_2 -> V_15 ) {
struct V_60 * V_11 ;
F_34 (pdev, &pe->pbus->devices, bus_list)
F_157 ( V_11 , & V_224 ) ;
} else if ( ( V_2 -> V_9 & V_14 ) && V_2 -> V_15 ) {
F_159 ( V_2 -> V_15 , F_157 , & V_224 ) ;
}
return V_224 ;
}
static void F_160 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_232 * V_233 = NULL ;
struct V_171 * V_172 ;
unsigned int V_224 , V_234 = 0 ;
unsigned int V_235 , V_64 , V_236 , V_237 , V_67 ;
T_5 V_37 ;
void * V_238 ;
V_224 = F_158 ( V_2 ) ;
if ( ! V_224 )
return;
F_159 ( V_26 -> V_44 -> V_19 , F_157 ,
& V_234 ) ;
V_236 = ( V_224 * V_26 -> V_30 . V_239 ) / V_234 ;
if ( ! V_236 )
V_236 = 1 ;
do {
for ( V_64 = 0 ; V_64 <= V_26 -> V_30 . V_239 - V_236 ; V_64 ++ ) {
for ( V_237 = 0 , V_67 = V_64 ; V_67 < V_64 + V_236 ; V_67 ++ ) {
if ( V_26 -> V_30 . V_240 [ V_67 ] ==
V_112 )
V_237 ++ ;
}
if ( V_237 == V_236 )
goto V_241;
}
} while ( -- V_236 );
if ( ! V_236 ) {
F_60 ( V_2 , L_64 ) ;
return;
}
V_241:
V_172 = F_161 ( V_26 -> V_44 -> V_242 ) ;
F_162 ( & V_2 -> V_173 , V_26 -> V_44 -> V_45 ,
V_2 -> V_21 ) ;
F_163 ( V_26 -> V_44 -> V_242 , 0 , V_172 , & V_2 -> V_173 ) ;
F_78 ( V_2 , L_65 ,
V_224 , V_234 , V_64 , V_236 ) ;
F_78 ( V_2 , L_66 ,
V_64 * V_243 ,
( V_64 + V_236 ) * V_243 - 1 ) ;
V_235 = V_243 >> ( V_244 - 3 ) ;
V_233 = F_164 ( V_26 -> V_44 -> V_242 , V_79 ,
F_165 ( V_235 * V_236 ) ) ;
if ( ! V_233 ) {
F_65 ( V_2 , L_67 ) ;
goto V_52;
}
V_238 = F_166 ( V_233 ) ;
memset ( V_238 , 0 , V_235 * V_236 ) ;
for ( V_67 = 0 ; V_67 < V_236 ; V_67 ++ ) {
V_37 = F_167 ( V_26 -> V_39 ,
V_2 -> V_21 ,
V_64 + V_67 , 1 ,
F_134 ( V_238 ) + V_235 * V_67 ,
V_235 , V_245 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_68
L_69 , V_37 ) ;
goto V_52;
}
}
for ( V_67 = V_64 ; V_67 < V_64 + V_236 ; V_67 ++ )
V_26 -> V_30 . V_240 [ V_67 ] = V_2 -> V_21 ;
F_168 ( V_172 , V_238 , V_235 * V_236 ,
V_64 * V_243 ,
V_244 ) ;
V_172 -> V_246 = & V_247 ;
V_2 -> V_173 . V_248 = V_172 -> V_207 << V_172 -> V_221 ;
V_2 -> V_173 . V_249 = V_172 -> V_250 << V_172 -> V_221 ;
F_169 ( V_172 , V_26 -> V_44 -> V_242 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_120 ( & V_2 -> V_11 -> V_12 , V_172 ) ;
F_129 ( & V_2 -> V_11 -> V_12 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_128 ( V_2 , V_2 -> V_15 ) ;
return;
V_52:
if ( V_233 )
F_170 ( V_233 , F_165 ( V_235 * V_236 ) ) ;
if ( V_172 ) {
F_171 ( V_172 , & V_2 -> V_173 ) ;
F_98 ( V_172 , L_63 ) ;
}
}
static long F_172 ( struct V_251 * V_173 ,
int V_252 , struct V_171 * V_172 )
{
struct V_1 * V_2 = F_133 ( V_173 , struct V_1 ,
V_173 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_5 V_37 ;
const unsigned long V_78 = V_172 -> V_253 ?
V_172 -> V_254 : V_172 -> V_250 ;
const T_16 V_255 = V_172 -> V_207 << V_172 -> V_221 ;
const T_16 V_256 = V_172 -> V_250 << V_172 -> V_221 ;
F_78 ( V_2 , L_70 , V_252 ,
V_255 , V_255 + V_256 - 1 ,
F_173 ( V_172 ) ) ;
V_37 = F_167 ( V_26 -> V_39 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_252 ,
V_172 -> V_253 + 1 ,
F_134 ( V_172 -> V_206 ) ,
V_78 << 3 ,
F_173 ( V_172 ) ) ;
if ( V_37 ) {
F_65 ( V_2 , L_71 , V_37 ) ;
return V_37 ;
}
F_163 ( V_26 -> V_44 -> V_242 , V_252 ,
V_172 , & V_2 -> V_173 ) ;
F_148 ( V_2 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , bool V_257 )
{
T_17 V_258 = ( V_2 -> V_21 << 1 ) + 1 ;
T_5 V_37 ;
F_78 ( V_2 , L_72 , V_257 ? L_42 : L_43 ) ;
if ( V_257 ) {
T_18 V_189 = F_122 () ;
V_189 = F_174 ( V_189 ) ;
V_37 = F_175 ( V_2 -> V_26 -> V_39 ,
V_2 -> V_21 ,
V_258 ,
V_2 -> V_187 ,
V_189 ) ;
} else {
V_37 = F_175 ( V_2 -> V_26 -> V_39 ,
V_2 -> V_21 ,
V_258 ,
V_2 -> V_187 ,
0 ) ;
}
if ( V_37 )
F_65 ( V_2 , L_73 , V_37 ) ;
else
V_2 -> V_192 = V_257 ;
}
static long F_176 ( struct V_251 * V_173 ,
int V_252 , T_19 V_259 , T_16 V_260 , T_19 V_261 ,
struct V_171 * * V_262 )
{
struct V_1 * V_2 = F_133 ( V_173 , struct V_1 ,
V_173 ) ;
int V_263 = V_2 -> V_26 -> V_44 -> V_242 ;
T_16 V_264 = V_252 ? V_2 -> V_187 : V_173 -> V_248 ;
long V_119 ;
struct V_171 * V_172 ;
V_172 = F_161 ( V_263 ) ;
if ( ! V_172 )
return - V_168 ;
V_119 = F_177 ( V_263 ,
V_264 , V_259 , V_260 ,
V_261 , V_172 ) ;
if ( V_119 ) {
F_98 ( V_172 , L_63 ) ;
return V_119 ;
}
V_172 -> V_246 = & V_265 ;
* V_262 = V_172 ;
return 0 ;
}
static long F_178 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = NULL ;
long V_37 ;
const T_8 V_266 = F_179 ( F_180 () ) ;
const T_8 V_260 = F_181 ( ( T_8 ) V_2 -> V_173 . V_249 , V_266 ) ;
V_37 = F_176 ( & V_2 -> V_173 , 0 ,
V_244 ,
V_260 ,
V_267 , & V_172 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_74 ,
V_37 ) ;
return V_37 ;
}
F_169 ( V_172 , V_2 -> V_26 -> V_44 -> V_242 ) ;
V_37 = F_172 ( & V_2 -> V_173 , 0 , V_172 ) ;
if ( V_37 ) {
F_65 ( V_2 , L_75 ,
V_37 ) ;
F_156 ( V_172 ) ;
return V_37 ;
}
if ( ! V_24 )
F_94 ( V_2 , true ) ;
if ( V_2 -> V_9 & V_10 )
F_120 ( & V_2 -> V_11 -> V_12 , V_172 ) ;
return 0 ;
}
static long F_93 ( struct V_251 * V_173 ,
int V_252 )
{
struct V_1 * V_2 = F_133 ( V_173 , struct V_1 ,
V_173 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
long V_119 ;
F_78 ( V_2 , L_76 , V_252 ) ;
V_119 = F_167 ( V_26 -> V_39 , V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_252 ,
0 , 0 ,
0 , 0 ) ;
if ( V_119 )
F_60 ( V_2 , L_77 , V_119 ) ;
else
F_148 ( V_2 ) ;
F_171 ( V_173 -> V_174 [ V_252 ] , V_173 ) ;
return V_119 ;
}
static unsigned long F_182 ( T_19 V_259 ,
T_16 V_260 , T_19 V_261 )
{
unsigned long V_268 = 0 ;
const unsigned V_269 = F_183 ( V_260 ) ;
unsigned V_270 = V_269 - V_259 ;
unsigned V_271 = V_270 + 3 ;
unsigned long V_272 = F_184 ( 0x1000UL , 1UL << V_271 ) ;
unsigned long V_273 ;
if ( ! V_261 || ( V_261 > V_274 ) ||
( V_260 > F_180 () ) ||
! F_185 ( V_260 ) )
return 0 ;
V_270 = ( V_270 + V_261 - 1 ) / V_261 ;
V_271 = V_270 + 3 ;
V_271 = F_186 ( unsigned , V_271 , V_275 ) ;
V_273 = 1UL << V_271 ;
for ( ; V_261 ; -- V_261 ) {
V_268 += F_29 ( V_272 , V_273 ) ;
V_272 /= V_273 ;
V_272 <<= 3 ;
V_272 = F_29 ( V_272 , V_273 ) ;
}
return V_268 ;
}
static void F_187 ( struct V_251 * V_173 )
{
struct V_1 * V_2 = F_133 ( V_173 , struct V_1 ,
V_173 ) ;
struct V_171 * V_172 = V_2 -> V_173 . V_174 [ 0 ] ;
F_94 ( V_2 , false ) ;
F_93 ( & V_2 -> V_173 , 0 ) ;
F_156 ( V_172 ) ;
}
static void F_188 ( struct V_251 * V_173 )
{
struct V_1 * V_2 = F_133 ( V_173 , struct V_1 ,
V_173 ) ;
F_178 ( V_2 ) ;
}
static int F_189 ( struct V_276 * V_12 , void * V_277 )
{
struct V_62 * V_44 ;
struct V_25 * V_26 ;
struct V_1 * * V_278 = V_277 ;
struct V_60 * V_11 = F_133 ( V_12 , struct V_60 , V_12 ) ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return 0 ;
V_44 = F_27 ( V_11 -> V_19 ) ;
V_26 = V_44 -> V_63 ;
if ( V_26 -> type != V_140 )
return 0 ;
* V_278 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
return 1 ;
}
static struct V_1 * F_190 (
struct V_251 * V_173 )
{
struct V_1 * V_279 = NULL ;
int V_119 = F_191 ( V_173 -> V_175 , & V_279 ,
F_189 ) ;
F_96 ( ! V_119 || ! V_279 ) ;
return V_279 ;
}
static long F_192 ( struct V_251 * V_173 ,
int V_252 , struct V_171 * V_172 )
{
long V_119 = F_172 ( V_173 , V_252 , V_172 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_193 ( F_190 ( V_173 ) , V_252 , V_172 ) ;
if ( V_119 )
F_93 ( V_173 , V_252 ) ;
return V_119 ;
}
static long F_194 (
struct V_251 * V_173 ,
int V_252 )
{
long V_119 = F_93 ( V_173 , V_252 ) ;
if ( V_119 )
return V_119 ;
return F_195 ( F_190 ( V_173 ) , V_252 ) ;
}
static void F_196 ( struct V_251 * V_173 )
{
F_197 ( F_190 ( V_173 ) ) ;
F_187 ( V_173 ) ;
}
static void F_198 ( void )
{
struct V_62 * V_44 , * V_160 ;
struct V_25 * V_26 ;
struct V_1 * V_2 , * V_280 ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_44 -> V_63 ;
if ( V_26 -> type != V_140 )
continue;
F_34 (pe, &phb->ioda.pe_list, list) {
V_280 = F_199 ( V_2 ) ;
if ( V_280 )
V_280 -> V_173 . V_281 = & V_282 ;
}
}
}
static void F_198 ( void ) { }
static T_14 * F_200 ( int V_263 , unsigned V_216 ,
unsigned V_261 , unsigned long V_283 ,
unsigned long * V_284 , unsigned long * V_285 )
{
struct V_232 * V_233 = NULL ;
T_14 * V_238 , * V_160 ;
unsigned V_286 = F_186 ( unsigned , V_216 , V_275 ) - V_275 ;
unsigned long V_287 = 1UL << ( V_286 + V_275 ) ;
unsigned V_288 = 1UL << ( V_216 - 3 ) ;
long V_67 ;
V_233 = F_164 ( V_263 , V_79 , V_286 ) ;
if ( ! V_233 ) {
F_74 ( L_78 , V_286 ) ;
return NULL ;
}
V_238 = F_166 ( V_233 ) ;
memset ( V_238 , 0 , V_287 ) ;
* V_285 += V_287 ;
-- V_261 ;
if ( ! V_261 ) {
* V_284 += V_287 ;
return V_238 ;
}
for ( V_67 = 0 ; V_67 < V_288 ; ++ V_67 ) {
V_160 = F_200 ( V_263 , V_216 ,
V_261 , V_283 , V_284 , V_285 ) ;
if ( ! V_160 )
break;
V_238 [ V_67 ] = F_137 ( F_134 ( V_160 ) |
V_289 | V_290 ) ;
if ( * V_284 >= V_283 )
break;
}
return V_238 ;
}
static long F_177 ( int V_263 , T_16 V_264 ,
T_19 V_259 , T_16 V_260 , T_19 V_261 ,
struct V_171 * V_172 )
{
void * V_238 ;
unsigned long V_144 = 0 , V_291 , V_285 = 0 ;
const unsigned V_269 = F_183 ( V_260 ) ;
unsigned V_270 = V_269 - V_259 ;
unsigned V_271 = F_186 ( unsigned , V_270 + 3 , V_275 ) ;
const unsigned long V_272 = 1UL << V_271 ;
if ( ! V_261 || ( V_261 > V_274 ) )
return - V_23 ;
if ( ( V_260 > F_180 () ) || ! F_185 ( V_260 ) )
return - V_23 ;
V_270 = ( V_270 + V_261 - 1 ) / V_261 ;
V_291 = V_270 + 3 ;
V_291 = F_186 ( unsigned , V_291 , V_275 ) ;
V_238 = F_200 ( V_263 , V_291 ,
V_261 , V_272 , & V_144 , & V_285 ) ;
if ( ! V_238 )
return - V_168 ;
if ( V_144 < V_272 ) {
F_201 ( V_238 ,
1ULL << ( V_291 - 3 ) , V_261 - 1 ) ;
return - V_168 ;
}
F_168 ( V_172 , V_238 , V_272 , V_264 ,
V_259 ) ;
V_172 -> V_254 = 1ULL << ( V_291 - 3 ) ;
V_172 -> V_253 = V_261 - 1 ;
V_172 -> V_292 = V_285 ;
F_202 ( L_79 ,
V_260 , V_272 , V_264 ) ;
return 0 ;
}
static void F_201 ( T_14 * V_238 ,
unsigned long V_78 , unsigned V_3 )
{
const unsigned long V_293 = ( unsigned long ) V_238 &
~ ( V_289 | V_290 ) ;
if ( V_3 ) {
long V_67 ;
T_8 * V_160 = ( T_8 * ) V_293 ;
for ( V_67 = 0 ; V_67 < V_78 ; ++ V_67 ) {
unsigned long V_212 = F_203 ( V_160 [ V_67 ] ) ;
if ( ! ( V_212 & ( V_289 | V_290 ) ) )
continue;
F_201 ( F_204 ( V_212 ) , V_78 ,
V_3 - 1 ) ;
}
}
F_205 ( V_293 , F_165 ( V_78 << 3 ) ) ;
}
static void F_97 ( struct V_171 * V_172 )
{
const unsigned long V_78 = V_172 -> V_253 ?
V_172 -> V_254 : V_172 -> V_250 ;
if ( ! V_172 -> V_250 )
return;
F_201 ( ( T_14 * ) V_172 -> V_206 , V_78 ,
V_172 -> V_253 ) ;
}
static void F_109 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
T_5 V_37 ;
if ( ! F_158 ( V_2 ) )
return;
V_2 -> V_187 = 1ull << 59 ;
F_162 ( & V_2 -> V_173 , V_26 -> V_44 -> V_45 ,
V_2 -> V_21 ) ;
F_78 ( V_2 , L_80 ,
V_26 -> V_30 . V_294 ) ;
V_2 -> V_173 . V_248 = 0 ;
V_2 -> V_173 . V_249 = V_26 -> V_30 . V_294 ;
V_2 -> V_173 . V_295 =
V_296 ;
V_2 -> V_173 . V_297 = V_274 ;
V_2 -> V_173 . V_298 = V_299 | V_300 | V_301 ;
#ifdef F_206
V_2 -> V_173 . V_281 = & V_302 ;
#endif
V_37 = F_178 ( V_2 ) ;
if ( V_37 )
return;
if ( V_2 -> V_9 & V_10 )
F_129 ( & V_2 -> V_11 -> V_12 ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_128 ( V_2 , V_2 -> V_15 ) ;
}
T_5 F_207 ( struct V_303 * V_304 , unsigned int V_305 )
{
struct V_25 * V_26 = F_133 ( V_304 , struct V_25 ,
V_30 . V_303 ) ;
return F_208 ( V_26 -> V_39 , V_305 ) ;
}
static void F_209 ( struct V_306 * V_307 )
{
T_5 V_37 ;
unsigned int V_305 = ( unsigned int ) F_210 ( V_307 ) ;
struct V_303 * V_304 = F_211 ( V_307 ) ;
V_37 = F_207 ( V_304 , V_305 ) ;
F_212 ( V_37 ) ;
F_213 ( V_307 ) ;
}
void F_214 ( struct V_25 * V_26 , unsigned int V_308 )
{
struct V_306 * V_309 ;
struct V_303 * V_310 ;
if ( V_26 -> V_218 != V_219 )
return;
if ( ! V_26 -> V_30 . V_311 ) {
V_309 = F_215 ( V_308 ) ;
V_310 = F_211 ( V_309 ) ;
V_26 -> V_30 . V_311 = 1 ;
V_26 -> V_30 . V_303 = * V_310 ;
V_26 -> V_30 . V_303 . V_312 = F_209 ;
}
F_216 ( V_308 , & V_26 -> V_30 . V_303 ) ;
}
bool F_217 ( struct V_303 * V_304 )
{
return V_304 -> V_312 == F_209 ;
}
static int F_218 ( struct V_25 * V_26 , struct V_60 * V_12 ,
unsigned int V_313 , unsigned int V_308 ,
unsigned int V_314 , struct V_315 * V_316 )
{
struct V_1 * V_2 = F_56 ( V_12 ) ;
unsigned int V_317 = V_313 - V_26 -> V_318 ;
T_7 V_223 ;
int V_37 ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_141 < 0 )
return - V_118 ;
if ( V_12 -> V_319 )
V_314 = 0 ;
V_37 = F_219 ( V_26 -> V_39 , V_2 -> V_21 , V_317 ) ;
if ( V_37 ) {
F_15 ( L_81 ,
F_75 ( V_12 ) , V_37 , V_317 ) ;
return - V_59 ;
}
if ( V_314 ) {
T_14 V_320 ;
V_37 = F_220 ( V_26 -> V_39 , V_2 -> V_141 , V_317 , 1 ,
& V_320 , & V_223 ) ;
if ( V_37 ) {
F_15 ( L_82 ,
F_75 ( V_12 ) , V_37 ) ;
return - V_59 ;
}
V_316 -> V_321 = F_203 ( V_320 ) >> 32 ;
V_316 -> V_322 = F_203 ( V_320 ) & 0xfffffffful ;
} else {
T_7 V_323 ;
V_37 = F_221 ( V_26 -> V_39 , V_2 -> V_141 , V_317 , 1 ,
& V_323 , & V_223 ) ;
if ( V_37 ) {
F_15 ( L_83 ,
F_75 ( V_12 ) , V_37 ) ;
return - V_59 ;
}
V_316 -> V_321 = 0 ;
V_316 -> V_322 = F_222 ( V_323 ) ;
}
V_316 -> V_223 = F_222 ( V_223 ) ;
F_214 ( V_26 , V_308 ) ;
F_202 ( L_84
L_85 ,
F_75 ( V_12 ) , V_314 ? L_86 : L_87 , V_313 , V_317 ,
V_316 -> V_321 , V_316 -> V_322 , V_223 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_223 ( struct V_25 * V_26 )
{
unsigned int V_125 ;
const T_7 * V_324 = F_46 ( V_26 -> V_44 -> V_88 ,
L_88 , NULL ) ;
if ( ! V_324 ) {
V_324 = F_46 ( V_26 -> V_44 -> V_88 , L_89 , NULL ) ;
}
if ( ! V_324 )
return;
V_26 -> V_318 = F_224 ( V_324 ) ;
V_125 = F_224 ( V_324 + 1 ) ;
if ( F_225 ( & V_26 -> V_325 , V_125 , V_26 -> V_44 -> V_88 ) ) {
F_74 ( L_90 ,
V_26 -> V_44 -> V_45 ) ;
return;
}
V_26 -> V_326 = F_218 ;
V_26 -> V_327 = 1 ;
F_10 ( L_91 ,
V_125 , V_26 -> V_318 ) ;
}
static void F_223 ( struct V_25 * V_26 ) { }
static void F_226 ( struct V_60 * V_11 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
const T_4 V_328 = V_26 -> V_30 . V_56 >> 2 ;
struct V_27 * V_89 ;
int V_67 ;
T_4 V_78 , V_329 ;
struct V_110 * V_111 ;
int V_330 , V_167 ;
if ( ! V_11 -> V_147 || V_11 -> V_331 )
return;
V_111 = F_57 ( V_11 ) ;
V_111 -> V_183 = 0 ;
V_111 -> V_163 = false ;
V_167 = F_89 ( V_11 ) ;
V_330 = V_26 -> V_30 . V_46 ;
V_329 = 0 ;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || V_89 -> V_69 )
continue;
if ( ! F_12 ( V_89 -> V_9 ) ) {
F_227 ( & V_11 -> V_12 , L_92
L_93 ,
V_67 , V_89 ) ;
goto V_332;
}
V_329 += F_70 ( V_11 ,
V_67 + V_149 ) ;
if ( V_329 > V_328 ) {
V_330 = F_174 ( V_167 ) ;
F_71 ( & V_11 -> V_12 ,
L_94 ,
V_329 , V_328 , V_330 ) ;
V_111 -> V_163 = true ;
break;
}
}
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
if ( ! V_89 -> V_9 || V_89 -> V_69 )
continue;
V_78 = F_70 ( V_11 , V_67 + V_149 ) ;
if ( V_111 -> V_163 && ( V_78 < V_333 ) )
goto V_332;
F_228 ( & V_11 -> V_12 , L_95 , V_67 , V_89 ) ;
V_89 -> V_57 = V_89 -> V_29 + V_78 * V_330 - 1 ;
F_228 ( & V_11 -> V_12 , L_96 , V_89 ) ;
F_71 ( & V_11 -> V_12 , L_97 ,
V_67 , V_89 , V_330 ) ;
}
V_111 -> V_183 = V_330 ;
return;
V_332:
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ ) {
V_89 = & V_11 -> V_27 [ V_67 + V_149 ] ;
V_89 -> V_9 = 0 ;
V_89 -> V_57 = V_89 -> V_29 - 1 ;
}
}
static void F_229 ( struct V_1 * V_2 ,
struct V_27 * V_89 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_334 V_335 ;
int V_70 ;
T_5 V_37 ;
if ( ! V_89 || ! V_89 -> V_9 || V_89 -> V_29 > V_89 -> V_57 )
return;
if ( V_89 -> V_9 & V_336 ) {
V_335 . V_29 = V_89 -> V_29 - V_26 -> V_30 . V_337 ;
V_335 . V_57 = V_89 -> V_57 - V_26 -> V_30 . V_337 ;
V_70 = V_335 . V_29 / V_26 -> V_30 . V_338 ;
while ( V_70 < V_26 -> V_30 . V_46 &&
V_335 . V_29 <= V_335 . V_57 ) {
V_26 -> V_30 . V_339 [ V_70 ] = V_2 -> V_21 ;
V_37 = F_43 ( V_26 -> V_39 ,
V_2 -> V_21 , V_340 , 0 , V_70 ) ;
if ( V_37 != V_41 ) {
F_74 ( L_98 ,
V_43 , V_37 , V_70 , V_2 -> V_21 ) ;
break;
}
V_335 . V_29 += V_26 -> V_30 . V_338 ;
V_70 ++ ;
}
} else if ( ( V_89 -> V_9 & V_96 ) &&
! F_11 ( V_26 , V_89 ) ) {
V_335 . V_29 = V_89 -> V_29 -
V_26 -> V_44 -> V_97 [ 0 ] -
V_26 -> V_30 . V_294 ;
V_335 . V_57 = V_89 -> V_57 -
V_26 -> V_44 -> V_97 [ 0 ] -
V_26 -> V_30 . V_294 ;
V_70 = V_335 . V_29 / V_26 -> V_30 . V_341 ;
while ( V_70 < V_26 -> V_30 . V_46 &&
V_335 . V_29 <= V_335 . V_57 ) {
V_26 -> V_30 . V_342 [ V_70 ] = V_2 -> V_21 ;
V_37 = F_43 ( V_26 -> V_39 ,
V_2 -> V_21 , V_343 , 0 , V_70 ) ;
if ( V_37 != V_41 ) {
F_74 ( L_99 ,
V_43 , V_37 , V_70 , V_2 -> V_21 ) ;
break;
}
V_335 . V_29 += V_26 -> V_30 . V_341 ;
V_70 ++ ;
}
}
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_60 * V_11 ;
int V_67 ;
F_96 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_34 (pdev, &pe->pbus->devices, bus_list) {
for ( V_67 = 0 ; V_67 <= V_68 ; V_67 ++ )
F_229 ( V_2 , & V_11 -> V_27 [ V_67 ] ) ;
if ( ! ( V_2 -> V_9 & V_14 ) || ! F_231 ( V_11 ) )
continue;
for ( V_67 = 0 ; V_67 < V_344 ; V_67 ++ )
F_229 ( V_2 ,
& V_11 -> V_27 [ V_345 + V_67 ] ) ;
}
}
static int F_232 ( void * V_223 , T_8 V_213 )
{
struct V_62 * V_44 ;
struct V_25 * V_26 ;
T_3 V_119 ;
if ( V_213 != 1ULL )
return - V_23 ;
V_44 = (struct V_62 * ) V_223 ;
if ( ! V_44 || ! V_44 -> V_63 )
return - V_191 ;
V_26 = V_44 -> V_63 ;
V_119 = F_233 ( V_26 -> V_39 , V_26 -> V_346 . V_347 ,
V_348 ) ;
if ( V_119 != V_41 )
return - V_59 ;
F_234 ( V_26 -> V_44 , V_26 -> V_346 . V_347 ) ;
return 0 ;
}
static void F_235 ( void )
{
#ifdef F_236
struct V_62 * V_44 , * V_160 ;
struct V_25 * V_26 ;
char V_95 [ 16 ] ;
F_86 (hose, tmp, &hose_list, list_node) {
V_26 = V_44 -> V_63 ;
V_26 -> V_349 = 1 ;
sprintf ( V_95 , L_100 , V_44 -> V_45 ) ;
V_26 -> V_350 = F_237 ( V_95 , V_351 ) ;
if ( ! V_26 -> V_350 ) {
F_76 ( L_101 ,
V_43 , V_44 -> V_45 ) ;
continue;
}
F_238 ( L_102 , 0200 , V_26 -> V_350 , V_44 ,
& V_352 ) ;
}
#endif
}
static void F_239 ( void )
{
F_85 () ;
F_198 () ;
F_235 () ;
#ifdef F_240
F_241 () ;
F_242 () ;
#endif
}
static T_4 F_243 ( struct V_74 * V_19 ,
unsigned long type )
{
struct V_60 * V_353 ;
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
int V_354 = 0 ;
V_353 = V_19 -> V_120 ;
while ( V_353 ) {
if ( F_244 ( V_353 ) == V_355 ) {
V_354 ++ ;
if ( V_354 >= 2 )
return 1 ;
}
V_353 = V_353 -> V_19 -> V_120 ;
}
if ( V_26 -> V_30 . V_56 && F_12 ( type ) )
return V_26 -> V_30 . V_56 ;
if ( type & V_96 )
return V_26 -> V_30 . V_341 ;
return V_26 -> V_30 . V_338 ;
}
static void F_245 ( struct V_74 * V_19 ,
unsigned long type )
{
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_60 * V_353 = V_19 -> V_120 ;
struct V_27 * V_28 , * V_356 ;
bool V_357 = false ;
int V_67 ;
if ( ! F_36 ( V_353 -> V_19 ) &&
! F_36 ( V_353 -> V_19 -> V_120 -> V_19 ) )
return;
for ( V_67 = 0 ; V_67 < V_344 ; V_67 ++ ) {
V_28 = & V_353 -> V_27 [ V_345 + V_67 ] ;
if ( ! V_28 -> V_9 || ! V_28 -> V_69 )
continue;
V_356 = NULL ;
if ( V_28 -> V_9 & type & V_336 )
V_356 = & V_44 -> V_358 ;
else if ( F_11 ( V_26 , V_28 ) &&
( type & V_35 ) &&
V_26 -> V_30 . V_56 )
V_356 = & V_44 -> V_54 [ 1 ] ;
else if ( V_28 -> V_9 & type & V_96 ) {
V_356 = & V_44 -> V_54 [ 0 ] ;
V_357 = true ;
}
V_28 -> V_29 = V_356 -> V_29 ;
V_28 -> V_57 = V_356 -> V_57 ;
if ( V_357 ) {
V_28 -> V_57 += 0x10000 ;
V_28 -> V_57 -= 0x100000 ;
}
}
}
static void F_246 ( struct V_74 * V_19 , unsigned long type )
{
struct V_62 * V_44 = F_27 ( V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_60 * V_353 = V_19 -> V_120 ;
struct V_1 * V_2 ;
bool V_75 = ( F_244 ( V_353 ) == V_355 ) ;
F_245 ( V_19 , type ) ;
if ( ! V_26 -> V_30 . V_359 ) {
V_2 = F_81 ( V_26 -> V_44 -> V_19 , false ) ;
if ( V_2 ) {
V_26 -> V_30 . V_155 = V_2 -> V_21 ;
V_26 -> V_30 . V_359 = true ;
}
}
if ( F_247 ( & V_19 -> V_360 ) )
return;
if ( V_26 -> V_100 )
V_26 -> V_100 ( V_19 , NULL , V_75 ) ;
V_2 = F_81 ( V_19 , V_75 ) ;
if ( ! V_2 )
return;
F_230 ( V_2 ) ;
switch ( V_26 -> type ) {
case V_86 :
F_160 ( V_26 , V_2 ) ;
break;
case V_92 :
F_109 ( V_26 , V_2 ) ;
break;
default:
F_15 ( L_103 ,
V_43 , V_26 -> V_44 -> V_45 , V_26 -> type ) ;
}
}
static T_4 F_248 ( struct V_60 * V_11 ,
int V_361 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
T_4 V_362 ;
V_362 = F_70 ( V_11 , V_361 ) ;
if ( ! V_111 -> V_183 )
return V_362 ;
if ( V_111 -> V_163 )
return F_184 ( V_362 , ( T_4 ) V_26 -> V_30 . V_56 ) ;
return V_111 -> V_183 * V_362 ;
}
bool F_249 ( struct V_60 * V_12 )
{
struct V_62 * V_44 = F_27 ( V_12 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 ;
if ( ! V_26 -> V_349 )
return true ;
V_111 = F_57 ( V_12 ) ;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return false ;
return true ;
}
static long F_250 ( struct V_251 * V_173 ,
int V_252 )
{
struct V_1 * V_2 = F_133 ( V_173 ,
struct V_1 , V_173 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_363 ;
long V_37 ;
F_78 ( V_2 , L_76 , V_252 ) ;
for ( V_363 = 0 ; V_363 < V_26 -> V_30 . V_239 ; V_363 ++ ) {
if ( V_26 -> V_30 . V_240 [ V_363 ] != V_2 -> V_21 )
continue;
V_37 = F_167 ( V_26 -> V_39 , V_2 -> V_21 ,
V_363 , 0 , 0ul , 0ul , 0ul ) ;
if ( V_37 != V_41 ) {
F_60 ( V_2 , L_104 ,
V_37 , V_363 ) ;
return V_37 ;
}
V_26 -> V_30 . V_240 [ V_363 ] = V_112 ;
}
F_171 ( V_173 -> V_174 [ V_252 ] , V_173 ) ;
return V_41 ;
}
static void F_251 ( struct V_1 * V_2 )
{
unsigned int V_224 = F_158 ( V_2 ) ;
struct V_171 * V_172 = V_2 -> V_173 . V_174 [ 0 ] ;
T_5 V_37 ;
if ( ! V_224 )
return;
V_37 = F_250 ( & V_2 -> V_173 , 0 ) ;
if ( V_37 != V_41 )
return;
F_131 ( V_172 , V_172 -> V_207 , V_172 -> V_250 , false ) ;
if ( V_2 -> V_173 . V_175 ) {
F_95 ( V_2 -> V_173 . V_175 ) ;
F_21 ( V_2 -> V_173 . V_175 ) ;
}
F_205 ( V_172 -> V_206 , F_165 ( V_172 -> V_250 << 3 ) ) ;
F_98 ( V_172 , L_63 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = V_2 -> V_173 . V_174 [ 0 ] ;
unsigned int V_224 = F_158 ( V_2 ) ;
#ifdef F_206
T_5 V_37 ;
#endif
if ( ! V_224 )
return;
#ifdef F_206
V_37 = F_93 ( & V_2 -> V_173 , 0 ) ;
if ( V_37 )
F_60 ( V_2 , L_54 , V_37 ) ;
#endif
F_94 ( V_2 , false ) ;
if ( V_2 -> V_173 . V_175 ) {
F_95 ( V_2 -> V_173 . V_175 ) ;
F_21 ( V_2 -> V_173 . V_175 ) ;
}
F_97 ( V_172 ) ;
F_98 ( V_172 , L_63 ) ;
}
static void F_253 ( struct V_1 * V_2 ,
unsigned short V_166 ,
unsigned int * V_364 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_363 ;
T_5 V_37 ;
for ( V_363 = 0 ; V_363 < V_26 -> V_30 . V_46 ; V_363 ++ ) {
if ( V_364 [ V_363 ] != V_2 -> V_21 )
continue;
if ( V_166 == V_50 )
V_37 = F_43 ( V_26 -> V_39 ,
V_26 -> V_30 . V_55 , V_166 ,
V_363 / V_73 ,
V_363 % V_73 ) ;
else
V_37 = F_43 ( V_26 -> V_39 ,
V_26 -> V_30 . V_55 , V_166 , 0 , V_363 ) ;
if ( V_37 != V_41 )
F_60 ( V_2 , L_105 ,
V_37 , V_166 , V_363 ) ;
V_364 [ V_363 ] = V_112 ;
}
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_26 -> type == V_86 ) {
F_253 ( V_2 , V_340 ,
V_26 -> V_30 . V_339 ) ;
F_253 ( V_2 , V_343 ,
V_26 -> V_30 . V_342 ) ;
F_253 ( V_2 , V_50 ,
V_26 -> V_30 . V_80 ) ;
} else if ( V_26 -> type == V_92 ) {
F_253 ( V_2 , V_343 ,
V_26 -> V_30 . V_342 ) ;
}
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_1 * V_102 , * V_160 ;
F_102 ( & V_2 -> V_85 ) ;
switch ( V_26 -> type ) {
case V_86 :
F_251 ( V_2 ) ;
break;
case V_92 :
F_252 ( V_2 ) ;
break;
default:
F_21 ( 1 ) ;
}
F_254 ( V_2 ) ;
F_62 ( V_2 -> V_26 , V_2 ) ;
if ( V_2 -> V_9 & V_81 ) {
F_86 (slave, tmp, &pe->slaves, list) {
F_102 ( & V_102 -> V_85 ) ;
F_20 ( V_102 ) ;
}
}
if ( V_26 -> V_30 . V_359 &&
V_26 -> V_30 . V_155 == V_2 -> V_21 )
V_26 -> V_30 . V_359 = false ;
else
F_20 ( V_2 ) ;
}
static void F_256 ( struct V_60 * V_11 )
{
struct V_62 * V_44 = F_27 ( V_11 -> V_19 ) ;
struct V_25 * V_26 = V_44 -> V_63 ;
struct V_110 * V_111 = F_57 ( V_11 ) ;
struct V_1 * V_2 ;
if ( V_11 -> V_365 )
return;
if ( ! V_111 || V_111 -> V_21 == V_112 )
return;
V_2 = & V_26 -> V_30 . V_38 [ V_111 -> V_21 ] ;
V_111 -> V_21 = V_112 ;
F_21 ( -- V_2 -> V_154 < 0 ) ;
if ( V_2 -> V_154 == 0 )
F_255 ( V_2 ) ;
}
static void F_257 ( struct V_62 * V_44 )
{
struct V_25 * V_26 = V_44 -> V_63 ;
F_258 ( V_26 -> V_39 , V_366 ,
V_367 ) ;
}
static int F_259 ( struct V_60 * V_368 , T_8 V_188 )
{
F_260 ( & V_368 -> V_12 ,
L_106 ,
V_43 ) ;
return - V_369 ;
}
static void T_2 F_261 ( struct V_87 * V_370 ,
T_8 V_371 , int V_372 )
{
struct V_62 * V_44 ;
struct V_25 * V_26 ;
unsigned long V_78 , V_373 , V_374 , V_375 ;
unsigned long V_376 = 0 , V_377 = 0 ;
struct V_27 V_28 ;
const T_14 * V_378 ;
const T_7 * V_379 ;
int V_380 ;
unsigned int V_66 ;
T_8 V_381 ;
void * V_382 ;
long V_37 ;
if ( ! F_262 ( V_370 ) )
return;
F_10 ( L_107 ,
V_383 [ V_372 ] , F_99 ( V_370 ) ) ;
V_378 = F_46 ( V_370 , L_108 , NULL ) ;
if ( ! V_378 ) {
F_74 ( L_109 ) ;
return;
}
V_381 = F_263 ( V_378 ) ;
F_18 ( L_110 , V_381 ) ;
V_26 = F_264 ( sizeof( struct V_25 ) , 0 ) ;
V_26 -> V_44 = V_44 = F_265 ( V_370 ) ;
if ( ! V_26 -> V_44 ) {
F_74 ( L_111 ,
V_370 -> V_94 ) ;
F_266 ( F_134 ( V_26 ) , sizeof( struct V_25 ) ) ;
return;
}
F_267 ( & V_26 -> V_384 ) ;
V_379 = F_46 ( V_370 , L_112 , & V_380 ) ;
if ( V_379 && V_380 == 8 ) {
V_44 -> V_385 = F_222 ( V_379 [ 0 ] ) ;
V_44 -> V_386 = F_222 ( V_379 [ 1 ] ) ;
} else {
F_15 ( L_113 , V_370 -> V_94 ) ;
V_44 -> V_385 = 0 ;
V_44 -> V_386 = 0xff ;
}
V_44 -> V_63 = V_26 ;
V_26 -> V_371 = V_371 ;
V_26 -> V_39 = V_381 ;
V_26 -> type = V_372 ;
F_268 ( & V_26 -> V_30 . V_185 ) ;
if ( F_269 ( V_370 , L_114 ) )
V_26 -> V_218 = V_387 ;
else if ( F_269 ( V_370 , L_115 ) )
V_26 -> V_218 = V_219 ;
else if ( F_269 ( V_370 , L_116 ) )
V_26 -> V_218 = V_388 ;
else
V_26 -> V_218 = V_389 ;
F_270 ( V_44 , V_370 , ! V_44 -> V_45 ) ;
if ( ! F_271 ( V_370 , 0 , & V_28 ) ) {
V_26 -> V_196 = V_28 . V_29 ;
V_26 -> V_197 = F_272 ( V_28 . V_29 , F_50 ( & V_28 ) ) ;
if ( V_26 -> V_197 == NULL )
F_74 ( L_117 ) ;
}
V_26 -> V_30 . V_46 = 1 ;
V_379 = F_46 ( V_370 , L_118 , NULL ) ;
if ( V_379 )
V_26 -> V_30 . V_46 = F_224 ( V_379 ) ;
V_379 = F_46 ( V_370 , L_119 , NULL ) ;
if ( V_379 )
V_26 -> V_30 . V_55 = F_224 ( V_379 ) ;
for ( V_66 = 0 ; V_66 < F_273 ( V_26 -> V_30 . V_137 ) ; V_66 ++ )
V_26 -> V_30 . V_137 [ V_66 ] = V_112 ;
F_44 ( V_26 ) ;
V_26 -> V_30 . V_390 = F_50 ( & V_44 -> V_54 [ 0 ] ) ;
V_26 -> V_30 . V_390 += 0x10000 ;
V_26 -> V_30 . V_341 = V_26 -> V_30 . V_390 / V_26 -> V_30 . V_46 ;
V_26 -> V_30 . V_294 = V_44 -> V_54 [ 0 ] . V_29 - V_44 -> V_97 [ 0 ] ;
V_26 -> V_30 . V_391 = V_44 -> V_392 ;
V_26 -> V_30 . V_338 = V_26 -> V_30 . V_391 / V_26 -> V_30 . V_46 ;
V_26 -> V_30 . V_337 = 0 ;
V_26 -> V_30 . V_239 = V_26 -> V_30 . V_294 /
V_243 ;
V_78 = F_29 ( F_186 ( unsigned , V_26 -> V_30 . V_46 , 8 ) / 8 ,
sizeof( unsigned long ) ) ;
V_373 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( V_26 -> V_30 . V_80 [ 0 ] ) ;
V_374 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( V_26 -> V_30 . V_342 [ 0 ] ) ;
if ( V_26 -> type == V_86 ) {
V_376 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( V_26 -> V_30 . V_339 [ 0 ] ) ;
V_377 = V_78 ;
V_78 += V_26 -> V_30 . V_239 *
sizeof( V_26 -> V_30 . V_240 [ 0 ] ) ;
}
V_375 = V_78 ;
V_78 += V_26 -> V_30 . V_46 * sizeof( struct V_1 ) ;
V_382 = F_264 ( V_78 , 0 ) ;
V_26 -> V_30 . V_47 = V_382 ;
V_26 -> V_30 . V_80 = V_382 + V_373 ;
V_26 -> V_30 . V_342 = V_382 + V_374 ;
for ( V_66 = 0 ; V_66 < V_26 -> V_30 . V_46 ; V_66 ++ ) {
V_26 -> V_30 . V_80 [ V_66 ] = V_112 ;
V_26 -> V_30 . V_342 [ V_66 ] = V_112 ;
}
if ( V_26 -> type == V_86 ) {
V_26 -> V_30 . V_339 = V_382 + V_376 ;
for ( V_66 = 0 ; V_66 < V_26 -> V_30 . V_46 ; V_66 ++ )
V_26 -> V_30 . V_339 [ V_66 ] = V_112 ;
V_26 -> V_30 . V_240 = V_382 + V_377 ;
for ( V_66 = 0 ; V_66 < V_26 -> V_30 . V_239 ; V_66 ++ )
V_26 -> V_30 . V_240 [ V_66 ] = V_112 ;
}
V_26 -> V_30 . V_38 = V_382 + V_375 ;
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
F_268 ( & V_26 -> V_30 . V_178 ) ;
V_26 -> V_30 . V_239 = V_26 -> V_30 . V_294 /
V_243 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_10 ( L_120 ,
V_26 -> V_30 . V_46 , V_26 -> V_30 . V_55 ,
V_26 -> V_30 . V_390 , V_26 -> V_30 . V_341 ) ;
if ( V_26 -> V_30 . V_32 )
F_10 ( L_121 ,
V_26 -> V_30 . V_32 , V_26 -> V_30 . V_56 ) ;
if ( V_26 -> V_30 . V_391 )
F_10 ( L_122 ,
V_26 -> V_30 . V_391 , V_26 -> V_30 . V_338 ) ;
V_26 -> V_44 -> V_281 = & V_393 ;
V_26 -> V_394 = F_54 ;
V_26 -> V_395 = F_51 ;
V_26 -> V_396 = F_53 ;
F_223 ( V_26 ) ;
V_397 . V_398 = F_239 ;
if ( V_26 -> type == V_140 ) {
V_44 -> V_399 = V_400 ;
} else {
V_26 -> V_401 = F_117 ;
V_44 -> V_399 = V_402 ;
}
#ifdef F_5
V_397 . V_403 = F_226 ;
V_397 . V_404 = F_248 ;
#endif
F_274 ( V_405 ) ;
V_37 = F_258 ( V_381 , V_366 , V_367 ) ;
if ( V_37 )
F_76 ( L_123 , V_37 ) ;
if ( F_275 () ) {
F_10 ( L_124 ) ;
F_276 ( V_44 , V_406 ) ;
F_276 ( V_44 , V_407 ) ;
}
if ( ! V_26 -> V_99 || V_26 -> V_99 ( V_26 ) )
V_44 -> V_54 [ 1 ] . V_9 = 0 ;
}
void T_2 F_277 ( struct V_87 * V_370 )
{
F_261 ( V_370 , 0 , V_92 ) ;
}
void T_2 F_278 ( struct V_87 * V_370 )
{
F_261 ( V_370 , 0 , V_140 ) ;
}
void T_2 F_279 ( struct V_87 * V_370 )
{
struct V_87 * V_408 ;
const T_14 * V_378 ;
T_8 V_371 ;
F_10 ( L_125 , V_370 -> V_94 ) ;
V_378 = F_46 ( V_370 , L_126 , NULL ) ;
if ( ! V_378 ) {
F_74 ( L_127 ) ;
return;
}
V_371 = F_263 ( V_378 ) ;
F_202 ( L_128 , V_371 ) ;
F_280 (np, phbn) {
if ( F_269 ( V_408 , L_129 ) )
F_261 ( V_408 , V_371 , V_86 ) ;
}
}
