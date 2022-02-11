char * F_1 ( const char * V_1 )
{
T_1 V_2 , V_3 ;
const char * V_4 ;
char * V_5 ;
for ( V_4 = V_1 + strlen ( V_1 ) ; -- V_4 > V_1 ; )
if ( * V_4 == '/' || * V_4 == '\\' || * V_4 == ':' ) {
V_4 ++ ;
break;
}
V_3 = strlen ( V_4 ) ;
if ( V_3 > 4 &&
( strcmp ( & V_4 [ V_3 - 4 ] , L_1 ) == 0 || strcmp ( & V_4 [ V_3 - 4 ] , L_2 ) == 0 ) )
V_3 -= 4 ;
if ( V_3 > sizeof F_2 - 1 )
V_3 = sizeof F_2 - 1 ;
for ( V_5 = F_2 , V_2 = 0 ; V_2 < V_3 ; V_2 ++ , V_4 ++ )
* V_5 ++ = isupper ( * V_4 ) ? tolower ( * V_4 ) : * V_4 ;
* V_5 = '\0' ;
return F_2 ;
}
char * F_1 ( const char * V_1 )
{
const char * V_4 , * V_5 ;
for ( V_4 = V_1 + strlen ( V_1 ) ; -- V_4 > V_1 ; )
if ( * V_4 == ':' || * V_4 == ']' || * V_4 == '>' ) {
V_4 ++ ;
break;
}
V_5 = strrchr ( V_4 , '.' ) ;
strncpy ( F_2 , V_4 , sizeof F_2 - 1 ) ;
F_2 [ sizeof F_2 - 1 ] = '\0' ;
if ( V_5 != NULL && V_5 - V_4 < sizeof F_2 )
F_2 [ V_5 - V_4 ] = '\0' ;
return F_2 ;
}
char * F_1 ( const char * V_1 )
{
const char * V_4 ;
for ( V_4 = V_1 + strlen ( V_1 ) ; -- V_4 > V_1 ; )
if ( * V_4 == '/' ) {
V_4 ++ ;
break;
}
strncpy ( F_2 , V_4 , sizeof F_2 - 1 ) ;
F_2 [ sizeof F_2 - 1 ] = '\0' ;
return F_2 ;
}
char * F_3 ( void )
{
return F_2 ;
}
char * F_4 ( int V_6 , char * * V_7 , const T_2 * V_8 )
{
V_9 = V_6 ;
V_10 = V_7 ;
V_11 = 1 ;
V_12 = V_8 ;
F_1 ( V_7 [ 0 ] ) ;
V_13 = NULL ;
for (; V_8 -> V_14 ; ++ V_8 ) {
#ifndef F_5
const T_2 * V_15 ;
int V_16 , V_2 ;
#endif
if ( V_8 -> V_14 == V_17 || V_8 -> V_14 == V_18 )
continue;
#ifndef F_5
V_2 = V_8 -> V_19 ;
assert ( V_8 -> V_14 [ 0 ] != '-' ) ;
assert ( V_8 -> V_20 > 0 ) ;
switch ( V_2 ) {
case 0 : case '-' : case '/' : case '<' : case '>' : case 'E' : case 'F' :
case 'M' : case 'U' : case 'f' : case 'l' : case 'n' : case 'p' : case 's' :
case 'u' : case 'c' :
break;
default:
assert ( 0 ) ;
}
for ( V_15 = V_8 + 1 ; V_15 -> V_14 ; ++ V_15 ) {
V_16 = strcmp ( V_8 -> V_14 , V_15 -> V_14 ) == 0 ;
assert ( ! V_16 ) ;
}
#endif
if ( V_8 -> V_14 [ 0 ] == '\0' ) {
assert ( V_13 == NULL ) ;
V_13 = V_8 ;
assert ( V_13 -> V_19 == 0 || V_13 -> V_19 == '-' ) ;
}
}
return F_2 ;
}
int F_6 ( const char * V_21 , unsigned long V_22 )
{
T_3 * V_23 ;
if ( V_22 == V_24 )
F_7 ( V_25 , L_3 ,
F_2 , V_21 ) ;
else {
F_7 ( V_25 , L_4 ,
F_2 , V_21 ) ;
for ( V_23 = V_26 ; V_23 -> V_14 ; V_23 ++ )
if ( V_22 & V_23 -> V_20 )
F_7 ( V_25 , L_5 , V_23 -> V_14 ) ;
}
return 0 ;
}
int F_8 ( const char * V_21 , unsigned long V_22 , int * V_27 )
{
switch ( * V_21 ) {
default:
return 0 ;
case 'D' :
case 'd' :
if ( ( V_22 & V_24 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_28 ;
break;
case 'T' :
case 't' :
if ( ( V_22 & V_29 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_30 ;
break;
case 'N' :
case 'n' :
if ( ( V_22 & V_31 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
if ( strcmp ( V_21 , L_6 ) != 0 && strcmp ( V_21 , L_7 ) != 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_32 ;
break;
case 'S' :
case 's' :
if ( ( V_22 & V_33 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_34 ;
break;
case 'M' :
case 'm' :
if ( ( V_22 & V_35 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_36 ;
break;
case 'E' :
case 'e' :
if ( ( V_22 & V_37 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_38 ;
break;
case 'H' :
case 'h' :
if ( ( V_22 & V_39 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_40 ;
break;
case '1' :
if ( ( V_22 & V_41 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_42 ;
break;
case 'P' :
case 'p' :
if ( V_21 [ 1 ] == '\0' || strcmp ( V_21 , L_8 ) == 0 || strcmp ( V_21 , L_9 ) == 0 ) {
if ( ( V_22 & V_24 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_43 ;
} else if ( strcmp ( V_21 , L_10 ) == 0 || strcmp ( V_21 , L_11 ) == 0 ) {
if ( ( V_22 & V_44 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_45 ;
} else if ( strcmp ( V_21 , L_12 ) == 0 || strcmp ( V_21 , L_13 ) == 0
|| strcmp ( V_21 , L_14 ) == 0 || strcmp ( V_21 , L_15 ) == 0 ) {
if ( ( V_22 & V_41 ) == 0 )
return F_6 ( V_21 , V_22 ) ;
* V_27 = V_42 ;
} else
return 0 ;
break;
}
return 1 ;
}
int F_9 ( const char * V_14 , const T_4 * * V_46 )
{
* V_46 = F_10 ( V_14 ) ;
if ( * V_46 )
return 1 ;
F_7 ( V_25 , L_16 , F_2 , V_14 ) ;
return 0 ;
}
int F_11 ( const char * V_14 , const T_5 * * V_47 )
{
* V_47 = F_12 ( V_14 ) ;
if ( * V_47 )
return 1 ;
F_7 ( V_25 , L_17 , F_2 , V_14 ) ;
return 0 ;
}
int F_13 ( const char * V_14 , const T_3 * V_48 , int * V_27 )
{
const T_3 * V_49 ;
for ( V_49 = V_48 ; V_49 -> V_14 ; V_49 ++ )
if ( strcmp ( V_49 -> V_14 , V_14 ) == 0 ) {
* V_27 = V_49 -> V_20 ;
return 1 ;
}
F_7 ( V_25 , L_18 , F_2 ) ;
for ( V_49 = V_48 ; V_49 -> V_14 ; V_49 ++ )
F_7 ( V_25 , L_19 , V_49 -> V_14 ) ;
return 0 ;
}
int F_14 ( const char * V_50 , int * V_27 )
{
long V_51 ;
if ( ! F_15 ( V_50 , & V_51 ) )
return 0 ;
* V_27 = ( int ) V_51 ;
if ( * V_27 != V_51 ) {
F_7 ( V_25 , L_20 ,
F_2 , V_50 ) ;
return 0 ;
}
return 1 ;
}
int F_15 ( const char * V_50 , long * V_27 )
{
int V_52 = V_53 ;
long V_51 ;
char * V_54 ;
V_53 = 0 ;
V_51 = strtol ( V_50 , & V_54 , 0 ) ;
if ( * V_54
|| V_54 == V_50
|| ( ( V_51 == V_55 || V_51 == V_56 ) && V_53 == V_57 )
|| ( V_51 == 0 && V_53 != 0 ) ) {
F_7 ( V_25 , L_21 ,
F_2 , V_50 ) ;
V_53 = V_52 ;
return 0 ;
}
* V_27 = V_51 ;
V_53 = V_52 ;
return 1 ;
}
int F_16 ( const char * V_50 , T_6 * V_27 )
{
int V_52 = V_53 ;
T_6 V_58 ;
char * V_54 ;
V_53 = 0 ;
V_58 = F_17 ( V_50 , & V_54 , 0 ) ;
if ( * V_54
|| V_54 == V_50
|| ( ( V_58 == V_59 || V_58 == V_60 ) && V_53 == V_57 )
|| ( V_58 == 0 && V_53 != 0 ) ) {
F_7 ( V_25 , L_21 ,
F_2 , V_50 ) ;
V_53 = V_52 ;
return 0 ;
}
* V_27 = V_58 ;
V_53 = V_52 ;
return 1 ;
}
int F_18 ( const char * V_50 , T_7 * V_27 )
{
int V_52 = V_53 ;
T_7 V_58 ;
char * V_54 ;
V_53 = 0 ;
V_58 = F_19 ( V_50 , & V_54 , 0 ) ;
if ( * V_54
|| V_54 == V_50
|| ( V_58 == V_61 && V_53 == V_57 )
|| ( V_58 == 0 && V_53 != 0 ) ) {
F_7 ( V_25 , L_21 ,
F_2 , V_50 ) ;
V_53 = V_52 ;
return 0 ;
}
* V_27 = V_58 ;
V_53 = V_52 ;
return 1 ;
}
int F_20 ( const char * V_50 , unsigned long * V_27 )
{
int V_52 = V_53 ;
char * V_62 ;
unsigned long V_51 ;
V_53 = 0 ;
V_51 = strtoul ( V_50 , & V_62 , 0 ) ;
if ( * V_62
|| V_62 == V_50
|| ( ( V_51 == V_63 ) && V_53 == V_57 )
|| ( V_51 == 0 && V_53 != 0 ) ) {
F_7 ( V_25 , L_22 ,
F_2 , V_50 ) ;
V_53 = V_52 ;
return 0 ;
}
* V_27 = V_51 ;
V_53 = V_52 ;
return 1 ;
}
int F_21 ( int V_64 , T_8 * V_65 )
{
int V_2 ;
T_9 V_66 = 0 ;
T_10 * V_67 ;
T_11 * V_68 ;
const T_8 * V_69 ;
assert ( V_65 != NULL ) ;
assert ( V_64 > V_70 ) ;
assert ( V_64 < V_71 ) ;
switch ( (enum V_72 ) V_64 ) {
case V_70 :
case V_71 :
return 0 ;
case V_73 :
V_67 = F_22 ( F_23 () , 0 ) ;
if ( V_67 == NULL ) {
F_7 ( V_25 , L_23 , F_2 , F_23 () ) ;
return 0 ;
}
F_24 ( V_65 , V_67 ) ;
break;
case V_74 :
V_2 = F_25 ( F_23 () ) ;
if ( V_2 < 0 ) {
F_7 ( V_25 , L_24 , F_2 , F_23 () ) ;
return 0 ;
}
V_68 = F_26 ( V_2 ) ;
V_2 = F_27 ( V_68 ) ;
if ( ! F_28 ( V_65 , V_2 ) ) {
F_7 ( V_25 ,
L_25 ,
F_2 , F_23 () ) ;
return 0 ;
}
break;
case V_75 :
V_69 = F_29 ( F_23 () ) ;
if ( V_69 == NULL ) {
F_7 ( V_25 , L_26 ,
F_2 , F_23 () ) ;
return 0 ;
}
F_30 ( V_65 , V_69 ) ;
break;
case V_76 :
V_2 = atoi ( F_23 () ) ;
if ( V_2 >= 0 )
F_31 ( V_65 , V_2 ) ;
break;
case V_77 :
V_2 = atoi ( F_23 () ) ;
if ( V_2 >= 0 )
F_32 ( V_65 , V_2 ) ;
break;
case V_78 :
if ( ! F_16 ( F_23 () , & V_66 ) )
return 0 ;
if ( V_66 != ( V_79 ) V_66 ) {
F_7 ( V_25 , L_27 ,
F_2 , F_23 () ) ;
return 0 ;
}
F_33 ( V_65 , ( V_79 ) V_66 ) ;
break;
case V_80 :
if ( ! F_34 ( V_65 , F_23 () , 0 ) )
return 0 ;
break;
case V_81 :
if ( ! F_35 ( V_65 , F_23 () , 0 ) )
return 0 ;
break;
case V_82 :
if ( ! F_36 ( V_65 , F_23 () ) )
return 0 ;
break;
case V_83 :
F_37 ( V_65 , V_84 ) ;
break;
case V_85 :
break;
case V_86 :
F_37 ( V_65 , V_87 ) ;
break;
case V_88 :
F_37 ( V_65 ,
V_87 |
V_89 ) ;
break;
case V_90 :
F_37 ( V_65 , V_91 ) ;
break;
case V_92 :
F_37 ( V_65 , V_93 ) ;
break;
case V_94 :
F_37 ( V_65 , V_95 ) ;
break;
case V_96 :
F_37 ( V_65 , V_97 ) ;
break;
case V_98 :
F_37 ( V_65 , V_99 ) ;
break;
case V_100 :
F_37 ( V_65 , V_101 ) ;
break;
case V_102 :
F_37 ( V_65 , V_103 ) ;
break;
case V_104 :
F_37 ( V_65 , V_105 ) ;
break;
case V_106 :
F_37 ( V_65 , V_107 ) ;
break;
case V_108 :
F_37 ( V_65 , V_109 ) ;
break;
case V_110 :
F_37 ( V_65 , V_111 ) ;
break;
case V_112 :
F_37 ( V_65 , V_113 ) ;
break;
case V_114 :
F_37 ( V_65 , V_115 ) ;
break;
case V_116 :
F_37 ( V_65 , V_117 ) ;
break;
case V_118 :
F_37 ( V_65 , V_119 ) ;
break;
case V_120 :
F_37 ( V_65 , V_121 ) ;
break;
case V_122 :
F_37 ( V_65 , V_123 ) ;
break;
}
return 1 ;
}
int F_38 ( void )
{
char * V_4 ;
const T_2 * V_8 ;
int V_124 ;
long V_125 ;
unsigned long V_126 ;
T_9 V_127 ;
T_12 V_128 ;
V_129 = NULL ;
V_4 = V_10 [ V_11 ] ;
if ( V_4 == NULL )
return 0 ;
if ( * V_4 != '-' )
return 0 ;
V_11 ++ ;
if ( strcmp ( V_4 , L_28 ) == 0 )
return 0 ;
if ( * ++ V_4 == '-' )
V_4 ++ ;
V_130 = V_4 - 1 ;
if ( ( V_129 = strchr ( V_4 , '=' ) ) != NULL )
* V_129 ++ = '\0' ;
for ( V_8 = V_12 ; V_8 -> V_14 ; ++ V_8 ) {
if ( strcmp ( V_4 , V_8 -> V_14 ) != 0 )
continue;
if ( V_8 -> V_19 == 0 || V_8 -> V_19 == '-' ) {
if ( V_129 ) {
F_7 ( V_25 ,
L_29 , F_2 , V_4 ) ;
return - 1 ;
}
return V_8 -> V_20 ;
}
if ( V_129 == NULL ) {
if ( V_10 [ V_11 ] == NULL ) {
F_7 ( V_25 ,
L_30 , F_2 , V_8 -> V_14 ) ;
return - 1 ;
}
V_129 = V_10 [ V_11 ++ ] ;
}
switch ( V_8 -> V_19 ) {
default:
case 's' :
break;
case '/' :
if ( F_39 ( V_129 ) >= 0 )
break;
F_7 ( V_25 , L_31 , F_2 , V_129 ) ;
return - 1 ;
case '<' :
if ( strcmp ( V_129 , L_32 ) == 0 || F_40 ( V_129 , V_131 ) >= 0 )
break;
F_7 ( V_25 ,
L_33 ,
F_2 , V_129 , strerror ( V_53 ) ) ;
return - 1 ;
case '>' :
if ( strcmp ( V_129 , L_32 ) == 0 || F_40 ( V_129 , V_132 ) >= 0 || V_53 == V_133 )
break;
F_7 ( V_25 ,
L_34 ,
F_2 , V_129 , strerror ( V_53 ) ) ;
return - 1 ;
case 'p' :
case 'n' :
if ( ! F_14 ( V_129 , & V_124 )
|| ( V_8 -> V_19 == 'p' && V_124 <= 0 ) ) {
F_7 ( V_25 ,
L_35 ,
F_2 , V_129 , V_8 -> V_14 ) ;
return - 1 ;
}
break;
case 'M' :
if ( ! F_16 ( V_129 , & V_127 ) ) {
F_7 ( V_25 ,
L_36 ,
F_2 , V_129 , V_8 -> V_14 ) ;
return - 1 ;
}
break;
case 'U' :
if ( ! F_18 ( V_129 , & V_128 ) ) {
F_7 ( V_25 ,
L_36 ,
F_2 , V_129 , V_8 -> V_14 ) ;
return - 1 ;
}
break;
case 'l' :
if ( ! F_15 ( V_129 , & V_125 ) ) {
F_7 ( V_25 ,
L_36 ,
F_2 , V_129 , V_8 -> V_14 ) ;
return - 1 ;
}
break;
case 'u' :
if ( ! F_20 ( V_129 , & V_126 ) ) {
F_7 ( V_25 ,
L_36 ,
F_2 , V_129 , V_8 -> V_14 ) ;
return - 1 ;
}
break;
case 'c' :
case 'E' :
case 'F' :
case 'f' :
if ( F_8 ( V_129 ,
V_8 -> V_19 == 'c' ? V_134 :
V_8 -> V_19 == 'E' ? V_135 :
V_8 -> V_19 == 'F' ? V_24
: V_136 , & V_124 ) )
break;
F_7 ( V_25 ,
L_37 ,
F_2 , V_129 , V_8 -> V_14 ) ;
return - 1 ;
}
return V_8 -> V_20 ;
}
if ( V_13 != NULL ) {
V_137 = V_4 ;
return V_13 -> V_20 ;
}
F_7 ( V_25 , L_38 , F_2 , V_4 ) ;
return - 1 ;
}
char * F_23 ( void )
{
return V_129 ;
}
char * F_41 ( void )
{
return V_130 ;
}
char * F_42 ( void )
{
return V_137 ;
}
char * * F_43 ( void )
{
return & V_10 [ V_11 ] ;
}
int F_44 ( void )
{
int V_2 = 0 ;
char * * V_49 ;
for ( V_49 = F_43 () ; * V_49 ; V_49 ++ , V_2 ++ )
continue;
return V_2 ;
}
static const char * F_45 ( const T_2 * V_8 )
{
switch ( V_8 -> V_19 ) {
case 0 :
case '-' :
return L_39 ;
case 's' :
return L_40 ;
case '/' :
return L_41 ;
case '<' :
return L_42 ;
case '>' :
return L_43 ;
case 'p' :
return L_44 ;
case 'n' :
return L_45 ;
case 'l' :
return L_46 ;
case 'u' :
return L_47 ;
case 'E' :
return L_48 ;
case 'F' :
return L_49 ;
case 'f' :
return L_50 ;
case 'M' :
return L_51 ;
case 'U' :
return L_52 ;
}
return L_53 ;
}
void F_46 ( const T_2 * V_138 )
{
const T_2 * V_8 ;
int V_2 ;
int V_139 ;
int V_140 = 5 ;
char V_141 [ 80 + 1 ] ;
char * V_4 ;
const char * V_142 ;
V_139 = V_138 [ 0 ] . V_14 != V_17 ;
for ( V_8 = V_138 ; V_8 -> V_14 ; V_8 ++ ) {
if ( V_8 -> V_14 == V_18 )
continue;
V_2 = 2 + ( int ) strlen ( V_8 -> V_14 ) ;
if ( V_8 -> V_19 != '-' )
V_2 += 1 + strlen ( F_45 ( V_8 ) ) ;
if ( V_2 < V_143 && V_2 > V_140 )
V_140 = V_2 ;
assert ( V_2 < ( int ) sizeof V_141 ) ;
}
if ( V_139 )
F_7 ( V_25 , L_54 ,
F_2 ) ;
for ( V_8 = V_138 ; V_8 -> V_14 ; V_8 ++ ) {
V_142 = V_8 -> V_144 ? V_8 -> V_144 : L_55 ;
if ( V_8 -> V_14 == V_17 ) {
F_7 ( V_25 , V_142 , F_2 ) ;
continue;
}
memset ( V_141 , ' ' , sizeof( V_141 ) - 1 ) ;
V_141 [ sizeof V_141 - 1 ] = '\0' ;
if ( V_8 -> V_14 == V_18 ) {
V_141 [ V_140 ] = '\0' ;
F_7 ( V_25 , L_56 , V_141 , V_142 ) ;
continue;
}
V_4 = V_141 ;
* V_4 ++ = ' ' ;
* V_4 ++ = '-' ;
if ( V_8 -> V_14 [ 0 ] )
V_4 += strlen ( strcpy ( V_4 , V_8 -> V_14 ) ) ;
else
* V_4 ++ = '*' ;
if ( V_8 -> V_19 != '-' ) {
* V_4 ++ = ' ' ;
V_4 += strlen ( strcpy ( V_4 , F_45 ( V_8 ) ) ) ;
}
* V_4 = ' ' ;
if ( ( int ) ( V_4 - V_141 ) >= V_143 ) {
* V_4 = '\0' ;
F_7 ( V_25 , L_57 , V_141 ) ;
memset ( V_141 , ' ' , sizeof( V_141 ) ) ;
}
V_141 [ V_140 ] = '\0' ;
F_7 ( V_25 , L_56 , V_141 , V_142 ) ;
}
}
int F_39 ( const char * V_14 )
{
struct V_145 V_146 ;
return V_14 != NULL && V_145 ( V_14 , & V_146 ) >= 0 && F_47 ( V_146 . V_147 ) ;
}
int main ( int V_6 , char * * V_7 )
{
T_13 V_8 ;
char * * V_148 ;
char * F_2 ;
V_25 = F_48 ( V_149 , V_150 | V_151 ) ;
F_2 = F_4 ( V_6 , V_7 , V_152 ) ;
while ( ( V_8 = F_38 () ) != V_153 ) {
switch ( V_154 ) {
case V_155 :
case V_153 :
case V_156 :
printf ( L_58 , F_2 ) ;
return 1 ;
case V_157 :
F_46 ( V_152 ) ;
return 0 ;
case V_158 :
printf ( L_59 , F_23 () ) ;
break;
case V_159 :
printf ( L_60 , F_23 () ) ;
break;
case V_160 :
printf ( L_61 , F_23 () ) ;
break;
case V_161 :
printf ( L_62 , F_23 () ) ;
break;
case V_162 :
printf ( L_63 , F_23 () ) ;
break;
case V_163 :
printf ( L_64 ) ;
break;
case V_164 :
printf ( L_65 , F_23 () ) ;
break;
}
}
V_9 = F_44 () ;
V_10 = F_43 () ;
printf ( L_66 , V_9 ) ;
if ( V_9 )
while ( * V_10 )
printf ( L_67 , * V_10 ++ ) ;
return 0 ;
}
