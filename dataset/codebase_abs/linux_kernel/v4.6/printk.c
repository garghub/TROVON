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
while ( V_15 < V_16 &&
! F_10 ( V_11 , false ) ) {
V_14 = F_9 ( V_14 ) ;
V_15 ++ ;
}
if ( V_17 < V_15 ) {
V_17 = V_15 ;
V_18 = V_14 ;
}
if ( F_10 ( V_11 , V_15 == V_16 ) )
return 0 ;
return - V_19 ;
}
static T_1 F_13 ( T_2 V_8 , T_2 V_20 , T_1 * V_21 )
{
T_1 V_22 ;
V_22 = sizeof( struct V_6 ) + V_8 + V_20 ;
* V_21 = ( - V_22 ) & ( V_23 - 1 ) ;
V_22 += * V_21 ;
return V_22 ;
}
static T_1 F_14 ( T_2 * V_8 , T_2 * V_24 ,
T_2 * V_20 , T_1 * V_21 )
{
T_1 V_25 = V_5 / V_26 ;
if ( * V_8 > V_25 )
* V_8 = V_25 ;
* V_24 = strlen ( V_27 ) ;
* V_20 = 0 ;
return F_13 ( * V_8 + * V_24 , 0 , V_21 ) ;
}
static int F_15 ( int V_28 , int V_29 ,
enum V_30 V_31 , T_3 V_32 ,
const char * V_33 , T_2 V_20 ,
const char * V_34 , T_2 V_8 )
{
struct V_6 * V_7 ;
T_1 V_22 , V_21 ;
T_2 V_24 = 0 ;
V_22 = F_13 ( V_8 , V_20 , & V_21 ) ;
if ( F_12 ( V_22 ) ) {
V_22 = F_14 ( & V_8 , & V_24 ,
& V_20 , & V_21 ) ;
if ( F_12 ( V_22 ) )
return 0 ;
}
if ( V_13 + V_22 + sizeof( struct V_6 ) > V_5 ) {
memset ( V_4 + V_13 , 0 , sizeof( struct V_6 ) ) ;
V_13 = 0 ;
}
V_7 = (struct V_6 * ) ( V_4 + V_13 ) ;
memcpy ( F_6 ( V_7 ) , V_34 , V_8 ) ;
V_7 -> V_8 = V_8 ;
if ( V_24 ) {
memcpy ( F_6 ( V_7 ) + V_8 , V_27 , V_24 ) ;
V_7 -> V_8 += V_24 ;
}
memcpy ( F_7 ( V_7 ) , V_33 , V_20 ) ;
V_7 -> V_20 = V_20 ;
V_7 -> V_28 = V_28 ;
V_7 -> V_29 = V_29 & 7 ;
V_7 -> V_31 = V_31 & 0x1f ;
if ( V_32 > 0 )
V_7 -> V_32 = V_32 ;
else
V_7 -> V_32 = F_16 () ;
memset ( F_7 ( V_7 ) + V_20 , 0 , V_21 ) ;
V_7 -> V_10 = V_22 ;
V_13 += V_7 -> V_10 ;
V_16 ++ ;
return V_7 -> V_8 ;
}
static int F_17 ( int type )
{
if ( V_35 )
return 1 ;
return type != V_36 &&
type != V_37 ;
}
int F_18 ( int type , int V_38 )
{
if ( V_38 == V_39 && type != V_40 )
goto V_41;
if ( F_17 ( type ) ) {
if ( F_19 ( V_42 ) )
goto V_41;
if ( F_19 ( V_43 ) ) {
F_20 ( L_1
L_2
L_3 ,
V_44 -> V_45 , F_21 ( V_44 ) ) ;
goto V_41;
}
return - V_46 ;
}
V_41:
return F_22 ( type ) ;
}
static void F_23 ( char * * V_47 , char * V_48 , char V_49 )
{
if ( * V_47 < V_48 )
* ( * V_47 ) ++ = V_49 ;
}
static T_4 F_24 ( char * V_50 , T_5 V_22 ,
struct V_6 * V_7 , T_3 V_51 ,
enum V_30 V_52 )
{
T_3 V_53 = V_7 -> V_32 ;
char V_54 = '-' ;
F_25 ( V_53 , 1000 ) ;
if ( V_7 -> V_31 & V_55 && ! ( V_52 & V_55 ) )
V_54 = 'c' ;
else if ( ( V_7 -> V_31 & V_55 ) ||
( ( V_52 & V_55 ) && ! ( V_7 -> V_31 & V_56 ) ) )
V_54 = '+' ;
return F_26 ( V_50 , V_22 , L_4 ,
( V_7 -> V_28 << 3 ) | V_7 -> V_29 , V_51 , V_53 , V_54 ) ;
}
static T_4 F_27 ( char * V_50 , T_5 V_22 ,
char * V_33 , T_5 V_20 ,
char * V_34 , T_5 V_8 )
{
char * V_57 = V_50 , * V_48 = V_50 + V_22 ;
T_5 V_58 ;
for ( V_58 = 0 ; V_58 < V_8 ; V_58 ++ ) {
unsigned char V_49 = V_34 [ V_58 ] ;
if ( V_49 < ' ' || V_49 >= 127 || V_49 == '\\' )
V_57 += F_26 ( V_57 , V_48 - V_57 , L_5 , V_49 ) ;
else
F_23 ( & V_57 , V_48 , V_49 ) ;
}
F_23 ( & V_57 , V_48 , '\n' ) ;
if ( V_20 ) {
bool line = true ;
for ( V_58 = 0 ; V_58 < V_20 ; V_58 ++ ) {
unsigned char V_49 = V_33 [ V_58 ] ;
if ( line ) {
F_23 ( & V_57 , V_48 , ' ' ) ;
line = false ;
}
if ( V_49 == '\0' ) {
F_23 ( & V_57 , V_48 , '\n' ) ;
line = true ;
continue;
}
if ( V_49 < ' ' || V_49 >= 127 || V_49 == '\\' ) {
V_57 += F_26 ( V_57 , V_48 - V_57 , L_5 , V_49 ) ;
continue;
}
F_23 ( & V_57 , V_48 , V_49 ) ;
}
F_23 ( & V_57 , V_48 , '\n' ) ;
}
return V_57 - V_50 ;
}
static T_4 F_28 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
char * V_50 , * line ;
int V_29 = V_63 ;
int V_28 = 1 ;
T_5 V_10 = F_29 ( V_62 ) ;
T_4 V_64 = V_10 ;
if ( V_10 > V_65 )
return - V_66 ;
V_50 = F_30 ( V_10 + 1 , V_67 ) ;
if ( V_50 == NULL )
return - V_19 ;
V_50 [ V_10 ] = '\0' ;
if ( F_31 ( V_50 , V_10 , V_62 ) != V_10 ) {
F_32 ( V_50 ) ;
return - V_68 ;
}
line = V_50 ;
if ( line [ 0 ] == '<' ) {
char * V_69 = NULL ;
unsigned int V_70 ;
V_70 = F_33 ( line + 1 , & V_69 , 10 ) ;
if ( V_69 && V_69 [ 0 ] == '>' ) {
V_29 = F_34 ( V_70 ) ;
if ( F_35 ( V_70 ) != 0 )
V_28 = F_35 ( V_70 ) ;
V_69 ++ ;
V_10 -= V_69 - line ;
line = V_69 ;
}
}
F_36 ( V_28 , V_29 , NULL , 0 , L_6 , line ) ;
F_32 ( V_50 ) ;
return V_64 ;
}
static T_4 F_37 ( struct V_71 * V_71 , char T_6 * V_50 ,
T_5 V_72 , T_7 * V_73 )
{
struct V_74 * V_75 = V_71 -> V_76 ;
struct V_6 * V_7 ;
T_5 V_10 ;
T_4 V_64 ;
if ( ! V_75 )
return - V_77 ;
V_64 = F_38 ( & V_75 -> V_78 ) ;
if ( V_64 )
return V_64 ;
F_39 ( & V_79 ) ;
while ( V_75 -> V_51 == V_16 ) {
if ( V_71 -> V_80 & V_81 ) {
V_64 = - V_82 ;
F_40 ( & V_79 ) ;
goto V_83;
}
F_40 ( & V_79 ) ;
V_64 = F_41 ( V_84 ,
V_75 -> V_51 != V_16 ) ;
if ( V_64 )
goto V_83;
F_39 ( & V_79 ) ;
}
if ( V_75 -> V_51 < V_15 ) {
V_75 -> V_9 = V_14 ;
V_75 -> V_51 = V_15 ;
V_64 = - V_85 ;
F_40 ( & V_79 ) ;
goto V_83;
}
V_7 = F_8 ( V_75 -> V_9 ) ;
V_10 = F_24 ( V_75 -> V_50 , sizeof( V_75 -> V_50 ) ,
V_7 , V_75 -> V_51 , V_75 -> V_86 ) ;
V_10 += F_27 ( V_75 -> V_50 + V_10 , sizeof( V_75 -> V_50 ) - V_10 ,
F_7 ( V_7 ) , V_7 -> V_20 ,
F_6 ( V_7 ) , V_7 -> V_8 ) ;
V_75 -> V_86 = V_7 -> V_31 ;
V_75 -> V_9 = F_9 ( V_75 -> V_9 ) ;
V_75 -> V_51 ++ ;
F_40 ( & V_79 ) ;
if ( V_10 > V_72 ) {
V_64 = - V_66 ;
goto V_83;
}
if ( F_42 ( V_50 , V_75 -> V_50 , V_10 ) ) {
V_64 = - V_68 ;
goto V_83;
}
V_64 = V_10 ;
V_83:
F_43 ( & V_75 -> V_78 ) ;
return V_64 ;
}
static T_7 F_44 ( struct V_71 * V_71 , T_7 V_87 , int V_88 )
{
struct V_74 * V_75 = V_71 -> V_76 ;
T_7 V_64 = 0 ;
if ( ! V_75 )
return - V_77 ;
if ( V_87 )
return - V_89 ;
F_39 ( & V_79 ) ;
switch ( V_88 ) {
case V_90 :
V_75 -> V_9 = V_14 ;
V_75 -> V_51 = V_15 ;
break;
case V_91 :
V_75 -> V_9 = V_18 ;
V_75 -> V_51 = V_17 ;
break;
case V_92 :
V_75 -> V_9 = V_13 ;
V_75 -> V_51 = V_16 ;
break;
default:
V_64 = - V_66 ;
}
F_40 ( & V_79 ) ;
return V_64 ;
}
static unsigned int F_45 ( struct V_71 * V_71 , T_8 * V_93 )
{
struct V_74 * V_75 = V_71 -> V_76 ;
int V_64 = 0 ;
if ( ! V_75 )
return V_94 | V_95 ;
F_46 ( V_71 , & V_84 , V_93 ) ;
F_39 ( & V_79 ) ;
if ( V_75 -> V_51 < V_16 ) {
if ( V_75 -> V_51 < V_15 )
V_64 = V_96 | V_97 | V_94 | V_98 ;
else
V_64 = V_96 | V_97 ;
}
F_40 ( & V_79 ) ;
return V_64 ;
}
static int F_47 ( struct V_99 * V_99 , struct V_71 * V_71 )
{
struct V_74 * V_75 ;
int V_100 ;
if ( ( V_71 -> V_80 & V_101 ) == V_102 )
return 0 ;
V_100 = F_18 ( V_36 ,
V_103 ) ;
if ( V_100 )
return V_100 ;
V_75 = F_30 ( sizeof( struct V_74 ) , V_67 ) ;
if ( ! V_75 )
return - V_19 ;
F_48 ( & V_75 -> V_78 ) ;
F_39 ( & V_79 ) ;
V_75 -> V_9 = V_14 ;
V_75 -> V_51 = V_15 ;
F_40 ( & V_79 ) ;
V_71 -> V_76 = V_75 ;
return 0 ;
}
static int F_49 ( struct V_99 * V_99 , struct V_71 * V_71 )
{
struct V_74 * V_75 = V_71 -> V_76 ;
if ( ! V_75 )
return 0 ;
F_50 ( & V_75 -> V_78 ) ;
F_32 ( V_75 ) ;
return 0 ;
}
void F_51 ( void )
{
F_52 ( V_4 ) ;
F_52 ( V_5 ) ;
F_52 ( V_14 ) ;
F_52 ( V_18 ) ;
F_52 ( V_13 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 , V_32 ) ;
F_54 ( V_6 , V_10 ) ;
F_54 ( V_6 , V_8 ) ;
F_54 ( V_6 , V_20 ) ;
}
static void T_9 F_55 ( unsigned V_22 )
{
if ( V_22 )
V_22 = F_56 ( V_22 ) ;
if ( V_22 > V_5 )
V_104 = V_22 ;
}
static int T_9 F_57 ( char * V_105 )
{
unsigned V_22 = F_58 ( V_105 , & V_105 ) ;
F_55 ( V_22 ) ;
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
unsigned long V_31 ;
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
F_63 ( V_104 , V_23 ) ;
} else {
V_110 = F_64 ( V_104 ,
V_23 ) ;
}
if ( F_65 ( ! V_110 ) ) {
F_66 ( L_10 ,
V_104 ) ;
return;
}
F_67 ( & V_79 , V_31 ) ;
V_5 = V_104 ;
V_4 = V_110 ;
V_104 = 0 ;
free = V_108 - V_13 ;
memcpy ( V_4 , V_111 , V_108 ) ;
F_68 ( & V_79 , V_31 ) ;
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
static void F_73 ( int V_29 )
{
unsigned long long V_118 ;
unsigned long V_119 ;
if ( ( V_117 == 0 || V_120 != V_121 )
|| ( V_29 >= V_122 && ! V_112 ) ) {
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
static inline void F_73 ( int V_29 )
{
}
static T_5 F_78 ( T_3 V_124 , char * V_50 )
{
unsigned long V_125 ;
if ( ! V_126 )
return 0 ;
V_125 = F_25 ( V_124 , 1000000000 ) ;
if ( ! V_50 )
return snprintf ( NULL , 0 , L_16 , ( unsigned long ) V_124 ) ;
return sprintf ( V_50 , L_17 ,
( unsigned long ) V_124 , V_125 / 1000 ) ;
}
static T_5 F_79 ( const struct V_6 * V_7 , bool V_127 , char * V_50 )
{
T_5 V_10 = 0 ;
unsigned int V_128 = ( V_7 -> V_28 << 3 ) | V_7 -> V_29 ;
if ( V_127 ) {
if ( V_50 ) {
V_10 += sprintf ( V_50 , L_18 , V_128 ) ;
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
V_10 += F_78 ( V_7 -> V_32 , V_50 ? V_50 + V_10 : NULL ) ;
return V_10 ;
}
static T_5 F_80 ( const struct V_6 * V_7 , enum V_30 V_86 ,
bool V_127 , char * V_50 , T_5 V_22 )
{
const char * V_34 = F_6 ( V_7 ) ;
T_5 V_129 = V_7 -> V_8 ;
bool V_128 = true ;
bool V_130 = true ;
T_5 V_10 = 0 ;
if ( ( V_86 & V_55 ) && ! ( V_7 -> V_31 & V_56 ) )
V_128 = false ;
if ( V_7 -> V_31 & V_55 ) {
if ( ( V_86 & V_55 ) && ! ( V_86 & V_131 ) )
V_128 = false ;
if ( ! ( V_7 -> V_31 & V_131 ) )
V_130 = false ;
}
do {
const char * V_132 = memchr ( V_34 , '\n' , V_129 ) ;
T_5 V_8 ;
if ( V_132 ) {
V_8 = V_132 - V_34 ;
V_132 ++ ;
V_129 -= V_132 - V_34 ;
} else {
V_8 = V_129 ;
}
if ( V_50 ) {
if ( F_79 ( V_7 , V_127 , NULL ) +
V_8 + 1 >= V_22 - V_10 )
break;
if ( V_128 )
V_10 += F_79 ( V_7 , V_127 , V_50 + V_10 ) ;
memcpy ( V_50 + V_10 , V_34 , V_8 ) ;
V_10 += V_8 ;
if ( V_132 || V_130 )
V_50 [ V_10 ++ ] = '\n' ;
} else {
if ( V_128 )
V_10 += F_79 ( V_7 , V_127 , NULL ) ;
V_10 += V_8 ;
if ( V_132 || V_130 )
V_10 ++ ;
}
V_128 = true ;
V_34 = V_132 ;
} while ( V_34 );
return V_10 ;
}
static int F_81 ( char T_6 * V_50 , int V_22 )
{
char * V_34 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
V_34 = F_30 ( V_65 + V_133 , V_67 ) ;
if ( ! V_34 )
return - V_19 ;
while ( V_22 > 0 ) {
T_5 V_134 ;
T_5 V_135 ;
F_39 ( & V_79 ) ;
if ( V_136 < V_15 ) {
V_136 = V_15 ;
V_137 = V_14 ;
V_138 = 0 ;
V_139 = 0 ;
}
if ( V_136 == V_16 ) {
F_40 ( & V_79 ) ;
break;
}
V_135 = V_139 ;
V_7 = F_8 ( V_137 ) ;
V_134 = F_80 ( V_7 , V_138 , true , V_34 ,
V_65 + V_133 ) ;
if ( V_134 - V_139 <= V_22 ) {
V_137 = F_9 ( V_137 ) ;
V_136 ++ ;
V_138 = V_7 -> V_31 ;
V_134 -= V_139 ;
V_139 = 0 ;
} else if ( ! V_10 ) {
V_134 = V_22 ;
V_139 += V_134 ;
} else
V_134 = 0 ;
F_40 ( & V_79 ) ;
if ( ! V_134 )
break;
if ( F_42 ( V_50 , V_34 + V_135 , V_134 ) ) {
if ( ! V_10 )
V_10 = - V_68 ;
break;
}
V_10 += V_134 ;
V_22 -= V_134 ;
V_50 += V_134 ;
}
F_32 ( V_34 ) ;
return V_10 ;
}
static int F_82 ( char T_6 * V_50 , int V_22 , bool V_140 )
{
char * V_34 ;
int V_10 = 0 ;
V_34 = F_30 ( V_65 + V_133 , V_67 ) ;
if ( ! V_34 )
return - V_19 ;
F_39 ( & V_79 ) ;
if ( V_50 ) {
T_3 V_141 ;
T_3 V_51 ;
T_1 V_9 ;
enum V_30 V_86 ;
V_51 = V_17 ;
V_9 = V_18 ;
V_86 = 0 ;
while ( V_51 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 += F_80 ( V_7 , V_86 , true , NULL , 0 ) ;
V_86 = V_7 -> V_31 ;
V_9 = F_9 ( V_9 ) ;
V_51 ++ ;
}
V_51 = V_17 ;
V_9 = V_18 ;
V_86 = 0 ;
while ( V_10 > V_22 && V_51 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 -= F_80 ( V_7 , V_86 , true , NULL , 0 ) ;
V_86 = V_7 -> V_31 ;
V_9 = F_9 ( V_9 ) ;
V_51 ++ ;
}
V_141 = V_16 ;
V_10 = 0 ;
while ( V_10 >= 0 && V_51 < V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
int V_142 ;
V_142 = F_80 ( V_7 , V_86 , true , V_34 ,
V_65 + V_133 ) ;
if ( V_142 < 0 ) {
V_10 = V_142 ;
break;
}
V_9 = F_9 ( V_9 ) ;
V_51 ++ ;
V_86 = V_7 -> V_31 ;
F_40 ( & V_79 ) ;
if ( F_42 ( V_50 + V_10 , V_34 , V_142 ) )
V_10 = - V_68 ;
else
V_10 += V_142 ;
F_39 ( & V_79 ) ;
if ( V_51 < V_15 ) {
V_51 = V_15 ;
V_9 = V_14 ;
V_86 = 0 ;
}
}
}
if ( V_140 ) {
V_17 = V_16 ;
V_18 = V_13 ;
}
F_40 ( & V_79 ) ;
F_32 ( V_34 ) ;
return V_10 ;
}
int F_83 ( int type , char T_6 * V_50 , int V_10 , int V_38 )
{
bool V_140 = false ;
static int V_143 = V_144 ;
int error ;
error = F_18 ( type , V_38 ) ;
if ( error )
goto V_83;
switch ( type ) {
case V_145 :
break;
case V_40 :
break;
case V_146 :
error = - V_66 ;
if ( ! V_50 || V_10 < 0 )
goto V_83;
error = 0 ;
if ( ! V_10 )
goto V_83;
if ( ! F_84 ( V_147 , V_50 , V_10 ) ) {
error = - V_68 ;
goto V_83;
}
error = F_41 ( V_84 ,
V_136 != V_16 ) ;
if ( error )
goto V_83;
error = F_81 ( V_50 , V_10 ) ;
break;
case V_148 :
V_140 = true ;
case V_36 :
error = - V_66 ;
if ( ! V_50 || V_10 < 0 )
goto V_83;
error = 0 ;
if ( ! V_10 )
goto V_83;
if ( ! F_84 ( V_147 , V_50 , V_10 ) ) {
error = - V_68 ;
goto V_83;
}
error = F_82 ( V_50 , V_10 , V_140 ) ;
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
error = - V_66 ;
if ( V_10 < 1 || V_10 > 8 )
goto V_83;
if ( V_10 < V_151 )
V_10 = V_151 ;
V_122 = V_10 ;
V_143 = V_144 ;
error = 0 ;
break;
case V_154 :
F_39 ( & V_79 ) ;
if ( V_136 < V_15 ) {
V_136 = V_15 ;
V_137 = V_14 ;
V_138 = 0 ;
V_139 = 0 ;
}
if ( V_38 == V_39 ) {
error = V_16 - V_136 ;
} else {
T_3 V_51 = V_136 ;
T_1 V_9 = V_137 ;
enum V_30 V_86 = V_138 ;
error = 0 ;
while ( V_51 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
error += F_80 ( V_7 , V_86 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_51 ++ ;
V_86 = V_7 -> V_31 ;
}
error -= V_139 ;
}
F_40 ( & V_79 ) ;
break;
case V_37 :
error = V_5 ;
break;
default:
error = - V_66 ;
break;
}
V_83:
return error ;
}
static void F_85 ( int V_29 ,
const char * V_155 , T_5 V_156 ,
const char * V_34 , T_5 V_10 )
{
struct V_157 * V_158 ;
F_86 ( V_34 , V_10 ) ;
if ( V_29 >= V_122 && ! V_112 )
return;
if ( ! V_159 )
return;
F_87 (con) {
if ( V_160 && V_158 != V_160 )
continue;
if ( ! ( V_158 -> V_31 & V_161 ) )
continue;
if ( ! V_158 -> V_162 )
continue;
if ( ! F_88 ( F_89 () ) &&
! ( V_158 -> V_31 & V_163 ) )
continue;
if ( V_158 -> V_31 & V_164 )
V_158 -> V_162 ( V_158 , V_155 , V_156 ) ;
else
V_158 -> V_162 ( V_158 , V_34 , V_10 ) ;
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
F_93 ( & V_79 ) ;
F_94 ( & V_2 , 1 ) ;
}
static inline void F_95 ( void )
{
if ( F_65 ( V_166 ) ) {
int V_167 = V_166 ;
while ( V_167 -- ) {
F_96 ( 1 ) ;
F_77 () ;
}
}
}
static void F_97 ( enum V_30 V_31 )
{
if ( V_54 . V_168 )
return;
if ( V_54 . V_10 == 0 )
return;
if ( V_54 . V_169 ) {
F_15 ( V_54 . V_28 , V_54 . V_29 , V_31 | V_170 ,
V_54 . V_32 , NULL , 0 , V_54 . V_50 , V_54 . V_10 ) ;
V_54 . V_31 = V_31 ;
V_54 . V_168 = true ;
} else {
F_15 ( V_54 . V_28 , V_54 . V_29 , V_31 , 0 ,
NULL , 0 , V_54 . V_50 , V_54 . V_10 ) ;
V_54 . V_10 = 0 ;
}
}
static bool F_98 ( int V_28 , int V_29 , const char * V_34 , T_5 V_10 )
{
if ( V_54 . V_10 && V_54 . V_168 )
return false ;
if ( V_171 || V_54 . V_10 + V_10 > sizeof( V_54 . V_50 ) ) {
F_97 ( V_55 ) ;
return false ;
}
if ( ! V_54 . V_10 ) {
V_54 . V_28 = V_28 ;
V_54 . V_29 = V_29 ;
V_54 . V_172 = V_44 ;
V_54 . V_32 = F_16 () ;
V_54 . V_31 = 0 ;
V_54 . V_169 = 0 ;
V_54 . V_168 = false ;
}
memcpy ( V_54 . V_50 + V_54 . V_10 , V_34 , V_10 ) ;
V_54 . V_10 += V_10 ;
if ( V_54 . V_10 > ( sizeof( V_54 . V_50 ) * 80 ) / 100 )
F_97 ( V_55 ) ;
return true ;
}
static T_5 F_99 ( char * V_34 , T_5 V_22 )
{
T_5 V_142 = 0 ;
T_5 V_10 ;
if ( V_54 . V_169 == 0 && ( V_173 & V_131 ) ) {
V_142 += F_78 ( V_54 . V_32 , V_34 ) ;
V_22 -= V_142 ;
}
V_10 = V_54 . V_10 - V_54 . V_169 ;
if ( V_10 > 0 ) {
if ( V_10 + 1 > V_22 )
V_10 = V_22 - 1 ;
memcpy ( V_34 + V_142 , V_54 . V_50 + V_54 . V_169 , V_10 ) ;
V_142 += V_10 ;
V_54 . V_169 = V_54 . V_10 ;
}
if ( V_54 . V_168 ) {
if ( V_54 . V_31 & V_131 )
V_34 [ V_142 ++ ] = '\n' ;
V_54 . V_10 = 0 ;
}
return V_142 ;
}
T_10 int F_100 ( int V_28 , int V_29 ,
const char * V_33 , T_5 V_174 ,
const char * V_175 , T_11 args )
{
static bool V_176 ;
static char V_177 [ V_65 ] ;
char * V_34 = V_177 ;
T_5 V_8 = 0 ;
enum V_30 V_178 = 0 ;
unsigned long V_31 ;
int V_179 ;
int V_180 = 0 ;
bool V_181 = false ;
static unsigned int V_182 = V_183 ;
if ( V_29 == V_184 ) {
V_29 = V_144 ;
V_181 = true ;
}
F_73 ( V_29 ) ;
F_95 () ;
F_101 ( V_31 ) ;
V_179 = F_89 () ;
if ( F_65 ( V_182 == V_179 ) ) {
if ( ! V_185 && ! F_102 ( V_44 ) ) {
V_176 = true ;
F_103 ( V_31 ) ;
return 0 ;
}
F_90 () ;
}
F_104 () ;
F_105 ( & V_79 ) ;
V_182 = V_179 ;
if ( F_65 ( V_176 ) ) {
static const char V_186 [] =
L_19 ;
V_176 = false ;
V_180 += F_15 ( 0 , 2 , V_56 | V_131 , 0 ,
NULL , 0 , V_186 ,
strlen ( V_186 ) ) ;
}
V_8 = F_106 ( V_34 , sizeof( V_177 ) , V_175 , args ) ;
if ( V_8 && V_34 [ V_8 - 1 ] == '\n' ) {
V_8 -- ;
V_178 |= V_131 ;
}
if ( V_28 == 0 ) {
int V_187 = F_107 ( V_34 ) ;
if ( V_187 ) {
const char * V_188 = F_108 ( V_34 ) ;
switch ( V_187 ) {
case '0' ... '7' :
if ( V_29 == V_144 )
V_29 = V_187 - '0' ;
case 'd' :
V_178 |= V_56 ;
}
V_8 -= V_188 - V_34 ;
V_34 = ( char * ) V_188 ;
}
}
if ( V_29 == V_144 )
V_29 = V_63 ;
if ( V_33 )
V_178 |= V_56 | V_131 ;
if ( ! ( V_178 & V_131 ) ) {
if ( V_54 . V_10 && ( V_178 & V_56 || V_54 . V_172 != V_44 ) )
F_97 ( V_131 ) ;
if ( F_98 ( V_28 , V_29 , V_34 , V_8 ) )
V_180 += V_8 ;
else
V_180 += F_15 ( V_28 , V_29 ,
V_178 | V_55 , 0 ,
V_33 , V_174 , V_34 , V_8 ) ;
} else {
bool V_189 = false ;
if ( V_54 . V_10 ) {
if ( V_54 . V_172 == V_44 && ! ( V_178 & V_56 ) )
V_189 = F_98 ( V_28 , V_29 , V_34 ,
V_8 ) ;
F_97 ( V_131 ) ;
}
if ( V_189 )
V_180 += V_8 ;
else
V_180 += F_15 ( V_28 , V_29 , V_178 , 0 ,
V_33 , V_174 , V_34 , V_8 ) ;
}
V_182 = V_183 ;
F_109 ( & V_79 ) ;
F_110 () ;
F_103 ( V_31 ) ;
if ( ! V_181 ) {
F_104 () ;
if ( F_111 () )
F_112 () ;
F_110 () ;
}
return V_180 ;
}
T_10 int F_113 ( const char * V_175 , T_11 args )
{
return F_100 ( 0 , V_144 , NULL , 0 , V_175 , args ) ;
}
T_10 int F_36 ( int V_28 , int V_29 ,
const char * V_33 , T_5 V_174 ,
const char * V_175 , ... )
{
T_11 args ;
int V_190 ;
va_start ( args , V_175 ) ;
V_190 = F_100 ( V_28 , V_29 , V_33 , V_174 , V_175 , args ) ;
va_end ( args ) ;
return V_190 ;
}
int F_114 ( const char * V_175 , T_11 args )
{
int V_190 ;
#ifdef F_115
if ( F_65 ( V_191 ) ) {
V_190 = F_116 ( V_192 , V_175 , args ) ;
return V_190 ;
}
#endif
V_190 = F_100 ( 0 , V_144 , NULL , 0 , V_175 , args ) ;
return V_190 ;
}
T_10 T_12 int F_117 ( const char * V_175 , ... )
{
T_13 V_193 ;
T_11 args ;
int V_190 ;
va_start ( args , V_175 ) ;
V_193 = F_118 ( V_194 ) ;
V_190 = V_193 ( V_175 , args ) ;
va_end ( args ) ;
return V_190 ;
}
static char * F_6 ( const struct V_6 * V_7 ) { return NULL ; }
static char * F_7 ( const struct V_6 * V_7 ) { return NULL ; }
static struct V_6 * F_8 ( T_1 V_9 ) { return NULL ; }
static T_1 F_9 ( T_1 V_9 ) { return 0 ; }
static T_4 F_24 ( char * V_50 , T_5 V_22 ,
struct V_6 * V_7 , T_3 V_51 ,
enum V_30 V_52 ) { return 0 ; }
static T_4 F_27 ( char * V_50 , T_5 V_22 ,
char * V_33 , T_5 V_20 ,
char * V_34 , T_5 V_8 ) { return 0 ; }
static void F_85 ( int V_29 ,
const char * V_155 , T_5 V_156 ,
const char * V_34 , T_5 V_10 ) {}
static T_5 F_80 ( const struct V_6 * V_7 , enum V_30 V_86 ,
bool V_127 , char * V_50 , T_5 V_22 ) { return 0 ; }
static T_5 F_99 ( char * V_34 , T_5 V_22 ) { return 0 ; }
T_10 T_12 void F_119 ( const char * V_175 , ... )
{
T_11 V_195 ;
char V_50 [ 512 ] ;
int V_134 ;
if ( ! V_196 )
return;
va_start ( V_195 , V_175 ) ;
V_134 = F_106 ( V_50 , sizeof( V_50 ) , V_175 , V_195 ) ;
va_end ( V_195 ) ;
V_196 -> V_162 ( V_196 , V_50 , V_134 ) ;
}
static int F_120 ( char * V_197 , int V_9 , char * V_198 ,
char * V_199 )
{
struct V_200 * V_49 ;
int V_58 ;
for ( V_58 = 0 , V_49 = V_200 ;
V_58 < V_201 && V_49 -> V_197 [ 0 ] ;
V_58 ++ , V_49 ++ ) {
if ( strcmp ( V_49 -> V_197 , V_197 ) == 0 && V_49 -> V_202 == V_9 ) {
if ( ! V_199 )
V_203 = V_58 ;
return 0 ;
}
}
if ( V_58 == V_201 )
return - V_204 ;
if ( ! V_199 )
V_203 = V_58 ;
F_121 ( V_49 -> V_197 , V_197 , sizeof( V_49 -> V_197 ) ) ;
V_49 -> V_198 = V_198 ;
F_122 ( V_49 , V_199 ) ;
V_49 -> V_202 = V_9 ;
return 0 ;
}
static int T_9 F_123 ( char * V_105 )
{
char V_50 [ sizeof( V_200 [ 0 ] . V_197 ) + 4 ] ;
char * V_205 , * V_198 , * V_199 = NULL ;
int V_9 ;
if ( F_124 ( & V_105 , & V_199 ) )
return 1 ;
if ( V_105 [ 0 ] >= '0' && V_105 [ 0 ] <= '9' ) {
strcpy ( V_50 , L_20 ) ;
strncpy ( V_50 + 4 , V_105 , sizeof( V_50 ) - 5 ) ;
} else {
strncpy ( V_50 , V_105 , sizeof( V_50 ) - 1 ) ;
}
V_50 [ sizeof( V_50 ) - 1 ] = 0 ;
V_198 = strchr ( V_105 , ',' ) ;
if ( V_198 )
* ( V_198 ++ ) = 0 ;
#ifdef F_125
if ( ! strcmp ( V_105 , L_21 ) )
strcpy ( V_50 , L_22 ) ;
if ( ! strcmp ( V_105 , L_23 ) )
strcpy ( V_50 , L_24 ) ;
#endif
for ( V_205 = V_50 ; * V_205 ; V_205 ++ )
if ( isdigit ( * V_205 ) || * V_205 == ',' )
break;
V_9 = F_33 ( V_205 , NULL , 10 ) ;
* V_205 = 0 ;
F_120 ( V_50 , V_9 , V_198 , V_199 ) ;
V_206 = 1 ;
return 1 ;
}
int F_126 ( char * V_197 , int V_9 , char * V_198 )
{
return F_120 ( V_197 , V_9 , V_198 , NULL ) ;
}
static int T_9 F_127 ( char * V_105 )
{
V_207 = false ;
return 1 ;
}
void F_128 ( void )
{
if ( ! V_207 )
return;
F_117 ( L_25 ) ;
F_129 () ;
V_208 = 1 ;
F_130 () ;
}
void F_131 ( void )
{
if ( ! V_207 )
return;
F_132 () ;
V_208 = 0 ;
F_112 () ;
}
static int F_133 ( struct V_209 * V_210 ,
unsigned long V_211 , void * V_212 )
{
switch ( V_211 ) {
case V_213 :
case V_214 :
case V_215 :
case V_216 :
F_129 () ;
F_112 () ;
}
return V_217 ;
}
void F_129 ( void )
{
F_134 () ;
F_132 () ;
if ( V_208 )
return;
V_218 = 1 ;
V_219 = 1 ;
}
int F_111 ( void )
{
if ( F_135 () )
return 0 ;
if ( V_208 ) {
F_130 () ;
return 0 ;
}
V_218 = 1 ;
V_219 = ! V_185 &&
F_136 () &&
! F_137 () ;
return 1 ;
}
int F_138 ( void )
{
return V_218 ;
}
static int F_139 ( void )
{
struct V_157 * V_158 ;
F_87 (con)
if ( ( V_158 -> V_31 & V_161 ) &&
( V_158 -> V_31 & V_163 ) )
return 1 ;
return 0 ;
}
static inline int F_140 ( void )
{
return F_88 ( F_141 () ) || F_139 () ;
}
static void F_142 ( char * V_34 , T_5 V_22 )
{
unsigned long V_31 ;
T_5 V_10 ;
F_67 ( & V_79 , V_31 ) ;
if ( ! V_54 . V_10 )
goto V_83;
if ( V_220 < V_16 && ! V_54 . V_169 )
goto V_83;
V_10 = F_99 ( V_34 , V_22 ) ;
F_109 ( & V_79 ) ;
F_143 () ;
F_85 ( V_54 . V_29 , NULL , 0 , V_34 , V_10 ) ;
F_144 () ;
F_103 ( V_31 ) ;
return;
V_83:
F_68 ( & V_79 , V_31 ) ;
}
void F_112 ( void )
{
static char V_155 [ V_221 ] ;
static char V_34 [ V_65 + V_133 ] ;
static T_3 V_222 ;
unsigned long V_31 ;
bool V_223 = false ;
bool V_224 , V_225 ;
if ( V_208 ) {
F_130 () ;
return;
}
V_224 = V_219 ;
V_219 = 0 ;
V_226:
if ( ! F_140 () ) {
V_218 = 0 ;
F_130 () ;
return;
}
F_142 ( V_34 , sizeof( V_34 ) ) ;
for (; ; ) {
struct V_6 * V_7 ;
T_5 V_156 = 0 ;
T_5 V_10 ;
int V_29 ;
F_67 ( & V_79 , V_31 ) ;
if ( V_222 != V_16 ) {
V_223 = true ;
V_222 = V_16 ;
}
if ( V_220 < V_15 ) {
V_10 = sprintf ( V_34 , L_26 ,
( unsigned ) ( V_15 - V_220 ) ) ;
V_220 = V_15 ;
V_227 = V_14 ;
V_173 = 0 ;
} else {
V_10 = 0 ;
}
V_135:
if ( V_220 == V_16 )
break;
V_7 = F_8 ( V_227 ) ;
if ( V_7 -> V_31 & V_170 ) {
V_227 = F_9 ( V_227 ) ;
V_220 ++ ;
V_7 -> V_31 &= ~ V_170 ;
V_173 = V_7 -> V_31 ;
goto V_135;
}
V_29 = V_7 -> V_29 ;
V_10 += F_80 ( V_7 , V_173 , false ,
V_34 + V_10 , sizeof( V_34 ) - V_10 ) ;
if ( V_171 ) {
V_156 = F_24 ( V_155 ,
sizeof( V_155 ) ,
V_7 , V_220 , V_173 ) ;
V_156 += F_27 ( V_155 + V_156 ,
sizeof( V_155 ) - V_156 ,
F_7 ( V_7 ) , V_7 -> V_20 ,
F_6 ( V_7 ) , V_7 -> V_8 ) ;
}
V_227 = F_9 ( V_227 ) ;
V_220 ++ ;
V_173 = V_7 -> V_31 ;
F_109 ( & V_79 ) ;
F_143 () ;
F_85 ( V_29 , V_155 , V_156 , V_34 , V_10 ) ;
F_144 () ;
F_103 ( V_31 ) ;
if ( V_224 )
F_145 () ;
}
V_218 = 0 ;
if ( F_65 ( V_160 ) )
V_160 = NULL ;
F_109 ( & V_79 ) ;
F_130 () ;
F_105 ( & V_79 ) ;
V_225 = V_220 != V_16 ;
F_68 ( & V_79 , V_31 ) ;
if ( V_225 && F_111 () )
goto V_226;
if ( V_223 )
F_146 () ;
}
void T_14 F_147 ( void )
{
if ( V_219 )
F_145 () ;
}
void F_148 ( void )
{
struct V_157 * V_49 ;
if ( V_185 ) {
if ( F_135 () != 0 )
return;
} else
F_129 () ;
V_218 = 1 ;
V_219 = 0 ;
F_87 (c)
if ( ( V_49 -> V_31 & V_161 ) && V_49 -> V_228 )
V_49 -> V_228 () ;
F_112 () ;
}
void F_149 ( void )
{
F_111 () ;
V_219 = 0 ;
F_112 () ;
}
struct V_229 * F_150 ( int * V_202 )
{
struct V_157 * V_49 ;
struct V_229 * V_230 = NULL ;
F_129 () ;
F_87 (c) {
if ( ! V_49 -> V_231 )
continue;
V_230 = V_49 -> V_231 ( V_49 , V_202 ) ;
if ( V_230 )
break;
}
F_112 () ;
return V_230 ;
}
void F_151 ( struct V_157 * V_157 )
{
F_129 () ;
V_157 -> V_31 &= ~ V_161 ;
F_112 () ;
}
void F_152 ( struct V_157 * V_157 )
{
F_129 () ;
V_157 -> V_31 |= V_161 ;
F_112 () ;
}
static int T_9 F_153 ( char * V_105 )
{
V_232 = 1 ;
F_61 ( L_27 ) ;
return 0 ;
}
void F_154 ( struct V_157 * V_233 )
{
int V_58 ;
unsigned long V_31 ;
struct V_157 * V_234 = NULL ;
struct V_200 * V_49 ;
if ( V_159 )
F_87 (bcon)
if ( F_155 ( V_234 == V_233 ,
L_28 ,
V_234 -> V_197 , V_234 -> V_202 ) )
return;
if ( V_159 && V_233 -> V_31 & V_235 ) {
F_87 (bcon) {
if ( ! ( V_234 -> V_31 & V_235 ) ) {
F_61 ( L_29 ,
V_233 -> V_197 , V_233 -> V_202 ) ;
return;
}
}
}
if ( V_159 && V_159 -> V_31 & V_235 )
V_234 = V_159 ;
if ( V_236 < 0 || V_234 || ! V_159 )
V_236 = V_203 ;
if ( V_236 < 0 ) {
if ( V_233 -> V_202 < 0 )
V_233 -> V_202 = 0 ;
if ( V_233 -> V_237 == NULL ||
V_233 -> V_237 ( V_233 , NULL ) == 0 ) {
V_233 -> V_31 |= V_161 ;
if ( V_233 -> V_231 ) {
V_233 -> V_31 |= V_238 ;
V_236 = 0 ;
}
}
}
for ( V_58 = 0 , V_49 = V_200 ;
V_58 < V_201 && V_49 -> V_197 [ 0 ] ;
V_58 ++ , V_49 ++ ) {
if ( ! V_233 -> V_239 ||
V_233 -> V_239 ( V_233 , V_49 -> V_197 , V_49 -> V_202 , V_49 -> V_198 ) != 0 ) {
F_156 ( sizeof( V_49 -> V_197 ) != sizeof( V_233 -> V_197 ) ) ;
if ( strcmp ( V_49 -> V_197 , V_233 -> V_197 ) != 0 )
continue;
if ( V_233 -> V_202 >= 0 &&
V_233 -> V_202 != V_49 -> V_202 )
continue;
if ( V_233 -> V_202 < 0 )
V_233 -> V_202 = V_49 -> V_202 ;
if ( F_157 ( V_233 , V_49 ) )
return;
if ( V_233 -> V_237 &&
V_233 -> V_237 ( V_233 , V_49 -> V_198 ) != 0 )
break;
}
V_233 -> V_31 |= V_161 ;
if ( V_58 == V_203 ) {
V_233 -> V_31 |= V_238 ;
V_236 = V_203 ;
}
break;
}
if ( ! ( V_233 -> V_31 & V_161 ) )
return;
if ( V_234 && ( ( V_233 -> V_31 & ( V_238 | V_235 ) ) == V_238 ) )
V_233 -> V_31 &= ~ V_240 ;
F_129 () ;
if ( ( V_233 -> V_31 & V_238 ) || V_159 == NULL ) {
V_233 -> V_132 = V_159 ;
V_159 = V_233 ;
if ( V_233 -> V_132 )
V_233 -> V_132 -> V_31 &= ~ V_238 ;
} else {
V_233 -> V_132 = V_159 -> V_132 ;
V_159 -> V_132 = V_233 ;
}
if ( V_233 -> V_31 & V_164 )
if ( ! V_171 ++ )
F_61 ( L_30 ) ;
if ( V_233 -> V_31 & V_240 ) {
F_67 ( & V_79 , V_31 ) ;
V_220 = V_136 ;
V_227 = V_137 ;
V_173 = V_138 ;
F_68 ( & V_79 , V_31 ) ;
V_160 = V_233 ;
}
F_112 () ;
F_158 () ;
F_61 ( L_31 ,
( V_233 -> V_31 & V_235 ) ? L_32 : L_33 ,
V_233 -> V_197 , V_233 -> V_202 ) ;
if ( V_234 &&
( ( V_233 -> V_31 & ( V_238 | V_235 ) ) == V_238 ) &&
! V_232 ) {
F_87 (bcon)
if ( V_234 -> V_31 & V_235 )
F_159 ( V_234 ) ;
}
}
int F_159 ( struct V_157 * V_157 )
{
struct V_157 * V_241 , * V_242 ;
int V_243 ;
F_61 ( L_34 ,
( V_157 -> V_31 & V_235 ) ? L_32 : L_33 ,
V_157 -> V_197 , V_157 -> V_202 ) ;
V_243 = F_160 ( V_157 ) ;
if ( V_243 )
return V_243 ;
V_243 = 1 ;
F_129 () ;
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
if ( ! V_243 && ( V_157 -> V_31 & V_164 ) )
V_171 -- ;
if ( V_159 != NULL && V_157 -> V_31 & V_238 )
V_159 -> V_31 |= V_238 ;
V_157 -> V_31 &= ~ V_161 ;
F_112 () ;
F_158 () ;
return V_243 ;
}
static int T_9 F_161 ( void )
{
struct V_157 * V_158 ;
F_87 (con) {
if ( ! V_232 && V_158 -> V_31 & V_235 ) {
if ( F_162 ( V_158 , sizeof( * V_158 ) ) )
F_159 ( V_158 ) ;
}
}
F_163 ( F_133 , 0 ) ;
return 0 ;
}
static void F_164 ( struct V_244 * V_244 )
{
int V_245 = F_165 ( V_246 , 0 ) ;
if ( V_245 & V_247 ) {
if ( F_111 () )
F_112 () ;
}
if ( V_245 & V_248 )
F_166 ( & V_84 ) ;
}
void F_146 ( void )
{
F_167 () ;
if ( F_168 ( & V_84 ) ) {
F_169 ( V_246 , V_248 ) ;
F_170 ( F_171 ( & V_249 ) ) ;
}
F_172 () ;
}
int F_173 ( const char * V_175 , ... )
{
T_11 args ;
int V_190 ;
F_167 () ;
va_start ( args , V_175 ) ;
V_190 = F_100 ( 0 , V_184 , NULL , 0 , V_175 , args ) ;
va_end ( args ) ;
F_174 ( V_246 , V_247 ) ;
F_170 ( F_171 ( & V_249 ) ) ;
F_172 () ;
return V_190 ;
}
int F_175 ( const char * V_250 )
{
return F_176 ( & V_251 , V_250 ) ;
}
bool F_177 ( unsigned long * V_252 ,
unsigned int V_253 )
{
unsigned long V_254 = V_123 - * V_252 ;
if ( * V_252 && V_254 <= F_74 ( V_253 ) )
return false ;
* V_252 = V_123 ;
return true ;
}
int F_178 ( struct V_255 * V_256 )
{
unsigned long V_31 ;
int V_100 = - V_257 ;
if ( ! V_256 -> V_258 )
return - V_66 ;
F_179 ( & V_259 , V_31 ) ;
if ( ! V_256 -> V_260 ) {
V_256 -> V_260 = 1 ;
F_180 ( & V_256 -> V_261 , & V_262 ) ;
V_100 = 0 ;
}
F_181 ( & V_259 , V_31 ) ;
return V_100 ;
}
int F_182 ( struct V_255 * V_256 )
{
unsigned long V_31 ;
int V_100 = - V_66 ;
F_179 ( & V_259 , V_31 ) ;
if ( V_256 -> V_260 ) {
V_256 -> V_260 = 0 ;
F_183 ( & V_256 -> V_261 ) ;
V_100 = 0 ;
}
F_181 ( & V_259 , V_31 ) ;
F_184 () ;
return V_100 ;
}
void F_185 ( enum V_263 V_264 )
{
struct V_255 * V_256 ;
unsigned long V_31 ;
if ( ( V_264 > V_265 ) && ! V_266 )
return;
F_186 () ;
F_187 (dumper, &dump_list, list) {
if ( V_256 -> V_267 && V_264 > V_256 -> V_267 )
continue;
V_256 -> V_268 = true ;
F_67 ( & V_79 , V_31 ) ;
V_256 -> V_269 = V_17 ;
V_256 -> V_270 = V_18 ;
V_256 -> V_141 = V_16 ;
V_256 -> V_271 = V_13 ;
F_68 ( & V_79 , V_31 ) ;
V_256 -> V_258 ( V_256 , V_264 ) ;
V_256 -> V_268 = false ;
}
F_188 () ;
}
bool F_189 ( struct V_255 * V_256 , bool V_127 ,
char * line , T_5 V_22 , T_5 * V_10 )
{
struct V_6 * V_7 ;
T_5 V_272 = 0 ;
bool V_64 = false ;
if ( ! V_256 -> V_268 )
goto V_83;
if ( V_256 -> V_269 < V_15 ) {
V_256 -> V_269 = V_15 ;
V_256 -> V_270 = V_14 ;
}
if ( V_256 -> V_269 >= V_16 )
goto V_83;
V_7 = F_8 ( V_256 -> V_270 ) ;
V_272 = F_80 ( V_7 , 0 , V_127 , line , V_22 ) ;
V_256 -> V_270 = F_9 ( V_256 -> V_270 ) ;
V_256 -> V_269 ++ ;
V_64 = true ;
V_83:
if ( V_10 )
* V_10 = V_272 ;
return V_64 ;
}
bool F_190 ( struct V_255 * V_256 , bool V_127 ,
char * line , T_5 V_22 , T_5 * V_10 )
{
unsigned long V_31 ;
bool V_64 ;
F_67 ( & V_79 , V_31 ) ;
V_64 = F_189 ( V_256 , V_127 , line , V_22 , V_10 ) ;
F_68 ( & V_79 , V_31 ) ;
return V_64 ;
}
bool F_191 ( struct V_255 * V_256 , bool V_127 ,
char * V_50 , T_5 V_22 , T_5 * V_10 )
{
unsigned long V_31 ;
T_3 V_51 ;
T_1 V_9 ;
T_3 V_141 ;
T_1 V_271 ;
enum V_30 V_86 ;
T_5 V_272 = 0 ;
bool V_64 = false ;
if ( ! V_256 -> V_268 )
goto V_83;
F_67 ( & V_79 , V_31 ) ;
if ( V_256 -> V_269 < V_15 ) {
V_256 -> V_269 = V_15 ;
V_256 -> V_270 = V_14 ;
}
if ( V_256 -> V_269 >= V_256 -> V_141 ) {
F_68 ( & V_79 , V_31 ) ;
goto V_83;
}
V_51 = V_256 -> V_269 ;
V_9 = V_256 -> V_270 ;
V_86 = 0 ;
while ( V_51 < V_256 -> V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_272 += F_80 ( V_7 , V_86 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_51 ++ ;
V_86 = V_7 -> V_31 ;
}
V_51 = V_256 -> V_269 ;
V_9 = V_256 -> V_270 ;
V_86 = 0 ;
while ( V_272 > V_22 && V_51 < V_256 -> V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_272 -= F_80 ( V_7 , V_86 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_51 ++ ;
V_86 = V_7 -> V_31 ;
}
V_141 = V_51 ;
V_271 = V_9 ;
V_272 = 0 ;
while ( V_51 < V_256 -> V_141 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_272 += F_80 ( V_7 , V_86 , V_127 , V_50 + V_272 , V_22 - V_272 ) ;
V_9 = F_9 ( V_9 ) ;
V_51 ++ ;
V_86 = V_7 -> V_31 ;
}
V_256 -> V_141 = V_141 ;
V_256 -> V_271 = V_271 ;
V_64 = true ;
F_68 ( & V_79 , V_31 ) ;
V_83:
if ( V_10 )
* V_10 = V_272 ;
return V_64 ;
}
void F_192 ( struct V_255 * V_256 )
{
V_256 -> V_269 = V_17 ;
V_256 -> V_270 = V_18 ;
V_256 -> V_141 = V_16 ;
V_256 -> V_271 = V_13 ;
}
void F_193 ( struct V_255 * V_256 )
{
unsigned long V_31 ;
F_67 ( & V_79 , V_31 ) ;
F_192 ( V_256 ) ;
F_68 ( & V_79 , V_31 ) ;
}
void T_9 F_194 ( const char * V_175 , ... )
{
T_11 args ;
va_start ( args , V_175 ) ;
vsnprintf ( V_273 , sizeof( V_273 ) ,
V_175 , args ) ;
va_end ( args ) ;
}
void F_195 ( const char * V_274 )
{
F_117 ( L_35 ,
V_274 , F_141 () , V_44 -> V_275 , V_44 -> V_45 ,
F_196 () , F_197 () -> V_276 ,
( int ) strcspn ( F_197 () -> V_277 , L_36 ) ,
F_197 () -> V_277 ) ;
if ( V_273 [ 0 ] != '\0' )
F_117 ( L_37 ,
V_274 , V_273 ) ;
F_198 ( V_274 , V_44 ) ;
}
void F_199 ( const char * V_274 )
{
F_195 ( V_274 ) ;
F_117 ( L_38 ,
V_274 , V_44 , F_200 () ,
F_201 ( V_44 ) ) ;
}
