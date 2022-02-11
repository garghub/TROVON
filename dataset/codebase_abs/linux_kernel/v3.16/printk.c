static int F_1 ( unsigned long V_1 )
{
if ( F_2 ( & V_2 ) )
return 1 ;
F_3 ( & V_3 , 0 , 1 , V_1 ) ;
return 0 ;
}
static char * F_4 ( const struct V_4 * V_5 )
{
return ( char * ) V_5 + sizeof( struct V_4 ) ;
}
static char * F_5 ( const struct V_4 * V_5 )
{
return ( char * ) V_5 + sizeof( struct V_4 ) + V_5 -> V_6 ;
}
static struct V_4 * F_6 ( T_1 V_7 )
{
struct V_4 * V_5 = (struct V_4 * ) ( V_8 + V_7 ) ;
if ( ! V_5 -> V_9 )
return (struct V_4 * ) V_8 ;
return V_5 ;
}
static T_1 F_7 ( T_1 V_7 )
{
struct V_4 * V_5 = (struct V_4 * ) ( V_8 + V_7 ) ;
if ( ! V_5 -> V_9 ) {
V_5 = (struct V_4 * ) V_8 ;
return V_5 -> V_9 ;
}
return V_7 + V_5 -> V_9 ;
}
static int F_8 ( T_1 V_10 , bool V_11 )
{
T_1 free ;
if ( V_12 > V_13 || V_11 )
free = F_9 ( V_14 - V_12 , V_13 ) ;
else
free = V_13 - V_12 ;
return free >= V_10 + sizeof( struct V_4 ) ;
}
static int F_10 ( T_1 V_10 )
{
while ( V_15 < V_16 ) {
if ( F_8 ( V_10 , false ) )
return 0 ;
V_13 = F_7 ( V_13 ) ;
V_15 ++ ;
}
if ( F_8 ( V_10 , true ) )
return 0 ;
return - V_17 ;
}
static T_1 F_11 ( T_2 V_6 , T_2 V_18 , T_1 * V_19 )
{
T_1 V_20 ;
V_20 = sizeof( struct V_4 ) + V_6 + V_18 ;
* V_19 = ( - V_20 ) & ( V_21 - 1 ) ;
V_20 += * V_19 ;
return V_20 ;
}
static T_1 F_12 ( T_2 * V_6 , T_2 * V_22 ,
T_2 * V_18 , T_1 * V_19 )
{
T_1 V_23 = V_14 / V_24 ;
if ( * V_6 > V_23 )
* V_6 = V_23 ;
* V_22 = strlen ( V_25 ) ;
* V_18 = 0 ;
return F_11 ( * V_6 + * V_22 , 0 , V_19 ) ;
}
static int F_13 ( int V_26 , int V_27 ,
enum V_28 V_29 , T_3 V_30 ,
const char * V_31 , T_2 V_18 ,
const char * V_32 , T_2 V_6 )
{
struct V_4 * V_5 ;
T_1 V_20 , V_19 ;
T_2 V_22 = 0 ;
V_20 = F_11 ( V_6 , V_18 , & V_19 ) ;
if ( F_10 ( V_20 ) ) {
V_20 = F_12 ( & V_6 , & V_22 ,
& V_18 , & V_19 ) ;
if ( F_10 ( V_20 ) )
return 0 ;
}
if ( V_12 + V_20 + sizeof( struct V_4 ) > V_14 ) {
memset ( V_8 + V_12 , 0 , sizeof( struct V_4 ) ) ;
V_12 = 0 ;
}
V_5 = (struct V_4 * ) ( V_8 + V_12 ) ;
memcpy ( F_4 ( V_5 ) , V_32 , V_6 ) ;
V_5 -> V_6 = V_6 ;
if ( V_22 ) {
memcpy ( F_4 ( V_5 ) + V_6 , V_25 , V_22 ) ;
V_5 -> V_6 += V_22 ;
}
memcpy ( F_5 ( V_5 ) , V_31 , V_18 ) ;
V_5 -> V_18 = V_18 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_27 = V_27 & 7 ;
V_5 -> V_29 = V_29 & 0x1f ;
if ( V_30 > 0 )
V_5 -> V_30 = V_30 ;
else
V_5 -> V_30 = F_14 () ;
memset ( F_5 ( V_5 ) + V_18 , 0 , V_19 ) ;
V_5 -> V_9 = V_20 ;
V_12 += V_5 -> V_9 ;
V_16 ++ ;
return V_5 -> V_6 ;
}
static int F_15 ( int type )
{
if ( V_33 )
return 1 ;
return type != V_34 &&
type != V_35 ;
}
static int F_16 ( int type , bool V_36 )
{
if ( V_36 && type != V_37 )
return 0 ;
if ( F_15 ( type ) ) {
if ( F_17 ( V_38 ) )
return 0 ;
if ( F_17 ( V_39 ) ) {
F_18 ( L_1
L_2
L_3 ,
V_40 -> V_41 , F_19 ( V_40 ) ) ;
return 0 ;
}
return - V_42 ;
}
return F_20 ( type ) ;
}
static T_4 F_21 ( struct V_43 * V_44 , const struct V_45 * V_46 ,
unsigned long V_47 , T_5 V_48 )
{
char * V_49 , * line ;
int V_50 ;
int V_27 = V_51 ;
int V_26 = 1 ;
T_6 V_9 = F_22 ( V_46 , V_47 ) ;
T_4 V_52 = V_9 ;
if ( V_9 > V_53 )
return - V_54 ;
V_49 = F_23 ( V_9 + 1 , V_55 ) ;
if ( V_49 == NULL )
return - V_17 ;
line = V_49 ;
for ( V_50 = 0 ; V_50 < V_47 ; V_50 ++ ) {
if ( F_24 ( line , V_46 [ V_50 ] . V_56 , V_46 [ V_50 ] . V_57 ) ) {
V_52 = - V_58 ;
goto V_59;
}
line += V_46 [ V_50 ] . V_57 ;
}
line = V_49 ;
if ( line [ 0 ] == '<' ) {
char * V_60 = NULL ;
V_50 = F_25 ( line + 1 , & V_60 , 10 ) ;
if ( V_60 && V_60 [ 0 ] == '>' ) {
V_27 = V_50 & 7 ;
if ( V_50 >> 3 )
V_26 = V_50 >> 3 ;
V_60 ++ ;
V_9 -= V_60 - line ;
line = V_60 ;
}
}
line [ V_9 ] = '\0' ;
F_26 ( V_26 , V_27 , NULL , 0 , L_4 , line ) ;
V_59:
F_27 ( V_49 ) ;
return V_52 ;
}
static T_4 F_28 ( struct V_61 * V_61 , char T_7 * V_49 ,
T_6 V_47 , T_5 * V_62 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
struct V_4 * V_5 ;
T_3 V_66 ;
T_6 V_50 ;
char V_67 = '-' ;
T_6 V_9 ;
T_4 V_52 ;
if ( ! V_64 )
return - V_68 ;
V_52 = F_29 ( & V_64 -> V_69 ) ;
if ( V_52 )
return V_52 ;
F_30 ( & V_70 ) ;
while ( V_64 -> V_71 == V_16 ) {
if ( V_61 -> V_72 & V_73 ) {
V_52 = - V_74 ;
F_31 ( & V_70 ) ;
goto V_59;
}
F_31 ( & V_70 ) ;
V_52 = F_32 ( V_75 ,
V_64 -> V_71 != V_16 ) ;
if ( V_52 )
goto V_59;
F_30 ( & V_70 ) ;
}
if ( V_64 -> V_71 < V_15 ) {
V_64 -> V_7 = V_13 ;
V_64 -> V_71 = V_15 ;
V_52 = - V_76 ;
F_31 ( & V_70 ) ;
goto V_59;
}
V_5 = F_6 ( V_64 -> V_7 ) ;
V_66 = V_5 -> V_30 ;
F_33 ( V_66 , 1000 ) ;
if ( V_5 -> V_29 & V_77 && ! ( V_64 -> V_78 & V_77 ) )
V_67 = 'c' ;
else if ( ( V_5 -> V_29 & V_77 ) ||
( ( V_64 -> V_78 & V_77 ) && ! ( V_5 -> V_29 & V_79 ) ) )
V_67 = '+' ;
V_9 = sprintf ( V_64 -> V_49 , L_5 ,
( V_5 -> V_26 << 3 ) | V_5 -> V_27 ,
V_64 -> V_71 , V_66 , V_67 ) ;
V_64 -> V_78 = V_5 -> V_29 ;
for ( V_50 = 0 ; V_50 < V_5 -> V_6 ; V_50 ++ ) {
unsigned char V_80 = F_4 ( V_5 ) [ V_50 ] ;
if ( V_80 < ' ' || V_80 >= 127 || V_80 == '\\' )
V_9 += sprintf ( V_64 -> V_49 + V_9 , L_6 , V_80 ) ;
else
V_64 -> V_49 [ V_9 ++ ] = V_80 ;
}
V_64 -> V_49 [ V_9 ++ ] = '\n' ;
if ( V_5 -> V_18 ) {
bool line = true ;
for ( V_50 = 0 ; V_50 < V_5 -> V_18 ; V_50 ++ ) {
unsigned char V_80 = F_5 ( V_5 ) [ V_50 ] ;
if ( line ) {
V_64 -> V_49 [ V_9 ++ ] = ' ' ;
line = false ;
}
if ( V_80 == '\0' ) {
V_64 -> V_49 [ V_9 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_80 < ' ' || V_80 >= 127 || V_80 == '\\' ) {
V_9 += sprintf ( V_64 -> V_49 + V_9 , L_6 , V_80 ) ;
continue;
}
V_64 -> V_49 [ V_9 ++ ] = V_80 ;
}
V_64 -> V_49 [ V_9 ++ ] = '\n' ;
}
V_64 -> V_7 = F_7 ( V_64 -> V_7 ) ;
V_64 -> V_71 ++ ;
F_31 ( & V_70 ) ;
if ( V_9 > V_47 ) {
V_52 = - V_54 ;
goto V_59;
}
if ( F_34 ( V_49 , V_64 -> V_49 , V_9 ) ) {
V_52 = - V_58 ;
goto V_59;
}
V_52 = V_9 ;
V_59:
F_35 ( & V_64 -> V_69 ) ;
return V_52 ;
}
static T_5 F_36 ( struct V_61 * V_61 , T_5 V_81 , int V_82 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
T_5 V_52 = 0 ;
if ( ! V_64 )
return - V_68 ;
if ( V_81 )
return - V_83 ;
F_30 ( & V_70 ) ;
switch ( V_82 ) {
case V_84 :
V_64 -> V_7 = V_13 ;
V_64 -> V_71 = V_15 ;
break;
case V_85 :
V_64 -> V_7 = V_86 ;
V_64 -> V_71 = V_87 ;
break;
case V_88 :
V_64 -> V_7 = V_12 ;
V_64 -> V_71 = V_16 ;
break;
default:
V_52 = - V_54 ;
}
F_31 ( & V_70 ) ;
return V_52 ;
}
static unsigned int F_37 ( struct V_61 * V_61 , T_8 * V_89 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
int V_52 = 0 ;
if ( ! V_64 )
return V_90 | V_91 ;
F_38 ( V_61 , & V_75 , V_89 ) ;
F_30 ( & V_70 ) ;
if ( V_64 -> V_71 < V_16 ) {
if ( V_64 -> V_71 < V_15 )
V_52 = V_92 | V_93 | V_90 | V_94 ;
else
V_52 = V_92 | V_93 ;
}
F_31 ( & V_70 ) ;
return V_52 ;
}
static int F_39 ( struct V_95 * V_95 , struct V_61 * V_61 )
{
struct V_63 * V_64 ;
int V_96 ;
if ( ( V_61 -> V_72 & V_97 ) == V_98 )
return 0 ;
V_96 = F_16 ( V_34 ,
V_99 ) ;
if ( V_96 )
return V_96 ;
V_64 = F_23 ( sizeof( struct V_63 ) , V_55 ) ;
if ( ! V_64 )
return - V_17 ;
F_40 ( & V_64 -> V_69 ) ;
F_30 ( & V_70 ) ;
V_64 -> V_7 = V_13 ;
V_64 -> V_71 = V_15 ;
F_31 ( & V_70 ) ;
V_61 -> V_65 = V_64 ;
return 0 ;
}
static int F_41 ( struct V_95 * V_95 , struct V_61 * V_61 )
{
struct V_63 * V_64 = V_61 -> V_65 ;
if ( ! V_64 )
return 0 ;
F_42 ( & V_64 -> V_69 ) ;
F_27 ( V_64 ) ;
return 0 ;
}
void F_43 ( void )
{
F_44 ( V_8 ) ;
F_44 ( V_14 ) ;
F_44 ( V_13 ) ;
F_44 ( V_12 ) ;
F_45 ( V_4 ) ;
F_46 ( V_4 , V_30 ) ;
F_46 ( V_4 , V_9 ) ;
F_46 ( V_4 , V_6 ) ;
F_46 ( V_4 , V_18 ) ;
}
static int T_9 F_47 ( char * V_100 )
{
unsigned V_20 = F_48 ( V_100 , & V_100 ) ;
if ( V_20 )
V_20 = F_49 ( V_20 ) ;
if ( V_20 > V_14 )
V_101 = V_20 ;
return 0 ;
}
void T_9 F_50 ( int V_102 )
{
unsigned long V_29 ;
char * V_103 ;
int free ;
if ( ! V_101 )
return;
if ( V_102 ) {
V_103 =
F_51 ( V_101 , V_104 ) ;
} else {
V_103 = F_52 ( V_101 , 0 ) ;
}
if ( F_53 ( ! V_103 ) ) {
F_54 ( L_7 ,
V_101 ) ;
return;
}
F_55 ( & V_70 , V_29 ) ;
V_14 = V_101 ;
V_8 = V_103 ;
V_101 = 0 ;
free = V_105 - V_12 ;
memcpy ( V_8 , V_106 , V_105 ) ;
F_56 ( & V_70 , V_29 ) ;
F_57 ( L_8 , V_14 ) ;
F_57 ( L_9 ,
free , ( free * 100 ) / V_105 ) ;
}
static int T_9 F_58 ( char * V_100 )
{
V_107 = 1 ;
F_57 ( L_10 ) ;
return 0 ;
}
static int T_9 F_59 ( char * V_100 )
{
unsigned long V_108 ;
V_108 = V_109 ? V_109 : 1000000 ;
V_110 = ( unsigned long long ) V_108 / 1000 * V_111 ;
F_60 ( & V_100 , & V_112 ) ;
if ( V_112 > 10 * 1000 )
V_112 = 0 ;
F_61 ( L_11
L_12 ,
V_112 , V_109 , V_108 , V_111 , V_110 ) ;
return 0 ;
}
static void F_62 ( int V_27 )
{
unsigned long long V_113 ;
unsigned long V_114 ;
if ( ( V_112 == 0 || V_115 != V_116 )
|| ( V_27 >= V_117 && ! V_107 ) ) {
return;
}
V_113 = ( unsigned long long ) V_110 * V_112 ;
V_114 = V_118 + F_63 ( V_112 ) ;
while ( V_113 ) {
V_113 -- ;
F_64 () ;
if ( F_65 ( V_118 , V_114 ) )
break;
F_66 () ;
}
}
static inline void F_62 ( int V_27 )
{
}
static T_6 F_67 ( T_3 V_119 , char * V_49 )
{
unsigned long V_120 ;
if ( ! V_121 )
return 0 ;
V_120 = F_33 ( V_119 , 1000000000 ) ;
if ( ! V_49 )
return snprintf ( NULL , 0 , L_13 , ( unsigned long ) V_119 ) ;
return sprintf ( V_49 , L_14 ,
( unsigned long ) V_119 , V_120 / 1000 ) ;
}
static T_6 F_68 ( const struct V_4 * V_5 , bool V_122 , char * V_49 )
{
T_6 V_9 = 0 ;
unsigned int V_123 = ( V_5 -> V_26 << 3 ) | V_5 -> V_27 ;
if ( V_122 ) {
if ( V_49 ) {
V_9 += sprintf ( V_49 , L_15 , V_123 ) ;
} else {
V_9 += 3 ;
if ( V_123 > 999 )
V_9 += 3 ;
else if ( V_123 > 99 )
V_9 += 2 ;
else if ( V_123 > 9 )
V_9 ++ ;
}
}
V_9 += F_67 ( V_5 -> V_30 , V_49 ? V_49 + V_9 : NULL ) ;
return V_9 ;
}
static T_6 F_69 ( const struct V_4 * V_5 , enum V_28 V_78 ,
bool V_122 , char * V_49 , T_6 V_20 )
{
const char * V_32 = F_4 ( V_5 ) ;
T_6 V_124 = V_5 -> V_6 ;
bool V_123 = true ;
bool V_125 = true ;
T_6 V_9 = 0 ;
if ( ( V_78 & V_77 ) && ! ( V_5 -> V_29 & V_79 ) )
V_123 = false ;
if ( V_5 -> V_29 & V_77 ) {
if ( ( V_78 & V_77 ) && ! ( V_78 & V_126 ) )
V_123 = false ;
if ( ! ( V_5 -> V_29 & V_126 ) )
V_125 = false ;
}
do {
const char * V_127 = memchr ( V_32 , '\n' , V_124 ) ;
T_6 V_6 ;
if ( V_127 ) {
V_6 = V_127 - V_32 ;
V_127 ++ ;
V_124 -= V_127 - V_32 ;
} else {
V_6 = V_124 ;
}
if ( V_49 ) {
if ( F_68 ( V_5 , V_122 , NULL ) +
V_6 + 1 >= V_20 - V_9 )
break;
if ( V_123 )
V_9 += F_68 ( V_5 , V_122 , V_49 + V_9 ) ;
memcpy ( V_49 + V_9 , V_32 , V_6 ) ;
V_9 += V_6 ;
if ( V_127 || V_125 )
V_49 [ V_9 ++ ] = '\n' ;
} else {
if ( V_123 )
V_9 += F_68 ( V_5 , V_122 , NULL ) ;
V_9 += V_6 ;
if ( V_127 || V_125 )
V_9 ++ ;
}
V_123 = true ;
V_32 = V_127 ;
} while ( V_32 );
return V_9 ;
}
static int F_70 ( char T_7 * V_49 , int V_20 )
{
char * V_32 ;
struct V_4 * V_5 ;
int V_9 = 0 ;
V_32 = F_23 ( V_53 + V_128 , V_55 ) ;
if ( ! V_32 )
return - V_17 ;
while ( V_20 > 0 ) {
T_6 V_129 ;
T_6 V_130 ;
F_30 ( & V_70 ) ;
if ( V_131 < V_15 ) {
V_131 = V_15 ;
V_132 = V_13 ;
V_133 = 0 ;
V_134 = 0 ;
}
if ( V_131 == V_16 ) {
F_31 ( & V_70 ) ;
break;
}
V_130 = V_134 ;
V_5 = F_6 ( V_132 ) ;
V_129 = F_69 ( V_5 , V_133 , true , V_32 ,
V_53 + V_128 ) ;
if ( V_129 - V_134 <= V_20 ) {
V_132 = F_7 ( V_132 ) ;
V_131 ++ ;
V_133 = V_5 -> V_29 ;
V_129 -= V_134 ;
V_134 = 0 ;
} else if ( ! V_9 ) {
V_129 = V_20 ;
V_134 += V_129 ;
} else
V_129 = 0 ;
F_31 ( & V_70 ) ;
if ( ! V_129 )
break;
if ( F_34 ( V_49 , V_32 + V_130 , V_129 ) ) {
if ( ! V_9 )
V_9 = - V_58 ;
break;
}
V_9 += V_129 ;
V_20 -= V_129 ;
V_49 += V_129 ;
}
F_27 ( V_32 ) ;
return V_9 ;
}
static int F_71 ( char T_7 * V_49 , int V_20 , bool V_135 )
{
char * V_32 ;
int V_9 = 0 ;
V_32 = F_23 ( V_53 + V_128 , V_55 ) ;
if ( ! V_32 )
return - V_17 ;
F_30 ( & V_70 ) ;
if ( V_49 ) {
T_3 V_136 ;
T_3 V_71 ;
T_1 V_7 ;
enum V_28 V_78 ;
if ( V_87 < V_15 ) {
V_87 = V_15 ;
V_86 = V_13 ;
}
V_71 = V_87 ;
V_7 = V_86 ;
V_78 = 0 ;
while ( V_71 < V_16 ) {
struct V_4 * V_5 = F_6 ( V_7 ) ;
V_9 += F_69 ( V_5 , V_78 , true , NULL , 0 ) ;
V_78 = V_5 -> V_29 ;
V_7 = F_7 ( V_7 ) ;
V_71 ++ ;
}
V_71 = V_87 ;
V_7 = V_86 ;
V_78 = 0 ;
while ( V_9 > V_20 && V_71 < V_16 ) {
struct V_4 * V_5 = F_6 ( V_7 ) ;
V_9 -= F_69 ( V_5 , V_78 , true , NULL , 0 ) ;
V_78 = V_5 -> V_29 ;
V_7 = F_7 ( V_7 ) ;
V_71 ++ ;
}
V_136 = V_16 ;
V_9 = 0 ;
while ( V_9 >= 0 && V_71 < V_136 ) {
struct V_4 * V_5 = F_6 ( V_7 ) ;
int V_137 ;
V_137 = F_69 ( V_5 , V_78 , true , V_32 ,
V_53 + V_128 ) ;
if ( V_137 < 0 ) {
V_9 = V_137 ;
break;
}
V_7 = F_7 ( V_7 ) ;
V_71 ++ ;
V_78 = V_5 -> V_29 ;
F_31 ( & V_70 ) ;
if ( F_34 ( V_49 + V_9 , V_32 , V_137 ) )
V_9 = - V_58 ;
else
V_9 += V_137 ;
F_30 ( & V_70 ) ;
if ( V_71 < V_15 ) {
V_71 = V_15 ;
V_7 = V_13 ;
V_78 = 0 ;
}
}
}
if ( V_135 ) {
V_87 = V_16 ;
V_86 = V_12 ;
}
F_31 ( & V_70 ) ;
F_27 ( V_32 ) ;
return V_9 ;
}
int F_72 ( int type , char T_7 * V_49 , int V_9 , bool V_36 )
{
bool V_135 = false ;
static int V_138 = - 1 ;
int error ;
error = F_16 ( type , V_36 ) ;
if ( error )
goto V_59;
error = F_20 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_139 :
break;
case V_37 :
break;
case V_140 :
error = - V_54 ;
if ( ! V_49 || V_9 < 0 )
goto V_59;
error = 0 ;
if ( ! V_9 )
goto V_59;
if ( ! F_73 ( V_141 , V_49 , V_9 ) ) {
error = - V_58 ;
goto V_59;
}
error = F_32 ( V_75 ,
V_131 != V_16 ) ;
if ( error )
goto V_59;
error = F_70 ( V_49 , V_9 ) ;
break;
case V_142 :
V_135 = true ;
case V_34 :
error = - V_54 ;
if ( ! V_49 || V_9 < 0 )
goto V_59;
error = 0 ;
if ( ! V_9 )
goto V_59;
if ( ! F_73 ( V_141 , V_49 , V_9 ) ) {
error = - V_58 ;
goto V_59;
}
error = F_71 ( V_49 , V_9 , V_135 ) ;
break;
case V_143 :
F_71 ( NULL , 0 , true ) ;
break;
case V_144 :
if ( V_138 == - 1 )
V_138 = V_117 ;
V_117 = V_145 ;
break;
case V_146 :
if ( V_138 != - 1 ) {
V_117 = V_138 ;
V_138 = - 1 ;
}
break;
case V_147 :
error = - V_54 ;
if ( V_9 < 1 || V_9 > 8 )
goto V_59;
if ( V_9 < V_145 )
V_9 = V_145 ;
V_117 = V_9 ;
V_138 = - 1 ;
error = 0 ;
break;
case V_148 :
F_30 ( & V_70 ) ;
if ( V_131 < V_15 ) {
V_131 = V_15 ;
V_132 = V_13 ;
V_133 = 0 ;
V_134 = 0 ;
}
if ( V_36 ) {
error = V_12 - V_132 ;
} else {
T_3 V_71 = V_131 ;
T_1 V_7 = V_132 ;
enum V_28 V_78 = V_133 ;
error = 0 ;
while ( V_71 < V_16 ) {
struct V_4 * V_5 = F_6 ( V_7 ) ;
error += F_69 ( V_5 , V_78 , true , NULL , 0 ) ;
V_7 = F_7 ( V_7 ) ;
V_71 ++ ;
V_78 = V_5 -> V_29 ;
}
error -= V_134 ;
}
F_31 ( & V_70 ) ;
break;
case V_35 :
error = V_14 ;
break;
default:
error = - V_54 ;
break;
}
V_59:
return error ;
}
static void F_74 ( int V_27 , const char * V_32 , T_6 V_9 )
{
struct V_149 * V_150 ;
F_75 ( V_32 , V_9 ) ;
if ( V_27 >= V_117 && ! V_107 )
return;
if ( ! V_151 )
return;
F_76 (con) {
if ( V_152 && V_150 != V_152 )
continue;
if ( ! ( V_150 -> V_29 & V_153 ) )
continue;
if ( ! V_150 -> V_154 )
continue;
if ( ! F_77 ( F_78 () ) &&
! ( V_150 -> V_29 & V_155 ) )
continue;
V_150 -> V_154 ( V_150 , V_32 , V_9 ) ;
}
}
static void F_79 ( void )
{
static unsigned long V_156 ;
if ( F_80 ( V_118 , V_156 ) &&
! F_65 ( V_118 , V_156 + 30 * V_111 ) )
return;
V_156 = V_118 ;
F_81 () ;
F_82 ( & V_70 ) ;
F_83 ( & V_2 , 1 ) ;
}
static int F_84 ( void )
{
struct V_149 * V_150 ;
F_76 (con)
if ( V_150 -> V_29 & V_155 )
return 1 ;
return 0 ;
}
static inline int F_85 ( unsigned int V_157 )
{
return F_77 ( V_157 ) || F_84 () ;
}
static int F_86 ( unsigned int V_157 )
{
if ( ! F_87 () )
return 0 ;
if ( ! F_85 ( V_157 ) ) {
V_158 = 0 ;
F_88 () ;
return 0 ;
}
return 1 ;
}
static inline void F_89 ( void )
{
if ( F_53 ( V_159 ) ) {
int V_160 = V_159 ;
while ( V_160 -- ) {
F_90 ( 1 ) ;
F_66 () ;
}
}
}
static void F_91 ( enum V_28 V_29 )
{
if ( V_67 . V_161 )
return;
if ( V_67 . V_9 == 0 )
return;
if ( V_67 . V_162 ) {
F_13 ( V_67 . V_26 , V_67 . V_27 , V_29 | V_163 ,
V_67 . V_30 , NULL , 0 , V_67 . V_49 , V_67 . V_9 ) ;
V_67 . V_29 = V_29 ;
V_67 . V_161 = true ;
} else {
F_13 ( V_67 . V_26 , V_67 . V_27 , V_29 , 0 ,
NULL , 0 , V_67 . V_49 , V_67 . V_9 ) ;
V_67 . V_9 = 0 ;
}
}
static bool F_92 ( int V_26 , int V_27 , const char * V_32 , T_6 V_9 )
{
if ( V_67 . V_9 && V_67 . V_161 )
return false ;
if ( V_67 . V_9 + V_9 > sizeof( V_67 . V_49 ) ) {
F_91 ( V_77 ) ;
return false ;
}
if ( ! V_67 . V_9 ) {
V_67 . V_26 = V_26 ;
V_67 . V_27 = V_27 ;
V_67 . V_164 = V_40 ;
V_67 . V_30 = F_14 () ;
V_67 . V_29 = 0 ;
V_67 . V_162 = 0 ;
V_67 . V_161 = false ;
}
memcpy ( V_67 . V_49 + V_67 . V_9 , V_32 , V_9 ) ;
V_67 . V_9 += V_9 ;
if ( V_67 . V_9 > ( sizeof( V_67 . V_49 ) * 80 ) / 100 )
F_91 ( V_77 ) ;
return true ;
}
static T_6 F_93 ( char * V_32 , T_6 V_20 )
{
T_6 V_137 = 0 ;
T_6 V_9 ;
if ( V_67 . V_162 == 0 && ( V_165 & V_126 ) ) {
V_137 += F_67 ( V_67 . V_30 , V_32 ) ;
V_20 -= V_137 ;
}
V_9 = V_67 . V_9 - V_67 . V_162 ;
if ( V_9 > 0 ) {
if ( V_9 + 1 > V_20 )
V_9 = V_20 - 1 ;
memcpy ( V_32 + V_137 , V_67 . V_49 + V_67 . V_162 , V_9 ) ;
V_137 += V_9 ;
V_67 . V_162 = V_67 . V_9 ;
}
if ( V_67 . V_161 ) {
if ( V_67 . V_29 & V_126 )
V_32 [ V_137 ++ ] = '\n' ;
V_67 . V_9 = 0 ;
}
return V_137 ;
}
T_10 int F_94 ( int V_26 , int V_27 ,
const char * V_31 , T_6 V_166 ,
const char * V_167 , T_11 args )
{
static int V_168 ;
static char V_169 [ V_53 ] ;
char * V_32 = V_169 ;
T_6 V_6 = 0 ;
enum V_28 V_170 = 0 ;
unsigned long V_29 ;
int V_171 ;
int V_172 = 0 ;
bool V_173 = false ;
static volatile unsigned int V_174 = V_175 ;
if ( V_27 == V_176 ) {
V_27 = - 1 ;
V_173 = true ;
}
F_62 ( V_27 ) ;
F_89 () ;
F_95 ( V_29 ) ;
V_171 = F_78 () ;
if ( F_53 ( V_174 == V_171 ) ) {
if ( ! V_177 && ! F_96 ( V_40 ) ) {
V_168 = 1 ;
goto V_178;
}
F_79 () ;
}
F_97 () ;
F_98 ( & V_70 ) ;
V_174 = V_171 ;
if ( V_168 ) {
static const char V_179 [] =
L_16 ;
V_168 = 0 ;
V_6 = strlen ( V_179 ) ;
V_172 += F_13 ( 0 , 2 , V_79 | V_126 , 0 ,
NULL , 0 , V_179 , V_6 ) ;
}
if ( V_173 )
V_6 = F_99 ( V_32 , sizeof( V_169 ) ,
V_180 L_17 ) ;
V_6 += F_100 ( V_32 + V_6 ,
sizeof( V_169 ) - V_6 , V_167 , args ) ;
if ( V_6 && V_32 [ V_6 - 1 ] == '\n' ) {
V_6 -- ;
V_170 |= V_126 ;
}
if ( V_26 == 0 ) {
int V_181 = F_101 ( V_32 ) ;
if ( V_181 ) {
const char * V_182 = F_102 ( V_32 ) ;
switch ( V_181 ) {
case '0' ... '7' :
if ( V_27 == - 1 )
V_27 = V_181 - '0' ;
case 'd' :
V_170 |= V_79 ;
}
V_6 -= V_182 - V_32 ;
V_32 = ( char * ) V_182 ;
}
}
if ( V_27 == - 1 )
V_27 = V_51 ;
if ( V_31 )
V_170 |= V_79 | V_126 ;
if ( ! ( V_170 & V_126 ) ) {
if ( V_67 . V_9 && ( V_170 & V_79 || V_67 . V_164 != V_40 ) )
F_91 ( V_126 ) ;
if ( F_92 ( V_26 , V_27 , V_32 , V_6 ) )
V_172 += V_6 ;
else
V_172 += F_13 ( V_26 , V_27 ,
V_170 | V_77 , 0 ,
V_31 , V_166 , V_32 , V_6 ) ;
} else {
bool V_183 = false ;
if ( V_67 . V_9 ) {
if ( V_67 . V_164 == V_40 && ! ( V_170 & V_79 ) )
V_183 = F_92 ( V_26 , V_27 , V_32 ,
V_6 ) ;
F_91 ( V_126 ) ;
}
if ( V_183 )
V_172 += V_6 ;
else
V_172 += F_13 ( V_26 , V_27 , V_170 , 0 ,
V_31 , V_166 , V_32 , V_6 ) ;
}
V_174 = V_175 ;
F_103 ( & V_70 ) ;
if ( ! V_173 ) {
if ( F_86 ( V_171 ) )
F_104 () ;
}
F_105 () ;
V_178:
F_106 ( V_29 ) ;
return V_172 ;
}
T_10 int F_107 ( const char * V_167 , T_11 args )
{
return F_94 ( 0 , - 1 , NULL , 0 , V_167 , args ) ;
}
T_10 int F_26 ( int V_26 , int V_27 ,
const char * V_31 , T_6 V_166 ,
const char * V_167 , ... )
{
T_11 args ;
int V_184 ;
va_start ( args , V_167 ) ;
V_184 = F_94 ( V_26 , V_27 , V_31 , V_166 , V_167 , args ) ;
va_end ( args ) ;
return V_184 ;
}
T_10 T_12 int F_108 ( const char * V_167 , ... )
{
T_11 args ;
int V_184 ;
#ifdef F_109
if ( F_53 ( V_185 ) ) {
va_start ( args , V_167 ) ;
V_184 = F_110 ( V_167 , args ) ;
va_end ( args ) ;
return V_184 ;
}
#endif
va_start ( args , V_167 ) ;
V_184 = F_94 ( 0 , - 1 , NULL , 0 , V_167 , args ) ;
va_end ( args ) ;
return V_184 ;
}
static struct V_4 * F_6 ( T_1 V_7 ) { return NULL ; }
static T_1 F_7 ( T_1 V_7 ) { return 0 ; }
static void F_74 ( int V_27 , const char * V_32 , T_6 V_9 ) {}
static T_6 F_69 ( const struct V_4 * V_5 , enum V_28 V_78 ,
bool V_122 , char * V_49 , T_6 V_20 ) { return 0 ; }
static T_6 F_93 ( char * V_32 , T_6 V_20 ) { return 0 ; }
void F_111 ( const char * V_167 , T_11 V_186 )
{
if ( V_187 ) {
char V_49 [ 512 ] ;
int V_129 = F_100 ( V_49 , sizeof( V_49 ) , V_167 , V_186 ) ;
V_187 -> V_154 ( V_187 , V_49 , V_129 ) ;
}
}
T_10 T_12 void F_112 ( const char * V_167 , ... )
{
T_11 V_186 ;
va_start ( V_186 , V_167 ) ;
F_111 ( V_167 , V_186 ) ;
va_end ( V_186 ) ;
}
static int F_113 ( char * V_188 , int V_7 , char * V_189 ,
char * V_190 )
{
struct V_191 * V_80 ;
int V_50 ;
for ( V_50 = 0 , V_80 = V_191 ;
V_50 < V_192 && V_80 -> V_188 [ 0 ] ;
V_50 ++ , V_80 ++ ) {
if ( strcmp ( V_80 -> V_188 , V_188 ) == 0 && V_80 -> V_193 == V_7 ) {
if ( ! V_190 )
V_194 = V_50 ;
return 0 ;
}
}
if ( V_50 == V_192 )
return - V_195 ;
if ( ! V_190 )
V_194 = V_50 ;
F_114 ( V_80 -> V_188 , V_188 , sizeof( V_80 -> V_188 ) ) ;
V_80 -> V_189 = V_189 ;
F_115 ( V_80 , V_190 ) ;
V_80 -> V_193 = V_7 ;
return 0 ;
}
static int T_9 F_116 ( char * V_100 )
{
char V_49 [ sizeof( V_191 [ 0 ] . V_188 ) + 4 ] ;
char * V_196 , * V_189 , * V_190 = NULL ;
int V_7 ;
if ( F_117 ( & V_100 , & V_190 ) )
return 1 ;
if ( V_100 [ 0 ] >= '0' && V_100 [ 0 ] <= '9' ) {
strcpy ( V_49 , L_18 ) ;
strncpy ( V_49 + 4 , V_100 , sizeof( V_49 ) - 5 ) ;
} else {
strncpy ( V_49 , V_100 , sizeof( V_49 ) - 1 ) ;
}
V_49 [ sizeof( V_49 ) - 1 ] = 0 ;
if ( ( V_189 = strchr ( V_100 , ',' ) ) != NULL )
* ( V_189 ++ ) = 0 ;
#ifdef F_118
if ( ! strcmp ( V_100 , L_19 ) )
strcpy ( V_49 , L_20 ) ;
if ( ! strcmp ( V_100 , L_21 ) )
strcpy ( V_49 , L_22 ) ;
#endif
for ( V_196 = V_49 ; * V_196 ; V_196 ++ )
if ( ( * V_196 >= '0' && * V_196 <= '9' ) || * V_196 == ',' )
break;
V_7 = F_25 ( V_196 , NULL , 10 ) ;
* V_196 = 0 ;
F_113 ( V_49 , V_7 , V_189 , V_190 ) ;
V_197 = 1 ;
return 1 ;
}
int F_119 ( char * V_188 , int V_7 , char * V_189 )
{
return F_113 ( V_188 , V_7 , V_189 , NULL ) ;
}
int F_120 ( char * V_188 , int V_7 , char * V_198 , int V_199 , char * V_189 )
{
struct V_191 * V_80 ;
int V_50 ;
for ( V_50 = 0 , V_80 = V_191 ;
V_50 < V_192 && V_80 -> V_188 [ 0 ] ;
V_50 ++ , V_80 ++ )
if ( strcmp ( V_80 -> V_188 , V_188 ) == 0 && V_80 -> V_193 == V_7 ) {
F_114 ( V_80 -> V_188 , V_198 , sizeof( V_80 -> V_188 ) ) ;
V_80 -> V_188 [ sizeof( V_80 -> V_188 ) - 1 ] = 0 ;
V_80 -> V_189 = V_189 ;
V_80 -> V_193 = V_199 ;
return V_50 ;
}
return - 1 ;
}
static int T_9 F_121 ( char * V_100 )
{
V_200 = 0 ;
return 1 ;
}
void F_122 ( void )
{
if ( ! V_200 )
return;
F_108 ( L_23 ) ;
F_123 () ;
V_201 = 1 ;
F_88 () ;
}
void F_124 ( void )
{
if ( ! V_200 )
return;
F_125 () ;
V_201 = 0 ;
F_104 () ;
}
static int F_126 ( struct V_202 * V_203 ,
unsigned long V_204 , void * V_205 )
{
switch ( V_204 ) {
case V_206 :
case V_207 :
case V_208 :
case V_209 :
F_123 () ;
F_104 () ;
}
return V_210 ;
}
void F_123 ( void )
{
F_127 () ;
F_125 () ;
if ( V_201 )
return;
V_158 = 1 ;
V_211 = 1 ;
}
int F_87 ( void )
{
if ( F_128 () )
return 0 ;
if ( V_201 ) {
F_88 () ;
return 0 ;
}
V_158 = 1 ;
V_211 = 0 ;
return 1 ;
}
int F_129 ( void )
{
return V_158 ;
}
static void F_130 ( char * V_32 , T_6 V_20 )
{
unsigned long V_29 ;
T_6 V_9 ;
F_55 ( & V_70 , V_29 ) ;
if ( ! V_67 . V_9 )
goto V_59;
if ( V_212 < V_16 && ! V_67 . V_162 )
goto V_59;
V_9 = F_93 ( V_32 , V_20 ) ;
F_103 ( & V_70 ) ;
F_131 () ;
F_74 ( V_67 . V_27 , V_32 , V_9 ) ;
F_132 () ;
F_106 ( V_29 ) ;
return;
V_59:
F_56 ( & V_70 , V_29 ) ;
}
void F_104 ( void )
{
static char V_32 [ V_53 + V_128 ] ;
static T_3 V_213 ;
unsigned long V_29 ;
bool V_214 = false ;
bool V_215 ;
if ( V_201 ) {
F_88 () ;
return;
}
V_211 = 0 ;
F_130 ( V_32 , sizeof( V_32 ) ) ;
V_216:
for (; ; ) {
struct V_4 * V_5 ;
T_6 V_9 ;
int V_27 ;
F_55 ( & V_70 , V_29 ) ;
if ( V_213 != V_16 ) {
V_214 = true ;
V_213 = V_16 ;
}
if ( V_212 < V_15 ) {
V_9 = sprintf ( V_32 , L_24 ,
( unsigned ) ( V_15 - V_212 ) ) ;
V_212 = V_15 ;
V_217 = V_13 ;
V_165 = 0 ;
} else {
V_9 = 0 ;
}
V_130:
if ( V_212 == V_16 )
break;
V_5 = F_6 ( V_217 ) ;
if ( V_5 -> V_29 & V_163 ) {
V_217 = F_7 ( V_217 ) ;
V_212 ++ ;
V_5 -> V_29 &= ~ V_163 ;
V_165 = V_5 -> V_29 ;
goto V_130;
}
V_27 = V_5 -> V_27 ;
V_9 += F_69 ( V_5 , V_165 , false ,
V_32 + V_9 , sizeof( V_32 ) - V_9 ) ;
V_217 = F_7 ( V_217 ) ;
V_212 ++ ;
V_165 = V_5 -> V_29 ;
F_103 ( & V_70 ) ;
F_131 () ;
F_74 ( V_27 , V_32 , V_9 ) ;
F_132 () ;
F_106 ( V_29 ) ;
}
V_158 = 0 ;
if ( F_53 ( V_152 ) )
V_152 = NULL ;
F_103 ( & V_70 ) ;
F_88 () ;
F_98 ( & V_70 ) ;
V_215 = V_212 != V_16 ;
F_56 ( & V_70 , V_29 ) ;
if ( V_215 && F_87 () )
goto V_216;
if ( V_214 )
F_133 () ;
}
void T_13 F_134 ( void )
{
if ( V_211 )
F_135 () ;
}
void F_136 ( void )
{
struct V_149 * V_80 ;
if ( V_177 ) {
if ( F_128 () != 0 )
return;
} else
F_123 () ;
V_158 = 1 ;
V_211 = 0 ;
F_76 (c)
if ( ( V_80 -> V_29 & V_153 ) && V_80 -> V_218 )
V_80 -> V_218 () ;
F_104 () ;
}
struct V_219 * F_137 ( int * V_193 )
{
struct V_149 * V_80 ;
struct V_219 * V_220 = NULL ;
F_123 () ;
F_76 (c) {
if ( ! V_80 -> V_221 )
continue;
V_220 = V_80 -> V_221 ( V_80 , V_193 ) ;
if ( V_220 )
break;
}
F_104 () ;
return V_220 ;
}
void F_138 ( struct V_149 * V_149 )
{
F_123 () ;
V_149 -> V_29 &= ~ V_153 ;
F_104 () ;
}
void F_139 ( struct V_149 * V_149 )
{
F_123 () ;
V_149 -> V_29 |= V_153 ;
F_104 () ;
}
static int T_9 F_140 ( char * V_100 )
{
V_222 = 1 ;
F_57 ( L_25 ) ;
return 0 ;
}
void F_141 ( struct V_149 * V_223 )
{
int V_50 ;
unsigned long V_29 ;
struct V_149 * V_224 = NULL ;
struct V_191 * V_80 ;
if ( V_151 )
F_76 (bcon)
if ( F_142 ( V_224 == V_223 ,
L_26 ,
V_224 -> V_188 , V_224 -> V_193 ) )
return;
if ( V_151 && V_223 -> V_29 & V_225 ) {
F_76 (bcon) {
if ( ! ( V_224 -> V_29 & V_225 ) ) {
F_57 ( L_27 ,
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
if ( F_143 ( V_223 , V_80 ) )
return;
if ( V_223 -> V_228 &&
V_223 -> V_228 ( V_223 , V_191 [ V_50 ] . V_189 ) != 0 )
break;
V_223 -> V_29 |= V_153 ;
V_223 -> V_193 = V_80 -> V_193 ;
if ( V_50 == V_194 ) {
V_223 -> V_29 |= V_229 ;
V_226 = V_194 ;
}
break;
}
if ( ! ( V_223 -> V_29 & V_153 ) )
return;
if ( V_224 && ( ( V_223 -> V_29 & ( V_229 | V_225 ) ) == V_229 ) )
V_223 -> V_29 &= ~ V_230 ;
F_123 () ;
if ( ( V_223 -> V_29 & V_229 ) || V_151 == NULL ) {
V_223 -> V_127 = V_151 ;
V_151 = V_223 ;
if ( V_223 -> V_127 )
V_223 -> V_127 -> V_29 &= ~ V_229 ;
} else {
V_223 -> V_127 = V_151 -> V_127 ;
V_151 -> V_127 = V_223 ;
}
if ( V_223 -> V_29 & V_230 ) {
F_55 ( & V_70 , V_29 ) ;
V_212 = V_131 ;
V_217 = V_132 ;
V_165 = V_133 ;
F_56 ( & V_70 , V_29 ) ;
V_152 = V_223 ;
}
F_104 () ;
F_144 () ;
F_57 ( L_28 ,
( V_223 -> V_29 & V_225 ) ? L_29 : L_30 ,
V_223 -> V_188 , V_223 -> V_193 ) ;
if ( V_224 &&
( ( V_223 -> V_29 & ( V_229 | V_225 ) ) == V_229 ) &&
! V_222 ) {
F_76 (bcon)
if ( V_224 -> V_29 & V_225 )
F_145 ( V_224 ) ;
}
}
int F_145 ( struct V_149 * V_149 )
{
struct V_149 * V_231 , * V_232 ;
int V_233 ;
F_57 ( L_31 ,
( V_149 -> V_29 & V_225 ) ? L_29 : L_30 ,
V_149 -> V_188 , V_149 -> V_193 ) ;
V_233 = F_146 ( V_149 ) ;
if ( V_233 )
return V_233 ;
V_233 = 1 ;
F_123 () ;
if ( V_151 == V_149 ) {
V_151 = V_149 -> V_127 ;
V_233 = 0 ;
} else if ( V_151 ) {
for ( V_231 = V_151 -> V_127 , V_232 = V_151 ;
V_231 ; V_232 = V_231 , V_231 = V_232 -> V_127 ) {
if ( V_231 == V_149 ) {
V_232 -> V_127 = V_231 -> V_127 ;
V_233 = 0 ;
break;
}
}
}
if ( V_151 != NULL && V_149 -> V_29 & V_229 )
V_151 -> V_29 |= V_229 ;
V_149 -> V_29 &= ~ V_153 ;
F_104 () ;
F_144 () ;
return V_233 ;
}
static int T_9 F_147 ( void )
{
struct V_149 * V_150 ;
F_76 (con) {
if ( ! V_222 && V_150 -> V_29 & V_225 ) {
F_145 ( V_150 ) ;
}
}
F_148 ( F_126 , 0 ) ;
return 0 ;
}
static void F_149 ( struct V_234 * V_234 )
{
int V_235 = F_150 ( V_236 , 0 ) ;
if ( V_235 & V_237 ) {
if ( F_87 () )
F_104 () ;
}
if ( V_235 & V_238 )
F_151 ( & V_75 ) ;
}
void F_133 ( void )
{
F_152 () ;
if ( F_153 ( & V_75 ) ) {
F_154 ( V_236 , V_238 ) ;
F_155 ( & F_156 ( V_239 ) ) ;
}
F_157 () ;
}
int F_158 ( const char * V_167 , ... )
{
T_11 args ;
int V_184 ;
F_152 () ;
va_start ( args , V_167 ) ;
V_184 = F_94 ( 0 , V_176 , NULL , 0 , V_167 , args ) ;
va_end ( args ) ;
F_159 ( V_236 , V_237 ) ;
F_155 ( & F_156 ( V_239 ) ) ;
F_157 () ;
return V_184 ;
}
int F_160 ( const char * V_240 )
{
return F_161 ( & V_241 , V_240 ) ;
}
bool F_162 ( unsigned long * V_242 ,
unsigned int V_243 )
{
if ( * V_242 == 0
|| ! F_163 ( V_118 , * V_242 ,
* V_242
+ F_63 ( V_243 ) ) ) {
* V_242 = V_118 ;
return true ;
}
return false ;
}
int F_164 ( struct V_244 * V_245 )
{
unsigned long V_29 ;
int V_96 = - V_246 ;
if ( ! V_245 -> V_247 )
return - V_54 ;
F_165 ( & V_248 , V_29 ) ;
if ( ! V_245 -> V_249 ) {
V_245 -> V_249 = 1 ;
F_166 ( & V_245 -> V_250 , & V_251 ) ;
V_96 = 0 ;
}
F_167 ( & V_248 , V_29 ) ;
return V_96 ;
}
int F_168 ( struct V_244 * V_245 )
{
unsigned long V_29 ;
int V_96 = - V_54 ;
F_165 ( & V_248 , V_29 ) ;
if ( V_245 -> V_249 ) {
V_245 -> V_249 = 0 ;
F_169 ( & V_245 -> V_250 ) ;
V_96 = 0 ;
}
F_167 ( & V_248 , V_29 ) ;
F_170 () ;
return V_96 ;
}
void F_171 ( enum V_252 V_253 )
{
struct V_244 * V_245 ;
unsigned long V_29 ;
if ( ( V_253 > V_254 ) && ! V_255 )
return;
F_172 () ;
F_173 (dumper, &dump_list, list) {
if ( V_245 -> V_256 && V_253 > V_245 -> V_256 )
continue;
V_245 -> V_257 = true ;
F_55 ( & V_70 , V_29 ) ;
V_245 -> V_258 = V_87 ;
V_245 -> V_259 = V_86 ;
V_245 -> V_136 = V_16 ;
V_245 -> V_260 = V_12 ;
F_56 ( & V_70 , V_29 ) ;
V_245 -> V_247 ( V_245 , V_253 ) ;
V_245 -> V_257 = false ;
}
F_174 () ;
}
bool F_175 ( struct V_244 * V_245 , bool V_122 ,
char * line , T_6 V_20 , T_6 * V_9 )
{
struct V_4 * V_5 ;
T_6 V_261 = 0 ;
bool V_52 = false ;
if ( ! V_245 -> V_257 )
goto V_59;
if ( V_245 -> V_258 < V_15 ) {
V_245 -> V_258 = V_15 ;
V_245 -> V_259 = V_13 ;
}
if ( V_245 -> V_258 >= V_16 )
goto V_59;
V_5 = F_6 ( V_245 -> V_259 ) ;
V_261 = F_69 ( V_5 , 0 , V_122 , line , V_20 ) ;
V_245 -> V_259 = F_7 ( V_245 -> V_259 ) ;
V_245 -> V_258 ++ ;
V_52 = true ;
V_59:
if ( V_9 )
* V_9 = V_261 ;
return V_52 ;
}
bool F_176 ( struct V_244 * V_245 , bool V_122 ,
char * line , T_6 V_20 , T_6 * V_9 )
{
unsigned long V_29 ;
bool V_52 ;
F_55 ( & V_70 , V_29 ) ;
V_52 = F_175 ( V_245 , V_122 , line , V_20 , V_9 ) ;
F_56 ( & V_70 , V_29 ) ;
return V_52 ;
}
bool F_177 ( struct V_244 * V_245 , bool V_122 ,
char * V_49 , T_6 V_20 , T_6 * V_9 )
{
unsigned long V_29 ;
T_3 V_71 ;
T_1 V_7 ;
T_3 V_136 ;
T_1 V_260 ;
enum V_28 V_78 ;
T_6 V_261 = 0 ;
bool V_52 = false ;
if ( ! V_245 -> V_257 )
goto V_59;
F_55 ( & V_70 , V_29 ) ;
if ( V_245 -> V_258 < V_15 ) {
V_245 -> V_258 = V_15 ;
V_245 -> V_259 = V_13 ;
}
if ( V_245 -> V_258 >= V_245 -> V_136 ) {
F_56 ( & V_70 , V_29 ) ;
goto V_59;
}
V_71 = V_245 -> V_258 ;
V_7 = V_245 -> V_259 ;
V_78 = 0 ;
while ( V_71 < V_245 -> V_136 ) {
struct V_4 * V_5 = F_6 ( V_7 ) ;
V_261 += F_69 ( V_5 , V_78 , true , NULL , 0 ) ;
V_7 = F_7 ( V_7 ) ;
V_71 ++ ;
V_78 = V_5 -> V_29 ;
}
V_71 = V_245 -> V_258 ;
V_7 = V_245 -> V_259 ;
V_78 = 0 ;
while ( V_261 > V_20 && V_71 < V_245 -> V_136 ) {
struct V_4 * V_5 = F_6 ( V_7 ) ;
V_261 -= F_69 ( V_5 , V_78 , true , NULL , 0 ) ;
V_7 = F_7 ( V_7 ) ;
V_71 ++ ;
V_78 = V_5 -> V_29 ;
}
V_136 = V_71 ;
V_260 = V_7 ;
V_261 = 0 ;
while ( V_71 < V_245 -> V_136 ) {
struct V_4 * V_5 = F_6 ( V_7 ) ;
V_261 += F_69 ( V_5 , V_78 , V_122 , V_49 + V_261 , V_20 - V_261 ) ;
V_7 = F_7 ( V_7 ) ;
V_71 ++ ;
V_78 = V_5 -> V_29 ;
}
V_245 -> V_136 = V_136 ;
V_245 -> V_260 = V_260 ;
V_52 = true ;
F_56 ( & V_70 , V_29 ) ;
V_59:
if ( V_9 )
* V_9 = V_261 ;
return V_52 ;
}
void F_178 ( struct V_244 * V_245 )
{
V_245 -> V_258 = V_87 ;
V_245 -> V_259 = V_86 ;
V_245 -> V_136 = V_16 ;
V_245 -> V_260 = V_12 ;
}
void F_179 ( struct V_244 * V_245 )
{
unsigned long V_29 ;
F_55 ( & V_70 , V_29 ) ;
F_178 ( V_245 ) ;
F_56 ( & V_70 , V_29 ) ;
}
void T_9 F_180 ( const char * V_167 , ... )
{
T_11 args ;
va_start ( args , V_167 ) ;
vsnprintf ( V_262 , sizeof( V_262 ) ,
V_167 , args ) ;
va_end ( args ) ;
}
void F_181 ( const char * V_263 )
{
F_108 ( L_32 ,
V_263 , F_182 () , V_40 -> V_264 , V_40 -> V_41 ,
F_183 () , F_184 () -> V_265 ,
( int ) strcspn ( F_184 () -> V_266 , L_33 ) ,
F_184 () -> V_266 ) ;
if ( V_262 [ 0 ] != '\0' )
F_108 ( L_34 ,
V_263 , V_262 ) ;
F_185 ( V_263 , V_40 ) ;
}
void F_186 ( const char * V_263 )
{
F_181 ( V_263 ) ;
F_108 ( L_35 ,
V_263 , V_40 , F_187 () ,
F_188 ( V_40 ) ) ;
}
