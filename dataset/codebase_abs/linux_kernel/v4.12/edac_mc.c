int F_1 ( void )
{
return V_1 ;
}
void F_2 ( int V_2 )
{
if ( V_2 == V_3 ||
V_2 == V_4 ||
V_2 == V_5 )
V_1 = V_2 ;
}
static int F_3 ( const char * V_6 , const struct V_7 * V_8 )
{
if ( ! V_6 )
return - V_9 ;
if ( ! strncmp ( V_6 , L_1 , 2 ) )
V_1 = V_3 ;
else if ( ! strncmp ( V_6 , L_2 , 3 ) )
V_1 = V_4 ;
else if ( ! strncmp ( V_6 , L_3 , 5 ) )
V_1 = V_5 ;
return 0 ;
}
static int F_4 ( char * V_10 , const struct V_7 * V_8 )
{
int V_11 = 0 ;
switch ( V_1 ) {
case V_3 :
V_11 = sprintf ( V_10 , L_1 ) ;
break;
case V_4 :
V_11 = sprintf ( V_10 , L_2 ) ;
break;
case V_5 :
V_11 = sprintf ( V_10 , L_3 ) ;
break;
default:
V_11 = - V_9 ;
break;
}
return V_11 ;
}
unsigned F_5 ( struct V_12 * V_13 , char * V_14 ,
unsigned V_15 )
{
struct V_16 * V_17 = V_13 -> V_17 ;
int V_18 , V_19 , V_20 = 0 ;
char * V_21 = V_14 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ ) {
V_19 = snprintf ( V_21 , V_15 , L_4 ,
V_23 [ V_17 -> V_24 [ V_18 ] . type ] ,
V_13 -> V_25 [ V_18 ] ) ;
V_21 += V_19 ;
V_15 -= V_19 ;
V_20 += V_19 ;
if ( ! V_15 )
break;
}
return V_20 ;
}
static void F_6 ( struct V_26 * V_27 )
{
F_7 ( 4 , L_5 , V_27 -> V_28 ) ;
F_7 ( 4 , L_6 , V_27 ) ;
F_7 ( 4 , L_7 , V_27 -> V_29 ) ;
F_7 ( 4 , L_8 , V_27 -> V_13 ) ;
}
static void F_8 ( struct V_12 * V_13 , int V_30 )
{
char V_25 [ 80 ] ;
F_5 ( V_13 , V_25 , sizeof( V_25 ) ) ;
F_7 ( 4 , L_9 ,
V_13 -> V_17 -> V_31 ? L_10 : L_11 ,
V_30 , V_25 , V_13 -> V_29 , V_13 -> V_32 ) ;
F_7 ( 4 , L_12 , V_13 ) ;
F_7 ( 4 , L_13 , V_13 -> V_33 ) ;
F_7 ( 4 , L_14 , V_13 -> V_34 ) ;
F_7 ( 4 , L_15 , V_13 -> V_35 ) ;
F_7 ( 4 , L_14 , V_13 -> V_34 ) ;
}
static void F_9 ( struct V_36 * V_29 )
{
F_7 ( 4 , L_16 , V_29 -> V_37 ) ;
F_7 ( 4 , L_17 , V_29 ) ;
F_7 ( 4 , L_18 , V_29 -> V_38 ) ;
F_7 ( 4 , L_19 , V_29 -> V_39 ) ;
F_7 ( 4 , L_20 , V_29 -> V_40 ) ;
F_7 ( 4 , L_21 , V_29 -> V_41 ) ;
F_7 ( 4 , L_22 , V_29 -> V_42 ) ;
F_7 ( 4 , L_23 , V_29 -> V_17 ) ;
}
static void F_10 ( struct V_16 * V_17 )
{
F_7 ( 3 , L_24 , V_17 ) ;
F_7 ( 3 , L_25 , V_17 -> V_43 ) ;
F_7 ( 3 , L_26 , V_17 -> V_44 ) ;
F_7 ( 3 , L_27 , V_17 -> V_45 ) ;
F_7 ( 4 , L_28 , V_17 -> V_46 ) ;
F_7 ( 3 , L_29 ,
V_17 -> V_47 , V_17 -> V_48 ) ;
F_7 ( 3 , L_30 ,
V_17 -> V_49 , V_17 -> V_50 ) ;
F_7 ( 3 , L_31 , V_17 -> V_51 ) ;
F_7 ( 3 , L_32 ,
V_17 -> V_52 , V_17 -> V_53 ) ;
F_7 ( 3 , L_33 , V_17 -> V_54 ) ;
}
void * F_11 ( void * * V_21 , unsigned V_55 , int V_56 )
{
unsigned V_57 , V_58 ;
void * V_59 = * V_21 ;
* V_21 += V_55 * V_56 ;
if ( V_55 > sizeof( long ) )
V_57 = sizeof( long long ) ;
else if ( V_55 > sizeof( int ) )
V_57 = sizeof( long ) ;
else if ( V_55 > sizeof( short ) )
V_57 = sizeof( int ) ;
else if ( V_55 > sizeof( char ) )
V_57 = sizeof( short ) ;
else
return ( char * ) V_59 ;
V_58 = ( unsigned long ) V_21 % V_57 ;
if ( V_58 == 0 )
return ( char * ) V_59 ;
* V_21 += V_57 - V_58 ;
return ( void * ) ( ( ( unsigned long ) V_59 ) + V_57 - V_58 ) ;
}
static void F_12 ( struct V_16 * V_17 )
{
int V_18 , V_60 , V_61 ;
struct V_36 * V_62 ;
const unsigned int V_49 = V_17 -> V_49 ;
const unsigned int V_63 = V_17 -> V_64 ;
const unsigned int V_65 = V_17 -> V_47 ;
if ( V_17 -> V_50 ) {
for ( V_18 = 0 ; V_18 < V_49 ; V_18 ++ )
F_13 ( V_17 -> V_50 [ V_18 ] ) ;
F_13 ( V_17 -> V_50 ) ;
}
if ( V_17 -> V_48 ) {
for ( V_61 = 0 ; V_61 < V_65 ; V_61 ++ ) {
V_62 = V_17 -> V_48 [ V_61 ] ;
if ( V_62 ) {
if ( V_62 -> V_42 ) {
for ( V_60 = 0 ; V_60 < V_63 ; V_60 ++ )
F_13 ( V_62 -> V_42 [ V_60 ] ) ;
F_13 ( V_62 -> V_42 ) ;
}
F_13 ( V_62 ) ;
}
}
F_13 ( V_17 -> V_48 ) ;
}
F_13 ( V_17 ) ;
}
struct V_16 * F_14 ( unsigned V_66 ,
unsigned V_22 ,
struct V_67 * V_24 ,
unsigned V_68 )
{
struct V_16 * V_17 ;
struct V_67 * V_69 ;
struct V_36 * V_62 ;
struct V_26 * V_27 ;
struct V_12 * V_13 ;
T_1 * V_70 [ V_71 ] , * V_72 [ V_71 ] ;
unsigned V_73 [ V_71 ] ;
unsigned V_55 , V_49 = 1 , V_20 = 1 ;
unsigned V_65 = 1 , V_63 = 1 , V_74 = 0 ;
void * V_75 , * V_21 , * V_59 = NULL ;
int V_18 , V_76 , V_61 , V_60 , V_19 , V_15 , V_77 ;
bool V_78 = false ;
F_15 ( V_22 > V_71 || V_22 == 0 ) ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
V_49 *= V_24 [ V_18 ] . V_55 ;
if ( V_24 [ V_18 ] . V_79 )
V_65 *= V_24 [ V_18 ] . V_55 ;
else
V_63 *= V_24 [ V_18 ] . V_55 ;
if ( V_24 [ V_18 ] . type == V_80 )
V_78 = true ;
}
V_17 = F_11 ( & V_59 , sizeof( * V_17 ) , 1 ) ;
V_69 = F_11 ( & V_59 , sizeof( * V_69 ) , V_22 ) ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
V_20 *= V_24 [ V_18 ] . V_55 ;
F_7 ( 4 , L_34 , V_18 , V_20 ) ;
V_70 [ V_18 ] = F_11 ( & V_59 , sizeof( T_1 ) , V_20 ) ;
V_72 [ V_18 ] = F_11 ( & V_59 , sizeof( T_1 ) , V_20 ) ;
V_74 += 2 * V_20 ;
}
F_7 ( 4 , L_35 , V_74 ) ;
V_75 = F_11 ( & V_59 , V_68 , 1 ) ;
V_55 = ( ( unsigned long ) V_75 ) + V_68 ;
F_7 ( 1 , L_36 ,
V_55 ,
V_49 ,
V_78 ? L_37 : L_38 ,
V_65 * V_63 ) ;
V_17 = F_16 ( V_55 , V_81 ) ;
if ( V_17 == NULL )
return NULL ;
V_69 = (struct V_67 * ) ( ( ( char * ) V_17 ) + ( ( unsigned long ) V_69 ) ) ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
V_17 -> V_70 [ V_18 ] = ( T_1 * ) ( ( char * ) V_17 + ( ( unsigned long ) V_70 [ V_18 ] ) ) ;
V_17 -> V_72 [ V_18 ] = ( T_1 * ) ( ( char * ) V_17 + ( ( unsigned long ) V_72 [ V_18 ] ) ) ;
}
V_75 = V_68 ? ( ( ( char * ) V_17 ) + ( ( unsigned long ) V_75 ) ) : NULL ;
V_17 -> V_82 = V_66 ;
V_17 -> V_49 = V_49 ;
V_17 -> V_54 = V_75 ;
V_17 -> V_22 = V_22 ;
V_17 -> V_24 = V_69 ;
memcpy ( V_17 -> V_24 , V_24 , sizeof( * V_69 ) * V_22 ) ;
V_17 -> V_47 = V_65 ;
V_17 -> V_64 = V_63 ;
V_17 -> V_31 = V_78 ;
V_17 -> V_48 = F_17 ( V_65 , sizeof( * V_17 -> V_48 ) , V_81 ) ;
if ( ! V_17 -> V_48 )
goto error;
for ( V_61 = 0 ; V_61 < V_65 ; V_61 ++ ) {
V_62 = F_16 ( sizeof( * * V_17 -> V_48 ) , V_81 ) ;
if ( ! V_62 )
goto error;
V_17 -> V_48 [ V_61 ] = V_62 ;
V_62 -> V_37 = V_61 ;
V_62 -> V_17 = V_17 ;
V_62 -> V_41 = V_63 ;
V_62 -> V_42 = F_17 ( V_63 , sizeof( * V_62 -> V_42 ) ,
V_81 ) ;
if ( ! V_62 -> V_42 )
goto error;
for ( V_60 = 0 ; V_60 < V_63 ; V_60 ++ ) {
V_27 = F_16 ( sizeof( * * V_62 -> V_42 ) , V_81 ) ;
if ( ! V_27 )
goto error;
V_62 -> V_42 [ V_60 ] = V_27 ;
V_27 -> V_28 = V_60 ;
V_27 -> V_29 = V_62 ;
}
}
V_17 -> V_50 = F_17 ( V_49 , sizeof( * V_17 -> V_50 ) , V_81 ) ;
if ( ! V_17 -> V_50 )
goto error;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_61 = 0 ;
V_60 = 0 ;
for ( V_18 = 0 ; V_18 < V_49 ; V_18 ++ ) {
V_27 = V_17 -> V_48 [ V_61 ] -> V_42 [ V_60 ] ;
V_77 = F_18 ( V_69 , V_22 , V_73 [ 0 ] , V_73 [ 1 ] , V_73 [ 2 ] ) ;
if ( V_77 < 0 || V_77 >= V_49 ) {
F_19 ( V_17 , V_83 , L_39 ) ;
goto error;
}
V_13 = F_16 ( sizeof( * * V_17 -> V_50 ) , V_81 ) ;
if ( ! V_13 )
goto error;
V_17 -> V_50 [ V_77 ] = V_13 ;
V_13 -> V_17 = V_17 ;
V_15 = sizeof( V_13 -> V_33 ) ;
V_21 = V_13 -> V_33 ;
V_19 = snprintf ( V_21 , V_15 , L_40 , V_66 ) ;
V_21 += V_19 ;
V_15 -= V_19 ;
for ( V_76 = 0 ; V_76 < V_22 ; V_76 ++ ) {
V_19 = snprintf ( V_21 , V_15 , L_41 ,
V_23 [ V_24 [ V_76 ] . type ] ,
V_73 [ V_76 ] ) ;
V_21 += V_19 ;
V_15 -= V_19 ;
V_13 -> V_25 [ V_76 ] = V_73 [ V_76 ] ;
if ( V_15 <= 0 )
break;
}
V_27 -> V_13 = V_13 ;
V_13 -> V_29 = V_61 ;
V_13 -> V_32 = V_60 ;
if ( V_24 [ 0 ] . V_79 ) {
V_60 ++ ;
if ( V_60 == V_63 ) {
V_60 = 0 ;
V_61 ++ ;
}
} else {
V_61 ++ ;
if ( V_61 == V_65 ) {
V_61 = 0 ;
V_60 ++ ;
}
}
for ( V_76 = V_22 - 1 ; V_76 >= 0 ; V_76 -- ) {
V_73 [ V_76 ] ++ ;
if ( V_73 [ V_76 ] < V_24 [ V_76 ] . V_55 )
break;
V_73 [ V_76 ] = 0 ;
}
}
V_17 -> V_84 = V_85 ;
return V_17 ;
error:
F_12 ( V_17 ) ;
return NULL ;
}
void F_20 ( struct V_16 * V_17 )
{
F_7 ( 1 , L_42 ) ;
if ( ! F_21 ( & V_17 -> V_86 ) ) {
F_12 ( V_17 ) ;
return;
}
F_22 ( V_17 ) ;
}
bool F_23 ( void )
{
bool V_11 ;
F_24 ( & V_87 ) ;
V_11 = F_25 ( & V_88 ) ;
F_26 ( & V_87 ) ;
return ! V_11 ;
}
static struct V_16 * F_27 ( struct V_89 * V_86 )
{
struct V_16 * V_17 ;
struct V_90 * V_91 ;
F_7 ( 3 , L_42 ) ;
F_28 (item, &mc_devices) {
V_17 = F_29 ( V_91 , struct V_16 , V_92 ) ;
if ( V_17 -> V_51 == V_86 )
return V_17 ;
}
return NULL ;
}
struct V_16 * F_30 ( struct V_89 * V_86 )
{
struct V_16 * V_11 ;
F_24 ( & V_87 ) ;
V_11 = F_27 ( V_86 ) ;
F_26 ( & V_87 ) ;
return V_11 ;
}
static void F_31 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = F_32 ( V_94 ) ;
struct V_16 * V_17 = F_33 ( V_96 ) ;
F_24 ( & V_87 ) ;
if ( V_17 -> V_84 != V_97 ) {
F_26 ( & V_87 ) ;
return;
}
if ( V_98 == V_99 )
V_17 -> V_46 ( V_17 ) ;
F_26 ( & V_87 ) ;
F_34 ( & V_17 -> V_100 , F_35 ( F_36 () ) ) ;
}
void F_37 ( unsigned long V_101 )
{
struct V_16 * V_17 ;
struct V_90 * V_91 ;
F_24 ( & V_87 ) ;
F_28 (item, &mc_devices) {
V_17 = F_29 ( V_91 , struct V_16 , V_92 ) ;
if ( V_17 -> V_84 == V_97 )
F_38 ( & V_17 -> V_100 , V_101 ) ;
}
F_26 ( & V_87 ) ;
}
static int F_39 ( struct V_16 * V_17 )
{
struct V_90 * V_91 , * V_102 ;
struct V_16 * V_21 ;
V_102 = & V_88 ;
V_21 = F_27 ( V_17 -> V_51 ) ;
if ( F_40 ( V_21 != NULL ) )
goto V_103;
F_28 (item, &mc_devices) {
V_21 = F_29 ( V_91 , struct V_16 , V_92 ) ;
if ( V_21 -> V_82 >= V_17 -> V_82 ) {
if ( F_40 ( V_21 -> V_82 == V_17 -> V_82 ) )
goto V_104;
V_102 = V_91 ;
break;
}
}
F_41 ( & V_17 -> V_92 , V_102 ) ;
return 0 ;
V_103:
F_42 ( V_105 , V_106 ,
L_43 , F_43 ( V_21 -> V_51 ) ,
F_44 ( V_17 ) , V_21 -> V_52 , V_21 -> V_53 , V_21 -> V_82 ) ;
return 1 ;
V_104:
F_42 ( V_105 , V_106 ,
L_44
L_45 , V_21 -> V_82 , V_107 ) ;
return 1 ;
}
static int F_45 ( struct V_16 * V_17 )
{
F_46 ( & V_17 -> V_92 ) ;
F_47 () ;
F_48 ( & V_17 -> V_92 ) ;
return F_25 ( & V_88 ) ;
}
struct V_16 * F_49 ( int V_108 )
{
struct V_16 * V_17 = NULL ;
struct V_90 * V_91 ;
F_24 ( & V_87 ) ;
F_28 (item, &mc_devices) {
V_17 = F_29 ( V_91 , struct V_16 , V_92 ) ;
if ( V_17 -> V_82 >= V_108 ) {
if ( V_17 -> V_82 == V_108 ) {
goto V_109;
}
break;
}
}
V_109:
F_26 ( & V_87 ) ;
return V_17 ;
}
int F_50 ( struct V_16 * V_17 ,
const struct V_110 * * V_111 )
{
int V_11 = - V_9 ;
F_7 ( 0 , L_42 ) ;
if ( V_17 -> V_82 >= V_112 ) {
F_51 ( L_46 , V_17 -> V_82 ) ;
return - V_113 ;
}
#ifdef F_52
if ( V_114 >= 3 )
F_10 ( V_17 ) ;
if ( V_114 >= 4 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_47 ; V_18 ++ ) {
struct V_36 * V_29 = V_17 -> V_48 [ V_18 ] ;
T_1 V_34 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_29 -> V_41 ; V_76 ++ )
V_34 += V_29 -> V_42 [ V_76 ] -> V_13 -> V_34 ;
if ( ! V_34 )
continue;
F_9 ( V_29 ) ;
for ( V_76 = 0 ; V_76 < V_29 -> V_41 ; V_76 ++ )
if ( V_29 -> V_42 [ V_76 ] -> V_13 -> V_34 )
F_6 ( V_29 -> V_42 [ V_76 ] ) ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_49 ; V_18 ++ )
if ( V_17 -> V_50 [ V_18 ] -> V_34 )
F_8 ( V_17 -> V_50 [ V_18 ] , V_18 ) ;
}
#endif
F_24 ( & V_87 ) ;
if ( V_115 && V_115 != V_17 -> V_52 ) {
V_11 = - V_116 ;
goto V_103;
}
if ( F_39 ( V_17 ) )
goto V_103;
V_17 -> V_117 = V_118 ;
V_17 -> V_119 = & V_120 [ V_17 -> V_82 ] ;
if ( F_53 ( V_17 , V_111 ) ) {
F_19 ( V_17 , V_105 ,
L_47 ) ;
goto V_104;
}
if ( V_17 -> V_46 ) {
V_17 -> V_84 = V_97 ;
F_54 ( & V_17 -> V_100 , F_31 ) ;
F_34 ( & V_17 -> V_100 , F_35 ( F_36 () ) ) ;
} else {
V_17 -> V_84 = V_121 ;
}
F_19 ( V_17 , V_122 ,
L_48 ,
V_17 -> V_52 , V_17 -> V_53 , V_17 -> F_43 ,
F_55 ( V_17 -> V_84 ) ) ;
V_115 = V_17 -> V_52 ;
F_26 ( & V_87 ) ;
return 0 ;
V_104:
F_45 ( V_17 ) ;
V_103:
F_26 ( & V_87 ) ;
return V_11 ;
}
struct V_16 * F_56 ( struct V_89 * V_86 )
{
struct V_16 * V_17 ;
F_7 ( 0 , L_42 ) ;
F_24 ( & V_87 ) ;
V_17 = F_27 ( V_86 ) ;
if ( V_17 == NULL ) {
F_26 ( & V_87 ) ;
return NULL ;
}
V_17 -> V_84 = V_123 ;
if ( F_45 ( V_17 ) )
V_115 = NULL ;
F_26 ( & V_87 ) ;
if ( V_17 -> V_46 )
F_57 ( & V_17 -> V_100 ) ;
F_58 ( V_17 ) ;
F_42 ( V_122 , V_106 ,
L_49 , V_17 -> V_82 ,
V_17 -> V_52 , V_17 -> V_53 , F_44 ( V_17 ) ) ;
return V_17 ;
}
static void F_59 ( unsigned long V_124 , unsigned long V_125 ,
T_1 V_55 )
{
struct V_124 * V_126 ;
void * V_127 ;
unsigned long V_128 = 0 ;
F_7 ( 3 , L_42 ) ;
if ( ! F_60 ( V_124 ) )
return;
V_126 = F_61 ( V_124 ) ;
if ( F_62 ( V_126 ) )
F_63 ( V_128 ) ;
V_127 = F_64 ( V_126 ) ;
F_65 ( V_127 + V_125 , V_55 ) ;
F_66 ( V_127 ) ;
if ( F_62 ( V_126 ) )
F_67 ( V_128 ) ;
}
int F_68 ( struct V_16 * V_17 , unsigned long V_124 )
{
struct V_36 * * V_48 = V_17 -> V_48 ;
int V_61 , V_18 , V_76 , V_19 ;
F_7 ( 1 , L_50 , V_17 -> V_82 , V_124 ) ;
V_61 = - 1 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_47 ; V_18 ++ ) {
struct V_36 * V_29 = V_48 [ V_18 ] ;
V_19 = 0 ;
for ( V_76 = 0 ; V_76 < V_29 -> V_41 ; V_76 ++ ) {
struct V_12 * V_13 = V_29 -> V_42 [ V_76 ] -> V_13 ;
V_19 += V_13 -> V_34 ;
}
if ( V_19 == 0 )
continue;
F_7 ( 3 , L_51 ,
V_17 -> V_82 ,
V_29 -> V_38 , V_124 , V_29 -> V_39 ,
V_29 -> V_40 ) ;
if ( ( V_124 >= V_29 -> V_38 ) &&
( V_124 <= V_29 -> V_39 ) &&
( ( V_124 & V_29 -> V_40 ) ==
( V_29 -> V_38 & V_29 -> V_40 ) ) ) {
V_61 = V_18 ;
break;
}
}
if ( V_61 == - 1 )
F_19 ( V_17 , V_83 ,
L_52 ,
( unsigned long ) V_124 ) ;
return V_61 ;
}
static void F_69 ( struct V_16 * V_17 ,
bool V_129 ,
const int V_73 [ V_71 ] ,
const T_2 V_20 )
{
int V_18 , V_130 = 0 ;
V_17 -> V_131 += V_20 ;
if ( ! V_129 ) {
V_17 -> V_132 += V_20 ;
return;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ ) {
if ( V_73 [ V_18 ] < 0 )
break;
V_130 += V_73 [ V_18 ] ;
V_17 -> V_70 [ V_18 ] [ V_130 ] += V_20 ;
if ( V_18 < V_17 -> V_22 - 1 )
V_130 *= V_17 -> V_24 [ V_18 + 1 ] . V_55 ;
}
}
static void F_70 ( struct V_16 * V_17 ,
bool V_129 ,
const int V_73 [ V_71 ] ,
const T_2 V_20 )
{
int V_18 , V_130 = 0 ;
V_17 -> V_133 += V_20 ;
if ( ! V_129 ) {
V_17 -> V_134 += V_20 ;
return;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ ) {
if ( V_73 [ V_18 ] < 0 )
break;
V_130 += V_73 [ V_18 ] ;
V_17 -> V_72 [ V_18 ] [ V_130 ] += V_20 ;
if ( V_18 < V_17 -> V_22 - 1 )
V_130 *= V_17 -> V_24 [ V_18 + 1 ] . V_55 ;
}
}
static void F_71 ( struct V_16 * V_17 ,
const T_2 V_135 ,
const int V_73 [ V_71 ] ,
const char * V_136 ,
const char * V_25 ,
const char * V_33 ,
const char * V_137 ,
const char * V_138 ,
const bool V_129 ,
const unsigned long V_139 ,
const unsigned long V_140 ,
long V_35 )
{
unsigned long V_141 ;
char * V_142 = L_53 ;
if ( * V_136 )
V_142 = L_54 ;
if ( F_72 () ) {
if ( V_138 && * V_138 )
F_19 ( V_17 , V_105 ,
L_55 ,
V_135 , V_136 , V_142 , V_33 ,
V_25 , V_137 , V_138 ) ;
else
F_19 ( V_17 , V_105 ,
L_56 ,
V_135 , V_136 , V_142 , V_33 ,
V_25 , V_137 ) ;
}
F_69 ( V_17 , V_129 , V_73 , V_135 ) ;
if ( V_17 -> V_143 == V_144 ) {
V_141 = V_17 -> V_145 ?
V_17 -> V_145 ( V_17 , V_139 ) :
V_139 ;
F_59 ( V_141 ,
V_140 , V_35 ) ;
}
}
static void F_73 ( struct V_16 * V_17 ,
const T_2 V_135 ,
const int V_73 [ V_71 ] ,
const char * V_136 ,
const char * V_25 ,
const char * V_33 ,
const char * V_137 ,
const char * V_138 ,
const bool V_129 )
{
char * V_142 = L_53 ;
if ( * V_136 )
V_142 = L_54 ;
if ( F_74 () ) {
if ( V_138 && * V_138 )
F_19 ( V_17 , V_105 ,
L_57 ,
V_135 , V_136 , V_142 , V_33 ,
V_25 , V_137 , V_138 ) ;
else
F_19 ( V_17 , V_105 ,
L_58 ,
V_135 , V_136 , V_142 , V_33 ,
V_25 , V_137 ) ;
}
if ( F_75 () ) {
if ( V_138 && * V_138 )
F_76 ( L_59 ,
V_136 , V_142 , V_33 , V_25 , V_137 , V_138 ) ;
else
F_76 ( L_60 ,
V_136 , V_142 , V_33 , V_25 , V_137 ) ;
}
F_70 ( V_17 , V_129 , V_73 , V_135 ) ;
}
void F_77 ( const enum V_146 type ,
struct V_16 * V_17 ,
struct V_147 * V_148 )
{
char V_137 [ 80 ] ;
int V_73 [ V_71 ] = { V_148 -> V_149 , V_148 -> V_150 , V_148 -> V_151 } ;
if ( type == V_152 ) {
snprintf ( V_137 , sizeof( V_137 ) ,
L_61 ,
V_148 -> V_139 , V_148 -> V_140 ,
V_148 -> V_35 , V_148 -> V_153 ) ;
F_71 ( V_17 , V_148 -> V_135 , V_73 , V_148 -> V_136 , V_148 -> V_25 , V_148 -> V_33 ,
V_137 , V_148 -> V_138 , V_148 -> V_129 ,
V_148 -> V_139 , V_148 -> V_140 , V_148 -> V_35 ) ;
} else {
snprintf ( V_137 , sizeof( V_137 ) ,
L_62 ,
V_148 -> V_139 , V_148 -> V_140 , V_148 -> V_35 ) ;
F_73 ( V_17 , V_148 -> V_135 , V_73 , V_148 -> V_136 , V_148 -> V_25 , V_148 -> V_33 ,
V_137 , V_148 -> V_138 , V_148 -> V_129 ) ;
}
}
void F_78 ( const enum V_146 type ,
struct V_16 * V_17 ,
const T_2 V_135 ,
const unsigned long V_139 ,
const unsigned long V_140 ,
const unsigned long V_153 ,
const int V_149 ,
const int V_150 ,
const int V_151 ,
const char * V_136 ,
const char * V_138 )
{
char * V_21 ;
int V_61 = - 1 , V_27 = - 1 ;
int V_73 [ V_71 ] = { V_149 , V_150 , V_151 } ;
int V_18 , V_154 = 0 ;
T_3 V_155 ;
struct V_147 * V_148 = & V_17 -> V_156 ;
F_7 ( 3 , L_63 , V_17 -> V_82 ) ;
memset ( V_148 , 0 , sizeof ( * V_148 ) ) ;
V_148 -> V_135 = V_135 ;
V_148 -> V_149 = V_149 ;
V_148 -> V_150 = V_150 ;
V_148 -> V_151 = V_151 ;
V_148 -> V_139 = V_139 ;
V_148 -> V_140 = V_140 ;
V_148 -> V_153 = V_153 ;
V_148 -> V_136 = V_136 ;
V_148 -> V_138 = V_138 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ ) {
if ( V_73 [ V_18 ] >= ( int ) V_17 -> V_24 [ V_18 ] . V_55 ) {
F_19 ( V_17 , V_83 ,
L_64 ,
V_23 [ V_17 -> V_24 [ V_18 ] . type ] ,
V_73 [ V_18 ] , V_17 -> V_24 [ V_18 ] . V_55 ) ;
V_73 [ V_18 ] = - 1 ;
}
if ( V_73 [ V_18 ] >= 0 )
V_148 -> V_129 = true ;
}
V_21 = V_148 -> V_33 ;
* V_21 = '\0' ;
for ( V_18 = 0 ; V_18 < V_17 -> V_49 ; V_18 ++ ) {
struct V_12 * V_13 = V_17 -> V_50 [ V_18 ] ;
if ( V_149 >= 0 && V_149 != V_13 -> V_25 [ 0 ] )
continue;
if ( V_150 >= 0 && V_150 != V_13 -> V_25 [ 1 ] )
continue;
if ( V_151 >= 0 && V_151 != V_13 -> V_25 [ 2 ] )
continue;
if ( V_13 -> V_35 > V_148 -> V_35 )
V_148 -> V_35 = V_13 -> V_35 ;
if ( V_148 -> V_129 && V_13 -> V_34 ) {
if ( V_154 >= V_157 ) {
V_148 -> V_129 = false ;
break;
}
V_154 ++ ;
if ( V_21 != V_148 -> V_33 ) {
strcpy ( V_21 , V_158 ) ;
V_21 += strlen ( V_158 ) ;
}
strcpy ( V_21 , V_13 -> V_33 ) ;
V_21 += strlen ( V_21 ) ;
* V_21 = '\0' ;
F_7 ( 4 , L_65 ,
V_17 -> V_31 ? L_10 : L_11 ,
V_13 -> V_29 , V_13 -> V_32 ) ;
if ( V_61 == - 1 )
V_61 = V_13 -> V_29 ;
else if ( V_61 >= 0 && V_61 != V_13 -> V_29 )
V_61 = - 2 ;
if ( V_27 == - 1 )
V_27 = V_13 -> V_32 ;
else if ( V_27 >= 0 && V_27 != V_13 -> V_32 )
V_27 = - 2 ;
}
}
if ( ! V_148 -> V_129 ) {
strcpy ( V_148 -> V_33 , L_66 ) ;
} else {
F_7 ( 4 , L_67 , V_61 , V_27 ) ;
if ( V_21 == V_148 -> V_33 )
strcpy ( V_148 -> V_33 , L_68 ) ;
if ( type == V_152 ) {
if ( V_61 >= 0 ) {
V_17 -> V_48 [ V_61 ] -> V_159 += V_135 ;
if ( V_27 >= 0 )
V_17 -> V_48 [ V_61 ] -> V_42 [ V_27 ] -> V_159 += V_135 ;
}
} else
if ( V_61 >= 0 )
V_17 -> V_48 [ V_61 ] -> V_160 += V_135 ;
}
V_21 = V_148 -> V_25 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ ) {
if ( V_73 [ V_18 ] < 0 )
continue;
V_21 += sprintf ( V_21 , L_69 ,
V_23 [ V_17 -> V_24 [ V_18 ] . type ] ,
V_73 [ V_18 ] ) ;
}
if ( V_21 > V_148 -> V_25 )
* ( V_21 - 1 ) = '\0' ;
V_155 = F_79 ( V_148 -> V_35 ) + 1 ;
if ( F_80 ( V_161 ) )
F_81 ( type , V_148 -> V_136 , V_148 -> V_33 , V_148 -> V_135 ,
V_17 -> V_82 , V_148 -> V_149 , V_148 -> V_150 ,
V_148 -> V_151 ,
( V_148 -> V_139 << V_162 ) | V_148 -> V_140 ,
V_155 , V_148 -> V_153 , V_148 -> V_138 ) ;
F_77 ( type , V_17 , V_148 ) ;
}
