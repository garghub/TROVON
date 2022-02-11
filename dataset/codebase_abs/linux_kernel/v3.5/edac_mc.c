static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 ) ;
F_2 ( L_2 , V_2 -> V_3 ) ;
F_2 ( L_3 , V_2 -> V_4 ) ;
F_2 ( L_4 , V_2 -> V_5 ) ;
}
static void F_3 ( struct V_6 * V_5 )
{
int V_7 ;
F_2 ( L_5 , V_5 ) ;
F_2 ( L_6 , V_5 -> V_8 ) ;
F_2 ( L_7 , V_5 -> V_9 ) ;
F_2 ( L_8 ) ;
for ( V_7 = 0 ; V_7 < V_5 -> V_10 -> V_11 ; V_7 ++ ) {
F_4 ( V_12 L_9 , V_5 -> V_13 [ V_7 ] ) ;
if ( V_7 < V_5 -> V_10 -> V_11 - 1 )
F_4 ( V_12 L_10 ) ;
}
F_4 ( V_12 L_11 ) ;
F_2 ( L_12 , V_5 -> V_14 ) ;
F_2 ( L_7 , V_5 -> V_9 ) ;
}
static void F_5 ( struct V_15 * V_4 )
{
F_2 ( L_13 , V_4 ) ;
F_2 ( L_14 , V_4 -> V_16 ) ;
F_2 ( L_15 , V_4 -> V_17 ) ;
F_2 ( L_16 , V_4 -> V_18 ) ;
F_2 ( L_17 , V_4 -> V_19 ) ;
F_2 ( L_18 , V_4 -> V_20 ) ;
F_2 ( L_19 , V_4 -> V_21 ) ;
F_2 ( L_20 , V_4 -> V_10 ) ;
}
static void F_6 ( struct V_22 * V_10 )
{
F_7 ( L_21 , V_10 ) ;
F_7 ( L_22 , V_10 -> V_23 ) ;
F_7 ( L_23 , V_10 -> V_24 ) ;
F_7 ( L_24 , V_10 -> V_25 ) ;
F_2 ( L_25 , V_10 -> V_26 ) ;
F_7 ( L_26 ,
V_10 -> V_27 , V_10 -> V_28 ) ;
F_7 ( L_27 ,
V_10 -> V_29 , V_10 -> V_30 ) ;
F_7 ( L_28 , V_10 -> V_31 ) ;
F_7 ( L_29 , V_10 -> V_32 , V_10 -> V_33 ) ;
F_7 ( L_30 , V_10 -> V_34 ) ;
}
void * F_8 ( void * * V_35 , unsigned V_36 , int V_37 )
{
unsigned V_38 , V_39 ;
void * V_40 = * V_35 ;
* V_35 += V_36 * V_37 ;
if ( V_36 > sizeof( long ) )
V_38 = sizeof( long long ) ;
else if ( V_36 > sizeof( int ) )
V_38 = sizeof( long ) ;
else if ( V_36 > sizeof( short ) )
V_38 = sizeof( int ) ;
else if ( V_36 > sizeof( char ) )
V_38 = sizeof( short ) ;
else
return ( char * ) V_40 ;
V_39 = ( unsigned long ) V_35 % V_38 ;
if ( V_39 == 0 )
return ( char * ) V_40 ;
* V_35 += V_38 - V_39 ;
return ( void * ) ( ( ( unsigned long ) V_40 ) + V_38 - V_39 ) ;
}
struct V_22 * F_9 ( unsigned V_41 ,
unsigned V_11 ,
struct V_42 * V_43 ,
unsigned V_44 )
{
struct V_22 * V_10 ;
struct V_42 * V_45 ;
struct V_15 * V_46 , * V_47 ;
struct V_1 * V_48 , * V_49 , * V_2 ;
struct V_6 * V_5 ;
T_1 * V_50 [ V_51 ] , * V_52 [ V_51 ] ;
unsigned V_53 [ V_51 ] ;
unsigned V_36 , V_29 = 1 , V_54 = 1 ;
unsigned V_55 = 1 , V_56 = 1 , V_57 = 0 ;
void * V_58 , * V_35 , * V_40 = NULL ;
int V_7 , V_59 , V_60 , V_61 , V_62 , V_63 , V_64 ;
bool V_65 = false ;
F_10 ( V_11 > V_51 || V_11 == 0 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_29 *= V_43 [ V_7 ] . V_36 ;
if ( V_43 [ V_7 ] . V_66 )
V_55 *= V_43 [ V_7 ] . V_36 ;
else
V_56 *= V_43 [ V_7 ] . V_36 ;
if ( V_43 [ V_7 ] . type == V_67 )
V_65 = true ;
}
V_10 = F_8 ( & V_40 , sizeof( * V_10 ) , 1 ) ;
V_45 = F_8 ( & V_40 , sizeof( * V_45 ) , V_11 ) ;
V_46 = F_8 ( & V_40 , sizeof( * V_46 ) , V_55 ) ;
V_48 = F_8 ( & V_40 , sizeof( * V_48 ) , V_55 * V_56 ) ;
V_5 = F_8 ( & V_40 , sizeof( * V_5 ) , V_29 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_54 *= V_43 [ V_7 ] . V_36 ;
F_2 ( L_31 , V_68 , V_7 , V_54 ) ;
V_50 [ V_7 ] = F_8 ( & V_40 , sizeof( T_1 ) , V_54 ) ;
V_52 [ V_7 ] = F_8 ( & V_40 , sizeof( T_1 ) , V_54 ) ;
V_57 += 2 * V_54 ;
}
F_2 ( L_32 , V_68 , V_57 ) ;
V_58 = F_8 ( & V_40 , V_44 , 1 ) ;
V_36 = ( ( unsigned long ) V_58 ) + V_44 ;
F_11 ( L_33 ,
V_68 , V_36 ,
V_29 ,
V_65 ? L_34 : L_35 ,
V_55 * V_56 ) ;
V_10 = F_12 ( V_36 , V_69 ) ;
if ( V_10 == NULL )
return NULL ;
V_45 = (struct V_42 * ) ( ( ( char * ) V_10 ) + ( ( unsigned long ) V_45 ) ) ;
V_46 = (struct V_15 * ) ( ( ( char * ) V_10 ) + ( ( unsigned long ) V_46 ) ) ;
V_48 = (struct V_1 * ) ( ( ( char * ) V_10 ) + ( ( unsigned long ) V_48 ) ) ;
V_5 = (struct V_6 * ) ( ( ( char * ) V_10 ) + ( ( unsigned long ) V_5 ) ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_10 -> V_50 [ V_7 ] = ( T_1 * ) ( ( char * ) V_10 + ( ( unsigned long ) V_50 [ V_7 ] ) ) ;
V_10 -> V_52 [ V_7 ] = ( T_1 * ) ( ( char * ) V_10 + ( ( unsigned long ) V_52 [ V_7 ] ) ) ;
}
V_58 = V_44 ? ( ( ( char * ) V_10 ) + ( ( unsigned long ) V_58 ) ) : NULL ;
V_10 -> V_70 = V_41 ;
V_10 -> V_28 = V_46 ;
V_10 -> V_30 = V_5 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_34 = V_58 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_43 = V_45 ;
memcpy ( V_10 -> V_43 , V_43 , sizeof( * V_45 ) * V_11 ) ;
V_10 -> V_27 = V_55 ;
V_10 -> V_71 = V_56 ;
V_10 -> V_72 = V_65 ;
for ( V_61 = 0 ; V_61 < V_55 ; V_61 ++ ) {
V_47 = & V_46 [ V_61 ] ;
V_47 -> V_16 = V_61 ;
V_47 -> V_10 = V_10 ;
V_47 -> V_20 = V_56 ;
V_49 = & V_48 [ V_61 * V_56 ] ;
V_47 -> V_21 = V_49 ;
for ( V_62 = 0 ; V_62 < V_56 ; V_62 ++ ) {
V_2 = & V_49 [ V_62 ] ;
V_2 -> V_3 = V_62 ;
V_2 -> V_4 = V_47 ;
}
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_61 = 0 ;
V_62 = 0 ;
F_2 ( L_36 , V_68 , V_29 ,
V_65 ? L_34 : L_35 ) ;
for ( V_7 = 0 ; V_7 < V_29 ; V_7 ++ ) {
V_2 = & V_46 [ V_61 ] . V_21 [ V_62 ] ;
V_5 = F_13 ( V_45 , V_10 -> V_30 , V_11 ,
V_53 [ 0 ] , V_53 [ 1 ] , V_53 [ 2 ] ) ;
V_5 -> V_10 = V_10 ;
F_14 ( L_37 , V_68 ,
V_7 , V_65 ? L_38 : L_39 , ( V_5 - V_10 -> V_30 ) ,
V_53 [ 0 ] , V_53 [ 1 ] , V_53 [ 2 ] , V_61 , V_62 ) ;
V_64 = sizeof( V_5 -> V_8 ) ;
V_35 = V_5 -> V_8 ;
V_63 = snprintf ( V_35 , V_64 , L_40 , V_41 ) ;
V_35 += V_63 ;
V_64 -= V_63 ;
for ( V_59 = 0 ; V_59 < V_11 ; V_59 ++ ) {
V_63 = snprintf ( V_35 , V_64 , L_41 ,
V_73 [ V_43 [ V_59 ] . type ] ,
V_53 [ V_59 ] ) ;
V_35 += V_63 ;
V_64 -= V_63 ;
V_5 -> V_13 [ V_59 ] = V_53 [ V_59 ] ;
if ( V_64 <= 0 )
break;
}
V_2 -> V_5 = V_5 ;
V_5 -> V_4 = V_61 ;
V_5 -> V_74 = V_62 ;
V_61 ++ ;
if ( V_61 == V_55 ) {
V_61 = 0 ;
V_62 ++ ;
}
for ( V_59 = V_11 - 1 ; V_59 >= 0 ; V_59 -- ) {
V_53 [ V_59 ] ++ ;
if ( V_53 [ V_59 ] < V_43 [ V_59 ] . V_36 )
break;
V_53 [ V_59 ] = 0 ;
}
}
V_10 -> V_75 = V_76 ;
F_15 ( & V_10 -> V_77 ) ;
V_60 = F_16 ( V_10 ) ;
if ( V_60 ) {
F_17 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
void F_18 ( struct V_22 * V_10 )
{
F_11 ( L_42 , V_68 ) ;
F_19 ( V_10 ) ;
F_17 ( V_10 ) ;
}
struct V_22 * F_20 ( struct V_78 * V_31 )
{
struct V_22 * V_10 ;
struct V_79 * V_80 ;
F_7 ( L_42 , V_68 ) ;
F_21 (item, &mc_devices) {
V_10 = F_22 ( V_80 , struct V_22 , V_81 ) ;
if ( V_10 -> V_31 == V_31 )
return V_10 ;
}
return NULL ;
}
static int F_23 ( void )
{
int V_82 ;
if ( V_83 == V_84 )
return 1 ;
V_82 = V_85 ;
V_85 = 0 ;
return V_82 ;
}
static void F_24 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = F_25 ( V_87 ) ;
struct V_22 * V_10 = F_26 ( V_89 ) ;
F_27 ( & V_90 ) ;
if ( V_10 -> V_75 == V_91 ) {
F_28 ( & V_90 ) ;
return;
}
if ( F_23 () && ( V_10 -> V_26 != NULL ) )
V_10 -> V_26 ( V_10 ) ;
F_28 ( & V_90 ) ;
F_29 ( V_92 , & V_10 -> V_93 ,
F_30 ( F_31 () ) ) ;
}
static void F_32 ( struct V_22 * V_10 , unsigned V_94 )
{
F_33 ( L_42 , V_68 ) ;
if ( V_10 -> V_75 != V_95 )
return;
F_34 ( & V_10 -> V_93 , F_24 ) ;
F_29 ( V_92 , & V_10 -> V_93 , F_30 ( V_94 ) ) ;
}
static void F_35 ( struct V_22 * V_10 )
{
int V_96 ;
if ( V_10 -> V_75 != V_95 )
return;
V_96 = F_36 ( & V_10 -> V_93 ) ;
if ( V_96 == 0 ) {
F_33 ( L_43 ,
V_68 ) ;
F_37 ( V_92 ) ;
}
}
void F_38 ( int V_97 )
{
struct V_22 * V_10 ;
struct V_79 * V_80 ;
F_27 ( & V_90 ) ;
F_21 (item, &mc_devices) {
V_10 = F_22 ( V_80 , struct V_22 , V_81 ) ;
if ( V_10 -> V_75 == V_95 )
F_36 ( & V_10 -> V_93 ) ;
}
F_28 ( & V_90 ) ;
F_27 ( & V_90 ) ;
F_21 (item, &mc_devices) {
V_10 = F_22 ( V_80 , struct V_22 , V_81 ) ;
F_32 ( V_10 , ( unsigned long ) V_97 ) ;
}
F_28 ( & V_90 ) ;
}
static int F_39 ( struct V_22 * V_10 )
{
struct V_79 * V_80 , * V_98 ;
struct V_22 * V_35 ;
V_98 = & V_99 ;
V_35 = F_20 ( V_10 -> V_31 ) ;
if ( F_40 ( V_35 != NULL ) )
goto V_100;
F_21 (item, &mc_devices) {
V_35 = F_22 ( V_80 , struct V_22 , V_81 ) ;
if ( V_35 -> V_70 >= V_10 -> V_70 ) {
if ( F_40 ( V_35 -> V_70 == V_10 -> V_70 ) )
goto V_101;
V_98 = V_80 ;
break;
}
}
F_41 ( & V_10 -> V_81 , V_98 ) ;
F_42 ( & V_102 ) ;
return 0 ;
V_100:
F_43 ( V_103 , V_104 ,
L_44 , F_44 ( V_35 -> V_31 ) ,
F_45 ( V_10 ) , V_35 -> V_32 , V_35 -> V_33 , V_35 -> V_70 ) ;
return 1 ;
V_101:
F_43 ( V_103 , V_104 ,
L_45
L_46 , V_35 -> V_70 , V_68 ) ;
return 1 ;
}
static void F_46 ( struct V_22 * V_10 )
{
F_47 ( & V_102 ) ;
F_48 ( & V_10 -> V_81 ) ;
F_49 () ;
F_15 ( & V_10 -> V_81 ) ;
}
struct V_22 * F_50 ( int V_105 )
{
struct V_79 * V_80 ;
struct V_22 * V_10 ;
F_21 (item, &mc_devices) {
V_10 = F_22 ( V_80 , struct V_22 , V_81 ) ;
if ( V_10 -> V_70 >= V_105 ) {
if ( V_10 -> V_70 == V_105 )
return V_10 ;
break;
}
}
return NULL ;
}
int F_51 ( struct V_22 * V_10 )
{
F_33 ( L_42 , V_68 ) ;
#ifdef F_52
if ( V_106 >= 3 )
F_6 ( V_10 ) ;
if ( V_106 >= 4 ) {
int V_7 ;
for ( V_7 = 0 ; V_7 < V_10 -> V_27 ; V_7 ++ ) {
int V_59 ;
F_5 ( & V_10 -> V_28 [ V_7 ] ) ;
for ( V_59 = 0 ; V_59 < V_10 -> V_28 [ V_7 ] . V_20 ; V_59 ++ )
F_1 ( & V_10 -> V_28 [ V_7 ] .
V_21 [ V_59 ] ) ;
}
for ( V_7 = 0 ; V_7 < V_10 -> V_29 ; V_7 ++ )
F_3 ( & V_10 -> V_30 [ V_7 ] ) ;
}
#endif
F_27 ( & V_90 ) ;
if ( F_39 ( V_10 ) )
goto V_100;
V_10 -> V_107 = V_108 ;
if ( F_53 ( V_10 ) ) {
F_54 ( V_10 , V_103 ,
L_47 ) ;
goto V_101;
}
if ( V_10 -> V_26 != NULL ) {
V_10 -> V_75 = V_95 ;
F_32 ( V_10 , F_31 () ) ;
} else {
V_10 -> V_75 = V_109 ;
}
F_54 ( V_10 , V_110 , L_48
L_49 , V_10 -> V_32 , V_10 -> V_33 , F_45 ( V_10 ) ) ;
F_28 ( & V_90 ) ;
return 0 ;
V_101:
F_46 ( V_10 ) ;
V_100:
F_28 ( & V_90 ) ;
return 1 ;
}
struct V_22 * F_55 ( struct V_78 * V_31 )
{
struct V_22 * V_10 ;
F_33 ( L_42 , V_68 ) ;
F_27 ( & V_90 ) ;
V_10 = F_20 ( V_31 ) ;
if ( V_10 == NULL ) {
F_28 ( & V_90 ) ;
return NULL ;
}
F_46 ( V_10 ) ;
F_28 ( & V_90 ) ;
F_35 ( V_10 ) ;
V_10 -> V_75 = V_91 ;
F_56 ( V_10 ) ;
F_43 ( V_110 , V_104 ,
L_50 , V_10 -> V_70 ,
V_10 -> V_32 , V_10 -> V_33 , F_45 ( V_10 ) ) ;
return V_10 ;
}
static void F_57 ( unsigned long V_111 , unsigned long V_112 ,
T_1 V_36 )
{
struct V_111 * V_113 ;
void * V_114 ;
unsigned long V_115 = 0 ;
F_7 ( L_42 , V_68 ) ;
if ( ! F_58 ( V_111 ) )
return;
V_113 = F_59 ( V_111 ) ;
if ( F_60 ( V_113 ) )
F_61 ( V_115 ) ;
V_114 = F_62 ( V_113 ) ;
F_63 ( V_114 + V_112 , V_36 ) ;
F_64 ( V_114 ) ;
if ( F_60 ( V_113 ) )
F_65 ( V_115 ) ;
}
int F_66 ( struct V_22 * V_10 , unsigned long V_111 )
{
struct V_15 * V_28 = V_10 -> V_28 ;
int V_61 , V_7 , V_59 , V_63 ;
F_11 ( L_51 , V_10 -> V_70 , V_68 , V_111 ) ;
V_61 = - 1 ;
for ( V_7 = 0 ; V_7 < V_10 -> V_27 ; V_7 ++ ) {
struct V_15 * V_4 = & V_28 [ V_7 ] ;
V_63 = 0 ;
for ( V_59 = 0 ; V_59 < V_4 -> V_20 ; V_59 ++ ) {
struct V_6 * V_5 = V_4 -> V_21 [ V_59 ] . V_5 ;
V_63 += V_5 -> V_9 ;
}
if ( V_63 == 0 )
continue;
F_7 ( L_52
L_53 , V_10 -> V_70 , V_68 ,
V_4 -> V_17 , V_111 , V_4 -> V_18 ,
V_4 -> V_19 ) ;
if ( ( V_111 >= V_4 -> V_17 ) &&
( V_111 <= V_4 -> V_18 ) &&
( ( V_111 & V_4 -> V_19 ) ==
( V_4 -> V_17 & V_4 -> V_19 ) ) ) {
V_61 = V_7 ;
break;
}
}
if ( V_61 == - 1 )
F_54 ( V_10 , V_116 ,
L_54 ,
( unsigned long ) V_111 ) ;
return V_61 ;
}
static void F_67 ( struct V_22 * V_10 ,
bool V_117 ,
const int V_53 [ V_51 ] )
{
int V_7 , V_118 = 0 ;
V_10 -> V_119 ++ ;
if ( ! V_117 ) {
V_10 -> V_120 ++ ;
return;
}
for ( V_7 = 0 ; V_7 < V_10 -> V_11 ; V_7 ++ ) {
if ( V_53 [ V_7 ] < 0 )
break;
V_118 += V_53 [ V_7 ] ;
V_10 -> V_50 [ V_7 ] [ V_118 ] ++ ;
if ( V_7 < V_10 -> V_11 - 1 )
V_118 *= V_10 -> V_43 [ V_7 + 1 ] . V_36 ;
}
}
static void F_68 ( struct V_22 * V_10 ,
bool V_117 ,
const int V_53 [ V_51 ] )
{
int V_7 , V_118 = 0 ;
V_10 -> V_121 ++ ;
if ( ! V_117 ) {
V_10 -> V_120 ++ ;
return;
}
for ( V_7 = 0 ; V_7 < V_10 -> V_11 ; V_7 ++ ) {
if ( V_53 [ V_7 ] < 0 )
break;
V_118 += V_53 [ V_7 ] ;
V_10 -> V_52 [ V_7 ] [ V_118 ] ++ ;
if ( V_7 < V_10 -> V_11 - 1 )
V_118 *= V_10 -> V_43 [ V_7 + 1 ] . V_36 ;
}
}
static void F_69 ( struct V_22 * V_10 ,
const int V_53 [ V_51 ] ,
const char * V_122 ,
const char * V_13 ,
const char * V_8 ,
const char * V_123 ,
const char * V_124 ,
const bool V_117 ,
const unsigned long V_125 ,
const unsigned long V_126 ,
T_1 V_14 )
{
unsigned long V_127 ;
if ( F_70 () ) {
if ( V_124 && * V_124 )
F_54 ( V_10 , V_103 ,
L_55 ,
V_122 , V_8 , V_13 ,
V_123 , V_124 ) ;
else
F_54 ( V_10 , V_103 ,
L_56 ,
V_122 , V_8 , V_13 ,
V_123 ) ;
}
F_67 ( V_10 , V_117 , V_53 ) ;
if ( V_10 -> V_128 & V_129 ) {
V_127 = V_10 -> V_130 ?
V_10 -> V_130 ( V_10 , V_125 ) :
V_125 ;
F_57 ( V_127 ,
V_126 , V_14 ) ;
}
}
static void F_71 ( struct V_22 * V_10 ,
const int V_53 [ V_51 ] ,
const char * V_122 ,
const char * V_13 ,
const char * V_8 ,
const char * V_123 ,
const char * V_124 ,
const bool V_117 )
{
if ( F_72 () ) {
if ( V_124 && * V_124 )
F_54 ( V_10 , V_103 ,
L_57 ,
V_122 , V_8 , V_13 , V_123 ,
V_124 ) ;
else
F_54 ( V_10 , V_103 ,
L_58 ,
V_122 , V_8 , V_13 , V_123 ) ;
}
if ( F_73 () ) {
if ( V_124 && * V_124 )
F_74 ( L_57 ,
V_122 , V_8 , V_13 , V_123 , V_124 ) ;
else
F_74 ( L_58 ,
V_122 , V_8 , V_13 , V_123 ) ;
}
F_68 ( V_10 , V_117 , V_53 ) ;
}
void F_75 ( const enum V_131 type ,
struct V_22 * V_10 ,
const unsigned long V_125 ,
const unsigned long V_126 ,
const unsigned long V_132 ,
const int V_133 ,
const int V_134 ,
const int V_135 ,
const char * V_122 ,
const char * V_124 ,
const void * V_136 )
{
char V_123 [ 80 ] , V_13 [ 80 ] ;
char V_8 [ ( V_137 + 1 + sizeof( V_138 ) ) * V_10 -> V_29 ] ;
char * V_35 ;
int V_61 = - 1 , V_2 = - 1 ;
int V_53 [ V_51 ] = { V_133 , V_134 , V_135 } ;
int V_7 ;
T_1 V_14 ;
bool V_117 = false ;
F_7 ( L_59 , V_10 -> V_70 , V_68 ) ;
for ( V_7 = 0 ; V_7 < V_10 -> V_11 ; V_7 ++ ) {
if ( V_53 [ V_7 ] >= ( int ) V_10 -> V_43 [ V_7 ] . V_36 ) {
if ( type == V_139 )
V_35 = L_60 ;
else
V_35 = L_61 ;
F_54 ( V_10 , V_116 ,
L_62 ,
V_73 [ V_10 -> V_43 [ V_7 ] . type ] ,
V_53 [ V_7 ] , V_10 -> V_43 [ V_7 ] . V_36 ) ;
V_53 [ V_7 ] = - 1 ;
}
if ( V_53 [ V_7 ] >= 0 )
V_117 = true ;
}
V_14 = 0 ;
V_35 = V_8 ;
* V_35 = '\0' ;
for ( V_7 = 0 ; V_7 < V_10 -> V_29 ; V_7 ++ ) {
struct V_6 * V_5 = & V_10 -> V_30 [ V_7 ] ;
if ( V_133 >= 0 && V_133 != V_5 -> V_13 [ 0 ] )
continue;
if ( V_134 >= 0 && V_134 != V_5 -> V_13 [ 1 ] )
continue;
if ( V_135 >= 0 && V_135 != V_5 -> V_13 [ 2 ] )
continue;
if ( V_5 -> V_14 > V_14 )
V_14 = V_5 -> V_14 ;
if ( V_117 && V_5 -> V_9 ) {
if ( V_35 != V_8 ) {
strcpy ( V_35 , V_138 ) ;
V_35 += strlen ( V_138 ) ;
}
strcpy ( V_35 , V_5 -> V_8 ) ;
V_35 += strlen ( V_35 ) ;
* V_35 = '\0' ;
F_2 ( L_63 ,
V_68 ,
V_10 -> V_72 ? L_38 : L_39 ,
V_5 -> V_4 , V_5 -> V_74 ) ;
if ( V_61 == - 1 )
V_61 = V_5 -> V_4 ;
else if ( V_61 >= 0 && V_61 != V_5 -> V_4 )
V_61 = - 2 ;
if ( V_2 == - 1 )
V_2 = V_5 -> V_74 ;
else if ( V_2 >= 0 && V_2 != V_5 -> V_74 )
V_2 = - 2 ;
}
}
if ( ! V_117 ) {
strcpy ( V_8 , L_64 ) ;
} else {
F_2 ( L_65 ,
V_68 , V_61 , V_2 ) ;
if ( V_35 == V_8 )
strcpy ( V_8 , L_66 ) ;
if ( type == V_139 ) {
if ( V_61 >= 0 ) {
V_10 -> V_28 [ V_61 ] . V_140 ++ ;
if ( V_2 >= 0 )
V_10 -> V_28 [ V_61 ] . V_21 [ V_2 ] . V_140 ++ ;
}
} else
if ( V_61 >= 0 )
V_10 -> V_28 [ V_61 ] . V_141 ++ ;
}
V_35 = V_13 ;
for ( V_7 = 0 ; V_7 < V_10 -> V_11 ; V_7 ++ ) {
if ( V_53 [ V_7 ] < 0 )
continue;
V_35 += sprintf ( V_35 , L_67 ,
V_73 [ V_10 -> V_43 [ V_7 ] . type ] ,
V_53 [ V_7 ] ) ;
}
if ( type == V_139 ) {
snprintf ( V_123 , sizeof( V_123 ) ,
L_68 ,
V_125 , V_126 ,
V_14 , V_132 ) ;
F_69 ( V_10 , V_53 , V_122 , V_13 , V_8 , V_123 ,
V_124 , V_117 ,
V_125 , V_126 , V_14 ) ;
} else {
snprintf ( V_123 , sizeof( V_123 ) ,
L_69 ,
V_125 , V_126 , V_14 ) ;
F_71 ( V_10 , V_53 , V_122 , V_13 , V_8 , V_123 ,
V_124 , V_117 ) ;
}
}
