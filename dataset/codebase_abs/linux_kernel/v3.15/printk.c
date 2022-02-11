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
if ( free >= V_15 + sizeof( struct V_1 ) )
break;
V_21 = F_4 ( V_21 ) ;
V_18 ++ ;
}
if ( V_20 + V_15 + sizeof( struct V_1 ) > V_22 ) {
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
V_2 -> V_6 = V_15 ;
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
V_94 =
F_44 ( V_92 , V_95 ) ;
} else {
V_94 = F_45 ( V_92 , 0 ) ;
}
if ( F_46 ( ! V_94 ) ) {
F_47 ( L_7 ,
V_92 ) ;
return;
}
F_48 ( & V_61 , V_10 ) ;
V_22 = V_92 ;
V_5 = V_94 ;
V_92 = 0 ;
free = V_96 - V_20 ;
memcpy ( V_5 , V_97 , V_96 ) ;
F_49 ( & V_61 , V_10 ) ;
F_50 ( L_8 , V_22 ) ;
F_50 ( L_9 ,
free , ( free * 100 ) / V_96 ) ;
}
static int T_9 F_51 ( char * V_91 )
{
V_98 = 1 ;
F_50 ( L_10 ) ;
return 0 ;
}
static int T_9 F_52 ( char * V_91 )
{
unsigned long V_99 ;
V_99 = V_100 ? V_100 : 1000000 ;
V_101 = ( unsigned long long ) V_99 / 1000 * V_102 ;
F_53 ( & V_91 , & V_103 ) ;
if ( V_103 > 10 * 1000 )
V_103 = 0 ;
F_54 ( L_11
L_12 ,
V_103 , V_100 , V_99 , V_102 , V_101 ) ;
return 0 ;
}
static void F_55 ( int V_8 )
{
unsigned long long V_104 ;
unsigned long V_105 ;
if ( ( V_103 == 0 || V_106 != V_107 )
|| ( V_8 >= V_108 && ! V_98 ) ) {
return;
}
V_104 = ( unsigned long long ) V_101 * V_103 ;
V_105 = V_109 + F_56 ( V_103 ) ;
while ( V_104 ) {
V_104 -- ;
F_57 () ;
if ( F_58 ( V_109 , V_105 ) )
break;
F_59 () ;
}
}
static inline void F_55 ( int V_8 )
{
}
static T_6 F_60 ( T_2 V_110 , char * V_39 )
{
unsigned long V_111 ;
if ( ! V_112 )
return 0 ;
V_111 = F_26 ( V_110 , 1000000000 ) ;
if ( ! V_39 )
return snprintf ( NULL , 0 , L_13 , ( unsigned long ) V_110 ) ;
return sprintf ( V_39 , L_14 ,
( unsigned long ) V_110 , V_111 / 1000 ) ;
}
static T_6 F_61 ( const struct V_1 * V_2 , bool V_113 , char * V_39 )
{
T_6 V_6 = 0 ;
unsigned int V_114 = ( V_2 -> V_7 << 3 ) | V_2 -> V_8 ;
if ( V_113 ) {
if ( V_39 ) {
V_6 += sprintf ( V_39 , L_15 , V_114 ) ;
} else {
V_6 += 3 ;
if ( V_114 > 999 )
V_6 += 3 ;
else if ( V_114 > 99 )
V_6 += 2 ;
else if ( V_114 > 9 )
V_6 ++ ;
}
}
V_6 += F_60 ( V_2 -> V_11 , V_39 ? V_39 + V_6 : NULL ) ;
return V_6 ;
}
static T_6 F_62 ( const struct V_1 * V_2 , enum V_9 V_69 ,
bool V_113 , char * V_39 , T_6 V_15 )
{
const char * V_14 = F_1 ( V_2 ) ;
T_6 V_115 = V_2 -> V_3 ;
bool V_114 = true ;
bool V_116 = true ;
T_6 V_6 = 0 ;
if ( ( V_69 & V_68 ) && ! ( V_2 -> V_10 & V_70 ) )
V_114 = false ;
if ( V_2 -> V_10 & V_68 ) {
if ( ( V_69 & V_68 ) && ! ( V_69 & V_117 ) )
V_114 = false ;
if ( ! ( V_2 -> V_10 & V_117 ) )
V_116 = false ;
}
do {
const char * V_118 = memchr ( V_14 , '\n' , V_115 ) ;
T_6 V_3 ;
if ( V_118 ) {
V_3 = V_118 - V_14 ;
V_118 ++ ;
V_115 -= V_118 - V_14 ;
} else {
V_3 = V_115 ;
}
if ( V_39 ) {
if ( F_61 ( V_2 , V_113 , NULL ) +
V_3 + 1 >= V_15 - V_6 )
break;
if ( V_114 )
V_6 += F_61 ( V_2 , V_113 , V_39 + V_6 ) ;
memcpy ( V_39 + V_6 , V_14 , V_3 ) ;
V_6 += V_3 ;
if ( V_118 || V_116 )
V_39 [ V_6 ++ ] = '\n' ;
} else {
if ( V_114 )
V_6 += F_61 ( V_2 , V_113 , NULL ) ;
V_6 += V_3 ;
if ( V_118 || V_116 )
V_6 ++ ;
}
V_114 = true ;
V_14 = V_118 ;
} while ( V_14 );
return V_6 ;
}
static int F_63 ( char T_7 * V_39 , int V_15 )
{
char * V_14 ;
struct V_1 * V_2 ;
int V_6 = 0 ;
V_14 = F_16 ( V_43 + V_119 , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
while ( V_15 > 0 ) {
T_6 V_120 ;
T_6 V_121 ;
F_23 ( & V_61 ) ;
if ( V_122 < V_18 ) {
V_122 = V_18 ;
V_123 = V_21 ;
V_124 = 0 ;
V_125 = 0 ;
}
if ( V_122 == V_19 ) {
F_24 ( & V_61 ) ;
break;
}
V_121 = V_125 ;
V_2 = F_3 ( V_123 ) ;
V_120 = F_62 ( V_2 , V_124 , true , V_14 ,
V_43 + V_119 ) ;
if ( V_120 - V_125 <= V_15 ) {
V_123 = F_4 ( V_123 ) ;
V_122 ++ ;
V_124 = V_2 -> V_10 ;
V_120 -= V_125 ;
V_125 = 0 ;
} else if ( ! V_6 ) {
V_120 = V_15 ;
V_125 += V_120 ;
} else
V_120 = 0 ;
F_24 ( & V_61 ) ;
if ( ! V_120 )
break;
if ( F_27 ( V_39 , V_14 + V_121 , V_120 ) ) {
if ( ! V_6 )
V_6 = - V_49 ;
break;
}
V_6 += V_120 ;
V_15 -= V_120 ;
V_39 += V_120 ;
}
F_20 ( V_14 ) ;
return V_6 ;
}
static int F_64 ( char T_7 * V_39 , int V_15 , bool V_126 )
{
char * V_14 ;
int V_6 = 0 ;
V_14 = F_16 ( V_43 + V_119 , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
F_23 ( & V_61 ) ;
if ( V_39 ) {
T_2 V_127 ;
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
V_6 += F_62 ( V_2 , V_69 , true , NULL , 0 ) ;
V_69 = V_2 -> V_10 ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
}
V_62 = V_78 ;
V_4 = V_77 ;
V_69 = 0 ;
while ( V_6 > V_15 && V_62 < V_19 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_6 -= F_62 ( V_2 , V_69 , true , NULL , 0 ) ;
V_69 = V_2 -> V_10 ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
}
V_127 = V_19 ;
V_6 = 0 ;
while ( V_6 >= 0 && V_62 < V_127 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
int V_128 ;
V_128 = F_62 ( V_2 , V_69 , true , V_14 ,
V_43 + V_119 ) ;
if ( V_128 < 0 ) {
V_6 = V_128 ;
break;
}
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
F_24 ( & V_61 ) ;
if ( F_27 ( V_39 + V_6 , V_14 , V_128 ) )
V_6 = - V_49 ;
else
V_6 += V_128 ;
F_23 ( & V_61 ) ;
if ( V_62 < V_18 ) {
V_62 = V_18 ;
V_4 = V_21 ;
V_69 = 0 ;
}
}
}
if ( V_126 ) {
V_78 = V_19 ;
V_77 = V_20 ;
}
F_24 ( & V_61 ) ;
F_20 ( V_14 ) ;
return V_6 ;
}
int F_65 ( int type , char T_7 * V_39 , int V_6 , bool V_26 )
{
bool V_126 = false ;
static int V_129 = - 1 ;
int error ;
error = F_9 ( type , V_26 ) ;
if ( error )
goto V_50;
error = F_13 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_130 :
break;
case V_27 :
break;
case V_131 :
error = - V_44 ;
if ( ! V_39 || V_6 < 0 )
goto V_50;
error = 0 ;
if ( ! V_6 )
goto V_50;
if ( ! F_66 ( V_132 , V_39 , V_6 ) ) {
error = - V_49 ;
goto V_50;
}
error = F_25 ( V_66 ,
V_122 != V_19 ) ;
if ( error )
goto V_50;
error = F_63 ( V_39 , V_6 ) ;
break;
case V_133 :
V_126 = true ;
case V_24 :
error = - V_44 ;
if ( ! V_39 || V_6 < 0 )
goto V_50;
error = 0 ;
if ( ! V_6 )
goto V_50;
if ( ! F_66 ( V_132 , V_39 , V_6 ) ) {
error = - V_49 ;
goto V_50;
}
error = F_64 ( V_39 , V_6 , V_126 ) ;
break;
case V_134 :
F_64 ( NULL , 0 , true ) ;
break;
case V_135 :
if ( V_129 == - 1 )
V_129 = V_108 ;
V_108 = V_136 ;
break;
case V_137 :
if ( V_129 != - 1 ) {
V_108 = V_129 ;
V_129 = - 1 ;
}
break;
case V_138 :
error = - V_44 ;
if ( V_6 < 1 || V_6 > 8 )
goto V_50;
if ( V_6 < V_136 )
V_6 = V_136 ;
V_108 = V_6 ;
V_129 = - 1 ;
error = 0 ;
break;
case V_139 :
F_23 ( & V_61 ) ;
if ( V_122 < V_18 ) {
V_122 = V_18 ;
V_123 = V_21 ;
V_124 = 0 ;
V_125 = 0 ;
}
if ( V_26 ) {
error = V_20 - V_123 ;
} else {
T_2 V_62 = V_122 ;
T_1 V_4 = V_123 ;
enum V_9 V_69 = V_124 ;
error = 0 ;
while ( V_62 < V_19 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
error += F_62 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
error -= V_125 ;
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
static void F_67 ( int V_8 , const char * V_14 , T_6 V_6 )
{
struct V_140 * V_141 ;
F_68 ( V_14 , V_6 ) ;
if ( V_8 >= V_108 && ! V_98 )
return;
if ( ! V_142 )
return;
F_69 (con) {
if ( V_143 && V_141 != V_143 )
continue;
if ( ! ( V_141 -> V_10 & V_144 ) )
continue;
if ( ! V_141 -> V_145 )
continue;
if ( ! F_70 ( F_71 () ) &&
! ( V_141 -> V_10 & V_146 ) )
continue;
V_141 -> V_145 ( V_141 , V_14 , V_6 ) ;
}
}
static void F_72 ( void )
{
static unsigned long V_147 ;
if ( F_73 ( V_109 , V_147 ) &&
! F_58 ( V_109 , V_147 + 30 * V_102 ) )
return;
V_147 = V_109 ;
F_74 () ;
F_75 ( & V_61 ) ;
F_76 ( & V_148 , 1 ) ;
}
static int F_77 ( void )
{
struct V_140 * V_141 ;
F_69 (con)
if ( V_141 -> V_10 & V_146 )
return 1 ;
return 0 ;
}
static inline int F_78 ( unsigned int V_149 )
{
return F_70 ( V_149 ) || F_77 () ;
}
static int F_79 ( unsigned int V_149 )
__releases( &logbuf_lock
static inline void F_80 ( void )
{
if ( F_46 ( V_150 ) ) {
int V_151 = V_150 ;
while ( V_151 -- ) {
F_81 ( 1 ) ;
F_59 () ;
}
}
}
static void F_82 ( enum V_9 V_10 )
{
if ( V_58 . V_152 )
return;
if ( V_58 . V_6 == 0 )
return;
if ( V_58 . V_153 ) {
F_5 ( V_58 . V_7 , V_58 . V_8 , V_10 | V_154 ,
V_58 . V_11 , NULL , 0 , V_58 . V_39 , V_58 . V_6 ) ;
V_58 . V_10 = V_10 ;
V_58 . V_152 = true ;
} else {
F_5 ( V_58 . V_7 , V_58 . V_8 , V_10 , 0 ,
NULL , 0 , V_58 . V_39 , V_58 . V_6 ) ;
V_58 . V_6 = 0 ;
}
}
static bool F_83 ( int V_7 , int V_8 , const char * V_14 , T_6 V_6 )
{
if ( V_58 . V_6 && V_58 . V_152 )
return false ;
if ( V_58 . V_6 + V_6 > sizeof( V_58 . V_39 ) ) {
F_82 ( V_68 ) ;
return false ;
}
if ( ! V_58 . V_6 ) {
V_58 . V_7 = V_7 ;
V_58 . V_8 = V_8 ;
V_58 . V_155 = V_30 ;
V_58 . V_11 = F_7 () ;
V_58 . V_10 = 0 ;
V_58 . V_153 = 0 ;
V_58 . V_152 = false ;
}
memcpy ( V_58 . V_39 + V_58 . V_6 , V_14 , V_6 ) ;
V_58 . V_6 += V_6 ;
if ( V_58 . V_6 > ( sizeof( V_58 . V_39 ) * 80 ) / 100 )
F_82 ( V_68 ) ;
return true ;
}
static T_6 F_84 ( char * V_14 , T_6 V_15 )
{
T_6 V_128 = 0 ;
T_6 V_6 ;
if ( V_58 . V_153 == 0 && ( V_156 & V_117 ) ) {
V_128 += F_60 ( V_58 . V_11 , V_14 ) ;
V_15 -= V_128 ;
}
V_6 = V_58 . V_6 - V_58 . V_153 ;
if ( V_6 > 0 ) {
if ( V_6 + 1 > V_15 )
V_6 = V_15 - 1 ;
memcpy ( V_14 + V_128 , V_58 . V_39 + V_58 . V_153 , V_6 ) ;
V_128 += V_6 ;
V_58 . V_153 = V_58 . V_6 ;
}
if ( V_58 . V_152 ) {
if ( V_58 . V_10 & V_117 )
V_14 [ V_128 ++ ] = '\n' ;
V_58 . V_6 = 0 ;
}
return V_128 ;
}
T_10 int F_85 ( int V_7 , int V_8 ,
const char * V_12 , T_6 V_157 ,
const char * V_158 , T_11 args )
{
static int V_159 ;
static char V_160 [ V_43 ] ;
char * V_14 = V_160 ;
T_6 V_3 ;
enum V_9 V_161 = 0 ;
unsigned long V_10 ;
int V_162 ;
int V_163 = 0 ;
F_55 ( V_8 ) ;
F_80 () ;
F_86 ( V_10 ) ;
V_162 = F_71 () ;
if ( F_46 ( V_164 == V_162 ) ) {
if ( ! V_165 && ! F_87 ( V_30 ) ) {
V_159 = 1 ;
goto V_166;
}
F_72 () ;
}
F_88 () ;
F_89 ( & V_61 ) ;
V_164 = V_162 ;
if ( V_159 ) {
static const char V_167 [] =
L_16 ;
V_159 = 0 ;
V_163 += strlen ( V_167 ) ;
F_5 ( 0 , 2 , V_70 | V_117 , 0 ,
NULL , 0 , V_167 , V_163 ) ;
}
V_3 = F_90 ( V_14 , sizeof( V_160 ) , V_158 , args ) ;
if ( V_3 && V_14 [ V_3 - 1 ] == '\n' ) {
V_3 -- ;
V_161 |= V_117 ;
}
if ( V_7 == 0 ) {
int V_168 = F_91 ( V_14 ) ;
if ( V_168 ) {
const char * V_169 = F_92 ( V_14 ) ;
switch ( V_168 ) {
case '0' ... '7' :
if ( V_8 == - 1 )
V_8 = V_168 - '0' ;
case 'd' :
V_161 |= V_70 ;
}
V_3 -= V_169 - V_14 ;
V_14 = ( char * ) V_169 ;
}
}
if ( V_8 == - 1 )
V_8 = V_41 ;
if ( V_12 )
V_161 |= V_70 | V_117 ;
if ( ! ( V_161 & V_117 ) ) {
if ( V_58 . V_6 && ( V_161 & V_70 || V_58 . V_155 != V_30 ) )
F_82 ( V_117 ) ;
if ( ! F_83 ( V_7 , V_8 , V_14 , V_3 ) )
F_5 ( V_7 , V_8 , V_161 | V_68 , 0 ,
V_12 , V_157 , V_14 , V_3 ) ;
} else {
bool V_170 = false ;
if ( V_58 . V_6 ) {
if ( V_58 . V_155 == V_30 && ! ( V_161 & V_70 ) )
V_170 = F_83 ( V_7 , V_8 , V_14 ,
V_3 ) ;
F_82 ( V_117 ) ;
}
if ( ! V_170 )
F_5 ( V_7 , V_8 , V_161 , 0 ,
V_12 , V_157 , V_14 , V_3 ) ;
}
V_163 += V_3 ;
if ( F_79 ( V_162 ) )
F_93 () ;
F_94 () ;
V_166:
F_95 ( V_10 ) ;
return V_163 ;
}
T_10 int F_96 ( const char * V_158 , T_11 args )
{
return F_85 ( 0 , - 1 , NULL , 0 , V_158 , args ) ;
}
T_10 int F_19 ( int V_7 , int V_8 ,
const char * V_12 , T_6 V_157 ,
const char * V_158 , ... )
{
T_11 args ;
int V_171 ;
va_start ( args , V_158 ) ;
V_171 = F_85 ( V_7 , V_8 , V_12 , V_157 , V_158 , args ) ;
va_end ( args ) ;
return V_171 ;
}
T_10 T_12 int F_97 ( const char * V_158 , ... )
{
T_11 args ;
int V_171 ;
#ifdef F_98
if ( F_46 ( V_172 ) ) {
va_start ( args , V_158 ) ;
V_171 = F_99 ( V_158 , args ) ;
va_end ( args ) ;
return V_171 ;
}
#endif
va_start ( args , V_158 ) ;
V_171 = F_85 ( 0 , - 1 , NULL , 0 , V_158 , args ) ;
va_end ( args ) ;
return V_171 ;
}
static struct V_1 * F_3 ( T_1 V_4 ) { return NULL ; }
static T_1 F_4 ( T_1 V_4 ) { return 0 ; }
static void F_67 ( int V_8 , const char * V_14 , T_6 V_6 ) {}
static T_6 F_62 ( const struct V_1 * V_2 , enum V_9 V_69 ,
bool V_113 , char * V_39 , T_6 V_15 ) { return 0 ; }
static T_6 F_84 ( char * V_14 , T_6 V_15 ) { return 0 ; }
void F_100 ( const char * V_158 , T_11 V_173 )
{
if ( V_174 ) {
char V_39 [ 512 ] ;
int V_120 = F_90 ( V_39 , sizeof( V_39 ) , V_158 , V_173 ) ;
V_174 -> V_145 ( V_174 , V_39 , V_120 ) ;
}
}
T_10 T_12 void F_101 ( const char * V_158 , ... )
{
T_11 V_173 ;
va_start ( V_173 , V_158 ) ;
F_100 ( V_158 , V_173 ) ;
va_end ( V_173 ) ;
}
static int F_102 ( char * V_175 , int V_4 , char * V_176 ,
char * V_177 )
{
struct V_178 * V_71 ;
int V_40 ;
for ( V_40 = 0 , V_71 = V_178 ;
V_40 < V_179 && V_71 -> V_175 [ 0 ] ;
V_40 ++ , V_71 ++ ) {
if ( strcmp ( V_71 -> V_175 , V_175 ) == 0 && V_71 -> V_180 == V_4 ) {
if ( ! V_177 )
V_181 = V_40 ;
return 0 ;
}
}
if ( V_40 == V_179 )
return - V_182 ;
if ( ! V_177 )
V_181 = V_40 ;
F_103 ( V_71 -> V_175 , V_175 , sizeof( V_71 -> V_175 ) ) ;
V_71 -> V_176 = V_176 ;
F_104 ( V_71 , V_177 ) ;
V_71 -> V_180 = V_4 ;
return 0 ;
}
static int T_9 F_105 ( char * V_91 )
{
char V_39 [ sizeof( V_178 [ 0 ] . V_175 ) + 4 ] ;
char * V_183 , * V_176 , * V_177 = NULL ;
int V_4 ;
if ( F_106 ( & V_91 , & V_177 ) )
return 1 ;
if ( V_91 [ 0 ] >= '0' && V_91 [ 0 ] <= '9' ) {
strcpy ( V_39 , L_17 ) ;
strncpy ( V_39 + 4 , V_91 , sizeof( V_39 ) - 5 ) ;
} else {
strncpy ( V_39 , V_91 , sizeof( V_39 ) - 1 ) ;
}
V_39 [ sizeof( V_39 ) - 1 ] = 0 ;
if ( ( V_176 = strchr ( V_91 , ',' ) ) != NULL )
* ( V_176 ++ ) = 0 ;
#ifdef F_107
if ( ! strcmp ( V_91 , L_18 ) )
strcpy ( V_39 , L_19 ) ;
if ( ! strcmp ( V_91 , L_20 ) )
strcpy ( V_39 , L_21 ) ;
#endif
for ( V_183 = V_39 ; * V_183 ; V_183 ++ )
if ( ( * V_183 >= '0' && * V_183 <= '9' ) || * V_183 == ',' )
break;
V_4 = F_18 ( V_183 , NULL , 10 ) ;
* V_183 = 0 ;
F_102 ( V_39 , V_4 , V_176 , V_177 ) ;
V_184 = 1 ;
return 1 ;
}
int F_108 ( char * V_175 , int V_4 , char * V_176 )
{
return F_102 ( V_175 , V_4 , V_176 , NULL ) ;
}
int F_109 ( char * V_175 , int V_4 , char * V_185 , int V_186 , char * V_176 )
{
struct V_178 * V_71 ;
int V_40 ;
for ( V_40 = 0 , V_71 = V_178 ;
V_40 < V_179 && V_71 -> V_175 [ 0 ] ;
V_40 ++ , V_71 ++ )
if ( strcmp ( V_71 -> V_175 , V_175 ) == 0 && V_71 -> V_180 == V_4 ) {
F_103 ( V_71 -> V_175 , V_185 , sizeof( V_71 -> V_175 ) ) ;
V_71 -> V_175 [ sizeof( V_71 -> V_175 ) - 1 ] = 0 ;
V_71 -> V_176 = V_176 ;
V_71 -> V_180 = V_186 ;
return V_40 ;
}
return - 1 ;
}
static int T_9 F_110 ( char * V_91 )
{
V_187 = 0 ;
return 1 ;
}
void F_111 ( void )
{
if ( ! V_187 )
return;
F_97 ( L_22 ) ;
F_112 () ;
V_188 = 1 ;
F_113 ( & V_148 ) ;
F_114 ( & V_189 , 1 , V_190 ) ;
}
void F_115 ( void )
{
if ( ! V_187 )
return;
F_116 ( & V_148 ) ;
F_117 ( & V_189 , 0 , 0 , V_190 ) ;
V_188 = 0 ;
F_93 () ;
}
static int F_118 ( struct V_191 * V_192 ,
unsigned long V_193 , void * V_194 )
{
switch ( V_193 ) {
case V_195 :
case V_196 :
case V_197 :
case V_198 :
F_112 () ;
F_93 () ;
}
return V_199 ;
}
void F_112 ( void )
{
F_119 () ;
F_116 ( & V_148 ) ;
if ( V_188 )
return;
V_200 = 1 ;
V_201 = 1 ;
F_117 ( & V_189 , 0 , 0 , V_190 ) ;
}
int F_120 ( void )
{
if ( F_121 ( & V_148 ) )
return 0 ;
if ( V_188 ) {
F_113 ( & V_148 ) ;
return 0 ;
}
V_200 = 1 ;
V_201 = 0 ;
F_117 ( & V_189 , 0 , 1 , V_190 ) ;
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
F_48 ( & V_61 , V_10 ) ;
if ( ! V_58 . V_6 )
goto V_50;
if ( V_202 < V_19 && ! V_58 . V_153 )
goto V_50;
V_6 = F_84 ( V_14 , V_15 ) ;
F_124 ( & V_61 ) ;
F_125 () ;
F_67 ( V_58 . V_8 , V_14 , V_6 ) ;
F_126 () ;
F_95 ( V_10 ) ;
return;
V_50:
F_49 ( & V_61 , V_10 ) ;
}
void F_93 ( void )
{
static char V_14 [ V_43 + V_119 ] ;
static T_2 V_203 ;
unsigned long V_10 ;
bool V_204 = false ;
bool V_205 ;
if ( V_188 ) {
F_113 ( & V_148 ) ;
return;
}
V_201 = 0 ;
F_123 ( V_14 , sizeof( V_14 ) ) ;
V_206:
for (; ; ) {
struct V_1 * V_2 ;
T_6 V_6 ;
int V_8 ;
F_48 ( & V_61 , V_10 ) ;
if ( V_203 != V_19 ) {
V_204 = true ;
V_203 = V_19 ;
}
if ( V_202 < V_18 ) {
V_202 = V_18 ;
V_207 = V_21 ;
V_156 = 0 ;
}
V_121:
if ( V_202 == V_19 )
break;
V_2 = F_3 ( V_207 ) ;
if ( V_2 -> V_10 & V_154 ) {
V_207 = F_4 ( V_207 ) ;
V_202 ++ ;
V_2 -> V_10 &= ~ V_154 ;
V_156 = V_2 -> V_10 ;
goto V_121;
}
V_8 = V_2 -> V_8 ;
V_6 = F_62 ( V_2 , V_156 , false ,
V_14 , sizeof( V_14 ) ) ;
V_207 = F_4 ( V_207 ) ;
V_202 ++ ;
V_156 = V_2 -> V_10 ;
F_124 ( & V_61 ) ;
F_125 () ;
F_67 ( V_8 , V_14 , V_6 ) ;
F_126 () ;
F_95 ( V_10 ) ;
}
V_200 = 0 ;
F_114 ( & V_189 , 1 , V_190 ) ;
if ( F_46 ( V_143 ) )
V_143 = NULL ;
F_124 ( & V_61 ) ;
F_113 ( & V_148 ) ;
F_89 ( & V_61 ) ;
V_205 = V_202 != V_19 ;
F_49 ( & V_61 , V_10 ) ;
if ( V_205 && F_120 () )
goto V_206;
if ( V_204 )
F_127 () ;
}
void T_13 F_128 ( void )
{
if ( V_201 )
F_129 () ;
}
void F_130 ( void )
{
struct V_140 * V_71 ;
if ( V_165 ) {
if ( F_121 ( & V_148 ) != 0 )
return;
} else
F_112 () ;
V_200 = 1 ;
V_201 = 0 ;
F_69 (c)
if ( ( V_71 -> V_10 & V_144 ) && V_71 -> V_208 )
V_71 -> V_208 () ;
F_93 () ;
}
struct V_209 * F_131 ( int * V_180 )
{
struct V_140 * V_71 ;
struct V_209 * V_210 = NULL ;
F_112 () ;
F_69 (c) {
if ( ! V_71 -> V_211 )
continue;
V_210 = V_71 -> V_211 ( V_71 , V_180 ) ;
if ( V_210 )
break;
}
F_93 () ;
return V_210 ;
}
void F_132 ( struct V_140 * V_140 )
{
F_112 () ;
V_140 -> V_10 &= ~ V_144 ;
F_93 () ;
}
void F_133 ( struct V_140 * V_140 )
{
F_112 () ;
V_140 -> V_10 |= V_144 ;
F_93 () ;
}
static int T_9 F_134 ( char * V_91 )
{
V_212 = 1 ;
F_50 ( L_23 ) ;
return 0 ;
}
void F_135 ( struct V_140 * V_213 )
{
int V_40 ;
unsigned long V_10 ;
struct V_140 * V_214 = NULL ;
struct V_178 * V_71 ;
if ( V_142 )
F_69 (bcon)
if ( F_136 ( V_214 == V_213 ,
L_24 ,
V_214 -> V_175 , V_214 -> V_180 ) )
return;
if ( V_142 && V_213 -> V_10 & V_215 ) {
F_69 (bcon) {
if ( ! ( V_214 -> V_10 & V_215 ) ) {
F_50 ( L_25 ,
V_213 -> V_175 , V_213 -> V_180 ) ;
return;
}
}
}
if ( V_142 && V_142 -> V_10 & V_215 )
V_214 = V_142 ;
if ( V_216 < 0 || V_214 || ! V_142 )
V_216 = V_181 ;
if ( V_213 -> V_217 )
V_213 -> V_217 () ;
if ( V_216 < 0 ) {
if ( V_213 -> V_180 < 0 )
V_213 -> V_180 = 0 ;
if ( V_213 -> V_218 == NULL ||
V_213 -> V_218 ( V_213 , NULL ) == 0 ) {
V_213 -> V_10 |= V_144 ;
if ( V_213 -> V_211 ) {
V_213 -> V_10 |= V_219 ;
V_216 = 0 ;
}
}
}
for ( V_40 = 0 , V_71 = V_178 ;
V_40 < V_179 && V_71 -> V_175 [ 0 ] ;
V_40 ++ , V_71 ++ ) {
if ( strcmp ( V_71 -> V_175 , V_213 -> V_175 ) != 0 )
continue;
if ( V_213 -> V_180 >= 0 &&
V_213 -> V_180 != V_71 -> V_180 )
continue;
if ( V_213 -> V_180 < 0 )
V_213 -> V_180 = V_71 -> V_180 ;
if ( F_137 ( V_213 , V_71 ) )
return;
if ( V_213 -> V_218 &&
V_213 -> V_218 ( V_213 , V_178 [ V_40 ] . V_176 ) != 0 )
break;
V_213 -> V_10 |= V_144 ;
V_213 -> V_180 = V_71 -> V_180 ;
if ( V_40 == V_181 ) {
V_213 -> V_10 |= V_219 ;
V_216 = V_181 ;
}
break;
}
if ( ! ( V_213 -> V_10 & V_144 ) )
return;
if ( V_214 && ( ( V_213 -> V_10 & ( V_219 | V_215 ) ) == V_219 ) )
V_213 -> V_10 &= ~ V_220 ;
F_112 () ;
if ( ( V_213 -> V_10 & V_219 ) || V_142 == NULL ) {
V_213 -> V_118 = V_142 ;
V_142 = V_213 ;
if ( V_213 -> V_118 )
V_213 -> V_118 -> V_10 &= ~ V_219 ;
} else {
V_213 -> V_118 = V_142 -> V_118 ;
V_142 -> V_118 = V_213 ;
}
if ( V_213 -> V_10 & V_220 ) {
F_48 ( & V_61 , V_10 ) ;
V_202 = V_122 ;
V_207 = V_123 ;
V_156 = V_124 ;
F_49 ( & V_61 , V_10 ) ;
V_143 = V_213 ;
}
F_93 () ;
F_138 () ;
F_50 ( L_26 ,
( V_213 -> V_10 & V_215 ) ? L_27 : L_28 ,
V_213 -> V_175 , V_213 -> V_180 ) ;
if ( V_214 &&
( ( V_213 -> V_10 & ( V_219 | V_215 ) ) == V_219 ) &&
! V_212 ) {
F_69 (bcon)
if ( V_214 -> V_10 & V_215 )
F_139 ( V_214 ) ;
}
}
int F_139 ( struct V_140 * V_140 )
{
struct V_140 * V_221 , * V_222 ;
int V_223 ;
F_50 ( L_29 ,
( V_140 -> V_10 & V_215 ) ? L_27 : L_28 ,
V_140 -> V_175 , V_140 -> V_180 ) ;
V_223 = F_140 ( V_140 ) ;
if ( V_223 )
return V_223 ;
V_223 = 1 ;
F_112 () ;
if ( V_142 == V_140 ) {
V_142 = V_140 -> V_118 ;
V_223 = 0 ;
} else if ( V_142 ) {
for ( V_221 = V_142 -> V_118 , V_222 = V_142 ;
V_221 ; V_222 = V_221 , V_221 = V_222 -> V_118 ) {
if ( V_221 == V_140 ) {
V_222 -> V_118 = V_221 -> V_118 ;
V_223 = 0 ;
break;
}
}
}
if ( V_142 != NULL && V_140 -> V_10 & V_219 )
V_142 -> V_10 |= V_219 ;
F_93 () ;
F_138 () ;
return V_223 ;
}
static int T_9 F_141 ( void )
{
struct V_140 * V_141 ;
F_69 (con) {
if ( ! V_212 && V_141 -> V_10 & V_215 ) {
F_139 ( V_141 ) ;
}
}
F_142 ( F_118 , 0 ) ;
return 0 ;
}
static void F_143 ( struct V_224 * V_224 )
{
int V_225 = F_144 ( V_226 , 0 ) ;
if ( V_225 & V_227 ) {
char * V_39 = F_145 ( V_228 ) ;
F_146 ( L_30 , V_39 ) ;
}
if ( V_225 & V_229 )
F_147 ( & V_66 ) ;
}
void F_127 ( void )
{
F_148 () ;
if ( F_149 ( & V_66 ) ) {
F_150 ( V_226 , V_229 ) ;
F_151 ( & F_145 ( V_230 ) ) ;
}
F_152 () ;
}
int F_153 ( const char * V_158 , ... )
{
unsigned long V_10 ;
T_11 args ;
char * V_39 ;
int V_171 ;
F_86 ( V_10 ) ;
V_39 = F_145 ( V_228 ) ;
va_start ( args , V_158 ) ;
V_171 = vsnprintf ( V_39 , V_231 , V_158 , args ) ;
va_end ( args ) ;
F_154 ( V_226 , V_227 ) ;
F_151 ( & F_145 ( V_230 ) ) ;
F_95 ( V_10 ) ;
return V_171 ;
}
int F_155 ( const char * V_232 )
{
return F_156 ( & V_233 , V_232 ) ;
}
bool F_157 ( unsigned long * V_234 ,
unsigned int V_235 )
{
if ( * V_234 == 0
|| ! F_158 ( V_109 , * V_234 ,
* V_234
+ F_56 ( V_235 ) ) ) {
* V_234 = V_109 ;
return true ;
}
return false ;
}
int F_159 ( struct V_236 * V_237 )
{
unsigned long V_10 ;
int V_87 = - V_238 ;
if ( ! V_237 -> V_239 )
return - V_44 ;
F_160 ( & V_240 , V_10 ) ;
if ( ! V_237 -> V_241 ) {
V_237 -> V_241 = 1 ;
F_161 ( & V_237 -> V_242 , & V_243 ) ;
V_87 = 0 ;
}
F_162 ( & V_240 , V_10 ) ;
return V_87 ;
}
int F_163 ( struct V_236 * V_237 )
{
unsigned long V_10 ;
int V_87 = - V_44 ;
F_160 ( & V_240 , V_10 ) ;
if ( V_237 -> V_241 ) {
V_237 -> V_241 = 0 ;
F_164 ( & V_237 -> V_242 ) ;
V_87 = 0 ;
}
F_162 ( & V_240 , V_10 ) ;
F_165 () ;
return V_87 ;
}
void F_166 ( enum V_244 V_245 )
{
struct V_236 * V_237 ;
unsigned long V_10 ;
if ( ( V_245 > V_246 ) && ! V_247 )
return;
F_167 () ;
F_168 (dumper, &dump_list, list) {
if ( V_237 -> V_248 && V_245 > V_237 -> V_248 )
continue;
V_237 -> V_249 = true ;
F_48 ( & V_61 , V_10 ) ;
V_237 -> V_250 = V_78 ;
V_237 -> V_251 = V_77 ;
V_237 -> V_127 = V_19 ;
V_237 -> V_252 = V_20 ;
F_49 ( & V_61 , V_10 ) ;
V_237 -> V_239 ( V_237 , V_245 ) ;
V_237 -> V_249 = false ;
}
F_169 () ;
}
bool F_170 ( struct V_236 * V_237 , bool V_113 ,
char * line , T_6 V_15 , T_6 * V_6 )
{
struct V_1 * V_2 ;
T_6 V_253 = 0 ;
bool V_42 = false ;
if ( ! V_237 -> V_249 )
goto V_50;
if ( V_237 -> V_250 < V_18 ) {
V_237 -> V_250 = V_18 ;
V_237 -> V_251 = V_21 ;
}
if ( V_237 -> V_250 >= V_19 )
goto V_50;
V_2 = F_3 ( V_237 -> V_251 ) ;
V_253 = F_62 ( V_2 , 0 , V_113 , line , V_15 ) ;
V_237 -> V_251 = F_4 ( V_237 -> V_251 ) ;
V_237 -> V_250 ++ ;
V_42 = true ;
V_50:
if ( V_6 )
* V_6 = V_253 ;
return V_42 ;
}
bool F_171 ( struct V_236 * V_237 , bool V_113 ,
char * line , T_6 V_15 , T_6 * V_6 )
{
unsigned long V_10 ;
bool V_42 ;
F_48 ( & V_61 , V_10 ) ;
V_42 = F_170 ( V_237 , V_113 , line , V_15 , V_6 ) ;
F_49 ( & V_61 , V_10 ) ;
return V_42 ;
}
bool F_172 ( struct V_236 * V_237 , bool V_113 ,
char * V_39 , T_6 V_15 , T_6 * V_6 )
{
unsigned long V_10 ;
T_2 V_62 ;
T_1 V_4 ;
T_2 V_127 ;
T_1 V_252 ;
enum V_9 V_69 ;
T_6 V_253 = 0 ;
bool V_42 = false ;
if ( ! V_237 -> V_249 )
goto V_50;
F_48 ( & V_61 , V_10 ) ;
if ( V_237 -> V_250 < V_18 ) {
V_237 -> V_250 = V_18 ;
V_237 -> V_251 = V_21 ;
}
if ( V_237 -> V_250 >= V_237 -> V_127 ) {
F_49 ( & V_61 , V_10 ) ;
goto V_50;
}
V_62 = V_237 -> V_250 ;
V_4 = V_237 -> V_251 ;
V_69 = 0 ;
while ( V_62 < V_237 -> V_127 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_253 += F_62 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_62 = V_237 -> V_250 ;
V_4 = V_237 -> V_251 ;
V_69 = 0 ;
while ( V_253 > V_15 && V_62 < V_237 -> V_127 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_253 -= F_62 ( V_2 , V_69 , true , NULL , 0 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_127 = V_62 ;
V_252 = V_4 ;
V_253 = 0 ;
while ( V_62 < V_237 -> V_127 ) {
struct V_1 * V_2 = F_3 ( V_4 ) ;
V_253 += F_62 ( V_2 , V_69 , V_113 , V_39 + V_253 , V_15 - V_253 ) ;
V_4 = F_4 ( V_4 ) ;
V_62 ++ ;
V_69 = V_2 -> V_10 ;
}
V_237 -> V_127 = V_127 ;
V_237 -> V_252 = V_252 ;
V_42 = true ;
F_49 ( & V_61 , V_10 ) ;
V_50:
if ( V_6 )
* V_6 = V_253 ;
return V_42 ;
}
void F_173 ( struct V_236 * V_237 )
{
V_237 -> V_250 = V_78 ;
V_237 -> V_251 = V_77 ;
V_237 -> V_127 = V_19 ;
V_237 -> V_252 = V_20 ;
}
void F_174 ( struct V_236 * V_237 )
{
unsigned long V_10 ;
F_48 ( & V_61 , V_10 ) ;
F_173 ( V_237 ) ;
F_49 ( & V_61 , V_10 ) ;
}
void T_9 F_175 ( const char * V_158 , ... )
{
T_11 args ;
va_start ( args , V_158 ) ;
vsnprintf ( V_254 , sizeof( V_254 ) ,
V_158 , args ) ;
va_end ( args ) ;
}
void F_176 ( const char * V_255 )
{
F_97 ( L_31 ,
V_255 , F_177 () , V_30 -> V_256 , V_30 -> V_31 ,
F_178 () , F_179 () -> V_257 ,
( int ) strcspn ( F_179 () -> V_258 , L_32 ) ,
F_179 () -> V_258 ) ;
if ( V_254 [ 0 ] != '\0' )
F_97 ( L_33 ,
V_255 , V_254 ) ;
F_180 ( V_255 , V_30 ) ;
}
void F_181 ( const char * V_255 )
{
F_176 ( V_255 ) ;
F_97 ( L_34 ,
V_255 , V_30 , F_182 () ,
F_183 ( V_30 ) ) ;
}
