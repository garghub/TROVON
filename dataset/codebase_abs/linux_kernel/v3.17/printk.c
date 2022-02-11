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
static T_4 F_23 ( struct V_43 * V_44 , const struct V_45 * V_46 ,
unsigned long V_47 , T_5 V_48 )
{
char * V_49 , * line ;
int V_50 ;
int V_27 = V_51 ;
int V_26 = 1 ;
T_6 V_10 = F_24 ( V_46 , V_47 ) ;
T_4 V_52 = V_10 ;
if ( V_10 > V_53 )
return - V_54 ;
V_49 = F_25 ( V_10 + 1 , V_55 ) ;
if ( V_49 == NULL )
return - V_17 ;
line = V_49 ;
for ( V_50 = 0 ; V_50 < V_47 ; V_50 ++ ) {
if ( F_26 ( line , V_46 [ V_50 ] . V_56 , V_46 [ V_50 ] . V_57 ) ) {
V_52 = - V_58 ;
goto V_59;
}
line += V_46 [ V_50 ] . V_57 ;
}
line = V_49 ;
if ( line [ 0 ] == '<' ) {
char * V_60 = NULL ;
V_50 = F_27 ( line + 1 , & V_60 , 10 ) ;
if ( V_60 && V_60 [ 0 ] == '>' ) {
V_27 = V_50 & 7 ;
if ( V_50 >> 3 )
V_26 = V_50 >> 3 ;
V_60 ++ ;
V_10 -= V_60 - line ;
line = V_60 ;
}
}
line [ V_10 ] = '\0' ;
F_28 ( V_26 , V_27 , NULL , 0 , L_4 , line ) ;
V_59:
F_29 ( V_49 ) ;
return V_52 ;
}
static T_4 F_30 ( struct V_61 * V_61 , char T_7 * V_49 ,
T_6 V_47 , T_5 * V_62 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
struct V_6 * V_7 ;
T_3 V_66 ;
T_6 V_50 ;
char V_67 = '-' ;
T_6 V_10 ;
T_4 V_52 ;
if ( ! V_64 )
return - V_68 ;
V_52 = F_31 ( & V_64 -> V_69 ) ;
if ( V_52 )
return V_52 ;
F_32 ( & V_70 ) ;
while ( V_64 -> V_71 == V_16 ) {
if ( V_61 -> V_72 & V_73 ) {
V_52 = - V_74 ;
F_33 ( & V_70 ) ;
goto V_59;
}
F_33 ( & V_70 ) ;
V_52 = F_34 ( V_75 ,
V_64 -> V_71 != V_16 ) ;
if ( V_52 )
goto V_59;
F_32 ( & V_70 ) ;
}
if ( V_64 -> V_71 < V_15 ) {
V_64 -> V_9 = V_14 ;
V_64 -> V_71 = V_15 ;
V_52 = - V_76 ;
F_33 ( & V_70 ) ;
goto V_59;
}
V_7 = F_8 ( V_64 -> V_9 ) ;
V_66 = V_7 -> V_30 ;
F_35 ( V_66 , 1000 ) ;
if ( V_7 -> V_29 & V_77 && ! ( V_64 -> V_78 & V_77 ) )
V_67 = 'c' ;
else if ( ( V_7 -> V_29 & V_77 ) ||
( ( V_64 -> V_78 & V_77 ) && ! ( V_7 -> V_29 & V_79 ) ) )
V_67 = '+' ;
V_10 = sprintf ( V_64 -> V_49 , L_5 ,
( V_7 -> V_26 << 3 ) | V_7 -> V_27 ,
V_64 -> V_71 , V_66 , V_67 ) ;
V_64 -> V_78 = V_7 -> V_29 ;
for ( V_50 = 0 ; V_50 < V_7 -> V_8 ; V_50 ++ ) {
unsigned char V_80 = F_6 ( V_7 ) [ V_50 ] ;
if ( V_80 < ' ' || V_80 >= 127 || V_80 == '\\' )
V_10 += sprintf ( V_64 -> V_49 + V_10 , L_6 , V_80 ) ;
else
V_64 -> V_49 [ V_10 ++ ] = V_80 ;
}
V_64 -> V_49 [ V_10 ++ ] = '\n' ;
if ( V_7 -> V_18 ) {
bool line = true ;
for ( V_50 = 0 ; V_50 < V_7 -> V_18 ; V_50 ++ ) {
unsigned char V_80 = F_7 ( V_7 ) [ V_50 ] ;
if ( line ) {
V_64 -> V_49 [ V_10 ++ ] = ' ' ;
line = false ;
}
if ( V_80 == '\0' ) {
V_64 -> V_49 [ V_10 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_80 < ' ' || V_80 >= 127 || V_80 == '\\' ) {
V_10 += sprintf ( V_64 -> V_49 + V_10 , L_6 , V_80 ) ;
continue;
}
V_64 -> V_49 [ V_10 ++ ] = V_80 ;
}
V_64 -> V_49 [ V_10 ++ ] = '\n' ;
}
V_64 -> V_9 = F_9 ( V_64 -> V_9 ) ;
V_64 -> V_71 ++ ;
F_33 ( & V_70 ) ;
if ( V_10 > V_47 ) {
V_52 = - V_54 ;
goto V_59;
}
if ( F_36 ( V_49 , V_64 -> V_49 , V_10 ) ) {
V_52 = - V_58 ;
goto V_59;
}
V_52 = V_10 ;
V_59:
F_37 ( & V_64 -> V_69 ) ;
return V_52 ;
}
static T_5 F_38 ( struct V_61 * V_61 , T_5 V_81 , int V_82 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
T_5 V_52 = 0 ;
if ( ! V_64 )
return - V_68 ;
if ( V_81 )
return - V_83 ;
F_32 ( & V_70 ) ;
switch ( V_82 ) {
case V_84 :
V_64 -> V_9 = V_14 ;
V_64 -> V_71 = V_15 ;
break;
case V_85 :
V_64 -> V_9 = V_86 ;
V_64 -> V_71 = V_87 ;
break;
case V_88 :
V_64 -> V_9 = V_13 ;
V_64 -> V_71 = V_16 ;
break;
default:
V_52 = - V_54 ;
}
F_33 ( & V_70 ) ;
return V_52 ;
}
static unsigned int F_39 ( struct V_61 * V_61 , T_8 * V_89 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
int V_52 = 0 ;
if ( ! V_64 )
return V_90 | V_91 ;
F_40 ( V_61 , & V_75 , V_89 ) ;
F_32 ( & V_70 ) ;
if ( V_64 -> V_71 < V_16 ) {
if ( V_64 -> V_71 < V_15 )
V_52 = V_92 | V_93 | V_90 | V_94 ;
else
V_52 = V_92 | V_93 ;
}
F_33 ( & V_70 ) ;
return V_52 ;
}
static int F_41 ( struct V_95 * V_95 , struct V_61 * V_61 )
{
struct V_63 * V_64 ;
int V_96 ;
if ( ( V_61 -> V_72 & V_97 ) == V_98 )
return 0 ;
V_96 = F_18 ( V_34 ,
V_99 ) ;
if ( V_96 )
return V_96 ;
V_64 = F_25 ( sizeof( struct V_63 ) , V_55 ) ;
if ( ! V_64 )
return - V_17 ;
F_42 ( & V_64 -> V_69 ) ;
F_32 ( & V_70 ) ;
V_64 -> V_9 = V_14 ;
V_64 -> V_71 = V_15 ;
F_33 ( & V_70 ) ;
V_61 -> V_65 = V_64 ;
return 0 ;
}
static int F_43 ( struct V_95 * V_95 , struct V_61 * V_61 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
if ( ! V_64 )
return 0 ;
F_44 ( & V_64 -> V_69 ) ;
F_29 ( V_64 ) ;
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
V_100 = V_20 ;
}
static int T_9 F_51 ( char * V_101 )
{
unsigned V_20 = F_52 ( V_101 , & V_101 ) ;
F_49 ( V_20 ) ;
return 0 ;
}
static void T_9 F_53 ( void )
{
unsigned int V_102 ;
if ( F_54 () == 1 )
return;
V_102 = ( F_54 () - 1 ) * V_103 ;
if ( V_102 <= V_104 / 2 )
return;
F_55 ( L_7 ,
V_103 ) ;
F_55 ( L_8 ,
V_102 ) ;
F_55 ( L_9 , V_104 ) ;
F_49 ( V_102 + V_104 ) ;
}
void T_9 F_56 ( int V_105 )
{
unsigned long V_29 ;
char * V_106 ;
int free ;
if ( V_4 != V_107 )
return;
if ( ! V_105 && ! V_100 )
F_53 () ;
if ( ! V_100 )
return;
if ( V_105 ) {
V_106 =
F_57 ( V_100 , V_21 ) ;
} else {
V_106 = F_58 ( V_100 ,
V_21 ) ;
}
if ( F_59 ( ! V_106 ) ) {
F_60 ( L_10 ,
V_100 ) ;
return;
}
F_61 ( & V_70 , V_29 ) ;
V_5 = V_100 ;
V_4 = V_106 ;
V_100 = 0 ;
free = V_104 - V_13 ;
memcpy ( V_4 , V_107 , V_104 ) ;
F_62 ( & V_70 , V_29 ) ;
F_55 ( L_11 , V_5 ) ;
F_55 ( L_12 ,
free , ( free * 100 ) / V_104 ) ;
}
static int T_9 F_63 ( char * V_101 )
{
V_108 = true ;
F_55 ( L_13 ) ;
return 0 ;
}
static int T_9 F_64 ( char * V_101 )
{
unsigned long V_109 ;
V_109 = V_110 ? V_110 : 1000000 ;
V_111 = ( unsigned long long ) V_109 / 1000 * V_112 ;
F_65 ( & V_101 , & V_113 ) ;
if ( V_113 > 10 * 1000 )
V_113 = 0 ;
F_66 ( L_14
L_15 ,
V_113 , V_110 , V_109 , V_112 , V_111 ) ;
return 0 ;
}
static void F_67 ( int V_27 )
{
unsigned long long V_114 ;
unsigned long V_115 ;
if ( ( V_113 == 0 || V_116 != V_117 )
|| ( V_27 >= V_118 && ! V_108 ) ) {
return;
}
V_114 = ( unsigned long long ) V_111 * V_113 ;
V_115 = V_119 + F_68 ( V_113 ) ;
while ( V_114 ) {
V_114 -- ;
F_69 () ;
if ( F_70 ( V_119 , V_115 ) )
break;
F_71 () ;
}
}
static inline void F_67 ( int V_27 )
{
}
static T_6 F_72 ( T_3 V_120 , char * V_49 )
{
unsigned long V_121 ;
if ( ! V_122 )
return 0 ;
V_121 = F_35 ( V_120 , 1000000000 ) ;
if ( ! V_49 )
return snprintf ( NULL , 0 , L_16 , ( unsigned long ) V_120 ) ;
return sprintf ( V_49 , L_17 ,
( unsigned long ) V_120 , V_121 / 1000 ) ;
}
static T_6 F_73 ( const struct V_6 * V_7 , bool V_123 , char * V_49 )
{
T_6 V_10 = 0 ;
unsigned int V_124 = ( V_7 -> V_26 << 3 ) | V_7 -> V_27 ;
if ( V_123 ) {
if ( V_49 ) {
V_10 += sprintf ( V_49 , L_18 , V_124 ) ;
} else {
V_10 += 3 ;
if ( V_124 > 999 )
V_10 += 3 ;
else if ( V_124 > 99 )
V_10 += 2 ;
else if ( V_124 > 9 )
V_10 ++ ;
}
}
V_10 += F_72 ( V_7 -> V_30 , V_49 ? V_49 + V_10 : NULL ) ;
return V_10 ;
}
static T_6 F_74 ( const struct V_6 * V_7 , enum V_28 V_78 ,
bool V_123 , char * V_49 , T_6 V_20 )
{
const char * V_32 = F_6 ( V_7 ) ;
T_6 V_125 = V_7 -> V_8 ;
bool V_124 = true ;
bool V_126 = true ;
T_6 V_10 = 0 ;
if ( ( V_78 & V_77 ) && ! ( V_7 -> V_29 & V_79 ) )
V_124 = false ;
if ( V_7 -> V_29 & V_77 ) {
if ( ( V_78 & V_77 ) && ! ( V_78 & V_127 ) )
V_124 = false ;
if ( ! ( V_7 -> V_29 & V_127 ) )
V_126 = false ;
}
do {
const char * V_128 = memchr ( V_32 , '\n' , V_125 ) ;
T_6 V_8 ;
if ( V_128 ) {
V_8 = V_128 - V_32 ;
V_128 ++ ;
V_125 -= V_128 - V_32 ;
} else {
V_8 = V_125 ;
}
if ( V_49 ) {
if ( F_73 ( V_7 , V_123 , NULL ) +
V_8 + 1 >= V_20 - V_10 )
break;
if ( V_124 )
V_10 += F_73 ( V_7 , V_123 , V_49 + V_10 ) ;
memcpy ( V_49 + V_10 , V_32 , V_8 ) ;
V_10 += V_8 ;
if ( V_128 || V_126 )
V_49 [ V_10 ++ ] = '\n' ;
} else {
if ( V_124 )
V_10 += F_73 ( V_7 , V_123 , NULL ) ;
V_10 += V_8 ;
if ( V_128 || V_126 )
V_10 ++ ;
}
V_124 = true ;
V_32 = V_128 ;
} while ( V_32 );
return V_10 ;
}
static int F_75 ( char T_7 * V_49 , int V_20 )
{
char * V_32 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
V_32 = F_25 ( V_53 + V_129 , V_55 ) ;
if ( ! V_32 )
return - V_17 ;
while ( V_20 > 0 ) {
T_6 V_130 ;
T_6 V_131 ;
F_32 ( & V_70 ) ;
if ( V_132 < V_15 ) {
V_132 = V_15 ;
V_133 = V_14 ;
V_134 = 0 ;
V_135 = 0 ;
}
if ( V_132 == V_16 ) {
F_33 ( & V_70 ) ;
break;
}
V_131 = V_135 ;
V_7 = F_8 ( V_133 ) ;
V_130 = F_74 ( V_7 , V_134 , true , V_32 ,
V_53 + V_129 ) ;
if ( V_130 - V_135 <= V_20 ) {
V_133 = F_9 ( V_133 ) ;
V_132 ++ ;
V_134 = V_7 -> V_29 ;
V_130 -= V_135 ;
V_135 = 0 ;
} else if ( ! V_10 ) {
V_130 = V_20 ;
V_135 += V_130 ;
} else
V_130 = 0 ;
F_33 ( & V_70 ) ;
if ( ! V_130 )
break;
if ( F_36 ( V_49 , V_32 + V_131 , V_130 ) ) {
if ( ! V_10 )
V_10 = - V_58 ;
break;
}
V_10 += V_130 ;
V_20 -= V_130 ;
V_49 += V_130 ;
}
F_29 ( V_32 ) ;
return V_10 ;
}
static int F_76 ( char T_7 * V_49 , int V_20 , bool V_136 )
{
char * V_32 ;
int V_10 = 0 ;
V_32 = F_25 ( V_53 + V_129 , V_55 ) ;
if ( ! V_32 )
return - V_17 ;
F_32 ( & V_70 ) ;
if ( V_49 ) {
T_3 V_137 ;
T_3 V_71 ;
T_1 V_9 ;
enum V_28 V_78 ;
if ( V_87 < V_15 ) {
V_87 = V_15 ;
V_86 = V_14 ;
}
V_71 = V_87 ;
V_9 = V_86 ;
V_78 = 0 ;
while ( V_71 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 += F_74 ( V_7 , V_78 , true , NULL , 0 ) ;
V_78 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_71 ++ ;
}
V_71 = V_87 ;
V_9 = V_86 ;
V_78 = 0 ;
while ( V_10 > V_20 && V_71 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_10 -= F_74 ( V_7 , V_78 , true , NULL , 0 ) ;
V_78 = V_7 -> V_29 ;
V_9 = F_9 ( V_9 ) ;
V_71 ++ ;
}
V_137 = V_16 ;
V_10 = 0 ;
while ( V_10 >= 0 && V_71 < V_137 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
int V_138 ;
V_138 = F_74 ( V_7 , V_78 , true , V_32 ,
V_53 + V_129 ) ;
if ( V_138 < 0 ) {
V_10 = V_138 ;
break;
}
V_9 = F_9 ( V_9 ) ;
V_71 ++ ;
V_78 = V_7 -> V_29 ;
F_33 ( & V_70 ) ;
if ( F_36 ( V_49 + V_10 , V_32 , V_138 ) )
V_10 = - V_58 ;
else
V_10 += V_138 ;
F_32 ( & V_70 ) ;
if ( V_71 < V_15 ) {
V_71 = V_15 ;
V_9 = V_14 ;
V_78 = 0 ;
}
}
}
if ( V_136 ) {
V_87 = V_16 ;
V_86 = V_13 ;
}
F_33 ( & V_70 ) ;
F_29 ( V_32 ) ;
return V_10 ;
}
int F_77 ( int type , char T_7 * V_49 , int V_10 , bool V_36 )
{
bool V_136 = false ;
static int V_139 = - 1 ;
int error ;
error = F_18 ( type , V_36 ) ;
if ( error )
goto V_59;
error = F_22 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_140 :
break;
case V_37 :
break;
case V_141 :
error = - V_54 ;
if ( ! V_49 || V_10 < 0 )
goto V_59;
error = 0 ;
if ( ! V_10 )
goto V_59;
if ( ! F_78 ( V_142 , V_49 , V_10 ) ) {
error = - V_58 ;
goto V_59;
}
error = F_34 ( V_75 ,
V_132 != V_16 ) ;
if ( error )
goto V_59;
error = F_75 ( V_49 , V_10 ) ;
break;
case V_143 :
V_136 = true ;
case V_34 :
error = - V_54 ;
if ( ! V_49 || V_10 < 0 )
goto V_59;
error = 0 ;
if ( ! V_10 )
goto V_59;
if ( ! F_78 ( V_142 , V_49 , V_10 ) ) {
error = - V_58 ;
goto V_59;
}
error = F_76 ( V_49 , V_10 , V_136 ) ;
break;
case V_144 :
F_76 ( NULL , 0 , true ) ;
break;
case V_145 :
if ( V_139 == - 1 )
V_139 = V_118 ;
V_118 = V_146 ;
break;
case V_147 :
if ( V_139 != - 1 ) {
V_118 = V_139 ;
V_139 = - 1 ;
}
break;
case V_148 :
error = - V_54 ;
if ( V_10 < 1 || V_10 > 8 )
goto V_59;
if ( V_10 < V_146 )
V_10 = V_146 ;
V_118 = V_10 ;
V_139 = - 1 ;
error = 0 ;
break;
case V_149 :
F_32 ( & V_70 ) ;
if ( V_132 < V_15 ) {
V_132 = V_15 ;
V_133 = V_14 ;
V_134 = 0 ;
V_135 = 0 ;
}
if ( V_36 ) {
error = V_16 - V_132 ;
} else {
T_3 V_71 = V_132 ;
T_1 V_9 = V_133 ;
enum V_28 V_78 = V_134 ;
error = 0 ;
while ( V_71 < V_16 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
error += F_74 ( V_7 , V_78 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_71 ++ ;
V_78 = V_7 -> V_29 ;
}
error -= V_135 ;
}
F_33 ( & V_70 ) ;
break;
case V_35 :
error = V_5 ;
break;
default:
error = - V_54 ;
break;
}
V_59:
return error ;
}
static void F_79 ( int V_27 , const char * V_32 , T_6 V_10 )
{
struct V_150 * V_151 ;
F_80 ( V_32 , V_10 ) ;
if ( V_27 >= V_118 && ! V_108 )
return;
if ( ! V_152 )
return;
F_81 (con) {
if ( V_153 && V_151 != V_153 )
continue;
if ( ! ( V_151 -> V_29 & V_154 ) )
continue;
if ( ! V_151 -> V_155 )
continue;
if ( ! F_82 ( F_83 () ) &&
! ( V_151 -> V_29 & V_156 ) )
continue;
V_151 -> V_155 ( V_151 , V_32 , V_10 ) ;
}
}
static void F_84 ( void )
{
static unsigned long V_157 ;
if ( F_85 ( V_119 , V_157 ) &&
! F_70 ( V_119 , V_157 + 30 * V_112 ) )
return;
V_157 = V_119 ;
F_86 () ;
F_87 ( & V_70 ) ;
F_88 ( & V_2 , 1 ) ;
}
static int F_89 ( void )
{
struct V_150 * V_151 ;
F_81 (con)
if ( V_151 -> V_29 & V_156 )
return 1 ;
return 0 ;
}
static inline int F_90 ( unsigned int V_158 )
{
return F_82 ( V_158 ) || F_89 () ;
}
static int F_91 ( void )
{
unsigned int V_158 = F_83 () ;
if ( ! F_92 () )
return 0 ;
if ( ! F_90 ( V_158 ) ) {
V_159 = 0 ;
F_93 () ;
return 0 ;
}
return 1 ;
}
static inline void F_94 ( void )
{
if ( F_59 ( V_160 ) ) {
int V_161 = V_160 ;
while ( V_161 -- ) {
F_95 ( 1 ) ;
F_71 () ;
}
}
}
static void F_96 ( enum V_28 V_29 )
{
if ( V_67 . V_162 )
return;
if ( V_67 . V_10 == 0 )
return;
if ( V_67 . V_163 ) {
F_15 ( V_67 . V_26 , V_67 . V_27 , V_29 | V_164 ,
V_67 . V_30 , NULL , 0 , V_67 . V_49 , V_67 . V_10 ) ;
V_67 . V_29 = V_29 ;
V_67 . V_162 = true ;
} else {
F_15 ( V_67 . V_26 , V_67 . V_27 , V_29 , 0 ,
NULL , 0 , V_67 . V_49 , V_67 . V_10 ) ;
V_67 . V_10 = 0 ;
}
}
static bool F_97 ( int V_26 , int V_27 , const char * V_32 , T_6 V_10 )
{
if ( V_67 . V_10 && V_67 . V_162 )
return false ;
if ( V_67 . V_10 + V_10 > sizeof( V_67 . V_49 ) ) {
F_96 ( V_77 ) ;
return false ;
}
if ( ! V_67 . V_10 ) {
V_67 . V_26 = V_26 ;
V_67 . V_27 = V_27 ;
V_67 . V_165 = V_40 ;
V_67 . V_30 = F_16 () ;
V_67 . V_29 = 0 ;
V_67 . V_163 = 0 ;
V_67 . V_162 = false ;
}
memcpy ( V_67 . V_49 + V_67 . V_10 , V_32 , V_10 ) ;
V_67 . V_10 += V_10 ;
if ( V_67 . V_10 > ( sizeof( V_67 . V_49 ) * 80 ) / 100 )
F_96 ( V_77 ) ;
return true ;
}
static T_6 F_98 ( char * V_32 , T_6 V_20 )
{
T_6 V_138 = 0 ;
T_6 V_10 ;
if ( V_67 . V_163 == 0 && ( V_166 & V_127 ) ) {
V_138 += F_72 ( V_67 . V_30 , V_32 ) ;
V_20 -= V_138 ;
}
V_10 = V_67 . V_10 - V_67 . V_163 ;
if ( V_10 > 0 ) {
if ( V_10 + 1 > V_20 )
V_10 = V_20 - 1 ;
memcpy ( V_32 + V_138 , V_67 . V_49 + V_67 . V_163 , V_10 ) ;
V_138 += V_10 ;
V_67 . V_163 = V_67 . V_10 ;
}
if ( V_67 . V_162 ) {
if ( V_67 . V_29 & V_127 )
V_32 [ V_138 ++ ] = '\n' ;
V_67 . V_10 = 0 ;
}
return V_138 ;
}
T_10 int F_99 ( int V_26 , int V_27 ,
const char * V_31 , T_6 V_167 ,
const char * V_168 , T_11 args )
{
static int V_169 ;
static char V_170 [ V_53 ] ;
char * V_32 = V_170 ;
T_6 V_8 = 0 ;
enum V_28 V_171 = 0 ;
unsigned long V_29 ;
int V_172 ;
int V_173 = 0 ;
bool V_174 = false ;
static volatile unsigned int V_175 = V_176 ;
if ( V_27 == V_177 ) {
V_27 = - 1 ;
V_174 = true ;
}
F_67 ( V_27 ) ;
F_94 () ;
F_100 ( V_29 ) ;
V_172 = F_83 () ;
if ( F_59 ( V_175 == V_172 ) ) {
if ( ! V_178 && ! F_101 ( V_40 ) ) {
V_169 = 1 ;
F_102 ( V_29 ) ;
return 0 ;
}
F_84 () ;
}
F_103 () ;
F_104 ( & V_70 ) ;
V_175 = V_172 ;
if ( F_59 ( V_169 ) ) {
static const char V_179 [] =
L_19 ;
V_169 = 0 ;
V_173 += F_15 ( 0 , 2 , V_79 | V_127 , 0 ,
NULL , 0 , V_179 ,
strlen ( V_179 ) ) ;
}
if ( V_174 )
V_8 = F_105 ( V_32 , sizeof( V_170 ) ,
V_180 L_20 ) ;
V_8 += F_106 ( V_32 + V_8 ,
sizeof( V_170 ) - V_8 , V_168 , args ) ;
if ( V_8 && V_32 [ V_8 - 1 ] == '\n' ) {
V_8 -- ;
V_171 |= V_127 ;
}
if ( V_26 == 0 ) {
int V_181 = F_107 ( V_32 ) ;
if ( V_181 ) {
const char * V_182 = F_108 ( V_32 ) ;
switch ( V_181 ) {
case '0' ... '7' :
if ( V_27 == - 1 )
V_27 = V_181 - '0' ;
case 'd' :
V_171 |= V_79 ;
}
V_8 -= V_182 - V_32 ;
V_32 = ( char * ) V_182 ;
}
}
if ( V_27 == - 1 )
V_27 = V_51 ;
if ( V_31 )
V_171 |= V_79 | V_127 ;
if ( ! ( V_171 & V_127 ) ) {
if ( V_67 . V_10 && ( V_171 & V_79 || V_67 . V_165 != V_40 ) )
F_96 ( V_127 ) ;
if ( F_97 ( V_26 , V_27 , V_32 , V_8 ) )
V_173 += V_8 ;
else
V_173 += F_15 ( V_26 , V_27 ,
V_171 | V_77 , 0 ,
V_31 , V_167 , V_32 , V_8 ) ;
} else {
bool V_183 = false ;
if ( V_67 . V_10 ) {
if ( V_67 . V_165 == V_40 && ! ( V_171 & V_79 ) )
V_183 = F_97 ( V_26 , V_27 , V_32 ,
V_8 ) ;
F_96 ( V_127 ) ;
}
if ( V_183 )
V_173 += V_8 ;
else
V_173 += F_15 ( V_26 , V_27 , V_171 , 0 ,
V_31 , V_167 , V_32 , V_8 ) ;
}
V_175 = V_176 ;
F_109 ( & V_70 ) ;
F_110 () ;
F_102 ( V_29 ) ;
if ( ! V_174 ) {
F_103 () ;
F_111 () ;
if ( F_91 () )
F_112 () ;
F_113 () ;
F_110 () ;
}
return V_173 ;
}
T_10 int F_114 ( const char * V_168 , T_11 args )
{
return F_99 ( 0 , - 1 , NULL , 0 , V_168 , args ) ;
}
T_10 int F_28 ( int V_26 , int V_27 ,
const char * V_31 , T_6 V_167 ,
const char * V_168 , ... )
{
T_11 args ;
int V_184 ;
va_start ( args , V_168 ) ;
V_184 = F_99 ( V_26 , V_27 , V_31 , V_167 , V_168 , args ) ;
va_end ( args ) ;
return V_184 ;
}
T_10 T_12 int F_115 ( const char * V_168 , ... )
{
T_11 args ;
int V_184 ;
#ifdef F_116
if ( F_59 ( V_185 ) ) {
va_start ( args , V_168 ) ;
V_184 = F_117 ( V_168 , args ) ;
va_end ( args ) ;
return V_184 ;
}
#endif
va_start ( args , V_168 ) ;
V_184 = F_99 ( 0 , - 1 , NULL , 0 , V_168 , args ) ;
va_end ( args ) ;
return V_184 ;
}
static struct V_6 * F_8 ( T_1 V_9 ) { return NULL ; }
static T_1 F_9 ( T_1 V_9 ) { return 0 ; }
static void F_79 ( int V_27 , const char * V_32 , T_6 V_10 ) {}
static T_6 F_74 ( const struct V_6 * V_7 , enum V_28 V_78 ,
bool V_123 , char * V_49 , T_6 V_20 ) { return 0 ; }
static T_6 F_98 ( char * V_32 , T_6 V_20 ) { return 0 ; }
void F_118 ( const char * V_168 , T_11 V_186 )
{
if ( V_187 ) {
char V_49 [ 512 ] ;
int V_130 = F_106 ( V_49 , sizeof( V_49 ) , V_168 , V_186 ) ;
V_187 -> V_155 ( V_187 , V_49 , V_130 ) ;
}
}
T_10 T_12 void F_119 ( const char * V_168 , ... )
{
T_11 V_186 ;
va_start ( V_186 , V_168 ) ;
F_118 ( V_168 , V_186 ) ;
va_end ( V_186 ) ;
}
static int F_120 ( char * V_188 , int V_9 , char * V_189 ,
char * V_190 )
{
struct V_191 * V_80 ;
int V_50 ;
for ( V_50 = 0 , V_80 = V_191 ;
V_50 < V_192 && V_80 -> V_188 [ 0 ] ;
V_50 ++ , V_80 ++ ) {
if ( strcmp ( V_80 -> V_188 , V_188 ) == 0 && V_80 -> V_193 == V_9 ) {
if ( ! V_190 )
V_194 = V_50 ;
return 0 ;
}
}
if ( V_50 == V_192 )
return - V_195 ;
if ( ! V_190 )
V_194 = V_50 ;
F_121 ( V_80 -> V_188 , V_188 , sizeof( V_80 -> V_188 ) ) ;
V_80 -> V_189 = V_189 ;
F_122 ( V_80 , V_190 ) ;
V_80 -> V_193 = V_9 ;
return 0 ;
}
static int T_9 F_123 ( char * V_101 )
{
char V_49 [ sizeof( V_191 [ 0 ] . V_188 ) + 4 ] ;
char * V_196 , * V_189 , * V_190 = NULL ;
int V_9 ;
if ( F_124 ( & V_101 , & V_190 ) )
return 1 ;
if ( V_101 [ 0 ] >= '0' && V_101 [ 0 ] <= '9' ) {
strcpy ( V_49 , L_21 ) ;
strncpy ( V_49 + 4 , V_101 , sizeof( V_49 ) - 5 ) ;
} else {
strncpy ( V_49 , V_101 , sizeof( V_49 ) - 1 ) ;
}
V_49 [ sizeof( V_49 ) - 1 ] = 0 ;
V_189 = strchr ( V_101 , ',' ) ;
if ( V_189 )
* ( V_189 ++ ) = 0 ;
#ifdef F_125
if ( ! strcmp ( V_101 , L_22 ) )
strcpy ( V_49 , L_23 ) ;
if ( ! strcmp ( V_101 , L_24 ) )
strcpy ( V_49 , L_25 ) ;
#endif
for ( V_196 = V_49 ; * V_196 ; V_196 ++ )
if ( isdigit ( * V_196 ) || * V_196 == ',' )
break;
V_9 = F_27 ( V_196 , NULL , 10 ) ;
* V_196 = 0 ;
F_120 ( V_49 , V_9 , V_189 , V_190 ) ;
V_197 = 1 ;
return 1 ;
}
int F_126 ( char * V_188 , int V_9 , char * V_189 )
{
return F_120 ( V_188 , V_9 , V_189 , NULL ) ;
}
int F_127 ( char * V_188 , int V_9 , char * V_198 , int V_199 , char * V_189 )
{
struct V_191 * V_80 ;
int V_50 ;
for ( V_50 = 0 , V_80 = V_191 ;
V_50 < V_192 && V_80 -> V_188 [ 0 ] ;
V_50 ++ , V_80 ++ )
if ( strcmp ( V_80 -> V_188 , V_188 ) == 0 && V_80 -> V_193 == V_9 ) {
F_121 ( V_80 -> V_188 , V_198 , sizeof( V_80 -> V_188 ) ) ;
V_80 -> V_189 = V_189 ;
V_80 -> V_193 = V_199 ;
return V_50 ;
}
return - 1 ;
}
static int T_9 F_128 ( char * V_101 )
{
V_200 = false ;
return 1 ;
}
void F_129 ( void )
{
if ( ! V_200 )
return;
F_115 ( L_26 ) ;
F_130 () ;
V_201 = 1 ;
F_93 () ;
}
void F_131 ( void )
{
if ( ! V_200 )
return;
F_132 () ;
V_201 = 0 ;
F_112 () ;
}
static int F_133 ( struct V_202 * V_203 ,
unsigned long V_204 , void * V_205 )
{
switch ( V_204 ) {
case V_206 :
case V_207 :
case V_208 :
case V_209 :
F_130 () ;
F_112 () ;
}
return V_210 ;
}
void F_130 ( void )
{
F_134 () ;
F_132 () ;
if ( V_201 )
return;
V_159 = 1 ;
V_211 = 1 ;
}
int F_92 ( void )
{
if ( F_135 () )
return 0 ;
if ( V_201 ) {
F_93 () ;
return 0 ;
}
V_159 = 1 ;
V_211 = 0 ;
return 1 ;
}
int F_136 ( void )
{
return V_159 ;
}
static void F_137 ( char * V_32 , T_6 V_20 )
{
unsigned long V_29 ;
T_6 V_10 ;
F_61 ( & V_70 , V_29 ) ;
if ( ! V_67 . V_10 )
goto V_59;
if ( V_212 < V_16 && ! V_67 . V_163 )
goto V_59;
V_10 = F_98 ( V_32 , V_20 ) ;
F_109 ( & V_70 ) ;
F_138 () ;
F_79 ( V_67 . V_27 , V_32 , V_10 ) ;
F_139 () ;
F_102 ( V_29 ) ;
return;
V_59:
F_62 ( & V_70 , V_29 ) ;
}
void F_112 ( void )
{
static char V_32 [ V_53 + V_129 ] ;
static T_3 V_213 ;
unsigned long V_29 ;
bool V_214 = false ;
bool V_215 ;
if ( V_201 ) {
F_93 () ;
return;
}
V_211 = 0 ;
F_137 ( V_32 , sizeof( V_32 ) ) ;
V_216:
for (; ; ) {
struct V_6 * V_7 ;
T_6 V_10 ;
int V_27 ;
F_61 ( & V_70 , V_29 ) ;
if ( V_213 != V_16 ) {
V_214 = true ;
V_213 = V_16 ;
}
if ( V_212 < V_15 ) {
V_10 = sprintf ( V_32 , L_27 ,
( unsigned ) ( V_15 - V_212 ) ) ;
V_212 = V_15 ;
V_217 = V_14 ;
V_166 = 0 ;
} else {
V_10 = 0 ;
}
V_131:
if ( V_212 == V_16 )
break;
V_7 = F_8 ( V_217 ) ;
if ( V_7 -> V_29 & V_164 ) {
V_217 = F_9 ( V_217 ) ;
V_212 ++ ;
V_7 -> V_29 &= ~ V_164 ;
V_166 = V_7 -> V_29 ;
goto V_131;
}
V_27 = V_7 -> V_27 ;
V_10 += F_74 ( V_7 , V_166 , false ,
V_32 + V_10 , sizeof( V_32 ) - V_10 ) ;
V_217 = F_9 ( V_217 ) ;
V_212 ++ ;
V_166 = V_7 -> V_29 ;
F_109 ( & V_70 ) ;
F_138 () ;
F_79 ( V_27 , V_32 , V_10 ) ;
F_139 () ;
F_102 ( V_29 ) ;
}
V_159 = 0 ;
if ( F_59 ( V_153 ) )
V_153 = NULL ;
F_109 ( & V_70 ) ;
F_93 () ;
F_104 ( & V_70 ) ;
V_215 = V_212 != V_16 ;
F_62 ( & V_70 , V_29 ) ;
if ( V_215 && F_92 () )
goto V_216;
if ( V_214 )
F_140 () ;
}
void T_13 F_141 ( void )
{
if ( V_211 )
F_142 () ;
}
void F_143 ( void )
{
struct V_150 * V_80 ;
if ( V_178 ) {
if ( F_135 () != 0 )
return;
} else
F_130 () ;
V_159 = 1 ;
V_211 = 0 ;
F_81 (c)
if ( ( V_80 -> V_29 & V_154 ) && V_80 -> V_218 )
V_80 -> V_218 () ;
F_112 () ;
}
struct V_219 * F_144 ( int * V_193 )
{
struct V_150 * V_80 ;
struct V_219 * V_220 = NULL ;
F_130 () ;
F_81 (c) {
if ( ! V_80 -> V_221 )
continue;
V_220 = V_80 -> V_221 ( V_80 , V_193 ) ;
if ( V_220 )
break;
}
F_112 () ;
return V_220 ;
}
void F_145 ( struct V_150 * V_150 )
{
F_130 () ;
V_150 -> V_29 &= ~ V_154 ;
F_112 () ;
}
void F_146 ( struct V_150 * V_150 )
{
F_130 () ;
V_150 -> V_29 |= V_154 ;
F_112 () ;
}
static int T_9 F_147 ( char * V_101 )
{
V_222 = 1 ;
F_55 ( L_28 ) ;
return 0 ;
}
void F_148 ( struct V_150 * V_223 )
{
int V_50 ;
unsigned long V_29 ;
struct V_150 * V_224 = NULL ;
struct V_191 * V_80 ;
if ( V_152 )
F_81 (bcon)
if ( F_149 ( V_224 == V_223 ,
L_29 ,
V_224 -> V_188 , V_224 -> V_193 ) )
return;
if ( V_152 && V_223 -> V_29 & V_225 ) {
F_81 (bcon) {
if ( ! ( V_224 -> V_29 & V_225 ) ) {
F_55 ( L_30 ,
V_223 -> V_188 , V_223 -> V_193 ) ;
return;
}
}
}
if ( V_152 && V_152 -> V_29 & V_225 )
V_224 = V_152 ;
if ( V_226 < 0 || V_224 || ! V_152 )
V_226 = V_194 ;
if ( V_223 -> V_227 )
V_223 -> V_227 () ;
if ( V_226 < 0 ) {
if ( V_223 -> V_193 < 0 )
V_223 -> V_193 = 0 ;
if ( V_223 -> V_228 == NULL ||
V_223 -> V_228 ( V_223 , NULL ) == 0 ) {
V_223 -> V_29 |= V_154 ;
if ( V_223 -> V_221 ) {
V_223 -> V_29 |= V_229 ;
V_226 = 0 ;
}
}
}
for ( V_50 = 0 , V_80 = V_191 ;
V_50 < V_192 && V_80 -> V_188 [ 0 ] ;
V_50 ++ , V_80 ++ ) {
if ( strcmp ( V_80 -> V_188 , V_223 -> V_188 ) != 0 )
continue;
if ( V_223 -> V_193 >= 0 &&
V_223 -> V_193 != V_80 -> V_193 )
continue;
if ( V_223 -> V_193 < 0 )
V_223 -> V_193 = V_80 -> V_193 ;
if ( F_150 ( V_223 , V_80 ) )
return;
if ( V_223 -> V_228 &&
V_223 -> V_228 ( V_223 , V_191 [ V_50 ] . V_189 ) != 0 )
break;
V_223 -> V_29 |= V_154 ;
V_223 -> V_193 = V_80 -> V_193 ;
if ( V_50 == V_194 ) {
V_223 -> V_29 |= V_229 ;
V_226 = V_194 ;
}
break;
}
if ( ! ( V_223 -> V_29 & V_154 ) )
return;
if ( V_224 && ( ( V_223 -> V_29 & ( V_229 | V_225 ) ) == V_229 ) )
V_223 -> V_29 &= ~ V_230 ;
F_130 () ;
if ( ( V_223 -> V_29 & V_229 ) || V_152 == NULL ) {
V_223 -> V_128 = V_152 ;
V_152 = V_223 ;
if ( V_223 -> V_128 )
V_223 -> V_128 -> V_29 &= ~ V_229 ;
} else {
V_223 -> V_128 = V_152 -> V_128 ;
V_152 -> V_128 = V_223 ;
}
if ( V_223 -> V_29 & V_230 ) {
F_61 ( & V_70 , V_29 ) ;
V_212 = V_132 ;
V_217 = V_133 ;
V_166 = V_134 ;
F_62 ( & V_70 , V_29 ) ;
V_153 = V_223 ;
}
F_112 () ;
F_151 () ;
F_55 ( L_31 ,
( V_223 -> V_29 & V_225 ) ? L_32 : L_33 ,
V_223 -> V_188 , V_223 -> V_193 ) ;
if ( V_224 &&
( ( V_223 -> V_29 & ( V_229 | V_225 ) ) == V_229 ) &&
! V_222 ) {
F_81 (bcon)
if ( V_224 -> V_29 & V_225 )
F_152 ( V_224 ) ;
}
}
int F_152 ( struct V_150 * V_150 )
{
struct V_150 * V_231 , * V_232 ;
int V_233 ;
F_55 ( L_34 ,
( V_150 -> V_29 & V_225 ) ? L_32 : L_33 ,
V_150 -> V_188 , V_150 -> V_193 ) ;
V_233 = F_153 ( V_150 ) ;
if ( V_233 )
return V_233 ;
V_233 = 1 ;
F_130 () ;
if ( V_152 == V_150 ) {
V_152 = V_150 -> V_128 ;
V_233 = 0 ;
} else if ( V_152 ) {
for ( V_231 = V_152 -> V_128 , V_232 = V_152 ;
V_231 ; V_232 = V_231 , V_231 = V_232 -> V_128 ) {
if ( V_231 == V_150 ) {
V_232 -> V_128 = V_231 -> V_128 ;
V_233 = 0 ;
break;
}
}
}
if ( V_152 != NULL && V_150 -> V_29 & V_229 )
V_152 -> V_29 |= V_229 ;
V_150 -> V_29 &= ~ V_154 ;
F_112 () ;
F_151 () ;
return V_233 ;
}
static int T_9 F_154 ( void )
{
struct V_150 * V_151 ;
F_81 (con) {
if ( ! V_222 && V_151 -> V_29 & V_225 ) {
F_152 ( V_151 ) ;
}
}
F_155 ( F_133 , 0 ) ;
return 0 ;
}
static void F_156 ( struct V_234 * V_234 )
{
int V_235 = F_157 ( V_236 , 0 ) ;
if ( V_235 & V_237 ) {
if ( F_92 () )
F_112 () ;
}
if ( V_235 & V_238 )
F_158 ( & V_75 ) ;
}
void F_140 ( void )
{
F_111 () ;
if ( F_159 ( & V_75 ) ) {
F_160 ( V_236 , V_238 ) ;
F_161 ( & F_162 ( V_239 ) ) ;
}
F_113 () ;
}
int F_163 ( const char * V_168 , ... )
{
T_11 args ;
int V_184 ;
F_111 () ;
va_start ( args , V_168 ) ;
V_184 = F_99 ( 0 , V_177 , NULL , 0 , V_168 , args ) ;
va_end ( args ) ;
F_164 ( V_236 , V_237 ) ;
F_161 ( & F_162 ( V_239 ) ) ;
F_113 () ;
return V_184 ;
}
int F_165 ( const char * V_240 )
{
return F_166 ( & V_241 , V_240 ) ;
}
bool F_167 ( unsigned long * V_242 ,
unsigned int V_243 )
{
unsigned long V_244 = V_119 - * V_242 ;
if ( * V_242 && V_244 <= F_68 ( V_243 ) )
return false ;
* V_242 = V_119 ;
return true ;
}
int F_168 ( struct V_245 * V_246 )
{
unsigned long V_29 ;
int V_96 = - V_247 ;
if ( ! V_246 -> V_248 )
return - V_54 ;
F_169 ( & V_249 , V_29 ) ;
if ( ! V_246 -> V_250 ) {
V_246 -> V_250 = 1 ;
F_170 ( & V_246 -> V_251 , & V_252 ) ;
V_96 = 0 ;
}
F_171 ( & V_249 , V_29 ) ;
return V_96 ;
}
int F_172 ( struct V_245 * V_246 )
{
unsigned long V_29 ;
int V_96 = - V_54 ;
F_169 ( & V_249 , V_29 ) ;
if ( V_246 -> V_250 ) {
V_246 -> V_250 = 0 ;
F_173 ( & V_246 -> V_251 ) ;
V_96 = 0 ;
}
F_171 ( & V_249 , V_29 ) ;
F_174 () ;
return V_96 ;
}
void F_175 ( enum V_253 V_254 )
{
struct V_245 * V_246 ;
unsigned long V_29 ;
if ( ( V_254 > V_255 ) && ! V_256 )
return;
F_176 () ;
F_177 (dumper, &dump_list, list) {
if ( V_246 -> V_257 && V_254 > V_246 -> V_257 )
continue;
V_246 -> V_258 = true ;
F_61 ( & V_70 , V_29 ) ;
V_246 -> V_259 = V_87 ;
V_246 -> V_260 = V_86 ;
V_246 -> V_137 = V_16 ;
V_246 -> V_261 = V_13 ;
F_62 ( & V_70 , V_29 ) ;
V_246 -> V_248 ( V_246 , V_254 ) ;
V_246 -> V_258 = false ;
}
F_178 () ;
}
bool F_179 ( struct V_245 * V_246 , bool V_123 ,
char * line , T_6 V_20 , T_6 * V_10 )
{
struct V_6 * V_7 ;
T_6 V_262 = 0 ;
bool V_52 = false ;
if ( ! V_246 -> V_258 )
goto V_59;
if ( V_246 -> V_259 < V_15 ) {
V_246 -> V_259 = V_15 ;
V_246 -> V_260 = V_14 ;
}
if ( V_246 -> V_259 >= V_16 )
goto V_59;
V_7 = F_8 ( V_246 -> V_260 ) ;
V_262 = F_74 ( V_7 , 0 , V_123 , line , V_20 ) ;
V_246 -> V_260 = F_9 ( V_246 -> V_260 ) ;
V_246 -> V_259 ++ ;
V_52 = true ;
V_59:
if ( V_10 )
* V_10 = V_262 ;
return V_52 ;
}
bool F_180 ( struct V_245 * V_246 , bool V_123 ,
char * line , T_6 V_20 , T_6 * V_10 )
{
unsigned long V_29 ;
bool V_52 ;
F_61 ( & V_70 , V_29 ) ;
V_52 = F_179 ( V_246 , V_123 , line , V_20 , V_10 ) ;
F_62 ( & V_70 , V_29 ) ;
return V_52 ;
}
bool F_181 ( struct V_245 * V_246 , bool V_123 ,
char * V_49 , T_6 V_20 , T_6 * V_10 )
{
unsigned long V_29 ;
T_3 V_71 ;
T_1 V_9 ;
T_3 V_137 ;
T_1 V_261 ;
enum V_28 V_78 ;
T_6 V_262 = 0 ;
bool V_52 = false ;
if ( ! V_246 -> V_258 )
goto V_59;
F_61 ( & V_70 , V_29 ) ;
if ( V_246 -> V_259 < V_15 ) {
V_246 -> V_259 = V_15 ;
V_246 -> V_260 = V_14 ;
}
if ( V_246 -> V_259 >= V_246 -> V_137 ) {
F_62 ( & V_70 , V_29 ) ;
goto V_59;
}
V_71 = V_246 -> V_259 ;
V_9 = V_246 -> V_260 ;
V_78 = 0 ;
while ( V_71 < V_246 -> V_137 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_262 += F_74 ( V_7 , V_78 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_71 ++ ;
V_78 = V_7 -> V_29 ;
}
V_71 = V_246 -> V_259 ;
V_9 = V_246 -> V_260 ;
V_78 = 0 ;
while ( V_262 > V_20 && V_71 < V_246 -> V_137 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_262 -= F_74 ( V_7 , V_78 , true , NULL , 0 ) ;
V_9 = F_9 ( V_9 ) ;
V_71 ++ ;
V_78 = V_7 -> V_29 ;
}
V_137 = V_71 ;
V_261 = V_9 ;
V_262 = 0 ;
while ( V_71 < V_246 -> V_137 ) {
struct V_6 * V_7 = F_8 ( V_9 ) ;
V_262 += F_74 ( V_7 , V_78 , V_123 , V_49 + V_262 , V_20 - V_262 ) ;
V_9 = F_9 ( V_9 ) ;
V_71 ++ ;
V_78 = V_7 -> V_29 ;
}
V_246 -> V_137 = V_137 ;
V_246 -> V_261 = V_261 ;
V_52 = true ;
F_62 ( & V_70 , V_29 ) ;
V_59:
if ( V_10 )
* V_10 = V_262 ;
return V_52 ;
}
void F_182 ( struct V_245 * V_246 )
{
V_246 -> V_259 = V_87 ;
V_246 -> V_260 = V_86 ;
V_246 -> V_137 = V_16 ;
V_246 -> V_261 = V_13 ;
}
void F_183 ( struct V_245 * V_246 )
{
unsigned long V_29 ;
F_61 ( & V_70 , V_29 ) ;
F_182 ( V_246 ) ;
F_62 ( & V_70 , V_29 ) ;
}
void T_9 F_184 ( const char * V_168 , ... )
{
T_11 args ;
va_start ( args , V_168 ) ;
vsnprintf ( V_263 , sizeof( V_263 ) ,
V_168 , args ) ;
va_end ( args ) ;
}
void F_185 ( const char * V_264 )
{
F_115 ( L_35 ,
V_264 , F_186 () , V_40 -> V_265 , V_40 -> V_41 ,
F_187 () , F_188 () -> V_266 ,
( int ) strcspn ( F_188 () -> V_267 , L_36 ) ,
F_188 () -> V_267 ) ;
if ( V_263 [ 0 ] != '\0' )
F_115 ( L_37 ,
V_264 , V_263 ) ;
F_189 ( V_264 , V_40 ) ;
}
void F_190 ( const char * V_264 )
{
F_185 ( V_264 ) ;
F_115 ( L_38 ,
V_264 , V_40 , F_191 () ,
F_192 ( V_40 ) ) ;
}
