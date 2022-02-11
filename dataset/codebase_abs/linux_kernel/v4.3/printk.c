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
int V_56 ;
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
V_56 = F_33 ( line + 1 , & V_67 , 10 ) ;
if ( V_67 && V_67 [ 0 ] == '>' ) {
V_27 = V_56 & 7 ;
if ( V_56 >> 3 )
V_26 = V_56 >> 3 ;
V_67 ++ ;
V_10 -= V_67 - line ;
line = V_67 ;
}
}
F_34 ( V_26 , V_27 , NULL , 0 , L_6 , line ) ;
F_32 ( V_48 ) ;
return V_62 ;
}
static T_4 F_35 ( struct V_68 * V_68 , char T_6 * V_48 ,
T_5 V_69 , T_7 * V_70 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_6 * V_7 ;
T_5 V_10 ;
T_4 V_62 ;
if ( ! V_72 )
return - V_74 ;
V_62 = F_36 ( & V_72 -> V_75 ) ;
if ( V_62 )
return V_62 ;
F_37 ( & V_76 ) ;
while ( V_72 -> V_49 == V_16 ) {
if ( V_68 -> V_77 & V_78 ) {
V_62 = - V_79 ;
F_38 ( & V_76 ) ;
goto V_80;
}
F_38 ( & V_76 ) ;
V_62 = F_39 ( V_81 ,
V_72 -> V_49 != V_16 ) ;
if ( V_62 )
goto V_80;
F_37 ( & V_76 ) ;
}
if ( V_72 -> V_49 < V_15 ) {
V_72 -> V_9 = V_14 ;
V_72 -> V_49 = V_15 ;
V_62 = - V_82 ;
F_38 ( & V_76 ) ;
goto V_80;
}
V_7 = F_8 ( V_72 -> V_9 ) ;
V_10 = F_24 ( V_72 -> V_48 , sizeof( V_72 -> V_48 ) ,
V_7 , V_72 -> V_49 , V_72 -> V_83 ) ;
V_10 += F_27 ( V_72 -> V_48 + V_10 , sizeof( V_72 -> V_48 ) - V_10 ,
F_7 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_7 ) , V_7 -> V_8 ) ;
V_72 -> V_83 = V_7 -> V_29 ;
V_72 -> V_9 = F_9 ( V_72 -> V_9 ) ;
V_72 -> V_49 ++ ;
F_38 ( & V_76 ) ;
if ( V_10 > V_69 ) {
V_62 = - V_64 ;
goto V_80;
}
if ( F_40 ( V_48 , V_72 -> V_48 , V_10 ) ) {
V_62 = - V_66 ;
goto V_80;
}
V_62 = V_10 ;
V_80:
F_41 ( & V_72 -> V_75 ) ;
return V_62 ;
}
static T_7 F_42 ( struct V_68 * V_68 , T_7 V_84 , int V_85 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
T_7 V_62 = 0 ;
if ( ! V_72 )
return - V_74 ;
if ( V_84 )
return - V_86 ;
F_37 ( & V_76 ) ;
switch ( V_85 ) {
case V_87 :
V_72 -> V_9 = V_14 ;
V_72 -> V_49 = V_15 ;
break;
case V_88 :
V_72 -> V_9 = V_89 ;
V_72 -> V_49 = V_90 ;
break;
case V_91 :
V_72 -> V_9 = V_13 ;
V_72 -> V_49 = V_16 ;
break;
default:
V_62 = - V_64 ;
}
F_38 ( & V_76 ) ;
return V_62 ;
}
static unsigned int F_43 ( struct V_68 * V_68 , T_8 * V_92 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
int V_62 = 0 ;
if ( ! V_72 )
return V_93 | V_94 ;
F_44 ( V_68 , & V_81 , V_92 ) ;
F_37 ( & V_76 ) ;
if ( V_72 -> V_49 < V_16 ) {
if ( V_72 -> V_49 < V_15 )
V_62 = V_95 | V_96 | V_93 | V_97 ;
else
V_62 = V_95 | V_96 ;
}
F_38 ( & V_76 ) ;
return V_62 ;
}
static int F_45 ( struct V_98 * V_98 , struct V_68 * V_68 )
{
struct V_71 * V_72 ;
int V_99 ;
if ( ( V_68 -> V_77 & V_100 ) == V_101 )
return 0 ;
V_99 = F_18 ( V_34 ,
V_102 ) ;
if ( V_99 )
return V_99 ;
V_72 = F_30 ( sizeof( struct V_71 ) , V_65 ) ;
if ( ! V_72 )
return - V_17 ;
F_46 ( & V_72 -> V_75 ) ;
F_37 ( & V_76 ) ;
V_72 -> V_9 = V_14 ;
V_72 -> V_49 = V_15 ;
F_38 ( & V_76 ) ;
V_68 -> V_73 = V_72 ;
return 0 ;
}
static int F_47 ( struct V_98 * V_98 , struct V_68 * V_68 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
if ( ! V_72 )
return 0 ;
F_48 ( & V_72 -> V_75 ) ;
F_32 ( V_72 ) ;
return 0 ;
}
void F_49 ( void )
{
F_50 ( V_4 ) ;
F_50 ( V_5 ) ;
F_50 ( V_14 ) ;
F_50 ( V_13 ) ;
F_51 ( V_6 ) ;
F_52 ( V_6 , V_30 ) ;
F_52 ( V_6 , V_10 ) ;
F_52 ( V_6 , V_8 ) ;
F_52 ( V_6 , V_18 ) ;
}
static void T_9 F_53 ( unsigned V_20 )
{
if ( V_20 )
V_20 = F_54 ( V_20 ) ;
if ( V_20 > V_5 )
V_103 = V_20 ;
}
static int T_9 F_55 ( char * V_104 )
{
unsigned V_20 = F_56 ( V_104 , & V_104 ) ;
F_53 ( V_20 ) ;
return 0 ;
}
static void T_9 F_57 ( void )
{
unsigned int V_105 ;
if ( F_58 () == 1 )
return;
V_105 = ( F_58 () - 1 ) * V_106 ;
if ( V_105 <= V_107 / 2 )
return;
F_59 ( L_7 ,
V_106 ) ;
F_59 ( L_8 ,
V_105 ) ;
F_59 ( L_9 , V_107 ) ;
F_53 ( V_105 + V_107 ) ;
}
static inline void F_57 ( void ) {}
void T_9 F_60 ( int V_108 )
{
unsigned long V_29 ;
char * V_109 ;
int free ;
if ( V_4 != V_110 )
return;
if ( ! V_108 && ! V_103 )
F_57 () ;
if ( ! V_103 )
return;
if ( V_108 ) {
V_109 =
F_61 ( V_103 , V_21 ) ;
} else {
V_109 = F_62 ( V_103 ,
V_21 ) ;
}
if ( F_63 ( ! V_109 ) ) {
F_64 ( L_10 ,
V_103 ) ;
return;
}
F_65 ( & V_76 , V_29 ) ;
V_5 = V_103 ;
V_4 = V_109 ;
V_103 = 0 ;
free = V_107 - V_13 ;
memcpy ( V_4 , V_110 , V_107 ) ;
F_66 ( & V_76 , V_29 ) ;
F_59 ( L_11 , V_5 ) ;
F_59 ( L_12 ,
free , ( free * 100 ) / V_107 ) ;
}
static int T_9 F_67 ( char * V_104 )
{
V_111 = true ;
F_59 ( L_13 ) ;
return 0 ;
}
static int T_9 F_68 ( char * V_104 )
{
unsigned long V_112 ;
V_112 = V_113 ? V_113 : 1000000 ;
V_114 = ( unsigned long long ) V_112 / 1000 * V_115 ;
F_69 ( & V_104 , & V_116 ) ;
if ( V_116 > 10 * 1000 )
V_116 = 0 ;
F_70 ( L_14
L_15 ,
V_116 , V_113 , V_112 , V_115 , V_114 ) ;
return 0 ;
}
static void F_71 ( int V_27 )
{
unsigned long long V_117 ;
unsigned long V_118 ;
if ( ( V_116 == 0 || V_119 != V_120 )
|| ( V_27 >= V_121 && ! V_111 ) ) {
return;
}
V_117 = ( unsigned long long ) V_114 * V_116 ;
V_118 = V_122 + F_72 ( V_116 ) ;
while ( V_117 ) {
V_117 -- ;
F_73 () ;
if ( F_74 ( V_122 , V_118 ) )
break;
F_75 () ;
}
}
static inline void F_71 ( int V_27 )
{
}
static T_5 F_76 ( T_3 V_123 , char * V_48 )
{
unsigned long V_124 ;
if ( ! V_125 )
return 0 ;
V_124 = F_25 ( V_123 , 1000000000 ) ;
if ( ! V_48 )
return snprintf ( NULL , 0 , L_16 , ( unsigned long ) V_123 ) ;
return sprintf ( V_48 , L_17 ,
( unsigned long ) V_123 , V_124 / 1000 ) ;
}
static T_5 F_77 ( const struct V_6 * V_7 , bool V_126 , char * V_48 )
{
T_5 V_10 = 0 ;
unsigned int V_127 = ( V_7 -> V_26 << 3 ) | V_7 -> V_27 ;
if ( V_126 ) {
if ( V_48 ) {
V_10 += sprintf ( V_48 , L_18 , V_127 ) ;
} else {
V_10 += 3 ;
if ( V_127 > 999 )
V_10 += 3 ;
else if ( V_127 > 99 )
V_10 += 2 ;
else if ( V_127 > 9 )
V_10 ++ ;
}
}
V_10 += F_76 ( V_7 -> V_30 , V_48 ? V_48 + V_10 : NULL ) ;
return V_10 ;
}
static T_5 F_78 ( const struct V_6 * V_7 , enum V_28 V_83 ,
bool V_126 , char * V_48 , T_5 V_20 )
{
const char * V_32 = F_6 ( V_7 ) ;
T_5 V_128 = V_7 -> V_8 ;
bool V_127 = true ;
bool V_129 = true ;
T_5 V_10 = 0 ;
if ( ( V_83 & V_53 ) && ! ( V_7 -> V_29 & V_54 ) )
V_127 = false ;
if ( V_7 -> V_29 & V_53 ) {
if ( ( V_83 & V_53 ) && ! ( V_83 & V_130 ) )
V_127 = false ;
if ( ! ( V_7 -> V_29 & V_130 ) )
V_129 = false ;
}
do {
const char * V_131 = memchr ( V_32 , '\n' , V_128 ) ;
T_5 V_8 ;
if ( V_131 ) {
V_8 = V_131 - V_32 ;
V_131 ++ ;
V_128 -= V_131 - V_32 ;
} else {
V_8 = V_128 ;
}
if ( V_48 ) {
if ( F_77 ( V_7 , V_126 , NULL ) +
V_8 + 1 >= V_20 - V_10 )
break;
if ( V_127 )
V_10 += F_77 ( V_7 , V_126 , V_48 + V_10 ) ;
memcpy ( V_48 + V_10 , V_32 , V_8 ) ;
V_10 += V_8 ;
if ( V_131 || V_129 )
V_48 [ V_10 ++ ] = '\n' ;
} else {
if ( V_127 )
V_10 += F_77 ( V_7 , V_126 , NULL ) ;
V_10 += V_8 ;
if ( V_131 || V_129 )
V_10 ++ ;
}
V_127 = true ;
V_32 = V_131 ;
} while ( V_32 );
return V_10 ;
}
static int F_79 ( char T_6 * V_48 , int V_20 )
{
char * V_32 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
V_32 = F_30 ( V_63 + V_132 , V_65 ) ;
if ( ! V_32 )
return - V_17 ;
while ( V_20 > 0 ) {
T_5 V_133 ;
T_5 V_134 ;
F_37 ( & V_76 ) ;
if ( V_135 < V_15 ) {
V_135 = V_15 ;
V_136 = V_14 ;
V_137 = 0 ;
V_138 = 0 ;
}
if ( V_135 == V_16 ) {
F_38 ( & V_76 ) ;
break;
}
V_134 = V_138 ;
V_7 = F_8 ( V_136 ) ;
V_133 = F_78 ( V_7 , V_137 , true , V_32 ,
V_63 + V_132 ) ;
if ( V_133 - V_138 <= V_20 ) {
V_136 = F_9 ( V_136 ) ;
V_135 ++ ;
V_137 = V_7 -> V_29 ;
V_133 -= V_138 ;
V_138 = 0 ;
} else if ( ! V_10 ) {
V_133 = V_20 ;
V_138 += V_133 ;
} else
V_133 = 0 ;
F_38 ( & V_76 ) ;
if ( ! V_133 )
break;
if ( F_40 ( V_48 , V_32 + V_134 , V_133 ) ) {
if ( ! V_10 )
V_10 = - V_66 ;
break;
}
V_10 += V_133 ;
V_20 -= V_133 ;
V_48 += V_133 ;
}
F_32 ( V_32 ) ;
return V_10 ;
}
static int F_80 ( char T_6 * V_48 , int V_20 , bool V_139 )
{
char * V_32 ;
int V_10 = 0 ;
V_32 = F_30 ( V_63 + V_132 , V_65 ) ;
if ( ! V_32 )
return - V_17 ;
F_37 ( & V_76 ) ;
if ( V_48 ) {
T_3 V_140 ;
T_3 V_49 ;
T_1 V_9 ;
enum V_28 V_83 ;
if ( V_90 < V_15 ) {
V_90 = V_15 ;
V_89 = V_14 ;
}
V_49 = V_90 ;
V_9 = V_89 ;
V_83 = 0 ;
while ( V_49 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 += F_78 ( V_7 , V_83 , true , NULL , 0 ) ;
V_83 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
}
V_49 = V_90 ;
V_9 = V_89 ;
V_83 = 0 ;
while ( V_10 > V_20 && V_49 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 -= F_78 ( V_7 , V_83 , true , NULL , 0 ) ;
V_83 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
}
V_140 = V_16 ;
V_10 = 0 ;
while ( V_10 >= 0 && V_49 < V_140 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
int V_141 ;
V_141 = F_78 ( V_7 , V_83 , true , V_32 ,
V_63 + V_132 ) ;
if ( V_141 < 0 ) {
V_10 = V_141 ;
break;
}
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_83 = V_7 -> V_29 ;
F_38 ( & V_76 ) ;
if ( F_40 ( V_48 + V_10 , V_32 , V_141 ) )
V_10 = - V_66 ;
else
V_10 += V_141 ;
F_37 ( & V_76 ) ;
if ( V_49 < V_15 ) {
V_49 = V_15 ;
V_9 = V_14 ;
V_83 = 0 ;
}
}
}
if ( V_139 ) {
V_90 = V_16 ;
V_89 = V_13 ;
}
F_38 ( & V_76 ) ;
F_32 ( V_32 ) ;
return V_10 ;
}
int F_81 ( int type , char T_6 * V_48 , int V_10 , int V_36 )
{
bool V_139 = false ;
static int V_142 = V_143 ;
int error ;
error = F_18 ( type , V_36 ) ;
if ( error )
goto V_80;
switch ( type ) {
case V_144 :
break;
case V_38 :
break;
case V_145 :
error = - V_64 ;
if ( ! V_48 || V_10 < 0 )
goto V_80;
error = 0 ;
if ( ! V_10 )
goto V_80;
if ( ! F_82 ( V_146 , V_48 , V_10 ) ) {
error = - V_66 ;
goto V_80;
}
error = F_39 ( V_81 ,
V_135 != V_16 ) ;
if ( error )
goto V_80;
error = F_79 ( V_48 , V_10 ) ;
break;
case V_147 :
V_139 = true ;
case V_34 :
error = - V_64 ;
if ( ! V_48 || V_10 < 0 )
goto V_80;
error = 0 ;
if ( ! V_10 )
goto V_80;
if ( ! F_82 ( V_146 , V_48 , V_10 ) ) {
error = - V_66 ;
goto V_80;
}
error = F_80 ( V_48 , V_10 , V_139 ) ;
break;
case V_148 :
F_80 ( NULL , 0 , true ) ;
break;
case V_149 :
if ( V_142 == V_143 )
V_142 = V_121 ;
V_121 = V_150 ;
break;
case V_151 :
if ( V_142 != V_143 ) {
V_121 = V_142 ;
V_142 = V_143 ;
}
break;
case V_152 :
error = - V_64 ;
if ( V_10 < 1 || V_10 > 8 )
goto V_80;
if ( V_10 < V_150 )
V_10 = V_150 ;
V_121 = V_10 ;
V_142 = V_143 ;
error = 0 ;
break;
case V_153 :
F_37 ( & V_76 ) ;
if ( V_135 < V_15 ) {
V_135 = V_15 ;
V_136 = V_14 ;
V_137 = 0 ;
V_138 = 0 ;
}
if ( V_36 == V_37 ) {
error = V_16 - V_135 ;
} else {
T_3 V_49 = V_135 ;
T_1 V_9 = V_136 ;
enum V_28 V_83 = V_137 ;
error = 0 ;
while ( V_49 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
error += F_78 ( V_7 , V_83 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_83 = V_7 -> V_29 ;
}
error -= V_138 ;
}
F_38 ( & V_76 ) ;
break;
case V_35 :
error = V_5 ;
break;
default:
error = - V_64 ;
break;
}
V_80:
return error ;
}
static void F_83 ( int V_27 ,
const char * V_154 , T_5 V_155 ,
const char * V_32 , T_5 V_10 )
{
struct V_156 * V_157 ;
F_84 ( V_32 , V_10 ) ;
if ( V_27 >= V_121 && ! V_111 )
return;
if ( ! V_158 )
return;
F_85 (con) {
if ( V_159 && V_157 != V_159 )
continue;
if ( ! ( V_157 -> V_29 & V_160 ) )
continue;
if ( ! V_157 -> V_161 )
continue;
if ( ! F_86 ( F_87 () ) &&
! ( V_157 -> V_29 & V_162 ) )
continue;
if ( V_157 -> V_29 & V_163 )
V_157 -> V_161 ( V_157 , V_154 , V_155 ) ;
else
V_157 -> V_161 ( V_157 , V_32 , V_10 ) ;
}
}
static void F_88 ( void )
{
static unsigned long V_164 ;
if ( F_89 ( V_122 , V_164 ) &&
! F_74 ( V_122 , V_164 + 30 * V_115 ) )
return;
V_164 = V_122 ;
F_90 () ;
F_91 ( & V_76 ) ;
F_92 ( & V_2 , 1 ) ;
}
static int F_93 ( void )
{
struct V_156 * V_157 ;
F_85 (con)
if ( V_157 -> V_29 & V_162 )
return 1 ;
return 0 ;
}
static inline int F_94 ( unsigned int V_165 )
{
return F_86 ( V_165 ) || F_93 () ;
}
static int F_95 ( void )
{
unsigned int V_165 = F_87 () ;
if ( ! F_96 () )
return 0 ;
if ( ! F_94 ( V_165 ) ) {
V_166 = 0 ;
F_97 () ;
return 0 ;
}
return 1 ;
}
static inline void F_98 ( void )
{
if ( F_63 ( V_167 ) ) {
int V_168 = V_167 ;
while ( V_168 -- ) {
F_99 ( 1 ) ;
F_75 () ;
}
}
}
static void F_100 ( enum V_28 V_29 )
{
if ( V_52 . V_169 )
return;
if ( V_52 . V_10 == 0 )
return;
if ( V_52 . V_170 ) {
F_15 ( V_52 . V_26 , V_52 . V_27 , V_29 | V_171 ,
V_52 . V_30 , NULL , 0 , V_52 . V_48 , V_52 . V_10 ) ;
V_52 . V_29 = V_29 ;
V_52 . V_169 = true ;
} else {
F_15 ( V_52 . V_26 , V_52 . V_27 , V_29 , 0 ,
NULL , 0 , V_52 . V_48 , V_52 . V_10 ) ;
V_52 . V_10 = 0 ;
}
}
static bool F_101 ( int V_26 , int V_27 , const char * V_32 , T_5 V_10 )
{
if ( V_52 . V_10 && V_52 . V_169 )
return false ;
if ( V_172 || V_52 . V_10 + V_10 > sizeof( V_52 . V_48 ) ) {
F_100 ( V_53 ) ;
return false ;
}
if ( ! V_52 . V_10 ) {
V_52 . V_26 = V_26 ;
V_52 . V_27 = V_27 ;
V_52 . V_173 = V_42 ;
V_52 . V_30 = F_16 () ;
V_52 . V_29 = 0 ;
V_52 . V_170 = 0 ;
V_52 . V_169 = false ;
}
memcpy ( V_52 . V_48 + V_52 . V_10 , V_32 , V_10 ) ;
V_52 . V_10 += V_10 ;
if ( V_52 . V_10 > ( sizeof( V_52 . V_48 ) * 80 ) / 100 )
F_100 ( V_53 ) ;
return true ;
}
static T_5 F_102 ( char * V_32 , T_5 V_20 )
{
T_5 V_141 = 0 ;
T_5 V_10 ;
if ( V_52 . V_170 == 0 && ( V_174 & V_130 ) ) {
V_141 += F_76 ( V_52 . V_30 , V_32 ) ;
V_20 -= V_141 ;
}
V_10 = V_52 . V_10 - V_52 . V_170 ;
if ( V_10 > 0 ) {
if ( V_10 + 1 > V_20 )
V_10 = V_20 - 1 ;
memcpy ( V_32 + V_141 , V_52 . V_48 + V_52 . V_170 , V_10 ) ;
V_141 += V_10 ;
V_52 . V_170 = V_52 . V_10 ;
}
if ( V_52 . V_169 ) {
if ( V_52 . V_29 & V_130 )
V_32 [ V_141 ++ ] = '\n' ;
V_52 . V_10 = 0 ;
}
return V_141 ;
}
T_10 int F_103 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_175 ,
const char * V_176 , T_11 args )
{
static int V_177 ;
static char V_178 [ V_63 ] ;
char * V_32 = V_178 ;
T_5 V_8 = 0 ;
enum V_28 V_179 = 0 ;
unsigned long V_29 ;
int V_180 ;
int V_181 = 0 ;
bool V_182 = false ;
static unsigned int V_183 = V_184 ;
if ( V_27 == V_185 ) {
V_27 = V_143 ;
V_182 = true ;
}
F_71 ( V_27 ) ;
F_98 () ;
F_104 ( V_29 ) ;
V_180 = F_87 () ;
if ( F_63 ( V_183 == V_180 ) ) {
if ( ! V_186 && ! F_105 ( V_42 ) ) {
V_177 = 1 ;
F_106 ( V_29 ) ;
return 0 ;
}
F_88 () ;
}
F_107 () ;
F_108 ( & V_76 ) ;
V_183 = V_180 ;
if ( F_63 ( V_177 ) ) {
static const char V_187 [] =
L_19 ;
V_177 = 0 ;
V_181 += F_15 ( 0 , 2 , V_54 | V_130 , 0 ,
NULL , 0 , V_187 ,
strlen ( V_187 ) ) ;
}
V_8 = F_109 ( V_32 , sizeof( V_178 ) , V_176 , args ) ;
if ( V_8 && V_32 [ V_8 - 1 ] == '\n' ) {
V_8 -- ;
V_179 |= V_130 ;
}
if ( V_26 == 0 ) {
int V_188 = F_110 ( V_32 ) ;
if ( V_188 ) {
const char * V_189 = F_111 ( V_32 ) ;
switch ( V_188 ) {
case '0' ... '7' :
if ( V_27 == V_143 )
V_27 = V_188 - '0' ;
case 'd' :
V_179 |= V_54 ;
}
V_8 -= V_189 - V_32 ;
V_32 = ( char * ) V_189 ;
}
}
if ( V_27 == V_143 )
V_27 = V_61 ;
if ( V_31 )
V_179 |= V_54 | V_130 ;
if ( ! ( V_179 & V_130 ) ) {
if ( V_52 . V_10 && ( V_179 & V_54 || V_52 . V_173 != V_42 ) )
F_100 ( V_130 ) ;
if ( F_101 ( V_26 , V_27 , V_32 , V_8 ) )
V_181 += V_8 ;
else
V_181 += F_15 ( V_26 , V_27 ,
V_179 | V_53 , 0 ,
V_31 , V_175 , V_32 , V_8 ) ;
} else {
bool V_190 = false ;
if ( V_52 . V_10 ) {
if ( V_52 . V_173 == V_42 && ! ( V_179 & V_54 ) )
V_190 = F_101 ( V_26 , V_27 , V_32 ,
V_8 ) ;
F_100 ( V_130 ) ;
}
if ( V_190 )
V_181 += V_8 ;
else
V_181 += F_15 ( V_26 , V_27 , V_179 , 0 ,
V_31 , V_175 , V_32 , V_8 ) ;
}
V_183 = V_184 ;
F_112 ( & V_76 ) ;
F_113 () ;
F_106 ( V_29 ) ;
if ( ! V_182 ) {
F_107 () ;
F_114 () ;
if ( F_95 () )
F_115 () ;
F_116 () ;
F_113 () ;
}
return V_181 ;
}
T_10 int F_117 ( const char * V_176 , T_11 args )
{
return F_103 ( 0 , V_143 , NULL , 0 , V_176 , args ) ;
}
T_10 int F_34 ( int V_26 , int V_27 ,
const char * V_31 , T_5 V_175 ,
const char * V_176 , ... )
{
T_11 args ;
int V_191 ;
va_start ( args , V_176 ) ;
V_191 = F_103 ( V_26 , V_27 , V_31 , V_175 , V_176 , args ) ;
va_end ( args ) ;
return V_191 ;
}
int F_118 ( const char * V_176 , T_11 args )
{
int V_191 ;
#ifdef F_119
if ( F_63 ( V_192 ) ) {
V_191 = F_120 ( V_193 , V_176 , args ) ;
return V_191 ;
}
#endif
V_191 = F_103 ( 0 , V_143 , NULL , 0 , V_176 , args ) ;
return V_191 ;
}
T_10 T_12 int F_121 ( const char * V_176 , ... )
{
T_13 V_194 ;
T_11 args ;
int V_191 ;
va_start ( args , V_176 ) ;
V_194 = F_122 ( V_195 ) ;
V_191 = V_194 ( V_176 , args ) ;
va_end ( args ) ;
return V_191 ;
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
static void F_83 ( int V_27 ,
const char * V_154 , T_5 V_155 ,
const char * V_32 , T_5 V_10 ) {}
static T_5 F_78 ( const struct V_6 * V_7 , enum V_28 V_83 ,
bool V_126 , char * V_48 , T_5 V_20 ) { return 0 ; }
static T_5 F_102 ( char * V_32 , T_5 V_20 ) { return 0 ; }
T_10 T_12 void F_123 ( const char * V_176 , ... )
{
T_11 V_196 ;
char V_48 [ 512 ] ;
int V_133 ;
if ( ! V_197 )
return;
va_start ( V_196 , V_176 ) ;
V_133 = F_109 ( V_48 , sizeof( V_48 ) , V_176 , V_196 ) ;
va_end ( V_196 ) ;
V_197 -> V_161 ( V_197 , V_48 , V_133 ) ;
}
static int F_124 ( char * V_198 , int V_9 , char * V_199 ,
char * V_200 )
{
struct V_201 * V_47 ;
int V_56 ;
for ( V_56 = 0 , V_47 = V_201 ;
V_56 < V_202 && V_47 -> V_198 [ 0 ] ;
V_56 ++ , V_47 ++ ) {
if ( strcmp ( V_47 -> V_198 , V_198 ) == 0 && V_47 -> V_203 == V_9 ) {
if ( ! V_200 )
V_204 = V_56 ;
return 0 ;
}
}
if ( V_56 == V_202 )
return - V_205 ;
if ( ! V_200 )
V_204 = V_56 ;
F_125 ( V_47 -> V_198 , V_198 , sizeof( V_47 -> V_198 ) ) ;
V_47 -> V_199 = V_199 ;
F_126 ( V_47 , V_200 ) ;
V_47 -> V_203 = V_9 ;
return 0 ;
}
static int T_9 F_127 ( char * V_104 )
{
char V_48 [ sizeof( V_201 [ 0 ] . V_198 ) + 4 ] ;
char * V_206 , * V_199 , * V_200 = NULL ;
int V_9 ;
if ( F_128 ( & V_104 , & V_200 ) )
return 1 ;
if ( V_104 [ 0 ] >= '0' && V_104 [ 0 ] <= '9' ) {
strcpy ( V_48 , L_20 ) ;
strncpy ( V_48 + 4 , V_104 , sizeof( V_48 ) - 5 ) ;
} else {
strncpy ( V_48 , V_104 , sizeof( V_48 ) - 1 ) ;
}
V_48 [ sizeof( V_48 ) - 1 ] = 0 ;
V_199 = strchr ( V_104 , ',' ) ;
if ( V_199 )
* ( V_199 ++ ) = 0 ;
#ifdef F_129
if ( ! strcmp ( V_104 , L_21 ) )
strcpy ( V_48 , L_22 ) ;
if ( ! strcmp ( V_104 , L_23 ) )
strcpy ( V_48 , L_24 ) ;
#endif
for ( V_206 = V_48 ; * V_206 ; V_206 ++ )
if ( isdigit ( * V_206 ) || * V_206 == ',' )
break;
V_9 = F_33 ( V_206 , NULL , 10 ) ;
* V_206 = 0 ;
F_124 ( V_48 , V_9 , V_199 , V_200 ) ;
V_207 = 1 ;
return 1 ;
}
int F_130 ( char * V_198 , int V_9 , char * V_199 )
{
return F_124 ( V_198 , V_9 , V_199 , NULL ) ;
}
static int T_9 F_131 ( char * V_104 )
{
V_208 = false ;
return 1 ;
}
void F_132 ( void )
{
if ( ! V_208 )
return;
F_121 ( L_25 ) ;
F_133 () ;
V_209 = 1 ;
F_97 () ;
}
void F_134 ( void )
{
if ( ! V_208 )
return;
F_135 () ;
V_209 = 0 ;
F_115 () ;
}
static int F_136 ( struct V_210 * V_211 ,
unsigned long V_212 , void * V_213 )
{
switch ( V_212 ) {
case V_214 :
case V_215 :
case V_216 :
case V_217 :
F_133 () ;
F_115 () ;
}
return V_218 ;
}
void F_133 ( void )
{
F_137 () ;
F_135 () ;
if ( V_209 )
return;
V_166 = 1 ;
V_219 = 1 ;
}
int F_96 ( void )
{
if ( F_138 () )
return 0 ;
if ( V_209 ) {
F_97 () ;
return 0 ;
}
V_166 = 1 ;
V_219 = 0 ;
return 1 ;
}
int F_139 ( void )
{
return V_166 ;
}
static void F_140 ( char * V_32 , T_5 V_20 )
{
unsigned long V_29 ;
T_5 V_10 ;
F_65 ( & V_76 , V_29 ) ;
if ( ! V_52 . V_10 )
goto V_80;
if ( V_220 < V_16 && ! V_52 . V_170 )
goto V_80;
V_10 = F_102 ( V_32 , V_20 ) ;
F_112 ( & V_76 ) ;
F_141 () ;
F_83 ( V_52 . V_27 , NULL , 0 , V_32 , V_10 ) ;
F_142 () ;
F_106 ( V_29 ) ;
return;
V_80:
F_66 ( & V_76 , V_29 ) ;
}
void F_115 ( void )
{
static char V_154 [ V_221 ] ;
static char V_32 [ V_63 + V_132 ] ;
static T_3 V_222 ;
unsigned long V_29 ;
bool V_223 = false ;
bool V_224 ;
if ( V_209 ) {
F_97 () ;
return;
}
V_219 = 0 ;
F_140 ( V_32 , sizeof( V_32 ) ) ;
V_225:
for (; ; ) {
struct V_6 * V_7 ;
T_5 V_155 = 0 ;
T_5 V_10 ;
int V_27 ;
F_65 ( & V_76 , V_29 ) ;
if ( V_222 != V_16 ) {
V_223 = true ;
V_222 = V_16 ;
}
if ( V_220 < V_15 ) {
V_10 = sprintf ( V_32 , L_26 ,
( unsigned ) ( V_15 - V_220 ) ) ;
V_220 = V_15 ;
V_226 = V_14 ;
V_174 = 0 ;
} else {
V_10 = 0 ;
}
V_134:
if ( V_220 == V_16 )
break;
V_7 = F_8 ( V_226 ) ;
if ( V_7 -> V_29 & V_171 ) {
V_226 = F_9 ( V_226 ) ;
V_220 ++ ;
V_7 -> V_29 &= ~ V_171 ;
V_174 = V_7 -> V_29 ;
goto V_134;
}
V_27 = V_7 -> V_27 ;
V_10 += F_78 ( V_7 , V_174 , false ,
V_32 + V_10 , sizeof( V_32 ) - V_10 ) ;
if ( V_172 ) {
V_155 = F_24 ( V_154 ,
sizeof( V_154 ) ,
V_7 , V_220 , V_174 ) ;
V_155 += F_27 ( V_154 + V_155 ,
sizeof( V_154 ) - V_155 ,
F_7 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_7 ) , V_7 -> V_8 ) ;
}
V_226 = F_9 ( V_226 ) ;
V_220 ++ ;
V_174 = V_7 -> V_29 ;
F_112 ( & V_76 ) ;
F_141 () ;
F_83 ( V_27 , V_154 , V_155 , V_32 , V_10 ) ;
F_142 () ;
F_106 ( V_29 ) ;
}
V_166 = 0 ;
if ( F_63 ( V_159 ) )
V_159 = NULL ;
F_112 ( & V_76 ) ;
F_97 () ;
F_108 ( & V_76 ) ;
V_224 = V_220 != V_16 ;
F_66 ( & V_76 , V_29 ) ;
if ( V_224 && F_96 () )
goto V_225;
if ( V_223 )
F_143 () ;
}
void T_14 F_144 ( void )
{
if ( V_219 )
F_145 () ;
}
void F_146 ( void )
{
struct V_156 * V_47 ;
if ( V_186 ) {
if ( F_138 () != 0 )
return;
} else
F_133 () ;
V_166 = 1 ;
V_219 = 0 ;
F_85 (c)
if ( ( V_47 -> V_29 & V_160 ) && V_47 -> V_227 )
V_47 -> V_227 () ;
F_115 () ;
}
struct V_228 * F_147 ( int * V_203 )
{
struct V_156 * V_47 ;
struct V_228 * V_229 = NULL ;
F_133 () ;
F_85 (c) {
if ( ! V_47 -> V_230 )
continue;
V_229 = V_47 -> V_230 ( V_47 , V_203 ) ;
if ( V_229 )
break;
}
F_115 () ;
return V_229 ;
}
void F_148 ( struct V_156 * V_156 )
{
F_133 () ;
V_156 -> V_29 &= ~ V_160 ;
F_115 () ;
}
void F_149 ( struct V_156 * V_156 )
{
F_133 () ;
V_156 -> V_29 |= V_160 ;
F_115 () ;
}
static int T_9 F_150 ( char * V_104 )
{
V_231 = 1 ;
F_59 ( L_27 ) ;
return 0 ;
}
void F_151 ( struct V_156 * V_232 )
{
int V_56 ;
unsigned long V_29 ;
struct V_156 * V_233 = NULL ;
struct V_201 * V_47 ;
if ( V_158 )
F_85 (bcon)
if ( F_152 ( V_233 == V_232 ,
L_28 ,
V_233 -> V_198 , V_233 -> V_203 ) )
return;
if ( V_158 && V_232 -> V_29 & V_234 ) {
F_85 (bcon) {
if ( ! ( V_233 -> V_29 & V_234 ) ) {
F_59 ( L_29 ,
V_232 -> V_198 , V_232 -> V_203 ) ;
return;
}
}
}
if ( V_158 && V_158 -> V_29 & V_234 )
V_233 = V_158 ;
if ( V_235 < 0 || V_233 || ! V_158 )
V_235 = V_204 ;
if ( V_235 < 0 ) {
if ( V_232 -> V_203 < 0 )
V_232 -> V_203 = 0 ;
if ( V_232 -> V_236 == NULL ||
V_232 -> V_236 ( V_232 , NULL ) == 0 ) {
V_232 -> V_29 |= V_160 ;
if ( V_232 -> V_230 ) {
V_232 -> V_29 |= V_237 ;
V_235 = 0 ;
}
}
}
for ( V_56 = 0 , V_47 = V_201 ;
V_56 < V_202 && V_47 -> V_198 [ 0 ] ;
V_56 ++ , V_47 ++ ) {
if ( ! V_232 -> V_238 ||
V_232 -> V_238 ( V_232 , V_47 -> V_198 , V_47 -> V_203 , V_47 -> V_199 ) != 0 ) {
F_153 ( sizeof( V_47 -> V_198 ) != sizeof( V_232 -> V_198 ) ) ;
if ( strcmp ( V_47 -> V_198 , V_232 -> V_198 ) != 0 )
continue;
if ( V_232 -> V_203 >= 0 &&
V_232 -> V_203 != V_47 -> V_203 )
continue;
if ( V_232 -> V_203 < 0 )
V_232 -> V_203 = V_47 -> V_203 ;
if ( F_154 ( V_232 , V_47 ) )
return;
if ( V_232 -> V_236 &&
V_232 -> V_236 ( V_232 , V_47 -> V_199 ) != 0 )
break;
}
V_232 -> V_29 |= V_160 ;
if ( V_56 == V_204 ) {
V_232 -> V_29 |= V_237 ;
V_235 = V_204 ;
}
break;
}
if ( ! ( V_232 -> V_29 & V_160 ) )
return;
if ( V_233 && ( ( V_232 -> V_29 & ( V_237 | V_234 ) ) == V_237 ) )
V_232 -> V_29 &= ~ V_239 ;
F_133 () ;
if ( ( V_232 -> V_29 & V_237 ) || V_158 == NULL ) {
V_232 -> V_131 = V_158 ;
V_158 = V_232 ;
if ( V_232 -> V_131 )
V_232 -> V_131 -> V_29 &= ~ V_237 ;
} else {
V_232 -> V_131 = V_158 -> V_131 ;
V_158 -> V_131 = V_232 ;
}
if ( V_232 -> V_29 & V_163 )
if ( ! V_172 ++ )
F_59 ( L_30 ) ;
if ( V_232 -> V_29 & V_239 ) {
F_65 ( & V_76 , V_29 ) ;
V_220 = V_135 ;
V_226 = V_136 ;
V_174 = V_137 ;
F_66 ( & V_76 , V_29 ) ;
V_159 = V_232 ;
}
F_115 () ;
F_155 () ;
F_59 ( L_31 ,
( V_232 -> V_29 & V_234 ) ? L_32 : L_33 ,
V_232 -> V_198 , V_232 -> V_203 ) ;
if ( V_233 &&
( ( V_232 -> V_29 & ( V_237 | V_234 ) ) == V_237 ) &&
! V_231 ) {
F_85 (bcon)
if ( V_233 -> V_29 & V_234 )
F_156 ( V_233 ) ;
}
}
int F_156 ( struct V_156 * V_156 )
{
struct V_156 * V_240 , * V_241 ;
int V_242 ;
F_59 ( L_34 ,
( V_156 -> V_29 & V_234 ) ? L_32 : L_33 ,
V_156 -> V_198 , V_156 -> V_203 ) ;
V_242 = F_157 ( V_156 ) ;
if ( V_242 )
return V_242 ;
V_242 = 1 ;
F_133 () ;
if ( V_158 == V_156 ) {
V_158 = V_156 -> V_131 ;
V_242 = 0 ;
} else if ( V_158 ) {
for ( V_240 = V_158 -> V_131 , V_241 = V_158 ;
V_240 ; V_241 = V_240 , V_240 = V_241 -> V_131 ) {
if ( V_240 == V_156 ) {
V_241 -> V_131 = V_240 -> V_131 ;
V_242 = 0 ;
break;
}
}
}
if ( ! V_242 && ( V_156 -> V_29 & V_163 ) )
V_172 -- ;
if ( V_158 != NULL && V_156 -> V_29 & V_237 )
V_158 -> V_29 |= V_237 ;
V_156 -> V_29 &= ~ V_160 ;
F_115 () ;
F_155 () ;
return V_242 ;
}
static int T_9 F_158 ( void )
{
struct V_156 * V_157 ;
F_85 (con) {
if ( ! V_231 && V_157 -> V_29 & V_234 ) {
F_156 ( V_157 ) ;
}
}
F_159 ( F_136 , 0 ) ;
return 0 ;
}
static void F_160 ( struct V_243 * V_243 )
{
int V_244 = F_161 ( V_245 , 0 ) ;
if ( V_244 & V_246 ) {
if ( F_96 () )
F_115 () ;
}
if ( V_244 & V_247 )
F_162 ( & V_81 ) ;
}
void F_143 ( void )
{
F_114 () ;
if ( F_163 ( & V_81 ) ) {
F_164 ( V_245 , V_247 ) ;
F_165 ( F_166 ( & V_248 ) ) ;
}
F_116 () ;
}
int F_167 ( const char * V_176 , ... )
{
T_11 args ;
int V_191 ;
F_114 () ;
va_start ( args , V_176 ) ;
V_191 = F_103 ( 0 , V_185 , NULL , 0 , V_176 , args ) ;
va_end ( args ) ;
F_168 ( V_245 , V_246 ) ;
F_165 ( F_166 ( & V_248 ) ) ;
F_116 () ;
return V_191 ;
}
int F_169 ( const char * V_249 )
{
return F_170 ( & V_250 , V_249 ) ;
}
bool F_171 ( unsigned long * V_251 ,
unsigned int V_252 )
{
unsigned long V_253 = V_122 - * V_251 ;
if ( * V_251 && V_253 <= F_72 ( V_252 ) )
return false ;
* V_251 = V_122 ;
return true ;
}
int F_172 ( struct V_254 * V_255 )
{
unsigned long V_29 ;
int V_99 = - V_256 ;
if ( ! V_255 -> V_257 )
return - V_64 ;
F_173 ( & V_258 , V_29 ) ;
if ( ! V_255 -> V_259 ) {
V_255 -> V_259 = 1 ;
F_174 ( & V_255 -> V_260 , & V_261 ) ;
V_99 = 0 ;
}
F_175 ( & V_258 , V_29 ) ;
return V_99 ;
}
int F_176 ( struct V_254 * V_255 )
{
unsigned long V_29 ;
int V_99 = - V_64 ;
F_173 ( & V_258 , V_29 ) ;
if ( V_255 -> V_259 ) {
V_255 -> V_259 = 0 ;
F_177 ( & V_255 -> V_260 ) ;
V_99 = 0 ;
}
F_175 ( & V_258 , V_29 ) ;
F_178 () ;
return V_99 ;
}
void F_179 ( enum V_262 V_263 )
{
struct V_254 * V_255 ;
unsigned long V_29 ;
if ( ( V_263 > V_264 ) && ! V_265 )
return;
F_180 () ;
F_181 (dumper, &dump_list, list) {
if ( V_255 -> V_266 && V_263 > V_255 -> V_266 )
continue;
V_255 -> V_267 = true ;
F_65 ( & V_76 , V_29 ) ;
V_255 -> V_268 = V_90 ;
V_255 -> V_269 = V_89 ;
V_255 -> V_140 = V_16 ;
V_255 -> V_270 = V_13 ;
F_66 ( & V_76 , V_29 ) ;
V_255 -> V_257 ( V_255 , V_263 ) ;
V_255 -> V_267 = false ;
}
F_182 () ;
}
bool F_183 ( struct V_254 * V_255 , bool V_126 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
struct V_6 * V_7 ;
T_5 V_271 = 0 ;
bool V_62 = false ;
if ( ! V_255 -> V_267 )
goto V_80;
if ( V_255 -> V_268 < V_15 ) {
V_255 -> V_268 = V_15 ;
V_255 -> V_269 = V_14 ;
}
if ( V_255 -> V_268 >= V_16 )
goto V_80;
V_7 = F_8 ( V_255 -> V_269 ) ;
V_271 = F_78 ( V_7 , 0 , V_126 , line , V_20 ) ;
V_255 -> V_269 = F_9 ( V_255 -> V_269 ) ;
V_255 -> V_268 ++ ;
V_62 = true ;
V_80:
if ( V_10 )
* V_10 = V_271 ;
return V_62 ;
}
bool F_184 ( struct V_254 * V_255 , bool V_126 ,
char * line , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
bool V_62 ;
F_65 ( & V_76 , V_29 ) ;
V_62 = F_183 ( V_255 , V_126 , line , V_20 , V_10 ) ;
F_66 ( & V_76 , V_29 ) ;
return V_62 ;
}
bool F_185 ( struct V_254 * V_255 , bool V_126 ,
char * V_48 , T_5 V_20 , T_5 * V_10 )
{
unsigned long V_29 ;
T_3 V_49 ;
T_1 V_9 ;
T_3 V_140 ;
T_1 V_270 ;
enum V_28 V_83 ;
T_5 V_271 = 0 ;
bool V_62 = false ;
if ( ! V_255 -> V_267 )
goto V_80;
F_65 ( & V_76 , V_29 ) ;
if ( V_255 -> V_268 < V_15 ) {
V_255 -> V_268 = V_15 ;
V_255 -> V_269 = V_14 ;
}
if ( V_255 -> V_268 >= V_255 -> V_140 ) {
F_66 ( & V_76 , V_29 ) ;
goto V_80;
}
V_49 = V_255 -> V_268 ;
V_9 = V_255 -> V_269 ;
V_83 = 0 ;
while ( V_49 < V_255 -> V_140 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_271 += F_78 ( V_7 , V_83 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_83 = V_7 -> V_29 ;
}
V_49 = V_255 -> V_268 ;
V_9 = V_255 -> V_269 ;
V_83 = 0 ;
while ( V_271 > V_20 && V_49 < V_255 -> V_140 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_271 -= F_78 ( V_7 , V_83 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_83 = V_7 -> V_29 ;
}
V_140 = V_49 ;
V_270 = V_9 ;
V_271 = 0 ;
while ( V_49 < V_255 -> V_140 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_271 += F_78 ( V_7 , V_83 , V_126 , V_48 + V_271 , V_20 - V_271 ) ;
V_9 = F_9 ( V_9 ) ;
V_49 ++ ;
V_83 = V_7 -> V_29 ;
}
V_255 -> V_140 = V_140 ;
V_255 -> V_270 = V_270 ;
V_62 = true ;
F_66 ( & V_76 , V_29 ) ;
V_80:
if ( V_10 )
* V_10 = V_271 ;
return V_62 ;
}
void F_186 ( struct V_254 * V_255 )
{
V_255 -> V_268 = V_90 ;
V_255 -> V_269 = V_89 ;
V_255 -> V_140 = V_16 ;
V_255 -> V_270 = V_13 ;
}
void F_187 ( struct V_254 * V_255 )
{
unsigned long V_29 ;
F_65 ( & V_76 , V_29 ) ;
F_186 ( V_255 ) ;
F_66 ( & V_76 , V_29 ) ;
}
void T_9 F_188 ( const char * V_176 , ... )
{
T_11 args ;
va_start ( args , V_176 ) ;
vsnprintf ( V_272 , sizeof( V_272 ) ,
V_176 , args ) ;
va_end ( args ) ;
}
void F_189 ( const char * V_273 )
{
F_121 ( L_35 ,
V_273 , F_190 () , V_42 -> V_274 , V_42 -> V_43 ,
F_191 () , F_192 () -> V_275 ,
( int ) strcspn ( F_192 () -> V_276 , L_36 ) ,
F_192 () -> V_276 ) ;
if ( V_272 [ 0 ] != '\0' )
F_121 ( L_37 ,
V_273 , V_272 ) ;
F_193 ( V_273 , V_42 ) ;
}
void F_194 ( const char * V_273 )
{
F_189 ( V_273 ) ;
F_121 ( L_38 ,
V_273 , V_42 , F_195 () ,
F_196 ( V_42 ) ) ;
}
