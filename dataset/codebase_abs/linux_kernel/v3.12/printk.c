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
F_53 ( V_100 L_10 ) ;
return 0 ;
}
static int T_9 F_54 ( char * V_91 )
{
unsigned long V_101 ;
V_101 = V_102 ? V_102 : 1000000 ;
V_103 = ( unsigned long long ) V_101 / 1000 * V_104 ;
F_55 ( & V_91 , & V_105 ) ;
if ( V_105 > 10 * 1000 )
V_105 = 0 ;
F_56 ( L_11
L_12 ,
V_105 , V_102 , V_101 , V_104 , V_103 ) ;
return 1 ;
}
static void F_57 ( int V_8 )
{
unsigned long long V_106 ;
unsigned long V_107 ;
if ( ( V_105 == 0 || V_108 != V_109 )
|| ( V_8 >= V_110 && ! V_99 ) ) {
return;
}
V_106 = ( unsigned long long ) V_103 * V_105 ;
V_107 = V_111 + F_58 ( V_105 ) ;
while ( V_106 ) {
V_106 -- ;
F_59 () ;
if ( F_60 ( V_111 , V_107 ) )
break;
F_61 () ;
}
}
static inline void F_57 ( int V_8 )
{
}
static T_6 F_62 ( T_2 V_112 , char * V_39 )
{
unsigned long V_113 ;
if ( ! V_114 )
return 0 ;
V_113 = F_26 ( V_112 , 1000000000 ) ;
if ( ! V_39 )
return snprintf ( NULL , 0 , L_13 , ( unsigned long ) V_112 ) ;
return sprintf ( V_39 , L_14 ,
( unsigned long ) V_112 , V_113 / 1000 ) ;
}
static T_6 F_63 ( const struct V_1 * V_2 , bool V_115 , char * V_39 )
{
T_6 V_6 = 0 ;
unsigned int V_116 = ( V_2 -> V_7 << 3 ) | V_2 -> V_8 ;
if ( V_115 ) {
if ( V_39 ) {
V_6 += sprintf ( V_39 , L_15 , V_116 ) ;
} else {
V_6 += 3 ;
if ( V_116 > 999 )
V_6 += 3 ;
else if ( V_116 > 99 )
V_6 += 2 ;
else if ( V_116 > 9 )
V_6 ++ ;
}
}
V_6 += F_62 ( V_2 -> V_11 , V_39 ? V_39 + V_6 : NULL ) ;
return V_6 ;
}
static T_6 F_64 ( const struct V_1 * V_2 , enum V_9 V_69 ,
bool V_115 , char * V_39 , T_6 V_15 )
{
const char * V_14 = F_1 ( V_2 ) ;
T_6 V_117 = V_2 -> V_3 ;
bool V_116 = true ;
bool V_118 = true ;
T_6 V_6 = 0 ;
if ( ( V_69 & V_68 ) && ! ( V_2 -> V_10 & V_70 ) )
V_116 = false ;
if ( V_2 -> V_10 & V_68 ) {
if ( ( V_69 & V_68 ) && ! ( V_69 & V_119 ) )
V_116 = false ;
if ( ! ( V_2 -> V_10 & V_119 ) )
V_118 = false ;
}
do {
const char * V_120 = memchr ( V_14 , '\n' , V_117 ) ;
T_6 V_3 ;
if ( V_120 ) {
V_3 = V_120 - V_14 ;
V_120 ++ ;
V_117 -= V_120 - V_14 ;
} else {
V_3 = V_117 ;
}
if ( V_39 ) {
if ( F_63 ( V_2 , V_115 , NULL ) +
V_3 + 1 >= V_15 - V_6 )
break;
if ( V_116 )
V_6 += F_63 ( V_2 , V_115 , V_39 + V_6 ) ;
memcpy ( V_39 + V_6 , V_14 , V_3 ) ;
V_6 += V_3 ;
if ( V_120 || V_118 )
V_39 [ V_6 ++ ] = '\n' ;
} else {
if ( V_116 )
V_6 += F_63 ( V_2 , V_115 , NULL ) ;
V_6 += V_3 ;
if ( V_120 || V_118 )
V_6 ++ ;
}
V_116 = true ;
V_14 = V_120 ;
} while ( V_14 );
return V_6 ;
}
static int F_65 ( char T_7 * V_39 , int V_15 )
{
char * V_14 ;
struct V_1 * V_2 ;
int V_6 = 0 ;
V_14 = F_16 ( V_43 + V_121 , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
while ( V_15 > 0 ) {
T_6 V_122 ;
T_6 V_123 ;
F_23 ( & V_61 ) ;
if ( V_124 < V_18 ) {
V_124 = V_18 ;
V_125 = V_21 ;
V_126 = 0 ;
V_127 = 0 ;
}
if ( V_124 == V_19 ) {
F_24 ( & V_61 ) ;
break;
}
V_123 = V_127 ;
V_2 = F_3 ( V_125 ) ;
V_122 = F_64 ( V_2 , V_126 , true , V_14 ,
V_43 + V_121 ) ;
if ( V_122 - V_127 <= V_15 ) {
V_125 = F_4 ( V_125 ) ;
V_124 ++ ;
V_126 = V_2 -> V_10 ;
V_122 -= V_127 ;
V_127 = 0 ;
} else if ( ! V_6 ) {
V_122 = V_15 ;
V_127 += V_122 ;
} else
V_122 = 0 ;
F_24 ( & V_61 ) ;
if ( ! V_122 )
break;
if ( F_27 ( V_39 , V_14 + V_123 , V_122 ) ) {
if ( ! V_6 )
V_6 = - V_49 ;
break;
}
V_6 += V_122 ;
V_15 -= V_122 ;
V_39 += V_122 ;
}
F_20 ( V_14 ) ;
return V_6 ;
}
static int F_66 ( char T_7 * V_39 , int V_15 , bool V_128 )
{
char * V_14 ;
int V_6 = 0 ;
V_14 = F_16 ( V_43 + V_121 , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
F_23 ( & V_61 ) ;
if ( V_39 ) {
T_2 V_129 ;
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
V_6 += F_64 ( V_2 , V_69 , true , NULL , 0 ) ;
V_69 = V_2 -> V_10 ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
}
V_62 = V_78 ;
V_4 = V_77 ;
V_69 = 0 ;
while ( V_6 > V_15 && V_62 < V_19 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_6 -= F_64 ( V_2 , V_69 , true , NULL , 0 ) ;
V_69 = V_2 -> V_10 ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
}
V_129 = V_19 ;
V_6 = 0 ;
V_69 = 0 ;
while ( V_6 >= 0 && V_62 < V_129 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
int V_130 ;
V_130 = F_64 ( V_2 , V_69 , true , V_14 ,
V_43 + V_121 ) ;
if ( V_130 < 0 ) {
V_6 = V_130 ;
break;
}
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
F_24 ( & V_61 ) ;
if ( F_27 ( V_39 + V_6 , V_14 , V_130 ) )
V_6 = - V_49 ;
else
V_6 += V_130 ;
F_23 ( & V_61 ) ;
if ( V_62 < V_18 ) {
V_62 = V_18 ;
V_4 = V_21 ;
V_69 = 0 ;
}
}
}
if ( V_128 ) {
V_78 = V_19 ;
V_77 = V_20 ;
}
F_24 ( & V_61 ) ;
F_20 ( V_14 ) ;
return V_6 ;
}
int F_67 ( int type , char T_7 * V_39 , int V_6 , bool V_26 )
{
bool V_128 = false ;
static int V_131 = - 1 ;
int error ;
error = F_9 ( type , V_26 ) ;
if ( error )
goto V_50;
error = F_13 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_132 :
break;
case V_27 :
break;
case V_133 :
error = - V_44 ;
if ( ! V_39 || V_6 < 0 )
goto V_50;
error = 0 ;
if ( ! V_6 )
goto V_50;
if ( ! F_68 ( V_134 , V_39 , V_6 ) ) {
error = - V_49 ;
goto V_50;
}
error = F_25 ( V_66 ,
V_124 != V_19 ) ;
if ( error )
goto V_50;
error = F_65 ( V_39 , V_6 ) ;
break;
case V_135 :
V_128 = true ;
case V_24 :
error = - V_44 ;
if ( ! V_39 || V_6 < 0 )
goto V_50;
error = 0 ;
if ( ! V_6 )
goto V_50;
if ( ! F_68 ( V_134 , V_39 , V_6 ) ) {
error = - V_49 ;
goto V_50;
}
error = F_66 ( V_39 , V_6 , V_128 ) ;
break;
case V_136 :
F_66 ( NULL , 0 , true ) ;
break;
case V_137 :
if ( V_131 == - 1 )
V_131 = V_110 ;
V_110 = V_138 ;
break;
case V_139 :
if ( V_131 != - 1 ) {
V_110 = V_131 ;
V_131 = - 1 ;
}
break;
case V_140 :
error = - V_44 ;
if ( V_6 < 1 || V_6 > 8 )
goto V_50;
if ( V_6 < V_138 )
V_6 = V_138 ;
V_110 = V_6 ;
V_131 = - 1 ;
error = 0 ;
break;
case V_141 :
F_23 ( & V_61 ) ;
if ( V_124 < V_18 ) {
V_124 = V_18 ;
V_125 = V_21 ;
V_126 = 0 ;
V_127 = 0 ;
}
if ( V_26 ) {
error = V_20 - V_125 ;
} else {
T_2 V_62 = V_124 ;
T_1 V_4 = V_125 ;
enum V_9 V_69 = V_126 ;
error = 0 ;
while ( V_62 < V_19 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
error += F_64 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
error -= V_127 ;
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
static void F_69 ( int V_8 , const char * V_14 , T_6 V_6 )
{
struct V_142 * V_143 ;
F_70 ( V_14 , V_6 ) ;
if ( V_8 >= V_110 && ! V_99 )
return;
if ( ! V_144 )
return;
F_71 (con) {
if ( V_145 && V_143 != V_145 )
continue;
if ( ! ( V_143 -> V_10 & V_146 ) )
continue;
if ( ! V_143 -> V_147 )
continue;
if ( ! F_72 ( F_73 () ) &&
! ( V_143 -> V_10 & V_148 ) )
continue;
V_143 -> V_147 ( V_143 , V_14 , V_6 ) ;
}
}
static void F_74 ( void )
{
static unsigned long V_149 ;
if ( F_75 ( V_111 , V_149 ) &&
! F_60 ( V_111 , V_149 + 30 * V_104 ) )
return;
V_149 = V_111 ;
F_76 () ;
F_77 ( & V_61 ) ;
F_78 ( & V_150 , 1 ) ;
}
static int F_79 ( void )
{
struct V_142 * V_143 ;
F_71 (con)
if ( V_143 -> V_10 & V_148 )
return 1 ;
return 0 ;
}
static inline int F_80 ( unsigned int V_151 )
{
return F_72 ( V_151 ) || F_79 () ;
}
static int F_81 ( unsigned int V_151 )
__releases( &logbuf_lock
static inline void F_82 ( void )
{
if ( F_47 ( V_152 ) ) {
int V_153 = V_152 ;
while ( V_153 -- ) {
F_83 ( 1 ) ;
F_61 () ;
}
}
}
static void F_84 ( enum V_9 V_10 )
{
if ( V_58 . V_154 )
return;
if ( V_58 . V_6 == 0 )
return;
if ( V_58 . V_155 ) {
F_5 ( V_58 . V_7 , V_58 . V_8 , V_10 | V_156 ,
V_58 . V_11 , NULL , 0 , V_58 . V_39 , V_58 . V_6 ) ;
V_58 . V_10 = V_10 ;
V_58 . V_154 = true ;
} else {
F_5 ( V_58 . V_7 , V_58 . V_8 , V_10 , 0 ,
NULL , 0 , V_58 . V_39 , V_58 . V_6 ) ;
V_58 . V_6 = 0 ;
}
}
static bool F_85 ( int V_7 , int V_8 , const char * V_14 , T_6 V_6 )
{
if ( V_58 . V_6 && V_58 . V_154 )
return false ;
if ( V_58 . V_6 + V_6 > sizeof( V_58 . V_39 ) ) {
F_84 ( V_68 ) ;
return false ;
}
if ( ! V_58 . V_6 ) {
V_58 . V_7 = V_7 ;
V_58 . V_8 = V_8 ;
V_58 . V_157 = V_30 ;
V_58 . V_11 = F_7 () ;
V_58 . V_10 = 0 ;
V_58 . V_155 = 0 ;
V_58 . V_154 = false ;
}
memcpy ( V_58 . V_39 + V_58 . V_6 , V_14 , V_6 ) ;
V_58 . V_6 += V_6 ;
if ( V_58 . V_6 > ( sizeof( V_58 . V_39 ) * 80 ) / 100 )
F_84 ( V_68 ) ;
return true ;
}
static T_6 F_86 ( char * V_14 , T_6 V_15 )
{
T_6 V_130 = 0 ;
T_6 V_6 ;
if ( V_58 . V_155 == 0 && ( V_158 & V_119 ) ) {
V_130 += F_62 ( V_58 . V_11 , V_14 ) ;
V_15 -= V_130 ;
}
V_6 = V_58 . V_6 - V_58 . V_155 ;
if ( V_6 > 0 ) {
if ( V_6 + 1 > V_15 )
V_6 = V_15 - 1 ;
memcpy ( V_14 + V_130 , V_58 . V_39 + V_58 . V_155 , V_6 ) ;
V_130 += V_6 ;
V_58 . V_155 = V_58 . V_6 ;
}
if ( V_58 . V_154 ) {
if ( V_58 . V_10 & V_119 )
V_14 [ V_130 ++ ] = '\n' ;
V_58 . V_6 = 0 ;
}
return V_130 ;
}
T_10 int F_87 ( int V_7 , int V_8 ,
const char * V_12 , T_6 V_159 ,
const char * V_160 , T_11 args )
{
static int V_161 ;
static char V_162 [ V_43 ] ;
char * V_14 = V_162 ;
T_6 V_3 ;
enum V_9 V_163 = 0 ;
unsigned long V_10 ;
int V_164 ;
int V_165 = 0 ;
F_57 ( V_8 ) ;
F_82 () ;
F_88 ( V_10 ) ;
V_164 = F_73 () ;
if ( F_47 ( V_166 == V_164 ) ) {
if ( ! V_167 && ! F_89 ( V_30 ) ) {
V_161 = 1 ;
goto V_168;
}
F_74 () ;
}
F_90 () ;
F_91 ( & V_61 ) ;
V_166 = V_164 ;
if ( V_161 ) {
static const char V_169 [] =
L_16 ;
V_161 = 0 ;
V_165 += strlen ( V_169 ) ;
F_5 ( 0 , 2 , V_70 | V_119 , 0 ,
NULL , 0 , V_169 , V_165 ) ;
}
V_3 = F_92 ( V_14 , sizeof( V_162 ) , V_160 , args ) ;
if ( V_3 && V_14 [ V_3 - 1 ] == '\n' ) {
V_3 -- ;
V_163 |= V_119 ;
}
if ( V_7 == 0 ) {
int V_170 = F_93 ( V_14 ) ;
if ( V_170 ) {
const char * V_171 = F_94 ( V_14 ) ;
switch ( V_170 ) {
case '0' ... '7' :
if ( V_8 == - 1 )
V_8 = V_170 - '0' ;
case 'd' :
V_163 |= V_70 ;
case 'c' :
break;
}
V_3 -= V_171 - V_14 ;
V_14 = ( char * ) V_171 ;
}
}
if ( V_8 == - 1 )
V_8 = V_41 ;
if ( V_12 )
V_163 |= V_70 | V_119 ;
if ( ! ( V_163 & V_119 ) ) {
if ( V_58 . V_6 && ( V_163 & V_70 || V_58 . V_157 != V_30 ) )
F_84 ( V_119 ) ;
if ( ! F_85 ( V_7 , V_8 , V_14 , V_3 ) )
F_5 ( V_7 , V_8 , V_163 | V_68 , 0 ,
V_12 , V_159 , V_14 , V_3 ) ;
} else {
bool V_172 = false ;
if ( V_58 . V_6 && V_58 . V_157 == V_30 ) {
if ( ! ( V_163 & V_70 ) )
V_172 = F_85 ( V_7 , V_8 , V_14 , V_3 ) ;
F_84 ( V_119 ) ;
}
if ( ! V_172 )
F_5 ( V_7 , V_8 , V_163 , 0 ,
V_12 , V_159 , V_14 , V_3 ) ;
}
V_165 += V_3 ;
if ( F_81 ( V_164 ) )
F_95 () ;
F_96 () ;
V_168:
F_97 ( V_10 ) ;
return V_165 ;
}
T_10 int F_98 ( const char * V_160 , T_11 args )
{
return F_87 ( 0 , - 1 , NULL , 0 , V_160 , args ) ;
}
T_10 int F_19 ( int V_7 , int V_8 ,
const char * V_12 , T_6 V_159 ,
const char * V_160 , ... )
{
T_11 args ;
int V_173 ;
va_start ( args , V_160 ) ;
V_173 = F_87 ( V_7 , V_8 , V_12 , V_159 , V_160 , args ) ;
va_end ( args ) ;
return V_173 ;
}
T_10 int F_53 ( const char * V_160 , ... )
{
T_11 args ;
int V_173 ;
#ifdef F_99
if ( F_47 ( V_174 ) ) {
va_start ( args , V_160 ) ;
V_173 = F_100 ( V_160 , args ) ;
va_end ( args ) ;
return V_173 ;
}
#endif
va_start ( args , V_160 ) ;
V_173 = F_87 ( 0 , - 1 , NULL , 0 , V_160 , args ) ;
va_end ( args ) ;
return V_173 ;
}
static struct V_1 * F_3 ( T_1 V_4 ) { return NULL ; }
static T_1 F_4 ( T_1 V_4 ) { return 0 ; }
static void F_69 ( int V_8 , const char * V_14 , T_6 V_6 ) {}
static T_6 F_64 ( const struct V_1 * V_2 , enum V_9 V_69 ,
bool V_115 , char * V_39 , T_6 V_15 ) { return 0 ; }
static T_6 F_86 ( char * V_14 , T_6 V_15 ) { return 0 ; }
void F_101 ( const char * V_160 , T_11 V_175 )
{
if ( V_176 ) {
char V_39 [ 512 ] ;
int V_122 = F_92 ( V_39 , sizeof( V_39 ) , V_160 , V_175 ) ;
V_176 -> V_147 ( V_176 , V_39 , V_122 ) ;
}
}
T_10 void F_102 ( const char * V_160 , ... )
{
T_11 V_175 ;
va_start ( V_175 , V_160 ) ;
F_101 ( V_160 , V_175 ) ;
va_end ( V_175 ) ;
}
static int F_103 ( char * V_177 , int V_4 , char * V_178 ,
char * V_179 )
{
struct V_180 * V_71 ;
int V_40 ;
for ( V_40 = 0 , V_71 = V_180 ;
V_40 < V_181 && V_71 -> V_177 [ 0 ] ;
V_40 ++ , V_71 ++ ) {
if ( strcmp ( V_71 -> V_177 , V_177 ) == 0 && V_71 -> V_182 == V_4 ) {
if ( ! V_179 )
V_183 = V_40 ;
return 0 ;
}
}
if ( V_40 == V_181 )
return - V_184 ;
if ( ! V_179 )
V_183 = V_40 ;
F_104 ( V_71 -> V_177 , V_177 , sizeof( V_71 -> V_177 ) ) ;
V_71 -> V_178 = V_178 ;
F_105 ( V_71 , V_179 ) ;
V_71 -> V_182 = V_4 ;
return 0 ;
}
static int T_9 F_106 ( char * V_91 )
{
char V_39 [ sizeof( V_180 [ 0 ] . V_177 ) + 4 ] ;
char * V_185 , * V_178 , * V_179 = NULL ;
int V_4 ;
if ( F_107 ( & V_91 , & V_179 ) )
return 1 ;
if ( V_91 [ 0 ] >= '0' && V_91 [ 0 ] <= '9' ) {
strcpy ( V_39 , L_17 ) ;
strncpy ( V_39 + 4 , V_91 , sizeof( V_39 ) - 5 ) ;
} else {
strncpy ( V_39 , V_91 , sizeof( V_39 ) - 1 ) ;
}
V_39 [ sizeof( V_39 ) - 1 ] = 0 ;
if ( ( V_178 = strchr ( V_91 , ',' ) ) != NULL )
* ( V_178 ++ ) = 0 ;
#ifdef F_108
if ( ! strcmp ( V_91 , L_18 ) )
strcpy ( V_39 , L_19 ) ;
if ( ! strcmp ( V_91 , L_20 ) )
strcpy ( V_39 , L_21 ) ;
#endif
for ( V_185 = V_39 ; * V_185 ; V_185 ++ )
if ( ( * V_185 >= '0' && * V_185 <= '9' ) || * V_185 == ',' )
break;
V_4 = F_18 ( V_185 , NULL , 10 ) ;
* V_185 = 0 ;
F_103 ( V_39 , V_4 , V_178 , V_179 ) ;
V_186 = 1 ;
return 1 ;
}
int F_109 ( char * V_177 , int V_4 , char * V_178 )
{
return F_103 ( V_177 , V_4 , V_178 , NULL ) ;
}
int F_110 ( char * V_177 , int V_4 , char * V_187 , int V_188 , char * V_178 )
{
struct V_180 * V_71 ;
int V_40 ;
for ( V_40 = 0 , V_71 = V_180 ;
V_40 < V_181 && V_71 -> V_177 [ 0 ] ;
V_40 ++ , V_71 ++ )
if ( strcmp ( V_71 -> V_177 , V_177 ) == 0 && V_71 -> V_182 == V_4 ) {
F_104 ( V_71 -> V_177 , V_187 , sizeof( V_71 -> V_177 ) ) ;
V_71 -> V_177 [ sizeof( V_71 -> V_177 ) - 1 ] = 0 ;
V_71 -> V_178 = V_178 ;
V_71 -> V_182 = V_188 ;
return V_40 ;
}
return - 1 ;
}
static int T_9 F_111 ( char * V_91 )
{
V_189 = 0 ;
return 1 ;
}
void F_112 ( void )
{
if ( ! V_189 )
return;
F_53 ( L_22 ) ;
F_113 () ;
V_190 = 1 ;
F_114 ( & V_150 ) ;
}
void F_115 ( void )
{
if ( ! V_189 )
return;
F_116 ( & V_150 ) ;
V_190 = 0 ;
F_95 () ;
}
static int F_117 ( struct V_191 * V_192 ,
unsigned long V_193 , void * V_194 )
{
switch ( V_193 ) {
case V_195 :
case V_196 :
case V_197 :
case V_198 :
F_113 () ;
F_95 () ;
}
return V_199 ;
}
void F_113 ( void )
{
F_118 () ;
F_116 ( & V_150 ) ;
if ( V_190 )
return;
V_200 = 1 ;
V_201 = 1 ;
F_119 ( & V_202 , 0 , 0 , V_203 ) ;
}
int F_120 ( void )
{
if ( F_121 ( & V_150 ) )
return 0 ;
if ( V_190 ) {
F_114 ( & V_150 ) ;
return 0 ;
}
V_200 = 1 ;
V_201 = 0 ;
F_119 ( & V_202 , 0 , 1 , V_203 ) ;
return 1 ;
}
int F_122 ( void )
{
return V_200 ;
}
static void F_123 ( char * V_14 , T_6 V_15 )
{
unsigned long V_10 ;
T_6 V_6 ;
F_49 ( & V_61 , V_10 ) ;
if ( ! V_58 . V_6 )
goto V_50;
if ( V_204 < V_19 && ! V_58 . V_155 )
goto V_50;
V_6 = F_86 ( V_14 , V_15 ) ;
F_124 ( & V_61 ) ;
F_125 () ;
F_69 ( V_58 . V_8 , V_14 , V_6 ) ;
F_126 () ;
F_97 ( V_10 ) ;
return;
V_50:
F_50 ( & V_61 , V_10 ) ;
}
void F_95 ( void )
{
static char V_14 [ V_43 + V_121 ] ;
static T_2 V_205 ;
unsigned long V_10 ;
bool V_206 = false ;
bool V_207 ;
if ( V_190 ) {
F_114 ( & V_150 ) ;
return;
}
V_201 = 0 ;
F_123 ( V_14 , sizeof( V_14 ) ) ;
V_208:
for (; ; ) {
struct V_1 * V_2 ;
T_6 V_6 ;
int V_8 ;
F_49 ( & V_61 , V_10 ) ;
if ( V_205 != V_19 ) {
V_206 = true ;
V_205 = V_19 ;
}
if ( V_204 < V_18 ) {
V_204 = V_18 ;
V_209 = V_21 ;
V_158 = 0 ;
}
V_123:
if ( V_204 == V_19 )
break;
V_2 = F_3 ( V_209 ) ;
if ( V_2 -> V_10 & V_156 ) {
V_209 = F_4 ( V_209 ) ;
V_204 ++ ;
V_2 -> V_10 &= ~ V_156 ;
V_158 = V_2 -> V_10 ;
goto V_123;
}
V_8 = V_2 -> V_8 ;
V_6 = F_64 ( V_2 , V_158 , false ,
V_14 , sizeof( V_14 ) ) ;
V_209 = F_4 ( V_209 ) ;
V_204 ++ ;
V_158 = V_2 -> V_10 ;
F_124 ( & V_61 ) ;
F_125 () ;
F_69 ( V_8 , V_14 , V_6 ) ;
F_126 () ;
F_97 ( V_10 ) ;
}
V_200 = 0 ;
F_127 ( & V_202 , 1 , V_203 ) ;
if ( F_47 ( V_145 ) )
V_145 = NULL ;
F_124 ( & V_61 ) ;
F_114 ( & V_150 ) ;
F_91 ( & V_61 ) ;
V_207 = V_204 != V_19 ;
F_50 ( & V_61 , V_10 ) ;
if ( V_207 && F_120 () )
goto V_208;
if ( V_206 )
F_128 () ;
}
void T_12 F_129 ( void )
{
if ( V_201 )
F_130 () ;
}
void F_131 ( void )
{
struct V_142 * V_71 ;
if ( V_167 ) {
if ( F_121 ( & V_150 ) != 0 )
return;
} else
F_113 () ;
V_200 = 1 ;
V_201 = 0 ;
F_71 (c)
if ( ( V_71 -> V_10 & V_146 ) && V_71 -> V_210 )
V_71 -> V_210 () ;
F_95 () ;
}
struct V_211 * F_132 ( int * V_182 )
{
struct V_142 * V_71 ;
struct V_211 * V_212 = NULL ;
F_113 () ;
F_71 (c) {
if ( ! V_71 -> V_213 )
continue;
V_212 = V_71 -> V_213 ( V_71 , V_182 ) ;
if ( V_212 )
break;
}
F_95 () ;
return V_212 ;
}
void F_133 ( struct V_142 * V_142 )
{
F_113 () ;
V_142 -> V_10 &= ~ V_146 ;
F_95 () ;
}
void F_134 ( struct V_142 * V_142 )
{
F_113 () ;
V_142 -> V_10 |= V_146 ;
F_95 () ;
}
static int T_9 F_135 ( char * V_91 )
{
V_214 = 1 ;
F_53 ( V_100 L_23 ) ;
return 0 ;
}
void F_136 ( struct V_142 * V_215 )
{
int V_40 ;
unsigned long V_10 ;
struct V_142 * V_216 = NULL ;
struct V_180 * V_71 ;
if ( V_144 )
F_71 (bcon)
if ( F_137 ( V_216 == V_215 ,
L_24 ,
V_216 -> V_177 , V_216 -> V_182 ) )
return;
if ( V_144 && V_215 -> V_10 & V_217 ) {
F_71 (bcon) {
if ( ! ( V_216 -> V_10 & V_217 ) ) {
F_53 ( V_100 L_25 ,
V_215 -> V_177 , V_215 -> V_182 ) ;
return;
}
}
}
if ( V_144 && V_144 -> V_10 & V_217 )
V_216 = V_144 ;
if ( V_218 < 0 || V_216 || ! V_144 )
V_218 = V_183 ;
if ( V_215 -> V_219 )
V_215 -> V_219 () ;
if ( V_218 < 0 ) {
if ( V_215 -> V_182 < 0 )
V_215 -> V_182 = 0 ;
if ( V_215 -> V_220 == NULL ||
V_215 -> V_220 ( V_215 , NULL ) == 0 ) {
V_215 -> V_10 |= V_146 ;
if ( V_215 -> V_213 ) {
V_215 -> V_10 |= V_221 ;
V_218 = 0 ;
}
}
}
for ( V_40 = 0 , V_71 = V_180 ;
V_40 < V_181 && V_71 -> V_177 [ 0 ] ;
V_40 ++ , V_71 ++ ) {
if ( strcmp ( V_71 -> V_177 , V_215 -> V_177 ) != 0 )
continue;
if ( V_215 -> V_182 >= 0 &&
V_215 -> V_182 != V_71 -> V_182 )
continue;
if ( V_215 -> V_182 < 0 )
V_215 -> V_182 = V_71 -> V_182 ;
if ( F_138 ( V_215 , V_71 ) )
return;
if ( V_215 -> V_220 &&
V_215 -> V_220 ( V_215 , V_180 [ V_40 ] . V_178 ) != 0 )
break;
V_215 -> V_10 |= V_146 ;
V_215 -> V_182 = V_71 -> V_182 ;
if ( V_40 == V_183 ) {
V_215 -> V_10 |= V_221 ;
V_218 = V_183 ;
}
break;
}
if ( ! ( V_215 -> V_10 & V_146 ) )
return;
if ( V_216 && ( ( V_215 -> V_10 & ( V_221 | V_217 ) ) == V_221 ) )
V_215 -> V_10 &= ~ V_222 ;
F_113 () ;
if ( ( V_215 -> V_10 & V_221 ) || V_144 == NULL ) {
V_215 -> V_120 = V_144 ;
V_144 = V_215 ;
if ( V_215 -> V_120 )
V_215 -> V_120 -> V_10 &= ~ V_221 ;
} else {
V_215 -> V_120 = V_144 -> V_120 ;
V_144 -> V_120 = V_215 ;
}
if ( V_215 -> V_10 & V_222 ) {
F_49 ( & V_61 , V_10 ) ;
V_204 = V_124 ;
V_209 = V_125 ;
V_158 = V_126 ;
F_50 ( & V_61 , V_10 ) ;
V_145 = V_215 ;
}
F_95 () ;
F_139 () ;
if ( V_216 &&
( ( V_215 -> V_10 & ( V_221 | V_217 ) ) == V_221 ) &&
! V_214 ) {
F_53 ( V_100 L_26 ,
V_215 -> V_177 , V_215 -> V_182 ) ;
F_71 (bcon)
if ( V_216 -> V_10 & V_217 )
F_140 ( V_216 ) ;
} else {
F_53 ( V_100 L_27 ,
( V_215 -> V_10 & V_217 ) ? L_28 : L_29 ,
V_215 -> V_177 , V_215 -> V_182 ) ;
}
}
int F_140 ( struct V_142 * V_142 )
{
struct V_142 * V_223 , * V_224 ;
int V_225 ;
V_225 = F_141 ( V_142 ) ;
if ( V_225 )
return V_225 ;
V_225 = 1 ;
F_113 () ;
if ( V_144 == V_142 ) {
V_144 = V_142 -> V_120 ;
V_225 = 0 ;
} else if ( V_144 ) {
for ( V_223 = V_144 -> V_120 , V_224 = V_144 ;
V_223 ; V_224 = V_223 , V_223 = V_224 -> V_120 ) {
if ( V_223 == V_142 ) {
V_224 -> V_120 = V_223 -> V_120 ;
V_225 = 0 ;
break;
}
}
}
if ( V_144 != NULL && V_142 -> V_10 & V_221 )
V_144 -> V_10 |= V_221 ;
F_95 () ;
F_139 () ;
return V_225 ;
}
static int T_9 F_142 ( void )
{
struct V_142 * V_143 ;
F_71 (con) {
if ( ! V_214 && V_143 -> V_10 & V_217 ) {
F_53 ( V_100 L_30 ,
V_143 -> V_177 , V_143 -> V_182 ) ;
F_140 ( V_143 ) ;
}
}
F_143 ( F_117 , 0 ) ;
return 0 ;
}
static void F_144 ( struct V_226 * V_226 )
{
int V_227 = F_145 ( V_228 , 0 ) ;
if ( V_227 & V_229 ) {
char * V_39 = F_146 ( V_230 ) ;
F_53 ( V_231 L_31 , V_39 ) ;
}
if ( V_227 & V_232 )
F_147 ( & V_66 ) ;
}
void F_128 ( void )
{
F_148 () ;
if ( F_149 ( & V_66 ) ) {
F_150 ( V_228 , V_232 ) ;
F_151 ( & F_146 ( V_233 ) ) ;
}
F_152 () ;
}
int F_153 ( const char * V_160 , ... )
{
unsigned long V_10 ;
T_11 args ;
char * V_39 ;
int V_173 ;
F_88 ( V_10 ) ;
V_39 = F_146 ( V_230 ) ;
va_start ( args , V_160 ) ;
V_173 = vsnprintf ( V_39 , V_234 , V_160 , args ) ;
va_end ( args ) ;
F_154 ( V_228 , V_229 ) ;
F_151 ( & F_146 ( V_233 ) ) ;
F_97 ( V_10 ) ;
return V_173 ;
}
int F_155 ( const char * V_235 )
{
return F_156 ( & V_236 , V_235 ) ;
}
bool F_157 ( unsigned long * V_237 ,
unsigned int V_238 )
{
if ( * V_237 == 0
|| ! F_158 ( V_111 , * V_237 ,
* V_237
+ F_58 ( V_238 ) ) ) {
* V_237 = V_111 ;
return true ;
}
return false ;
}
int F_159 ( struct V_239 * V_240 )
{
unsigned long V_10 ;
int V_87 = - V_241 ;
if ( ! V_240 -> V_242 )
return - V_44 ;
F_160 ( & V_243 , V_10 ) ;
if ( ! V_240 -> V_244 ) {
V_240 -> V_244 = 1 ;
F_161 ( & V_240 -> V_245 , & V_246 ) ;
V_87 = 0 ;
}
F_162 ( & V_243 , V_10 ) ;
return V_87 ;
}
int F_163 ( struct V_239 * V_240 )
{
unsigned long V_10 ;
int V_87 = - V_44 ;
F_160 ( & V_243 , V_10 ) ;
if ( V_240 -> V_244 ) {
V_240 -> V_244 = 0 ;
F_164 ( & V_240 -> V_245 ) ;
V_87 = 0 ;
}
F_162 ( & V_243 , V_10 ) ;
F_165 () ;
return V_87 ;
}
void F_166 ( enum V_247 V_248 )
{
struct V_239 * V_240 ;
unsigned long V_10 ;
if ( ( V_248 > V_249 ) && ! V_250 )
return;
F_167 () ;
F_168 (dumper, &dump_list, list) {
if ( V_240 -> V_251 && V_248 > V_240 -> V_251 )
continue;
V_240 -> V_252 = true ;
F_49 ( & V_61 , V_10 ) ;
V_240 -> V_253 = V_78 ;
V_240 -> V_254 = V_77 ;
V_240 -> V_129 = V_19 ;
V_240 -> V_255 = V_20 ;
F_50 ( & V_61 , V_10 ) ;
V_240 -> V_242 ( V_240 , V_248 ) ;
V_240 -> V_252 = false ;
}
F_169 () ;
}
bool F_170 ( struct V_239 * V_240 , bool V_115 ,
char * line , T_6 V_15 , T_6 * V_6 )
{
struct V_1 * V_2 ;
T_6 V_256 = 0 ;
bool V_42 = false ;
if ( ! V_240 -> V_252 )
goto V_50;
if ( V_240 -> V_253 < V_18 ) {
V_240 -> V_253 = V_18 ;
V_240 -> V_254 = V_21 ;
}
if ( V_240 -> V_253 >= V_19 )
goto V_50;
V_2 = F_3 ( V_240 -> V_254 ) ;
V_256 = F_64 ( V_2 , 0 , V_115 , line , V_15 ) ;
V_240 -> V_254 = F_4 ( V_240 -> V_254 ) ;
V_240 -> V_253 ++ ;
V_42 = true ;
V_50:
if ( V_6 )
* V_6 = V_256 ;
return V_42 ;
}
bool F_171 ( struct V_239 * V_240 , bool V_115 ,
char * line , T_6 V_15 , T_6 * V_6 )
{
unsigned long V_10 ;
bool V_42 ;
F_49 ( & V_61 , V_10 ) ;
V_42 = F_170 ( V_240 , V_115 , line , V_15 , V_6 ) ;
F_50 ( & V_61 , V_10 ) ;
return V_42 ;
}
bool F_172 ( struct V_239 * V_240 , bool V_115 ,
char * V_39 , T_6 V_15 , T_6 * V_6 )
{
unsigned long V_10 ;
T_2 V_62 ;
T_1 V_4 ;
T_2 V_129 ;
T_1 V_255 ;
enum V_9 V_69 ;
T_6 V_256 = 0 ;
bool V_42 = false ;
if ( ! V_240 -> V_252 )
goto V_50;
F_49 ( & V_61 , V_10 ) ;
if ( V_240 -> V_253 < V_18 ) {
V_240 -> V_253 = V_18 ;
V_240 -> V_254 = V_21 ;
}
if ( V_240 -> V_253 >= V_240 -> V_129 ) {
F_50 ( & V_61 , V_10 ) ;
goto V_50;
}
V_62 = V_240 -> V_253 ;
V_4 = V_240 -> V_254 ;
V_69 = 0 ;
while ( V_62 < V_240 -> V_129 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_256 += F_64 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_62 = V_240 -> V_253 ;
V_4 = V_240 -> V_254 ;
V_69 = 0 ;
while ( V_256 > V_15 && V_62 < V_240 -> V_129 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_256 -= F_64 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_129 = V_62 ;
V_255 = V_4 ;
V_256 = 0 ;
V_69 = 0 ;
while ( V_62 < V_240 -> V_129 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_256 += F_64 ( V_2 , V_69 , V_115 , V_39 + V_256 , V_15 - V_256 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_240 -> V_129 = V_129 ;
V_240 -> V_255 = V_255 ;
V_42 = true ;
F_50 ( & V_61 , V_10 ) ;
V_50:
if ( V_6 )
* V_6 = V_256 ;
return V_42 ;
}
void F_173 ( struct V_239 * V_240 )
{
V_240 -> V_253 = V_78 ;
V_240 -> V_254 = V_77 ;
V_240 -> V_129 = V_19 ;
V_240 -> V_255 = V_20 ;
}
void F_174 ( struct V_239 * V_240 )
{
unsigned long V_10 ;
F_49 ( & V_61 , V_10 ) ;
F_173 ( V_240 ) ;
F_50 ( & V_61 , V_10 ) ;
}
void T_9 F_175 ( const char * V_160 , ... )
{
T_11 args ;
va_start ( args , V_160 ) ;
vsnprintf ( V_257 , sizeof( V_257 ) ,
V_160 , args ) ;
va_end ( args ) ;
}
void F_176 ( const char * V_258 )
{
F_53 ( L_32 ,
V_258 , F_177 () , V_30 -> V_259 , V_30 -> V_31 ,
F_178 () , F_179 () -> V_260 ,
( int ) strcspn ( F_179 () -> V_261 , L_33 ) ,
F_179 () -> V_261 ) ;
if ( V_257 [ 0 ] != '\0' )
F_53 ( L_34 ,
V_258 , V_257 ) ;
F_180 ( V_258 , V_30 ) ;
}
void F_181 ( const char * V_258 )
{
F_176 ( V_258 ) ;
F_53 ( L_35 ,
V_258 , V_30 , F_182 () ,
F_183 ( V_30 ) ) ;
}
