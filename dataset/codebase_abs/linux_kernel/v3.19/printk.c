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
static int V_137 = V_138 ;
int error ;
error = F_18 ( type , V_36 ) ;
if ( error )
goto V_72;
error = F_22 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_139 :
break;
case V_37 :
break;
case V_140 :
error = - V_53 ;
if ( ! V_47 || V_10 < 0 )
goto V_72;
error = 0 ;
if ( ! V_10 )
goto V_72;
if ( ! F_77 ( V_141 , V_47 , V_10 ) ) {
error = - V_55 ;
goto V_72;
}
error = F_33 ( V_73 ,
V_130 != V_16 ) ;
if ( error )
goto V_72;
error = F_74 ( V_47 , V_10 ) ;
break;
case V_142 :
V_134 = true ;
case V_34 :
error = - V_53 ;
if ( ! V_47 || V_10 < 0 )
goto V_72;
error = 0 ;
if ( ! V_10 )
goto V_72;
if ( ! F_77 ( V_141 , V_47 , V_10 ) ) {
error = - V_55 ;
goto V_72;
}
error = F_75 ( V_47 , V_10 , V_134 ) ;
break;
case V_143 :
F_75 ( NULL , 0 , true ) ;
break;
case V_144 :
if ( V_137 == V_138 )
V_137 = V_116 ;
V_116 = V_145 ;
break;
case V_146 :
if ( V_137 != V_138 ) {
V_116 = V_137 ;
V_137 = V_138 ;
}
break;
case V_147 :
error = - V_53 ;
if ( V_10 < 1 || V_10 > 8 )
goto V_72;
if ( V_10 < V_145 )
V_10 = V_145 ;
V_116 = V_10 ;
V_137 = V_138 ;
error = 0 ;
break;
case V_148 :
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
struct V_149 * V_150 ;
F_79 ( V_32 , V_10 ) ;
if ( V_27 >= V_116 && ! V_106 )
return;
if ( ! V_151 )
return;
F_80 (con) {
if ( V_152 && V_150 != V_152 )
continue;
if ( ! ( V_150 -> V_29 & V_153 ) )
continue;
if ( ! V_150 -> V_154 )
continue;
if ( ! F_81 ( F_82 () ) &&
! ( V_150 -> V_29 & V_155 ) )
continue;
V_150 -> V_154 ( V_150 , V_32 , V_10 ) ;
}
}
static void F_83 ( void )
{
static unsigned long V_156 ;
if ( F_84 ( V_117 , V_156 ) &&
! F_69 ( V_117 , V_156 + 30 * V_110 ) )
return;
V_156 = V_117 ;
F_85 () ;
F_86 ( & V_67 ) ;
F_87 ( & V_2 , 1 ) ;
}
static int F_88 ( void )
{
struct V_149 * V_150 ;
F_80 (con)
if ( V_150 -> V_29 & V_155 )
return 1 ;
return 0 ;
}
static inline int F_89 ( unsigned int V_157 )
{
return F_81 ( V_157 ) || F_88 () ;
}
static int F_90 ( void )
{
unsigned int V_157 = F_82 () ;
if ( ! F_91 () )
return 0 ;
if ( ! F_89 ( V_157 ) ) {
V_158 = 0 ;
F_92 () ;
return 0 ;
}
return 1 ;
}
static inline void F_93 ( void )
{
if ( F_58 ( V_159 ) ) {
int V_160 = V_159 ;
while ( V_160 -- ) {
F_94 ( 1 ) ;
F_70 () ;
}
}
}
static void F_95 ( enum V_28 V_29 )
{
if ( V_64 . V_161 )
return;
if ( V_64 . V_10 == 0 )
return;
if ( V_64 . V_162 ) {
F_15 ( V_64 . V_26 , V_64 . V_27 , V_29 | V_163 ,
V_64 . V_30 , NULL , 0 , V_64 . V_47 , V_64 . V_10 ) ;
V_64 . V_29 = V_29 ;
V_64 . V_161 = true ;
} else {
F_15 ( V_64 . V_26 , V_64 . V_27 , V_29 , 0 ,
NULL , 0 , V_64 . V_47 , V_64 . V_10 ) ;
V_64 . V_10 = 0 ;
}
}
static bool F_96 ( int V_26 , int V_27 , const char * V_32 , T_5 V_10 )
{
if ( V_64 . V_10 && V_64 . V_161 )
return false ;
if ( V_64 . V_10 + V_10 > sizeof( V_64 . V_47 ) ) {
F_95 ( V_75 ) ;
return false ;
}
if ( ! V_64 . V_10 ) {
V_64 . V_26 = V_26 ;
V_64 . V_27 = V_27 ;
V_64 . V_164 = V_40 ;
V_64 . V_30 = F_16 () ;
V_64 . V_29 = 0 ;
V_64 . V_162 = 0 ;
V_64 . V_161 = false ;
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
if ( V_64 . V_162 == 0 && ( V_165 & V_125 ) ) {
V_136 += F_71 ( V_64 . V_30 , V_32 ) ;
V_20 -= V_136 ;
}
V_10 = V_64 . V_10 - V_64 . V_162 ;
if ( V_10 > 0 ) {
if ( V_10 + 1 > V_20 )
V_10 = V_20 - 1 ;
memcpy ( V_32 + V_136 , V_64 . V_47 + V_64 . V_162 , V_10 ) ;
V_136 += V_10 ;
V_64 . V_162 = V_64 . V_10 ;
}
if ( V_64 . V_161 ) {
if ( V_64 . V_29 & V_125 )
V_32 [ V_136 ++ ] = '\n' ;
V_64 . V_10 = 0 ;
}
return V_136 ;
}
T_10 int F_98 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_166 ,
const char * V_167 , T_11 args )
{
static int V_168 ;
static char V_169 [ V_52 ] ;
char * V_32 = V_169 ;
T_5 V_8 = 0 ;
enum V_28 V_170 = 0 ;
unsigned long V_29 ;
int V_171 ;
int V_172 = 0 ;
bool V_173 = false ;
static unsigned int V_174 = V_175 ;
if ( V_27 == V_176 ) {
V_27 = V_138 ;
V_173 = true ;
}
F_66 ( V_27 ) ;
F_93 () ;
F_99 ( V_29 ) ;
V_171 = F_82 () ;
if ( F_58 ( V_174 == V_171 ) ) {
if ( ! V_177 && ! F_100 ( V_40 ) ) {
V_168 = 1 ;
F_101 ( V_29 ) ;
return 0 ;
}
F_83 () ;
}
F_102 () ;
F_103 ( & V_67 ) ;
V_174 = V_171 ;
if ( F_58 ( V_168 ) ) {
static const char V_178 [] =
L_19 ;
V_168 = 0 ;
V_172 += F_15 ( 0 , 2 , V_77 | V_125 , 0 ,
NULL , 0 , V_178 ,
strlen ( V_178 ) ) ;
}
V_8 = F_104 ( V_32 , sizeof( V_169 ) , V_167 , args ) ;
if ( V_8 && V_32 [ V_8 - 1 ] == '\n' ) {
V_8 -- ;
V_170 |= V_125 ;
}
if ( V_26 == 0 ) {
int V_179 = F_105 ( V_32 ) ;
if ( V_179 ) {
const char * V_180 = F_106 ( V_32 ) ;
switch ( V_179 ) {
case '0' ... '7' :
if ( V_27 == V_138 )
V_27 = V_179 - '0' ;
case 'd' :
V_170 |= V_77 ;
}
V_8 -= V_180 - V_32 ;
V_32 = ( char * ) V_180 ;
}
}
if ( V_27 == V_138 )
V_27 = V_49 ;
if ( V_31 )
V_170 |= V_77 | V_125 ;
if ( ! ( V_170 & V_125 ) ) {
if ( V_64 . V_10 && ( V_170 & V_77 || V_64 . V_164 != V_40 ) )
F_95 ( V_125 ) ;
if ( F_96 ( V_26 , V_27 , V_32 , V_8 ) )
V_172 += V_8 ;
else
V_172 += F_15 ( V_26 , V_27 ,
V_170 | V_75 , 0 ,
V_31 , V_166 , V_32 , V_8 ) ;
} else {
bool V_181 = false ;
if ( V_64 . V_10 ) {
if ( V_64 . V_164 == V_40 && ! ( V_170 & V_77 ) )
V_181 = F_96 ( V_26 , V_27 , V_32 ,
V_8 ) ;
F_95 ( V_125 ) ;
}
if ( V_181 )
V_172 += V_8 ;
else
V_172 += F_15 ( V_26 , V_27 , V_170 , 0 ,
V_31 , V_166 , V_32 , V_8 ) ;
}
V_174 = V_175 ;
F_107 ( & V_67 ) ;
F_108 () ;
F_101 ( V_29 ) ;
if ( ! V_173 ) {
F_102 () ;
F_109 () ;
if ( F_90 () )
F_110 () ;
F_111 () ;
F_108 () ;
}
return V_172 ;
}
T_10 int F_112 ( const char * V_167 , T_11 args )
{
return F_98 ( 0 , V_138 , NULL , 0 , V_167 , args ) ;
}
T_10 int F_28 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_166 ,
const char * V_167 , ... )
{
T_11 args ;
int V_182 ;
va_start ( args , V_167 ) ;
V_182 = F_98 ( V_26 , V_27 , V_31 , V_166 , V_167 , args ) ;
va_end ( args ) ;
return V_182 ;
}
int F_113 ( const char * V_167 , T_11 args )
{
int V_182 ;
#ifdef F_114
if ( F_58 ( V_183 ) ) {
V_182 = F_115 ( V_167 , args ) ;
return V_182 ;
}
#endif
V_182 = F_98 ( 0 , V_138 , NULL , 0 , V_167 , args ) ;
return V_182 ;
}
T_10 T_12 int F_116 ( const char * V_167 , ... )
{
T_13 V_184 ;
T_11 args ;
int V_182 ;
va_start ( args , V_167 ) ;
V_184 = F_117 ( V_185 ) ;
V_182 = V_184 ( V_167 , args ) ;
va_end ( args ) ;
return V_182 ;
}
static struct V_6 * F_8 ( T_1 V_9 ) { return NULL ; }
static T_1 F_9 ( T_1 V_9 ) { return 0 ; }
static void F_78 ( int V_27 , const char * V_32 , T_5 V_10 ) {}
static T_5 F_73 ( const struct V_6 * V_7 , enum V_28 V_76 ,
bool V_121 , char * V_47 , T_5 V_20 ) { return 0 ; }
static T_5 F_97 ( char * V_32 , T_5 V_20 ) { return 0 ; }
T_10 T_12 void F_118 ( const char * V_167 , ... )
{
T_11 V_186 ;
char V_47 [ 512 ] ;
int V_128 ;
if ( ! V_187 )
return;
va_start ( V_186 , V_167 ) ;
V_128 = F_104 ( V_47 , sizeof( V_47 ) , V_167 , V_186 ) ;
va_end ( V_186 ) ;
V_187 -> V_154 ( V_187 , V_47 , V_128 ) ;
}
static int F_119 ( char * V_188 , int V_9 , char * V_189 ,
char * V_190 )
{
struct V_191 * V_78 ;
int V_48 ;
for ( V_48 = 0 , V_78 = V_191 ;
V_48 < V_192 && V_78 -> V_188 [ 0 ] ;
V_48 ++ , V_78 ++ ) {
if ( strcmp ( V_78 -> V_188 , V_188 ) == 0 && V_78 -> V_193 == V_9 ) {
if ( ! V_190 )
V_194 = V_48 ;
return 0 ;
}
}
if ( V_48 == V_192 )
return - V_195 ;
if ( ! V_190 )
V_194 = V_48 ;
F_120 ( V_78 -> V_188 , V_188 , sizeof( V_78 -> V_188 ) ) ;
V_78 -> V_189 = V_189 ;
F_121 ( V_78 , V_190 ) ;
V_78 -> V_193 = V_9 ;
return 0 ;
}
static int T_9 F_122 ( char * V_99 )
{
char V_47 [ sizeof( V_191 [ 0 ] . V_188 ) + 4 ] ;
char * V_196 , * V_189 , * V_190 = NULL ;
int V_9 ;
if ( F_123 ( & V_99 , & V_190 ) )
return 1 ;
if ( V_99 [ 0 ] >= '0' && V_99 [ 0 ] <= '9' ) {
strcpy ( V_47 , L_20 ) ;
strncpy ( V_47 + 4 , V_99 , sizeof( V_47 ) - 5 ) ;
} else {
strncpy ( V_47 , V_99 , sizeof( V_47 ) - 1 ) ;
}
V_47 [ sizeof( V_47 ) - 1 ] = 0 ;
V_189 = strchr ( V_99 , ',' ) ;
if ( V_189 )
* ( V_189 ++ ) = 0 ;
#ifdef F_124
if ( ! strcmp ( V_99 , L_21 ) )
strcpy ( V_47 , L_22 ) ;
if ( ! strcmp ( V_99 , L_23 ) )
strcpy ( V_47 , L_24 ) ;
#endif
for ( V_196 = V_47 ; * V_196 ; V_196 ++ )
if ( isdigit ( * V_196 ) || * V_196 == ',' )
break;
V_9 = F_27 ( V_196 , NULL , 10 ) ;
* V_196 = 0 ;
F_119 ( V_47 , V_9 , V_189 , V_190 ) ;
V_197 = 1 ;
return 1 ;
}
int F_125 ( char * V_188 , int V_9 , char * V_189 )
{
return F_119 ( V_188 , V_9 , V_189 , NULL ) ;
}
int F_126 ( char * V_188 , int V_9 , char * V_198 , int V_199 , char * V_189 )
{
struct V_191 * V_78 ;
int V_48 ;
for ( V_48 = 0 , V_78 = V_191 ;
V_48 < V_192 && V_78 -> V_188 [ 0 ] ;
V_48 ++ , V_78 ++ )
if ( strcmp ( V_78 -> V_188 , V_188 ) == 0 && V_78 -> V_193 == V_9 ) {
F_120 ( V_78 -> V_188 , V_198 , sizeof( V_78 -> V_188 ) ) ;
V_78 -> V_189 = V_189 ;
V_78 -> V_193 = V_199 ;
return V_48 ;
}
return - 1 ;
}
static int T_9 F_127 ( char * V_99 )
{
V_200 = false ;
return 1 ;
}
void F_128 ( void )
{
if ( ! V_200 )
return;
F_116 ( L_25 ) ;
F_129 () ;
V_201 = 1 ;
F_92 () ;
}
void F_130 ( void )
{
if ( ! V_200 )
return;
F_131 () ;
V_201 = 0 ;
F_110 () ;
}
static int F_132 ( struct V_202 * V_203 ,
unsigned long V_204 , void * V_205 )
{
switch ( V_204 ) {
case V_206 :
case V_207 :
case V_208 :
case V_209 :
F_129 () ;
F_110 () ;
}
return V_210 ;
}
void F_129 ( void )
{
F_133 () ;
F_131 () ;
if ( V_201 )
return;
V_158 = 1 ;
V_211 = 1 ;
}
int F_91 ( void )
{
if ( F_134 () )
return 0 ;
if ( V_201 ) {
F_92 () ;
return 0 ;
}
V_158 = 1 ;
V_211 = 0 ;
return 1 ;
}
int F_135 ( void )
{
return V_158 ;
}
static void F_136 ( char * V_32 , T_5 V_20 )
{
unsigned long V_29 ;
T_5 V_10 ;
F_60 ( & V_67 , V_29 ) ;
if ( ! V_64 . V_10 )
goto V_72;
if ( V_212 < V_16 && ! V_64 . V_162 )
goto V_72;
V_10 = F_97 ( V_32 , V_20 ) ;
F_107 ( & V_67 ) ;
F_137 () ;
F_78 ( V_64 . V_27 , V_32 , V_10 ) ;
F_138 () ;
F_101 ( V_29 ) ;
return;
V_72:
F_61 ( & V_67 , V_29 ) ;
}
void F_110 ( void )
{
static char V_32 [ V_52 + V_127 ] ;
static T_3 V_213 ;
unsigned long V_29 ;
bool V_214 = false ;
bool V_215 ;
if ( V_201 ) {
F_92 () ;
return;
}
V_211 = 0 ;
F_136 ( V_32 , sizeof( V_32 ) ) ;
V_216:
for (; ; ) {
struct V_6 * V_7 ;
T_5 V_10 ;
int V_27 ;
F_60 ( & V_67 , V_29 ) ;
if ( V_213 != V_16 ) {
V_214 = true ;
V_213 = V_16 ;
}
if ( V_212 < V_15 ) {
V_10 = sprintf ( V_32 , L_26 ,
( unsigned ) ( V_15 - V_212 ) ) ;
V_212 = V_15 ;
V_217 = V_14 ;
V_165 = 0 ;
} else {
V_10 = 0 ;
}
V_129:
if ( V_212 == V_16 )
break;
V_7 = F_8 ( V_217 ) ;
if ( V_7 -> V_29 & V_163 ) {
V_217 = F_9 ( V_217 ) ;
V_212 ++ ;
V_7 -> V_29 &= ~ V_163 ;
V_165 = V_7 -> V_29 ;
goto V_129;
}
V_27 = V_7 -> V_27 ;
V_10 += F_73 ( V_7 , V_165 , false ,
V_32 + V_10 , sizeof( V_32 ) - V_10 ) ;
V_217 = F_9 ( V_217 ) ;
V_212 ++ ;
V_165 = V_7 -> V_29 ;
F_107 ( & V_67 ) ;
F_137 () ;
F_78 ( V_27 , V_32 , V_10 ) ;
F_138 () ;
F_101 ( V_29 ) ;
}
V_158 = 0 ;
if ( F_58 ( V_152 ) )
V_152 = NULL ;
F_107 ( & V_67 ) ;
F_92 () ;
F_103 ( & V_67 ) ;
V_215 = V_212 != V_16 ;
F_61 ( & V_67 , V_29 ) ;
if ( V_215 && F_91 () )
goto V_216;
if ( V_214 )
F_139 () ;
}
void T_14 F_140 ( void )
{
if ( V_211 )
F_141 () ;
}
void F_142 ( void )
{
struct V_149 * V_78 ;
if ( V_177 ) {
if ( F_134 () != 0 )
return;
} else
F_129 () ;
V_158 = 1 ;
V_211 = 0 ;
F_80 (c)
if ( ( V_78 -> V_29 & V_153 ) && V_78 -> V_218 )
V_78 -> V_218 () ;
F_110 () ;
}
struct V_219 * F_143 ( int * V_193 )
{
struct V_149 * V_78 ;
struct V_219 * V_220 = NULL ;
F_129 () ;
F_80 (c) {
if ( ! V_78 -> V_221 )
continue;
V_220 = V_78 -> V_221 ( V_78 , V_193 ) ;
if ( V_220 )
break;
}
F_110 () ;
return V_220 ;
}
void F_144 ( struct V_149 * V_149 )
{
F_129 () ;
V_149 -> V_29 &= ~ V_153 ;
F_110 () ;
}
void F_145 ( struct V_149 * V_149 )
{
F_129 () ;
V_149 -> V_29 |= V_153 ;
F_110 () ;
}
static int T_9 F_146 ( char * V_99 )
{
V_222 = 1 ;
F_54 ( L_27 ) ;
return 0 ;
}
void F_147 ( struct V_149 * V_223 )
{
int V_48 ;
unsigned long V_29 ;
struct V_149 * V_224 = NULL ;
struct V_191 * V_78 ;
if ( V_151 )
F_80 (bcon)
if ( F_148 ( V_224 == V_223 ,
L_28 ,
V_224 -> V_188 , V_224 -> V_193 ) )
return;
if ( V_151 && V_223 -> V_29 & V_225 ) {
F_80 (bcon) {
if ( ! ( V_224 -> V_29 & V_225 ) ) {
F_54 ( L_29 ,
V_223 -> V_188 , V_223 -> V_193 ) ;
return;
}
}
}
if ( V_151 && V_151 -> V_29 & V_225 )
V_224 = V_151 ;
if ( V_226 < 0 || V_224 || ! V_151 )
V_226 = V_194 ;
if ( V_223 -> V_227 )
V_223 -> V_227 () ;
if ( V_226 < 0 ) {
if ( V_223 -> V_193 < 0 )
V_223 -> V_193 = 0 ;
if ( V_223 -> V_228 == NULL ||
V_223 -> V_228 ( V_223 , NULL ) == 0 ) {
V_223 -> V_29 |= V_153 ;
if ( V_223 -> V_221 ) {
V_223 -> V_29 |= V_229 ;
V_226 = 0 ;
}
}
}
for ( V_48 = 0 , V_78 = V_191 ;
V_48 < V_192 && V_78 -> V_188 [ 0 ] ;
V_48 ++ , V_78 ++ ) {
if ( strcmp ( V_78 -> V_188 , V_223 -> V_188 ) != 0 )
continue;
if ( V_223 -> V_193 >= 0 &&
V_223 -> V_193 != V_78 -> V_193 )
continue;
if ( V_223 -> V_193 < 0 )
V_223 -> V_193 = V_78 -> V_193 ;
if ( F_149 ( V_223 , V_78 ) )
return;
if ( V_223 -> V_228 &&
V_223 -> V_228 ( V_223 , V_191 [ V_48 ] . V_189 ) != 0 )
break;
V_223 -> V_29 |= V_153 ;
V_223 -> V_193 = V_78 -> V_193 ;
if ( V_48 == V_194 ) {
V_223 -> V_29 |= V_229 ;
V_226 = V_194 ;
}
break;
}
if ( ! ( V_223 -> V_29 & V_153 ) )
return;
if ( V_224 && ( ( V_223 -> V_29 & ( V_229 | V_225 ) ) == V_229 ) )
V_223 -> V_29 &= ~ V_230 ;
F_129 () ;
if ( ( V_223 -> V_29 & V_229 ) || V_151 == NULL ) {
V_223 -> V_126 = V_151 ;
V_151 = V_223 ;
if ( V_223 -> V_126 )
V_223 -> V_126 -> V_29 &= ~ V_229 ;
} else {
V_223 -> V_126 = V_151 -> V_126 ;
V_151 -> V_126 = V_223 ;
}
if ( V_223 -> V_29 & V_230 ) {
F_60 ( & V_67 , V_29 ) ;
V_212 = V_130 ;
V_217 = V_131 ;
V_165 = V_132 ;
F_61 ( & V_67 , V_29 ) ;
V_152 = V_223 ;
}
F_110 () ;
F_150 () ;
F_54 ( L_30 ,
( V_223 -> V_29 & V_225 ) ? L_31 : L_32 ,
V_223 -> V_188 , V_223 -> V_193 ) ;
if ( V_224 &&
( ( V_223 -> V_29 & ( V_229 | V_225 ) ) == V_229 ) &&
! V_222 ) {
F_80 (bcon)
if ( V_224 -> V_29 & V_225 )
F_151 ( V_224 ) ;
}
}
int F_151 ( struct V_149 * V_149 )
{
struct V_149 * V_231 , * V_232 ;
int V_233 ;
F_54 ( L_33 ,
( V_149 -> V_29 & V_225 ) ? L_31 : L_32 ,
V_149 -> V_188 , V_149 -> V_193 ) ;
V_233 = F_152 ( V_149 ) ;
if ( V_233 )
return V_233 ;
V_233 = 1 ;
F_129 () ;
if ( V_151 == V_149 ) {
V_151 = V_149 -> V_126 ;
V_233 = 0 ;
} else if ( V_151 ) {
for ( V_231 = V_151 -> V_126 , V_232 = V_151 ;
V_231 ; V_232 = V_231 , V_231 = V_232 -> V_126 ) {
if ( V_231 == V_149 ) {
V_232 -> V_126 = V_231 -> V_126 ;
V_233 = 0 ;
break;
}
}
}
if ( V_151 != NULL && V_149 -> V_29 & V_229 )
V_151 -> V_29 |= V_229 ;
V_149 -> V_29 &= ~ V_153 ;
F_110 () ;
F_150 () ;
return V_233 ;
}
static int T_9 F_153 ( void )
{
struct V_149 * V_150 ;
F_80 (con) {
if ( ! V_222 && V_150 -> V_29 & V_225 ) {
F_151 ( V_150 ) ;
}
}
F_154 ( F_132 , 0 ) ;
return 0 ;
}
static void F_155 ( struct V_234 * V_234 )
{
int V_235 = F_156 ( V_236 , 0 ) ;
if ( V_235 & V_237 ) {
if ( F_91 () )
F_110 () ;
}
if ( V_235 & V_238 )
F_157 ( & V_73 ) ;
}
void F_139 ( void )
{
F_109 () ;
if ( F_158 ( & V_73 ) ) {
F_159 ( V_236 , V_238 ) ;
F_160 ( F_161 ( & V_239 ) ) ;
}
F_111 () ;
}
int F_162 ( const char * V_167 , ... )
{
T_11 args ;
int V_182 ;
F_109 () ;
va_start ( args , V_167 ) ;
V_182 = F_98 ( 0 , V_176 , NULL , 0 , V_167 , args ) ;
va_end ( args ) ;
F_163 ( V_236 , V_237 ) ;
F_160 ( F_161 ( & V_239 ) ) ;
F_111 () ;
return V_182 ;
}
int F_164 ( const char * V_240 )
{
return F_165 ( & V_241 , V_240 ) ;
}
bool F_166 ( unsigned long * V_242 ,
unsigned int V_243 )
{
unsigned long V_244 = V_117 - * V_242 ;
if ( * V_242 && V_244 <= F_67 ( V_243 ) )
return false ;
* V_242 = V_117 ;
return true ;
}
int F_167 ( struct V_245 * V_246 )
{
unsigned long V_29 ;
int V_94 = - V_247 ;
if ( ! V_246 -> V_248 )
return - V_53 ;
F_168 ( & V_249 , V_29 ) ;
if ( ! V_246 -> V_250 ) {
V_246 -> V_250 = 1 ;
F_169 ( & V_246 -> V_251 , & V_252 ) ;
V_94 = 0 ;
}
F_170 ( & V_249 , V_29 ) ;
return V_94 ;
}
int F_171 ( struct V_245 * V_246 )
{
unsigned long V_29 ;
int V_94 = - V_53 ;
F_168 ( & V_249 , V_29 ) ;
if ( V_246 -> V_250 ) {
V_246 -> V_250 = 0 ;
F_172 ( & V_246 -> V_251 ) ;
V_94 = 0 ;
}
F_170 ( & V_249 , V_29 ) ;
F_173 () ;
return V_94 ;
}
void F_174 ( enum V_253 V_254 )
{
struct V_245 * V_246 ;
unsigned long V_29 ;
if ( ( V_254 > V_255 ) && ! V_256 )
return;
F_175 () ;
F_176 (dumper, &dump_list, list) {
if ( V_246 -> V_257 && V_254 > V_246 -> V_257 )
continue;
V_246 -> V_258 = true ;
F_60 ( & V_67 , V_29 ) ;
V_246 -> V_259 = V_85 ;
V_246 -> V_260 = V_84 ;
V_246 -> V_135 = V_16 ;
V_246 -> V_261 = V_13 ;
F_61 ( & V_67 , V_29 ) ;
V_246 -> V_248 ( V_246 , V_254 ) ;
V_246 -> V_258 = false ;
}
F_177 () ;
}
bool F_178 ( struct V_245 * V_246 , bool V_121 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
struct V_6 * V_7 ;
T_5 V_262 = 0 ;
bool V_51 = false ;
if ( ! V_246 -> V_258 )
goto V_72;
if ( V_246 -> V_259 < V_15 ) {
V_246 -> V_259 = V_15 ;
V_246 -> V_260 = V_14 ;
}
if ( V_246 -> V_259 >= V_16 )
goto V_72;
V_7 = F_8 ( V_246 -> V_260 ) ;
V_262 = F_73 ( V_7 , 0 , V_121 , line , V_20 ) ;
V_246 -> V_260 = F_9 ( V_246 -> V_260 ) ;
V_246 -> V_259 ++ ;
V_51 = true ;
V_72:
if ( V_10 )
* V_10 = V_262 ;
return V_51 ;
}
bool F_179 ( struct V_245 * V_246 , bool V_121 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
bool V_51 ;
F_60 ( & V_67 , V_29 ) ;
V_51 = F_178 ( V_246 , V_121 , line , V_20 , V_10 ) ;
F_61 ( & V_67 , V_29 ) ;
return V_51 ;
}
bool F_180 ( struct V_245 * V_246 , bool V_121 ,
char * V_47 , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
T_3 V_68 ;
T_1 V_9 ;
T_3 V_135 ;
T_1 V_261 ;
enum V_28 V_76 ;
T_5 V_262 = 0 ;
bool V_51 = false ;
if ( ! V_246 -> V_258 )
goto V_72;
F_60 ( & V_67 , V_29 ) ;
if ( V_246 -> V_259 < V_15 ) {
V_246 -> V_259 = V_15 ;
V_246 -> V_260 = V_14 ;
}
if ( V_246 -> V_259 >= V_246 -> V_135 ) {
F_61 ( & V_67 , V_29 ) ;
goto V_72;
}
V_68 = V_246 -> V_259 ;
V_9 = V_246 -> V_260 ;
V_76 = 0 ;
while ( V_68 < V_246 -> V_135 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_262 += F_73 ( V_7 , V_76 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
}
V_68 = V_246 -> V_259 ;
V_9 = V_246 -> V_260 ;
V_76 = 0 ;
while ( V_262 > V_20 && V_68 < V_246 -> V_135 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_262 -= F_73 ( V_7 , V_76 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
}
V_135 = V_68 ;
V_261 = V_9 ;
V_262 = 0 ;
while ( V_68 < V_246 -> V_135 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_262 += F_73 ( V_7 , V_76 , V_121 , V_47 + V_262 , V_20 - V_262 ) ;
V_9 = F_9 ( V_9 ) ;
V_68 ++ ;
V_76 = V_7 -> V_29 ;
}
V_246 -> V_135 = V_135 ;
V_246 -> V_261 = V_261 ;
V_51 = true ;
F_61 ( & V_67 , V_29 ) ;
V_72:
if ( V_10 )
* V_10 = V_262 ;
return V_51 ;
}
void F_181 ( struct V_245 * V_246 )
{
V_246 -> V_259 = V_85 ;
V_246 -> V_260 = V_84 ;
V_246 -> V_135 = V_16 ;
V_246 -> V_261 = V_13 ;
}
void F_182 ( struct V_245 * V_246 )
{
unsigned long V_29 ;
F_60 ( & V_67 , V_29 ) ;
F_181 ( V_246 ) ;
F_61 ( & V_67 , V_29 ) ;
}
void T_9 F_183 ( const char * V_167 , ... )
{
T_11 args ;
va_start ( args , V_167 ) ;
vsnprintf ( V_263 , sizeof( V_263 ) ,
V_167 , args ) ;
va_end ( args ) ;
}
void F_184 ( const char * V_264 )
{
F_116 ( L_34 ,
V_264 , F_185 () , V_40 -> V_265 , V_40 -> V_41 ,
F_186 () , F_187 () -> V_266 ,
( int ) strcspn ( F_187 () -> V_267 , L_35 ) ,
F_187 () -> V_267 ) ;
if ( V_263 [ 0 ] != '\0' )
F_116 ( L_36 ,
V_264 , V_263 ) ;
F_188 ( V_264 , V_40 ) ;
}
void F_189 ( const char * V_264 )
{
F_184 ( V_264 ) ;
F_116 ( L_37 ,
V_264 , V_40 , F_190 () ,
F_191 ( V_40 ) ) ;
}
