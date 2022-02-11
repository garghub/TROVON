static char * F_1 ( const struct log * V_1 )
{
return ( char * ) V_1 + sizeof( struct log ) ;
}
static char * F_2 ( const struct log * V_1 )
{
return ( char * ) V_1 + sizeof( struct log ) + V_1 -> V_2 ;
}
static struct log * F_3 ( T_1 V_3 )
{
struct log * V_1 = (struct log * ) ( V_4 + V_3 ) ;
if ( ! V_1 -> V_5 )
return (struct log * ) V_4 ;
return V_1 ;
}
static T_1 F_4 ( T_1 V_3 )
{
struct log * V_1 = (struct log * ) ( V_4 + V_3 ) ;
if ( ! V_1 -> V_5 ) {
V_1 = (struct log * ) V_4 ;
return V_1 -> V_5 ;
}
return V_3 + V_1 -> V_5 ;
}
static void F_5 ( int V_6 , int V_7 ,
enum V_8 V_9 , T_2 V_10 ,
const char * V_11 , T_3 V_12 ,
const char * V_13 , T_3 V_2 )
{
struct log * V_1 ;
T_1 V_14 , V_15 ;
V_14 = sizeof( struct log ) + V_2 + V_12 ;
V_15 = ( - V_14 ) & ( V_16 - 1 ) ;
V_14 += V_15 ;
while ( V_17 < V_18 ) {
T_1 free ;
if ( V_19 > V_20 )
free = F_6 ( V_21 - V_19 , V_20 ) ;
else
free = V_20 - V_19 ;
if ( free > V_14 + sizeof( struct log ) )
break;
V_20 = F_4 ( V_20 ) ;
V_17 ++ ;
}
if ( V_19 + V_14 + sizeof( struct log ) >= V_21 ) {
memset ( V_4 + V_19 , 0 , sizeof( struct log ) ) ;
V_19 = 0 ;
}
V_1 = (struct log * ) ( V_4 + V_19 ) ;
memcpy ( F_1 ( V_1 ) , V_13 , V_2 ) ;
V_1 -> V_2 = V_2 ;
memcpy ( F_2 ( V_1 ) , V_11 , V_12 ) ;
V_1 -> V_12 = V_12 ;
V_1 -> V_6 = V_6 ;
V_1 -> V_7 = V_7 & 7 ;
V_1 -> V_9 = V_9 & 0x1f ;
if ( V_10 > 0 )
V_1 -> V_10 = V_10 ;
else
V_1 -> V_10 = F_7 () ;
memset ( F_2 ( V_1 ) + V_12 , 0 , V_15 ) ;
V_1 -> V_5 = sizeof( struct log ) + V_2 + V_12 + V_15 ;
V_19 += V_1 -> V_5 ;
V_18 ++ ;
}
static T_4 F_8 ( struct V_22 * V_23 , const struct V_24 * V_25 ,
unsigned long V_26 , T_5 V_27 )
{
char * V_28 , * line ;
int V_29 ;
int V_7 = V_30 ;
int V_6 = 1 ;
T_6 V_5 = F_9 ( V_25 , V_26 ) ;
T_4 V_31 = V_5 ;
if ( V_5 > V_32 )
return - V_33 ;
V_28 = F_10 ( V_5 + 1 , V_34 ) ;
if ( V_28 == NULL )
return - V_35 ;
line = V_28 ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
if ( F_11 ( line , V_25 [ V_29 ] . V_36 , V_25 [ V_29 ] . V_37 ) )
goto V_38;
line += V_25 [ V_29 ] . V_37 ;
}
line = V_28 ;
if ( line [ 0 ] == '<' ) {
char * V_39 = NULL ;
V_29 = F_12 ( line + 1 , & V_39 , 10 ) ;
if ( V_39 && V_39 [ 0 ] == '>' ) {
V_7 = V_29 & 7 ;
if ( V_29 >> 3 )
V_6 = V_29 >> 3 ;
V_39 ++ ;
V_5 -= V_39 - line ;
line = V_39 ;
}
}
line [ V_5 ] = '\0' ;
F_13 ( V_6 , V_7 , NULL , 0 , L_1 , line ) ;
V_38:
F_14 ( V_28 ) ;
return V_31 ;
}
static T_4 F_15 ( struct V_40 * V_40 , char T_7 * V_28 ,
T_6 V_26 , T_5 * V_41 )
{
struct V_42 * V_43 = V_40 -> V_44 ;
struct log * V_1 ;
T_2 V_45 ;
T_6 V_29 ;
T_6 V_5 ;
T_4 V_31 ;
if ( ! V_43 )
return - V_46 ;
V_31 = F_16 ( & V_43 -> V_47 ) ;
if ( V_31 )
return V_31 ;
F_17 ( & V_48 ) ;
while ( V_43 -> V_49 == V_18 ) {
if ( V_40 -> V_50 & V_51 ) {
V_31 = - V_52 ;
F_18 ( & V_48 ) ;
goto V_38;
}
F_18 ( & V_48 ) ;
V_31 = F_19 ( V_53 ,
V_43 -> V_49 != V_18 ) ;
if ( V_31 )
goto V_38;
F_17 ( & V_48 ) ;
}
if ( V_43 -> V_49 < V_17 ) {
V_43 -> V_3 = V_20 ;
V_43 -> V_49 = V_17 ;
V_31 = - V_54 ;
F_18 ( & V_48 ) ;
goto V_38;
}
V_1 = F_3 ( V_43 -> V_3 ) ;
V_45 = V_1 -> V_10 ;
F_20 ( V_45 , 1000 ) ;
V_5 = sprintf ( V_43 -> V_28 , L_2 ,
( V_1 -> V_6 << 3 ) | V_1 -> V_7 , V_43 -> V_49 , V_45 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_2 ; V_29 ++ ) {
unsigned char V_55 = F_1 ( V_1 ) [ V_29 ] ;
if ( V_55 < ' ' || V_55 >= 127 || V_55 == '\\' )
V_5 += sprintf ( V_43 -> V_28 + V_5 , L_3 , V_55 ) ;
else
V_43 -> V_28 [ V_5 ++ ] = V_55 ;
}
V_43 -> V_28 [ V_5 ++ ] = '\n' ;
if ( V_1 -> V_12 ) {
bool line = true ;
for ( V_29 = 0 ; V_29 < V_1 -> V_12 ; V_29 ++ ) {
unsigned char V_55 = F_2 ( V_1 ) [ V_29 ] ;
if ( line ) {
V_43 -> V_28 [ V_5 ++ ] = ' ' ;
line = false ;
}
if ( V_55 == '\0' ) {
V_43 -> V_28 [ V_5 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_55 < ' ' || V_55 >= 127 || V_55 == '\\' ) {
V_5 += sprintf ( V_43 -> V_28 + V_5 , L_3 , V_55 ) ;
continue;
}
V_43 -> V_28 [ V_5 ++ ] = V_55 ;
}
V_43 -> V_28 [ V_5 ++ ] = '\n' ;
}
V_43 -> V_3 = F_4 ( V_43 -> V_3 ) ;
V_43 -> V_49 ++ ;
F_18 ( & V_48 ) ;
if ( V_5 > V_26 ) {
V_31 = - V_33 ;
goto V_38;
}
if ( F_21 ( V_28 , V_43 -> V_28 , V_5 ) ) {
V_31 = - V_56 ;
goto V_38;
}
V_31 = V_5 ;
V_38:
F_22 ( & V_43 -> V_47 ) ;
return V_31 ;
}
static T_5 F_23 ( struct V_40 * V_40 , T_5 V_57 , int V_58 )
{
struct V_42 * V_43 = V_40 -> V_44 ;
T_5 V_31 = 0 ;
if ( ! V_43 )
return - V_46 ;
if ( V_57 )
return - V_59 ;
F_17 ( & V_48 ) ;
switch ( V_58 ) {
case V_60 :
V_43 -> V_3 = V_20 ;
V_43 -> V_49 = V_17 ;
break;
case V_61 :
V_43 -> V_3 = V_62 ;
V_43 -> V_49 = V_63 ;
break;
case V_64 :
V_43 -> V_3 = V_19 ;
V_43 -> V_49 = V_18 ;
break;
default:
V_31 = - V_33 ;
}
F_18 ( & V_48 ) ;
return V_31 ;
}
static unsigned int F_24 ( struct V_40 * V_40 , T_8 * V_65 )
{
struct V_42 * V_43 = V_40 -> V_44 ;
int V_31 = 0 ;
if ( ! V_43 )
return V_66 | V_67 ;
F_25 ( V_40 , & V_53 , V_65 ) ;
F_17 ( & V_48 ) ;
if ( V_43 -> V_49 < V_18 ) {
if ( V_43 -> V_49 < V_17 )
V_31 = V_68 | V_69 | V_66 | V_70 ;
V_31 = V_68 | V_69 ;
}
F_18 ( & V_48 ) ;
return V_31 ;
}
static int F_26 ( struct V_71 * V_71 , struct V_40 * V_40 )
{
struct V_42 * V_43 ;
int V_72 ;
if ( ( V_40 -> V_50 & V_73 ) == V_74 )
return 0 ;
V_72 = F_27 ( V_75 ) ;
if ( V_72 )
return V_72 ;
V_43 = F_10 ( sizeof( struct V_42 ) , V_34 ) ;
if ( ! V_43 )
return - V_35 ;
F_28 ( & V_43 -> V_47 ) ;
F_17 ( & V_48 ) ;
V_43 -> V_3 = V_20 ;
V_43 -> V_49 = V_17 ;
F_18 ( & V_48 ) ;
V_40 -> V_44 = V_43 ;
return 0 ;
}
static int F_29 ( struct V_71 * V_71 , struct V_40 * V_40 )
{
struct V_42 * V_43 = V_40 -> V_44 ;
if ( ! V_43 )
return 0 ;
F_30 ( & V_43 -> V_47 ) ;
F_14 ( V_43 ) ;
return 0 ;
}
void F_31 ( void )
{
F_32 ( V_4 ) ;
F_32 ( V_21 ) ;
F_32 ( V_20 ) ;
F_32 ( V_19 ) ;
}
static int T_9 F_33 ( char * V_76 )
{
unsigned V_14 = F_34 ( V_76 , & V_76 ) ;
if ( V_14 )
V_14 = F_35 ( V_14 ) ;
if ( V_14 > V_21 )
V_77 = V_14 ;
return 0 ;
}
void T_9 F_36 ( int V_78 )
{
unsigned long V_9 ;
char * V_79 ;
int free ;
if ( ! V_77 )
return;
if ( V_78 ) {
unsigned long V_80 ;
V_80 = F_37 ( V_77 , V_81 ) ;
if ( ! V_80 )
return;
V_79 = F_38 ( V_80 ) ;
} else {
V_79 = F_39 ( V_77 ) ;
}
if ( F_40 ( ! V_79 ) ) {
F_41 ( L_4 ,
V_77 ) ;
return;
}
F_42 ( & V_48 , V_9 ) ;
V_21 = V_77 ;
V_4 = V_79 ;
V_77 = 0 ;
free = V_82 - V_19 ;
memcpy ( V_4 , V_83 , V_82 ) ;
F_43 ( & V_48 , V_9 ) ;
F_44 ( L_5 , V_21 ) ;
F_44 ( L_6 ,
free , ( free * 100 ) / V_82 ) ;
}
static int T_9 F_45 ( char * V_76 )
{
unsigned long V_84 ;
V_84 = V_85 ? V_85 : 1000000 ;
V_86 = ( unsigned long long ) V_84 / 1000 * V_87 ;
F_46 ( & V_76 , & V_88 ) ;
if ( V_88 > 10 * 1000 )
V_88 = 0 ;
F_47 ( L_7
L_8 ,
V_88 , V_85 , V_84 , V_87 , V_86 ) ;
return 1 ;
}
static void F_48 ( void )
{
unsigned long long V_89 ;
unsigned long V_90 ;
if ( V_88 == 0 || V_91 != V_92 )
return;
V_89 = ( unsigned long long ) V_86 * V_88 ;
V_90 = V_93 + F_49 ( V_88 ) ;
while ( V_89 ) {
V_89 -- ;
F_50 () ;
if ( F_51 ( V_93 , V_90 ) )
break;
F_52 () ;
}
}
static inline void F_48 ( void )
{
}
static int F_53 ( int type )
{
if ( V_94 )
return 1 ;
return type != V_75 && type != V_95 ;
}
static int F_54 ( int type , bool V_96 )
{
if ( V_96 && type != V_97 )
return 0 ;
if ( F_53 ( type ) ) {
if ( F_55 ( V_98 ) )
return 0 ;
if ( F_55 ( V_99 ) ) {
F_56 ( V_100 L_9
L_10
L_11 ,
V_101 -> V_102 , F_57 ( V_101 ) ) ;
return 0 ;
}
return - V_103 ;
}
return 0 ;
}
static T_6 F_58 ( T_2 V_104 , char * V_28 )
{
unsigned long V_105 ;
if ( ! V_106 )
return 0 ;
if ( ! V_28 )
return 15 ;
V_105 = F_20 ( V_104 , 1000000000 ) ;
return sprintf ( V_28 , L_12 ,
( unsigned long ) V_104 , V_105 / 1000 ) ;
}
static T_6 F_59 ( const struct log * V_1 , bool V_107 , char * V_28 )
{
T_6 V_5 = 0 ;
unsigned int V_108 = ( V_1 -> V_6 << 3 ) | V_1 -> V_7 ;
if ( V_107 ) {
if ( V_28 ) {
V_5 += sprintf ( V_28 , L_13 , V_108 ) ;
} else {
V_5 += 3 ;
if ( V_108 > 999 )
V_5 += 3 ;
else if ( V_108 > 99 )
V_5 += 2 ;
else if ( V_108 > 9 )
V_5 ++ ;
}
}
V_5 += F_58 ( V_1 -> V_10 , V_28 ? V_28 + V_5 : NULL ) ;
return V_5 ;
}
static T_6 F_60 ( const struct log * V_1 , enum V_8 V_109 ,
bool V_107 , char * V_28 , T_6 V_14 )
{
const char * V_13 = F_1 ( V_1 ) ;
T_6 V_110 = V_1 -> V_2 ;
bool V_108 = true ;
bool V_111 = true ;
T_6 V_5 = 0 ;
if ( ( V_109 & V_112 ) && ! ( V_1 -> V_9 & V_113 ) )
V_108 = false ;
if ( V_1 -> V_9 & V_112 ) {
if ( ( V_109 & V_112 ) && ! ( V_109 & V_114 ) )
V_108 = false ;
if ( ! ( V_1 -> V_9 & V_114 ) )
V_111 = false ;
}
do {
const char * V_115 = memchr ( V_13 , '\n' , V_110 ) ;
T_6 V_2 ;
if ( V_115 ) {
V_2 = V_115 - V_13 ;
V_115 ++ ;
V_110 -= V_115 - V_13 ;
} else {
V_2 = V_110 ;
}
if ( V_28 ) {
if ( F_59 ( V_1 , V_107 , NULL ) +
V_2 + 1 >= V_14 - V_5 )
break;
if ( V_108 )
V_5 += F_59 ( V_1 , V_107 , V_28 + V_5 ) ;
memcpy ( V_28 + V_5 , V_13 , V_2 ) ;
V_5 += V_2 ;
if ( V_115 || V_111 )
V_28 [ V_5 ++ ] = '\n' ;
} else {
if ( V_108 )
V_5 += F_59 ( V_1 , V_107 , NULL ) ;
V_5 += V_2 ;
if ( V_115 || V_111 )
V_5 ++ ;
}
V_108 = true ;
V_13 = V_115 ;
} while ( V_13 );
return V_5 ;
}
static int F_61 ( char T_7 * V_28 , int V_14 )
{
char * V_13 ;
struct log * V_1 ;
int V_5 = 0 ;
V_13 = F_10 ( V_32 , V_34 ) ;
if ( ! V_13 )
return - V_35 ;
while ( V_14 > 0 ) {
T_6 V_116 ;
T_6 V_117 ;
F_17 ( & V_48 ) ;
if ( V_118 < V_17 ) {
V_118 = V_17 ;
V_119 = V_20 ;
V_120 = 0 ;
V_121 = 0 ;
}
if ( V_118 == V_18 ) {
F_18 ( & V_48 ) ;
break;
}
V_117 = V_121 ;
V_1 = F_3 ( V_119 ) ;
V_116 = F_60 ( V_1 , V_120 , true , V_13 , V_32 ) ;
if ( V_116 - V_121 <= V_14 ) {
V_119 = F_4 ( V_119 ) ;
V_118 ++ ;
V_120 = V_1 -> V_9 ;
V_116 -= V_121 ;
V_121 = 0 ;
} else if ( ! V_5 ) {
V_116 = V_14 ;
V_121 += V_116 ;
} else
V_116 = 0 ;
F_18 ( & V_48 ) ;
if ( ! V_116 )
break;
if ( F_21 ( V_28 , V_13 + V_117 , V_116 ) ) {
if ( ! V_5 )
V_5 = - V_56 ;
break;
}
V_5 += V_116 ;
V_14 -= V_116 ;
V_28 += V_116 ;
}
F_14 ( V_13 ) ;
return V_5 ;
}
static int F_62 ( char T_7 * V_28 , int V_14 , bool V_122 )
{
char * V_13 ;
int V_5 = 0 ;
V_13 = F_10 ( V_32 , V_34 ) ;
if ( ! V_13 )
return - V_35 ;
F_17 ( & V_48 ) ;
if ( V_28 ) {
T_2 V_123 ;
T_2 V_49 ;
T_1 V_3 ;
enum V_8 V_109 ;
if ( V_63 < V_17 ) {
V_63 = V_17 ;
V_62 = V_20 ;
}
V_49 = V_63 ;
V_3 = V_62 ;
V_109 = 0 ;
while ( V_49 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_5 += F_60 ( V_1 , V_109 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_49 ++ ;
}
V_49 = V_63 ;
V_3 = V_62 ;
V_109 = 0 ;
while ( V_5 > V_14 && V_49 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_5 -= F_60 ( V_1 , V_109 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_49 ++ ;
}
V_123 = V_18 ;
V_5 = 0 ;
V_109 = 0 ;
while ( V_5 >= 0 && V_49 < V_123 ) {
struct log * V_1 = F_3 ( V_3 ) ;
int V_124 ;
V_124 = F_60 ( V_1 , V_109 , true , V_13 , V_32 ) ;
if ( V_124 < 0 ) {
V_5 = V_124 ;
break;
}
V_3 = F_4 ( V_3 ) ;
V_49 ++ ;
V_109 = V_1 -> V_9 ;
F_18 ( & V_48 ) ;
if ( F_21 ( V_28 + V_5 , V_13 , V_124 ) )
V_5 = - V_56 ;
else
V_5 += V_124 ;
F_17 ( & V_48 ) ;
if ( V_49 < V_17 ) {
V_49 = V_17 ;
V_3 = V_20 ;
V_109 = 0 ;
}
}
}
if ( V_122 ) {
V_63 = V_18 ;
V_62 = V_19 ;
}
F_18 ( & V_48 ) ;
F_14 ( V_13 ) ;
return V_5 ;
}
int F_63 ( int type , char T_7 * V_28 , int V_5 , bool V_96 )
{
bool V_122 = false ;
static int V_125 = - 1 ;
int error ;
error = F_54 ( type , V_96 ) ;
if ( error )
goto V_38;
error = F_27 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_126 :
break;
case V_97 :
break;
case V_127 :
error = - V_33 ;
if ( ! V_28 || V_5 < 0 )
goto V_38;
error = 0 ;
if ( ! V_5 )
goto V_38;
if ( ! F_64 ( V_128 , V_28 , V_5 ) ) {
error = - V_56 ;
goto V_38;
}
error = F_19 ( V_53 ,
V_118 != V_18 ) ;
if ( error )
goto V_38;
error = F_61 ( V_28 , V_5 ) ;
break;
case V_129 :
V_122 = true ;
case V_75 :
error = - V_33 ;
if ( ! V_28 || V_5 < 0 )
goto V_38;
error = 0 ;
if ( ! V_5 )
goto V_38;
if ( ! F_64 ( V_128 , V_28 , V_5 ) ) {
error = - V_56 ;
goto V_38;
}
error = F_62 ( V_28 , V_5 , V_122 ) ;
break;
case V_130 :
F_62 ( NULL , 0 , true ) ;
break;
case V_131 :
if ( V_125 == - 1 )
V_125 = V_132 ;
V_132 = V_133 ;
break;
case V_134 :
if ( V_125 != - 1 ) {
V_132 = V_125 ;
V_125 = - 1 ;
}
break;
case V_135 :
error = - V_33 ;
if ( V_5 < 1 || V_5 > 8 )
goto V_38;
if ( V_5 < V_133 )
V_5 = V_133 ;
V_132 = V_5 ;
V_125 = - 1 ;
error = 0 ;
break;
case V_136 :
F_17 ( & V_48 ) ;
if ( V_118 < V_17 ) {
V_118 = V_17 ;
V_119 = V_20 ;
V_120 = 0 ;
V_121 = 0 ;
}
if ( V_96 ) {
error = V_19 - V_119 ;
} else {
T_2 V_49 = V_118 ;
T_1 V_3 = V_119 ;
enum V_8 V_109 = V_120 ;
error = 0 ;
while ( V_49 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
error += F_60 ( V_1 , V_109 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_49 ++ ;
V_109 = V_1 -> V_9 ;
}
error -= V_121 ;
}
F_18 ( & V_48 ) ;
break;
case V_95 :
error = V_21 ;
break;
default:
error = - V_33 ;
break;
}
V_38:
return error ;
}
static int T_9 F_65 ( char * V_76 )
{
V_137 = 1 ;
F_66 ( V_138 L_14 ) ;
return 0 ;
}
static void F_67 ( int V_7 , const char * V_13 , T_6 V_5 )
{
struct V_139 * V_140 ;
F_68 ( V_13 , 0 , V_5 , V_5 ) ;
if ( V_7 >= V_132 && ! V_137 )
return;
if ( ! V_141 )
return;
F_69 (con) {
if ( V_142 && V_140 != V_142 )
continue;
if ( ! ( V_140 -> V_9 & V_143 ) )
continue;
if ( ! V_140 -> V_144 )
continue;
if ( ! F_70 ( F_71 () ) &&
! ( V_140 -> V_9 & V_145 ) )
continue;
V_140 -> V_144 ( V_140 , V_13 , V_5 ) ;
}
}
static void F_72 ( void )
{
static unsigned long V_146 ;
if ( F_73 ( V_93 , V_146 ) &&
! F_51 ( V_93 , V_146 + 30 * V_87 ) )
return;
V_146 = V_93 ;
F_74 () ;
F_75 ( & V_48 ) ;
F_76 ( & V_147 , 1 ) ;
}
static int F_77 ( void )
{
struct V_139 * V_140 ;
F_69 (con)
if ( V_140 -> V_9 & V_145 )
return 1 ;
return 0 ;
}
static inline int F_78 ( unsigned int V_148 )
{
return F_70 ( V_148 ) || F_77 () ;
}
static int F_79 ( unsigned int V_148 )
__releases( &logbuf_lock
static inline void F_80 ( void )
{
if ( F_40 ( V_149 ) ) {
int V_150 = V_149 ;
while ( V_150 -- ) {
F_81 ( 1 ) ;
F_52 () ;
}
}
}
static void F_82 ( void )
{
if ( V_151 . V_152 )
return;
if ( V_151 . V_5 == 0 )
return;
F_5 ( V_151 . V_6 , V_151 . V_7 , V_153 , V_151 . V_10 ,
NULL , 0 , V_151 . V_28 , V_151 . V_5 ) ;
V_151 . V_152 = true ;
}
static bool F_83 ( int V_6 , int V_7 , const char * V_13 , T_6 V_5 )
{
if ( V_151 . V_5 && V_151 . V_152 )
return false ;
if ( V_151 . V_5 + V_5 > sizeof( V_151 . V_28 ) ) {
F_82 () ;
return false ;
}
if ( ! V_151 . V_5 ) {
V_151 . V_6 = V_6 ;
V_151 . V_7 = V_7 ;
V_151 . V_154 = V_101 ;
V_151 . V_10 = F_7 () ;
V_151 . V_155 = 0 ;
V_151 . V_152 = false ;
}
memcpy ( V_151 . V_28 + V_151 . V_5 , V_13 , V_5 ) ;
V_151 . V_5 += V_5 ;
return true ;
}
static T_6 F_84 ( char * V_13 , T_6 V_14 )
{
T_6 V_124 = 0 ;
T_6 V_5 ;
if ( V_151 . V_155 == 0 ) {
V_124 += F_58 ( V_151 . V_10 , V_13 ) ;
V_14 -= V_124 ;
}
V_5 = V_151 . V_5 - V_151 . V_155 ;
if ( V_5 > 0 ) {
if ( V_5 + 1 > V_14 )
V_5 = V_14 - 1 ;
memcpy ( V_13 + V_124 , V_151 . V_28 + V_151 . V_155 , V_5 ) ;
V_124 += V_5 ;
V_151 . V_155 = V_151 . V_5 ;
}
if ( V_151 . V_152 ) {
V_13 [ V_124 ++ ] = '\n' ;
V_151 . V_5 = 0 ;
}
return V_124 ;
}
T_10 int F_85 ( int V_6 , int V_7 ,
const char * V_11 , T_6 V_156 ,
const char * V_157 , T_11 args )
{
static int V_158 ;
static char V_159 [ V_32 ] ;
char * V_13 = V_159 ;
T_6 V_2 ;
enum V_8 V_160 = 0 ;
unsigned long V_9 ;
int V_161 ;
int V_162 = 0 ;
F_48 () ;
F_80 () ;
F_86 ( V_9 ) ;
V_161 = F_71 () ;
if ( F_40 ( V_163 == V_161 ) ) {
if ( ! V_164 && ! F_87 ( V_101 ) ) {
V_158 = 1 ;
goto V_165;
}
F_72 () ;
}
F_88 () ;
F_89 ( & V_48 ) ;
V_163 = V_161 ;
if ( V_158 ) {
static const char V_166 [] =
L_15 ;
V_158 = 0 ;
V_162 += strlen ( V_166 ) ;
F_5 ( 0 , 2 , V_113 | V_114 , 0 ,
NULL , 0 , V_166 , V_162 ) ;
}
V_2 = F_90 ( V_13 , sizeof( V_159 ) , V_157 , args ) ;
if ( V_2 && V_13 [ V_2 - 1 ] == '\n' ) {
V_2 -- ;
V_160 |= V_114 ;
}
if ( V_13 [ 0 ] == '<' && V_13 [ 1 ] && V_13 [ 2 ] == '>' ) {
switch ( V_13 [ 1 ] ) {
case '0' ... '7' :
if ( V_7 == - 1 )
V_7 = V_13 [ 1 ] - '0' ;
case 'd' :
V_160 |= V_113 ;
case 'c' :
V_13 += 3 ;
V_2 -= 3 ;
}
}
if ( V_7 == - 1 )
V_7 = V_30 ;
if ( V_11 )
V_160 |= V_113 | V_114 ;
if ( ! ( V_160 & V_114 ) ) {
if ( V_151 . V_5 && ( V_160 & V_113 || V_151 . V_154 != V_101 ) )
F_82 () ;
if ( ! F_83 ( V_6 , V_7 , V_13 , V_2 ) )
F_5 ( V_6 , V_7 , V_160 | V_112 , 0 ,
V_11 , V_156 , V_13 , V_2 ) ;
} else {
bool V_167 = false ;
if ( V_151 . V_5 && V_151 . V_154 == V_101 ) {
if ( ! ( V_160 & V_113 ) )
V_167 = F_83 ( V_6 , V_7 , V_13 , V_2 ) ;
F_82 () ;
}
if ( ! V_167 )
F_5 ( V_6 , V_7 , V_160 , 0 ,
V_11 , V_156 , V_13 , V_2 ) ;
}
V_162 += V_2 ;
if ( F_79 ( V_161 ) )
F_91 () ;
F_92 () ;
V_165:
F_93 ( V_9 ) ;
return V_162 ;
}
T_10 int F_94 ( const char * V_157 , T_11 args )
{
return F_85 ( 0 , - 1 , NULL , 0 , V_157 , args ) ;
}
T_10 int F_13 ( int V_6 , int V_7 ,
const char * V_11 , T_6 V_156 ,
const char * V_157 , ... )
{
T_11 args ;
int V_168 ;
va_start ( args , V_157 ) ;
V_168 = F_85 ( V_6 , V_7 , V_11 , V_156 , V_157 , args ) ;
va_end ( args ) ;
return V_168 ;
}
T_10 int F_66 ( const char * V_157 , ... )
{
T_11 args ;
int V_168 ;
#ifdef F_95
if ( F_40 ( V_169 ) ) {
va_start ( args , V_157 ) ;
V_168 = F_96 ( V_157 , args ) ;
va_end ( args ) ;
return V_168 ;
}
#endif
va_start ( args , V_157 ) ;
V_168 = F_85 ( 0 , - 1 , NULL , 0 , V_157 , args ) ;
va_end ( args ) ;
return V_168 ;
}
static struct log * F_3 ( T_1 V_3 ) { return NULL ; }
static T_1 F_4 ( T_1 V_3 ) { return 0 ; }
static void F_67 ( int V_7 , const char * V_13 , T_6 V_5 ) {}
static T_6 F_60 ( const struct log * V_1 , enum V_8 V_109 ,
bool V_107 , char * V_28 , T_6 V_14 ) { return 0 ; }
static T_6 F_84 ( char * V_13 , T_6 V_14 ) { return 0 ; }
static int F_97 ( char * V_170 , int V_3 , char * V_171 ,
char * V_172 )
{
struct V_173 * V_55 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_174 && V_173 [ V_29 ] . V_170 [ 0 ] ; V_29 ++ )
if ( strcmp ( V_173 [ V_29 ] . V_170 , V_170 ) == 0 &&
V_173 [ V_29 ] . V_175 == V_3 ) {
if ( ! V_172 )
V_176 = V_29 ;
return 0 ;
}
if ( V_29 == V_174 )
return - V_177 ;
if ( ! V_172 )
V_176 = V_29 ;
V_55 = & V_173 [ V_29 ] ;
F_98 ( V_55 -> V_170 , V_170 , sizeof( V_55 -> V_170 ) ) ;
V_55 -> V_171 = V_171 ;
#ifdef F_99
V_55 -> V_172 = V_172 ;
#endif
V_55 -> V_175 = V_3 ;
return 0 ;
}
static int T_9 F_100 ( char * V_76 )
{
char V_28 [ sizeof( V_173 [ 0 ] . V_170 ) + 4 ] ;
char * V_178 , * V_171 , * V_172 = NULL ;
int V_3 ;
#ifdef F_99
if ( ! memcmp ( V_76 , L_16 , 4 ) ) {
V_172 = L_17 ;
V_76 += 4 ;
} else if ( ! memcmp ( V_76 , L_18 , 4 ) ) {
V_172 = V_76 + 4 ;
V_76 = strchr ( V_172 , ',' ) ;
if ( ! V_76 ) {
F_66 ( V_179 L_19 ) ;
return 1 ;
}
* ( V_76 ++ ) = 0 ;
}
#endif
if ( V_76 [ 0 ] >= '0' && V_76 [ 0 ] <= '9' ) {
strcpy ( V_28 , L_20 ) ;
strncpy ( V_28 + 4 , V_76 , sizeof( V_28 ) - 5 ) ;
} else {
strncpy ( V_28 , V_76 , sizeof( V_28 ) - 1 ) ;
}
V_28 [ sizeof( V_28 ) - 1 ] = 0 ;
if ( ( V_171 = strchr ( V_76 , ',' ) ) != NULL )
* ( V_171 ++ ) = 0 ;
#ifdef F_101
if ( ! strcmp ( V_76 , L_21 ) )
strcpy ( V_28 , L_22 ) ;
if ( ! strcmp ( V_76 , L_23 ) )
strcpy ( V_28 , L_24 ) ;
#endif
for ( V_178 = V_28 ; * V_178 ; V_178 ++ )
if ( ( * V_178 >= '0' && * V_178 <= '9' ) || * V_178 == ',' )
break;
V_3 = F_12 ( V_178 , NULL , 10 ) ;
* V_178 = 0 ;
F_97 ( V_28 , V_3 , V_171 , V_172 ) ;
V_180 = 1 ;
return 1 ;
}
int F_102 ( char * V_170 , int V_3 , char * V_171 )
{
return F_97 ( V_170 , V_3 , V_171 , NULL ) ;
}
int F_103 ( char * V_170 , int V_3 , char * V_181 , int V_182 , char * V_171 )
{
struct V_173 * V_55 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_174 && V_173 [ V_29 ] . V_170 [ 0 ] ; V_29 ++ )
if ( strcmp ( V_173 [ V_29 ] . V_170 , V_170 ) == 0 &&
V_173 [ V_29 ] . V_175 == V_3 ) {
V_55 = & V_173 [ V_29 ] ;
F_98 ( V_55 -> V_170 , V_181 , sizeof( V_55 -> V_170 ) ) ;
V_55 -> V_170 [ sizeof( V_55 -> V_170 ) - 1 ] = 0 ;
V_55 -> V_171 = V_171 ;
V_55 -> V_175 = V_182 ;
return V_29 ;
}
return - 1 ;
}
static int T_9 F_104 ( char * V_76 )
{
V_183 = 0 ;
return 1 ;
}
void F_105 ( void )
{
if ( ! V_183 )
return;
F_66 ( L_25 ) ;
F_106 () ;
V_184 = 1 ;
F_107 ( & V_147 ) ;
}
void F_108 ( void )
{
if ( ! V_183 )
return;
F_109 ( & V_147 ) ;
V_184 = 0 ;
F_91 () ;
}
static int T_12 F_110 ( struct V_185 * V_186 ,
unsigned long V_187 , void * V_188 )
{
switch ( V_187 ) {
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
F_106 () ;
F_91 () ;
}
return V_194 ;
}
void F_106 ( void )
{
F_111 ( F_112 () ) ;
F_109 ( & V_147 ) ;
if ( V_184 )
return;
V_195 = 1 ;
V_196 = 1 ;
}
int F_113 ( void )
{
if ( F_114 ( & V_147 ) )
return 0 ;
if ( V_184 ) {
F_107 ( & V_147 ) ;
return 0 ;
}
V_195 = 1 ;
V_196 = 0 ;
return 1 ;
}
int F_115 ( void )
{
return V_195 ;
}
void F_116 ( void )
{
if ( F_117 ( V_197 ) ) {
int V_198 = F_118 ( V_197 , 0 ) ;
if ( V_198 & V_199 ) {
char * V_28 = F_119 ( V_200 ) ;
F_66 ( V_100 L_26 , V_28 ) ;
}
if ( V_198 & V_201 )
F_120 ( & V_53 ) ;
}
}
int F_121 ( int V_148 )
{
if ( F_122 ( V_148 ) )
F_116 () ;
return F_117 ( V_197 ) ;
}
void F_123 ( void )
{
if ( F_124 ( & V_53 ) )
F_125 ( V_197 , V_201 ) ;
}
void F_91 ( void )
{
static char V_13 [ V_32 ] ;
static T_2 V_202 ;
unsigned long V_9 ;
bool V_203 = false ;
bool V_204 ;
if ( V_184 ) {
F_107 ( & V_147 ) ;
return;
}
V_196 = 0 ;
F_42 ( & V_48 , V_9 ) ;
if ( V_151 . V_5 && ( V_151 . V_155 < V_151 . V_5 || V_151 . V_152 ) ) {
T_6 V_5 ;
V_5 = F_84 ( V_13 , sizeof( V_13 ) ) ;
F_126 ( & V_48 ) ;
F_127 () ;
F_67 ( V_151 . V_7 , V_13 , V_5 ) ;
F_128 () ;
F_93 ( V_9 ) ;
} else
F_43 ( & V_48 , V_9 ) ;
V_205:
for (; ; ) {
struct log * V_1 ;
T_6 V_5 ;
int V_7 ;
F_42 ( & V_48 , V_9 ) ;
if ( V_202 != V_18 ) {
V_203 = true ;
V_202 = V_18 ;
}
if ( V_206 < V_17 ) {
V_206 = V_17 ;
V_207 = V_20 ;
V_208 = 0 ;
}
V_117:
if ( V_206 == V_18 )
break;
V_1 = F_3 ( V_207 ) ;
if ( V_1 -> V_9 & V_153 ) {
V_207 = F_4 ( V_207 ) ;
V_206 ++ ;
V_1 -> V_9 &= ~ V_153 ;
goto V_117;
}
V_7 = V_1 -> V_7 ;
V_5 = F_60 ( V_1 , V_208 , false ,
V_13 , sizeof( V_13 ) ) ;
V_207 = F_4 ( V_207 ) ;
V_206 ++ ;
V_208 = V_1 -> V_9 ;
F_126 ( & V_48 ) ;
F_127 () ;
F_67 ( V_7 , V_13 , V_5 ) ;
F_128 () ;
F_93 ( V_9 ) ;
}
V_195 = 0 ;
if ( F_40 ( V_142 ) )
V_142 = NULL ;
F_126 ( & V_48 ) ;
F_107 ( & V_147 ) ;
F_89 ( & V_48 ) ;
V_204 = V_206 != V_18 ;
F_43 ( & V_48 , V_9 ) ;
if ( V_204 && F_113 () )
goto V_205;
if ( V_203 )
F_123 () ;
}
void T_13 F_129 ( void )
{
if ( V_196 )
F_130 () ;
}
void F_131 ( void )
{
struct V_139 * V_55 ;
if ( V_164 ) {
if ( F_114 ( & V_147 ) != 0 )
return;
} else
F_106 () ;
V_195 = 1 ;
V_196 = 0 ;
F_69 (c)
if ( ( V_55 -> V_9 & V_143 ) && V_55 -> V_209 )
V_55 -> V_209 () ;
F_91 () ;
}
struct V_210 * F_132 ( int * V_175 )
{
struct V_139 * V_55 ;
struct V_210 * V_211 = NULL ;
F_106 () ;
F_69 (c) {
if ( ! V_55 -> V_212 )
continue;
V_211 = V_55 -> V_212 ( V_55 , V_175 ) ;
if ( V_211 )
break;
}
F_91 () ;
return V_211 ;
}
void F_133 ( struct V_139 * V_139 )
{
F_106 () ;
V_139 -> V_9 &= ~ V_143 ;
F_91 () ;
}
void F_134 ( struct V_139 * V_139 )
{
F_106 () ;
V_139 -> V_9 |= V_143 ;
F_91 () ;
}
static int T_9 F_135 ( char * V_76 )
{
V_213 = 1 ;
F_66 ( V_138 L_27 ) ;
return 0 ;
}
void F_136 ( struct V_139 * V_214 )
{
int V_29 ;
unsigned long V_9 ;
struct V_139 * V_215 = NULL ;
if ( V_141 && V_214 -> V_9 & V_216 ) {
F_69 (bcon) {
if ( ! ( V_215 -> V_9 & V_216 ) ) {
F_66 ( V_138 L_28 ,
V_214 -> V_170 , V_214 -> V_175 ) ;
return;
}
}
}
if ( V_141 && V_141 -> V_9 & V_216 )
V_215 = V_141 ;
if ( V_217 < 0 || V_215 || ! V_141 )
V_217 = V_176 ;
if ( V_214 -> V_218 )
V_214 -> V_218 () ;
if ( V_217 < 0 ) {
if ( V_214 -> V_175 < 0 )
V_214 -> V_175 = 0 ;
if ( V_214 -> V_219 == NULL ||
V_214 -> V_219 ( V_214 , NULL ) == 0 ) {
V_214 -> V_9 |= V_143 ;
if ( V_214 -> V_212 ) {
V_214 -> V_9 |= V_220 ;
V_217 = 0 ;
}
}
}
for ( V_29 = 0 ; V_29 < V_174 && V_173 [ V_29 ] . V_170 [ 0 ] ;
V_29 ++ ) {
if ( strcmp ( V_173 [ V_29 ] . V_170 , V_214 -> V_170 ) != 0 )
continue;
if ( V_214 -> V_175 >= 0 &&
V_214 -> V_175 != V_173 [ V_29 ] . V_175 )
continue;
if ( V_214 -> V_175 < 0 )
V_214 -> V_175 = V_173 [ V_29 ] . V_175 ;
#ifdef F_99
if ( V_173 [ V_29 ] . V_172 ) {
V_214 -> V_9 |= V_221 ;
F_137 ( V_214 ,
V_173 [ V_29 ] . V_175 ,
V_173 [ V_29 ] . V_171 ,
V_173 [ V_29 ] . V_172 ) ;
return;
}
#endif
if ( V_214 -> V_219 &&
V_214 -> V_219 ( V_214 , V_173 [ V_29 ] . V_171 ) != 0 )
break;
V_214 -> V_9 |= V_143 ;
V_214 -> V_175 = V_173 [ V_29 ] . V_175 ;
if ( V_29 == V_176 ) {
V_214 -> V_9 |= V_220 ;
V_217 = V_176 ;
}
break;
}
if ( ! ( V_214 -> V_9 & V_143 ) )
return;
if ( V_215 && ( ( V_214 -> V_9 & ( V_220 | V_216 ) ) == V_220 ) )
V_214 -> V_9 &= ~ V_222 ;
F_106 () ;
if ( ( V_214 -> V_9 & V_220 ) || V_141 == NULL ) {
V_214 -> V_115 = V_141 ;
V_141 = V_214 ;
if ( V_214 -> V_115 )
V_214 -> V_115 -> V_9 &= ~ V_220 ;
} else {
V_214 -> V_115 = V_141 -> V_115 ;
V_141 -> V_115 = V_214 ;
}
if ( V_214 -> V_9 & V_222 ) {
F_42 ( & V_48 , V_9 ) ;
V_206 = V_118 ;
V_207 = V_119 ;
V_208 = V_120 ;
F_43 ( & V_48 , V_9 ) ;
V_142 = V_214 ;
}
F_91 () ;
F_138 () ;
if ( V_215 &&
( ( V_214 -> V_9 & ( V_220 | V_216 ) ) == V_220 ) &&
! V_213 ) {
F_66 ( V_138 L_29 ,
V_214 -> V_170 , V_214 -> V_175 ) ;
F_69 (bcon)
if ( V_215 -> V_9 & V_216 )
F_139 ( V_215 ) ;
} else {
F_66 ( V_138 L_30 ,
( V_214 -> V_9 & V_216 ) ? L_31 : L_17 ,
V_214 -> V_170 , V_214 -> V_175 ) ;
}
}
int F_139 ( struct V_139 * V_139 )
{
struct V_139 * V_223 , * V_224 ;
int V_225 = 1 ;
#ifdef F_99
if ( V_139 -> V_9 & V_221 )
return F_140 ( V_139 ) ;
#endif
F_106 () ;
if ( V_141 == V_139 ) {
V_141 = V_139 -> V_115 ;
V_225 = 0 ;
} else if ( V_141 ) {
for ( V_223 = V_141 -> V_115 , V_224 = V_141 ;
V_223 ; V_224 = V_223 , V_223 = V_224 -> V_115 ) {
if ( V_223 == V_139 ) {
V_224 -> V_115 = V_223 -> V_115 ;
V_225 = 0 ;
break;
}
}
}
if ( V_141 != NULL && V_139 -> V_9 & V_220 )
V_141 -> V_9 |= V_220 ;
F_91 () ;
F_138 () ;
return V_225 ;
}
static int T_9 F_141 ( void )
{
struct V_139 * V_140 ;
F_69 (con) {
if ( ! V_213 && V_140 -> V_9 & V_216 ) {
F_66 ( V_138 L_32 ,
V_140 -> V_170 , V_140 -> V_175 ) ;
F_139 ( V_140 ) ;
}
}
F_142 ( F_110 , 0 ) ;
return 0 ;
}
int F_143 ( const char * V_157 , ... )
{
unsigned long V_9 ;
T_11 args ;
char * V_28 ;
int V_168 ;
F_86 ( V_9 ) ;
V_28 = F_119 ( V_200 ) ;
va_start ( args , V_157 ) ;
V_168 = vsnprintf ( V_28 , V_226 , V_157 , args ) ;
va_end ( args ) ;
F_144 ( V_197 , V_199 ) ;
F_93 ( V_9 ) ;
return V_168 ;
}
int F_145 ( const char * V_227 )
{
return F_146 ( & V_228 , V_227 ) ;
}
bool F_147 ( unsigned long * V_229 ,
unsigned int V_230 )
{
if ( * V_229 == 0
|| ! F_148 ( V_93 , * V_229 ,
* V_229
+ F_49 ( V_230 ) ) ) {
* V_229 = V_93 ;
return true ;
}
return false ;
}
int F_149 ( struct V_231 * V_232 )
{
unsigned long V_9 ;
int V_72 = - V_233 ;
if ( ! V_232 -> V_234 )
return - V_33 ;
F_150 ( & V_235 , V_9 ) ;
if ( ! V_232 -> V_236 ) {
V_232 -> V_236 = 1 ;
F_151 ( & V_232 -> V_237 , & V_238 ) ;
V_72 = 0 ;
}
F_152 ( & V_235 , V_9 ) ;
return V_72 ;
}
int F_153 ( struct V_231 * V_232 )
{
unsigned long V_9 ;
int V_72 = - V_33 ;
F_150 ( & V_235 , V_9 ) ;
if ( V_232 -> V_236 ) {
V_232 -> V_236 = 0 ;
F_154 ( & V_232 -> V_237 ) ;
V_72 = 0 ;
}
F_152 ( & V_235 , V_9 ) ;
F_155 () ;
return V_72 ;
}
void F_156 ( enum V_239 V_240 )
{
struct V_231 * V_232 ;
unsigned long V_9 ;
if ( ( V_240 > V_241 ) && ! V_242 )
return;
F_157 () ;
F_158 (dumper, &dump_list, list) {
if ( V_232 -> V_243 && V_240 > V_232 -> V_243 )
continue;
V_232 -> V_244 = true ;
F_42 ( & V_48 , V_9 ) ;
V_232 -> V_245 = V_63 ;
V_232 -> V_246 = V_62 ;
V_232 -> V_123 = V_18 ;
V_232 -> V_247 = V_19 ;
F_43 ( & V_48 , V_9 ) ;
V_232 -> V_234 ( V_232 , V_240 ) ;
V_232 -> V_244 = false ;
}
F_159 () ;
}
bool F_160 ( struct V_231 * V_232 , bool V_107 ,
char * line , T_6 V_14 , T_6 * V_5 )
{
struct log * V_1 ;
T_6 V_248 = 0 ;
bool V_31 = false ;
if ( ! V_232 -> V_244 )
goto V_38;
if ( V_232 -> V_245 < V_17 ) {
V_232 -> V_245 = V_17 ;
V_232 -> V_246 = V_20 ;
}
if ( V_232 -> V_245 >= V_18 )
goto V_38;
V_1 = F_3 ( V_232 -> V_246 ) ;
V_248 = F_60 ( V_1 , 0 , V_107 , line , V_14 ) ;
V_232 -> V_246 = F_4 ( V_232 -> V_246 ) ;
V_232 -> V_245 ++ ;
V_31 = true ;
V_38:
if ( V_5 )
* V_5 = V_248 ;
return V_31 ;
}
bool F_161 ( struct V_231 * V_232 , bool V_107 ,
char * line , T_6 V_14 , T_6 * V_5 )
{
unsigned long V_9 ;
bool V_31 ;
F_42 ( & V_48 , V_9 ) ;
V_31 = F_160 ( V_232 , V_107 , line , V_14 , V_5 ) ;
F_43 ( & V_48 , V_9 ) ;
return V_31 ;
}
bool F_162 ( struct V_231 * V_232 , bool V_107 ,
char * V_28 , T_6 V_14 , T_6 * V_5 )
{
unsigned long V_9 ;
T_2 V_49 ;
T_1 V_3 ;
T_2 V_123 ;
T_1 V_247 ;
enum V_8 V_109 ;
T_6 V_248 = 0 ;
bool V_31 = false ;
if ( ! V_232 -> V_244 )
goto V_38;
F_42 ( & V_48 , V_9 ) ;
if ( V_232 -> V_245 < V_17 ) {
V_232 -> V_245 = V_17 ;
V_232 -> V_246 = V_20 ;
}
if ( V_232 -> V_245 >= V_232 -> V_123 ) {
F_43 ( & V_48 , V_9 ) ;
goto V_38;
}
V_49 = V_232 -> V_245 ;
V_3 = V_232 -> V_246 ;
V_109 = 0 ;
while ( V_49 < V_232 -> V_123 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_248 += F_60 ( V_1 , V_109 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_49 ++ ;
V_109 = V_1 -> V_9 ;
}
V_49 = V_232 -> V_245 ;
V_3 = V_232 -> V_246 ;
V_109 = 0 ;
while ( V_248 > V_14 && V_49 < V_232 -> V_123 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_248 -= F_60 ( V_1 , V_109 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_49 ++ ;
V_109 = V_1 -> V_9 ;
}
V_123 = V_49 ;
V_247 = V_3 ;
V_248 = 0 ;
V_109 = 0 ;
while ( V_49 < V_232 -> V_123 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_248 += F_60 ( V_1 , V_109 , V_107 , V_28 + V_248 , V_14 - V_248 ) ;
V_3 = F_4 ( V_3 ) ;
V_49 ++ ;
V_109 = V_1 -> V_9 ;
}
V_232 -> V_123 = V_123 ;
V_232 -> V_247 = V_247 ;
V_31 = true ;
F_43 ( & V_48 , V_9 ) ;
V_38:
if ( V_5 )
* V_5 = V_248 ;
return V_31 ;
}
void F_163 ( struct V_231 * V_232 )
{
V_232 -> V_245 = V_63 ;
V_232 -> V_246 = V_62 ;
V_232 -> V_123 = V_18 ;
V_232 -> V_247 = V_19 ;
}
void F_164 ( struct V_231 * V_232 )
{
unsigned long V_9 ;
F_42 ( & V_48 , V_9 ) ;
F_163 ( V_232 ) ;
F_43 ( & V_48 , V_9 ) ;
}
