unsigned F_1 ( struct V_1 * V_2 , char * V_3 ,
unsigned V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 , V_8 , V_9 = 0 ;
char * V_10 = V_3 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = snprintf ( V_10 , V_4 , L_1 ,
V_12 [ V_6 -> V_13 [ V_7 ] . type ] ,
V_2 -> V_14 [ V_7 ] ) ;
V_10 += V_8 ;
V_4 -= V_8 ;
V_9 += V_8 ;
if ( ! V_4 )
break;
}
return V_9 ;
}
static void F_2 ( struct V_15 * V_16 )
{
F_3 ( 4 , L_2 , V_16 -> V_17 ) ;
F_3 ( 4 , L_3 , V_16 ) ;
F_3 ( 4 , L_4 , V_16 -> V_18 ) ;
F_3 ( 4 , L_5 , V_16 -> V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_19 )
{
char V_14 [ 80 ] ;
F_1 ( V_2 , V_14 , sizeof( V_14 ) ) ;
F_3 ( 4 , L_6 ,
V_2 -> V_6 -> V_20 ? L_7 : L_8 ,
V_19 , V_14 , V_2 -> V_18 , V_2 -> V_21 ) ;
F_3 ( 4 , L_9 , V_2 ) ;
F_3 ( 4 , L_10 , V_2 -> V_22 ) ;
F_3 ( 4 , L_11 , V_2 -> V_23 ) ;
F_3 ( 4 , L_12 , V_2 -> V_24 ) ;
F_3 ( 4 , L_11 , V_2 -> V_23 ) ;
}
static void F_5 ( struct V_25 * V_18 )
{
F_3 ( 4 , L_13 , V_18 -> V_26 ) ;
F_3 ( 4 , L_14 , V_18 ) ;
F_3 ( 4 , L_15 , V_18 -> V_27 ) ;
F_3 ( 4 , L_16 , V_18 -> V_28 ) ;
F_3 ( 4 , L_17 , V_18 -> V_29 ) ;
F_3 ( 4 , L_18 , V_18 -> V_30 ) ;
F_3 ( 4 , L_19 , V_18 -> V_31 ) ;
F_3 ( 4 , L_20 , V_18 -> V_6 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
F_3 ( 3 , L_21 , V_6 ) ;
F_3 ( 3 , L_22 , V_6 -> V_32 ) ;
F_3 ( 3 , L_23 , V_6 -> V_33 ) ;
F_3 ( 3 , L_24 , V_6 -> V_34 ) ;
F_3 ( 4 , L_25 , V_6 -> V_35 ) ;
F_3 ( 3 , L_26 ,
V_6 -> V_36 , V_6 -> V_37 ) ;
F_3 ( 3 , L_27 ,
V_6 -> V_38 , V_6 -> V_39 ) ;
F_3 ( 3 , L_28 , V_6 -> V_40 ) ;
F_3 ( 3 , L_29 ,
V_6 -> V_41 , V_6 -> V_42 ) ;
F_3 ( 3 , L_30 , V_6 -> V_43 ) ;
}
void * F_7 ( void * * V_10 , unsigned V_44 , int V_45 )
{
unsigned V_46 , V_47 ;
void * V_48 = * V_10 ;
* V_10 += V_44 * V_45 ;
if ( V_44 > sizeof( long ) )
V_46 = sizeof( long long ) ;
else if ( V_44 > sizeof( int ) )
V_46 = sizeof( long ) ;
else if ( V_44 > sizeof( short ) )
V_46 = sizeof( int ) ;
else if ( V_44 > sizeof( char ) )
V_46 = sizeof( short ) ;
else
return ( char * ) V_48 ;
V_47 = ( unsigned long ) V_10 % V_46 ;
if ( V_47 == 0 )
return ( char * ) V_48 ;
* V_10 += V_46 - V_47 ;
return ( void * ) ( ( ( unsigned long ) V_48 ) + V_46 - V_47 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
int V_7 , V_49 , V_50 ;
struct V_25 * V_51 ;
const unsigned int V_38 = V_6 -> V_38 ;
const unsigned int V_52 = V_6 -> V_53 ;
const unsigned int V_54 = V_6 -> V_36 ;
if ( V_6 -> V_39 ) {
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
F_9 ( V_6 -> V_39 [ V_7 ] ) ;
F_9 ( V_6 -> V_39 ) ;
}
if ( V_6 -> V_37 ) {
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
V_51 = V_6 -> V_37 [ V_50 ] ;
if ( V_51 ) {
if ( V_51 -> V_31 ) {
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ )
F_9 ( V_51 -> V_31 [ V_49 ] ) ;
F_9 ( V_51 -> V_31 ) ;
}
F_9 ( V_51 ) ;
}
}
F_9 ( V_6 -> V_37 ) ;
}
F_9 ( V_6 ) ;
}
struct V_5 * F_10 ( unsigned V_55 ,
unsigned V_11 ,
struct V_56 * V_13 ,
unsigned V_57 )
{
struct V_5 * V_6 ;
struct V_56 * V_58 ;
struct V_25 * V_51 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
T_1 * V_59 [ V_60 ] , * V_61 [ V_60 ] ;
unsigned V_62 [ V_60 ] ;
unsigned V_44 , V_38 = 1 , V_9 = 1 ;
unsigned V_54 = 1 , V_52 = 1 , V_63 = 0 ;
void * V_64 , * V_10 , * V_48 = NULL ;
int V_7 , V_65 , V_50 , V_49 , V_8 , V_4 , V_66 ;
bool V_67 = false ;
F_11 ( V_11 > V_60 || V_11 == 0 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_38 *= V_13 [ V_7 ] . V_44 ;
if ( V_13 [ V_7 ] . V_68 )
V_54 *= V_13 [ V_7 ] . V_44 ;
else
V_52 *= V_13 [ V_7 ] . V_44 ;
if ( V_13 [ V_7 ] . type == V_69 )
V_67 = true ;
}
V_6 = F_7 ( & V_48 , sizeof( * V_6 ) , 1 ) ;
V_58 = F_7 ( & V_48 , sizeof( * V_58 ) , V_11 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_9 *= V_13 [ V_7 ] . V_44 ;
F_3 ( 4 , L_31 , V_7 , V_9 ) ;
V_59 [ V_7 ] = F_7 ( & V_48 , sizeof( T_1 ) , V_9 ) ;
V_61 [ V_7 ] = F_7 ( & V_48 , sizeof( T_1 ) , V_9 ) ;
V_63 += 2 * V_9 ;
}
F_3 ( 4 , L_32 , V_63 ) ;
V_64 = F_7 ( & V_48 , V_57 , 1 ) ;
V_44 = ( ( unsigned long ) V_64 ) + V_57 ;
F_3 ( 1 , L_33 ,
V_44 ,
V_38 ,
V_67 ? L_34 : L_35 ,
V_54 * V_52 ) ;
V_6 = F_12 ( V_44 , V_70 ) ;
if ( V_6 == NULL )
return NULL ;
V_58 = (struct V_56 * ) ( ( ( char * ) V_6 ) + ( ( unsigned long ) V_58 ) ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_6 -> V_59 [ V_7 ] = ( T_1 * ) ( ( char * ) V_6 + ( ( unsigned long ) V_59 [ V_7 ] ) ) ;
V_6 -> V_61 [ V_7 ] = ( T_1 * ) ( ( char * ) V_6 + ( ( unsigned long ) V_61 [ V_7 ] ) ) ;
}
V_64 = V_57 ? ( ( ( char * ) V_6 ) + ( ( unsigned long ) V_64 ) ) : NULL ;
V_6 -> V_71 = V_55 ;
V_6 -> V_38 = V_38 ;
V_6 -> V_43 = V_64 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_13 = V_58 ;
memcpy ( V_6 -> V_13 , V_13 , sizeof( * V_58 ) * V_11 ) ;
V_6 -> V_36 = V_54 ;
V_6 -> V_53 = V_52 ;
V_6 -> V_20 = V_67 ;
V_6 -> V_37 = F_13 ( V_54 , sizeof( * V_6 -> V_37 ) , V_70 ) ;
if ( ! V_6 -> V_37 )
goto error;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
V_51 = F_12 ( sizeof( * * V_6 -> V_37 ) , V_70 ) ;
if ( ! V_51 )
goto error;
V_6 -> V_37 [ V_50 ] = V_51 ;
V_51 -> V_26 = V_50 ;
V_51 -> V_6 = V_6 ;
V_51 -> V_30 = V_52 ;
V_51 -> V_31 = F_13 ( V_52 , sizeof( * V_51 -> V_31 ) ,
V_70 ) ;
if ( ! V_51 -> V_31 )
goto error;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_16 = F_12 ( sizeof( * * V_51 -> V_31 ) , V_70 ) ;
if ( ! V_16 )
goto error;
V_51 -> V_31 [ V_49 ] = V_16 ;
V_16 -> V_17 = V_49 ;
V_16 -> V_18 = V_51 ;
}
}
V_6 -> V_39 = F_13 ( V_38 , sizeof( * V_6 -> V_39 ) , V_70 ) ;
if ( ! V_6 -> V_39 )
goto error;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_50 = 0 ;
V_49 = 0 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_16 = V_6 -> V_37 [ V_50 ] -> V_31 [ V_49 ] ;
V_66 = F_14 ( V_58 , V_11 , V_62 [ 0 ] , V_62 [ 1 ] , V_62 [ 2 ] ) ;
if ( V_66 < 0 || V_66 >= V_38 ) {
F_15 ( V_6 , V_72 , L_36 ) ;
goto error;
}
V_2 = F_12 ( sizeof( * * V_6 -> V_39 ) , V_70 ) ;
if ( ! V_2 )
goto error;
V_6 -> V_39 [ V_66 ] = V_2 ;
V_2 -> V_6 = V_6 ;
V_4 = sizeof( V_2 -> V_22 ) ;
V_10 = V_2 -> V_22 ;
V_8 = snprintf ( V_10 , V_4 , L_37 , V_55 ) ;
V_10 += V_8 ;
V_4 -= V_8 ;
for ( V_65 = 0 ; V_65 < V_11 ; V_65 ++ ) {
V_8 = snprintf ( V_10 , V_4 , L_38 ,
V_12 [ V_13 [ V_65 ] . type ] ,
V_62 [ V_65 ] ) ;
V_10 += V_8 ;
V_4 -= V_8 ;
V_2 -> V_14 [ V_65 ] = V_62 [ V_65 ] ;
if ( V_4 <= 0 )
break;
}
V_16 -> V_2 = V_2 ;
V_2 -> V_18 = V_50 ;
V_2 -> V_21 = V_49 ;
if ( V_13 [ 0 ] . V_68 ) {
V_49 ++ ;
if ( V_49 == V_52 ) {
V_49 = 0 ;
V_50 ++ ;
}
} else {
V_50 ++ ;
if ( V_50 == V_54 ) {
V_50 = 0 ;
V_49 ++ ;
}
}
for ( V_65 = V_11 - 1 ; V_65 >= 0 ; V_65 -- ) {
V_62 [ V_65 ] ++ ;
if ( V_62 [ V_65 ] < V_13 [ V_65 ] . V_44 )
break;
V_62 [ V_65 ] = 0 ;
}
}
V_6 -> V_73 = V_74 ;
return V_6 ;
error:
F_8 ( V_6 ) ;
return NULL ;
}
void F_16 ( struct V_5 * V_6 )
{
F_3 ( 1 , L_39 ) ;
if ( ! F_17 ( & V_6 -> V_75 ) ) {
F_8 ( V_6 ) ;
return;
}
F_18 ( V_6 ) ;
}
struct V_5 * F_19 ( struct V_76 * V_75 )
{
struct V_5 * V_6 ;
struct V_77 * V_78 ;
F_3 ( 3 , L_39 ) ;
F_20 (item, &mc_devices) {
V_6 = F_21 ( V_78 , struct V_5 , V_79 ) ;
if ( V_6 -> V_40 == V_75 )
return V_6 ;
}
return NULL ;
}
static int F_22 ( void )
{
int V_80 ;
if ( V_81 == V_82 )
return 1 ;
V_80 = V_83 ;
V_83 = 0 ;
return V_80 ;
}
static void F_23 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = F_24 ( V_85 ) ;
struct V_5 * V_6 = F_25 ( V_87 ) ;
F_26 ( & V_88 ) ;
if ( V_6 -> V_73 == V_89 ) {
F_27 ( & V_88 ) ;
return;
}
if ( F_22 () && ( V_6 -> V_35 != NULL ) )
V_6 -> V_35 ( V_6 ) ;
F_27 ( & V_88 ) ;
F_28 ( V_90 , & V_6 -> V_91 ,
F_29 ( F_30 () ) ) ;
}
static void F_31 ( struct V_5 * V_6 , unsigned V_92 ,
bool V_93 )
{
F_3 ( 0 , L_39 ) ;
if ( V_6 -> V_73 != V_94 )
return;
if ( V_93 )
F_32 ( & V_6 -> V_91 , F_23 ) ;
F_33 ( V_90 , & V_6 -> V_91 , F_29 ( V_92 ) ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
int V_95 ;
if ( V_6 -> V_73 != V_94 )
return;
V_95 = F_35 ( & V_6 -> V_91 ) ;
if ( V_95 == 0 ) {
F_3 ( 0 , L_40 ) ;
F_36 ( V_90 ) ;
}
}
void F_37 ( unsigned long V_96 )
{
struct V_5 * V_6 ;
struct V_77 * V_78 ;
F_26 ( & V_88 ) ;
F_20 (item, &mc_devices) {
V_6 = F_21 ( V_78 , struct V_5 , V_79 ) ;
F_31 ( V_6 , V_96 , false ) ;
}
F_27 ( & V_88 ) ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_77 * V_78 , * V_97 ;
struct V_5 * V_10 ;
V_97 = & V_98 ;
V_10 = F_19 ( V_6 -> V_40 ) ;
if ( F_39 ( V_10 != NULL ) )
goto V_99;
F_20 (item, &mc_devices) {
V_10 = F_21 ( V_78 , struct V_5 , V_79 ) ;
if ( V_10 -> V_71 >= V_6 -> V_71 ) {
if ( F_39 ( V_10 -> V_71 == V_6 -> V_71 ) )
goto V_100;
V_97 = V_78 ;
break;
}
}
F_40 ( & V_6 -> V_79 , V_97 ) ;
F_41 ( & V_101 ) ;
return 0 ;
V_99:
F_42 ( V_102 , V_103 ,
L_41 , F_43 ( V_10 -> V_40 ) ,
F_44 ( V_6 ) , V_10 -> V_41 , V_10 -> V_42 , V_10 -> V_71 ) ;
return 1 ;
V_100:
F_42 ( V_102 , V_103 ,
L_42
L_43 , V_10 -> V_71 , V_104 ) ;
return 1 ;
}
static int F_45 ( struct V_5 * V_6 )
{
int V_105 = F_46 ( & V_101 ) ;
F_47 ( & V_6 -> V_79 ) ;
F_48 () ;
F_49 ( & V_6 -> V_79 ) ;
return V_105 ;
}
struct V_5 * F_50 ( int V_106 )
{
struct V_77 * V_78 ;
struct V_5 * V_6 ;
F_20 (item, &mc_devices) {
V_6 = F_21 ( V_78 , struct V_5 , V_79 ) ;
if ( V_6 -> V_71 >= V_106 ) {
if ( V_6 -> V_71 == V_106 )
return V_6 ;
break;
}
}
return NULL ;
}
int F_51 ( struct V_5 * V_6 )
{
int V_107 = - V_108 ;
F_3 ( 0 , L_39 ) ;
if ( V_6 -> V_71 >= V_109 ) {
F_52 ( L_44 , V_6 -> V_71 ) ;
return - V_110 ;
}
#ifdef F_53
if ( V_111 >= 3 )
F_6 ( V_6 ) ;
if ( V_111 >= 4 ) {
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_36 ; V_7 ++ ) {
struct V_25 * V_18 = V_6 -> V_37 [ V_7 ] ;
T_1 V_23 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_18 -> V_30 ; V_65 ++ )
V_23 += V_18 -> V_31 [ V_65 ] -> V_2 -> V_23 ;
if ( ! V_23 )
continue;
F_5 ( V_18 ) ;
for ( V_65 = 0 ; V_65 < V_18 -> V_30 ; V_65 ++ )
if ( V_18 -> V_31 [ V_65 ] -> V_2 -> V_23 )
F_2 ( V_18 -> V_31 [ V_65 ] ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_38 ; V_7 ++ )
if ( V_6 -> V_39 [ V_7 ] -> V_23 )
F_4 ( V_6 -> V_39 [ V_7 ] , V_7 ) ;
}
#endif
F_26 ( & V_88 ) ;
if ( V_112 && V_112 != V_6 -> V_41 ) {
V_107 = - V_113 ;
goto V_99;
}
if ( F_38 ( V_6 ) )
goto V_99;
V_6 -> V_114 = V_115 ;
V_6 -> V_116 = & V_117 [ V_6 -> V_71 ] ;
if ( F_54 ( V_6 ) ) {
F_15 ( V_6 , V_102 ,
L_45 ) ;
goto V_100;
}
if ( V_6 -> V_35 != NULL ) {
V_6 -> V_73 = V_94 ;
F_31 ( V_6 , F_30 () , true ) ;
} else {
V_6 -> V_73 = V_118 ;
}
F_15 ( V_6 , V_119 ,
L_46 ,
V_6 -> V_41 , V_6 -> V_42 , V_6 -> F_43 ,
F_55 ( V_6 -> V_73 ) ) ;
V_112 = V_6 -> V_41 ;
F_27 ( & V_88 ) ;
return 0 ;
V_100:
F_45 ( V_6 ) ;
V_99:
F_27 ( & V_88 ) ;
return V_107 ;
}
struct V_5 * F_56 ( struct V_76 * V_75 )
{
struct V_5 * V_6 ;
F_3 ( 0 , L_39 ) ;
F_26 ( & V_88 ) ;
V_6 = F_19 ( V_75 ) ;
if ( V_6 == NULL ) {
F_27 ( & V_88 ) ;
return NULL ;
}
if ( ! F_45 ( V_6 ) )
V_112 = NULL ;
F_27 ( & V_88 ) ;
F_34 ( V_6 ) ;
V_6 -> V_73 = V_89 ;
F_57 ( V_6 ) ;
F_42 ( V_119 , V_103 ,
L_47 , V_6 -> V_71 ,
V_6 -> V_41 , V_6 -> V_42 , F_44 ( V_6 ) ) ;
return V_6 ;
}
static void F_58 ( unsigned long V_120 , unsigned long V_121 ,
T_1 V_44 )
{
struct V_120 * V_122 ;
void * V_123 ;
unsigned long V_124 = 0 ;
F_3 ( 3 , L_39 ) ;
if ( ! F_59 ( V_120 ) )
return;
V_122 = F_60 ( V_120 ) ;
if ( F_61 ( V_122 ) )
F_62 ( V_124 ) ;
V_123 = F_63 ( V_122 ) ;
F_64 ( V_123 + V_121 , V_44 ) ;
F_65 ( V_123 ) ;
if ( F_61 ( V_122 ) )
F_66 ( V_124 ) ;
}
int F_67 ( struct V_5 * V_6 , unsigned long V_120 )
{
struct V_25 * * V_37 = V_6 -> V_37 ;
int V_50 , V_7 , V_65 , V_8 ;
F_3 ( 1 , L_48 , V_6 -> V_71 , V_120 ) ;
V_50 = - 1 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_36 ; V_7 ++ ) {
struct V_25 * V_18 = V_37 [ V_7 ] ;
V_8 = 0 ;
for ( V_65 = 0 ; V_65 < V_18 -> V_30 ; V_65 ++ ) {
struct V_1 * V_2 = V_18 -> V_31 [ V_65 ] -> V_2 ;
V_8 += V_2 -> V_23 ;
}
if ( V_8 == 0 )
continue;
F_3 ( 3 , L_49 ,
V_6 -> V_71 ,
V_18 -> V_27 , V_120 , V_18 -> V_28 ,
V_18 -> V_29 ) ;
if ( ( V_120 >= V_18 -> V_27 ) &&
( V_120 <= V_18 -> V_28 ) &&
( ( V_120 & V_18 -> V_29 ) ==
( V_18 -> V_27 & V_18 -> V_29 ) ) ) {
V_50 = V_7 ;
break;
}
}
if ( V_50 == - 1 )
F_15 ( V_6 , V_72 ,
L_50 ,
( unsigned long ) V_120 ) ;
return V_50 ;
}
static void F_68 ( struct V_5 * V_6 ,
bool V_125 ,
const int V_62 [ V_60 ] ,
const T_2 V_9 )
{
int V_7 , V_126 = 0 ;
V_6 -> V_127 += V_9 ;
if ( ! V_125 ) {
V_6 -> V_128 += V_9 ;
return;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
if ( V_62 [ V_7 ] < 0 )
break;
V_126 += V_62 [ V_7 ] ;
V_6 -> V_59 [ V_7 ] [ V_126 ] += V_9 ;
if ( V_7 < V_6 -> V_11 - 1 )
V_126 *= V_6 -> V_13 [ V_7 + 1 ] . V_44 ;
}
}
static void F_69 ( struct V_5 * V_6 ,
bool V_125 ,
const int V_62 [ V_60 ] ,
const T_2 V_9 )
{
int V_7 , V_126 = 0 ;
V_6 -> V_129 += V_9 ;
if ( ! V_125 ) {
V_6 -> V_128 += V_9 ;
return;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
if ( V_62 [ V_7 ] < 0 )
break;
V_126 += V_62 [ V_7 ] ;
V_6 -> V_61 [ V_7 ] [ V_126 ] += V_9 ;
if ( V_7 < V_6 -> V_11 - 1 )
V_126 *= V_6 -> V_13 [ V_7 + 1 ] . V_44 ;
}
}
static void F_70 ( struct V_5 * V_6 ,
const T_2 V_130 ,
const int V_62 [ V_60 ] ,
const char * V_131 ,
const char * V_14 ,
const char * V_22 ,
const char * V_132 ,
const char * V_133 ,
const bool V_125 ,
const unsigned long V_134 ,
const unsigned long V_135 ,
long V_24 )
{
unsigned long V_136 ;
char * V_137 = L_51 ;
if ( * V_131 )
V_137 = L_52 ;
if ( F_71 () ) {
if ( V_133 && * V_133 )
F_15 ( V_6 , V_102 ,
L_53 ,
V_130 , V_131 , V_137 , V_22 ,
V_14 , V_132 , V_133 ) ;
else
F_15 ( V_6 , V_102 ,
L_54 ,
V_130 , V_131 , V_137 , V_22 ,
V_14 , V_132 ) ;
}
F_68 ( V_6 , V_125 , V_62 , V_130 ) ;
if ( V_6 -> V_138 & V_139 ) {
V_136 = V_6 -> V_140 ?
V_6 -> V_140 ( V_6 , V_134 ) :
V_134 ;
F_58 ( V_136 ,
V_135 , V_24 ) ;
}
}
static void F_72 ( struct V_5 * V_6 ,
const T_2 V_130 ,
const int V_62 [ V_60 ] ,
const char * V_131 ,
const char * V_14 ,
const char * V_22 ,
const char * V_132 ,
const char * V_133 ,
const bool V_125 )
{
char * V_137 = L_51 ;
if ( * V_131 )
V_137 = L_52 ;
if ( F_73 () ) {
if ( V_133 && * V_133 )
F_15 ( V_6 , V_102 ,
L_55 ,
V_130 , V_131 , V_137 , V_22 ,
V_14 , V_132 , V_133 ) ;
else
F_15 ( V_6 , V_102 ,
L_56 ,
V_130 , V_131 , V_137 , V_22 ,
V_14 , V_132 ) ;
}
if ( F_74 () ) {
if ( V_133 && * V_133 )
F_75 ( L_57 ,
V_131 , V_137 , V_22 , V_14 , V_132 , V_133 ) ;
else
F_75 ( L_58 ,
V_131 , V_137 , V_22 , V_14 , V_132 ) ;
}
F_69 ( V_6 , V_125 , V_62 , V_130 ) ;
}
void F_76 ( const enum V_141 type ,
struct V_5 * V_6 ,
struct V_142 * V_143 )
{
char V_132 [ 80 ] ;
int V_62 [ V_60 ] = { V_143 -> V_144 , V_143 -> V_145 , V_143 -> V_146 } ;
if ( type == V_147 ) {
snprintf ( V_132 , sizeof( V_132 ) ,
L_59 ,
V_143 -> V_134 , V_143 -> V_135 ,
V_143 -> V_24 , V_143 -> V_148 ) ;
F_70 ( V_6 , V_143 -> V_130 , V_62 , V_143 -> V_131 , V_143 -> V_14 , V_143 -> V_22 ,
V_132 , V_143 -> V_133 , V_143 -> V_125 ,
V_143 -> V_134 , V_143 -> V_135 , V_143 -> V_24 ) ;
} else {
snprintf ( V_132 , sizeof( V_132 ) ,
L_60 ,
V_143 -> V_134 , V_143 -> V_135 , V_143 -> V_24 ) ;
F_72 ( V_6 , V_143 -> V_130 , V_62 , V_143 -> V_131 , V_143 -> V_14 , V_143 -> V_22 ,
V_132 , V_143 -> V_133 , V_143 -> V_125 ) ;
}
}
void F_77 ( const enum V_141 type ,
struct V_5 * V_6 ,
const T_2 V_130 ,
const unsigned long V_134 ,
const unsigned long V_135 ,
const unsigned long V_148 ,
const int V_144 ,
const int V_145 ,
const int V_146 ,
const char * V_131 ,
const char * V_133 )
{
char * V_10 ;
int V_50 = - 1 , V_16 = - 1 ;
int V_62 [ V_60 ] = { V_144 , V_145 , V_146 } ;
int V_7 , V_149 = 0 ;
T_3 V_150 ;
struct V_142 * V_143 = & V_6 -> V_151 ;
F_3 ( 3 , L_61 , V_6 -> V_71 ) ;
memset ( V_143 , 0 , sizeof ( * V_143 ) ) ;
V_143 -> V_130 = V_130 ;
V_143 -> V_144 = V_144 ;
V_143 -> V_145 = V_145 ;
V_143 -> V_146 = V_146 ;
V_143 -> V_134 = V_134 ;
V_143 -> V_135 = V_135 ;
V_143 -> V_148 = V_148 ;
V_143 -> V_131 = V_131 ;
V_143 -> V_133 = V_133 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
if ( V_62 [ V_7 ] >= ( int ) V_6 -> V_13 [ V_7 ] . V_44 ) {
F_15 ( V_6 , V_72 ,
L_62 ,
V_12 [ V_6 -> V_13 [ V_7 ] . type ] ,
V_62 [ V_7 ] , V_6 -> V_13 [ V_7 ] . V_44 ) ;
V_62 [ V_7 ] = - 1 ;
}
if ( V_62 [ V_7 ] >= 0 )
V_143 -> V_125 = true ;
}
V_10 = V_143 -> V_22 ;
* V_10 = '\0' ;
for ( V_7 = 0 ; V_7 < V_6 -> V_38 ; V_7 ++ ) {
struct V_1 * V_2 = V_6 -> V_39 [ V_7 ] ;
if ( V_144 >= 0 && V_144 != V_2 -> V_14 [ 0 ] )
continue;
if ( V_145 >= 0 && V_145 != V_2 -> V_14 [ 1 ] )
continue;
if ( V_146 >= 0 && V_146 != V_2 -> V_14 [ 2 ] )
continue;
if ( V_2 -> V_24 > V_143 -> V_24 )
V_143 -> V_24 = V_2 -> V_24 ;
if ( V_143 -> V_125 && V_2 -> V_23 ) {
if ( V_149 >= V_152 ) {
V_143 -> V_125 = false ;
break;
}
V_149 ++ ;
if ( V_10 != V_143 -> V_22 ) {
strcpy ( V_10 , V_153 ) ;
V_10 += strlen ( V_153 ) ;
}
strcpy ( V_10 , V_2 -> V_22 ) ;
V_10 += strlen ( V_10 ) ;
* V_10 = '\0' ;
F_3 ( 4 , L_63 ,
V_6 -> V_20 ? L_7 : L_8 ,
V_2 -> V_18 , V_2 -> V_21 ) ;
if ( V_50 == - 1 )
V_50 = V_2 -> V_18 ;
else if ( V_50 >= 0 && V_50 != V_2 -> V_18 )
V_50 = - 2 ;
if ( V_16 == - 1 )
V_16 = V_2 -> V_21 ;
else if ( V_16 >= 0 && V_16 != V_2 -> V_21 )
V_16 = - 2 ;
}
}
if ( ! V_143 -> V_125 ) {
strcpy ( V_143 -> V_22 , L_64 ) ;
} else {
F_3 ( 4 , L_65 , V_50 , V_16 ) ;
if ( V_10 == V_143 -> V_22 )
strcpy ( V_143 -> V_22 , L_66 ) ;
if ( type == V_147 ) {
if ( V_50 >= 0 ) {
V_6 -> V_37 [ V_50 ] -> V_154 += V_130 ;
if ( V_16 >= 0 )
V_6 -> V_37 [ V_50 ] -> V_31 [ V_16 ] -> V_154 += V_130 ;
}
} else
if ( V_50 >= 0 )
V_6 -> V_37 [ V_50 ] -> V_155 += V_130 ;
}
V_10 = V_143 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
if ( V_62 [ V_7 ] < 0 )
continue;
V_10 += sprintf ( V_10 , L_67 ,
V_12 [ V_6 -> V_13 [ V_7 ] . type ] ,
V_62 [ V_7 ] ) ;
}
if ( V_10 > V_143 -> V_14 )
* ( V_10 - 1 ) = '\0' ;
V_150 = F_78 ( V_143 -> V_24 ) + 1 ;
F_79 ( type , V_143 -> V_131 , V_143 -> V_22 , V_143 -> V_130 ,
V_6 -> V_71 , V_143 -> V_144 , V_143 -> V_145 , V_143 -> V_146 ,
F_80 ( V_143 -> V_134 ) | V_143 -> V_135 ,
V_150 , V_143 -> V_148 , V_143 -> V_133 ) ;
F_76 ( type , V_6 , V_143 ) ;
}
