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
static int F_18 ( int type , bool V_36 )
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
T_5 V_10 = V_44 -> V_50 ;
T_4 V_51 = V_10 ;
if ( V_10 > V_52 )
return - V_53 ;
V_47 = F_24 ( V_10 + 1 , V_54 ) ;
if ( V_47 == NULL )
return - V_17 ;
V_47 [ V_10 ] = '\0' ;
if ( F_25 ( V_47 , V_10 , V_46 ) != V_10 ) {
F_26 ( V_47 ) ;
return - V_55 ;
}
line = V_47 ;
if ( line [ 0 ] == '<' ) {
char * V_56 = NULL ;
V_48 = F_27 ( line + 1 , & V_56 , 10 ) ;
if ( V_56 && V_56 [ 0 ] == '>' ) {
V_27 = V_48 & 7 ;
if ( V_48 >> 3 )
V_26 = V_48 >> 3 ;
V_56 ++ ;
V_10 -= V_56 - line ;
line = V_56 ;
}
}
F_28 ( V_26 , V_27 , NULL , 0 , L_4 , line ) ;
F_26 ( V_47 ) ;
return V_51 ;
}
static T_4 F_29 ( struct V_57 * V_57 , char T_6 * V_47 ,
T_5 V_58 , T_7 * V_59 )
{
struct V_60 * V_61 = V_57 -> V_62 ;
struct V_6 * V_7 ;
T_3 V_63 ;
T_5 V_48 ;
char V_64 = '-' ;
T_5 V_10 ;
T_4 V_51 ;
if ( ! V_61 )
return - V_65 ;
V_51 = F_30 ( & V_61 -> V_66 ) ;
if ( V_51 )
return V_51 ;
F_31 ( & V_67 ) ;
while ( V_61 -> V_68 == V_16 ) {
if ( V_57 -> V_69 & V_70 ) {
V_51 = - V_71 ;
F_32 ( & V_67 ) ;
goto V_72;
}
F_32 ( & V_67 ) ;
V_51 = F_33 ( V_73 ,
V_61 -> V_68 != V_16 ) ;
if ( V_51 )
goto V_72;
F_31 ( & V_67 ) ;
}
if ( V_61 -> V_68 < V_15 ) {
V_61 -> V_9 = V_14 ;
V_61 -> V_68 = V_15 ;
V_51 = - V_74 ;
F_32 ( & V_67 ) ;
goto V_72;
}
V_7 = F_8 ( V_61 -> V_9 ) ;
V_63 = V_7 -> V_30 ;
F_34 ( V_63 , 1000 ) ;
if ( V_7 -> V_29 & V_75 && ! ( V_61 -> V_76 & V_75 ) )
V_64 = 'c' ;
else if ( ( V_7 -> V_29 & V_75 ) ||
( ( V_61 -> V_76 & V_75 ) && ! ( V_7 -> V_29 & V_77 ) ) )
V_64 = '+' ;
V_10 = sprintf ( V_61 -> V_47 , L_5 ,
( V_7 -> V_26 << 3 ) | V_7 -> V_27 ,
V_61 -> V_68 , V_63 , V_64 ) ;
V_61 -> V_76 = V_7 -> V_29 ;
for ( V_48 = 0 ; V_48 < V_7 -> V_8 ; V_48 ++ ) {
unsigned char V_78 = F_6 ( V_7 ) [ V_48 ] ;
if ( V_78 < ' ' || V_78 >= 127 || V_78 == '\\' )
V_10 += sprintf ( V_61 -> V_47 + V_10 , L_6 , V_78 ) ;
else
V_61 -> V_47 [ V_10 ++ ] = V_78 ;
}
V_61 -> V_47 [ V_10 ++ ] = '\n' ;
if ( V_7 -> V_18 ) {
bool line = true ;
for ( V_48 = 0 ; V_48 < V_7 -> V_18 ; V_48 ++ ) {
unsigned char V_78 = F_7 ( V_7 ) [ V_48 ] ;
if ( line ) {
V_61 -> V_47 [ V_10 ++ ] = ' ' ;
line = false ;
}
if ( V_78 == '\0' ) {
V_61 -> V_47 [ V_10 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_78 < ' ' || V_78 >= 127 || V_78 == '\\' ) {
V_10 += sprintf ( V_61 -> V_47 + V_10 , L_6 , V_78 ) ;
continue;
}
V_61 -> V_47 [ V_10 ++ ] = V_78 ;
}
V_61 -> V_47 [ V_10 ++ ] = '\n' ;
}
V_61 -> V_9 = F_9 ( V_61 -> V_9 ) ;
V_61 -> V_68 ++ ;
F_32 ( & V_67 ) ;
if ( V_10 > V_58 ) {
V_51 = - V_53 ;
goto V_72;
}
if ( F_35 ( V_47 , V_61 -> V_47 , V_10 ) ) {
V_51 = - V_55 ;
goto V_72;
}
V_51 = V_10 ;
V_72:
F_36 ( & V_61 -> V_66 ) ;
return V_51 ;
}
static T_7 F_37 ( struct V_57 * V_57 , T_7 V_79 , int V_80 )
{
struct V_60 * V_61 = V_57 -> V_62 ;
T_7 V_51 = 0 ;
if ( ! V_61 )
return - V_65 ;
if ( V_79 )
return - V_81 ;
F_31 ( & V_67 ) ;
switch ( V_80 ) {
case V_82 :
V_61 -> V_9 = V_14 ;
V_61 -> V_68 = V_15 ;
break;
case V_83 :
V_61 -> V_9 = V_84 ;
V_61 -> V_68 = V_85 ;
break;
case V_86 :
V_61 -> V_9 = V_13 ;
V_61 -> V_68 = V_16 ;
break;
default:
V_51 = - V_53 ;
}
F_32 ( & V_67 ) ;
return V_51 ;
}
static unsigned int F_38 ( struct V_57 * V_57 , T_8 * V_87 )
{
struct V_60 * V_61 = V_57 -> V_62 ;
int V_51 = 0 ;
if ( ! V_61 )
return V_88 | V_89 ;
F_39 ( V_57 , & V_73 , V_87 ) ;
F_31 ( & V_67 ) ;
if ( V_61 -> V_68 < V_16 ) {
if ( V_61 -> V_68 < V_15 )
V_51 = V_90 | V_91 | V_88 | V_92 ;
else
V_51 = V_90 | V_91 ;
}
F_32 ( & V_67 ) ;
return V_51 ;
}
static int F_40 ( struct V_93 * V_93 , struct V_57 * V_57 )
{
struct V_60 * V_61 ;
int V_94 ;
if ( ( V_57 -> V_69 & V_95 ) == V_96 )
return 0 ;
V_94 = F_18 ( V_34 ,
V_97 ) ;
if ( V_94 )
return V_94 ;
V_61 = F_24 ( sizeof( struct V_60 ) , V_54 ) ;
if ( ! V_61 )
return - V_17 ;
F_41 ( & V_61 -> V_66 ) ;
F_31 ( & V_67 ) ;
V_61 -> V_9 = V_14 ;
V_61 -> V_68 = V_15 ;
F_32 ( & V_67 ) ;
V_57 -> V_62 = V_61 ;
return 0 ;
}
static int F_42 ( struct V_93 * V_93 , struct V_57 * V_57 )
{
struct V_60 * V_61 = V_57 -> V_62 ;
if ( ! V_61 )
return 0 ;
F_43 ( & V_61 -> V_66 ) ;
F_26 ( V_61 ) ;
return 0 ;
}
void F_44 ( void )
{
F_45 ( V_4 ) ;
F_45 ( V_5 ) ;
F_45 ( V_14 ) ;
F_45 ( V_13 ) ;
F_46 ( V_6 ) ;
F_47 ( V_6 , V_30 ) ;
F_47 ( V_6 , V_10 ) ;
F_47 ( V_6 , V_8 ) ;
F_47 ( V_6 , V_18 ) ;
}
static void T_9 F_48 ( unsigned V_20 )
{
if ( V_20 )
V_20 = F_49 ( V_20 ) ;
if ( V_20 > V_5 )
V_98 = V_20 ;
}
static int T_9 F_50 ( char * V_99 )
{
unsigned V_20 = F_51 ( V_99 , & V_99 ) ;
F_48 ( V_20 ) ;
return 0 ;
}
static void T_9 F_52 ( void )
{
unsigned int V_100 ;
if ( F_53 () == 1 )
return;
V_100 = ( F_53 () - 1 ) * V_101 ;
if ( V_100 <= V_102 / 2 )
return;
F_54 ( L_7 ,
V_101 ) ;
F_54 ( L_8 ,
V_100 ) ;
F_54 ( L_9 , V_102 ) ;
F_48 ( V_100 + V_102 ) ;
}
static inline void F_52 ( void ) {}
void T_9 F_55 ( int V_103 )
{
unsigned long V_29 ;
char * V_104 ;
int free ;
if ( V_4 != V_105 )
return;
if ( ! V_103 && ! V_98 )
F_52 () ;
if ( ! V_98 )
return;
if ( V_103 ) {
V_104 =
F_56 ( V_98 , V_21 ) ;
} else {
V_104 = F_57 ( V_98 ,
V_21 ) ;
}
if ( F_58 ( ! V_104 ) ) {
F_59 ( L_10 ,
V_98 ) ;
return;
}
F_60 ( & V_67 , V_29 ) ;
V_5 = V_98 ;
V_4 = V_104 ;
V_98 = 0 ;
free = V_102 - V_13 ;
memcpy ( V_4 , V_105 , V_102 ) ;
F_61 ( & V_67 , V_29 ) ;
F_54 ( L_11 , V_5 ) ;
F_54 ( L_12 ,
free , ( free * 100 ) / V_102 ) ;
}
static int T_9 F_62 ( char * V_99 )
{
V_106 = true ;
F_54 ( L_13 ) ;
return 0 ;
}
static int T_9 F_63 ( char * V_99 )
{
unsigned long V_107 ;
V_107 = V_108 ? V_108 : 1000000 ;
V_109 = ( unsigned long long ) V_107 / 1000 * V_110 ;
F_64 ( & V_99 , & V_111 ) ;
if ( V_111 > 10 * 1000 )
V_111 = 0 ;
F_65 ( L_14
L_15 ,
V_111 , V_108 , V_107 , V_110 , V_109 ) ;
return 0 ;
}
static void F_66 ( int V_27 )
{
unsigned long long V_112 ;
unsigned long V_113 ;
if ( ( V_111 == 0 || V_114 != V_115 )
|| ( V_27 >= V_116 && ! V_106 ) ) {
return;
}
V_112 = ( unsigned long long ) V_109 * V_111 ;
V_113 = V_117 + F_67 ( V_111 ) ;
while ( V_112 ) {
V_112 -- ;
F_68 () ;
if ( F_69 ( V_117 , V_113 ) )
break;
F_70 () ;
}
}
static inline void F_66 ( int V_27 )
{
}
static T_5 F_71 ( T_3 V_118 , char * V_47 )
{
unsigned long V_119 ;
if ( ! V_120 )
return 0 ;
V_119 = F_34 ( V_118 , 1000000000 ) ;
if ( ! V_47 )
return snprintf ( NULL , 0 , L_16 , ( unsigned long ) V_118 ) ;
return sprintf ( V_47 , L_17 ,
( unsigned long ) V_118 , V_119 / 1000 ) ;
}
static T_5 F_72 ( const struct V_6 * V_7 , bool V_121 , char * V_47 )
{
T_5 V_10 = 0 ;
unsigned int V_122 = ( V_7 -> V_26 << 3 ) | V_7 -> V_27 ;
if ( V_121 ) {
if ( V_47 ) {
V_10 += sprintf ( V_47 , L_18 , V_122 ) ;
} else {
V_10 += 3 ;
if ( V_122 > 999 )
V_10 += 3 ;
else if ( V_122 > 99 )
V_10 += 2 ;
else if ( V_122 > 9 )
V_10 ++ ;
}
}
V_10 += F_71 ( V_7 -> V_30 , V_47 ? V_47 + V_10 : NULL ) ;
return V_10 ;
}
static T_5 F_73 ( const struct V_6 * V_7 , enum V_28 V_76 ,
bool V_121 , char * V_47 , T_5 V_20 )
{
const char * V_32 = F_6 ( V_7 ) ;
T_5 V_123 = V_7 -> V_8 ;
bool V_122 = true ;
bool V_124 = true ;
T_5 V_10 = 0 ;
if ( ( V_76 & V_75 ) && ! ( V_7 -> V_29 & V_77 ) )
V_122 = false ;
if ( V_7 -> V_29 & V_75 ) {
if ( ( V_76 & V_75 ) && ! ( V_76 & V_125 ) )
V_122 = false ;
if ( ! ( V_7 -> V_29 & V_125 ) )
V_124 = false ;
}
do {
const char * V_126 = memchr ( V_32 , '\n' , V_123 ) ;
T_5 V_8 ;
if ( V_126 ) {
V_8 = V_126 - V_32 ;
V_126 ++ ;
V_123 -= V_126 - V_32 ;
} else {
V_8 = V_123 ;
}
if ( V_47 ) {
if ( F_72 ( V_7 , V_121 , NULL ) +
V_8 + 1 >= V_20 - V_10 )
break;
if ( V_122 )
V_10 += F_72 ( V_7 , V_121 , V_47 + V_10 ) ;
memcpy ( V_47 + V_10 , V_32 , V_8 ) ;
V_10 += V_8 ;
if ( V_126 || V_124 )
V_47 [ V_10 ++ ] = '\n' ;
} else {
if ( V_122 )
V_10 += F_72 ( V_7 , V_121 , NULL ) ;
V_10 += V_8 ;
if ( V_126 || V_124 )
V_10 ++ ;
}
V_122 = true ;
V_32 = V_126 ;
} while ( V_32 );
return V_10 ;
}
static int F_74 ( char T_6 * V_47 , int V_20 )
{
char * V_32 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
V_32 = F_24 ( V_52 + V_127 , V_54 ) ;
if ( ! V_32 )
return - V_17 ;
while ( V_20 > 0 ) {
T_5 V_128 ;
T_5 V_129 ;
F_31 ( & V_67 ) ;
if ( V_130 < V_15 ) {
V_130 = V_15 ;
V_131 = V_14 ;
V_132 = 0 ;
V_133 = 0 ;
}
if ( V_130 == V_16 ) {
F_32 ( & V_67 ) ;
break;
}
V_129 = V_133 ;
V_7 = F_8 ( V_131 ) ;
V_128 = F_73 ( V_7 , V_132 , true , V_32 ,
V_52 + V_127 ) ;
if ( V_128 - V_133 <= V_20 ) {
V_131 = F_9 ( V_131 ) ;
V_130 ++ ;
V_132 = V_7 -> V_29 ;
V_128 -= V_133 ;
V_133 = 0 ;
} else if ( ! V_10 ) {
V_128 = V_20 ;
V_133 += V_128 ;
} else
V_128 = 0 ;
F_32 ( & V_67 ) ;
if ( ! V_128 )
break;
if ( F_35 ( V_47 , V_32 + V_129 , V_128 ) ) {
if ( ! V_10 )
V_10 = - V_55 ;
break;
}
V_10 += V_128 ;
V_20 -= V_128 ;
V_47 += V_128 ;
}
F_26 ( V_32 ) ;
return V_10 ;
}
static int F_75 ( char T_6 * V_47 , int V_20 , bool V_134 )
{
char * V_32 ;
int V_10 = 0 ;
V_32 = F_24 ( V_52 + V_127 , V_54 ) ;
if ( ! V_32 )
return - V_17 ;
F_31 ( & V_67 ) ;
if ( V_47 ) {
T_3 V_135 ;
T_3 V_68 ;
T_1 V_9 ;
enum V_28 V_76 ;
if ( V_85 < V_15 ) {
V_85 = V_15 ;
V_84 = V_14 ;
}
V_68 = V_85 ;
V_9 = V_84 ;
V_76 = 0 ;
while ( V_68 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 += F_73 ( V_7 , V_76 , true , NULL , 0 ) ;
V_76 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
}
V_68 = V_85 ;
V_9 = V_84 ;
V_76 = 0 ;
while ( V_10 > V_20 && V_68 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 -= F_73 ( V_7 , V_76 , true , NULL , 0 ) ;
V_76 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
}
V_135 = V_16 ;
V_10 = 0 ;
while ( V_10 >= 0 && V_68 < V_135 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
int V_136 ;
V_136 = F_73 ( V_7 , V_76 , true , V_32 ,
V_52 + V_127 ) ;
if ( V_136 < 0 ) {
V_10 = V_136 ;
break;
}
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
F_32 ( & V_67 ) ;
if ( F_35 ( V_47 + V_10 , V_32 , V_136 ) )
V_10 = - V_55 ;
else
V_10 += V_136 ;
F_31 ( & V_67 ) ;
if ( V_68 < V_15 ) {
V_68 = V_15 ;
V_9 = V_14 ;
V_76 = 0 ;
}
}
}
if ( V_134 ) {
V_85 = V_16 ;
V_84 = V_13 ;
}
F_32 ( & V_67 ) ;
F_26 ( V_32 ) ;
return V_10 ;
}
int F_76 ( int type , char T_6 * V_47 , int V_10 , bool V_36 )
{
bool V_134 = false ;
static int V_137 = - 1 ;
int error ;
error = F_18 ( type , V_36 ) ;
if ( error )
goto V_72;
error = F_22 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_138 :
break;
case V_37 :
break;
case V_139 :
error = - V_53 ;
if ( ! V_47 || V_10 < 0 )
goto V_72;
error = 0 ;
if ( ! V_10 )
goto V_72;
if ( ! F_77 ( V_140 , V_47 , V_10 ) ) {
error = - V_55 ;
goto V_72;
}
error = F_33 ( V_73 ,
V_130 != V_16 ) ;
if ( error )
goto V_72;
error = F_74 ( V_47 , V_10 ) ;
break;
case V_141 :
V_134 = true ;
case V_34 :
error = - V_53 ;
if ( ! V_47 || V_10 < 0 )
goto V_72;
error = 0 ;
if ( ! V_10 )
goto V_72;
if ( ! F_77 ( V_140 , V_47 , V_10 ) ) {
error = - V_55 ;
goto V_72;
}
error = F_75 ( V_47 , V_10 , V_134 ) ;
break;
case V_142 :
F_75 ( NULL , 0 , true ) ;
break;
case V_143 :
if ( V_137 == - 1 )
V_137 = V_116 ;
V_116 = V_144 ;
break;
case V_145 :
if ( V_137 != - 1 ) {
V_116 = V_137 ;
V_137 = - 1 ;
}
break;
case V_146 :
error = - V_53 ;
if ( V_10 < 1 || V_10 > 8 )
goto V_72;
if ( V_10 < V_144 )
V_10 = V_144 ;
V_116 = V_10 ;
V_137 = - 1 ;
error = 0 ;
break;
case V_147 :
F_31 ( & V_67 ) ;
if ( V_130 < V_15 ) {
V_130 = V_15 ;
V_131 = V_14 ;
V_132 = 0 ;
V_133 = 0 ;
}
if ( V_36 ) {
error = V_16 - V_130 ;
} else {
T_3 V_68 = V_130 ;
T_1 V_9 = V_131 ;
enum V_28 V_76 = V_132 ;
error = 0 ;
while ( V_68 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
error += F_73 ( V_7 , V_76 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
}
error -= V_133 ;
}
F_32 ( & V_67 ) ;
break;
case V_35 :
error = V_5 ;
break;
default:
error = - V_53 ;
break;
}
V_72:
return error ;
}
static void F_78 ( int V_27 , const char * V_32 , T_5 V_10 )
{
struct V_148 * V_149 ;
F_79 ( V_32 , V_10 ) ;
if ( V_27 >= V_116 && ! V_106 )
return;
if ( ! V_150 )
return;
F_80 (con) {
if ( V_151 && V_149 != V_151 )
continue;
if ( ! ( V_149 -> V_29 & V_152 ) )
continue;
if ( ! V_149 -> V_153 )
continue;
if ( ! F_81 ( F_82 () ) &&
! ( V_149 -> V_29 & V_154 ) )
continue;
V_149 -> V_153 ( V_149 , V_32 , V_10 ) ;
}
}
static void F_83 ( void )
{
static unsigned long V_155 ;
if ( F_84 ( V_117 , V_155 ) &&
! F_69 ( V_117 , V_155 + 30 * V_110 ) )
return;
V_155 = V_117 ;
F_85 () ;
F_86 ( & V_67 ) ;
F_87 ( & V_2 , 1 ) ;
}
static int F_88 ( void )
{
struct V_148 * V_149 ;
F_80 (con)
if ( V_149 -> V_29 & V_154 )
return 1 ;
return 0 ;
}
static inline int F_89 ( unsigned int V_156 )
{
return F_81 ( V_156 ) || F_88 () ;
}
static int F_90 ( void )
{
unsigned int V_156 = F_82 () ;
if ( ! F_91 () )
return 0 ;
if ( ! F_89 ( V_156 ) ) {
V_157 = 0 ;
F_92 () ;
return 0 ;
}
return 1 ;
}
static inline void F_93 ( void )
{
if ( F_58 ( V_158 ) ) {
int V_159 = V_158 ;
while ( V_159 -- ) {
F_94 ( 1 ) ;
F_70 () ;
}
}
}
static void F_95 ( enum V_28 V_29 )
{
if ( V_64 . V_160 )
return;
if ( V_64 . V_10 == 0 )
return;
if ( V_64 . V_161 ) {
F_15 ( V_64 . V_26 , V_64 . V_27 , V_29 | V_162 ,
V_64 . V_30 , NULL , 0 , V_64 . V_47 , V_64 . V_10 ) ;
V_64 . V_29 = V_29 ;
V_64 . V_160 = true ;
} else {
F_15 ( V_64 . V_26 , V_64 . V_27 , V_29 , 0 ,
NULL , 0 , V_64 . V_47 , V_64 . V_10 ) ;
V_64 . V_10 = 0 ;
}
}
static bool F_96 ( int V_26 , int V_27 , const char * V_32 , T_5 V_10 )
{
if ( V_64 . V_10 && V_64 . V_160 )
return false ;
if ( V_64 . V_10 + V_10 > sizeof( V_64 . V_47 ) ) {
F_95 ( V_75 ) ;
return false ;
}
if ( ! V_64 . V_10 ) {
V_64 . V_26 = V_26 ;
V_64 . V_27 = V_27 ;
V_64 . V_163 = V_40 ;
V_64 . V_30 = F_16 () ;
V_64 . V_29 = 0 ;
V_64 . V_161 = 0 ;
V_64 . V_160 = false ;
}
memcpy ( V_64 . V_47 + V_64 . V_10 , V_32 , V_10 ) ;
V_64 . V_10 += V_10 ;
if ( V_64 . V_10 > ( sizeof( V_64 . V_47 ) * 80 ) / 100 )
F_95 ( V_75 ) ;
return true ;
}
static T_5 F_97 ( char * V_32 , T_5 V_20 )
{
T_5 V_136 = 0 ;
T_5 V_10 ;
if ( V_64 . V_161 == 0 && ( V_164 & V_125 ) ) {
V_136 += F_71 ( V_64 . V_30 , V_32 ) ;
V_20 -= V_136 ;
}
V_10 = V_64 . V_10 - V_64 . V_161 ;
if ( V_10 > 0 ) {
if ( V_10 + 1 > V_20 )
V_10 = V_20 - 1 ;
memcpy ( V_32 + V_136 , V_64 . V_47 + V_64 . V_161 , V_10 ) ;
V_136 += V_10 ;
V_64 . V_161 = V_64 . V_10 ;
}
if ( V_64 . V_160 ) {
if ( V_64 . V_29 & V_125 )
V_32 [ V_136 ++ ] = '\n' ;
V_64 . V_10 = 0 ;
}
return V_136 ;
}
T_10 int F_98 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_165 ,
const char * V_166 , T_11 args )
{
static int V_167 ;
static char V_168 [ V_52 ] ;
char * V_32 = V_168 ;
T_5 V_8 = 0 ;
enum V_28 V_169 = 0 ;
unsigned long V_29 ;
int V_170 ;
int V_171 = 0 ;
bool V_172 = false ;
static volatile unsigned int V_173 = V_174 ;
if ( V_27 == V_175 ) {
V_27 = - 1 ;
V_172 = true ;
}
F_66 ( V_27 ) ;
F_93 () ;
F_99 ( V_29 ) ;
V_170 = F_82 () ;
if ( F_58 ( V_173 == V_170 ) ) {
if ( ! V_176 && ! F_100 ( V_40 ) ) {
V_167 = 1 ;
F_101 ( V_29 ) ;
return 0 ;
}
F_83 () ;
}
F_102 () ;
F_103 ( & V_67 ) ;
V_173 = V_170 ;
if ( F_58 ( V_167 ) ) {
static const char V_177 [] =
L_19 ;
V_167 = 0 ;
V_171 += F_15 ( 0 , 2 , V_77 | V_125 , 0 ,
NULL , 0 , V_177 ,
strlen ( V_177 ) ) ;
}
V_8 = F_104 ( V_32 , sizeof( V_168 ) , V_166 , args ) ;
if ( V_8 && V_32 [ V_8 - 1 ] == '\n' ) {
V_8 -- ;
V_169 |= V_125 ;
}
if ( V_26 == 0 ) {
int V_178 = F_105 ( V_32 ) ;
if ( V_178 ) {
const char * V_179 = F_106 ( V_32 ) ;
switch ( V_178 ) {
case '0' ... '7' :
if ( V_27 == - 1 )
V_27 = V_178 - '0' ;
case 'd' :
V_169 |= V_77 ;
}
V_8 -= V_179 - V_32 ;
V_32 = ( char * ) V_179 ;
}
}
if ( V_27 == - 1 )
V_27 = V_49 ;
if ( V_31 )
V_169 |= V_77 | V_125 ;
if ( ! ( V_169 & V_125 ) ) {
if ( V_64 . V_10 && ( V_169 & V_77 || V_64 . V_163 != V_40 ) )
F_95 ( V_125 ) ;
if ( F_96 ( V_26 , V_27 , V_32 , V_8 ) )
V_171 += V_8 ;
else
V_171 += F_15 ( V_26 , V_27 ,
V_169 | V_75 , 0 ,
V_31 , V_165 , V_32 , V_8 ) ;
} else {
bool V_180 = false ;
if ( V_64 . V_10 ) {
if ( V_64 . V_163 == V_40 && ! ( V_169 & V_77 ) )
V_180 = F_96 ( V_26 , V_27 , V_32 ,
V_8 ) ;
F_95 ( V_125 ) ;
}
if ( V_180 )
V_171 += V_8 ;
else
V_171 += F_15 ( V_26 , V_27 , V_169 , 0 ,
V_31 , V_165 , V_32 , V_8 ) ;
}
V_173 = V_174 ;
F_107 ( & V_67 ) ;
F_108 () ;
F_101 ( V_29 ) ;
if ( ! V_172 ) {
F_102 () ;
F_109 () ;
if ( F_90 () )
F_110 () ;
F_111 () ;
F_108 () ;
}
return V_171 ;
}
T_10 int F_112 ( const char * V_166 , T_11 args )
{
return F_98 ( 0 , - 1 , NULL , 0 , V_166 , args ) ;
}
T_10 int F_28 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_165 ,
const char * V_166 , ... )
{
T_11 args ;
int V_181 ;
va_start ( args , V_166 ) ;
V_181 = F_98 ( V_26 , V_27 , V_31 , V_165 , V_166 , args ) ;
va_end ( args ) ;
return V_181 ;
}
T_10 T_12 int F_113 ( const char * V_166 , ... )
{
T_11 args ;
int V_181 ;
#ifdef F_114
if ( F_58 ( V_182 ) ) {
va_start ( args , V_166 ) ;
V_181 = F_115 ( V_166 , args ) ;
va_end ( args ) ;
return V_181 ;
}
#endif
va_start ( args , V_166 ) ;
V_181 = F_98 ( 0 , - 1 , NULL , 0 , V_166 , args ) ;
va_end ( args ) ;
return V_181 ;
}
static struct V_6 * F_8 ( T_1 V_9 ) { return NULL ; }
static T_1 F_9 ( T_1 V_9 ) { return 0 ; }
static void F_78 ( int V_27 , const char * V_32 , T_5 V_10 ) {}
static T_5 F_73 ( const struct V_6 * V_7 , enum V_28 V_76 ,
bool V_121 , char * V_47 , T_5 V_20 ) { return 0 ; }
static T_5 F_97 ( char * V_32 , T_5 V_20 ) { return 0 ; }
void F_116 ( const char * V_166 , T_11 V_183 )
{
if ( V_184 ) {
char V_47 [ 512 ] ;
int V_128 = F_104 ( V_47 , sizeof( V_47 ) , V_166 , V_183 ) ;
V_184 -> V_153 ( V_184 , V_47 , V_128 ) ;
}
}
T_10 T_12 void F_117 ( const char * V_166 , ... )
{
T_11 V_183 ;
va_start ( V_183 , V_166 ) ;
F_116 ( V_166 , V_183 ) ;
va_end ( V_183 ) ;
}
static int F_118 ( char * V_185 , int V_9 , char * V_186 ,
char * V_187 )
{
struct V_188 * V_78 ;
int V_48 ;
for ( V_48 = 0 , V_78 = V_188 ;
V_48 < V_189 && V_78 -> V_185 [ 0 ] ;
V_48 ++ , V_78 ++ ) {
if ( strcmp ( V_78 -> V_185 , V_185 ) == 0 && V_78 -> V_190 == V_9 ) {
if ( ! V_187 )
V_191 = V_48 ;
return 0 ;
}
}
if ( V_48 == V_189 )
return - V_192 ;
if ( ! V_187 )
V_191 = V_48 ;
F_119 ( V_78 -> V_185 , V_185 , sizeof( V_78 -> V_185 ) ) ;
V_78 -> V_186 = V_186 ;
F_120 ( V_78 , V_187 ) ;
V_78 -> V_190 = V_9 ;
return 0 ;
}
static int T_9 F_121 ( char * V_99 )
{
char V_47 [ sizeof( V_188 [ 0 ] . V_185 ) + 4 ] ;
char * V_193 , * V_186 , * V_187 = NULL ;
int V_9 ;
if ( F_122 ( & V_99 , & V_187 ) )
return 1 ;
if ( V_99 [ 0 ] >= '0' && V_99 [ 0 ] <= '9' ) {
strcpy ( V_47 , L_20 ) ;
strncpy ( V_47 + 4 , V_99 , sizeof( V_47 ) - 5 ) ;
} else {
strncpy ( V_47 , V_99 , sizeof( V_47 ) - 1 ) ;
}
V_47 [ sizeof( V_47 ) - 1 ] = 0 ;
V_186 = strchr ( V_99 , ',' ) ;
if ( V_186 )
* ( V_186 ++ ) = 0 ;
#ifdef F_123
if ( ! strcmp ( V_99 , L_21 ) )
strcpy ( V_47 , L_22 ) ;
if ( ! strcmp ( V_99 , L_23 ) )
strcpy ( V_47 , L_24 ) ;
#endif
for ( V_193 = V_47 ; * V_193 ; V_193 ++ )
if ( isdigit ( * V_193 ) || * V_193 == ',' )
break;
V_9 = F_27 ( V_193 , NULL , 10 ) ;
* V_193 = 0 ;
F_118 ( V_47 , V_9 , V_186 , V_187 ) ;
V_194 = 1 ;
return 1 ;
}
int F_124 ( char * V_185 , int V_9 , char * V_186 )
{
return F_118 ( V_185 , V_9 , V_186 , NULL ) ;
}
int F_125 ( char * V_185 , int V_9 , char * V_195 , int V_196 , char * V_186 )
{
struct V_188 * V_78 ;
int V_48 ;
for ( V_48 = 0 , V_78 = V_188 ;
V_48 < V_189 && V_78 -> V_185 [ 0 ] ;
V_48 ++ , V_78 ++ )
if ( strcmp ( V_78 -> V_185 , V_185 ) == 0 && V_78 -> V_190 == V_9 ) {
F_119 ( V_78 -> V_185 , V_195 , sizeof( V_78 -> V_185 ) ) ;
V_78 -> V_186 = V_186 ;
V_78 -> V_190 = V_196 ;
return V_48 ;
}
return - 1 ;
}
static int T_9 F_126 ( char * V_99 )
{
V_197 = false ;
return 1 ;
}
void F_127 ( void )
{
if ( ! V_197 )
return;
F_113 ( L_25 ) ;
F_128 () ;
V_198 = 1 ;
F_92 () ;
}
void F_129 ( void )
{
if ( ! V_197 )
return;
F_130 () ;
V_198 = 0 ;
F_110 () ;
}
static int F_131 ( struct V_199 * V_200 ,
unsigned long V_201 , void * V_202 )
{
switch ( V_201 ) {
case V_203 :
case V_204 :
case V_205 :
case V_206 :
F_128 () ;
F_110 () ;
}
return V_207 ;
}
void F_128 ( void )
{
F_132 () ;
F_130 () ;
if ( V_198 )
return;
V_157 = 1 ;
V_208 = 1 ;
}
int F_91 ( void )
{
if ( F_133 () )
return 0 ;
if ( V_198 ) {
F_92 () ;
return 0 ;
}
V_157 = 1 ;
V_208 = 0 ;
return 1 ;
}
int F_134 ( void )
{
return V_157 ;
}
static void F_135 ( char * V_32 , T_5 V_20 )
{
unsigned long V_29 ;
T_5 V_10 ;
F_60 ( & V_67 , V_29 ) ;
if ( ! V_64 . V_10 )
goto V_72;
if ( V_209 < V_16 && ! V_64 . V_161 )
goto V_72;
V_10 = F_97 ( V_32 , V_20 ) ;
F_107 ( & V_67 ) ;
F_136 () ;
F_78 ( V_64 . V_27 , V_32 , V_10 ) ;
F_137 () ;
F_101 ( V_29 ) ;
return;
V_72:
F_61 ( & V_67 , V_29 ) ;
}
void F_110 ( void )
{
static char V_32 [ V_52 + V_127 ] ;
static T_3 V_210 ;
unsigned long V_29 ;
bool V_211 = false ;
bool V_212 ;
if ( V_198 ) {
F_92 () ;
return;
}
V_208 = 0 ;
F_135 ( V_32 , sizeof( V_32 ) ) ;
V_213:
for (; ; ) {
struct V_6 * V_7 ;
T_5 V_10 ;
int V_27 ;
F_60 ( & V_67 , V_29 ) ;
if ( V_210 != V_16 ) {
V_211 = true ;
V_210 = V_16 ;
}
if ( V_209 < V_15 ) {
V_10 = sprintf ( V_32 , L_26 ,
( unsigned ) ( V_15 - V_209 ) ) ;
V_209 = V_15 ;
V_214 = V_14 ;
V_164 = 0 ;
} else {
V_10 = 0 ;
}
V_129:
if ( V_209 == V_16 )
break;
V_7 = F_8 ( V_214 ) ;
if ( V_7 -> V_29 & V_162 ) {
V_214 = F_9 ( V_214 ) ;
V_209 ++ ;
V_7 -> V_29 &= ~ V_162 ;
V_164 = V_7 -> V_29 ;
goto V_129;
}
V_27 = V_7 -> V_27 ;
V_10 += F_73 ( V_7 , V_164 , false ,
V_32 + V_10 , sizeof( V_32 ) - V_10 ) ;
V_214 = F_9 ( V_214 ) ;
V_209 ++ ;
V_164 = V_7 -> V_29 ;
F_107 ( & V_67 ) ;
F_136 () ;
F_78 ( V_27 , V_32 , V_10 ) ;
F_137 () ;
F_101 ( V_29 ) ;
}
V_157 = 0 ;
if ( F_58 ( V_151 ) )
V_151 = NULL ;
F_107 ( & V_67 ) ;
F_92 () ;
F_103 ( & V_67 ) ;
V_212 = V_209 != V_16 ;
F_61 ( & V_67 , V_29 ) ;
if ( V_212 && F_91 () )
goto V_213;
if ( V_211 )
F_138 () ;
}
void T_13 F_139 ( void )
{
if ( V_208 )
F_140 () ;
}
void F_141 ( void )
{
struct V_148 * V_78 ;
if ( V_176 ) {
if ( F_133 () != 0 )
return;
} else
F_128 () ;
V_157 = 1 ;
V_208 = 0 ;
F_80 (c)
if ( ( V_78 -> V_29 & V_152 ) && V_78 -> V_215 )
V_78 -> V_215 () ;
F_110 () ;
}
struct V_216 * F_142 ( int * V_190 )
{
struct V_148 * V_78 ;
struct V_216 * V_217 = NULL ;
F_128 () ;
F_80 (c) {
if ( ! V_78 -> V_218 )
continue;
V_217 = V_78 -> V_218 ( V_78 , V_190 ) ;
if ( V_217 )
break;
}
F_110 () ;
return V_217 ;
}
void F_143 ( struct V_148 * V_148 )
{
F_128 () ;
V_148 -> V_29 &= ~ V_152 ;
F_110 () ;
}
void F_144 ( struct V_148 * V_148 )
{
F_128 () ;
V_148 -> V_29 |= V_152 ;
F_110 () ;
}
static int T_9 F_145 ( char * V_99 )
{
V_219 = 1 ;
F_54 ( L_27 ) ;
return 0 ;
}
void F_146 ( struct V_148 * V_220 )
{
int V_48 ;
unsigned long V_29 ;
struct V_148 * V_221 = NULL ;
struct V_188 * V_78 ;
if ( V_150 )
F_80 (bcon)
if ( F_147 ( V_221 == V_220 ,
L_28 ,
V_221 -> V_185 , V_221 -> V_190 ) )
return;
if ( V_150 && V_220 -> V_29 & V_222 ) {
F_80 (bcon) {
if ( ! ( V_221 -> V_29 & V_222 ) ) {
F_54 ( L_29 ,
V_220 -> V_185 , V_220 -> V_190 ) ;
return;
}
}
}
if ( V_150 && V_150 -> V_29 & V_222 )
V_221 = V_150 ;
if ( V_223 < 0 || V_221 || ! V_150 )
V_223 = V_191 ;
if ( V_220 -> V_224 )
V_220 -> V_224 () ;
if ( V_223 < 0 ) {
if ( V_220 -> V_190 < 0 )
V_220 -> V_190 = 0 ;
if ( V_220 -> V_225 == NULL ||
V_220 -> V_225 ( V_220 , NULL ) == 0 ) {
V_220 -> V_29 |= V_152 ;
if ( V_220 -> V_218 ) {
V_220 -> V_29 |= V_226 ;
V_223 = 0 ;
}
}
}
for ( V_48 = 0 , V_78 = V_188 ;
V_48 < V_189 && V_78 -> V_185 [ 0 ] ;
V_48 ++ , V_78 ++ ) {
if ( strcmp ( V_78 -> V_185 , V_220 -> V_185 ) != 0 )
continue;
if ( V_220 -> V_190 >= 0 &&
V_220 -> V_190 != V_78 -> V_190 )
continue;
if ( V_220 -> V_190 < 0 )
V_220 -> V_190 = V_78 -> V_190 ;
if ( F_148 ( V_220 , V_78 ) )
return;
if ( V_220 -> V_225 &&
V_220 -> V_225 ( V_220 , V_188 [ V_48 ] . V_186 ) != 0 )
break;
V_220 -> V_29 |= V_152 ;
V_220 -> V_190 = V_78 -> V_190 ;
if ( V_48 == V_191 ) {
V_220 -> V_29 |= V_226 ;
V_223 = V_191 ;
}
break;
}
if ( ! ( V_220 -> V_29 & V_152 ) )
return;
if ( V_221 && ( ( V_220 -> V_29 & ( V_226 | V_222 ) ) == V_226 ) )
V_220 -> V_29 &= ~ V_227 ;
F_128 () ;
if ( ( V_220 -> V_29 & V_226 ) || V_150 == NULL ) {
V_220 -> V_126 = V_150 ;
V_150 = V_220 ;
if ( V_220 -> V_126 )
V_220 -> V_126 -> V_29 &= ~ V_226 ;
} else {
V_220 -> V_126 = V_150 -> V_126 ;
V_150 -> V_126 = V_220 ;
}
if ( V_220 -> V_29 & V_227 ) {
F_60 ( & V_67 , V_29 ) ;
V_209 = V_130 ;
V_214 = V_131 ;
V_164 = V_132 ;
F_61 ( & V_67 , V_29 ) ;
V_151 = V_220 ;
}
F_110 () ;
F_149 () ;
F_54 ( L_30 ,
( V_220 -> V_29 & V_222 ) ? L_31 : L_32 ,
V_220 -> V_185 , V_220 -> V_190 ) ;
if ( V_221 &&
( ( V_220 -> V_29 & ( V_226 | V_222 ) ) == V_226 ) &&
! V_219 ) {
F_80 (bcon)
if ( V_221 -> V_29 & V_222 )
F_150 ( V_221 ) ;
}
}
int F_150 ( struct V_148 * V_148 )
{
struct V_148 * V_228 , * V_229 ;
int V_230 ;
F_54 ( L_33 ,
( V_148 -> V_29 & V_222 ) ? L_31 : L_32 ,
V_148 -> V_185 , V_148 -> V_190 ) ;
V_230 = F_151 ( V_148 ) ;
if ( V_230 )
return V_230 ;
V_230 = 1 ;
F_128 () ;
if ( V_150 == V_148 ) {
V_150 = V_148 -> V_126 ;
V_230 = 0 ;
} else if ( V_150 ) {
for ( V_228 = V_150 -> V_126 , V_229 = V_150 ;
V_228 ; V_229 = V_228 , V_228 = V_229 -> V_126 ) {
if ( V_228 == V_148 ) {
V_229 -> V_126 = V_228 -> V_126 ;
V_230 = 0 ;
break;
}
}
}
if ( V_150 != NULL && V_148 -> V_29 & V_226 )
V_150 -> V_29 |= V_226 ;
V_148 -> V_29 &= ~ V_152 ;
F_110 () ;
F_149 () ;
return V_230 ;
}
static int T_9 F_152 ( void )
{
struct V_148 * V_149 ;
F_80 (con) {
if ( ! V_219 && V_149 -> V_29 & V_222 ) {
F_150 ( V_149 ) ;
}
}
F_153 ( F_131 , 0 ) ;
return 0 ;
}
static void F_154 ( struct V_231 * V_231 )
{
int V_232 = F_155 ( V_233 , 0 ) ;
if ( V_232 & V_234 ) {
if ( F_91 () )
F_110 () ;
}
if ( V_232 & V_235 )
F_156 ( & V_73 ) ;
}
void F_138 ( void )
{
F_109 () ;
if ( F_157 ( & V_73 ) ) {
F_158 ( V_233 , V_235 ) ;
F_159 ( F_160 ( & V_236 ) ) ;
}
F_111 () ;
}
int F_161 ( const char * V_166 , ... )
{
T_11 args ;
int V_181 ;
F_109 () ;
va_start ( args , V_166 ) ;
V_181 = F_98 ( 0 , V_175 , NULL , 0 , V_166 , args ) ;
va_end ( args ) ;
F_162 ( V_233 , V_234 ) ;
F_159 ( F_160 ( & V_236 ) ) ;
F_111 () ;
return V_181 ;
}
int F_163 ( const char * V_237 )
{
return F_164 ( & V_238 , V_237 ) ;
}
bool F_165 ( unsigned long * V_239 ,
unsigned int V_240 )
{
unsigned long V_241 = V_117 - * V_239 ;
if ( * V_239 && V_241 <= F_67 ( V_240 ) )
return false ;
* V_239 = V_117 ;
return true ;
}
int F_166 ( struct V_242 * V_243 )
{
unsigned long V_29 ;
int V_94 = - V_244 ;
if ( ! V_243 -> V_245 )
return - V_53 ;
F_167 ( & V_246 , V_29 ) ;
if ( ! V_243 -> V_247 ) {
V_243 -> V_247 = 1 ;
F_168 ( & V_243 -> V_248 , & V_249 ) ;
V_94 = 0 ;
}
F_169 ( & V_246 , V_29 ) ;
return V_94 ;
}
int F_170 ( struct V_242 * V_243 )
{
unsigned long V_29 ;
int V_94 = - V_53 ;
F_167 ( & V_246 , V_29 ) ;
if ( V_243 -> V_247 ) {
V_243 -> V_247 = 0 ;
F_171 ( & V_243 -> V_248 ) ;
V_94 = 0 ;
}
F_169 ( & V_246 , V_29 ) ;
F_172 () ;
return V_94 ;
}
void F_173 ( enum V_250 V_251 )
{
struct V_242 * V_243 ;
unsigned long V_29 ;
if ( ( V_251 > V_252 ) && ! V_253 )
return;
F_174 () ;
F_175 (dumper, &dump_list, list) {
if ( V_243 -> V_254 && V_251 > V_243 -> V_254 )
continue;
V_243 -> V_255 = true ;
F_60 ( & V_67 , V_29 ) ;
V_243 -> V_256 = V_85 ;
V_243 -> V_257 = V_84 ;
V_243 -> V_135 = V_16 ;
V_243 -> V_258 = V_13 ;
F_61 ( & V_67 , V_29 ) ;
V_243 -> V_245 ( V_243 , V_251 ) ;
V_243 -> V_255 = false ;
}
F_176 () ;
}
bool F_177 ( struct V_242 * V_243 , bool V_121 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
struct V_6 * V_7 ;
T_5 V_259 = 0 ;
bool V_51 = false ;
if ( ! V_243 -> V_255 )
goto V_72;
if ( V_243 -> V_256 < V_15 ) {
V_243 -> V_256 = V_15 ;
V_243 -> V_257 = V_14 ;
}
if ( V_243 -> V_256 >= V_16 )
goto V_72;
V_7 = F_8 ( V_243 -> V_257 ) ;
V_259 = F_73 ( V_7 , 0 , V_121 , line , V_20 ) ;
V_243 -> V_257 = F_9 ( V_243 -> V_257 ) ;
V_243 -> V_256 ++ ;
V_51 = true ;
V_72:
if ( V_10 )
* V_10 = V_259 ;
return V_51 ;
}
bool F_178 ( struct V_242 * V_243 , bool V_121 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
bool V_51 ;
F_60 ( & V_67 , V_29 ) ;
V_51 = F_177 ( V_243 , V_121 , line , V_20 , V_10 ) ;
F_61 ( & V_67 , V_29 ) ;
return V_51 ;
}
bool F_179 ( struct V_242 * V_243 , bool V_121 ,
char * V_47 , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
T_3 V_68 ;
T_1 V_9 ;
T_3 V_135 ;
T_1 V_258 ;
enum V_28 V_76 ;
T_5 V_259 = 0 ;
bool V_51 = false ;
if ( ! V_243 -> V_255 )
goto V_72;
F_60 ( & V_67 , V_29 ) ;
if ( V_243 -> V_256 < V_15 ) {
V_243 -> V_256 = V_15 ;
V_243 -> V_257 = V_14 ;
}
if ( V_243 -> V_256 >= V_243 -> V_135 ) {
F_61 ( & V_67 , V_29 ) ;
goto V_72;
}
V_68 = V_243 -> V_256 ;
V_9 = V_243 -> V_257 ;
V_76 = 0 ;
while ( V_68 < V_243 -> V_135 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_259 += F_73 ( V_7 , V_76 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
}
V_68 = V_243 -> V_256 ;
V_9 = V_243 -> V_257 ;
V_76 = 0 ;
while ( V_259 > V_20 && V_68 < V_243 -> V_135 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_259 -= F_73 ( V_7 , V_76 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
}
V_135 = V_68 ;
V_258 = V_9 ;
V_259 = 0 ;
while ( V_68 < V_243 -> V_135 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_259 += F_73 ( V_7 , V_76 , V_121 , V_47 + V_259 , V_20 - V_259 ) ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
}
V_243 -> V_135 = V_135 ;
V_243 -> V_258 = V_258 ;
V_51 = true ;
F_61 ( & V_67 , V_29 ) ;
V_72:
if ( V_10 )
* V_10 = V_259 ;
return V_51 ;
}
void F_180 ( struct V_242 * V_243 )
{
V_243 -> V_256 = V_85 ;
V_243 -> V_257 = V_84 ;
V_243 -> V_135 = V_16 ;
V_243 -> V_258 = V_13 ;
}
void F_181 ( struct V_242 * V_243 )
{
unsigned long V_29 ;
F_60 ( & V_67 , V_29 ) ;
F_180 ( V_243 ) ;
F_61 ( & V_67 , V_29 ) ;
}
void T_9 F_182 ( const char * V_166 , ... )
{
T_11 args ;
va_start ( args , V_166 ) ;
vsnprintf ( V_260 , sizeof( V_260 ) ,
V_166 , args ) ;
va_end ( args ) ;
}
void F_183 ( const char * V_261 )
{
F_113 ( L_34 ,
V_261 , F_184 () , V_40 -> V_262 , V_40 -> V_41 ,
F_185 () , F_186 () -> V_263 ,
( int ) strcspn ( F_186 () -> V_264 , L_35 ) ,
F_186 () -> V_264 ) ;
if ( V_260 [ 0 ] != '\0' )
F_113 ( L_36 ,
V_261 , V_260 ) ;
F_187 ( V_261 , V_40 ) ;
}
void F_188 ( const char * V_261 )
{
F_183 ( V_261 ) ;
F_113 ( L_37 ,
V_261 , V_40 , F_189 () ,
F_190 ( V_40 ) ) ;
}
