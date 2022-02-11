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
if ( F_11 ( line , V_25 [ V_29 ] . V_36 , V_25 [ V_29 ] . V_37 ) ) {
V_31 = - V_38 ;
goto V_39;
}
line += V_25 [ V_29 ] . V_37 ;
}
line = V_28 ;
if ( line [ 0 ] == '<' ) {
char * V_40 = NULL ;
V_29 = F_12 ( line + 1 , & V_40 , 10 ) ;
if ( V_40 && V_40 [ 0 ] == '>' ) {
V_7 = V_29 & 7 ;
if ( V_29 >> 3 )
V_6 = V_29 >> 3 ;
V_40 ++ ;
V_5 -= V_40 - line ;
line = V_40 ;
}
}
line [ V_5 ] = '\0' ;
F_13 ( V_6 , V_7 , NULL , 0 , L_1 , line ) ;
V_39:
F_14 ( V_28 ) ;
return V_31 ;
}
static T_4 F_15 ( struct V_41 * V_41 , char T_7 * V_28 ,
T_6 V_26 , T_5 * V_42 )
{
struct V_43 * V_44 = V_41 -> V_45 ;
struct log * V_1 ;
T_2 V_46 ;
T_6 V_29 ;
char V_47 = '-' ;
T_6 V_5 ;
T_4 V_31 ;
if ( ! V_44 )
return - V_48 ;
V_31 = F_16 ( & V_44 -> V_49 ) ;
if ( V_31 )
return V_31 ;
F_17 ( & V_50 ) ;
while ( V_44 -> V_51 == V_18 ) {
if ( V_41 -> V_52 & V_53 ) {
V_31 = - V_54 ;
F_18 ( & V_50 ) ;
goto V_39;
}
F_18 ( & V_50 ) ;
V_31 = F_19 ( V_55 ,
V_44 -> V_51 != V_18 ) ;
if ( V_31 )
goto V_39;
F_17 ( & V_50 ) ;
}
if ( V_44 -> V_51 < V_17 ) {
V_44 -> V_3 = V_20 ;
V_44 -> V_51 = V_17 ;
V_31 = - V_56 ;
F_18 ( & V_50 ) ;
goto V_39;
}
V_1 = F_3 ( V_44 -> V_3 ) ;
V_46 = V_1 -> V_10 ;
F_20 ( V_46 , 1000 ) ;
if ( V_1 -> V_9 & V_57 && ! ( V_44 -> V_58 & V_57 ) )
V_47 = 'c' ;
else if ( ( V_1 -> V_9 & V_57 ) ||
( ( V_44 -> V_58 & V_57 ) && ! ( V_1 -> V_9 & V_59 ) ) )
V_47 = '+' ;
V_5 = sprintf ( V_44 -> V_28 , L_2 ,
( V_1 -> V_6 << 3 ) | V_1 -> V_7 ,
V_44 -> V_51 , V_46 , V_47 ) ;
V_44 -> V_58 = V_1 -> V_9 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_2 ; V_29 ++ ) {
unsigned char V_60 = F_1 ( V_1 ) [ V_29 ] ;
if ( V_60 < ' ' || V_60 >= 127 || V_60 == '\\' )
V_5 += sprintf ( V_44 -> V_28 + V_5 , L_3 , V_60 ) ;
else
V_44 -> V_28 [ V_5 ++ ] = V_60 ;
}
V_44 -> V_28 [ V_5 ++ ] = '\n' ;
if ( V_1 -> V_12 ) {
bool line = true ;
for ( V_29 = 0 ; V_29 < V_1 -> V_12 ; V_29 ++ ) {
unsigned char V_60 = F_2 ( V_1 ) [ V_29 ] ;
if ( line ) {
V_44 -> V_28 [ V_5 ++ ] = ' ' ;
line = false ;
}
if ( V_60 == '\0' ) {
V_44 -> V_28 [ V_5 ++ ] = '\n' ;
line = true ;
continue;
}
if ( V_60 < ' ' || V_60 >= 127 || V_60 == '\\' ) {
V_5 += sprintf ( V_44 -> V_28 + V_5 , L_3 , V_60 ) ;
continue;
}
V_44 -> V_28 [ V_5 ++ ] = V_60 ;
}
V_44 -> V_28 [ V_5 ++ ] = '\n' ;
}
V_44 -> V_3 = F_4 ( V_44 -> V_3 ) ;
V_44 -> V_51 ++ ;
F_18 ( & V_50 ) ;
if ( V_5 > V_26 ) {
V_31 = - V_33 ;
goto V_39;
}
if ( F_21 ( V_28 , V_44 -> V_28 , V_5 ) ) {
V_31 = - V_38 ;
goto V_39;
}
V_31 = V_5 ;
V_39:
F_22 ( & V_44 -> V_49 ) ;
return V_31 ;
}
static T_5 F_23 ( struct V_41 * V_41 , T_5 V_61 , int V_62 )
{
struct V_43 * V_44 = V_41 -> V_45 ;
T_5 V_31 = 0 ;
if ( ! V_44 )
return - V_48 ;
if ( V_61 )
return - V_63 ;
F_17 ( & V_50 ) ;
switch ( V_62 ) {
case V_64 :
V_44 -> V_3 = V_20 ;
V_44 -> V_51 = V_17 ;
break;
case V_65 :
V_44 -> V_3 = V_66 ;
V_44 -> V_51 = V_67 ;
break;
case V_68 :
V_44 -> V_3 = V_19 ;
V_44 -> V_51 = V_18 ;
break;
default:
V_31 = - V_33 ;
}
F_18 ( & V_50 ) ;
return V_31 ;
}
static unsigned int F_24 ( struct V_41 * V_41 , T_8 * V_69 )
{
struct V_43 * V_44 = V_41 -> V_45 ;
int V_31 = 0 ;
if ( ! V_44 )
return V_70 | V_71 ;
F_25 ( V_41 , & V_55 , V_69 ) ;
F_17 ( & V_50 ) ;
if ( V_44 -> V_51 < V_18 ) {
if ( V_44 -> V_51 < V_17 )
V_31 = V_72 | V_73 | V_70 | V_74 ;
V_31 = V_72 | V_73 ;
}
F_18 ( & V_50 ) ;
return V_31 ;
}
static int F_26 ( struct V_75 * V_75 , struct V_41 * V_41 )
{
struct V_43 * V_44 ;
int V_76 ;
if ( ( V_41 -> V_52 & V_77 ) == V_78 )
return 0 ;
V_76 = F_27 ( V_79 ) ;
if ( V_76 )
return V_76 ;
V_44 = F_10 ( sizeof( struct V_43 ) , V_34 ) ;
if ( ! V_44 )
return - V_35 ;
F_28 ( & V_44 -> V_49 ) ;
F_17 ( & V_50 ) ;
V_44 -> V_3 = V_20 ;
V_44 -> V_51 = V_17 ;
F_18 ( & V_50 ) ;
V_41 -> V_45 = V_44 ;
return 0 ;
}
static int F_29 ( struct V_75 * V_75 , struct V_41 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 ;
if ( ! V_44 )
return 0 ;
F_30 ( & V_44 -> V_49 ) ;
F_14 ( V_44 ) ;
return 0 ;
}
void F_31 ( void )
{
F_32 ( V_4 ) ;
F_32 ( V_21 ) ;
F_32 ( V_20 ) ;
F_32 ( V_19 ) ;
F_33 ( log ) ;
F_34 ( log , V_10 ) ;
F_34 ( log , V_5 ) ;
F_34 ( log , V_2 ) ;
F_34 ( log , V_12 ) ;
}
static int T_9 F_35 ( char * V_80 )
{
unsigned V_14 = F_36 ( V_80 , & V_80 ) ;
if ( V_14 )
V_14 = F_37 ( V_14 ) ;
if ( V_14 > V_21 )
V_81 = V_14 ;
return 0 ;
}
void T_9 F_38 ( int V_82 )
{
unsigned long V_9 ;
char * V_83 ;
int free ;
if ( ! V_81 )
return;
if ( V_82 ) {
unsigned long V_84 ;
V_84 = F_39 ( V_81 , V_85 ) ;
if ( ! V_84 )
return;
V_83 = F_40 ( V_84 ) ;
} else {
V_83 = F_41 ( V_81 ) ;
}
if ( F_42 ( ! V_83 ) ) {
F_43 ( L_4 ,
V_81 ) ;
return;
}
F_44 ( & V_50 , V_9 ) ;
V_21 = V_81 ;
V_4 = V_83 ;
V_81 = 0 ;
free = V_86 - V_19 ;
memcpy ( V_4 , V_87 , V_86 ) ;
F_45 ( & V_50 , V_9 ) ;
F_46 ( L_5 , V_21 ) ;
F_46 ( L_6 ,
free , ( free * 100 ) / V_86 ) ;
}
static int T_9 F_47 ( char * V_80 )
{
V_88 = 1 ;
F_48 ( V_89 L_7 ) ;
return 0 ;
}
static int T_9 F_49 ( char * V_80 )
{
unsigned long V_90 ;
V_90 = V_91 ? V_91 : 1000000 ;
V_92 = ( unsigned long long ) V_90 / 1000 * V_93 ;
F_50 ( & V_80 , & V_94 ) ;
if ( V_94 > 10 * 1000 )
V_94 = 0 ;
F_51 ( L_8
L_9 ,
V_94 , V_91 , V_90 , V_93 , V_92 ) ;
return 1 ;
}
static void F_52 ( int V_7 )
{
unsigned long long V_95 ;
unsigned long V_96 ;
if ( ( V_94 == 0 || V_97 != V_98 )
|| ( V_7 >= V_99 && ! V_88 ) ) {
return;
}
V_95 = ( unsigned long long ) V_92 * V_94 ;
V_96 = V_100 + F_53 ( V_94 ) ;
while ( V_95 ) {
V_95 -- ;
F_54 () ;
if ( F_55 ( V_100 , V_96 ) )
break;
F_56 () ;
}
}
static inline void F_52 ( int V_7 )
{
}
static int F_57 ( int type )
{
if ( V_101 )
return 1 ;
return type != V_79 && type != V_102 ;
}
static int F_58 ( int type , bool V_103 )
{
if ( V_103 && type != V_104 )
return 0 ;
if ( F_57 ( type ) ) {
if ( F_59 ( V_105 ) )
return 0 ;
if ( F_59 ( V_106 ) ) {
F_60 ( V_107 L_10
L_11
L_12 ,
V_108 -> V_109 , F_61 ( V_108 ) ) ;
return 0 ;
}
return - V_110 ;
}
return 0 ;
}
static T_6 F_62 ( T_2 V_111 , char * V_28 )
{
unsigned long V_112 ;
if ( ! V_113 )
return 0 ;
V_112 = F_20 ( V_111 , 1000000000 ) ;
if ( ! V_28 )
return snprintf ( NULL , 0 , L_13 , ( unsigned long ) V_111 ) ;
return sprintf ( V_28 , L_14 ,
( unsigned long ) V_111 , V_112 / 1000 ) ;
}
static T_6 F_63 ( const struct log * V_1 , bool V_114 , char * V_28 )
{
T_6 V_5 = 0 ;
unsigned int V_115 = ( V_1 -> V_6 << 3 ) | V_1 -> V_7 ;
if ( V_114 ) {
if ( V_28 ) {
V_5 += sprintf ( V_28 , L_15 , V_115 ) ;
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
V_5 += F_62 ( V_1 -> V_10 , V_28 ? V_28 + V_5 : NULL ) ;
return V_5 ;
}
static T_6 F_64 ( const struct log * V_1 , enum V_8 V_58 ,
bool V_114 , char * V_28 , T_6 V_14 )
{
const char * V_13 = F_1 ( V_1 ) ;
T_6 V_116 = V_1 -> V_2 ;
bool V_115 = true ;
bool V_117 = true ;
T_6 V_5 = 0 ;
if ( ( V_58 & V_57 ) && ! ( V_1 -> V_9 & V_59 ) )
V_115 = false ;
if ( V_1 -> V_9 & V_57 ) {
if ( ( V_58 & V_57 ) && ! ( V_58 & V_118 ) )
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
if ( V_28 ) {
if ( F_63 ( V_1 , V_114 , NULL ) +
V_2 + 1 >= V_14 - V_5 )
break;
if ( V_115 )
V_5 += F_63 ( V_1 , V_114 , V_28 + V_5 ) ;
memcpy ( V_28 + V_5 , V_13 , V_2 ) ;
V_5 += V_2 ;
if ( V_119 || V_117 )
V_28 [ V_5 ++ ] = '\n' ;
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
static int F_65 ( char T_7 * V_28 , int V_14 )
{
char * V_13 ;
struct log * V_1 ;
int V_5 = 0 ;
V_13 = F_10 ( V_32 + V_120 , V_34 ) ;
if ( ! V_13 )
return - V_35 ;
while ( V_14 > 0 ) {
T_6 V_121 ;
T_6 V_122 ;
F_17 ( & V_50 ) ;
if ( V_123 < V_17 ) {
V_123 = V_17 ;
V_124 = V_20 ;
V_125 = 0 ;
V_126 = 0 ;
}
if ( V_123 == V_18 ) {
F_18 ( & V_50 ) ;
break;
}
V_122 = V_126 ;
V_1 = F_3 ( V_124 ) ;
V_121 = F_64 ( V_1 , V_125 , true , V_13 ,
V_32 + V_120 ) ;
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
F_18 ( & V_50 ) ;
if ( ! V_121 )
break;
if ( F_21 ( V_28 , V_13 + V_122 , V_121 ) ) {
if ( ! V_5 )
V_5 = - V_38 ;
break;
}
V_5 += V_121 ;
V_14 -= V_121 ;
V_28 += V_121 ;
}
F_14 ( V_13 ) ;
return V_5 ;
}
static int F_66 ( char T_7 * V_28 , int V_14 , bool V_127 )
{
char * V_13 ;
int V_5 = 0 ;
V_13 = F_10 ( V_32 + V_120 , V_34 ) ;
if ( ! V_13 )
return - V_35 ;
F_17 ( & V_50 ) ;
if ( V_28 ) {
T_2 V_128 ;
T_2 V_51 ;
T_1 V_3 ;
enum V_8 V_58 ;
if ( V_67 < V_17 ) {
V_67 = V_17 ;
V_66 = V_20 ;
}
V_51 = V_67 ;
V_3 = V_66 ;
V_58 = 0 ;
while ( V_51 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_5 += F_64 ( V_1 , V_58 , true , NULL , 0 ) ;
V_58 = V_1 -> V_9 ;
V_3 = F_4 ( V_3 ) ;
V_51 ++ ;
}
V_51 = V_67 ;
V_3 = V_66 ;
V_58 = 0 ;
while ( V_5 > V_14 && V_51 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_5 -= F_64 ( V_1 , V_58 , true , NULL , 0 ) ;
V_58 = V_1 -> V_9 ;
V_3 = F_4 ( V_3 ) ;
V_51 ++ ;
}
V_128 = V_18 ;
V_5 = 0 ;
V_58 = 0 ;
while ( V_5 >= 0 && V_51 < V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
int V_129 ;
V_129 = F_64 ( V_1 , V_58 , true , V_13 ,
V_32 + V_120 ) ;
if ( V_129 < 0 ) {
V_5 = V_129 ;
break;
}
V_3 = F_4 ( V_3 ) ;
V_51 ++ ;
V_58 = V_1 -> V_9 ;
F_18 ( & V_50 ) ;
if ( F_21 ( V_28 + V_5 , V_13 , V_129 ) )
V_5 = - V_38 ;
else
V_5 += V_129 ;
F_17 ( & V_50 ) ;
if ( V_51 < V_17 ) {
V_51 = V_17 ;
V_3 = V_20 ;
V_58 = 0 ;
}
}
}
if ( V_127 ) {
V_67 = V_18 ;
V_66 = V_19 ;
}
F_18 ( & V_50 ) ;
F_14 ( V_13 ) ;
return V_5 ;
}
int F_67 ( int type , char T_7 * V_28 , int V_5 , bool V_103 )
{
bool V_127 = false ;
static int V_130 = - 1 ;
int error ;
error = F_58 ( type , V_103 ) ;
if ( error )
goto V_39;
error = F_27 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_131 :
break;
case V_104 :
break;
case V_132 :
error = - V_33 ;
if ( ! V_28 || V_5 < 0 )
goto V_39;
error = 0 ;
if ( ! V_5 )
goto V_39;
if ( ! F_68 ( V_133 , V_28 , V_5 ) ) {
error = - V_38 ;
goto V_39;
}
error = F_19 ( V_55 ,
V_123 != V_18 ) ;
if ( error )
goto V_39;
error = F_65 ( V_28 , V_5 ) ;
break;
case V_134 :
V_127 = true ;
case V_79 :
error = - V_33 ;
if ( ! V_28 || V_5 < 0 )
goto V_39;
error = 0 ;
if ( ! V_5 )
goto V_39;
if ( ! F_68 ( V_133 , V_28 , V_5 ) ) {
error = - V_38 ;
goto V_39;
}
error = F_66 ( V_28 , V_5 , V_127 ) ;
break;
case V_135 :
F_66 ( NULL , 0 , true ) ;
break;
case V_136 :
if ( V_130 == - 1 )
V_130 = V_99 ;
V_99 = V_137 ;
break;
case V_138 :
if ( V_130 != - 1 ) {
V_99 = V_130 ;
V_130 = - 1 ;
}
break;
case V_139 :
error = - V_33 ;
if ( V_5 < 1 || V_5 > 8 )
goto V_39;
if ( V_5 < V_137 )
V_5 = V_137 ;
V_99 = V_5 ;
V_130 = - 1 ;
error = 0 ;
break;
case V_140 :
F_17 ( & V_50 ) ;
if ( V_123 < V_17 ) {
V_123 = V_17 ;
V_124 = V_20 ;
V_125 = 0 ;
V_126 = 0 ;
}
if ( V_103 ) {
error = V_19 - V_124 ;
} else {
T_2 V_51 = V_123 ;
T_1 V_3 = V_124 ;
enum V_8 V_58 = V_125 ;
error = 0 ;
while ( V_51 < V_18 ) {
struct log * V_1 = F_3 ( V_3 ) ;
error += F_64 ( V_1 , V_58 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_51 ++ ;
V_58 = V_1 -> V_9 ;
}
error -= V_126 ;
}
F_18 ( & V_50 ) ;
break;
case V_102 :
error = V_21 ;
break;
default:
error = - V_33 ;
break;
}
V_39:
return error ;
}
static void F_69 ( int V_7 , const char * V_13 , T_6 V_5 )
{
struct V_141 * V_142 ;
F_70 ( V_13 , 0 , V_5 , V_5 ) ;
if ( V_7 >= V_99 && ! V_88 )
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
if ( F_75 ( V_100 , V_148 ) &&
! F_55 ( V_100 , V_148 + 30 * V_93 ) )
return;
V_148 = V_100 ;
F_76 () ;
F_77 ( & V_50 ) ;
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
if ( F_42 ( V_151 ) ) {
int V_152 = V_151 ;
while ( V_152 -- ) {
F_83 ( 1 ) ;
F_56 () ;
}
}
}
static void F_84 ( enum V_8 V_9 )
{
if ( V_47 . V_153 )
return;
if ( V_47 . V_5 == 0 )
return;
if ( V_47 . V_154 ) {
F_5 ( V_47 . V_6 , V_47 . V_7 , V_9 | V_155 ,
V_47 . V_10 , NULL , 0 , V_47 . V_28 , V_47 . V_5 ) ;
V_47 . V_9 = V_9 ;
V_47 . V_153 = true ;
} else {
F_5 ( V_47 . V_6 , V_47 . V_7 , V_9 , 0 ,
NULL , 0 , V_47 . V_28 , V_47 . V_5 ) ;
V_47 . V_5 = 0 ;
}
}
static bool F_85 ( int V_6 , int V_7 , const char * V_13 , T_6 V_5 )
{
if ( V_47 . V_5 && V_47 . V_153 )
return false ;
if ( V_47 . V_5 + V_5 > sizeof( V_47 . V_28 ) ) {
F_84 ( V_57 ) ;
return false ;
}
if ( ! V_47 . V_5 ) {
V_47 . V_6 = V_6 ;
V_47 . V_7 = V_7 ;
V_47 . V_156 = V_108 ;
V_47 . V_10 = F_7 () ;
V_47 . V_9 = 0 ;
V_47 . V_154 = 0 ;
V_47 . V_153 = false ;
}
memcpy ( V_47 . V_28 + V_47 . V_5 , V_13 , V_5 ) ;
V_47 . V_5 += V_5 ;
if ( V_47 . V_5 > ( sizeof( V_47 . V_28 ) * 80 ) / 100 )
F_84 ( V_57 ) ;
return true ;
}
static T_6 F_86 ( char * V_13 , T_6 V_14 )
{
T_6 V_129 = 0 ;
T_6 V_5 ;
if ( V_47 . V_154 == 0 && ( V_157 & V_118 ) ) {
V_129 += F_62 ( V_47 . V_10 , V_13 ) ;
V_14 -= V_129 ;
}
V_5 = V_47 . V_5 - V_47 . V_154 ;
if ( V_5 > 0 ) {
if ( V_5 + 1 > V_14 )
V_5 = V_14 - 1 ;
memcpy ( V_13 + V_129 , V_47 . V_28 + V_47 . V_154 , V_5 ) ;
V_129 += V_5 ;
V_47 . V_154 = V_47 . V_5 ;
}
if ( V_47 . V_153 ) {
if ( V_47 . V_9 & V_118 )
V_13 [ V_129 ++ ] = '\n' ;
V_47 . V_5 = 0 ;
}
return V_129 ;
}
T_10 int F_87 ( int V_6 , int V_7 ,
const char * V_11 , T_6 V_158 ,
const char * V_159 , T_11 args )
{
static int V_160 ;
static char V_161 [ V_32 ] ;
char * V_13 = V_161 ;
T_6 V_2 ;
enum V_8 V_162 = 0 ;
unsigned long V_9 ;
int V_163 ;
int V_164 = 0 ;
F_52 ( V_7 ) ;
F_82 () ;
F_88 ( V_9 ) ;
V_163 = F_73 () ;
if ( F_42 ( V_165 == V_163 ) ) {
if ( ! V_166 && ! F_89 ( V_108 ) ) {
V_160 = 1 ;
goto V_167;
}
F_74 () ;
}
F_90 () ;
F_91 ( & V_50 ) ;
V_165 = V_163 ;
if ( V_160 ) {
static const char V_168 [] =
L_16 ;
V_160 = 0 ;
V_164 += strlen ( V_168 ) ;
F_5 ( 0 , 2 , V_59 | V_118 , 0 ,
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
V_162 |= V_59 ;
case 'c' :
break;
}
V_2 -= V_170 - V_13 ;
V_13 = ( char * ) V_170 ;
}
}
if ( V_7 == - 1 )
V_7 = V_30 ;
if ( V_11 )
V_162 |= V_59 | V_118 ;
if ( ! ( V_162 & V_118 ) ) {
if ( V_47 . V_5 && ( V_162 & V_59 || V_47 . V_156 != V_108 ) )
F_84 ( V_118 ) ;
if ( ! F_85 ( V_6 , V_7 , V_13 , V_2 ) )
F_5 ( V_6 , V_7 , V_162 | V_57 , 0 ,
V_11 , V_158 , V_13 , V_2 ) ;
} else {
bool V_171 = false ;
if ( V_47 . V_5 && V_47 . V_156 == V_108 ) {
if ( ! ( V_162 & V_59 ) )
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
T_10 int F_13 ( int V_6 , int V_7 ,
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
T_10 int F_48 ( const char * V_159 , ... )
{
T_11 args ;
int V_172 ;
#ifdef F_99
if ( F_42 ( V_173 ) ) {
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
static T_6 F_64 ( const struct log * V_1 , enum V_8 V_58 ,
bool V_114 , char * V_28 , T_6 V_14 ) { return 0 ; }
static T_6 F_86 ( char * V_13 , T_6 V_14 ) { return 0 ; }
static int F_101 ( char * V_174 , int V_3 , char * V_175 ,
char * V_176 )
{
struct V_177 * V_60 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_178 && V_177 [ V_29 ] . V_174 [ 0 ] ; V_29 ++ )
if ( strcmp ( V_177 [ V_29 ] . V_174 , V_174 ) == 0 &&
V_177 [ V_29 ] . V_179 == V_3 ) {
if ( ! V_176 )
V_180 = V_29 ;
return 0 ;
}
if ( V_29 == V_178 )
return - V_181 ;
if ( ! V_176 )
V_180 = V_29 ;
V_60 = & V_177 [ V_29 ] ;
F_102 ( V_60 -> V_174 , V_174 , sizeof( V_60 -> V_174 ) ) ;
V_60 -> V_175 = V_175 ;
#ifdef F_103
V_60 -> V_176 = V_176 ;
#endif
V_60 -> V_179 = V_3 ;
return 0 ;
}
static int T_9 F_104 ( char * V_80 )
{
char V_28 [ sizeof( V_177 [ 0 ] . V_174 ) + 4 ] ;
char * V_182 , * V_175 , * V_176 = NULL ;
int V_3 ;
#ifdef F_103
if ( ! memcmp ( V_80 , L_17 , 4 ) ) {
V_176 = L_18 ;
V_80 += 4 ;
} else if ( ! memcmp ( V_80 , L_19 , 4 ) ) {
V_176 = V_80 + 4 ;
V_80 = strchr ( V_176 , ',' ) ;
if ( ! V_80 ) {
F_48 ( V_183 L_20 ) ;
return 1 ;
}
* ( V_80 ++ ) = 0 ;
}
#endif
if ( V_80 [ 0 ] >= '0' && V_80 [ 0 ] <= '9' ) {
strcpy ( V_28 , L_21 ) ;
strncpy ( V_28 + 4 , V_80 , sizeof( V_28 ) - 5 ) ;
} else {
strncpy ( V_28 , V_80 , sizeof( V_28 ) - 1 ) ;
}
V_28 [ sizeof( V_28 ) - 1 ] = 0 ;
if ( ( V_175 = strchr ( V_80 , ',' ) ) != NULL )
* ( V_175 ++ ) = 0 ;
#ifdef F_105
if ( ! strcmp ( V_80 , L_22 ) )
strcpy ( V_28 , L_23 ) ;
if ( ! strcmp ( V_80 , L_24 ) )
strcpy ( V_28 , L_25 ) ;
#endif
for ( V_182 = V_28 ; * V_182 ; V_182 ++ )
if ( ( * V_182 >= '0' && * V_182 <= '9' ) || * V_182 == ',' )
break;
V_3 = F_12 ( V_182 , NULL , 10 ) ;
* V_182 = 0 ;
F_101 ( V_28 , V_3 , V_175 , V_176 ) ;
V_184 = 1 ;
return 1 ;
}
int F_106 ( char * V_174 , int V_3 , char * V_175 )
{
return F_101 ( V_174 , V_3 , V_175 , NULL ) ;
}
int F_107 ( char * V_174 , int V_3 , char * V_185 , int V_186 , char * V_175 )
{
struct V_177 * V_60 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_178 && V_177 [ V_29 ] . V_174 [ 0 ] ; V_29 ++ )
if ( strcmp ( V_177 [ V_29 ] . V_174 , V_174 ) == 0 &&
V_177 [ V_29 ] . V_179 == V_3 ) {
V_60 = & V_177 [ V_29 ] ;
F_102 ( V_60 -> V_174 , V_185 , sizeof( V_60 -> V_174 ) ) ;
V_60 -> V_174 [ sizeof( V_60 -> V_174 ) - 1 ] = 0 ;
V_60 -> V_175 = V_175 ;
V_60 -> V_179 = V_186 ;
return V_29 ;
}
return - 1 ;
}
static int T_9 F_108 ( char * V_80 )
{
V_187 = 0 ;
return 1 ;
}
void F_109 ( void )
{
if ( ! V_187 )
return;
F_48 ( L_26 ) ;
F_110 () ;
V_188 = 1 ;
F_111 ( & V_149 ) ;
}
void F_112 ( void )
{
if ( ! V_187 )
return;
F_113 ( & V_149 ) ;
V_188 = 0 ;
F_95 () ;
}
static int T_12 F_114 ( struct V_189 * V_190 ,
unsigned long V_191 , void * V_192 )
{
switch ( V_191 ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
F_110 () ;
F_95 () ;
}
return V_197 ;
}
void F_110 ( void )
{
F_115 () ;
F_113 ( & V_149 ) ;
if ( V_188 )
return;
V_198 = 1 ;
V_199 = 1 ;
F_116 ( & V_200 , 0 , 0 , V_201 ) ;
}
int F_117 ( void )
{
if ( F_118 ( & V_149 ) )
return 0 ;
if ( V_188 ) {
F_111 ( & V_149 ) ;
return 0 ;
}
V_198 = 1 ;
V_199 = 0 ;
F_116 ( & V_200 , 0 , 1 , V_201 ) ;
return 1 ;
}
int F_119 ( void )
{
return V_198 ;
}
static void F_120 ( char * V_13 , T_6 V_14 )
{
unsigned long V_9 ;
T_6 V_5 ;
F_44 ( & V_50 , V_9 ) ;
if ( ! V_47 . V_5 )
goto V_39;
if ( V_202 < V_18 && ! V_47 . V_154 )
goto V_39;
V_5 = F_86 ( V_13 , V_14 ) ;
F_121 ( & V_50 ) ;
F_122 () ;
F_69 ( V_47 . V_7 , V_13 , V_5 ) ;
F_123 () ;
F_97 ( V_9 ) ;
return;
V_39:
F_45 ( & V_50 , V_9 ) ;
}
void F_95 ( void )
{
static char V_13 [ V_32 + V_120 ] ;
static T_2 V_203 ;
unsigned long V_9 ;
bool V_204 = false ;
bool V_205 ;
if ( V_188 ) {
F_111 ( & V_149 ) ;
return;
}
V_199 = 0 ;
F_120 ( V_13 , sizeof( V_13 ) ) ;
V_206:
for (; ; ) {
struct log * V_1 ;
T_6 V_5 ;
int V_7 ;
F_44 ( & V_50 , V_9 ) ;
if ( V_203 != V_18 ) {
V_204 = true ;
V_203 = V_18 ;
}
if ( V_202 < V_17 ) {
V_202 = V_17 ;
V_207 = V_20 ;
V_157 = 0 ;
}
V_122:
if ( V_202 == V_18 )
break;
V_1 = F_3 ( V_207 ) ;
if ( V_1 -> V_9 & V_155 ) {
V_207 = F_4 ( V_207 ) ;
V_202 ++ ;
V_1 -> V_9 &= ~ V_155 ;
V_157 = V_1 -> V_9 ;
goto V_122;
}
V_7 = V_1 -> V_7 ;
V_5 = F_64 ( V_1 , V_157 , false ,
V_13 , sizeof( V_13 ) ) ;
V_207 = F_4 ( V_207 ) ;
V_202 ++ ;
V_157 = V_1 -> V_9 ;
F_121 ( & V_50 ) ;
F_122 () ;
F_69 ( V_7 , V_13 , V_5 ) ;
F_123 () ;
F_97 ( V_9 ) ;
}
V_198 = 0 ;
F_124 ( & V_200 , 1 , V_201 ) ;
if ( F_42 ( V_144 ) )
V_144 = NULL ;
F_121 ( & V_50 ) ;
F_111 ( & V_149 ) ;
F_91 ( & V_50 ) ;
V_205 = V_202 != V_18 ;
F_45 ( & V_50 , V_9 ) ;
if ( V_205 && F_117 () )
goto V_206;
if ( V_204 )
F_125 () ;
}
void T_13 F_126 ( void )
{
if ( V_199 )
F_127 () ;
}
void F_128 ( void )
{
struct V_141 * V_60 ;
if ( V_166 ) {
if ( F_118 ( & V_149 ) != 0 )
return;
} else
F_110 () ;
V_198 = 1 ;
V_199 = 0 ;
F_71 (c)
if ( ( V_60 -> V_9 & V_145 ) && V_60 -> V_208 )
V_60 -> V_208 () ;
F_95 () ;
}
struct V_209 * F_129 ( int * V_179 )
{
struct V_141 * V_60 ;
struct V_209 * V_210 = NULL ;
F_110 () ;
F_71 (c) {
if ( ! V_60 -> V_211 )
continue;
V_210 = V_60 -> V_211 ( V_60 , V_179 ) ;
if ( V_210 )
break;
}
F_95 () ;
return V_210 ;
}
void F_130 ( struct V_141 * V_141 )
{
F_110 () ;
V_141 -> V_9 &= ~ V_145 ;
F_95 () ;
}
void F_131 ( struct V_141 * V_141 )
{
F_110 () ;
V_141 -> V_9 |= V_145 ;
F_95 () ;
}
static int T_9 F_132 ( char * V_80 )
{
V_212 = 1 ;
F_48 ( V_89 L_27 ) ;
return 0 ;
}
void F_133 ( struct V_141 * V_213 )
{
int V_29 ;
unsigned long V_9 ;
struct V_141 * V_214 = NULL ;
if ( V_143 && V_213 -> V_9 & V_215 ) {
F_71 (bcon) {
if ( ! ( V_214 -> V_9 & V_215 ) ) {
F_48 ( V_89 L_28 ,
V_213 -> V_174 , V_213 -> V_179 ) ;
return;
}
}
}
if ( V_143 && V_143 -> V_9 & V_215 )
V_214 = V_143 ;
if ( V_216 < 0 || V_214 || ! V_143 )
V_216 = V_180 ;
if ( V_213 -> V_217 )
V_213 -> V_217 () ;
if ( V_216 < 0 ) {
if ( V_213 -> V_179 < 0 )
V_213 -> V_179 = 0 ;
if ( V_213 -> V_218 == NULL ||
V_213 -> V_218 ( V_213 , NULL ) == 0 ) {
V_213 -> V_9 |= V_145 ;
if ( V_213 -> V_211 ) {
V_213 -> V_9 |= V_219 ;
V_216 = 0 ;
}
}
}
for ( V_29 = 0 ; V_29 < V_178 && V_177 [ V_29 ] . V_174 [ 0 ] ;
V_29 ++ ) {
if ( strcmp ( V_177 [ V_29 ] . V_174 , V_213 -> V_174 ) != 0 )
continue;
if ( V_213 -> V_179 >= 0 &&
V_213 -> V_179 != V_177 [ V_29 ] . V_179 )
continue;
if ( V_213 -> V_179 < 0 )
V_213 -> V_179 = V_177 [ V_29 ] . V_179 ;
#ifdef F_103
if ( V_177 [ V_29 ] . V_176 ) {
V_213 -> V_9 |= V_220 ;
F_134 ( V_213 ,
V_177 [ V_29 ] . V_179 ,
V_177 [ V_29 ] . V_175 ,
V_177 [ V_29 ] . V_176 ) ;
return;
}
#endif
if ( V_213 -> V_218 &&
V_213 -> V_218 ( V_213 , V_177 [ V_29 ] . V_175 ) != 0 )
break;
V_213 -> V_9 |= V_145 ;
V_213 -> V_179 = V_177 [ V_29 ] . V_179 ;
if ( V_29 == V_180 ) {
V_213 -> V_9 |= V_219 ;
V_216 = V_180 ;
}
break;
}
if ( ! ( V_213 -> V_9 & V_145 ) )
return;
if ( V_214 && ( ( V_213 -> V_9 & ( V_219 | V_215 ) ) == V_219 ) )
V_213 -> V_9 &= ~ V_221 ;
F_110 () ;
if ( ( V_213 -> V_9 & V_219 ) || V_143 == NULL ) {
V_213 -> V_119 = V_143 ;
V_143 = V_213 ;
if ( V_213 -> V_119 )
V_213 -> V_119 -> V_9 &= ~ V_219 ;
} else {
V_213 -> V_119 = V_143 -> V_119 ;
V_143 -> V_119 = V_213 ;
}
if ( V_213 -> V_9 & V_221 ) {
F_44 ( & V_50 , V_9 ) ;
V_202 = V_123 ;
V_207 = V_124 ;
V_157 = V_125 ;
F_45 ( & V_50 , V_9 ) ;
V_144 = V_213 ;
}
F_95 () ;
F_135 () ;
if ( V_214 &&
( ( V_213 -> V_9 & ( V_219 | V_215 ) ) == V_219 ) &&
! V_212 ) {
F_48 ( V_89 L_29 ,
V_213 -> V_174 , V_213 -> V_179 ) ;
F_71 (bcon)
if ( V_214 -> V_9 & V_215 )
F_136 ( V_214 ) ;
} else {
F_48 ( V_89 L_30 ,
( V_213 -> V_9 & V_215 ) ? L_31 : L_18 ,
V_213 -> V_174 , V_213 -> V_179 ) ;
}
}
int F_136 ( struct V_141 * V_141 )
{
struct V_141 * V_222 , * V_223 ;
int V_224 = 1 ;
#ifdef F_103
if ( V_141 -> V_9 & V_220 )
return F_137 ( V_141 ) ;
#endif
F_110 () ;
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
if ( V_143 != NULL && V_141 -> V_9 & V_219 )
V_143 -> V_9 |= V_219 ;
F_95 () ;
F_135 () ;
return V_224 ;
}
static int T_9 F_138 ( void )
{
struct V_141 * V_142 ;
F_71 (con) {
if ( ! V_212 && V_142 -> V_9 & V_215 ) {
F_48 ( V_89 L_32 ,
V_142 -> V_174 , V_142 -> V_179 ) ;
F_136 ( V_142 ) ;
}
}
F_139 ( F_114 , 0 ) ;
return 0 ;
}
static void F_140 ( struct V_225 * V_225 )
{
int V_226 = F_141 ( V_227 , 0 ) ;
if ( V_226 & V_228 ) {
char * V_28 = F_142 ( V_229 ) ;
F_48 ( V_107 L_33 , V_28 ) ;
}
if ( V_226 & V_230 )
F_143 ( & V_55 ) ;
}
void F_125 ( void )
{
F_144 () ;
if ( F_145 ( & V_55 ) ) {
F_146 ( V_227 , V_230 ) ;
F_147 ( & F_142 ( V_231 ) ) ;
}
F_148 () ;
}
int F_149 ( const char * V_159 , ... )
{
unsigned long V_9 ;
T_11 args ;
char * V_28 ;
int V_172 ;
F_88 ( V_9 ) ;
V_28 = F_142 ( V_229 ) ;
va_start ( args , V_159 ) ;
V_172 = vsnprintf ( V_28 , V_232 , V_159 , args ) ;
va_end ( args ) ;
F_150 ( V_227 , V_228 ) ;
F_147 ( & F_142 ( V_231 ) ) ;
F_97 ( V_9 ) ;
return V_172 ;
}
int F_151 ( const char * V_233 )
{
return F_152 ( & V_234 , V_233 ) ;
}
bool F_153 ( unsigned long * V_235 ,
unsigned int V_236 )
{
if ( * V_235 == 0
|| ! F_154 ( V_100 , * V_235 ,
* V_235
+ F_53 ( V_236 ) ) ) {
* V_235 = V_100 ;
return true ;
}
return false ;
}
int F_155 ( struct V_237 * V_238 )
{
unsigned long V_9 ;
int V_76 = - V_239 ;
if ( ! V_238 -> V_240 )
return - V_33 ;
F_156 ( & V_241 , V_9 ) ;
if ( ! V_238 -> V_242 ) {
V_238 -> V_242 = 1 ;
F_157 ( & V_238 -> V_243 , & V_244 ) ;
V_76 = 0 ;
}
F_158 ( & V_241 , V_9 ) ;
return V_76 ;
}
int F_159 ( struct V_237 * V_238 )
{
unsigned long V_9 ;
int V_76 = - V_33 ;
F_156 ( & V_241 , V_9 ) ;
if ( V_238 -> V_242 ) {
V_238 -> V_242 = 0 ;
F_160 ( & V_238 -> V_243 ) ;
V_76 = 0 ;
}
F_158 ( & V_241 , V_9 ) ;
F_161 () ;
return V_76 ;
}
void F_162 ( enum V_245 V_246 )
{
struct V_237 * V_238 ;
unsigned long V_9 ;
if ( ( V_246 > V_247 ) && ! V_248 )
return;
F_163 () ;
F_164 (dumper, &dump_list, list) {
if ( V_238 -> V_249 && V_246 > V_238 -> V_249 )
continue;
V_238 -> V_250 = true ;
F_44 ( & V_50 , V_9 ) ;
V_238 -> V_251 = V_67 ;
V_238 -> V_252 = V_66 ;
V_238 -> V_128 = V_18 ;
V_238 -> V_253 = V_19 ;
F_45 ( & V_50 , V_9 ) ;
V_238 -> V_240 ( V_238 , V_246 ) ;
V_238 -> V_250 = false ;
}
F_165 () ;
}
bool F_166 ( struct V_237 * V_238 , bool V_114 ,
char * line , T_6 V_14 , T_6 * V_5 )
{
struct log * V_1 ;
T_6 V_254 = 0 ;
bool V_31 = false ;
if ( ! V_238 -> V_250 )
goto V_39;
if ( V_238 -> V_251 < V_17 ) {
V_238 -> V_251 = V_17 ;
V_238 -> V_252 = V_20 ;
}
if ( V_238 -> V_251 >= V_18 )
goto V_39;
V_1 = F_3 ( V_238 -> V_252 ) ;
V_254 = F_64 ( V_1 , 0 , V_114 , line , V_14 ) ;
V_238 -> V_252 = F_4 ( V_238 -> V_252 ) ;
V_238 -> V_251 ++ ;
V_31 = true ;
V_39:
if ( V_5 )
* V_5 = V_254 ;
return V_31 ;
}
bool F_167 ( struct V_237 * V_238 , bool V_114 ,
char * line , T_6 V_14 , T_6 * V_5 )
{
unsigned long V_9 ;
bool V_31 ;
F_44 ( & V_50 , V_9 ) ;
V_31 = F_166 ( V_238 , V_114 , line , V_14 , V_5 ) ;
F_45 ( & V_50 , V_9 ) ;
return V_31 ;
}
bool F_168 ( struct V_237 * V_238 , bool V_114 ,
char * V_28 , T_6 V_14 , T_6 * V_5 )
{
unsigned long V_9 ;
T_2 V_51 ;
T_1 V_3 ;
T_2 V_128 ;
T_1 V_253 ;
enum V_8 V_58 ;
T_6 V_254 = 0 ;
bool V_31 = false ;
if ( ! V_238 -> V_250 )
goto V_39;
F_44 ( & V_50 , V_9 ) ;
if ( V_238 -> V_251 < V_17 ) {
V_238 -> V_251 = V_17 ;
V_238 -> V_252 = V_20 ;
}
if ( V_238 -> V_251 >= V_238 -> V_128 ) {
F_45 ( & V_50 , V_9 ) ;
goto V_39;
}
V_51 = V_238 -> V_251 ;
V_3 = V_238 -> V_252 ;
V_58 = 0 ;
while ( V_51 < V_238 -> V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_254 += F_64 ( V_1 , V_58 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_51 ++ ;
V_58 = V_1 -> V_9 ;
}
V_51 = V_238 -> V_251 ;
V_3 = V_238 -> V_252 ;
V_58 = 0 ;
while ( V_254 > V_14 && V_51 < V_238 -> V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_254 -= F_64 ( V_1 , V_58 , true , NULL , 0 ) ;
V_3 = F_4 ( V_3 ) ;
V_51 ++ ;
V_58 = V_1 -> V_9 ;
}
V_128 = V_51 ;
V_253 = V_3 ;
V_254 = 0 ;
V_58 = 0 ;
while ( V_51 < V_238 -> V_128 ) {
struct log * V_1 = F_3 ( V_3 ) ;
V_254 += F_64 ( V_1 , V_58 , V_114 , V_28 + V_254 , V_14 - V_254 ) ;
V_3 = F_4 ( V_3 ) ;
V_51 ++ ;
V_58 = V_1 -> V_9 ;
}
V_238 -> V_128 = V_128 ;
V_238 -> V_253 = V_253 ;
V_31 = true ;
F_45 ( & V_50 , V_9 ) ;
V_39:
if ( V_5 )
* V_5 = V_254 ;
return V_31 ;
}
void F_169 ( struct V_237 * V_238 )
{
V_238 -> V_251 = V_67 ;
V_238 -> V_252 = V_66 ;
V_238 -> V_128 = V_18 ;
V_238 -> V_253 = V_19 ;
}
void F_170 ( struct V_237 * V_238 )
{
unsigned long V_9 ;
F_44 ( & V_50 , V_9 ) ;
F_169 ( V_238 ) ;
F_45 ( & V_50 , V_9 ) ;
}
