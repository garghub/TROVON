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
int F_18 ( int type , bool V_36 )
{
if ( V_36 && type != V_37 )
return 0 ;
if ( F_17 ( type ) ) {
if ( F_19 ( V_38 ) )
return 0 ;
if ( F_19 ( V_39 ) ) {
F_20 ( L_1
L_2
L_3 ,
V_40 -> V_41 , F_21 ( V_40 ) ) ;
return 0 ;
}
return - V_42 ;
}
return F_22 ( type ) ;
}
static T_4 F_23 ( struct V_43 * V_44 , struct V_45 * V_46 )
{
char * V_47 , * line ;
int V_48 ;
int V_27 = V_49 ;
int V_26 = 1 ;
T_5 V_10 = F_24 ( V_46 ) ;
T_4 V_50 = V_10 ;
if ( V_10 > V_51 )
return - V_52 ;
V_47 = F_25 ( V_10 + 1 , V_53 ) ;
if ( V_47 == NULL )
return - V_17 ;
V_47 [ V_10 ] = '\0' ;
if ( F_26 ( V_47 , V_10 , V_46 ) != V_10 ) {
F_27 ( V_47 ) ;
return - V_54 ;
}
line = V_47 ;
if ( line [ 0 ] == '<' ) {
char * V_55 = NULL ;
V_48 = F_28 ( line + 1 , & V_55 , 10 ) ;
if ( V_55 && V_55 [ 0 ] == '>' ) {
V_27 = V_48 & 7 ;
if ( V_48 >> 3 )
V_26 = V_48 >> 3 ;
V_55 ++ ;
V_10 -= V_55 - line ;
line = V_55 ;
}
}
F_29 ( V_26 , V_27 , NULL , 0 , L_4 , line ) ;
F_27 ( V_47 ) ;
return V_50 ;
}
static T_4 F_30 ( struct V_56 * V_56 , char T_6 * V_47 ,
T_5 V_57 , T_7 * V_58 )
{
struct V_59 * V_60 = V_56 -> V_61 ;
struct V_6 * V_7 ;
T_3 V_62 ;
T_5 V_48 ;
char V_63 = '-' ;
T_5 V_10 ;
T_4 V_50 ;
if ( ! V_60 )
return - V_64 ;
V_50 = F_31 ( & V_60 -> V_65 ) ;
if ( V_50 )
return V_50 ;
F_32 ( & V_66 ) ;
while ( V_60 -> V_67 == V_16 ) {
if ( V_56 -> V_68 & V_69 ) {
V_50 = - V_70 ;
F_33 ( & V_66 ) ;
goto V_71;
}
F_33 ( & V_66 ) ;
V_50 = F_34 ( V_72 ,
V_60 -> V_67 != V_16 ) ;
if ( V_50 )
goto V_71;
F_32 ( & V_66 ) ;
}
if ( V_60 -> V_67 < V_15 ) {
V_60 -> V_9 = V_14 ;
V_60 -> V_67 = V_15 ;
V_50 = - V_73 ;
F_33 ( & V_66 ) ;
goto V_71;
}
V_7 = F_8 ( V_60 -> V_9 ) ;
V_62 = V_7 -> V_30 ;
F_35 ( V_62 , 1000 ) ;
if ( V_7 -> V_29 & V_74 && ! ( V_60 -> V_75 & V_74 ) )
V_63 = 'c' ;
else if ( ( V_7 -> V_29 & V_74 ) ||
( ( V_60 -> V_75 & V_74 ) && ! ( V_7 -> V_29 & V_76 ) ) )
V_63 = '+' ;
V_10 = sprintf ( V_60 -> V_47 , L_5 ,
( V_7 -> V_26 << 3 ) | V_7 -> V_27 ,
V_60 -> V_67 , V_62 , V_63 ) ;
V_60 -> V_75 = V_7 -> V_29 ;
for ( V_48 = 0 ; V_48 < V_7 -> V_8 ; V_48 ++ ) {
unsigned char V_77 = F_6 ( V_7 ) [ V_48 ] ;
if ( V_77 < ' ' || V_77 >= 127 || V_77 == '\\' )
V_10 += sprintf ( V_60 -> V_47 + V_10 , L_6 , V_77 ) ;
else
V_60 -> V_47 [ V_10 ++ ] = V_77 ;
}
V_60 -> V_47 [ V_10 ++ ] = '\n' ;
if ( V_7 -> V_18 ) {
bool line = true ;
for ( V_48 = 0 ; V_48 < V_7 -> V_18 ; V_48 ++ ) {
unsigned char V_77 = F_7 ( V_7 ) [ V_48 ] ;
if ( line ) {
V_60 -> V_47 [ V_10 ++ ] = ' ' ;
line = false ;
}
if ( V_77 == '\0' ) {
V_60 -> V_47 [ V_10 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_77 < ' ' || V_77 >= 127 || V_77 == '\\' ) {
V_10 += sprintf ( V_60 -> V_47 + V_10 , L_6 , V_77 ) ;
continue;
}
V_60 -> V_47 [ V_10 ++ ] = V_77 ;
}
V_60 -> V_47 [ V_10 ++ ] = '\n' ;
}
V_60 -> V_9 = F_9 ( V_60 -> V_9 ) ;
V_60 -> V_67 ++ ;
F_33 ( & V_66 ) ;
if ( V_10 > V_57 ) {
V_50 = - V_52 ;
goto V_71;
}
if ( F_36 ( V_47 , V_60 -> V_47 , V_10 ) ) {
V_50 = - V_54 ;
goto V_71;
}
V_50 = V_10 ;
V_71:
F_37 ( & V_60 -> V_65 ) ;
return V_50 ;
}
static T_7 F_38 ( struct V_56 * V_56 , T_7 V_78 , int V_79 )
{
struct V_59 * V_60 = V_56 -> V_61 ;
T_7 V_50 = 0 ;
if ( ! V_60 )
return - V_64 ;
if ( V_78 )
return - V_80 ;
F_32 ( & V_66 ) ;
switch ( V_79 ) {
case V_81 :
V_60 -> V_9 = V_14 ;
V_60 -> V_67 = V_15 ;
break;
case V_82 :
V_60 -> V_9 = V_83 ;
V_60 -> V_67 = V_84 ;
break;
case V_85 :
V_60 -> V_9 = V_13 ;
V_60 -> V_67 = V_16 ;
break;
default:
V_50 = - V_52 ;
}
F_33 ( & V_66 ) ;
return V_50 ;
}
static unsigned int F_39 ( struct V_56 * V_56 , T_8 * V_86 )
{
struct V_59 * V_60 = V_56 -> V_61 ;
int V_50 = 0 ;
if ( ! V_60 )
return V_87 | V_88 ;
F_40 ( V_56 , & V_72 , V_86 ) ;
F_32 ( & V_66 ) ;
if ( V_60 -> V_67 < V_16 ) {
if ( V_60 -> V_67 < V_15 )
V_50 = V_89 | V_90 | V_87 | V_91 ;
else
V_50 = V_89 | V_90 ;
}
F_33 ( & V_66 ) ;
return V_50 ;
}
static int F_41 ( struct V_92 * V_92 , struct V_56 * V_56 )
{
struct V_59 * V_60 ;
int V_93 ;
if ( ( V_56 -> V_68 & V_94 ) == V_95 )
return 0 ;
V_93 = F_18 ( V_34 ,
V_96 ) ;
if ( V_93 )
return V_93 ;
V_60 = F_25 ( sizeof( struct V_59 ) , V_53 ) ;
if ( ! V_60 )
return - V_17 ;
F_42 ( & V_60 -> V_65 ) ;
F_32 ( & V_66 ) ;
V_60 -> V_9 = V_14 ;
V_60 -> V_67 = V_15 ;
F_33 ( & V_66 ) ;
V_56 -> V_61 = V_60 ;
return 0 ;
}
static int F_43 ( struct V_92 * V_92 , struct V_56 * V_56 )
{
struct V_59 * V_60 = V_56 -> V_61 ;
if ( ! V_60 )
return 0 ;
F_44 ( & V_60 -> V_65 ) ;
F_27 ( V_60 ) ;
return 0 ;
}
void F_45 ( void )
{
F_46 ( V_4 ) ;
F_46 ( V_5 ) ;
F_46 ( V_14 ) ;
F_46 ( V_13 ) ;
F_47 ( V_6 ) ;
F_48 ( V_6 , V_30 ) ;
F_48 ( V_6 , V_10 ) ;
F_48 ( V_6 , V_8 ) ;
F_48 ( V_6 , V_18 ) ;
}
static void T_9 F_49 ( unsigned V_20 )
{
if ( V_20 )
V_20 = F_50 ( V_20 ) ;
if ( V_20 > V_5 )
V_97 = V_20 ;
}
static int T_9 F_51 ( char * V_98 )
{
unsigned V_20 = F_52 ( V_98 , & V_98 ) ;
F_49 ( V_20 ) ;
return 0 ;
}
static void T_9 F_53 ( void )
{
unsigned int V_99 ;
if ( F_54 () == 1 )
return;
V_99 = ( F_54 () - 1 ) * V_100 ;
if ( V_99 <= V_101 / 2 )
return;
F_55 ( L_7 ,
V_100 ) ;
F_55 ( L_8 ,
V_99 ) ;
F_55 ( L_9 , V_101 ) ;
F_49 ( V_99 + V_101 ) ;
}
static inline void F_53 ( void ) {}
void T_9 F_56 ( int V_102 )
{
unsigned long V_29 ;
char * V_103 ;
int free ;
if ( V_4 != V_104 )
return;
if ( ! V_102 && ! V_97 )
F_53 () ;
if ( ! V_97 )
return;
if ( V_102 ) {
V_103 =
F_57 ( V_97 , V_21 ) ;
} else {
V_103 = F_58 ( V_97 ,
V_21 ) ;
}
if ( F_59 ( ! V_103 ) ) {
F_60 ( L_10 ,
V_97 ) ;
return;
}
F_61 ( & V_66 , V_29 ) ;
V_5 = V_97 ;
V_4 = V_103 ;
V_97 = 0 ;
free = V_101 - V_13 ;
memcpy ( V_4 , V_104 , V_101 ) ;
F_62 ( & V_66 , V_29 ) ;
F_55 ( L_11 , V_5 ) ;
F_55 ( L_12 ,
free , ( free * 100 ) / V_101 ) ;
}
static int T_9 F_63 ( char * V_98 )
{
V_105 = true ;
F_55 ( L_13 ) ;
return 0 ;
}
static int T_9 F_64 ( char * V_98 )
{
unsigned long V_106 ;
V_106 = V_107 ? V_107 : 1000000 ;
V_108 = ( unsigned long long ) V_106 / 1000 * V_109 ;
F_65 ( & V_98 , & V_110 ) ;
if ( V_110 > 10 * 1000 )
V_110 = 0 ;
F_66 ( L_14
L_15 ,
V_110 , V_107 , V_106 , V_109 , V_108 ) ;
return 0 ;
}
static void F_67 ( int V_27 )
{
unsigned long long V_111 ;
unsigned long V_112 ;
if ( ( V_110 == 0 || V_113 != V_114 )
|| ( V_27 >= V_115 && ! V_105 ) ) {
return;
}
V_111 = ( unsigned long long ) V_108 * V_110 ;
V_112 = V_116 + F_68 ( V_110 ) ;
while ( V_111 ) {
V_111 -- ;
F_69 () ;
if ( F_70 ( V_116 , V_112 ) )
break;
F_71 () ;
}
}
static inline void F_67 ( int V_27 )
{
}
static T_5 F_72 ( T_3 V_117 , char * V_47 )
{
unsigned long V_118 ;
if ( ! V_119 )
return 0 ;
V_118 = F_35 ( V_117 , 1000000000 ) ;
if ( ! V_47 )
return snprintf ( NULL , 0 , L_16 , ( unsigned long ) V_117 ) ;
return sprintf ( V_47 , L_17 ,
( unsigned long ) V_117 , V_118 / 1000 ) ;
}
static T_5 F_73 ( const struct V_6 * V_7 , bool V_120 , char * V_47 )
{
T_5 V_10 = 0 ;
unsigned int V_121 = ( V_7 -> V_26 << 3 ) | V_7 -> V_27 ;
if ( V_120 ) {
if ( V_47 ) {
V_10 += sprintf ( V_47 , L_18 , V_121 ) ;
} else {
V_10 += 3 ;
if ( V_121 > 999 )
V_10 += 3 ;
else if ( V_121 > 99 )
V_10 += 2 ;
else if ( V_121 > 9 )
V_10 ++ ;
}
}
V_10 += F_72 ( V_7 -> V_30 , V_47 ? V_47 + V_10 : NULL ) ;
return V_10 ;
}
static T_5 F_74 ( const struct V_6 * V_7 , enum V_28 V_75 ,
bool V_120 , char * V_47 , T_5 V_20 )
{
const char * V_32 = F_6 ( V_7 ) ;
T_5 V_122 = V_7 -> V_8 ;
bool V_121 = true ;
bool V_123 = true ;
T_5 V_10 = 0 ;
if ( ( V_75 & V_74 ) && ! ( V_7 -> V_29 & V_76 ) )
V_121 = false ;
if ( V_7 -> V_29 & V_74 ) {
if ( ( V_75 & V_74 ) && ! ( V_75 & V_124 ) )
V_121 = false ;
if ( ! ( V_7 -> V_29 & V_124 ) )
V_123 = false ;
}
do {
const char * V_125 = memchr ( V_32 , '\n' , V_122 ) ;
T_5 V_8 ;
if ( V_125 ) {
V_8 = V_125 - V_32 ;
V_125 ++ ;
V_122 -= V_125 - V_32 ;
} else {
V_8 = V_122 ;
}
if ( V_47 ) {
if ( F_73 ( V_7 , V_120 , NULL ) +
V_8 + 1 >= V_20 - V_10 )
break;
if ( V_121 )
V_10 += F_73 ( V_7 , V_120 , V_47 + V_10 ) ;
memcpy ( V_47 + V_10 , V_32 , V_8 ) ;
V_10 += V_8 ;
if ( V_125 || V_123 )
V_47 [ V_10 ++ ] = '\n' ;
} else {
if ( V_121 )
V_10 += F_73 ( V_7 , V_120 , NULL ) ;
V_10 += V_8 ;
if ( V_125 || V_123 )
V_10 ++ ;
}
V_121 = true ;
V_32 = V_125 ;
} while ( V_32 );
return V_10 ;
}
static int F_75 ( char T_6 * V_47 , int V_20 )
{
char * V_32 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
V_32 = F_25 ( V_51 + V_126 , V_53 ) ;
if ( ! V_32 )
return - V_17 ;
while ( V_20 > 0 ) {
T_5 V_127 ;
T_5 V_128 ;
F_32 ( & V_66 ) ;
if ( V_129 < V_15 ) {
V_129 = V_15 ;
V_130 = V_14 ;
V_131 = 0 ;
V_132 = 0 ;
}
if ( V_129 == V_16 ) {
F_33 ( & V_66 ) ;
break;
}
V_128 = V_132 ;
V_7 = F_8 ( V_130 ) ;
V_127 = F_74 ( V_7 , V_131 , true , V_32 ,
V_51 + V_126 ) ;
if ( V_127 - V_132 <= V_20 ) {
V_130 = F_9 ( V_130 ) ;
V_129 ++ ;
V_131 = V_7 -> V_29 ;
V_127 -= V_132 ;
V_132 = 0 ;
} else if ( ! V_10 ) {
V_127 = V_20 ;
V_132 += V_127 ;
} else
V_127 = 0 ;
F_33 ( & V_66 ) ;
if ( ! V_127 )
break;
if ( F_36 ( V_47 , V_32 + V_128 , V_127 ) ) {
if ( ! V_10 )
V_10 = - V_54 ;
break;
}
V_10 += V_127 ;
V_20 -= V_127 ;
V_47 += V_127 ;
}
F_27 ( V_32 ) ;
return V_10 ;
}
static int F_76 ( char T_6 * V_47 , int V_20 , bool V_133 )
{
char * V_32 ;
int V_10 = 0 ;
V_32 = F_25 ( V_51 + V_126 , V_53 ) ;
if ( ! V_32 )
return - V_17 ;
F_32 ( & V_66 ) ;
if ( V_47 ) {
T_3 V_134 ;
T_3 V_67 ;
T_1 V_9 ;
enum V_28 V_75 ;
if ( V_84 < V_15 ) {
V_84 = V_15 ;
V_83 = V_14 ;
}
V_67 = V_84 ;
V_9 = V_83 ;
V_75 = 0 ;
while ( V_67 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 += F_74 ( V_7 , V_75 , true , NULL , 0 ) ;
V_75 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_67 ++ ;
}
V_67 = V_84 ;
V_9 = V_83 ;
V_75 = 0 ;
while ( V_10 > V_20 && V_67 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 -= F_74 ( V_7 , V_75 , true , NULL , 0 ) ;
V_75 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_67 ++ ;
}
V_134 = V_16 ;
V_10 = 0 ;
while ( V_10 >= 0 && V_67 < V_134 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
int V_135 ;
V_135 = F_74 ( V_7 , V_75 , true , V_32 ,
V_51 + V_126 ) ;
if ( V_135 < 0 ) {
V_10 = V_135 ;
break;
}
V_9 = F_9 ( V_9 ) ;
V_67 ++ ;
V_75 = V_7 -> V_29 ;
F_33 ( & V_66 ) ;
if ( F_36 ( V_47 + V_10 , V_32 , V_135 ) )
V_10 = - V_54 ;
else
V_10 += V_135 ;
F_32 ( & V_66 ) ;
if ( V_67 < V_15 ) {
V_67 = V_15 ;
V_9 = V_14 ;
V_75 = 0 ;
}
}
}
if ( V_133 ) {
V_84 = V_16 ;
V_83 = V_13 ;
}
F_33 ( & V_66 ) ;
F_27 ( V_32 ) ;
return V_10 ;
}
int F_77 ( int type , char T_6 * V_47 , int V_10 , bool V_36 )
{
bool V_133 = false ;
static int V_136 = V_137 ;
int error ;
error = F_18 ( type , V_36 ) ;
if ( error )
goto V_71;
error = F_22 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_138 :
break;
case V_37 :
break;
case V_139 :
error = - V_52 ;
if ( ! V_47 || V_10 < 0 )
goto V_71;
error = 0 ;
if ( ! V_10 )
goto V_71;
if ( ! F_78 ( V_140 , V_47 , V_10 ) ) {
error = - V_54 ;
goto V_71;
}
error = F_34 ( V_72 ,
V_129 != V_16 ) ;
if ( error )
goto V_71;
error = F_75 ( V_47 , V_10 ) ;
break;
case V_141 :
V_133 = true ;
case V_34 :
error = - V_52 ;
if ( ! V_47 || V_10 < 0 )
goto V_71;
error = 0 ;
if ( ! V_10 )
goto V_71;
if ( ! F_78 ( V_140 , V_47 , V_10 ) ) {
error = - V_54 ;
goto V_71;
}
error = F_76 ( V_47 , V_10 , V_133 ) ;
break;
case V_142 :
F_76 ( NULL , 0 , true ) ;
break;
case V_143 :
if ( V_136 == V_137 )
V_136 = V_115 ;
V_115 = V_144 ;
break;
case V_145 :
if ( V_136 != V_137 ) {
V_115 = V_136 ;
V_136 = V_137 ;
}
break;
case V_146 :
error = - V_52 ;
if ( V_10 < 1 || V_10 > 8 )
goto V_71;
if ( V_10 < V_144 )
V_10 = V_144 ;
V_115 = V_10 ;
V_136 = V_137 ;
error = 0 ;
break;
case V_147 :
F_32 ( & V_66 ) ;
if ( V_129 < V_15 ) {
V_129 = V_15 ;
V_130 = V_14 ;
V_131 = 0 ;
V_132 = 0 ;
}
if ( V_36 ) {
error = V_16 - V_129 ;
} else {
T_3 V_67 = V_129 ;
T_1 V_9 = V_130 ;
enum V_28 V_75 = V_131 ;
error = 0 ;
while ( V_67 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
error += F_74 ( V_7 , V_75 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_67 ++ ;
V_75 = V_7 -> V_29 ;
}
error -= V_132 ;
}
F_33 ( & V_66 ) ;
break;
case V_35 :
error = V_5 ;
break;
default:
error = - V_52 ;
break;
}
V_71:
return error ;
}
static void F_79 ( int V_27 , const char * V_32 , T_5 V_10 )
{
struct V_148 * V_149 ;
F_80 ( V_32 , V_10 ) ;
if ( V_27 >= V_115 && ! V_105 )
return;
if ( ! V_150 )
return;
F_81 (con) {
if ( V_151 && V_149 != V_151 )
continue;
if ( ! ( V_149 -> V_29 & V_152 ) )
continue;
if ( ! V_149 -> V_153 )
continue;
if ( ! F_82 ( F_83 () ) &&
! ( V_149 -> V_29 & V_154 ) )
continue;
V_149 -> V_153 ( V_149 , V_32 , V_10 ) ;
}
}
static void F_84 ( void )
{
static unsigned long V_155 ;
if ( F_85 ( V_116 , V_155 ) &&
! F_70 ( V_116 , V_155 + 30 * V_109 ) )
return;
V_155 = V_116 ;
F_86 () ;
F_87 ( & V_66 ) ;
F_88 ( & V_2 , 1 ) ;
}
static int F_89 ( void )
{
struct V_148 * V_149 ;
F_81 (con)
if ( V_149 -> V_29 & V_154 )
return 1 ;
return 0 ;
}
static inline int F_90 ( unsigned int V_156 )
{
return F_82 ( V_156 ) || F_89 () ;
}
static int F_91 ( void )
{
unsigned int V_156 = F_83 () ;
if ( ! F_92 () )
return 0 ;
if ( ! F_90 ( V_156 ) ) {
V_157 = 0 ;
F_93 () ;
return 0 ;
}
return 1 ;
}
static inline void F_94 ( void )
{
if ( F_59 ( V_158 ) ) {
int V_159 = V_158 ;
while ( V_159 -- ) {
F_95 ( 1 ) ;
F_71 () ;
}
}
}
static void F_96 ( enum V_28 V_29 )
{
if ( V_63 . V_160 )
return;
if ( V_63 . V_10 == 0 )
return;
if ( V_63 . V_161 ) {
F_15 ( V_63 . V_26 , V_63 . V_27 , V_29 | V_162 ,
V_63 . V_30 , NULL , 0 , V_63 . V_47 , V_63 . V_10 ) ;
V_63 . V_29 = V_29 ;
V_63 . V_160 = true ;
} else {
F_15 ( V_63 . V_26 , V_63 . V_27 , V_29 , 0 ,
NULL , 0 , V_63 . V_47 , V_63 . V_10 ) ;
V_63 . V_10 = 0 ;
}
}
static bool F_97 ( int V_26 , int V_27 , const char * V_32 , T_5 V_10 )
{
if ( V_63 . V_10 && V_63 . V_160 )
return false ;
if ( V_63 . V_10 + V_10 > sizeof( V_63 . V_47 ) ) {
F_96 ( V_74 ) ;
return false ;
}
if ( ! V_63 . V_10 ) {
V_63 . V_26 = V_26 ;
V_63 . V_27 = V_27 ;
V_63 . V_163 = V_40 ;
V_63 . V_30 = F_16 () ;
V_63 . V_29 = 0 ;
V_63 . V_161 = 0 ;
V_63 . V_160 = false ;
}
memcpy ( V_63 . V_47 + V_63 . V_10 , V_32 , V_10 ) ;
V_63 . V_10 += V_10 ;
if ( V_63 . V_10 > ( sizeof( V_63 . V_47 ) * 80 ) / 100 )
F_96 ( V_74 ) ;
return true ;
}
static T_5 F_98 ( char * V_32 , T_5 V_20 )
{
T_5 V_135 = 0 ;
T_5 V_10 ;
if ( V_63 . V_161 == 0 && ( V_164 & V_124 ) ) {
V_135 += F_72 ( V_63 . V_30 , V_32 ) ;
V_20 -= V_135 ;
}
V_10 = V_63 . V_10 - V_63 . V_161 ;
if ( V_10 > 0 ) {
if ( V_10 + 1 > V_20 )
V_10 = V_20 - 1 ;
memcpy ( V_32 + V_135 , V_63 . V_47 + V_63 . V_161 , V_10 ) ;
V_135 += V_10 ;
V_63 . V_161 = V_63 . V_10 ;
}
if ( V_63 . V_160 ) {
if ( V_63 . V_29 & V_124 )
V_32 [ V_135 ++ ] = '\n' ;
V_63 . V_10 = 0 ;
}
return V_135 ;
}
T_10 int F_99 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_165 ,
const char * V_166 , T_11 args )
{
static int V_167 ;
static char V_168 [ V_51 ] ;
char * V_32 = V_168 ;
T_5 V_8 = 0 ;
enum V_28 V_169 = 0 ;
unsigned long V_29 ;
int V_170 ;
int V_171 = 0 ;
bool V_172 = false ;
static unsigned int V_173 = V_174 ;
if ( V_27 == V_175 ) {
V_27 = V_137 ;
V_172 = true ;
}
F_67 ( V_27 ) ;
F_94 () ;
F_100 ( V_29 ) ;
V_170 = F_83 () ;
if ( F_59 ( V_173 == V_170 ) ) {
if ( ! V_176 && ! F_101 ( V_40 ) ) {
V_167 = 1 ;
F_102 ( V_29 ) ;
return 0 ;
}
F_84 () ;
}
F_103 () ;
F_104 ( & V_66 ) ;
V_173 = V_170 ;
if ( F_59 ( V_167 ) ) {
static const char V_177 [] =
L_19 ;
V_167 = 0 ;
V_171 += F_15 ( 0 , 2 , V_76 | V_124 , 0 ,
NULL , 0 , V_177 ,
strlen ( V_177 ) ) ;
}
V_8 = F_105 ( V_32 , sizeof( V_168 ) , V_166 , args ) ;
if ( V_8 && V_32 [ V_8 - 1 ] == '\n' ) {
V_8 -- ;
V_169 |= V_124 ;
}
if ( V_26 == 0 ) {
int V_178 = F_106 ( V_32 ) ;
if ( V_178 ) {
const char * V_179 = F_107 ( V_32 ) ;
switch ( V_178 ) {
case '0' ... '7' :
if ( V_27 == V_137 )
V_27 = V_178 - '0' ;
case 'd' :
V_169 |= V_76 ;
}
V_8 -= V_179 - V_32 ;
V_32 = ( char * ) V_179 ;
}
}
if ( V_27 == V_137 )
V_27 = V_49 ;
if ( V_31 )
V_169 |= V_76 | V_124 ;
if ( ! ( V_169 & V_124 ) ) {
if ( V_63 . V_10 && ( V_169 & V_76 || V_63 . V_163 != V_40 ) )
F_96 ( V_124 ) ;
if ( F_97 ( V_26 , V_27 , V_32 , V_8 ) )
V_171 += V_8 ;
else
V_171 += F_15 ( V_26 , V_27 ,
V_169 | V_74 , 0 ,
V_31 , V_165 , V_32 , V_8 ) ;
} else {
bool V_180 = false ;
if ( V_63 . V_10 ) {
if ( V_63 . V_163 == V_40 && ! ( V_169 & V_76 ) )
V_180 = F_97 ( V_26 , V_27 , V_32 ,
V_8 ) ;
F_96 ( V_124 ) ;
}
if ( V_180 )
V_171 += V_8 ;
else
V_171 += F_15 ( V_26 , V_27 , V_169 , 0 ,
V_31 , V_165 , V_32 , V_8 ) ;
}
V_173 = V_174 ;
F_108 ( & V_66 ) ;
F_109 () ;
F_102 ( V_29 ) ;
if ( ! V_172 ) {
F_103 () ;
F_110 () ;
if ( F_91 () )
F_111 () ;
F_112 () ;
F_109 () ;
}
return V_171 ;
}
T_10 int F_113 ( const char * V_166 , T_11 args )
{
return F_99 ( 0 , V_137 , NULL , 0 , V_166 , args ) ;
}
T_10 int F_29 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_165 ,
const char * V_166 , ... )
{
T_11 args ;
int V_181 ;
va_start ( args , V_166 ) ;
V_181 = F_99 ( V_26 , V_27 , V_31 , V_165 , V_166 , args ) ;
va_end ( args ) ;
return V_181 ;
}
int F_114 ( const char * V_166 , T_11 args )
{
int V_181 ;
#ifdef F_115
if ( F_59 ( V_182 ) ) {
V_181 = F_116 ( V_183 , V_166 , args ) ;
return V_181 ;
}
#endif
V_181 = F_99 ( 0 , V_137 , NULL , 0 , V_166 , args ) ;
return V_181 ;
}
T_10 T_12 int F_117 ( const char * V_166 , ... )
{
T_13 V_184 ;
T_11 args ;
int V_181 ;
va_start ( args , V_166 ) ;
V_184 = F_118 ( V_185 ) ;
V_181 = V_184 ( V_166 , args ) ;
va_end ( args ) ;
return V_181 ;
}
static struct V_6 * F_8 ( T_1 V_9 ) { return NULL ; }
static T_1 F_9 ( T_1 V_9 ) { return 0 ; }
static void F_79 ( int V_27 , const char * V_32 , T_5 V_10 ) {}
static T_5 F_74 ( const struct V_6 * V_7 , enum V_28 V_75 ,
bool V_120 , char * V_47 , T_5 V_20 ) { return 0 ; }
static T_5 F_98 ( char * V_32 , T_5 V_20 ) { return 0 ; }
T_10 T_12 void F_119 ( const char * V_166 , ... )
{
T_11 V_186 ;
char V_47 [ 512 ] ;
int V_127 ;
if ( ! V_187 )
return;
va_start ( V_186 , V_166 ) ;
V_127 = F_105 ( V_47 , sizeof( V_47 ) , V_166 , V_186 ) ;
va_end ( V_186 ) ;
V_187 -> V_153 ( V_187 , V_47 , V_127 ) ;
}
static int F_120 ( char * V_188 , int V_9 , char * V_189 ,
char * V_190 )
{
struct V_191 * V_77 ;
int V_48 ;
for ( V_48 = 0 , V_77 = V_191 ;
V_48 < V_192 && V_77 -> V_188 [ 0 ] ;
V_48 ++ , V_77 ++ ) {
if ( strcmp ( V_77 -> V_188 , V_188 ) == 0 && V_77 -> V_193 == V_9 ) {
if ( ! V_190 )
V_194 = V_48 ;
return 0 ;
}
}
if ( V_48 == V_192 )
return - V_195 ;
if ( ! V_190 )
V_194 = V_48 ;
F_121 ( V_77 -> V_188 , V_188 , sizeof( V_77 -> V_188 ) ) ;
V_77 -> V_189 = V_189 ;
F_122 ( V_77 , V_190 ) ;
V_77 -> V_193 = V_9 ;
return 0 ;
}
static int T_9 F_123 ( char * V_98 )
{
char V_47 [ sizeof( V_191 [ 0 ] . V_188 ) + 4 ] ;
char * V_196 , * V_189 , * V_190 = NULL ;
int V_9 ;
if ( F_124 ( & V_98 , & V_190 ) )
return 1 ;
if ( V_98 [ 0 ] >= '0' && V_98 [ 0 ] <= '9' ) {
strcpy ( V_47 , L_20 ) ;
strncpy ( V_47 + 4 , V_98 , sizeof( V_47 ) - 5 ) ;
} else {
strncpy ( V_47 , V_98 , sizeof( V_47 ) - 1 ) ;
}
V_47 [ sizeof( V_47 ) - 1 ] = 0 ;
V_189 = strchr ( V_98 , ',' ) ;
if ( V_189 )
* ( V_189 ++ ) = 0 ;
#ifdef F_125
if ( ! strcmp ( V_98 , L_21 ) )
strcpy ( V_47 , L_22 ) ;
if ( ! strcmp ( V_98 , L_23 ) )
strcpy ( V_47 , L_24 ) ;
#endif
for ( V_196 = V_47 ; * V_196 ; V_196 ++ )
if ( isdigit ( * V_196 ) || * V_196 == ',' )
break;
V_9 = F_28 ( V_196 , NULL , 10 ) ;
* V_196 = 0 ;
F_120 ( V_47 , V_9 , V_189 , V_190 ) ;
V_197 = 1 ;
return 1 ;
}
int F_126 ( char * V_188 , int V_9 , char * V_189 )
{
return F_120 ( V_188 , V_9 , V_189 , NULL ) ;
}
static int T_9 F_127 ( char * V_98 )
{
V_198 = false ;
return 1 ;
}
void F_128 ( void )
{
if ( ! V_198 )
return;
F_117 ( L_25 ) ;
F_129 () ;
V_199 = 1 ;
F_93 () ;
}
void F_130 ( void )
{
if ( ! V_198 )
return;
F_131 () ;
V_199 = 0 ;
F_111 () ;
}
static int F_132 ( struct V_200 * V_201 ,
unsigned long V_202 , void * V_203 )
{
switch ( V_202 ) {
case V_204 :
case V_205 :
case V_206 :
case V_207 :
F_129 () ;
F_111 () ;
}
return V_208 ;
}
void F_129 ( void )
{
F_133 () ;
F_131 () ;
if ( V_199 )
return;
V_157 = 1 ;
V_209 = 1 ;
}
int F_92 ( void )
{
if ( F_134 () )
return 0 ;
if ( V_199 ) {
F_93 () ;
return 0 ;
}
V_157 = 1 ;
V_209 = 0 ;
return 1 ;
}
int F_135 ( void )
{
return V_157 ;
}
static void F_136 ( char * V_32 , T_5 V_20 )
{
unsigned long V_29 ;
T_5 V_10 ;
F_61 ( & V_66 , V_29 ) ;
if ( ! V_63 . V_10 )
goto V_71;
if ( V_210 < V_16 && ! V_63 . V_161 )
goto V_71;
V_10 = F_98 ( V_32 , V_20 ) ;
F_108 ( & V_66 ) ;
F_137 () ;
F_79 ( V_63 . V_27 , V_32 , V_10 ) ;
F_138 () ;
F_102 ( V_29 ) ;
return;
V_71:
F_62 ( & V_66 , V_29 ) ;
}
void F_111 ( void )
{
static char V_32 [ V_51 + V_126 ] ;
static T_3 V_211 ;
unsigned long V_29 ;
bool V_212 = false ;
bool V_213 ;
if ( V_199 ) {
F_93 () ;
return;
}
V_209 = 0 ;
F_136 ( V_32 , sizeof( V_32 ) ) ;
V_214:
for (; ; ) {
struct V_6 * V_7 ;
T_5 V_10 ;
int V_27 ;
F_61 ( & V_66 , V_29 ) ;
if ( V_211 != V_16 ) {
V_212 = true ;
V_211 = V_16 ;
}
if ( V_210 < V_15 ) {
V_10 = sprintf ( V_32 , L_26 ,
( unsigned ) ( V_15 - V_210 ) ) ;
V_210 = V_15 ;
V_215 = V_14 ;
V_164 = 0 ;
} else {
V_10 = 0 ;
}
V_128:
if ( V_210 == V_16 )
break;
V_7 = F_8 ( V_215 ) ;
if ( V_7 -> V_29 & V_162 ) {
V_215 = F_9 ( V_215 ) ;
V_210 ++ ;
V_7 -> V_29 &= ~ V_162 ;
V_164 = V_7 -> V_29 ;
goto V_128;
}
V_27 = V_7 -> V_27 ;
V_10 += F_74 ( V_7 , V_164 , false ,
V_32 + V_10 , sizeof( V_32 ) - V_10 ) ;
V_215 = F_9 ( V_215 ) ;
V_210 ++ ;
V_164 = V_7 -> V_29 ;
F_108 ( & V_66 ) ;
F_137 () ;
F_79 ( V_27 , V_32 , V_10 ) ;
F_138 () ;
F_102 ( V_29 ) ;
}
V_157 = 0 ;
if ( F_59 ( V_151 ) )
V_151 = NULL ;
F_108 ( & V_66 ) ;
F_93 () ;
F_104 ( & V_66 ) ;
V_213 = V_210 != V_16 ;
F_62 ( & V_66 , V_29 ) ;
if ( V_213 && F_92 () )
goto V_214;
if ( V_212 )
F_139 () ;
}
void T_14 F_140 ( void )
{
if ( V_209 )
F_141 () ;
}
void F_142 ( void )
{
struct V_148 * V_77 ;
if ( V_176 ) {
if ( F_134 () != 0 )
return;
} else
F_129 () ;
V_157 = 1 ;
V_209 = 0 ;
F_81 (c)
if ( ( V_77 -> V_29 & V_152 ) && V_77 -> V_216 )
V_77 -> V_216 () ;
F_111 () ;
}
struct V_217 * F_143 ( int * V_193 )
{
struct V_148 * V_77 ;
struct V_217 * V_218 = NULL ;
F_129 () ;
F_81 (c) {
if ( ! V_77 -> V_219 )
continue;
V_218 = V_77 -> V_219 ( V_77 , V_193 ) ;
if ( V_218 )
break;
}
F_111 () ;
return V_218 ;
}
void F_144 ( struct V_148 * V_148 )
{
F_129 () ;
V_148 -> V_29 &= ~ V_152 ;
F_111 () ;
}
void F_145 ( struct V_148 * V_148 )
{
F_129 () ;
V_148 -> V_29 |= V_152 ;
F_111 () ;
}
static int T_9 F_146 ( char * V_98 )
{
V_220 = 1 ;
F_55 ( L_27 ) ;
return 0 ;
}
void F_147 ( struct V_148 * V_221 )
{
int V_48 ;
unsigned long V_29 ;
struct V_148 * V_222 = NULL ;
struct V_191 * V_77 ;
if ( V_150 )
F_81 (bcon)
if ( F_148 ( V_222 == V_221 ,
L_28 ,
V_222 -> V_188 , V_222 -> V_193 ) )
return;
if ( V_150 && V_221 -> V_29 & V_223 ) {
F_81 (bcon) {
if ( ! ( V_222 -> V_29 & V_223 ) ) {
F_55 ( L_29 ,
V_221 -> V_188 , V_221 -> V_193 ) ;
return;
}
}
}
if ( V_150 && V_150 -> V_29 & V_223 )
V_222 = V_150 ;
if ( V_224 < 0 || V_222 || ! V_150 )
V_224 = V_194 ;
if ( V_224 < 0 ) {
if ( V_221 -> V_193 < 0 )
V_221 -> V_193 = 0 ;
if ( V_221 -> V_225 == NULL ||
V_221 -> V_225 ( V_221 , NULL ) == 0 ) {
V_221 -> V_29 |= V_152 ;
if ( V_221 -> V_219 ) {
V_221 -> V_29 |= V_226 ;
V_224 = 0 ;
}
}
}
for ( V_48 = 0 , V_77 = V_191 ;
V_48 < V_192 && V_77 -> V_188 [ 0 ] ;
V_48 ++ , V_77 ++ ) {
if ( ! V_221 -> V_227 ||
V_221 -> V_227 ( V_221 , V_77 -> V_188 , V_77 -> V_193 , V_77 -> V_189 ) != 0 ) {
F_149 ( sizeof( V_77 -> V_188 ) != sizeof( V_221 -> V_188 ) ) ;
if ( strcmp ( V_77 -> V_188 , V_221 -> V_188 ) != 0 )
continue;
if ( V_221 -> V_193 >= 0 &&
V_221 -> V_193 != V_77 -> V_193 )
continue;
if ( V_221 -> V_193 < 0 )
V_221 -> V_193 = V_77 -> V_193 ;
if ( F_150 ( V_221 , V_77 ) )
return;
if ( V_221 -> V_225 &&
V_221 -> V_225 ( V_221 , V_77 -> V_189 ) != 0 )
break;
}
V_221 -> V_29 |= V_152 ;
if ( V_48 == V_194 ) {
V_221 -> V_29 |= V_226 ;
V_224 = V_194 ;
}
break;
}
if ( ! ( V_221 -> V_29 & V_152 ) )
return;
if ( V_222 && ( ( V_221 -> V_29 & ( V_226 | V_223 ) ) == V_226 ) )
V_221 -> V_29 &= ~ V_228 ;
F_129 () ;
if ( ( V_221 -> V_29 & V_226 ) || V_150 == NULL ) {
V_221 -> V_125 = V_150 ;
V_150 = V_221 ;
if ( V_221 -> V_125 )
V_221 -> V_125 -> V_29 &= ~ V_226 ;
} else {
V_221 -> V_125 = V_150 -> V_125 ;
V_150 -> V_125 = V_221 ;
}
if ( V_221 -> V_29 & V_228 ) {
F_61 ( & V_66 , V_29 ) ;
V_210 = V_129 ;
V_215 = V_130 ;
V_164 = V_131 ;
F_62 ( & V_66 , V_29 ) ;
V_151 = V_221 ;
}
F_111 () ;
F_151 () ;
F_55 ( L_30 ,
( V_221 -> V_29 & V_223 ) ? L_31 : L_32 ,
V_221 -> V_188 , V_221 -> V_193 ) ;
if ( V_222 &&
( ( V_221 -> V_29 & ( V_226 | V_223 ) ) == V_226 ) &&
! V_220 ) {
F_81 (bcon)
if ( V_222 -> V_29 & V_223 )
F_152 ( V_222 ) ;
}
}
int F_152 ( struct V_148 * V_148 )
{
struct V_148 * V_229 , * V_230 ;
int V_231 ;
F_55 ( L_33 ,
( V_148 -> V_29 & V_223 ) ? L_31 : L_32 ,
V_148 -> V_188 , V_148 -> V_193 ) ;
V_231 = F_153 ( V_148 ) ;
if ( V_231 )
return V_231 ;
V_231 = 1 ;
F_129 () ;
if ( V_150 == V_148 ) {
V_150 = V_148 -> V_125 ;
V_231 = 0 ;
} else if ( V_150 ) {
for ( V_229 = V_150 -> V_125 , V_230 = V_150 ;
V_229 ; V_230 = V_229 , V_229 = V_230 -> V_125 ) {
if ( V_229 == V_148 ) {
V_230 -> V_125 = V_229 -> V_125 ;
V_231 = 0 ;
break;
}
}
}
if ( V_150 != NULL && V_148 -> V_29 & V_226 )
V_150 -> V_29 |= V_226 ;
V_148 -> V_29 &= ~ V_152 ;
F_111 () ;
F_151 () ;
return V_231 ;
}
static int T_9 F_154 ( void )
{
struct V_148 * V_149 ;
F_81 (con) {
if ( ! V_220 && V_149 -> V_29 & V_223 ) {
F_152 ( V_149 ) ;
}
}
F_155 ( F_132 , 0 ) ;
return 0 ;
}
static void F_156 ( struct V_232 * V_232 )
{
int V_233 = F_157 ( V_234 , 0 ) ;
if ( V_233 & V_235 ) {
if ( F_92 () )
F_111 () ;
}
if ( V_233 & V_236 )
F_158 ( & V_72 ) ;
}
void F_139 ( void )
{
F_110 () ;
if ( F_159 ( & V_72 ) ) {
F_160 ( V_234 , V_236 ) ;
F_161 ( F_162 ( & V_237 ) ) ;
}
F_112 () ;
}
int F_163 ( const char * V_166 , ... )
{
T_11 args ;
int V_181 ;
F_110 () ;
va_start ( args , V_166 ) ;
V_181 = F_99 ( 0 , V_175 , NULL , 0 , V_166 , args ) ;
va_end ( args ) ;
F_164 ( V_234 , V_235 ) ;
F_161 ( F_162 ( & V_237 ) ) ;
F_112 () ;
return V_181 ;
}
int F_165 ( const char * V_238 )
{
return F_166 ( & V_239 , V_238 ) ;
}
bool F_167 ( unsigned long * V_240 ,
unsigned int V_241 )
{
unsigned long V_242 = V_116 - * V_240 ;
if ( * V_240 && V_242 <= F_68 ( V_241 ) )
return false ;
* V_240 = V_116 ;
return true ;
}
int F_168 ( struct V_243 * V_244 )
{
unsigned long V_29 ;
int V_93 = - V_245 ;
if ( ! V_244 -> V_246 )
return - V_52 ;
F_169 ( & V_247 , V_29 ) ;
if ( ! V_244 -> V_248 ) {
V_244 -> V_248 = 1 ;
F_170 ( & V_244 -> V_249 , & V_250 ) ;
V_93 = 0 ;
}
F_171 ( & V_247 , V_29 ) ;
return V_93 ;
}
int F_172 ( struct V_243 * V_244 )
{
unsigned long V_29 ;
int V_93 = - V_52 ;
F_169 ( & V_247 , V_29 ) ;
if ( V_244 -> V_248 ) {
V_244 -> V_248 = 0 ;
F_173 ( & V_244 -> V_249 ) ;
V_93 = 0 ;
}
F_171 ( & V_247 , V_29 ) ;
F_174 () ;
return V_93 ;
}
void F_175 ( enum V_251 V_252 )
{
struct V_243 * V_244 ;
unsigned long V_29 ;
if ( ( V_252 > V_253 ) && ! V_254 )
return;
F_176 () ;
F_177 (dumper, &dump_list, list) {
if ( V_244 -> V_255 && V_252 > V_244 -> V_255 )
continue;
V_244 -> V_256 = true ;
F_61 ( & V_66 , V_29 ) ;
V_244 -> V_257 = V_84 ;
V_244 -> V_258 = V_83 ;
V_244 -> V_134 = V_16 ;
V_244 -> V_259 = V_13 ;
F_62 ( & V_66 , V_29 ) ;
V_244 -> V_246 ( V_244 , V_252 ) ;
V_244 -> V_256 = false ;
}
F_178 () ;
}
bool F_179 ( struct V_243 * V_244 , bool V_120 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
struct V_6 * V_7 ;
T_5 V_260 = 0 ;
bool V_50 = false ;
if ( ! V_244 -> V_256 )
goto V_71;
if ( V_244 -> V_257 < V_15 ) {
V_244 -> V_257 = V_15 ;
V_244 -> V_258 = V_14 ;
}
if ( V_244 -> V_257 >= V_16 )
goto V_71;
V_7 = F_8 ( V_244 -> V_258 ) ;
V_260 = F_74 ( V_7 , 0 , V_120 , line , V_20 ) ;
V_244 -> V_258 = F_9 ( V_244 -> V_258 ) ;
V_244 -> V_257 ++ ;
V_50 = true ;
V_71:
if ( V_10 )
* V_10 = V_260 ;
return V_50 ;
}
bool F_180 ( struct V_243 * V_244 , bool V_120 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
bool V_50 ;
F_61 ( & V_66 , V_29 ) ;
V_50 = F_179 ( V_244 , V_120 , line , V_20 , V_10 ) ;
F_62 ( & V_66 , V_29 ) ;
return V_50 ;
}
bool F_181 ( struct V_243 * V_244 , bool V_120 ,
char * V_47 , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
T_3 V_67 ;
T_1 V_9 ;
T_3 V_134 ;
T_1 V_259 ;
enum V_28 V_75 ;
T_5 V_260 = 0 ;
bool V_50 = false ;
if ( ! V_244 -> V_256 )
goto V_71;
F_61 ( & V_66 , V_29 ) ;
if ( V_244 -> V_257 < V_15 ) {
V_244 -> V_257 = V_15 ;
V_244 -> V_258 = V_14 ;
}
if ( V_244 -> V_257 >= V_244 -> V_134 ) {
F_62 ( & V_66 , V_29 ) ;
goto V_71;
}
V_67 = V_244 -> V_257 ;
V_9 = V_244 -> V_258 ;
V_75 = 0 ;
while ( V_67 < V_244 -> V_134 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_260 += F_74 ( V_7 , V_75 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_67 ++ ;
V_75 = V_7 -> V_29 ;
}
V_67 = V_244 -> V_257 ;
V_9 = V_244 -> V_258 ;
V_75 = 0 ;
while ( V_260 > V_20 && V_67 < V_244 -> V_134 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_260 -= F_74 ( V_7 , V_75 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_67 ++ ;
V_75 = V_7 -> V_29 ;
}
V_134 = V_67 ;
V_259 = V_9 ;
V_260 = 0 ;
while ( V_67 < V_244 -> V_134 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_260 += F_74 ( V_7 , V_75 , V_120 , V_47 + V_260 , V_20 - V_260 ) ;
V_9 = F_9 ( V_9 ) ;
V_67 ++ ;
V_75 = V_7 -> V_29 ;
}
V_244 -> V_134 = V_134 ;
V_244 -> V_259 = V_259 ;
V_50 = true ;
F_62 ( & V_66 , V_29 ) ;
V_71:
if ( V_10 )
* V_10 = V_260 ;
return V_50 ;
}
void F_182 ( struct V_243 * V_244 )
{
V_244 -> V_257 = V_84 ;
V_244 -> V_258 = V_83 ;
V_244 -> V_134 = V_16 ;
V_244 -> V_259 = V_13 ;
}
void F_183 ( struct V_243 * V_244 )
{
unsigned long V_29 ;
F_61 ( & V_66 , V_29 ) ;
F_182 ( V_244 ) ;
F_62 ( & V_66 , V_29 ) ;
}
void T_9 F_184 ( const char * V_166 , ... )
{
T_11 args ;
va_start ( args , V_166 ) ;
vsnprintf ( V_261 , sizeof( V_261 ) ,
V_166 , args ) ;
va_end ( args ) ;
}
void F_185 ( const char * V_262 )
{
F_117 ( L_34 ,
V_262 , F_186 () , V_40 -> V_263 , V_40 -> V_41 ,
F_187 () , F_188 () -> V_264 ,
( int ) strcspn ( F_188 () -> V_265 , L_35 ) ,
F_188 () -> V_265 ) ;
if ( V_261 [ 0 ] != '\0' )
F_117 ( L_36 ,
V_262 , V_261 ) ;
F_189 ( V_262 , V_40 ) ;
}
void F_190 ( const char * V_262 )
{
F_185 ( V_262 ) ;
F_117 ( L_37 ,
V_262 , V_40 , F_191 () ,
F_192 ( V_40 ) ) ;
}
