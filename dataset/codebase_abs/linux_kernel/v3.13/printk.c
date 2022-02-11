static char * F_1 ( const struct V_1 * V_2 )
{
return ( char * ) V_2 + sizeof( struct V_1 ) ;
}
static char * F_2 ( const struct V_1 * V_2 )
{
return ( char * ) V_2 + sizeof( struct V_1 ) + V_2 -> V_3 ;
}
static struct V_1 * F_3 ( T_1 V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_5 + V_4 ) ;
if ( ! V_2 -> V_6 )
return (struct V_1 * ) V_5 ;
return V_2 ;
}
static T_1 F_4 ( T_1 V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_5 + V_4 ) ;
if ( ! V_2 -> V_6 ) {
V_2 = (struct V_1 * ) V_5 ;
return V_2 -> V_6 ;
}
return V_4 + V_2 -> V_6 ;
}
static void F_5 ( int V_7 , int V_8 ,
enum V_9 V_10 , T_2 V_11 ,
const char * V_12 , T_3 V_13 ,
const char * V_14 , T_3 V_3 )
{
struct V_1 * V_2 ;
T_1 V_15 , V_16 ;
V_15 = sizeof( struct V_1 ) + V_3 + V_13 ;
V_16 = ( - V_15 ) & ( V_17 - 1 ) ;
V_15 += V_16 ;
while ( V_18 < V_19 ) {
T_1 free ;
if ( V_20 > V_21 )
free = F_6 ( V_22 - V_20 , V_21 ) ;
else
free = V_21 - V_20 ;
if ( free > V_15 + sizeof( struct V_1 ) )
break;
V_21 = F_4 ( V_21 ) ;
V_18 ++ ;
}
if ( V_20 + V_15 + sizeof( struct V_1 ) >= V_22 ) {
memset ( V_5 + V_20 , 0 , sizeof( struct V_1 ) ) ;
V_20 = 0 ;
}
V_2 = (struct V_1 * ) ( V_5 + V_20 ) ;
memcpy ( F_1 ( V_2 ) , V_14 , V_3 ) ;
V_2 -> V_3 = V_3 ;
memcpy ( F_2 ( V_2 ) , V_12 , V_13 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 & 7 ;
V_2 -> V_10 = V_10 & 0x1f ;
if ( V_11 > 0 )
V_2 -> V_11 = V_11 ;
else
V_2 -> V_11 = F_7 () ;
memset ( F_2 ( V_2 ) + V_13 , 0 , V_16 ) ;
V_2 -> V_6 = sizeof( struct V_1 ) + V_3 + V_13 + V_16 ;
V_20 += V_2 -> V_6 ;
V_19 ++ ;
}
static int F_8 ( int type )
{
if ( V_23 )
return 1 ;
return type != V_24 &&
type != V_25 ;
}
static int F_9 ( int type , bool V_26 )
{
if ( V_26 && type != V_27 )
return 0 ;
if ( F_8 ( type ) ) {
if ( F_10 ( V_28 ) )
return 0 ;
if ( F_10 ( V_29 ) ) {
F_11 ( L_1
L_2
L_3 ,
V_30 -> V_31 , F_12 ( V_30 ) ) ;
return 0 ;
}
return - V_32 ;
}
return F_13 ( type ) ;
}
static T_4 F_14 ( struct V_33 * V_34 , const struct V_35 * V_36 ,
unsigned long V_37 , T_5 V_38 )
{
char * V_39 , * line ;
int V_40 ;
int V_8 = V_41 ;
int V_7 = 1 ;
T_6 V_6 = F_15 ( V_36 , V_37 ) ;
T_4 V_42 = V_6 ;
if ( V_6 > V_43 )
return - V_44 ;
V_39 = F_16 ( V_6 + 1 , V_45 ) ;
if ( V_39 == NULL )
return - V_46 ;
line = V_39 ;
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
if ( F_17 ( line , V_36 [ V_40 ] . V_47 , V_36 [ V_40 ] . V_48 ) ) {
V_42 = - V_49 ;
goto V_50;
}
line += V_36 [ V_40 ] . V_48 ;
}
line = V_39 ;
if ( line [ 0 ] == '<' ) {
char * V_51 = NULL ;
V_40 = F_18 ( line + 1 , & V_51 , 10 ) ;
if ( V_51 && V_51 [ 0 ] == '>' ) {
V_8 = V_40 & 7 ;
if ( V_40 >> 3 )
V_7 = V_40 >> 3 ;
V_51 ++ ;
V_6 -= V_51 - line ;
line = V_51 ;
}
}
line [ V_6 ] = '\0' ;
F_19 ( V_7 , V_8 , NULL , 0 , L_4 , line ) ;
V_50:
F_20 ( V_39 ) ;
return V_42 ;
}
static T_4 F_21 ( struct V_52 * V_52 , char T_7 * V_39 ,
T_6 V_37 , T_5 * V_53 )
{
struct V_54 * V_55 = V_52 -> V_56 ;
struct V_1 * V_2 ;
T_2 V_57 ;
T_6 V_40 ;
char V_58 = '-' ;
T_6 V_6 ;
T_4 V_42 ;
if ( ! V_55 )
return - V_59 ;
V_42 = F_22 ( & V_55 -> V_60 ) ;
if ( V_42 )
return V_42 ;
F_23 ( & V_61 ) ;
while ( V_55 -> V_62 == V_19 ) {
if ( V_52 -> V_63 & V_64 ) {
V_42 = - V_65 ;
F_24 ( & V_61 ) ;
goto V_50;
}
F_24 ( & V_61 ) ;
V_42 = F_25 ( V_66 ,
V_55 -> V_62 != V_19 ) ;
if ( V_42 )
goto V_50;
F_23 ( & V_61 ) ;
}
if ( V_55 -> V_62 < V_18 ) {
V_55 -> V_4 = V_21 ;
V_55 -> V_62 = V_18 ;
V_42 = - V_67 ;
F_24 ( & V_61 ) ;
goto V_50;
}
V_2 = F_3 ( V_55 -> V_4 ) ;
V_57 = V_2 -> V_11 ;
F_26 ( V_57 , 1000 ) ;
if ( V_2 -> V_10 & V_68 && ! ( V_55 -> V_69 & V_68 ) )
V_58 = 'c' ;
else if ( ( V_2 -> V_10 & V_68 ) ||
( ( V_55 -> V_69 & V_68 ) && ! ( V_2 -> V_10 & V_70 ) ) )
V_58 = '+' ;
V_6 = sprintf ( V_55 -> V_39 , L_5 ,
( V_2 -> V_7 << 3 ) | V_2 -> V_8 ,
V_55 -> V_62 , V_57 , V_58 ) ;
V_55 -> V_69 = V_2 -> V_10 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_3 ; V_40 ++ ) {
unsigned char V_71 = F_1 ( V_2 ) [ V_40 ] ;
if ( V_71 < ' ' || V_71 >= 127 || V_71 == '\\' )
V_6 += sprintf ( V_55 -> V_39 + V_6 , L_6 , V_71 ) ;
else
V_55 -> V_39 [ V_6 ++ ] = V_71 ;
}
V_55 -> V_39 [ V_6 ++ ] = '\n' ;
if ( V_2 -> V_13 ) {
bool line = true ;
for ( V_40 = 0 ; V_40 < V_2 -> V_13 ; V_40 ++ ) {
unsigned char V_71 = F_2 ( V_2 ) [ V_40 ] ;
if ( line ) {
V_55 -> V_39 [ V_6 ++ ] = ' ' ;
line = false ;
}
if ( V_71 == '\0' ) {
V_55 -> V_39 [ V_6 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_71 < ' ' || V_71 >= 127 || V_71 == '\\' ) {
V_6 += sprintf ( V_55 -> V_39 + V_6 , L_6 , V_71 ) ;
continue;
}
V_55 -> V_39 [ V_6 ++ ] = V_71 ;
}
V_55 -> V_39 [ V_6 ++ ] = '\n' ;
}
V_55 -> V_4 = F_4 ( V_55 -> V_4 ) ;
V_55 -> V_62 ++ ;
F_24 ( & V_61 ) ;
if ( V_6 > V_37 ) {
V_42 = - V_44 ;
goto V_50;
}
if ( F_27 ( V_39 , V_55 -> V_39 , V_6 ) ) {
V_42 = - V_49 ;
goto V_50;
}
V_42 = V_6 ;
V_50:
F_28 ( & V_55 -> V_60 ) ;
return V_42 ;
}
static T_5 F_29 ( struct V_52 * V_52 , T_5 V_72 , int V_73 )
{
struct V_54 * V_55 = V_52 -> V_56 ;
T_5 V_42 = 0 ;
if ( ! V_55 )
return - V_59 ;
if ( V_72 )
return - V_74 ;
F_23 ( & V_61 ) ;
switch ( V_73 ) {
case V_75 :
V_55 -> V_4 = V_21 ;
V_55 -> V_62 = V_18 ;
break;
case V_76 :
V_55 -> V_4 = V_77 ;
V_55 -> V_62 = V_78 ;
break;
case V_79 :
V_55 -> V_4 = V_20 ;
V_55 -> V_62 = V_19 ;
break;
default:
V_42 = - V_44 ;
}
F_24 ( & V_61 ) ;
return V_42 ;
}
static unsigned int F_30 ( struct V_52 * V_52 , T_8 * V_80 )
{
struct V_54 * V_55 = V_52 -> V_56 ;
int V_42 = 0 ;
if ( ! V_55 )
return V_81 | V_82 ;
F_31 ( V_52 , & V_66 , V_80 ) ;
F_23 ( & V_61 ) ;
if ( V_55 -> V_62 < V_19 ) {
if ( V_55 -> V_62 < V_18 )
V_42 = V_83 | V_84 | V_81 | V_85 ;
else
V_42 = V_83 | V_84 ;
}
F_24 ( & V_61 ) ;
return V_42 ;
}
static int F_32 ( struct V_86 * V_86 , struct V_52 * V_52 )
{
struct V_54 * V_55 ;
int V_87 ;
if ( ( V_52 -> V_63 & V_88 ) == V_89 )
return 0 ;
V_87 = F_9 ( V_24 ,
V_90 ) ;
if ( V_87 )
return V_87 ;
V_55 = F_16 ( sizeof( struct V_54 ) , V_45 ) ;
if ( ! V_55 )
return - V_46 ;
F_33 ( & V_55 -> V_60 ) ;
F_23 ( & V_61 ) ;
V_55 -> V_4 = V_21 ;
V_55 -> V_62 = V_18 ;
F_24 ( & V_61 ) ;
V_52 -> V_56 = V_55 ;
return 0 ;
}
static int F_34 ( struct V_86 * V_86 , struct V_52 * V_52 )
{
struct V_54 * V_55 = V_52 -> V_56 ;
if ( ! V_55 )
return 0 ;
F_35 ( & V_55 -> V_60 ) ;
F_20 ( V_55 ) ;
return 0 ;
}
void F_36 ( void )
{
F_37 ( V_5 ) ;
F_37 ( V_22 ) ;
F_37 ( V_21 ) ;
F_37 ( V_20 ) ;
F_38 ( V_1 ) ;
F_39 ( V_1 , V_11 ) ;
F_39 ( V_1 , V_6 ) ;
F_39 ( V_1 , V_3 ) ;
F_39 ( V_1 , V_13 ) ;
}
static int T_9 F_40 ( char * V_91 )
{
unsigned V_15 = F_41 ( V_91 , & V_91 ) ;
if ( V_15 )
V_15 = F_42 ( V_15 ) ;
if ( V_15 > V_22 )
V_92 = V_15 ;
return 0 ;
}
void T_9 F_43 ( int V_93 )
{
unsigned long V_10 ;
char * V_94 ;
int free ;
if ( ! V_92 )
return;
if ( V_93 ) {
unsigned long V_95 ;
V_95 = F_44 ( V_92 , V_96 ) ;
if ( ! V_95 )
return;
V_94 = F_45 ( V_95 ) ;
} else {
V_94 = F_46 ( V_92 ) ;
}
if ( F_47 ( ! V_94 ) ) {
F_48 ( L_7 ,
V_92 ) ;
return;
}
F_49 ( & V_61 , V_10 ) ;
V_22 = V_92 ;
V_5 = V_94 ;
V_92 = 0 ;
free = V_97 - V_20 ;
memcpy ( V_5 , V_98 , V_97 ) ;
F_50 ( & V_61 , V_10 ) ;
F_51 ( L_8 , V_22 ) ;
F_51 ( L_9 ,
free , ( free * 100 ) / V_97 ) ;
}
static int T_9 F_52 ( char * V_91 )
{
V_99 = 1 ;
F_51 ( L_10 ) ;
return 0 ;
}
static int T_9 F_53 ( char * V_91 )
{
unsigned long V_100 ;
V_100 = V_101 ? V_101 : 1000000 ;
V_102 = ( unsigned long long ) V_100 / 1000 * V_103 ;
F_54 ( & V_91 , & V_104 ) ;
if ( V_104 > 10 * 1000 )
V_104 = 0 ;
F_55 ( L_11
L_12 ,
V_104 , V_101 , V_100 , V_103 , V_102 ) ;
return 0 ;
}
static void F_56 ( int V_8 )
{
unsigned long long V_105 ;
unsigned long V_106 ;
if ( ( V_104 == 0 || V_107 != V_108 )
|| ( V_8 >= V_109 && ! V_99 ) ) {
return;
}
V_105 = ( unsigned long long ) V_102 * V_104 ;
V_106 = V_110 + F_57 ( V_104 ) ;
while ( V_105 ) {
V_105 -- ;
F_58 () ;
if ( F_59 ( V_110 , V_106 ) )
break;
F_60 () ;
}
}
static inline void F_56 ( int V_8 )
{
}
static T_6 F_61 ( T_2 V_111 , char * V_39 )
{
unsigned long V_112 ;
if ( ! V_113 )
return 0 ;
V_112 = F_26 ( V_111 , 1000000000 ) ;
if ( ! V_39 )
return snprintf ( NULL , 0 , L_13 , ( unsigned long ) V_111 ) ;
return sprintf ( V_39 , L_14 ,
( unsigned long ) V_111 , V_112 / 1000 ) ;
}
static T_6 F_62 ( const struct V_1 * V_2 , bool V_114 , char * V_39 )
{
T_6 V_6 = 0 ;
unsigned int V_115 = ( V_2 -> V_7 << 3 ) | V_2 -> V_8 ;
if ( V_114 ) {
if ( V_39 ) {
V_6 += sprintf ( V_39 , L_15 , V_115 ) ;
} else {
V_6 += 3 ;
if ( V_115 > 999 )
V_6 += 3 ;
else if ( V_115 > 99 )
V_6 += 2 ;
else if ( V_115 > 9 )
V_6 ++ ;
}
}
V_6 += F_61 ( V_2 -> V_11 , V_39 ? V_39 + V_6 : NULL ) ;
return V_6 ;
}
static T_6 F_63 ( const struct V_1 * V_2 , enum V_9 V_69 ,
bool V_114 , char * V_39 , T_6 V_15 )
{
const char * V_14 = F_1 ( V_2 ) ;
T_6 V_116 = V_2 -> V_3 ;
bool V_115 = true ;
bool V_117 = true ;
T_6 V_6 = 0 ;
if ( ( V_69 & V_68 ) && ! ( V_2 -> V_10 & V_70 ) )
V_115 = false ;
if ( V_2 -> V_10 & V_68 ) {
if ( ( V_69 & V_68 ) && ! ( V_69 & V_118 ) )
V_115 = false ;
if ( ! ( V_2 -> V_10 & V_118 ) )
V_117 = false ;
}
do {
const char * V_119 = memchr ( V_14 , '\n' , V_116 ) ;
T_6 V_3 ;
if ( V_119 ) {
V_3 = V_119 - V_14 ;
V_119 ++ ;
V_116 -= V_119 - V_14 ;
} else {
V_3 = V_116 ;
}
if ( V_39 ) {
if ( F_62 ( V_2 , V_114 , NULL ) +
V_3 + 1 >= V_15 - V_6 )
break;
if ( V_115 )
V_6 += F_62 ( V_2 , V_114 , V_39 + V_6 ) ;
memcpy ( V_39 + V_6 , V_14 , V_3 ) ;
V_6 += V_3 ;
if ( V_119 || V_117 )
V_39 [ V_6 ++ ] = '\n' ;
} else {
if ( V_115 )
V_6 += F_62 ( V_2 , V_114 , NULL ) ;
V_6 += V_3 ;
if ( V_119 || V_117 )
V_6 ++ ;
}
V_115 = true ;
V_14 = V_119 ;
} while ( V_14 );
return V_6 ;
}
static int F_64 ( char T_7 * V_39 , int V_15 )
{
char * V_14 ;
struct V_1 * V_2 ;
int V_6 = 0 ;
V_14 = F_16 ( V_43 + V_120 , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
while ( V_15 > 0 ) {
T_6 V_121 ;
T_6 V_122 ;
F_23 ( & V_61 ) ;
if ( V_123 < V_18 ) {
V_123 = V_18 ;
V_124 = V_21 ;
V_125 = 0 ;
V_126 = 0 ;
}
if ( V_123 == V_19 ) {
F_24 ( & V_61 ) ;
break;
}
V_122 = V_126 ;
V_2 = F_3 ( V_124 ) ;
V_121 = F_63 ( V_2 , V_125 , true , V_14 ,
V_43 + V_120 ) ;
if ( V_121 - V_126 <= V_15 ) {
V_124 = F_4 ( V_124 ) ;
V_123 ++ ;
V_125 = V_2 -> V_10 ;
V_121 -= V_126 ;
V_126 = 0 ;
} else if ( ! V_6 ) {
V_121 = V_15 ;
V_126 += V_121 ;
} else
V_121 = 0 ;
F_24 ( & V_61 ) ;
if ( ! V_121 )
break;
if ( F_27 ( V_39 , V_14 + V_122 , V_121 ) ) {
if ( ! V_6 )
V_6 = - V_49 ;
break;
}
V_6 += V_121 ;
V_15 -= V_121 ;
V_39 += V_121 ;
}
F_20 ( V_14 ) ;
return V_6 ;
}
static int F_65 ( char T_7 * V_39 , int V_15 , bool V_127 )
{
char * V_14 ;
int V_6 = 0 ;
V_14 = F_16 ( V_43 + V_120 , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
F_23 ( & V_61 ) ;
if ( V_39 ) {
T_2 V_128 ;
T_2 V_62 ;
T_1 V_4 ;
enum V_9 V_69 ;
if ( V_78 < V_18 ) {
V_78 = V_18 ;
V_77 = V_21 ;
}
V_62 = V_78 ;
V_4 = V_77 ;
V_69 = 0 ;
while ( V_62 < V_19 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_6 += F_63 ( V_2 , V_69 , true , NULL , 0 ) ;
V_69 = V_2 -> V_10 ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
}
V_62 = V_78 ;
V_4 = V_77 ;
V_69 = 0 ;
while ( V_6 > V_15 && V_62 < V_19 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_6 -= F_63 ( V_2 , V_69 , true , NULL , 0 ) ;
V_69 = V_2 -> V_10 ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
}
V_128 = V_19 ;
V_6 = 0 ;
V_69 = 0 ;
while ( V_6 >= 0 && V_62 < V_128 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
int V_129 ;
V_129 = F_63 ( V_2 , V_69 , true , V_14 ,
V_43 + V_120 ) ;
if ( V_129 < 0 ) {
V_6 = V_129 ;
break;
}
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
F_24 ( & V_61 ) ;
if ( F_27 ( V_39 + V_6 , V_14 , V_129 ) )
V_6 = - V_49 ;
else
V_6 += V_129 ;
F_23 ( & V_61 ) ;
if ( V_62 < V_18 ) {
V_62 = V_18 ;
V_4 = V_21 ;
V_69 = 0 ;
}
}
}
if ( V_127 ) {
V_78 = V_19 ;
V_77 = V_20 ;
}
F_24 ( & V_61 ) ;
F_20 ( V_14 ) ;
return V_6 ;
}
int F_66 ( int type , char T_7 * V_39 , int V_6 , bool V_26 )
{
bool V_127 = false ;
static int V_130 = - 1 ;
int error ;
error = F_9 ( type , V_26 ) ;
if ( error )
goto V_50;
error = F_13 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_131 :
break;
case V_27 :
break;
case V_132 :
error = - V_44 ;
if ( ! V_39 || V_6 < 0 )
goto V_50;
error = 0 ;
if ( ! V_6 )
goto V_50;
if ( ! F_67 ( V_133 , V_39 , V_6 ) ) {
error = - V_49 ;
goto V_50;
}
error = F_25 ( V_66 ,
V_123 != V_19 ) ;
if ( error )
goto V_50;
error = F_64 ( V_39 , V_6 ) ;
break;
case V_134 :
V_127 = true ;
case V_24 :
error = - V_44 ;
if ( ! V_39 || V_6 < 0 )
goto V_50;
error = 0 ;
if ( ! V_6 )
goto V_50;
if ( ! F_67 ( V_133 , V_39 , V_6 ) ) {
error = - V_49 ;
goto V_50;
}
error = F_65 ( V_39 , V_6 , V_127 ) ;
break;
case V_135 :
F_65 ( NULL , 0 , true ) ;
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
error = - V_44 ;
if ( V_6 < 1 || V_6 > 8 )
goto V_50;
if ( V_6 < V_137 )
V_6 = V_137 ;
V_109 = V_6 ;
V_130 = - 1 ;
error = 0 ;
break;
case V_140 :
F_23 ( & V_61 ) ;
if ( V_123 < V_18 ) {
V_123 = V_18 ;
V_124 = V_21 ;
V_125 = 0 ;
V_126 = 0 ;
}
if ( V_26 ) {
error = V_20 - V_124 ;
} else {
T_2 V_62 = V_123 ;
T_1 V_4 = V_124 ;
enum V_9 V_69 = V_125 ;
error = 0 ;
while ( V_62 < V_19 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
error += F_63 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
error -= V_126 ;
}
F_24 ( & V_61 ) ;
break;
case V_25 :
error = V_22 ;
break;
default:
error = - V_44 ;
break;
}
V_50:
return error ;
}
static void F_68 ( int V_8 , const char * V_14 , T_6 V_6 )
{
struct V_141 * V_142 ;
F_69 ( V_14 , V_6 ) ;
if ( V_8 >= V_109 && ! V_99 )
return;
if ( ! V_143 )
return;
F_70 (con) {
if ( V_144 && V_142 != V_144 )
continue;
if ( ! ( V_142 -> V_10 & V_145 ) )
continue;
if ( ! V_142 -> V_146 )
continue;
if ( ! F_71 ( F_72 () ) &&
! ( V_142 -> V_10 & V_147 ) )
continue;
V_142 -> V_146 ( V_142 , V_14 , V_6 ) ;
}
}
static void F_73 ( void )
{
static unsigned long V_148 ;
if ( F_74 ( V_110 , V_148 ) &&
! F_59 ( V_110 , V_148 + 30 * V_103 ) )
return;
V_148 = V_110 ;
F_75 () ;
F_76 ( & V_61 ) ;
F_77 ( & V_149 , 1 ) ;
}
static int F_78 ( void )
{
struct V_141 * V_142 ;
F_70 (con)
if ( V_142 -> V_10 & V_147 )
return 1 ;
return 0 ;
}
static inline int F_79 ( unsigned int V_150 )
{
return F_71 ( V_150 ) || F_78 () ;
}
static int F_80 ( unsigned int V_150 )
__releases( &logbuf_lock
static inline void F_81 ( void )
{
if ( F_47 ( V_151 ) ) {
int V_152 = V_151 ;
while ( V_152 -- ) {
F_82 ( 1 ) ;
F_60 () ;
}
}
}
static void F_83 ( enum V_9 V_10 )
{
if ( V_58 . V_153 )
return;
if ( V_58 . V_6 == 0 )
return;
if ( V_58 . V_154 ) {
F_5 ( V_58 . V_7 , V_58 . V_8 , V_10 | V_155 ,
V_58 . V_11 , NULL , 0 , V_58 . V_39 , V_58 . V_6 ) ;
V_58 . V_10 = V_10 ;
V_58 . V_153 = true ;
} else {
F_5 ( V_58 . V_7 , V_58 . V_8 , V_10 , 0 ,
NULL , 0 , V_58 . V_39 , V_58 . V_6 ) ;
V_58 . V_6 = 0 ;
}
}
static bool F_84 ( int V_7 , int V_8 , const char * V_14 , T_6 V_6 )
{
if ( V_58 . V_6 && V_58 . V_153 )
return false ;
if ( V_58 . V_6 + V_6 > sizeof( V_58 . V_39 ) ) {
F_83 ( V_68 ) ;
return false ;
}
if ( ! V_58 . V_6 ) {
V_58 . V_7 = V_7 ;
V_58 . V_8 = V_8 ;
V_58 . V_156 = V_30 ;
V_58 . V_11 = F_7 () ;
V_58 . V_10 = 0 ;
V_58 . V_154 = 0 ;
V_58 . V_153 = false ;
}
memcpy ( V_58 . V_39 + V_58 . V_6 , V_14 , V_6 ) ;
V_58 . V_6 += V_6 ;
if ( V_58 . V_6 > ( sizeof( V_58 . V_39 ) * 80 ) / 100 )
F_83 ( V_68 ) ;
return true ;
}
static T_6 F_85 ( char * V_14 , T_6 V_15 )
{
T_6 V_129 = 0 ;
T_6 V_6 ;
if ( V_58 . V_154 == 0 && ( V_157 & V_118 ) ) {
V_129 += F_61 ( V_58 . V_11 , V_14 ) ;
V_15 -= V_129 ;
}
V_6 = V_58 . V_6 - V_58 . V_154 ;
if ( V_6 > 0 ) {
if ( V_6 + 1 > V_15 )
V_6 = V_15 - 1 ;
memcpy ( V_14 + V_129 , V_58 . V_39 + V_58 . V_154 , V_6 ) ;
V_129 += V_6 ;
V_58 . V_154 = V_58 . V_6 ;
}
if ( V_58 . V_153 ) {
if ( V_58 . V_10 & V_118 )
V_14 [ V_129 ++ ] = '\n' ;
V_58 . V_6 = 0 ;
}
return V_129 ;
}
T_10 int F_86 ( int V_7 , int V_8 ,
const char * V_12 , T_6 V_158 ,
const char * V_159 , T_11 args )
{
static int V_160 ;
static char V_161 [ V_43 ] ;
char * V_14 = V_161 ;
T_6 V_3 ;
enum V_9 V_162 = 0 ;
unsigned long V_10 ;
int V_163 ;
int V_164 = 0 ;
F_56 ( V_8 ) ;
F_81 () ;
F_87 ( V_10 ) ;
V_163 = F_72 () ;
if ( F_47 ( V_165 == V_163 ) ) {
if ( ! V_166 && ! F_88 ( V_30 ) ) {
V_160 = 1 ;
goto V_167;
}
F_73 () ;
}
F_89 () ;
F_90 ( & V_61 ) ;
V_165 = V_163 ;
if ( V_160 ) {
static const char V_168 [] =
L_16 ;
V_160 = 0 ;
V_164 += strlen ( V_168 ) ;
F_5 ( 0 , 2 , V_70 | V_118 , 0 ,
NULL , 0 , V_168 , V_164 ) ;
}
V_3 = F_91 ( V_14 , sizeof( V_161 ) , V_159 , args ) ;
if ( V_3 && V_14 [ V_3 - 1 ] == '\n' ) {
V_3 -- ;
V_162 |= V_118 ;
}
if ( V_7 == 0 ) {
int V_169 = F_92 ( V_14 ) ;
if ( V_169 ) {
const char * V_170 = F_93 ( V_14 ) ;
switch ( V_169 ) {
case '0' ... '7' :
if ( V_8 == - 1 )
V_8 = V_169 - '0' ;
case 'd' :
V_162 |= V_70 ;
case 'c' :
break;
}
V_3 -= V_170 - V_14 ;
V_14 = ( char * ) V_170 ;
}
}
if ( V_8 == - 1 )
V_8 = V_41 ;
if ( V_12 )
V_162 |= V_70 | V_118 ;
if ( ! ( V_162 & V_118 ) ) {
if ( V_58 . V_6 && ( V_162 & V_70 || V_58 . V_156 != V_30 ) )
F_83 ( V_118 ) ;
if ( ! F_84 ( V_7 , V_8 , V_14 , V_3 ) )
F_5 ( V_7 , V_8 , V_162 | V_68 , 0 ,
V_12 , V_158 , V_14 , V_3 ) ;
} else {
bool V_171 = false ;
if ( V_58 . V_6 && V_58 . V_156 == V_30 ) {
if ( ! ( V_162 & V_70 ) )
V_171 = F_84 ( V_7 , V_8 , V_14 , V_3 ) ;
F_83 ( V_118 ) ;
}
if ( ! V_171 )
F_5 ( V_7 , V_8 , V_162 , 0 ,
V_12 , V_158 , V_14 , V_3 ) ;
}
V_164 += V_3 ;
if ( F_80 ( V_163 ) )
F_94 () ;
F_95 () ;
V_167:
F_96 ( V_10 ) ;
return V_164 ;
}
T_10 int F_97 ( const char * V_159 , T_11 args )
{
return F_86 ( 0 , - 1 , NULL , 0 , V_159 , args ) ;
}
T_10 int F_19 ( int V_7 , int V_8 ,
const char * V_12 , T_6 V_158 ,
const char * V_159 , ... )
{
T_11 args ;
int V_172 ;
va_start ( args , V_159 ) ;
V_172 = F_86 ( V_7 , V_8 , V_12 , V_158 , V_159 , args ) ;
va_end ( args ) ;
return V_172 ;
}
T_10 int F_98 ( const char * V_159 , ... )
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
V_172 = F_86 ( 0 , - 1 , NULL , 0 , V_159 , args ) ;
va_end ( args ) ;
return V_172 ;
}
static struct V_1 * F_3 ( T_1 V_4 ) { return NULL ; }
static T_1 F_4 ( T_1 V_4 ) { return 0 ; }
static void F_68 ( int V_8 , const char * V_14 , T_6 V_6 ) {}
static T_6 F_63 ( const struct V_1 * V_2 , enum V_9 V_69 ,
bool V_114 , char * V_39 , T_6 V_15 ) { return 0 ; }
static T_6 F_85 ( char * V_14 , T_6 V_15 ) { return 0 ; }
void F_101 ( const char * V_159 , T_11 V_174 )
{
if ( V_175 ) {
char V_39 [ 512 ] ;
int V_121 = F_91 ( V_39 , sizeof( V_39 ) , V_159 , V_174 ) ;
V_175 -> V_146 ( V_175 , V_39 , V_121 ) ;
}
}
T_10 void F_102 ( const char * V_159 , ... )
{
T_11 V_174 ;
va_start ( V_174 , V_159 ) ;
F_101 ( V_159 , V_174 ) ;
va_end ( V_174 ) ;
}
static int F_103 ( char * V_176 , int V_4 , char * V_177 ,
char * V_178 )
{
struct V_179 * V_71 ;
int V_40 ;
for ( V_40 = 0 , V_71 = V_179 ;
V_40 < V_180 && V_71 -> V_176 [ 0 ] ;
V_40 ++ , V_71 ++ ) {
if ( strcmp ( V_71 -> V_176 , V_176 ) == 0 && V_71 -> V_181 == V_4 ) {
if ( ! V_178 )
V_182 = V_40 ;
return 0 ;
}
}
if ( V_40 == V_180 )
return - V_183 ;
if ( ! V_178 )
V_182 = V_40 ;
F_104 ( V_71 -> V_176 , V_176 , sizeof( V_71 -> V_176 ) ) ;
V_71 -> V_177 = V_177 ;
F_105 ( V_71 , V_178 ) ;
V_71 -> V_181 = V_4 ;
return 0 ;
}
static int T_9 F_106 ( char * V_91 )
{
char V_39 [ sizeof( V_179 [ 0 ] . V_176 ) + 4 ] ;
char * V_184 , * V_177 , * V_178 = NULL ;
int V_4 ;
if ( F_107 ( & V_91 , & V_178 ) )
return 1 ;
if ( V_91 [ 0 ] >= '0' && V_91 [ 0 ] <= '9' ) {
strcpy ( V_39 , L_17 ) ;
strncpy ( V_39 + 4 , V_91 , sizeof( V_39 ) - 5 ) ;
} else {
strncpy ( V_39 , V_91 , sizeof( V_39 ) - 1 ) ;
}
V_39 [ sizeof( V_39 ) - 1 ] = 0 ;
if ( ( V_177 = strchr ( V_91 , ',' ) ) != NULL )
* ( V_177 ++ ) = 0 ;
#ifdef F_108
if ( ! strcmp ( V_91 , L_18 ) )
strcpy ( V_39 , L_19 ) ;
if ( ! strcmp ( V_91 , L_20 ) )
strcpy ( V_39 , L_21 ) ;
#endif
for ( V_184 = V_39 ; * V_184 ; V_184 ++ )
if ( ( * V_184 >= '0' && * V_184 <= '9' ) || * V_184 == ',' )
break;
V_4 = F_18 ( V_184 , NULL , 10 ) ;
* V_184 = 0 ;
F_103 ( V_39 , V_4 , V_177 , V_178 ) ;
V_185 = 1 ;
return 1 ;
}
int F_109 ( char * V_176 , int V_4 , char * V_177 )
{
return F_103 ( V_176 , V_4 , V_177 , NULL ) ;
}
int F_110 ( char * V_176 , int V_4 , char * V_186 , int V_187 , char * V_177 )
{
struct V_179 * V_71 ;
int V_40 ;
for ( V_40 = 0 , V_71 = V_179 ;
V_40 < V_180 && V_71 -> V_176 [ 0 ] ;
V_40 ++ , V_71 ++ )
if ( strcmp ( V_71 -> V_176 , V_176 ) == 0 && V_71 -> V_181 == V_4 ) {
F_104 ( V_71 -> V_176 , V_186 , sizeof( V_71 -> V_176 ) ) ;
V_71 -> V_176 [ sizeof( V_71 -> V_176 ) - 1 ] = 0 ;
V_71 -> V_177 = V_177 ;
V_71 -> V_181 = V_187 ;
return V_40 ;
}
return - 1 ;
}
static int T_9 F_111 ( char * V_91 )
{
V_188 = 0 ;
return 1 ;
}
void F_112 ( void )
{
if ( ! V_188 )
return;
F_98 ( L_22 ) ;
F_113 () ;
V_189 = 1 ;
F_114 ( & V_149 ) ;
}
void F_115 ( void )
{
if ( ! V_188 )
return;
F_116 ( & V_149 ) ;
V_189 = 0 ;
F_94 () ;
}
static int F_117 ( struct V_190 * V_191 ,
unsigned long V_192 , void * V_193 )
{
switch ( V_192 ) {
case V_194 :
case V_195 :
case V_196 :
case V_197 :
F_113 () ;
F_94 () ;
}
return V_198 ;
}
void F_113 ( void )
{
F_118 () ;
F_116 ( & V_149 ) ;
if ( V_189 )
return;
V_199 = 1 ;
V_200 = 1 ;
F_119 ( & V_201 , 0 , 0 , V_202 ) ;
}
int F_120 ( void )
{
if ( F_121 ( & V_149 ) )
return 0 ;
if ( V_189 ) {
F_114 ( & V_149 ) ;
return 0 ;
}
V_199 = 1 ;
V_200 = 0 ;
F_119 ( & V_201 , 0 , 1 , V_202 ) ;
return 1 ;
}
int F_122 ( void )
{
return V_199 ;
}
static void F_123 ( char * V_14 , T_6 V_15 )
{
unsigned long V_10 ;
T_6 V_6 ;
F_49 ( & V_61 , V_10 ) ;
if ( ! V_58 . V_6 )
goto V_50;
if ( V_203 < V_19 && ! V_58 . V_154 )
goto V_50;
V_6 = F_85 ( V_14 , V_15 ) ;
F_124 ( & V_61 ) ;
F_125 () ;
F_68 ( V_58 . V_8 , V_14 , V_6 ) ;
F_126 () ;
F_96 ( V_10 ) ;
return;
V_50:
F_50 ( & V_61 , V_10 ) ;
}
void F_94 ( void )
{
static char V_14 [ V_43 + V_120 ] ;
static T_2 V_204 ;
unsigned long V_10 ;
bool V_205 = false ;
bool V_206 ;
if ( V_189 ) {
F_114 ( & V_149 ) ;
return;
}
V_200 = 0 ;
F_123 ( V_14 , sizeof( V_14 ) ) ;
V_207:
for (; ; ) {
struct V_1 * V_2 ;
T_6 V_6 ;
int V_8 ;
F_49 ( & V_61 , V_10 ) ;
if ( V_204 != V_19 ) {
V_205 = true ;
V_204 = V_19 ;
}
if ( V_203 < V_18 ) {
V_203 = V_18 ;
V_208 = V_21 ;
V_157 = 0 ;
}
V_122:
if ( V_203 == V_19 )
break;
V_2 = F_3 ( V_208 ) ;
if ( V_2 -> V_10 & V_155 ) {
V_208 = F_4 ( V_208 ) ;
V_203 ++ ;
V_2 -> V_10 &= ~ V_155 ;
V_157 = V_2 -> V_10 ;
goto V_122;
}
V_8 = V_2 -> V_8 ;
V_6 = F_63 ( V_2 , V_157 , false ,
V_14 , sizeof( V_14 ) ) ;
V_208 = F_4 ( V_208 ) ;
V_203 ++ ;
V_157 = V_2 -> V_10 ;
F_124 ( & V_61 ) ;
F_125 () ;
F_68 ( V_8 , V_14 , V_6 ) ;
F_126 () ;
F_96 ( V_10 ) ;
}
V_199 = 0 ;
F_127 ( & V_201 , 1 , V_202 ) ;
if ( F_47 ( V_144 ) )
V_144 = NULL ;
F_124 ( & V_61 ) ;
F_114 ( & V_149 ) ;
F_90 ( & V_61 ) ;
V_206 = V_203 != V_19 ;
F_50 ( & V_61 , V_10 ) ;
if ( V_206 && F_120 () )
goto V_207;
if ( V_205 )
F_128 () ;
}
void T_12 F_129 ( void )
{
if ( V_200 )
F_130 () ;
}
void F_131 ( void )
{
struct V_141 * V_71 ;
if ( V_166 ) {
if ( F_121 ( & V_149 ) != 0 )
return;
} else
F_113 () ;
V_199 = 1 ;
V_200 = 0 ;
F_70 (c)
if ( ( V_71 -> V_10 & V_145 ) && V_71 -> V_209 )
V_71 -> V_209 () ;
F_94 () ;
}
struct V_210 * F_132 ( int * V_181 )
{
struct V_141 * V_71 ;
struct V_210 * V_211 = NULL ;
F_113 () ;
F_70 (c) {
if ( ! V_71 -> V_212 )
continue;
V_211 = V_71 -> V_212 ( V_71 , V_181 ) ;
if ( V_211 )
break;
}
F_94 () ;
return V_211 ;
}
void F_133 ( struct V_141 * V_141 )
{
F_113 () ;
V_141 -> V_10 &= ~ V_145 ;
F_94 () ;
}
void F_134 ( struct V_141 * V_141 )
{
F_113 () ;
V_141 -> V_10 |= V_145 ;
F_94 () ;
}
static int T_9 F_135 ( char * V_91 )
{
V_213 = 1 ;
F_51 ( L_23 ) ;
return 0 ;
}
void F_136 ( struct V_141 * V_214 )
{
int V_40 ;
unsigned long V_10 ;
struct V_141 * V_215 = NULL ;
struct V_179 * V_71 ;
if ( V_143 )
F_70 (bcon)
if ( F_137 ( V_215 == V_214 ,
L_24 ,
V_215 -> V_176 , V_215 -> V_181 ) )
return;
if ( V_143 && V_214 -> V_10 & V_216 ) {
F_70 (bcon) {
if ( ! ( V_215 -> V_10 & V_216 ) ) {
F_51 ( L_25 ,
V_214 -> V_176 , V_214 -> V_181 ) ;
return;
}
}
}
if ( V_143 && V_143 -> V_10 & V_216 )
V_215 = V_143 ;
if ( V_217 < 0 || V_215 || ! V_143 )
V_217 = V_182 ;
if ( V_214 -> V_218 )
V_214 -> V_218 () ;
if ( V_217 < 0 ) {
if ( V_214 -> V_181 < 0 )
V_214 -> V_181 = 0 ;
if ( V_214 -> V_219 == NULL ||
V_214 -> V_219 ( V_214 , NULL ) == 0 ) {
V_214 -> V_10 |= V_145 ;
if ( V_214 -> V_212 ) {
V_214 -> V_10 |= V_220 ;
V_217 = 0 ;
}
}
}
for ( V_40 = 0 , V_71 = V_179 ;
V_40 < V_180 && V_71 -> V_176 [ 0 ] ;
V_40 ++ , V_71 ++ ) {
if ( strcmp ( V_71 -> V_176 , V_214 -> V_176 ) != 0 )
continue;
if ( V_214 -> V_181 >= 0 &&
V_214 -> V_181 != V_71 -> V_181 )
continue;
if ( V_214 -> V_181 < 0 )
V_214 -> V_181 = V_71 -> V_181 ;
if ( F_138 ( V_214 , V_71 ) )
return;
if ( V_214 -> V_219 &&
V_214 -> V_219 ( V_214 , V_179 [ V_40 ] . V_177 ) != 0 )
break;
V_214 -> V_10 |= V_145 ;
V_214 -> V_181 = V_71 -> V_181 ;
if ( V_40 == V_182 ) {
V_214 -> V_10 |= V_220 ;
V_217 = V_182 ;
}
break;
}
if ( ! ( V_214 -> V_10 & V_145 ) )
return;
if ( V_215 && ( ( V_214 -> V_10 & ( V_220 | V_216 ) ) == V_220 ) )
V_214 -> V_10 &= ~ V_221 ;
F_113 () ;
if ( ( V_214 -> V_10 & V_220 ) || V_143 == NULL ) {
V_214 -> V_119 = V_143 ;
V_143 = V_214 ;
if ( V_214 -> V_119 )
V_214 -> V_119 -> V_10 &= ~ V_220 ;
} else {
V_214 -> V_119 = V_143 -> V_119 ;
V_143 -> V_119 = V_214 ;
}
if ( V_214 -> V_10 & V_221 ) {
F_49 ( & V_61 , V_10 ) ;
V_203 = V_123 ;
V_208 = V_124 ;
V_157 = V_125 ;
F_50 ( & V_61 , V_10 ) ;
V_144 = V_214 ;
}
F_94 () ;
F_139 () ;
F_51 ( L_26 ,
( V_214 -> V_10 & V_216 ) ? L_27 : L_28 ,
V_214 -> V_176 , V_214 -> V_181 ) ;
if ( V_215 &&
( ( V_214 -> V_10 & ( V_220 | V_216 ) ) == V_220 ) &&
! V_213 ) {
F_70 (bcon)
if ( V_215 -> V_10 & V_216 )
F_140 ( V_215 ) ;
}
}
int F_140 ( struct V_141 * V_141 )
{
struct V_141 * V_222 , * V_223 ;
int V_224 ;
F_51 ( L_29 ,
( V_141 -> V_10 & V_216 ) ? L_27 : L_28 ,
V_141 -> V_176 , V_141 -> V_181 ) ;
V_224 = F_141 ( V_141 ) ;
if ( V_224 )
return V_224 ;
V_224 = 1 ;
F_113 () ;
if ( V_143 == V_141 ) {
V_143 = V_141 -> V_119 ;
V_224 = 0 ;
} else if ( V_143 ) {
for ( V_222 = V_143 -> V_119 , V_223 = V_143 ;
V_222 ; V_223 = V_222 , V_222 = V_223 -> V_119 ) {
if ( V_222 == V_141 ) {
V_223 -> V_119 = V_222 -> V_119 ;
V_224 = 0 ;
break;
}
}
}
if ( V_143 != NULL && V_141 -> V_10 & V_220 )
V_143 -> V_10 |= V_220 ;
F_94 () ;
F_139 () ;
return V_224 ;
}
static int T_9 F_142 ( void )
{
struct V_141 * V_142 ;
F_70 (con) {
if ( ! V_213 && V_142 -> V_10 & V_216 ) {
F_140 ( V_142 ) ;
}
}
F_143 ( F_117 , 0 ) ;
return 0 ;
}
static void F_144 ( struct V_225 * V_225 )
{
int V_226 = F_145 ( V_227 , 0 ) ;
if ( V_226 & V_228 ) {
char * V_39 = F_146 ( V_229 ) ;
F_147 ( L_30 , V_39 ) ;
}
if ( V_226 & V_230 )
F_148 ( & V_66 ) ;
}
void F_128 ( void )
{
F_149 () ;
if ( F_150 ( & V_66 ) ) {
F_151 ( V_227 , V_230 ) ;
F_152 ( & F_146 ( V_231 ) ) ;
}
F_153 () ;
}
int F_154 ( const char * V_159 , ... )
{
unsigned long V_10 ;
T_11 args ;
char * V_39 ;
int V_172 ;
F_87 ( V_10 ) ;
V_39 = F_146 ( V_229 ) ;
va_start ( args , V_159 ) ;
V_172 = vsnprintf ( V_39 , V_232 , V_159 , args ) ;
va_end ( args ) ;
F_155 ( V_227 , V_228 ) ;
F_152 ( & F_146 ( V_231 ) ) ;
F_96 ( V_10 ) ;
return V_172 ;
}
int F_156 ( const char * V_233 )
{
return F_157 ( & V_234 , V_233 ) ;
}
bool F_158 ( unsigned long * V_235 ,
unsigned int V_236 )
{
if ( * V_235 == 0
|| ! F_159 ( V_110 , * V_235 ,
* V_235
+ F_57 ( V_236 ) ) ) {
* V_235 = V_110 ;
return true ;
}
return false ;
}
int F_160 ( struct V_237 * V_238 )
{
unsigned long V_10 ;
int V_87 = - V_239 ;
if ( ! V_238 -> V_240 )
return - V_44 ;
F_161 ( & V_241 , V_10 ) ;
if ( ! V_238 -> V_242 ) {
V_238 -> V_242 = 1 ;
F_162 ( & V_238 -> V_243 , & V_244 ) ;
V_87 = 0 ;
}
F_163 ( & V_241 , V_10 ) ;
return V_87 ;
}
int F_164 ( struct V_237 * V_238 )
{
unsigned long V_10 ;
int V_87 = - V_44 ;
F_161 ( & V_241 , V_10 ) ;
if ( V_238 -> V_242 ) {
V_238 -> V_242 = 0 ;
F_165 ( & V_238 -> V_243 ) ;
V_87 = 0 ;
}
F_163 ( & V_241 , V_10 ) ;
F_166 () ;
return V_87 ;
}
void F_167 ( enum V_245 V_246 )
{
struct V_237 * V_238 ;
unsigned long V_10 ;
if ( ( V_246 > V_247 ) && ! V_248 )
return;
F_168 () ;
F_169 (dumper, &dump_list, list) {
if ( V_238 -> V_249 && V_246 > V_238 -> V_249 )
continue;
V_238 -> V_250 = true ;
F_49 ( & V_61 , V_10 ) ;
V_238 -> V_251 = V_78 ;
V_238 -> V_252 = V_77 ;
V_238 -> V_128 = V_19 ;
V_238 -> V_253 = V_20 ;
F_50 ( & V_61 , V_10 ) ;
V_238 -> V_240 ( V_238 , V_246 ) ;
V_238 -> V_250 = false ;
}
F_170 () ;
}
bool F_171 ( struct V_237 * V_238 , bool V_114 ,
char * line , T_6 V_15 , T_6 * V_6 )
{
struct V_1 * V_2 ;
T_6 V_254 = 0 ;
bool V_42 = false ;
if ( ! V_238 -> V_250 )
goto V_50;
if ( V_238 -> V_251 < V_18 ) {
V_238 -> V_251 = V_18 ;
V_238 -> V_252 = V_21 ;
}
if ( V_238 -> V_251 >= V_19 )
goto V_50;
V_2 = F_3 ( V_238 -> V_252 ) ;
V_254 = F_63 ( V_2 , 0 , V_114 , line , V_15 ) ;
V_238 -> V_252 = F_4 ( V_238 -> V_252 ) ;
V_238 -> V_251 ++ ;
V_42 = true ;
V_50:
if ( V_6 )
* V_6 = V_254 ;
return V_42 ;
}
bool F_172 ( struct V_237 * V_238 , bool V_114 ,
char * line , T_6 V_15 , T_6 * V_6 )
{
unsigned long V_10 ;
bool V_42 ;
F_49 ( & V_61 , V_10 ) ;
V_42 = F_171 ( V_238 , V_114 , line , V_15 , V_6 ) ;
F_50 ( & V_61 , V_10 ) ;
return V_42 ;
}
bool F_173 ( struct V_237 * V_238 , bool V_114 ,
char * V_39 , T_6 V_15 , T_6 * V_6 )
{
unsigned long V_10 ;
T_2 V_62 ;
T_1 V_4 ;
T_2 V_128 ;
T_1 V_253 ;
enum V_9 V_69 ;
T_6 V_254 = 0 ;
bool V_42 = false ;
if ( ! V_238 -> V_250 )
goto V_50;
F_49 ( & V_61 , V_10 ) ;
if ( V_238 -> V_251 < V_18 ) {
V_238 -> V_251 = V_18 ;
V_238 -> V_252 = V_21 ;
}
if ( V_238 -> V_251 >= V_238 -> V_128 ) {
F_50 ( & V_61 , V_10 ) ;
goto V_50;
}
V_62 = V_238 -> V_251 ;
V_4 = V_238 -> V_252 ;
V_69 = 0 ;
while ( V_62 < V_238 -> V_128 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_254 += F_63 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_62 = V_238 -> V_251 ;
V_4 = V_238 -> V_252 ;
V_69 = 0 ;
while ( V_254 > V_15 && V_62 < V_238 -> V_128 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_254 -= F_63 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_128 = V_62 ;
V_253 = V_4 ;
V_254 = 0 ;
V_69 = 0 ;
while ( V_62 < V_238 -> V_128 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_254 += F_63 ( V_2 , V_69 , V_114 , V_39 + V_254 , V_15 - V_254 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_238 -> V_128 = V_128 ;
V_238 -> V_253 = V_253 ;
V_42 = true ;
F_50 ( & V_61 , V_10 ) ;
V_50:
if ( V_6 )
* V_6 = V_254 ;
return V_42 ;
}
void F_174 ( struct V_237 * V_238 )
{
V_238 -> V_251 = V_78 ;
V_238 -> V_252 = V_77 ;
V_238 -> V_128 = V_19 ;
V_238 -> V_253 = V_20 ;
}
void F_175 ( struct V_237 * V_238 )
{
unsigned long V_10 ;
F_49 ( & V_61 , V_10 ) ;
F_174 ( V_238 ) ;
F_50 ( & V_61 , V_10 ) ;
}
void T_9 F_176 ( const char * V_159 , ... )
{
T_11 args ;
va_start ( args , V_159 ) ;
vsnprintf ( V_255 , sizeof( V_255 ) ,
V_159 , args ) ;
va_end ( args ) ;
}
void F_177 ( const char * V_256 )
{
F_98 ( L_31 ,
V_256 , F_178 () , V_30 -> V_257 , V_30 -> V_31 ,
F_179 () , F_180 () -> V_258 ,
( int ) strcspn ( F_180 () -> V_259 , L_32 ) ,
F_180 () -> V_259 ) ;
if ( V_255 [ 0 ] != '\0' )
F_98 ( L_33 ,
V_256 , V_255 ) ;
F_181 ( V_256 , V_30 ) ;
}
void F_182 ( const char * V_256 )
{
F_177 ( V_256 ) ;
F_98 ( L_34 ,
V_256 , V_30 , F_183 () ,
F_184 ( V_30 ) ) ;
}
