static int F_1 ( unsigned long V_1 )
{
if ( F_2 ( & V_2 ) )
return 1 ;
F_3 ( & V_3 , 0 , 1 , V_1 ) ;
return 0 ;
}
char * F_4 ( void )
{
return V_4 ;
}
T_1 F_5 ( void )
{
return V_5 ;
}
static char * F_6 ( const struct V_6 * V_7 )
{
return ( char * ) V_7 + sizeof( struct V_6 ) ;
}
static char * F_7 ( const struct V_6 * V_7 )
{
return ( char * ) V_7 + sizeof( struct V_6 ) + V_7 -> V_8 ;
}
static struct V_6 * F_8 ( T_1 V_9 )
{
struct V_6 * V_7 = (struct V_6 * ) ( V_4 + V_9 ) ;
if ( ! V_7 -> V_10 )
return (struct V_6 * ) V_4 ;
return V_7 ;
}
static T_1 F_9 ( T_1 V_9 )
{
struct V_6 * V_7 = (struct V_6 * ) ( V_4 + V_9 ) ;
if ( ! V_7 -> V_10 ) {
V_7 = (struct V_6 * ) V_4 ;
return V_7 -> V_10 ;
}
return V_9 + V_7 -> V_10 ;
}
static int F_10 ( T_1 V_11 , bool V_12 )
{
T_1 free ;
if ( V_13 > V_14 || V_12 )
free = F_11 ( V_5 - V_13 , V_14 ) ;
else
free = V_14 - V_13 ;
return free >= V_11 + sizeof( struct V_6 ) ;
}
static int F_12 ( T_1 V_11 )
{
while ( V_15 < V_16 ) {
if ( F_10 ( V_11 , false ) )
return 0 ;
V_14 = F_9 ( V_14 ) ;
V_15 ++ ;
}
if ( F_10 ( V_11 , true ) )
return 0 ;
return - V_17 ;
}
static T_1 F_13 ( T_2 V_8 , T_2 V_18 , T_1 * V_19 )
{
T_1 V_20 ;
V_20 = sizeof( struct V_6 ) + V_8 + V_18 ;
* V_19 = ( - V_20 ) & ( V_21 - 1 ) ;
V_20 += * V_19 ;
return V_20 ;
}
static T_1 F_14 ( T_2 * V_8 , T_2 * V_22 ,
T_2 * V_18 , T_1 * V_19 )
{
T_1 V_23 = V_5 / V_24 ;
if ( * V_8 > V_23 )
* V_8 = V_23 ;
* V_22 = strlen ( V_25 ) ;
* V_18 = 0 ;
return F_13 ( * V_8 + * V_22 , 0 , V_19 ) ;
}
static int F_15 ( int V_26 , int V_27 ,
enum V_28 V_29 , T_3 V_30 ,
const char * V_31 , T_2 V_18 ,
const char * V_32 , T_2 V_8 )
{
struct V_6 * V_7 ;
T_1 V_20 , V_19 ;
T_2 V_22 = 0 ;
V_20 = F_13 ( V_8 , V_18 , & V_19 ) ;
if ( F_12 ( V_20 ) ) {
V_20 = F_14 ( & V_8 , & V_22 ,
& V_18 , & V_19 ) ;
if ( F_12 ( V_20 ) )
return 0 ;
}
if ( V_13 + V_20 + sizeof( struct V_6 ) > V_5 ) {
memset ( V_4 + V_13 , 0 , sizeof( struct V_6 ) ) ;
V_13 = 0 ;
}
V_7 = (struct V_6 * ) ( V_4 + V_13 ) ;
memcpy ( F_6 ( V_7 ) , V_32 , V_8 ) ;
V_7 -> V_8 = V_8 ;
if ( V_22 ) {
memcpy ( F_6 ( V_7 ) + V_8 , V_25 , V_22 ) ;
V_7 -> V_8 += V_22 ;
}
memcpy ( F_7 ( V_7 ) , V_31 , V_18 ) ;
V_7 -> V_18 = V_18 ;
V_7 -> V_26 = V_26 ;
V_7 -> V_27 = V_27 & 7 ;
V_7 -> V_29 = V_29 & 0x1f ;
if ( V_30 > 0 )
V_7 -> V_30 = V_30 ;
else
V_7 -> V_30 = F_16 () ;
memset ( F_7 ( V_7 ) + V_18 , 0 , V_19 ) ;
V_7 -> V_10 = V_20 ;
V_13 += V_7 -> V_10 ;
V_16 ++ ;
return V_7 -> V_8 ;
}
static int F_17 ( int type )
{
if ( V_33 )
return 1 ;
return type != V_34 &&
type != V_35 ;
}
int F_18 ( int type , int V_36 )
{
if ( V_36 == V_37 && type != V_38 )
goto V_39;
if ( F_17 ( type ) ) {
if ( F_19 ( V_40 ) )
goto V_39;
if ( F_19 ( V_41 ) ) {
F_20 ( L_1
L_2
L_3 ,
V_42 -> V_43 , F_21 ( V_42 ) ) ;
goto V_39;
}
return - V_44 ;
}
V_39:
return F_22 ( type ) ;
}
static void F_23 ( char * * V_45 , char * V_46 , char V_47 )
{
if ( * V_45 < V_46 )
* ( * V_45 ) ++ = V_47 ;
}
static T_4 F_24 ( char * V_48 , T_5 V_20 ,
struct V_6 * V_7 , T_3 V_49 ,
enum V_28 V_50 )
{
T_3 V_51 = V_7 -> V_30 ;
char V_52 = '-' ;
F_25 ( V_51 , 1000 ) ;
if ( V_7 -> V_29 & V_53 && ! ( V_50 & V_53 ) )
V_52 = 'c' ;
else if ( ( V_7 -> V_29 & V_53 ) ||
( ( V_50 & V_53 ) && ! ( V_7 -> V_29 & V_54 ) ) )
V_52 = '+' ;
return F_26 ( V_48 , V_20 , L_4 ,
( V_7 -> V_26 << 3 ) | V_7 -> V_27 , V_49 , V_51 , V_52 ) ;
}
static T_4 F_27 ( char * V_48 , T_5 V_20 ,
char * V_31 , T_5 V_18 ,
char * V_32 , T_5 V_8 )
{
char * V_55 = V_48 , * V_46 = V_48 + V_20 ;
T_5 V_56 ;
for ( V_56 = 0 ; V_56 < V_8 ; V_56 ++ ) {
unsigned char V_47 = V_32 [ V_56 ] ;
if ( V_47 < ' ' || V_47 >= 127 || V_47 == '\\' )
V_55 += F_26 ( V_55 , V_46 - V_55 , L_5 , V_47 ) ;
else
F_23 ( & V_55 , V_46 , V_47 ) ;
}
F_23 ( & V_55 , V_46 , '\n' ) ;
if ( V_18 ) {
bool line = true ;
for ( V_56 = 0 ; V_56 < V_18 ; V_56 ++ ) {
unsigned char V_47 = V_31 [ V_56 ] ;
if ( line ) {
F_23 ( & V_55 , V_46 , ' ' ) ;
line = false ;
}
if ( V_47 == '\0' ) {
F_23 ( & V_55 , V_46 , '\n' ) ;
line = true ;
continue;
}
if ( V_47 < ' ' || V_47 >= 127 || V_47 == '\\' ) {
V_55 += F_26 ( V_55 , V_46 - V_55 , L_5 , V_47 ) ;
continue;
}
F_23 ( & V_55 , V_46 , V_47 ) ;
}
F_23 ( & V_55 , V_46 , '\n' ) ;
}
return V_55 - V_48 ;
}
static T_4 F_28 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
char * V_48 , * line ;
int V_27 = V_61 ;
int V_26 = 1 ;
T_5 V_10 = F_29 ( V_60 ) ;
T_4 V_62 = V_10 ;
if ( V_10 > V_63 )
return - V_64 ;
V_48 = F_30 ( V_10 + 1 , V_65 ) ;
if ( V_48 == NULL )
return - V_17 ;
V_48 [ V_10 ] = '\0' ;
if ( F_31 ( V_48 , V_10 , V_60 ) != V_10 ) {
F_32 ( V_48 ) ;
return - V_66 ;
}
line = V_48 ;
if ( line [ 0 ] == '<' ) {
char * V_67 = NULL ;
unsigned int V_68 ;
V_68 = F_33 ( line + 1 , & V_67 , 10 ) ;
if ( V_67 && V_67 [ 0 ] == '>' ) {
V_27 = F_34 ( V_68 ) ;
if ( F_35 ( V_68 ) != 0 )
V_26 = F_35 ( V_68 ) ;
V_67 ++ ;
V_10 -= V_67 - line ;
line = V_67 ;
}
}
F_36 ( V_26 , V_27 , NULL , 0 , L_6 , line ) ;
F_32 ( V_48 ) ;
return V_62 ;
}
static T_4 F_37 ( struct V_69 * V_69 , char T_6 * V_48 ,
T_5 V_70 , T_7 * V_71 )
{
struct V_72 * V_73 = V_69 -> V_74 ;
struct V_6 * V_7 ;
T_5 V_10 ;
T_4 V_62 ;
if ( ! V_73 )
return - V_75 ;
V_62 = F_38 ( & V_73 -> V_76 ) ;
if ( V_62 )
return V_62 ;
F_39 ( & V_77 ) ;
while ( V_73 -> V_49 == V_16 ) {
if ( V_69 -> V_78 & V_79 ) {
V_62 = - V_80 ;
F_40 ( & V_77 ) ;
goto V_81;
}
F_40 ( & V_77 ) ;
V_62 = F_41 ( V_82 ,
V_73 -> V_49 != V_16 ) ;
if ( V_62 )
goto V_81;
F_39 ( & V_77 ) ;
}
if ( V_73 -> V_49 < V_15 ) {
V_73 -> V_9 = V_14 ;
V_73 -> V_49 = V_15 ;
V_62 = - V_83 ;
F_40 ( & V_77 ) ;
goto V_81;
}
V_7 = F_8 ( V_73 -> V_9 ) ;
V_10 = F_24 ( V_73 -> V_48 , sizeof( V_73 -> V_48 ) ,
V_7 , V_73 -> V_49 , V_73 -> V_84 ) ;
V_10 += F_27 ( V_73 -> V_48 + V_10 , sizeof( V_73 -> V_48 ) - V_10 ,
F_7 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_7 ) , V_7 -> V_8 ) ;
V_73 -> V_84 = V_7 -> V_29 ;
V_73 -> V_9 = F_9 ( V_73 -> V_9 ) ;
V_73 -> V_49 ++ ;
F_40 ( & V_77 ) ;
if ( V_10 > V_70 ) {
V_62 = - V_64 ;
goto V_81;
}
if ( F_42 ( V_48 , V_73 -> V_48 , V_10 ) ) {
V_62 = - V_66 ;
goto V_81;
}
V_62 = V_10 ;
V_81:
F_43 ( & V_73 -> V_76 ) ;
return V_62 ;
}
static T_7 F_44 ( struct V_69 * V_69 , T_7 V_85 , int V_86 )
{
struct V_72 * V_73 = V_69 -> V_74 ;
T_7 V_62 = 0 ;
if ( ! V_73 )
return - V_75 ;
if ( V_85 )
return - V_87 ;
F_39 ( & V_77 ) ;
switch ( V_86 ) {
case V_88 :
V_73 -> V_9 = V_14 ;
V_73 -> V_49 = V_15 ;
break;
case V_89 :
V_73 -> V_9 = V_90 ;
V_73 -> V_49 = V_91 ;
break;
case V_92 :
V_73 -> V_9 = V_13 ;
V_73 -> V_49 = V_16 ;
break;
default:
V_62 = - V_64 ;
}
F_40 ( & V_77 ) ;
return V_62 ;
}
static unsigned int F_45 ( struct V_69 * V_69 , T_8 * V_93 )
{
struct V_72 * V_73 = V_69 -> V_74 ;
int V_62 = 0 ;
if ( ! V_73 )
return V_94 | V_95 ;
F_46 ( V_69 , & V_82 , V_93 ) ;
F_39 ( & V_77 ) ;
if ( V_73 -> V_49 < V_16 ) {
if ( V_73 -> V_49 < V_15 )
V_62 = V_96 | V_97 | V_94 | V_98 ;
else
V_62 = V_96 | V_97 ;
}
F_40 ( & V_77 ) ;
return V_62 ;
}
static int F_47 ( struct V_99 * V_99 , struct V_69 * V_69 )
{
struct V_72 * V_73 ;
int V_100 ;
if ( ( V_69 -> V_78 & V_101 ) == V_102 )
return 0 ;
V_100 = F_18 ( V_34 ,
V_103 ) ;
if ( V_100 )
return V_100 ;
V_73 = F_30 ( sizeof( struct V_72 ) , V_65 ) ;
if ( ! V_73 )
return - V_17 ;
F_48 ( & V_73 -> V_76 ) ;
F_39 ( & V_77 ) ;
V_73 -> V_9 = V_14 ;
V_73 -> V_49 = V_15 ;
F_40 ( & V_77 ) ;
V_69 -> V_74 = V_73 ;
return 0 ;
}
static int F_49 ( struct V_99 * V_99 , struct V_69 * V_69 )
{
struct V_72 * V_73 = V_69 -> V_74 ;
if ( ! V_73 )
return 0 ;
F_50 ( & V_73 -> V_76 ) ;
F_32 ( V_73 ) ;
return 0 ;
}
void F_51 ( void )
{
F_52 ( V_4 ) ;
F_52 ( V_5 ) ;
F_52 ( V_14 ) ;
F_52 ( V_13 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 , V_30 ) ;
F_54 ( V_6 , V_10 ) ;
F_54 ( V_6 , V_8 ) ;
F_54 ( V_6 , V_18 ) ;
}
static void T_9 F_55 ( unsigned V_20 )
{
if ( V_20 )
V_20 = F_56 ( V_20 ) ;
if ( V_20 > V_5 )
V_104 = V_20 ;
}
static int T_9 F_57 ( char * V_105 )
{
unsigned V_20 = F_58 ( V_105 , & V_105 ) ;
F_55 ( V_20 ) ;
return 0 ;
}
static void T_9 F_59 ( void )
{
unsigned int V_106 ;
if ( F_60 () == 1 )
return;
V_106 = ( F_60 () - 1 ) * V_107 ;
if ( V_106 <= V_108 / 2 )
return;
F_61 ( L_7 ,
V_107 ) ;
F_61 ( L_8 ,
V_106 ) ;
F_61 ( L_9 , V_108 ) ;
F_55 ( V_106 + V_108 ) ;
}
static inline void F_59 ( void ) {}
void T_9 F_62 ( int V_109 )
{
unsigned long V_29 ;
char * V_110 ;
int free ;
if ( V_4 != V_111 )
return;
if ( ! V_109 && ! V_104 )
F_59 () ;
if ( ! V_104 )
return;
if ( V_109 ) {
V_110 =
F_63 ( V_104 , V_21 ) ;
} else {
V_110 = F_64 ( V_104 ,
V_21 ) ;
}
if ( F_65 ( ! V_110 ) ) {
F_66 ( L_10 ,
V_104 ) ;
return;
}
F_67 ( & V_77 , V_29 ) ;
V_5 = V_104 ;
V_4 = V_110 ;
V_104 = 0 ;
free = V_108 - V_13 ;
memcpy ( V_4 , V_111 , V_108 ) ;
F_68 ( & V_77 , V_29 ) ;
F_61 ( L_11 , V_5 ) ;
F_61 ( L_12 ,
free , ( free * 100 ) / V_108 ) ;
}
static int T_9 F_69 ( char * V_105 )
{
V_112 = true ;
F_61 ( L_13 ) ;
return 0 ;
}
static int T_9 F_70 ( char * V_105 )
{
unsigned long V_113 ;
V_113 = V_114 ? V_114 : 1000000 ;
V_115 = ( unsigned long long ) V_113 / 1000 * V_116 ;
F_71 ( & V_105 , & V_117 ) ;
if ( V_117 > 10 * 1000 )
V_117 = 0 ;
F_72 ( L_14
L_15 ,
V_117 , V_114 , V_113 , V_116 , V_115 ) ;
return 0 ;
}
static void F_73 ( int V_27 )
{
unsigned long long V_118 ;
unsigned long V_119 ;
if ( ( V_117 == 0 || V_120 != V_121 )
|| ( V_27 >= V_122 && ! V_112 ) ) {
return;
}
V_118 = ( unsigned long long ) V_115 * V_117 ;
V_119 = V_123 + F_74 ( V_117 ) ;
while ( V_118 ) {
V_118 -- ;
F_75 () ;
if ( F_76 ( V_123 , V_119 ) )
break;
F_77 () ;
}
}
static inline void F_73 ( int V_27 )
{
}
static T_5 F_78 ( T_3 V_124 , char * V_48 )
{
unsigned long V_125 ;
if ( ! V_126 )
return 0 ;
V_125 = F_25 ( V_124 , 1000000000 ) ;
if ( ! V_48 )
return snprintf ( NULL , 0 , L_16 , ( unsigned long ) V_124 ) ;
return sprintf ( V_48 , L_17 ,
( unsigned long ) V_124 , V_125 / 1000 ) ;
}
static T_5 F_79 ( const struct V_6 * V_7 , bool V_127 , char * V_48 )
{
T_5 V_10 = 0 ;
unsigned int V_128 = ( V_7 -> V_26 << 3 ) | V_7 -> V_27 ;
if ( V_127 ) {
if ( V_48 ) {
V_10 += sprintf ( V_48 , L_18 , V_128 ) ;
} else {
V_10 += 3 ;
if ( V_128 > 999 )
V_10 += 3 ;
else if ( V_128 > 99 )
V_10 += 2 ;
else if ( V_128 > 9 )
V_10 ++ ;
}
}
V_10 += F_78 ( V_7 -> V_30 , V_48 ? V_48 + V_10 : NULL ) ;
return V_10 ;
}
static T_5 F_80 ( const struct V_6 * V_7 , enum V_28 V_84 ,
bool V_127 , char * V_48 , T_5 V_20 )
{
const char * V_32 = F_6 ( V_7 ) ;
T_5 V_129 = V_7 -> V_8 ;
bool V_128 = true ;
bool V_130 = true ;
T_5 V_10 = 0 ;
if ( ( V_84 & V_53 ) && ! ( V_7 -> V_29 & V_54 ) )
V_128 = false ;
if ( V_7 -> V_29 & V_53 ) {
if ( ( V_84 & V_53 ) && ! ( V_84 & V_131 ) )
V_128 = false ;
if ( ! ( V_7 -> V_29 & V_131 ) )
V_130 = false ;
}
do {
const char * V_132 = memchr ( V_32 , '\n' , V_129 ) ;
T_5 V_8 ;
if ( V_132 ) {
V_8 = V_132 - V_32 ;
V_132 ++ ;
V_129 -= V_132 - V_32 ;
} else {
V_8 = V_129 ;
}
if ( V_48 ) {
if ( F_79 ( V_7 , V_127 , NULL ) +
V_8 + 1 >= V_20 - V_10 )
break;
if ( V_128 )
V_10 += F_79 ( V_7 , V_127 , V_48 + V_10 ) ;
memcpy ( V_48 + V_10 , V_32 , V_8 ) ;
V_10 += V_8 ;
if ( V_132 || V_130 )
V_48 [ V_10 ++ ] = '\n' ;
} else {
if ( V_128 )
V_10 += F_79 ( V_7 , V_127 , NULL ) ;
V_10 += V_8 ;
if ( V_132 || V_130 )
V_10 ++ ;
}
V_128 = true ;
V_32 = V_132 ;
} while ( V_32 );
return V_10 ;
}
static int F_81 ( char T_6 * V_48 , int V_20 )
{
char * V_32 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
V_32 = F_30 ( V_63 + V_133 , V_65 ) ;
if ( ! V_32 )
return - V_17 ;
while ( V_20 > 0 ) {
T_5 V_134 ;
T_5 V_135 ;
F_39 ( & V_77 ) ;
if ( V_136 < V_15 ) {
V_136 = V_15 ;
V_137 = V_14 ;
V_138 = 0 ;
V_139 = 0 ;
}
if ( V_136 == V_16 ) {
F_40 ( & V_77 ) ;
break;
}
V_135 = V_139 ;
V_7 = F_8 ( V_137 ) ;
V_134 = F_80 ( V_7 , V_138 , true , V_32 ,
V_63 + V_133 ) ;
if ( V_134 - V_139 <= V_20 ) {
V_137 = F_9 ( V_137 ) ;
V_136 ++ ;
V_138 = V_7 -> V_29 ;
V_134 -= V_139 ;
V_139 = 0 ;
} else if ( ! V_10 ) {
V_134 = V_20 ;
V_139 += V_134 ;
} else
V_134 = 0 ;
F_40 ( & V_77 ) ;
if ( ! V_134 )
break;
if ( F_42 ( V_48 , V_32 + V_135 , V_134 ) ) {
if ( ! V_10 )
V_10 = - V_66 ;
break;
}
V_10 += V_134 ;
V_20 -= V_134 ;
V_48 += V_134 ;
}
F_32 ( V_32 ) ;
return V_10 ;
}
static int F_82 ( char T_6 * V_48 , int V_20 , bool V_140 )
{
char * V_32 ;
int V_10 = 0 ;
V_32 = F_30 ( V_63 + V_133 , V_65 ) ;
if ( ! V_32 )
return - V_17 ;
F_39 ( & V_77 ) ;
if ( V_48 ) {
T_3 V_141 ;
T_3 V_49 ;
T_1 V_9 ;
enum V_28 V_84 ;
if ( V_91 < V_15 ) {
V_91 = V_15 ;
V_90 = V_14 ;
}
V_49 = V_91 ;
V_9 = V_90 ;
V_84 = 0 ;
while ( V_49 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 += F_80 ( V_7 , V_84 , true , NULL , 0 ) ;
V_84 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
}
V_49 = V_91 ;
V_9 = V_90 ;
V_84 = 0 ;
while ( V_10 > V_20 && V_49 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 -= F_80 ( V_7 , V_84 , true , NULL , 0 ) ;
V_84 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
}
V_141 = V_16 ;
V_10 = 0 ;
while ( V_10 >= 0 && V_49 < V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
int V_142 ;
V_142 = F_80 ( V_7 , V_84 , true , V_32 ,
V_63 + V_133 ) ;
if ( V_142 < 0 ) {
V_10 = V_142 ;
break;
}
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_84 = V_7 -> V_29 ;
F_40 ( & V_77 ) ;
if ( F_42 ( V_48 + V_10 , V_32 , V_142 ) )
V_10 = - V_66 ;
else
V_10 += V_142 ;
F_39 ( & V_77 ) ;
if ( V_49 < V_15 ) {
V_49 = V_15 ;
V_9 = V_14 ;
V_84 = 0 ;
}
}
}
if ( V_140 ) {
V_91 = V_16 ;
V_90 = V_13 ;
}
F_40 ( & V_77 ) ;
F_32 ( V_32 ) ;
return V_10 ;
}
int F_83 ( int type , char T_6 * V_48 , int V_10 , int V_36 )
{
bool V_140 = false ;
static int V_143 = V_144 ;
int error ;
error = F_18 ( type , V_36 ) ;
if ( error )
goto V_81;
switch ( type ) {
case V_145 :
break;
case V_38 :
break;
case V_146 :
error = - V_64 ;
if ( ! V_48 || V_10 < 0 )
goto V_81;
error = 0 ;
if ( ! V_10 )
goto V_81;
if ( ! F_84 ( V_147 , V_48 , V_10 ) ) {
error = - V_66 ;
goto V_81;
}
error = F_41 ( V_82 ,
V_136 != V_16 ) ;
if ( error )
goto V_81;
error = F_81 ( V_48 , V_10 ) ;
break;
case V_148 :
V_140 = true ;
case V_34 :
error = - V_64 ;
if ( ! V_48 || V_10 < 0 )
goto V_81;
error = 0 ;
if ( ! V_10 )
goto V_81;
if ( ! F_84 ( V_147 , V_48 , V_10 ) ) {
error = - V_66 ;
goto V_81;
}
error = F_82 ( V_48 , V_10 , V_140 ) ;
break;
case V_149 :
F_82 ( NULL , 0 , true ) ;
break;
case V_150 :
if ( V_143 == V_144 )
V_143 = V_122 ;
V_122 = V_151 ;
break;
case V_152 :
if ( V_143 != V_144 ) {
V_122 = V_143 ;
V_143 = V_144 ;
}
break;
case V_153 :
error = - V_64 ;
if ( V_10 < 1 || V_10 > 8 )
goto V_81;
if ( V_10 < V_151 )
V_10 = V_151 ;
V_122 = V_10 ;
V_143 = V_144 ;
error = 0 ;
break;
case V_154 :
F_39 ( & V_77 ) ;
if ( V_136 < V_15 ) {
V_136 = V_15 ;
V_137 = V_14 ;
V_138 = 0 ;
V_139 = 0 ;
}
if ( V_36 == V_37 ) {
error = V_16 - V_136 ;
} else {
T_3 V_49 = V_136 ;
T_1 V_9 = V_137 ;
enum V_28 V_84 = V_138 ;
error = 0 ;
while ( V_49 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
error += F_80 ( V_7 , V_84 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_84 = V_7 -> V_29 ;
}
error -= V_139 ;
}
F_40 ( & V_77 ) ;
break;
case V_35 :
error = V_5 ;
break;
default:
error = - V_64 ;
break;
}
V_81:
return error ;
}
static void F_85 ( int V_27 ,
const char * V_155 , T_5 V_156 ,
const char * V_32 , T_5 V_10 )
{
struct V_157 * V_158 ;
F_86 ( V_32 , V_10 ) ;
if ( V_27 >= V_122 && ! V_112 )
return;
if ( ! V_159 )
return;
F_87 (con) {
if ( V_160 && V_158 != V_160 )
continue;
if ( ! ( V_158 -> V_29 & V_161 ) )
continue;
if ( ! V_158 -> V_162 )
continue;
if ( ! F_88 ( F_89 () ) &&
! ( V_158 -> V_29 & V_163 ) )
continue;
if ( V_158 -> V_29 & V_164 )
V_158 -> V_162 ( V_158 , V_155 , V_156 ) ;
else
V_158 -> V_162 ( V_158 , V_32 , V_10 ) ;
}
}
static void F_90 ( void )
{
static unsigned long V_165 ;
if ( F_91 ( V_123 , V_165 ) &&
! F_76 ( V_123 , V_165 + 30 * V_116 ) )
return;
V_165 = V_123 ;
F_92 () ;
F_93 ( & V_77 ) ;
F_94 ( & V_2 , 1 ) ;
}
static int F_95 ( void )
{
struct V_157 * V_158 ;
F_87 (con)
if ( V_158 -> V_29 & V_163 )
return 1 ;
return 0 ;
}
static inline int F_96 ( unsigned int V_166 )
{
return F_88 ( V_166 ) || F_95 () ;
}
static int F_97 ( void )
{
unsigned int V_166 = F_89 () ;
if ( ! F_98 () )
return 0 ;
if ( ! F_96 ( V_166 ) ) {
V_167 = 0 ;
F_99 () ;
return 0 ;
}
return 1 ;
}
static inline void F_100 ( void )
{
if ( F_65 ( V_168 ) ) {
int V_169 = V_168 ;
while ( V_169 -- ) {
F_101 ( 1 ) ;
F_77 () ;
}
}
}
static void F_102 ( enum V_28 V_29 )
{
if ( V_52 . V_170 )
return;
if ( V_52 . V_10 == 0 )
return;
if ( V_52 . V_171 ) {
F_15 ( V_52 . V_26 , V_52 . V_27 , V_29 | V_172 ,
V_52 . V_30 , NULL , 0 , V_52 . V_48 , V_52 . V_10 ) ;
V_52 . V_29 = V_29 ;
V_52 . V_170 = true ;
} else {
F_15 ( V_52 . V_26 , V_52 . V_27 , V_29 , 0 ,
NULL , 0 , V_52 . V_48 , V_52 . V_10 ) ;
V_52 . V_10 = 0 ;
}
}
static bool F_103 ( int V_26 , int V_27 , const char * V_32 , T_5 V_10 )
{
if ( V_52 . V_10 && V_52 . V_170 )
return false ;
if ( V_173 || V_52 . V_10 + V_10 > sizeof( V_52 . V_48 ) ) {
F_102 ( V_53 ) ;
return false ;
}
if ( ! V_52 . V_10 ) {
V_52 . V_26 = V_26 ;
V_52 . V_27 = V_27 ;
V_52 . V_174 = V_42 ;
V_52 . V_30 = F_16 () ;
V_52 . V_29 = 0 ;
V_52 . V_171 = 0 ;
V_52 . V_170 = false ;
}
memcpy ( V_52 . V_48 + V_52 . V_10 , V_32 , V_10 ) ;
V_52 . V_10 += V_10 ;
if ( V_52 . V_10 > ( sizeof( V_52 . V_48 ) * 80 ) / 100 )
F_102 ( V_53 ) ;
return true ;
}
static T_5 F_104 ( char * V_32 , T_5 V_20 )
{
T_5 V_142 = 0 ;
T_5 V_10 ;
if ( V_52 . V_171 == 0 && ( V_175 & V_131 ) ) {
V_142 += F_78 ( V_52 . V_30 , V_32 ) ;
V_20 -= V_142 ;
}
V_10 = V_52 . V_10 - V_52 . V_171 ;
if ( V_10 > 0 ) {
if ( V_10 + 1 > V_20 )
V_10 = V_20 - 1 ;
memcpy ( V_32 + V_142 , V_52 . V_48 + V_52 . V_171 , V_10 ) ;
V_142 += V_10 ;
V_52 . V_171 = V_52 . V_10 ;
}
if ( V_52 . V_170 ) {
if ( V_52 . V_29 & V_131 )
V_32 [ V_142 ++ ] = '\n' ;
V_52 . V_10 = 0 ;
}
return V_142 ;
}
T_10 int F_105 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_176 ,
const char * V_177 , T_11 args )
{
static int V_178 ;
static char V_179 [ V_63 ] ;
char * V_32 = V_179 ;
T_5 V_8 = 0 ;
enum V_28 V_180 = 0 ;
unsigned long V_29 ;
int V_181 ;
int V_182 = 0 ;
bool V_183 = false ;
static unsigned int V_184 = V_185 ;
if ( V_27 == V_186 ) {
V_27 = V_144 ;
V_183 = true ;
}
F_73 ( V_27 ) ;
F_100 () ;
F_106 ( V_29 ) ;
V_181 = F_89 () ;
if ( F_65 ( V_184 == V_181 ) ) {
if ( ! V_187 && ! F_107 ( V_42 ) ) {
V_178 = 1 ;
F_108 ( V_29 ) ;
return 0 ;
}
F_90 () ;
}
F_109 () ;
F_110 ( & V_77 ) ;
V_184 = V_181 ;
if ( F_65 ( V_178 ) ) {
static const char V_188 [] =
L_19 ;
V_178 = 0 ;
V_182 += F_15 ( 0 , 2 , V_54 | V_131 , 0 ,
NULL , 0 , V_188 ,
strlen ( V_188 ) ) ;
}
V_8 = F_111 ( V_32 , sizeof( V_179 ) , V_177 , args ) ;
if ( V_8 && V_32 [ V_8 - 1 ] == '\n' ) {
V_8 -- ;
V_180 |= V_131 ;
}
if ( V_26 == 0 ) {
int V_189 = F_112 ( V_32 ) ;
if ( V_189 ) {
const char * V_190 = F_113 ( V_32 ) ;
switch ( V_189 ) {
case '0' ... '7' :
if ( V_27 == V_144 )
V_27 = V_189 - '0' ;
case 'd' :
V_180 |= V_54 ;
}
V_8 -= V_190 - V_32 ;
V_32 = ( char * ) V_190 ;
}
}
if ( V_27 == V_144 )
V_27 = V_61 ;
if ( V_31 )
V_180 |= V_54 | V_131 ;
if ( ! ( V_180 & V_131 ) ) {
if ( V_52 . V_10 && ( V_180 & V_54 || V_52 . V_174 != V_42 ) )
F_102 ( V_131 ) ;
if ( F_103 ( V_26 , V_27 , V_32 , V_8 ) )
V_182 += V_8 ;
else
V_182 += F_15 ( V_26 , V_27 ,
V_180 | V_53 , 0 ,
V_31 , V_176 , V_32 , V_8 ) ;
} else {
bool V_191 = false ;
if ( V_52 . V_10 ) {
if ( V_52 . V_174 == V_42 && ! ( V_180 & V_54 ) )
V_191 = F_103 ( V_26 , V_27 , V_32 ,
V_8 ) ;
F_102 ( V_131 ) ;
}
if ( V_191 )
V_182 += V_8 ;
else
V_182 += F_15 ( V_26 , V_27 , V_180 , 0 ,
V_31 , V_176 , V_32 , V_8 ) ;
}
V_184 = V_185 ;
F_114 ( & V_77 ) ;
F_115 () ;
F_108 ( V_29 ) ;
if ( ! V_183 ) {
F_109 () ;
F_116 () ;
if ( F_97 () )
F_117 () ;
F_118 () ;
F_115 () ;
}
return V_182 ;
}
T_10 int F_119 ( const char * V_177 , T_11 args )
{
return F_105 ( 0 , V_144 , NULL , 0 , V_177 , args ) ;
}
T_10 int F_36 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_176 ,
const char * V_177 , ... )
{
T_11 args ;
int V_192 ;
va_start ( args , V_177 ) ;
V_192 = F_105 ( V_26 , V_27 , V_31 , V_176 , V_177 , args ) ;
va_end ( args ) ;
return V_192 ;
}
int F_120 ( const char * V_177 , T_11 args )
{
int V_192 ;
#ifdef F_121
if ( F_65 ( V_193 ) ) {
V_192 = F_122 ( V_194 , V_177 , args ) ;
return V_192 ;
}
#endif
V_192 = F_105 ( 0 , V_144 , NULL , 0 , V_177 , args ) ;
return V_192 ;
}
T_10 T_12 int F_123 ( const char * V_177 , ... )
{
T_13 V_195 ;
T_11 args ;
int V_192 ;
va_start ( args , V_177 ) ;
V_195 = F_124 ( V_196 ) ;
V_192 = V_195 ( V_177 , args ) ;
va_end ( args ) ;
return V_192 ;
}
static char * F_6 ( const struct V_6 * V_7 ) { return NULL ; }
static char * F_7 ( const struct V_6 * V_7 ) { return NULL ; }
static struct V_6 * F_8 ( T_1 V_9 ) { return NULL ; }
static T_1 F_9 ( T_1 V_9 ) { return 0 ; }
static T_4 F_24 ( char * V_48 , T_5 V_20 ,
struct V_6 * V_7 , T_3 V_49 ,
enum V_28 V_50 ) { return 0 ; }
static T_4 F_27 ( char * V_48 , T_5 V_20 ,
char * V_31 , T_5 V_18 ,
char * V_32 , T_5 V_8 ) { return 0 ; }
static void F_85 ( int V_27 ,
const char * V_155 , T_5 V_156 ,
const char * V_32 , T_5 V_10 ) {}
static T_5 F_80 ( const struct V_6 * V_7 , enum V_28 V_84 ,
bool V_127 , char * V_48 , T_5 V_20 ) { return 0 ; }
static T_5 F_104 ( char * V_32 , T_5 V_20 ) { return 0 ; }
T_10 T_12 void F_125 ( const char * V_177 , ... )
{
T_11 V_197 ;
char V_48 [ 512 ] ;
int V_134 ;
if ( ! V_198 )
return;
va_start ( V_197 , V_177 ) ;
V_134 = F_111 ( V_48 , sizeof( V_48 ) , V_177 , V_197 ) ;
va_end ( V_197 ) ;
V_198 -> V_162 ( V_198 , V_48 , V_134 ) ;
}
static int F_126 ( char * V_199 , int V_9 , char * V_200 ,
char * V_201 )
{
struct V_202 * V_47 ;
int V_56 ;
for ( V_56 = 0 , V_47 = V_202 ;
V_56 < V_203 && V_47 -> V_199 [ 0 ] ;
V_56 ++ , V_47 ++ ) {
if ( strcmp ( V_47 -> V_199 , V_199 ) == 0 && V_47 -> V_204 == V_9 ) {
if ( ! V_201 )
V_205 = V_56 ;
return 0 ;
}
}
if ( V_56 == V_203 )
return - V_206 ;
if ( ! V_201 )
V_205 = V_56 ;
F_127 ( V_47 -> V_199 , V_199 , sizeof( V_47 -> V_199 ) ) ;
V_47 -> V_200 = V_200 ;
F_128 ( V_47 , V_201 ) ;
V_47 -> V_204 = V_9 ;
return 0 ;
}
static int T_9 F_129 ( char * V_105 )
{
char V_48 [ sizeof( V_202 [ 0 ] . V_199 ) + 4 ] ;
char * V_207 , * V_200 , * V_201 = NULL ;
int V_9 ;
if ( F_130 ( & V_105 , & V_201 ) )
return 1 ;
if ( V_105 [ 0 ] >= '0' && V_105 [ 0 ] <= '9' ) {
strcpy ( V_48 , L_20 ) ;
strncpy ( V_48 + 4 , V_105 , sizeof( V_48 ) - 5 ) ;
} else {
strncpy ( V_48 , V_105 , sizeof( V_48 ) - 1 ) ;
}
V_48 [ sizeof( V_48 ) - 1 ] = 0 ;
V_200 = strchr ( V_105 , ',' ) ;
if ( V_200 )
* ( V_200 ++ ) = 0 ;
#ifdef F_131
if ( ! strcmp ( V_105 , L_21 ) )
strcpy ( V_48 , L_22 ) ;
if ( ! strcmp ( V_105 , L_23 ) )
strcpy ( V_48 , L_24 ) ;
#endif
for ( V_207 = V_48 ; * V_207 ; V_207 ++ )
if ( isdigit ( * V_207 ) || * V_207 == ',' )
break;
V_9 = F_33 ( V_207 , NULL , 10 ) ;
* V_207 = 0 ;
F_126 ( V_48 , V_9 , V_200 , V_201 ) ;
V_208 = 1 ;
return 1 ;
}
int F_132 ( char * V_199 , int V_9 , char * V_200 )
{
return F_126 ( V_199 , V_9 , V_200 , NULL ) ;
}
static int T_9 F_133 ( char * V_105 )
{
V_209 = false ;
return 1 ;
}
void F_134 ( void )
{
if ( ! V_209 )
return;
F_123 ( L_25 ) ;
F_135 () ;
V_210 = 1 ;
F_99 () ;
}
void F_136 ( void )
{
if ( ! V_209 )
return;
F_137 () ;
V_210 = 0 ;
F_117 () ;
}
static int F_138 ( struct V_211 * V_212 ,
unsigned long V_213 , void * V_214 )
{
switch ( V_213 ) {
case V_215 :
case V_216 :
case V_217 :
case V_218 :
F_135 () ;
F_117 () ;
}
return V_219 ;
}
void F_135 ( void )
{
F_139 () ;
F_137 () ;
if ( V_210 )
return;
V_167 = 1 ;
V_220 = 1 ;
}
int F_98 ( void )
{
if ( F_140 () )
return 0 ;
if ( V_210 ) {
F_99 () ;
return 0 ;
}
V_167 = 1 ;
V_220 = 0 ;
return 1 ;
}
int F_141 ( void )
{
return V_167 ;
}
static void F_142 ( char * V_32 , T_5 V_20 )
{
unsigned long V_29 ;
T_5 V_10 ;
F_67 ( & V_77 , V_29 ) ;
if ( ! V_52 . V_10 )
goto V_81;
if ( V_221 < V_16 && ! V_52 . V_171 )
goto V_81;
V_10 = F_104 ( V_32 , V_20 ) ;
F_114 ( & V_77 ) ;
F_143 () ;
F_85 ( V_52 . V_27 , NULL , 0 , V_32 , V_10 ) ;
F_144 () ;
F_108 ( V_29 ) ;
return;
V_81:
F_68 ( & V_77 , V_29 ) ;
}
void F_117 ( void )
{
static char V_155 [ V_222 ] ;
static char V_32 [ V_63 + V_133 ] ;
static T_3 V_223 ;
unsigned long V_29 ;
bool V_224 = false ;
bool V_225 ;
if ( V_210 ) {
F_99 () ;
return;
}
V_220 = 0 ;
F_142 ( V_32 , sizeof( V_32 ) ) ;
V_226:
for (; ; ) {
struct V_6 * V_7 ;
T_5 V_156 = 0 ;
T_5 V_10 ;
int V_27 ;
F_67 ( & V_77 , V_29 ) ;
if ( V_223 != V_16 ) {
V_224 = true ;
V_223 = V_16 ;
}
if ( V_221 < V_15 ) {
V_10 = sprintf ( V_32 , L_26 ,
( unsigned ) ( V_15 - V_221 ) ) ;
V_221 = V_15 ;
V_227 = V_14 ;
V_175 = 0 ;
} else {
V_10 = 0 ;
}
V_135:
if ( V_221 == V_16 )
break;
V_7 = F_8 ( V_227 ) ;
if ( V_7 -> V_29 & V_172 ) {
V_227 = F_9 ( V_227 ) ;
V_221 ++ ;
V_7 -> V_29 &= ~ V_172 ;
V_175 = V_7 -> V_29 ;
goto V_135;
}
V_27 = V_7 -> V_27 ;
V_10 += F_80 ( V_7 , V_175 , false ,
V_32 + V_10 , sizeof( V_32 ) - V_10 ) ;
if ( V_173 ) {
V_156 = F_24 ( V_155 ,
sizeof( V_155 ) ,
V_7 , V_221 , V_175 ) ;
V_156 += F_27 ( V_155 + V_156 ,
sizeof( V_155 ) - V_156 ,
F_7 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_7 ) , V_7 -> V_8 ) ;
}
V_227 = F_9 ( V_227 ) ;
V_221 ++ ;
V_175 = V_7 -> V_29 ;
F_114 ( & V_77 ) ;
F_143 () ;
F_85 ( V_27 , V_155 , V_156 , V_32 , V_10 ) ;
F_144 () ;
F_108 ( V_29 ) ;
}
V_167 = 0 ;
if ( F_65 ( V_160 ) )
V_160 = NULL ;
F_114 ( & V_77 ) ;
F_99 () ;
F_110 ( & V_77 ) ;
V_225 = V_221 != V_16 ;
F_68 ( & V_77 , V_29 ) ;
if ( V_225 && F_98 () )
goto V_226;
if ( V_224 )
F_145 () ;
}
void T_14 F_146 ( void )
{
if ( V_220 )
F_147 () ;
}
void F_148 ( void )
{
struct V_157 * V_47 ;
if ( V_187 ) {
if ( F_140 () != 0 )
return;
} else
F_135 () ;
V_167 = 1 ;
V_220 = 0 ;
F_87 (c)
if ( ( V_47 -> V_29 & V_161 ) && V_47 -> V_228 )
V_47 -> V_228 () ;
F_117 () ;
}
struct V_229 * F_149 ( int * V_204 )
{
struct V_157 * V_47 ;
struct V_229 * V_230 = NULL ;
F_135 () ;
F_87 (c) {
if ( ! V_47 -> V_231 )
continue;
V_230 = V_47 -> V_231 ( V_47 , V_204 ) ;
if ( V_230 )
break;
}
F_117 () ;
return V_230 ;
}
void F_150 ( struct V_157 * V_157 )
{
F_135 () ;
V_157 -> V_29 &= ~ V_161 ;
F_117 () ;
}
void F_151 ( struct V_157 * V_157 )
{
F_135 () ;
V_157 -> V_29 |= V_161 ;
F_117 () ;
}
static int T_9 F_152 ( char * V_105 )
{
V_232 = 1 ;
F_61 ( L_27 ) ;
return 0 ;
}
void F_153 ( struct V_157 * V_233 )
{
int V_56 ;
unsigned long V_29 ;
struct V_157 * V_234 = NULL ;
struct V_202 * V_47 ;
if ( V_159 )
F_87 (bcon)
if ( F_154 ( V_234 == V_233 ,
L_28 ,
V_234 -> V_199 , V_234 -> V_204 ) )
return;
if ( V_159 && V_233 -> V_29 & V_235 ) {
F_87 (bcon) {
if ( ! ( V_234 -> V_29 & V_235 ) ) {
F_61 ( L_29 ,
V_233 -> V_199 , V_233 -> V_204 ) ;
return;
}
}
}
if ( V_159 && V_159 -> V_29 & V_235 )
V_234 = V_159 ;
if ( V_236 < 0 || V_234 || ! V_159 )
V_236 = V_205 ;
if ( V_236 < 0 ) {
if ( V_233 -> V_204 < 0 )
V_233 -> V_204 = 0 ;
if ( V_233 -> V_237 == NULL ||
V_233 -> V_237 ( V_233 , NULL ) == 0 ) {
V_233 -> V_29 |= V_161 ;
if ( V_233 -> V_231 ) {
V_233 -> V_29 |= V_238 ;
V_236 = 0 ;
}
}
}
for ( V_56 = 0 , V_47 = V_202 ;
V_56 < V_203 && V_47 -> V_199 [ 0 ] ;
V_56 ++ , V_47 ++ ) {
if ( ! V_233 -> V_239 ||
V_233 -> V_239 ( V_233 , V_47 -> V_199 , V_47 -> V_204 , V_47 -> V_200 ) != 0 ) {
F_155 ( sizeof( V_47 -> V_199 ) != sizeof( V_233 -> V_199 ) ) ;
if ( strcmp ( V_47 -> V_199 , V_233 -> V_199 ) != 0 )
continue;
if ( V_233 -> V_204 >= 0 &&
V_233 -> V_204 != V_47 -> V_204 )
continue;
if ( V_233 -> V_204 < 0 )
V_233 -> V_204 = V_47 -> V_204 ;
if ( F_156 ( V_233 , V_47 ) )
return;
if ( V_233 -> V_237 &&
V_233 -> V_237 ( V_233 , V_47 -> V_200 ) != 0 )
break;
}
V_233 -> V_29 |= V_161 ;
if ( V_56 == V_205 ) {
V_233 -> V_29 |= V_238 ;
V_236 = V_205 ;
}
break;
}
if ( ! ( V_233 -> V_29 & V_161 ) )
return;
if ( V_234 && ( ( V_233 -> V_29 & ( V_238 | V_235 ) ) == V_238 ) )
V_233 -> V_29 &= ~ V_240 ;
F_135 () ;
if ( ( V_233 -> V_29 & V_238 ) || V_159 == NULL ) {
V_233 -> V_132 = V_159 ;
V_159 = V_233 ;
if ( V_233 -> V_132 )
V_233 -> V_132 -> V_29 &= ~ V_238 ;
} else {
V_233 -> V_132 = V_159 -> V_132 ;
V_159 -> V_132 = V_233 ;
}
if ( V_233 -> V_29 & V_164 )
if ( ! V_173 ++ )
F_61 ( L_30 ) ;
if ( V_233 -> V_29 & V_240 ) {
F_67 ( & V_77 , V_29 ) ;
V_221 = V_136 ;
V_227 = V_137 ;
V_175 = V_138 ;
F_68 ( & V_77 , V_29 ) ;
V_160 = V_233 ;
}
F_117 () ;
F_157 () ;
F_61 ( L_31 ,
( V_233 -> V_29 & V_235 ) ? L_32 : L_33 ,
V_233 -> V_199 , V_233 -> V_204 ) ;
if ( V_234 &&
( ( V_233 -> V_29 & ( V_238 | V_235 ) ) == V_238 ) &&
! V_232 ) {
F_87 (bcon)
if ( V_234 -> V_29 & V_235 )
F_158 ( V_234 ) ;
}
}
int F_158 ( struct V_157 * V_157 )
{
struct V_157 * V_241 , * V_242 ;
int V_243 ;
F_61 ( L_34 ,
( V_157 -> V_29 & V_235 ) ? L_32 : L_33 ,
V_157 -> V_199 , V_157 -> V_204 ) ;
V_243 = F_159 ( V_157 ) ;
if ( V_243 )
return V_243 ;
V_243 = 1 ;
F_135 () ;
if ( V_159 == V_157 ) {
V_159 = V_157 -> V_132 ;
V_243 = 0 ;
} else if ( V_159 ) {
for ( V_241 = V_159 -> V_132 , V_242 = V_159 ;
V_241 ; V_242 = V_241 , V_241 = V_242 -> V_132 ) {
if ( V_241 == V_157 ) {
V_242 -> V_132 = V_241 -> V_132 ;
V_243 = 0 ;
break;
}
}
}
if ( ! V_243 && ( V_157 -> V_29 & V_164 ) )
V_173 -- ;
if ( V_159 != NULL && V_157 -> V_29 & V_238 )
V_159 -> V_29 |= V_238 ;
V_157 -> V_29 &= ~ V_161 ;
F_117 () ;
F_157 () ;
return V_243 ;
}
static int T_9 F_160 ( void )
{
struct V_157 * V_158 ;
F_87 (con) {
if ( ! V_232 && V_158 -> V_29 & V_235 ) {
F_158 ( V_158 ) ;
}
}
F_161 ( F_138 , 0 ) ;
return 0 ;
}
static void F_162 ( struct V_244 * V_244 )
{
int V_245 = F_163 ( V_246 , 0 ) ;
if ( V_245 & V_247 ) {
if ( F_98 () )
F_117 () ;
}
if ( V_245 & V_248 )
F_164 ( & V_82 ) ;
}
void F_145 ( void )
{
F_116 () ;
if ( F_165 ( & V_82 ) ) {
F_166 ( V_246 , V_248 ) ;
F_167 ( F_168 ( & V_249 ) ) ;
}
F_118 () ;
}
int F_169 ( const char * V_177 , ... )
{
T_11 args ;
int V_192 ;
F_116 () ;
va_start ( args , V_177 ) ;
V_192 = F_105 ( 0 , V_186 , NULL , 0 , V_177 , args ) ;
va_end ( args ) ;
F_170 ( V_246 , V_247 ) ;
F_167 ( F_168 ( & V_249 ) ) ;
F_118 () ;
return V_192 ;
}
int F_171 ( const char * V_250 )
{
return F_172 ( & V_251 , V_250 ) ;
}
bool F_173 ( unsigned long * V_252 ,
unsigned int V_253 )
{
unsigned long V_254 = V_123 - * V_252 ;
if ( * V_252 && V_254 <= F_74 ( V_253 ) )
return false ;
* V_252 = V_123 ;
return true ;
}
int F_174 ( struct V_255 * V_256 )
{
unsigned long V_29 ;
int V_100 = - V_257 ;
if ( ! V_256 -> V_258 )
return - V_64 ;
F_175 ( & V_259 , V_29 ) ;
if ( ! V_256 -> V_260 ) {
V_256 -> V_260 = 1 ;
F_176 ( & V_256 -> V_261 , & V_262 ) ;
V_100 = 0 ;
}
F_177 ( & V_259 , V_29 ) ;
return V_100 ;
}
int F_178 ( struct V_255 * V_256 )
{
unsigned long V_29 ;
int V_100 = - V_64 ;
F_175 ( & V_259 , V_29 ) ;
if ( V_256 -> V_260 ) {
V_256 -> V_260 = 0 ;
F_179 ( & V_256 -> V_261 ) ;
V_100 = 0 ;
}
F_177 ( & V_259 , V_29 ) ;
F_180 () ;
return V_100 ;
}
void F_181 ( enum V_263 V_264 )
{
struct V_255 * V_256 ;
unsigned long V_29 ;
if ( ( V_264 > V_265 ) && ! V_266 )
return;
F_182 () ;
F_183 (dumper, &dump_list, list) {
if ( V_256 -> V_267 && V_264 > V_256 -> V_267 )
continue;
V_256 -> V_268 = true ;
F_67 ( & V_77 , V_29 ) ;
V_256 -> V_269 = V_91 ;
V_256 -> V_270 = V_90 ;
V_256 -> V_141 = V_16 ;
V_256 -> V_271 = V_13 ;
F_68 ( & V_77 , V_29 ) ;
V_256 -> V_258 ( V_256 , V_264 ) ;
V_256 -> V_268 = false ;
}
F_184 () ;
}
bool F_185 ( struct V_255 * V_256 , bool V_127 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
struct V_6 * V_7 ;
T_5 V_272 = 0 ;
bool V_62 = false ;
if ( ! V_256 -> V_268 )
goto V_81;
if ( V_256 -> V_269 < V_15 ) {
V_256 -> V_269 = V_15 ;
V_256 -> V_270 = V_14 ;
}
if ( V_256 -> V_269 >= V_16 )
goto V_81;
V_7 = F_8 ( V_256 -> V_270 ) ;
V_272 = F_80 ( V_7 , 0 , V_127 , line , V_20 ) ;
V_256 -> V_270 = F_9 ( V_256 -> V_270 ) ;
V_256 -> V_269 ++ ;
V_62 = true ;
V_81:
if ( V_10 )
* V_10 = V_272 ;
return V_62 ;
}
bool F_186 ( struct V_255 * V_256 , bool V_127 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
bool V_62 ;
F_67 ( & V_77 , V_29 ) ;
V_62 = F_185 ( V_256 , V_127 , line , V_20 , V_10 ) ;
F_68 ( & V_77 , V_29 ) ;
return V_62 ;
}
bool F_187 ( struct V_255 * V_256 , bool V_127 ,
char * V_48 , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
T_3 V_49 ;
T_1 V_9 ;
T_3 V_141 ;
T_1 V_271 ;
enum V_28 V_84 ;
T_5 V_272 = 0 ;
bool V_62 = false ;
if ( ! V_256 -> V_268 )
goto V_81;
F_67 ( & V_77 , V_29 ) ;
if ( V_256 -> V_269 < V_15 ) {
V_256 -> V_269 = V_15 ;
V_256 -> V_270 = V_14 ;
}
if ( V_256 -> V_269 >= V_256 -> V_141 ) {
F_68 ( & V_77 , V_29 ) ;
goto V_81;
}
V_49 = V_256 -> V_269 ;
V_9 = V_256 -> V_270 ;
V_84 = 0 ;
while ( V_49 < V_256 -> V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_272 += F_80 ( V_7 , V_84 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_84 = V_7 -> V_29 ;
}
V_49 = V_256 -> V_269 ;
V_9 = V_256 -> V_270 ;
V_84 = 0 ;
while ( V_272 > V_20 && V_49 < V_256 -> V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_272 -= F_80 ( V_7 , V_84 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_84 = V_7 -> V_29 ;
}
V_141 = V_49 ;
V_271 = V_9 ;
V_272 = 0 ;
while ( V_49 < V_256 -> V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_272 += F_80 ( V_7 , V_84 , V_127 , V_48 + V_272 , V_20 - V_272 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_84 = V_7 -> V_29 ;
}
V_256 -> V_141 = V_141 ;
V_256 -> V_271 = V_271 ;
V_62 = true ;
F_68 ( & V_77 , V_29 ) ;
V_81:
if ( V_10 )
* V_10 = V_272 ;
return V_62 ;
}
void F_188 ( struct V_255 * V_256 )
{
V_256 -> V_269 = V_91 ;
V_256 -> V_270 = V_90 ;
V_256 -> V_141 = V_16 ;
V_256 -> V_271 = V_13 ;
}
void F_189 ( struct V_255 * V_256 )
{
unsigned long V_29 ;
F_67 ( & V_77 , V_29 ) ;
F_188 ( V_256 ) ;
F_68 ( & V_77 , V_29 ) ;
}
void T_9 F_190 ( const char * V_177 , ... )
{
T_11 args ;
va_start ( args , V_177 ) ;
vsnprintf ( V_273 , sizeof( V_273 ) ,
V_177 , args ) ;
va_end ( args ) ;
}
void F_191 ( const char * V_274 )
{
F_123 ( L_35 ,
V_274 , F_192 () , V_42 -> V_275 , V_42 -> V_43 ,
F_193 () , F_194 () -> V_276 ,
( int ) strcspn ( F_194 () -> V_277 , L_36 ) ,
F_194 () -> V_277 ) ;
if ( V_273 [ 0 ] != '\0' )
F_123 ( L_37 ,
V_274 , V_273 ) ;
F_195 ( V_274 , V_42 ) ;
}
void F_196 ( const char * V_274 )
{
F_191 ( V_274 ) ;
F_123 ( L_38 ,
V_274 , V_42 , F_197 () ,
F_198 ( V_42 ) ) ;
}
