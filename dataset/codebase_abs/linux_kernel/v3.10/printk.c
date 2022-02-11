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
static int F_8 ( int type )
{
if ( V_22 )
return 1 ;
return type != V_23 &&
type != V_24 ;
}
static int F_9 ( int type , bool V_25 )
{
if ( V_25 && type != V_26 )
return 0 ;
if ( F_8 ( type ) ) {
if ( F_10 ( V_27 ) )
return 0 ;
if ( F_10 ( V_28 ) ) {
F_11 ( L_1
L_2
L_3 ,
V_29 -> V_30 , F_12 ( V_29 ) ) ;
return 0 ;
}
return - V_31 ;
}
return F_13 ( type ) ;
}
static T_4 F_14 ( struct V_32 * V_33 , const struct V_34 * V_35 ,
unsigned long V_36 , T_5 V_37 )
{
char * V_38 , * line ;
int V_39 ;
int V_7 = V_40 ;
int V_6 = 1 ;
T_6 V_5 = F_15 ( V_35 , V_36 ) ;
T_4 V_41 = V_5 ;
if ( V_5 > V_42 )
return - V_43 ;
V_38 = F_16 ( V_5 + 1 , V_44 ) ;
if ( V_38 == NULL )
return - V_45 ;
line = V_38 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
if ( F_17 ( line , V_35 [ V_39 ] . V_46 , V_35 [ V_39 ] . V_47 ) ) {
V_41 = - V_48 ;
goto V_49;
}
line += V_35 [ V_39 ] . V_47 ;
}
line = V_38 ;
if ( line [ 0 ] == '<' ) {
char * V_50 = NULL ;
V_39 = F_18 ( line + 1 , & V_50 , 10 ) ;
if ( V_50 && V_50 [ 0 ] == '>' ) {
V_7 = V_39 & 7 ;
if ( V_39 >> 3 )
V_6 = V_39 >> 3 ;
V_50 ++ ;
V_5 -= V_50 - line ;
line = V_50 ;
}
}
line [ V_5 ] = '\0' ;
F_19 ( V_6 , V_7 , NULL , 0 , L_4 , line ) ;
V_49:
F_20 ( V_38 ) ;
return V_41 ;
}
static T_4 F_21 ( struct V_51 * V_51 , char T_7 * V_38 ,
T_6 V_36 , T_5 * V_52 )
{
struct V_53 * V_54 = V_51 -> V_55 ;
struct log * V_1 ;
T_2 V_56 ;
T_6 V_39 ;
char V_57 = '-' ;
T_6 V_5 ;
T_4 V_41 ;
if ( ! V_54 )
return - V_58 ;
V_41 = F_22 ( & V_54 -> V_59 ) ;
if ( V_41 )
return V_41 ;
F_23 ( & V_60 ) ;
while ( V_54 -> V_61 == V_18 ) {
if ( V_51 -> V_62 & V_63 ) {
V_41 = - V_64 ;
F_24 ( & V_60 ) ;
goto V_49;
}
F_24 ( & V_60 ) ;
V_41 = F_25 ( V_65 ,
V_54 -> V_61 != V_18 ) ;
if ( V_41 )
goto V_49;
F_23 ( & V_60 ) ;
}
if ( V_54 -> V_61 < V_17 ) {
V_54 -> V_3 = V_20 ;
V_54 -> V_61 = V_17 ;
V_41 = - V_66 ;
F_24 ( & V_60 ) ;
goto V_49;
}
V_1 = F_3 ( V_54 -> V_3 ) ;
V_56 = V_1 -> V_10 ;
F_26 ( V_56 , 1000 ) ;
if ( V_1 -> V_9 & V_67 && ! ( V_54 -> V_68 & V_67 ) )
V_57 = 'c' ;
else if ( ( V_1 -> V_9 & V_67 ) ||
( ( V_54 -> V_68 & V_67 ) && ! ( V_1 -> V_9 & V_69 ) ) )
V_57 = '+' ;
V_5 = sprintf ( V_54 -> V_38 , L_5 ,
( V_1 -> V_6 << 3 ) | V_1 -> V_7 ,
V_54 -> V_61 , V_56 , V_57 ) ;
V_54 -> V_68 = V_1 -> V_9 ;
for ( V_39 = 0 ; V_39 < V_1 -> V_2 ; V_39 ++ ) {
unsigned char V_70 = F_1 ( V_1 ) [ V_39 ] ;
if ( V_70 < ' ' || V_70 >= 127 || V_70 == '\\' )
V_5 += sprintf ( V_54 -> V_38 + V_5 , L_6 , V_70 ) ;
else
V_54 -> V_38 [ V_5 ++ ] = V_70 ;
}
V_54 -> V_38 [ V_5 ++ ] = '\n' ;
if ( V_1 -> V_12 ) {
bool line = true ;
for ( V_39 = 0 ; V_39 < V_1 -> V_12 ; V_39 ++ ) {
unsigned char V_70 = F_2 ( V_1 ) [ V_39 ] ;
if ( line ) {
V_54 -> V_38 [ V_5 ++ ] = ' ' ;
line = false ;
}
if ( V_70 == '\0' ) {
V_54 -> V_38 [ V_5 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_70 < ' ' || V_70 >= 127 || V_70 == '\\' ) {
V_5 += sprintf ( V_54 -> V_38 + V_5 , L_6 , V_70 ) ;
continue;
}
V_54 -> V_38 [ V_5 ++ ] = V_70 ;
}
V_54 -> V_38 [ V_5 ++ ] = '\n' ;
}
V_54 -> V_3 = F_4 ( V_54 -> V_3 ) ;
V_54 -> V_61 ++ ;
F_24 ( & V_60 ) ;
if ( V_5 > V_36 ) {
V_41 = - V_43 ;
goto V_49;
}
if ( F_27 ( V_38 , V_54 -> V_38 , V_5 ) ) {
V_41 = - V_48 ;
goto V_49;
}
V_41 = V_5 ;
V_49:
F_28 ( & V_54 -> V_59 ) ;
return V_41 ;
}
static T_5 F_29 ( struct V_51 * V_51 , T_5 V_71 , int V_72 )
{
struct V_53 * V_54 = V_51 -> V_55 ;
T_5 V_41 = 0 ;
if ( ! V_54 )
return - V_58 ;
if ( V_71 )
return - V_73 ;
F_23 ( & V_60 ) ;
switch ( V_72 ) {
case V_74 :
V_54 -> V_3 = V_20 ;
V_54 -> V_61 = V_17 ;
break;
case V_75 :
V_54 -> V_3 = V_76 ;
V_54 -> V_61 = V_77 ;
break;
case V_78 :
V_54 -> V_3 = V_19 ;
V_54 -> V_61 = V_18 ;
break;
default:
V_41 = - V_43 ;
}
F_24 ( & V_60 ) ;
return V_41 ;
}
static unsigned int F_30 ( struct V_51 * V_51 , T_8 * V_79 )
{
struct V_53 * V_54 = V_51 -> V_55 ;
int V_41 = 0 ;
if ( ! V_54 )
return V_80 | V_81 ;
F_31 ( V_51 , & V_65 , V_79 ) ;
F_23 ( & V_60 ) ;
if ( V_54 -> V_61 < V_18 ) {
if ( V_54 -> V_61 < V_17 )
V_41 = V_82 | V_83 | V_80 | V_84 ;
else
V_41 = V_82 | V_83 ;
}
F_24 ( & V_60 ) ;
return V_41 ;
}
static int F_32 ( struct V_85 * V_85 , struct V_51 * V_51 )
{
struct V_53 * V_54 ;
int V_86 ;
if ( ( V_51 -> V_62 & V_87 ) == V_88 )
return 0 ;
V_86 = F_9 ( V_23 ,
V_89 ) ;
if ( V_86 )
return V_86 ;
V_54 = F_16 ( sizeof( struct V_53 ) , V_44 ) ;
if ( ! V_54 )
return - V_45 ;
F_33 ( & V_54 -> V_59 ) ;
F_23 ( & V_60 ) ;
V_54 -> V_3 = V_20 ;
V_54 -> V_61 = V_17 ;
F_24 ( & V_60 ) ;
V_51 -> V_55 = V_54 ;
return 0 ;
}
static int F_34 ( struct V_85 * V_85 , struct V_51 * V_51 )
{
struct V_53 * V_54 = V_51 -> V_55 ;
if ( ! V_54 )
return 0 ;
F_35 ( & V_54 -> V_59 ) ;
F_20 ( V_54 ) ;
return 0 ;
}
void F_36 ( void )
{
F_37 ( V_4 ) ;
F_37 ( V_21 ) ;
F_37 ( V_20 ) ;
F_37 ( V_19 ) ;
F_38 ( log ) ;
F_39 ( log , V_10 ) ;
F_39 ( log , V_5 ) ;
F_39 ( log , V_2 ) ;
F_39 ( log , V_12 ) ;
}
static int T_9 F_40 ( char * V_90 )
{
unsigned V_14 = F_41 ( V_90 , & V_90 ) ;
if ( V_14 )
V_14 = F_42 ( V_14 ) ;
if ( V_14 > V_21 )
V_91 = V_14 ;
return 0 ;
}
void T_9 F_43 ( int V_92 )
{
unsigned long V_9 ;
char * V_93 ;
int free ;
if ( ! V_91 )
return;
if ( V_92 ) {
unsigned long V_94 ;
V_94 = F_44 ( V_91 , V_95 ) ;
if ( ! V_94 )
return;
V_93 = F_45 ( V_94 ) ;
} else {
V_93 = F_46 ( V_91 ) ;
}
if ( F_47 ( ! V_93 ) ) {
F_48 ( L_7 ,
V_91 ) ;
return;
}
F_49 ( & V_60 , V_9 ) ;
V_21 = V_91 ;
V_4 = V_93 ;
V_91 = 0 ;
free = V_96 - V_19 ;
memcpy ( V_4 , V_97 , V_96 ) ;
F_50 ( & V_60 , V_9 ) ;
F_51 ( L_8 , V_21 ) ;
F_51 ( L_9 ,
free , ( free * 100 ) / V_96 ) ;
}
static int T_9 F_52 ( char * V_90 )
{
V_98 = 1 ;
F_53 ( V_99 L_10 ) ;
return 0 ;
}
static int T_9 F_54 ( char * V_90 )
{
unsigned long V_100 ;
V_100 = V_101 ? V_101 : 1000000 ;
V_102 = ( unsigned long long ) V_100 / 1000 * V_103 ;
F_55 ( & V_90 , & V_104 ) ;
if ( V_104 > 10 * 1000 )
V_104 = 0 ;
F_56 ( L_11
L_12 ,
V_104 , V_101 , V_100 , V_103 , V_102 ) ;
return 1 ;
}
static void F_57 ( int V_7 )
{
unsigned long long V_105 ;
unsigned long V_106 ;
if ( ( V_104 == 0 || V_107 != V_108 )
|| ( V_7 >= V_109 && ! V_98 ) ) {
return;
}
V_105 = ( unsigned long long ) V_102 * V_104 ;
V_106 = V_110 + F_58 ( V_104 ) ;
while ( V_105 ) {
V_105 -- ;
F_59 () ;
if ( F_60 ( V_110 , V_106 ) )
break;
F_61 () ;
}
}
static inline void F_57 ( int V_7 )
{
}
static T_6 F_62 ( T_2 V_111 , char * V_38 )
{
unsigned long V_112 ;
if ( ! V_113 )
return 0 ;
V_112 = F_26 ( V_111 , 1000000000 ) ;
if ( ! V_38 )
return snprintf ( NULL , 0 , L_13 , ( unsigned long ) V_111 ) ;
return sprintf ( V_38 , L_14 ,
( unsigned long ) V_111 , V_112 / 1000 ) ;
}
static T_6 F_63 ( const struct log * V_1 , bool V_114 , char * V_38 )
{
T_6 V_5 = 0 ;
unsigned int V_115 = ( V_1 -> V_6 << 3 ) | V_1 -> V_7 ;
if ( V_114 ) {
if ( V_38 ) {
V_5 += sprintf ( V_38 , L_15 , V_115 ) ;
} else {
V_5 += 3 ;
if ( V_115 > 999 )
V_5 += 3 ;
else if ( V_115 > 99 )
V_5 += 2 ;
else if ( V_115 > 9 )
V_5 ++ ;
}
}
V_5 += F_62 ( V_1 -> V_10 , V_38 ? V_38 + V_5 : NULL ) ;
return V_5 ;
}
static T_6 F_64 ( const struct log * V_1 , enum V_8 V_68 ,
bool V_114 , char * V_38 , T_6 V_14 )
{
const char * V_13 = F_1 ( V_1 ) ;
T_6 V_116 = V_1 -> V_2 ;
bool V_115 = true ;
bool V_117 = true ;
T_6 V_5 = 0 ;
if ( ( V_68 & V_67 ) && ! ( V_1 -> V_9 & V_69 ) )
V_115 = false ;
if ( V_1 -> V_9 & V_67 ) {
if ( ( V_68 & V_67 ) && ! ( V_68 & V_118 ) )
V_115 = false ;
if ( ! ( V_1 -> V_9 & V_118 ) )
V_117 = false ;
}
do {
const char * V_119 = memchr ( V_13 , '\n' , V_116 ) ;
T_6 V_2 ;
if ( V_119 ) {
V_2 = V_119 - V_13 ;
V_119 ++ ;
V_116 -= V_119 - V_13 ;
} else {
V_2 = V_116 ;
}
if ( V_38 ) {
if ( F_63 ( V_1 , V_114 , NULL ) +
V_2 + 1 >= V_14 - V_5 )
break;
if ( V_115 )
V_5 += F_63 ( V_1 , V_114 , V_38 + V_5 ) ;
memcpy ( V_38 + V_5 , V_13 , V_2 ) ;
V_5 += V_2 ;
if ( V_119 || V_117 )
V_38 [ V_5 ++ ] = '\n' ;
} else {
if ( V_115 )
V_5 += F_63 ( V_1 , V_114 , NULL ) ;
V_5 += V_2 ;
if ( V_119 || V_117 )
V_5 ++ ;
}
V_115 = true ;
V_13 = V_119 ;
} while ( V_13 );
return V_5 ;
}
static int F_65 ( char T_7 * V_38 , int V_14 )
{
char * V_13 ;
struct log * V_1 ;
int V_5 = 0 ;
V_13 = F_16 ( V_42 + V_120 , V_44 ) ;
if ( ! V_13 )
return - V_45 ;
while ( V_14 > 0 ) {
T_6 V_121 ;
T_6 V_122 ;
F_23 ( & V_60 ) ;
if ( V_123 < V_17 ) {
V_123 = V_17 ;
V_124 = V_20 ;
V_125 = 0 ;
V_126 = 0 ;
}
if ( V_123 == V_18 ) {
F_24 ( & V_60 ) ;
break;
}
V_122 = V_126 ;
V_1 = F_3 ( V_124 ) ;
V_121 = F_64 ( V_1 , V_125 , true , V_13 ,
V_42 + V_120 ) ;
if ( V_121 - V_126 <= V_14 ) {
V_124 = F_4 ( V_124 ) ;
V_123 ++ ;
V_125 = V_1 -> V_9 ;
V_121 -= V_126 ;
V_126 = 0 ;
} else if ( ! V_5 ) {
V_121 = V_14 ;
V_126 += V_121 ;
} else
V_121 = 0 ;
F_24 ( & V_60 ) ;
if ( ! V_121 )
break;
if ( F_27 ( V_38 , V_13 + V_122 , V_121 ) ) {
if ( ! V_5 )
V_5 = - V_48 ;
break;
}
V_5 += V_121 ;
V_14 -= V_121 ;
V_38 += V_121 ;
}
F_20 ( V_13 ) ;
return V_5 ;
}
static int F_66 ( char T_7 * V_38 , int V_14 , bool V_127 )
{
char * V_13 ;
int V_5 = 0 ;
V_13 = F_16 ( V_42 + V_120 , V_44 ) ;
if ( ! V_13 )
return - V_45 ;
F_23 ( & V_60 ) ;
if ( V_38 ) {
T_2 V_128 ;
T_2 V_61 ;
T_1 V_3 ;
enum V_8 V_68 ;
if ( V_77 < V_17 ) {
V_77 = V_17 ;
V_76 = V_20 ;
}
V_61 = V_77 ;
V_3 = V_76 ;
V_68 = 0 ;
while ( V_61 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_5 += F_64 ( V_1 , V_68 , true , NULL , 0 ) ;
V_68 = V_1 -> V_9 ;
V_3 = F_4 ( V_3 ) ;
V_61 ++ ;
}
V_61 = V_77 ;
V_3 = V_76 ;
V_68 = 0 ;
while ( V_5 > V_14 && V_61 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_5 -= F_64 ( V_1 , V_68 , true , NULL , 0 ) ;
V_68 = V_1 -> V_9 ;
V_3 = F_4 ( V_3 ) ;
V_61 ++ ;
}
V_128 = V_18 ;
V_5 = 0 ;
V_68 = 0 ;
while ( V_5 >= 0 && V_61 < V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
int V_129 ;
V_129 = F_64 ( V_1 , V_68 , true , V_13 ,
V_42 + V_120 ) ;
if ( V_129 < 0 ) {
V_5 = V_129 ;
break;
}
V_3 = F_4 ( V_3 ) ;
V_61 ++ ;
V_68 = V_1 -> V_9 ;
F_24 ( & V_60 ) ;
if ( F_27 ( V_38 + V_5 , V_13 , V_129 ) )
V_5 = - V_48 ;
else
V_5 += V_129 ;
F_23 ( & V_60 ) ;
if ( V_61 < V_17 ) {
V_61 = V_17 ;
V_3 = V_20 ;
V_68 = 0 ;
}
}
}
if ( V_127 ) {
V_77 = V_18 ;
V_76 = V_19 ;
}
F_24 ( & V_60 ) ;
F_20 ( V_13 ) ;
return V_5 ;
}
int F_67 ( int type , char T_7 * V_38 , int V_5 , bool V_25 )
{
bool V_127 = false ;
static int V_130 = - 1 ;
int error ;
error = F_9 ( type , V_25 ) ;
if ( error )
goto V_49;
error = F_13 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_131 :
break;
case V_26 :
break;
case V_132 :
error = - V_43 ;
if ( ! V_38 || V_5 < 0 )
goto V_49;
error = 0 ;
if ( ! V_5 )
goto V_49;
if ( ! F_68 ( V_133 , V_38 , V_5 ) ) {
error = - V_48 ;
goto V_49;
}
error = F_25 ( V_65 ,
V_123 != V_18 ) ;
if ( error )
goto V_49;
error = F_65 ( V_38 , V_5 ) ;
break;
case V_134 :
V_127 = true ;
case V_23 :
error = - V_43 ;
if ( ! V_38 || V_5 < 0 )
goto V_49;
error = 0 ;
if ( ! V_5 )
goto V_49;
if ( ! F_68 ( V_133 , V_38 , V_5 ) ) {
error = - V_48 ;
goto V_49;
}
error = F_66 ( V_38 , V_5 , V_127 ) ;
break;
case V_135 :
F_66 ( NULL , 0 , true ) ;
break;
case V_136 :
if ( V_130 == - 1 )
V_130 = V_109 ;
V_109 = V_137 ;
break;
case V_138 :
if ( V_130 != - 1 ) {
V_109 = V_130 ;
V_130 = - 1 ;
}
break;
case V_139 :
error = - V_43 ;
if ( V_5 < 1 || V_5 > 8 )
goto V_49;
if ( V_5 < V_137 )
V_5 = V_137 ;
V_109 = V_5 ;
V_130 = - 1 ;
error = 0 ;
break;
case V_140 :
F_23 ( & V_60 ) ;
if ( V_123 < V_17 ) {
V_123 = V_17 ;
V_124 = V_20 ;
V_125 = 0 ;
V_126 = 0 ;
}
if ( V_25 ) {
error = V_19 - V_124 ;
} else {
T_2 V_61 = V_123 ;
T_1 V_3 = V_124 ;
enum V_8 V_68 = V_125 ;
error = 0 ;
while ( V_61 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
error += F_64 ( V_1 , V_68 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_61 ++ ;
V_68 = V_1 -> V_9 ;
}
error -= V_126 ;
}
F_24 ( & V_60 ) ;
break;
case V_24 :
error = V_21 ;
break;
default:
error = - V_43 ;
break;
}
V_49:
return error ;
}
static void F_69 ( int V_7 , const char * V_13 , T_6 V_5 )
{
struct V_141 * V_142 ;
F_70 ( V_13 , V_5 ) ;
if ( V_7 >= V_109 && ! V_98 )
return;
if ( ! V_143 )
return;
F_71 (con) {
if ( V_144 && V_142 != V_144 )
continue;
if ( ! ( V_142 -> V_9 & V_145 ) )
continue;
if ( ! V_142 -> V_146 )
continue;
if ( ! F_72 ( F_73 () ) &&
! ( V_142 -> V_9 & V_147 ) )
continue;
V_142 -> V_146 ( V_142 , V_13 , V_5 ) ;
}
}
static void F_74 ( void )
{
static unsigned long V_148 ;
if ( F_75 ( V_110 , V_148 ) &&
! F_60 ( V_110 , V_148 + 30 * V_103 ) )
return;
V_148 = V_110 ;
F_76 () ;
F_77 ( & V_60 ) ;
F_78 ( & V_149 , 1 ) ;
}
static int F_79 ( void )
{
struct V_141 * V_142 ;
F_71 (con)
if ( V_142 -> V_9 & V_147 )
return 1 ;
return 0 ;
}
static inline int F_80 ( unsigned int V_150 )
{
return F_72 ( V_150 ) || F_79 () ;
}
static int F_81 ( unsigned int V_150 )
__releases( &logbuf_lock
static inline void F_82 ( void )
{
if ( F_47 ( V_151 ) ) {
int V_152 = V_151 ;
while ( V_152 -- ) {
F_83 ( 1 ) ;
F_61 () ;
}
}
}
static void F_84 ( enum V_8 V_9 )
{
if ( V_57 . V_153 )
return;
if ( V_57 . V_5 == 0 )
return;
if ( V_57 . V_154 ) {
F_5 ( V_57 . V_6 , V_57 . V_7 , V_9 | V_155 ,
V_57 . V_10 , NULL , 0 , V_57 . V_38 , V_57 . V_5 ) ;
V_57 . V_9 = V_9 ;
V_57 . V_153 = true ;
} else {
F_5 ( V_57 . V_6 , V_57 . V_7 , V_9 , 0 ,
NULL , 0 , V_57 . V_38 , V_57 . V_5 ) ;
V_57 . V_5 = 0 ;
}
}
static bool F_85 ( int V_6 , int V_7 , const char * V_13 , T_6 V_5 )
{
if ( V_57 . V_5 && V_57 . V_153 )
return false ;
if ( V_57 . V_5 + V_5 > sizeof( V_57 . V_38 ) ) {
F_84 ( V_67 ) ;
return false ;
}
if ( ! V_57 . V_5 ) {
V_57 . V_6 = V_6 ;
V_57 . V_7 = V_7 ;
V_57 . V_156 = V_29 ;
V_57 . V_10 = F_7 () ;
V_57 . V_9 = 0 ;
V_57 . V_154 = 0 ;
V_57 . V_153 = false ;
}
memcpy ( V_57 . V_38 + V_57 . V_5 , V_13 , V_5 ) ;
V_57 . V_5 += V_5 ;
if ( V_57 . V_5 > ( sizeof( V_57 . V_38 ) * 80 ) / 100 )
F_84 ( V_67 ) ;
return true ;
}
static T_6 F_86 ( char * V_13 , T_6 V_14 )
{
T_6 V_129 = 0 ;
T_6 V_5 ;
if ( V_57 . V_154 == 0 && ( V_157 & V_118 ) ) {
V_129 += F_62 ( V_57 . V_10 , V_13 ) ;
V_14 -= V_129 ;
}
V_5 = V_57 . V_5 - V_57 . V_154 ;
if ( V_5 > 0 ) {
if ( V_5 + 1 > V_14 )
V_5 = V_14 - 1 ;
memcpy ( V_13 + V_129 , V_57 . V_38 + V_57 . V_154 , V_5 ) ;
V_129 += V_5 ;
V_57 . V_154 = V_57 . V_5 ;
}
if ( V_57 . V_153 ) {
if ( V_57 . V_9 & V_118 )
V_13 [ V_129 ++ ] = '\n' ;
V_57 . V_5 = 0 ;
}
return V_129 ;
}
T_10 int F_87 ( int V_6 , int V_7 ,
const char * V_11 , T_6 V_158 ,
const char * V_159 , T_11 args )
{
static int V_160 ;
static char V_161 [ V_42 ] ;
char * V_13 = V_161 ;
T_6 V_2 ;
enum V_8 V_162 = 0 ;
unsigned long V_9 ;
int V_163 ;
int V_164 = 0 ;
F_57 ( V_7 ) ;
F_82 () ;
F_88 ( V_9 ) ;
V_163 = F_73 () ;
if ( F_47 ( V_165 == V_163 ) ) {
if ( ! V_166 && ! F_89 ( V_29 ) ) {
V_160 = 1 ;
goto V_167;
}
F_74 () ;
}
F_90 () ;
F_91 ( & V_60 ) ;
V_165 = V_163 ;
if ( V_160 ) {
static const char V_168 [] =
L_16 ;
V_160 = 0 ;
V_164 += strlen ( V_168 ) ;
F_5 ( 0 , 2 , V_69 | V_118 , 0 ,
NULL , 0 , V_168 , V_164 ) ;
}
V_2 = F_92 ( V_13 , sizeof( V_161 ) , V_159 , args ) ;
if ( V_2 && V_13 [ V_2 - 1 ] == '\n' ) {
V_2 -- ;
V_162 |= V_118 ;
}
if ( V_6 == 0 ) {
int V_169 = F_93 ( V_13 ) ;
if ( V_169 ) {
const char * V_170 = F_94 ( V_13 ) ;
switch ( V_169 ) {
case '0' ... '7' :
if ( V_7 == - 1 )
V_7 = V_169 - '0' ;
case 'd' :
V_162 |= V_69 ;
case 'c' :
break;
}
V_2 -= V_170 - V_13 ;
V_13 = ( char * ) V_170 ;
}
}
if ( V_7 == - 1 )
V_7 = V_40 ;
if ( V_11 )
V_162 |= V_69 | V_118 ;
if ( ! ( V_162 & V_118 ) ) {
if ( V_57 . V_5 && ( V_162 & V_69 || V_57 . V_156 != V_29 ) )
F_84 ( V_118 ) ;
if ( ! F_85 ( V_6 , V_7 , V_13 , V_2 ) )
F_5 ( V_6 , V_7 , V_162 | V_67 , 0 ,
V_11 , V_158 , V_13 , V_2 ) ;
} else {
bool V_171 = false ;
if ( V_57 . V_5 && V_57 . V_156 == V_29 ) {
if ( ! ( V_162 & V_69 ) )
V_171 = F_85 ( V_6 , V_7 , V_13 , V_2 ) ;
F_84 ( V_118 ) ;
}
if ( ! V_171 )
F_5 ( V_6 , V_7 , V_162 , 0 ,
V_11 , V_158 , V_13 , V_2 ) ;
}
V_164 += V_2 ;
if ( F_81 ( V_163 ) )
F_95 () ;
F_96 () ;
V_167:
F_97 ( V_9 ) ;
return V_164 ;
}
T_10 int F_98 ( const char * V_159 , T_11 args )
{
return F_87 ( 0 , - 1 , NULL , 0 , V_159 , args ) ;
}
T_10 int F_19 ( int V_6 , int V_7 ,
const char * V_11 , T_6 V_158 ,
const char * V_159 , ... )
{
T_11 args ;
int V_172 ;
va_start ( args , V_159 ) ;
V_172 = F_87 ( V_6 , V_7 , V_11 , V_158 , V_159 , args ) ;
va_end ( args ) ;
return V_172 ;
}
T_10 int F_53 ( const char * V_159 , ... )
{
T_11 args ;
int V_172 ;
#ifdef F_99
if ( F_47 ( V_173 ) ) {
va_start ( args , V_159 ) ;
V_172 = F_100 ( V_159 , args ) ;
va_end ( args ) ;
return V_172 ;
}
#endif
va_start ( args , V_159 ) ;
V_172 = F_87 ( 0 , - 1 , NULL , 0 , V_159 , args ) ;
va_end ( args ) ;
return V_172 ;
}
static struct log * F_3 ( T_1 V_3 ) { return NULL ; }
static T_1 F_4 ( T_1 V_3 ) { return 0 ; }
static void F_69 ( int V_7 , const char * V_13 , T_6 V_5 ) {}
static T_6 F_64 ( const struct log * V_1 , enum V_8 V_68 ,
bool V_114 , char * V_38 , T_6 V_14 ) { return 0 ; }
static T_6 F_86 ( char * V_13 , T_6 V_14 ) { return 0 ; }
void F_101 ( const char * V_159 , T_11 V_174 )
{
if ( V_175 ) {
char V_38 [ 512 ] ;
int V_121 = F_92 ( V_38 , sizeof( V_38 ) , V_159 , V_174 ) ;
V_175 -> V_146 ( V_175 , V_38 , V_121 ) ;
}
}
T_10 void F_102 ( const char * V_159 , ... )
{
T_11 V_174 ;
va_start ( V_174 , V_159 ) ;
F_101 ( V_159 , V_174 ) ;
va_end ( V_174 ) ;
}
static int F_103 ( char * V_176 , int V_3 , char * V_177 ,
char * V_178 )
{
struct V_179 * V_70 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_180 && V_179 [ V_39 ] . V_176 [ 0 ] ; V_39 ++ )
if ( strcmp ( V_179 [ V_39 ] . V_176 , V_176 ) == 0 &&
V_179 [ V_39 ] . V_181 == V_3 ) {
if ( ! V_178 )
V_182 = V_39 ;
return 0 ;
}
if ( V_39 == V_180 )
return - V_183 ;
if ( ! V_178 )
V_182 = V_39 ;
V_70 = & V_179 [ V_39 ] ;
F_104 ( V_70 -> V_176 , V_176 , sizeof( V_70 -> V_176 ) ) ;
V_70 -> V_177 = V_177 ;
#ifdef F_105
V_70 -> V_178 = V_178 ;
#endif
V_70 -> V_181 = V_3 ;
return 0 ;
}
static int T_9 F_106 ( char * V_90 )
{
char V_38 [ sizeof( V_179 [ 0 ] . V_176 ) + 4 ] ;
char * V_184 , * V_177 , * V_178 = NULL ;
int V_3 ;
#ifdef F_105
if ( ! memcmp ( V_90 , L_17 , 4 ) ) {
V_178 = L_18 ;
V_90 += 4 ;
} else if ( ! memcmp ( V_90 , L_19 , 4 ) ) {
V_178 = V_90 + 4 ;
V_90 = strchr ( V_178 , ',' ) ;
if ( ! V_90 ) {
F_53 ( V_185 L_20 ) ;
return 1 ;
}
* ( V_90 ++ ) = 0 ;
}
#endif
if ( V_90 [ 0 ] >= '0' && V_90 [ 0 ] <= '9' ) {
strcpy ( V_38 , L_21 ) ;
strncpy ( V_38 + 4 , V_90 , sizeof( V_38 ) - 5 ) ;
} else {
strncpy ( V_38 , V_90 , sizeof( V_38 ) - 1 ) ;
}
V_38 [ sizeof( V_38 ) - 1 ] = 0 ;
if ( ( V_177 = strchr ( V_90 , ',' ) ) != NULL )
* ( V_177 ++ ) = 0 ;
#ifdef F_107
if ( ! strcmp ( V_90 , L_22 ) )
strcpy ( V_38 , L_23 ) ;
if ( ! strcmp ( V_90 , L_24 ) )
strcpy ( V_38 , L_25 ) ;
#endif
for ( V_184 = V_38 ; * V_184 ; V_184 ++ )
if ( ( * V_184 >= '0' && * V_184 <= '9' ) || * V_184 == ',' )
break;
V_3 = F_18 ( V_184 , NULL , 10 ) ;
* V_184 = 0 ;
F_103 ( V_38 , V_3 , V_177 , V_178 ) ;
V_186 = 1 ;
return 1 ;
}
int F_108 ( char * V_176 , int V_3 , char * V_177 )
{
return F_103 ( V_176 , V_3 , V_177 , NULL ) ;
}
int F_109 ( char * V_176 , int V_3 , char * V_187 , int V_188 , char * V_177 )
{
struct V_179 * V_70 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_180 && V_179 [ V_39 ] . V_176 [ 0 ] ; V_39 ++ )
if ( strcmp ( V_179 [ V_39 ] . V_176 , V_176 ) == 0 &&
V_179 [ V_39 ] . V_181 == V_3 ) {
V_70 = & V_179 [ V_39 ] ;
F_104 ( V_70 -> V_176 , V_187 , sizeof( V_70 -> V_176 ) ) ;
V_70 -> V_176 [ sizeof( V_70 -> V_176 ) - 1 ] = 0 ;
V_70 -> V_177 = V_177 ;
V_70 -> V_181 = V_188 ;
return V_39 ;
}
return - 1 ;
}
static int T_9 F_110 ( char * V_90 )
{
V_189 = 0 ;
return 1 ;
}
void F_111 ( void )
{
if ( ! V_189 )
return;
F_53 ( L_26 ) ;
F_112 () ;
V_190 = 1 ;
F_113 ( & V_149 ) ;
}
void F_114 ( void )
{
if ( ! V_189 )
return;
F_115 ( & V_149 ) ;
V_190 = 0 ;
F_95 () ;
}
static int T_12 F_116 ( struct V_191 * V_192 ,
unsigned long V_193 , void * V_194 )
{
switch ( V_193 ) {
case V_195 :
case V_196 :
case V_197 :
case V_198 :
F_112 () ;
F_95 () ;
}
return V_199 ;
}
void F_112 ( void )
{
F_117 () ;
F_115 ( & V_149 ) ;
if ( V_190 )
return;
V_200 = 1 ;
V_201 = 1 ;
F_118 ( & V_202 , 0 , 0 , V_203 ) ;
}
int F_119 ( void )
{
if ( F_120 ( & V_149 ) )
return 0 ;
if ( V_190 ) {
F_113 ( & V_149 ) ;
return 0 ;
}
V_200 = 1 ;
V_201 = 0 ;
F_118 ( & V_202 , 0 , 1 , V_203 ) ;
return 1 ;
}
int F_121 ( void )
{
return V_200 ;
}
static void F_122 ( char * V_13 , T_6 V_14 )
{
unsigned long V_9 ;
T_6 V_5 ;
F_49 ( & V_60 , V_9 ) ;
if ( ! V_57 . V_5 )
goto V_49;
if ( V_204 < V_18 && ! V_57 . V_154 )
goto V_49;
V_5 = F_86 ( V_13 , V_14 ) ;
F_123 ( & V_60 ) ;
F_124 () ;
F_69 ( V_57 . V_7 , V_13 , V_5 ) ;
F_125 () ;
F_97 ( V_9 ) ;
return;
V_49:
F_50 ( & V_60 , V_9 ) ;
}
void F_95 ( void )
{
static char V_13 [ V_42 + V_120 ] ;
static T_2 V_205 ;
unsigned long V_9 ;
bool V_206 = false ;
bool V_207 ;
if ( V_190 ) {
F_113 ( & V_149 ) ;
return;
}
V_201 = 0 ;
F_122 ( V_13 , sizeof( V_13 ) ) ;
V_208:
for (; ; ) {
struct log * V_1 ;
T_6 V_5 ;
int V_7 ;
F_49 ( & V_60 , V_9 ) ;
if ( V_205 != V_18 ) {
V_206 = true ;
V_205 = V_18 ;
}
if ( V_204 < V_17 ) {
V_204 = V_17 ;
V_209 = V_20 ;
V_157 = 0 ;
}
V_122:
if ( V_204 == V_18 )
break;
V_1 = F_3 ( V_209 ) ;
if ( V_1 -> V_9 & V_155 ) {
V_209 = F_4 ( V_209 ) ;
V_204 ++ ;
V_1 -> V_9 &= ~ V_155 ;
V_157 = V_1 -> V_9 ;
goto V_122;
}
V_7 = V_1 -> V_7 ;
V_5 = F_64 ( V_1 , V_157 , false ,
V_13 , sizeof( V_13 ) ) ;
V_209 = F_4 ( V_209 ) ;
V_204 ++ ;
V_157 = V_1 -> V_9 ;
F_123 ( & V_60 ) ;
F_124 () ;
F_69 ( V_7 , V_13 , V_5 ) ;
F_125 () ;
F_97 ( V_9 ) ;
}
V_200 = 0 ;
F_126 ( & V_202 , 1 , V_203 ) ;
if ( F_47 ( V_144 ) )
V_144 = NULL ;
F_123 ( & V_60 ) ;
F_113 ( & V_149 ) ;
F_91 ( & V_60 ) ;
V_207 = V_204 != V_18 ;
F_50 ( & V_60 , V_9 ) ;
if ( V_207 && F_119 () )
goto V_208;
if ( V_206 )
F_127 () ;
}
void T_13 F_128 ( void )
{
if ( V_201 )
F_129 () ;
}
void F_130 ( void )
{
struct V_141 * V_70 ;
if ( V_166 ) {
if ( F_120 ( & V_149 ) != 0 )
return;
} else
F_112 () ;
V_200 = 1 ;
V_201 = 0 ;
F_71 (c)
if ( ( V_70 -> V_9 & V_145 ) && V_70 -> V_210 )
V_70 -> V_210 () ;
F_95 () ;
}
struct V_211 * F_131 ( int * V_181 )
{
struct V_141 * V_70 ;
struct V_211 * V_212 = NULL ;
F_112 () ;
F_71 (c) {
if ( ! V_70 -> V_213 )
continue;
V_212 = V_70 -> V_213 ( V_70 , V_181 ) ;
if ( V_212 )
break;
}
F_95 () ;
return V_212 ;
}
void F_132 ( struct V_141 * V_141 )
{
F_112 () ;
V_141 -> V_9 &= ~ V_145 ;
F_95 () ;
}
void F_133 ( struct V_141 * V_141 )
{
F_112 () ;
V_141 -> V_9 |= V_145 ;
F_95 () ;
}
static int T_9 F_134 ( char * V_90 )
{
V_214 = 1 ;
F_53 ( V_99 L_27 ) ;
return 0 ;
}
void F_135 ( struct V_141 * V_215 )
{
int V_39 ;
unsigned long V_9 ;
struct V_141 * V_216 = NULL ;
if ( V_143 && V_215 -> V_9 & V_217 ) {
F_71 (bcon) {
if ( ! ( V_216 -> V_9 & V_217 ) ) {
F_53 ( V_99 L_28 ,
V_215 -> V_176 , V_215 -> V_181 ) ;
return;
}
}
}
if ( V_143 && V_143 -> V_9 & V_217 )
V_216 = V_143 ;
if ( V_218 < 0 || V_216 || ! V_143 )
V_218 = V_182 ;
if ( V_215 -> V_219 )
V_215 -> V_219 () ;
if ( V_218 < 0 ) {
if ( V_215 -> V_181 < 0 )
V_215 -> V_181 = 0 ;
if ( V_215 -> V_220 == NULL ||
V_215 -> V_220 ( V_215 , NULL ) == 0 ) {
V_215 -> V_9 |= V_145 ;
if ( V_215 -> V_213 ) {
V_215 -> V_9 |= V_221 ;
V_218 = 0 ;
}
}
}
for ( V_39 = 0 ; V_39 < V_180 && V_179 [ V_39 ] . V_176 [ 0 ] ;
V_39 ++ ) {
if ( strcmp ( V_179 [ V_39 ] . V_176 , V_215 -> V_176 ) != 0 )
continue;
if ( V_215 -> V_181 >= 0 &&
V_215 -> V_181 != V_179 [ V_39 ] . V_181 )
continue;
if ( V_215 -> V_181 < 0 )
V_215 -> V_181 = V_179 [ V_39 ] . V_181 ;
#ifdef F_105
if ( V_179 [ V_39 ] . V_178 ) {
V_215 -> V_9 |= V_222 ;
F_136 ( V_215 ,
V_179 [ V_39 ] . V_181 ,
V_179 [ V_39 ] . V_177 ,
V_179 [ V_39 ] . V_178 ) ;
return;
}
#endif
if ( V_215 -> V_220 &&
V_215 -> V_220 ( V_215 , V_179 [ V_39 ] . V_177 ) != 0 )
break;
V_215 -> V_9 |= V_145 ;
V_215 -> V_181 = V_179 [ V_39 ] . V_181 ;
if ( V_39 == V_182 ) {
V_215 -> V_9 |= V_221 ;
V_218 = V_182 ;
}
break;
}
if ( ! ( V_215 -> V_9 & V_145 ) )
return;
if ( V_216 && ( ( V_215 -> V_9 & ( V_221 | V_217 ) ) == V_221 ) )
V_215 -> V_9 &= ~ V_223 ;
F_112 () ;
if ( ( V_215 -> V_9 & V_221 ) || V_143 == NULL ) {
V_215 -> V_119 = V_143 ;
V_143 = V_215 ;
if ( V_215 -> V_119 )
V_215 -> V_119 -> V_9 &= ~ V_221 ;
} else {
V_215 -> V_119 = V_143 -> V_119 ;
V_143 -> V_119 = V_215 ;
}
if ( V_215 -> V_9 & V_223 ) {
F_49 ( & V_60 , V_9 ) ;
V_204 = V_123 ;
V_209 = V_124 ;
V_157 = V_125 ;
F_50 ( & V_60 , V_9 ) ;
V_144 = V_215 ;
}
F_95 () ;
F_137 () ;
if ( V_216 &&
( ( V_215 -> V_9 & ( V_221 | V_217 ) ) == V_221 ) &&
! V_214 ) {
F_53 ( V_99 L_29 ,
V_215 -> V_176 , V_215 -> V_181 ) ;
F_71 (bcon)
if ( V_216 -> V_9 & V_217 )
F_138 ( V_216 ) ;
} else {
F_53 ( V_99 L_30 ,
( V_215 -> V_9 & V_217 ) ? L_31 : L_18 ,
V_215 -> V_176 , V_215 -> V_181 ) ;
}
}
int F_138 ( struct V_141 * V_141 )
{
struct V_141 * V_224 , * V_225 ;
int V_226 = 1 ;
#ifdef F_105
if ( V_141 -> V_9 & V_222 )
return F_139 ( V_141 ) ;
#endif
F_112 () ;
if ( V_143 == V_141 ) {
V_143 = V_141 -> V_119 ;
V_226 = 0 ;
} else if ( V_143 ) {
for ( V_224 = V_143 -> V_119 , V_225 = V_143 ;
V_224 ; V_225 = V_224 , V_224 = V_225 -> V_119 ) {
if ( V_224 == V_141 ) {
V_225 -> V_119 = V_224 -> V_119 ;
V_226 = 0 ;
break;
}
}
}
if ( V_143 != NULL && V_141 -> V_9 & V_221 )
V_143 -> V_9 |= V_221 ;
F_95 () ;
F_137 () ;
return V_226 ;
}
static int T_9 F_140 ( void )
{
struct V_141 * V_142 ;
F_71 (con) {
if ( ! V_214 && V_142 -> V_9 & V_217 ) {
F_53 ( V_99 L_32 ,
V_142 -> V_176 , V_142 -> V_181 ) ;
F_138 ( V_142 ) ;
}
}
F_141 ( F_116 , 0 ) ;
return 0 ;
}
static void F_142 ( struct V_227 * V_227 )
{
int V_228 = F_143 ( V_229 , 0 ) ;
if ( V_228 & V_230 ) {
char * V_38 = F_144 ( V_231 ) ;
F_53 ( V_232 L_33 , V_38 ) ;
}
if ( V_228 & V_233 )
F_145 ( & V_65 ) ;
}
void F_127 ( void )
{
F_146 () ;
if ( F_147 ( & V_65 ) ) {
F_148 ( V_229 , V_233 ) ;
F_149 ( & F_144 ( V_234 ) ) ;
}
F_150 () ;
}
int F_151 ( const char * V_159 , ... )
{
unsigned long V_9 ;
T_11 args ;
char * V_38 ;
int V_172 ;
F_88 ( V_9 ) ;
V_38 = F_144 ( V_231 ) ;
va_start ( args , V_159 ) ;
V_172 = vsnprintf ( V_38 , V_235 , V_159 , args ) ;
va_end ( args ) ;
F_152 ( V_229 , V_230 ) ;
F_149 ( & F_144 ( V_234 ) ) ;
F_97 ( V_9 ) ;
return V_172 ;
}
int F_153 ( const char * V_236 )
{
return F_154 ( & V_237 , V_236 ) ;
}
bool F_155 ( unsigned long * V_238 ,
unsigned int V_239 )
{
if ( * V_238 == 0
|| ! F_156 ( V_110 , * V_238 ,
* V_238
+ F_58 ( V_239 ) ) ) {
* V_238 = V_110 ;
return true ;
}
return false ;
}
int F_157 ( struct V_240 * V_241 )
{
unsigned long V_9 ;
int V_86 = - V_242 ;
if ( ! V_241 -> V_243 )
return - V_43 ;
F_158 ( & V_244 , V_9 ) ;
if ( ! V_241 -> V_245 ) {
V_241 -> V_245 = 1 ;
F_159 ( & V_241 -> V_246 , & V_247 ) ;
V_86 = 0 ;
}
F_160 ( & V_244 , V_9 ) ;
return V_86 ;
}
int F_161 ( struct V_240 * V_241 )
{
unsigned long V_9 ;
int V_86 = - V_43 ;
F_158 ( & V_244 , V_9 ) ;
if ( V_241 -> V_245 ) {
V_241 -> V_245 = 0 ;
F_162 ( & V_241 -> V_246 ) ;
V_86 = 0 ;
}
F_160 ( & V_244 , V_9 ) ;
F_163 () ;
return V_86 ;
}
void F_164 ( enum V_248 V_249 )
{
struct V_240 * V_241 ;
unsigned long V_9 ;
if ( ( V_249 > V_250 ) && ! V_251 )
return;
F_165 () ;
F_166 (dumper, &dump_list, list) {
if ( V_241 -> V_252 && V_249 > V_241 -> V_252 )
continue;
V_241 -> V_253 = true ;
F_49 ( & V_60 , V_9 ) ;
V_241 -> V_254 = V_77 ;
V_241 -> V_255 = V_76 ;
V_241 -> V_128 = V_18 ;
V_241 -> V_256 = V_19 ;
F_50 ( & V_60 , V_9 ) ;
V_241 -> V_243 ( V_241 , V_249 ) ;
V_241 -> V_253 = false ;
}
F_167 () ;
}
bool F_168 ( struct V_240 * V_241 , bool V_114 ,
char * line , T_6 V_14 , T_6 * V_5 )
{
struct log * V_1 ;
T_6 V_257 = 0 ;
bool V_41 = false ;
if ( ! V_241 -> V_253 )
goto V_49;
if ( V_241 -> V_254 < V_17 ) {
V_241 -> V_254 = V_17 ;
V_241 -> V_255 = V_20 ;
}
if ( V_241 -> V_254 >= V_18 )
goto V_49;
V_1 = F_3 ( V_241 -> V_255 ) ;
V_257 = F_64 ( V_1 , 0 , V_114 , line , V_14 ) ;
V_241 -> V_255 = F_4 ( V_241 -> V_255 ) ;
V_241 -> V_254 ++ ;
V_41 = true ;
V_49:
if ( V_5 )
* V_5 = V_257 ;
return V_41 ;
}
bool F_169 ( struct V_240 * V_241 , bool V_114 ,
char * line , T_6 V_14 , T_6 * V_5 )
{
unsigned long V_9 ;
bool V_41 ;
F_49 ( & V_60 , V_9 ) ;
V_41 = F_168 ( V_241 , V_114 , line , V_14 , V_5 ) ;
F_50 ( & V_60 , V_9 ) ;
return V_41 ;
}
bool F_170 ( struct V_240 * V_241 , bool V_114 ,
char * V_38 , T_6 V_14 , T_6 * V_5 )
{
unsigned long V_9 ;
T_2 V_61 ;
T_1 V_3 ;
T_2 V_128 ;
T_1 V_256 ;
enum V_8 V_68 ;
T_6 V_257 = 0 ;
bool V_41 = false ;
if ( ! V_241 -> V_253 )
goto V_49;
F_49 ( & V_60 , V_9 ) ;
if ( V_241 -> V_254 < V_17 ) {
V_241 -> V_254 = V_17 ;
V_241 -> V_255 = V_20 ;
}
if ( V_241 -> V_254 >= V_241 -> V_128 ) {
F_50 ( & V_60 , V_9 ) ;
goto V_49;
}
V_61 = V_241 -> V_254 ;
V_3 = V_241 -> V_255 ;
V_68 = 0 ;
while ( V_61 < V_241 -> V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_257 += F_64 ( V_1 , V_68 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_61 ++ ;
V_68 = V_1 -> V_9 ;
}
V_61 = V_241 -> V_254 ;
V_3 = V_241 -> V_255 ;
V_68 = 0 ;
while ( V_257 > V_14 && V_61 < V_241 -> V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_257 -= F_64 ( V_1 , V_68 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_61 ++ ;
V_68 = V_1 -> V_9 ;
}
V_128 = V_61 ;
V_256 = V_3 ;
V_257 = 0 ;
V_68 = 0 ;
while ( V_61 < V_241 -> V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_257 += F_64 ( V_1 , V_68 , V_114 , V_38 + V_257 , V_14 - V_257 ) ;
V_3 = F_4 ( V_3 ) ;
V_61 ++ ;
V_68 = V_1 -> V_9 ;
}
V_241 -> V_128 = V_128 ;
V_241 -> V_256 = V_256 ;
V_41 = true ;
F_50 ( & V_60 , V_9 ) ;
V_49:
if ( V_5 )
* V_5 = V_257 ;
return V_41 ;
}
void F_171 ( struct V_240 * V_241 )
{
V_241 -> V_254 = V_77 ;
V_241 -> V_255 = V_76 ;
V_241 -> V_128 = V_18 ;
V_241 -> V_256 = V_19 ;
}
void F_172 ( struct V_240 * V_241 )
{
unsigned long V_9 ;
F_49 ( & V_60 , V_9 ) ;
F_171 ( V_241 ) ;
F_50 ( & V_60 , V_9 ) ;
}
void T_9 F_173 ( const char * V_159 , ... )
{
T_11 args ;
va_start ( args , V_159 ) ;
vsnprintf ( V_258 , sizeof( V_258 ) ,
V_159 , args ) ;
va_end ( args ) ;
}
void F_174 ( const char * V_259 )
{
F_53 ( L_34 ,
V_259 , F_175 () , V_29 -> V_260 , V_29 -> V_30 ,
F_176 () , F_177 () -> V_261 ,
( int ) strcspn ( F_177 () -> V_262 , L_35 ) ,
F_177 () -> V_262 ) ;
if ( V_258 [ 0 ] != '\0' )
F_53 ( L_36 ,
V_259 , V_258 ) ;
F_178 ( V_259 , V_29 ) ;
}
void F_179 ( const char * V_259 )
{
F_174 ( V_259 ) ;
F_53 ( L_37 ,
V_259 , V_29 , F_180 () ,
F_181 ( V_29 ) ) ;
}
