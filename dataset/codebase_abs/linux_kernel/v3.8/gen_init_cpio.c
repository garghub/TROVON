static void F_1 ( const char * V_1 )
{
unsigned int V_2 = strlen ( V_1 ) + 1 ;
fputs ( V_1 , stdout ) ;
putchar ( 0 ) ;
V_3 += V_2 ;
}
static void F_2 ( void )
{
while ( V_3 & 3 ) {
putchar ( 0 ) ;
V_3 ++ ;
}
}
static void F_3 ( const char * V_1 )
{
unsigned int V_2 = strlen ( V_1 ) + 1 ;
unsigned int V_4 ;
fputs ( V_1 , stdout ) ;
putchar ( 0 ) ;
V_3 += V_2 ;
V_4 = V_2 + 110 ;
while ( V_4 & 3 ) {
putchar ( 0 ) ;
V_3 ++ ;
V_4 ++ ;
}
}
static void F_4 ( const char * V_5 )
{
fputs ( V_5 , stdout ) ;
V_3 += 110 ;
}
static void F_5 ( void )
{
char V_5 [ 256 ] ;
const char V_1 [] = L_1 ;
sprintf ( V_5 , L_2
L_3 ,
L_4 ,
0 ,
0 ,
( long ) 0 ,
( long ) 0 ,
1 ,
( long ) 0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
( unsigned ) strlen ( V_1 ) + 1 ,
0 ) ;
F_4 ( V_5 ) ;
F_3 ( V_1 ) ;
while ( V_3 % 512 ) {
putchar ( 0 ) ;
V_3 ++ ;
}
}
static int F_6 ( const char * V_1 , const char * V_6 ,
unsigned int V_7 , T_1 V_8 , T_2 V_9 )
{
char V_5 [ 256 ] ;
if ( V_1 [ 0 ] == '/' )
V_1 ++ ;
sprintf ( V_5 , L_2
L_3 ,
L_4 ,
V_10 ++ ,
V_11 | V_7 ,
( long ) V_8 ,
( long ) V_9 ,
1 ,
( long ) V_12 ,
( unsigned ) strlen ( V_6 ) + 1 ,
3 ,
1 ,
0 ,
0 ,
( unsigned ) strlen ( V_1 ) + 1 ,
0 ) ;
F_4 ( V_5 ) ;
F_1 ( V_1 ) ;
F_2 () ;
F_1 ( V_6 ) ;
F_2 () ;
return 0 ;
}
static int F_7 ( const char * line )
{
char V_1 [ V_13 + 1 ] ;
char V_6 [ V_13 + 1 ] ;
unsigned int V_7 ;
int V_8 ;
int V_9 ;
int V_14 = - 1 ;
if ( 5 != sscanf ( line , L_5 F_8 ( V_13 ) L_6 F_8 ( V_13 ) L_7 , V_1 , V_6 , & V_7 , & V_8 , & V_9 ) ) {
fprintf ( V_15 , L_8 , line ) ;
goto V_16;
}
V_14 = F_6 ( V_1 , V_6 , V_7 , V_8 , V_9 ) ;
V_16:
return V_14 ;
}
static int F_9 ( const char * V_1 , unsigned int V_7 ,
T_1 V_8 , T_2 V_9 )
{
char V_5 [ 256 ] ;
if ( V_1 [ 0 ] == '/' )
V_1 ++ ;
sprintf ( V_5 , L_2
L_3 ,
L_4 ,
V_10 ++ ,
V_7 ,
( long ) V_8 ,
( long ) V_9 ,
2 ,
( long ) V_12 ,
0 ,
3 ,
1 ,
0 ,
0 ,
( unsigned ) strlen ( V_1 ) + 1 ,
0 ) ;
F_4 ( V_5 ) ;
F_3 ( V_1 ) ;
return 0 ;
}
static int F_10 ( const char * line , enum V_17 V_18 )
{
char V_1 [ V_13 + 1 ] ;
unsigned int V_7 ;
int V_8 ;
int V_9 ;
int V_14 = - 1 ;
if ( 4 != sscanf ( line , L_5 F_8 ( V_13 ) L_7 , V_1 , & V_7 , & V_8 , & V_9 ) ) {
fprintf ( V_15 , L_9 ,
line , V_19 [ V_18 ] . type ) ;
goto V_16;
}
V_7 |= V_19 [ V_18 ] . V_7 ;
V_14 = F_9 ( V_1 , V_7 , V_8 , V_9 ) ;
V_16:
return V_14 ;
}
static int F_11 ( const char * line )
{
return F_10 ( line , V_20 ) ;
}
static int F_12 ( const char * line )
{
return F_10 ( line , V_21 ) ;
}
static int F_13 ( const char * line )
{
return F_10 ( line , V_22 ) ;
}
static int F_14 ( const char * V_1 , unsigned int V_7 ,
T_1 V_8 , T_2 V_9 , char V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
char V_5 [ 256 ] ;
if ( V_23 == 'b' )
V_7 |= V_26 ;
else
V_7 |= V_27 ;
if ( V_1 [ 0 ] == '/' )
V_1 ++ ;
sprintf ( V_5 , L_2
L_3 ,
L_4 ,
V_10 ++ ,
V_7 ,
( long ) V_8 ,
( long ) V_9 ,
1 ,
( long ) V_12 ,
0 ,
3 ,
1 ,
V_24 ,
V_25 ,
( unsigned ) strlen ( V_1 ) + 1 ,
0 ) ;
F_4 ( V_5 ) ;
F_3 ( V_1 ) ;
return 0 ;
}
static int F_15 ( const char * line )
{
char V_1 [ V_13 + 1 ] ;
unsigned int V_7 ;
int V_8 ;
int V_9 ;
char V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
int V_14 = - 1 ;
if ( 7 != sscanf ( line , L_5 F_8 ( V_13 ) L_10 ,
V_1 , & V_7 , & V_8 , & V_9 , & V_23 , & V_24 , & V_25 ) ) {
fprintf ( V_15 , L_11 , line ) ;
goto V_16;
}
V_14 = F_14 ( V_1 , V_7 , V_8 , V_9 , V_23 , V_24 , V_25 ) ;
V_16:
return V_14 ;
}
static int F_16 ( const char * V_1 , const char * V_28 ,
unsigned int V_7 , T_1 V_8 , T_2 V_9 ,
unsigned int V_29 )
{
char V_5 [ 256 ] ;
char * V_30 = NULL ;
struct V_31 V_32 ;
long V_33 ;
int V_34 = - 1 ;
int V_35 ;
int V_14 = - 1 ;
int V_36 ;
unsigned int V_37 ;
V_7 |= V_38 ;
V_34 = F_17 ( V_28 , V_39 ) ;
if ( V_34 < 0 ) {
fprintf ( V_15 , L_12 , V_28 ) ;
goto error;
}
V_35 = F_18 ( V_34 , & V_32 ) ;
if ( V_35 ) {
fprintf ( V_15 , L_13 , V_28 ) ;
goto error;
}
V_30 = malloc ( V_32 . V_40 ) ;
if ( ! V_30 ) {
fprintf ( V_15 , L_14 ) ;
goto error;
}
V_35 = F_19 ( V_34 , V_30 , V_32 . V_40 ) ;
if ( V_35 < 0 ) {
fprintf ( V_15 , L_15 , V_28 ) ;
goto error;
}
V_33 = 0 ;
for ( V_37 = 1 ; V_37 <= V_29 ; V_37 ++ ) {
if ( V_37 == V_29 ) V_33 = V_32 . V_40 ;
if ( V_1 [ 0 ] == '/' )
V_1 ++ ;
V_36 = strlen ( V_1 ) + 1 ;
sprintf ( V_5 , L_2
L_16 ,
L_4 ,
V_10 ,
V_7 ,
( long ) V_8 ,
( long ) V_9 ,
V_29 ,
( long ) V_32 . V_41 ,
V_33 ,
3 ,
1 ,
0 ,
0 ,
V_36 ,
0 ) ;
F_4 ( V_5 ) ;
F_1 ( V_1 ) ;
F_2 () ;
if ( V_33 ) {
if ( fwrite ( V_30 , V_33 , 1 , stdout ) != 1 ) {
fprintf ( V_15 , L_17 ) ;
goto error;
}
V_3 += V_33 ;
F_2 () ;
}
V_1 += V_36 ;
}
V_10 ++ ;
V_14 = 0 ;
error:
if ( V_30 ) free ( V_30 ) ;
if ( V_34 >= 0 ) F_20 ( V_34 ) ;
return V_14 ;
}
static char * F_21 ( char * V_42 )
{
char V_43 [ V_13 + 1 ] ;
char V_44 [ V_13 + 1 ] ;
char * V_45 ;
char * V_46 ;
for ( V_45 = NULL ; ( V_45 = strstr ( V_42 , L_18 ) ) ; ) {
V_46 = strchr ( V_45 , '}' ) ;
if ( V_45 < V_46 ) {
* V_44 = * V_43 = '\0' ;
strncat ( V_44 , V_45 + 2 , V_46 - V_45 - 2 ) ;
strncat ( V_43 , V_42 , V_45 - V_42 ) ;
strncat ( V_43 , getenv ( V_44 ) ,
V_13 - strlen ( V_43 ) ) ;
strncat ( V_43 , V_46 + 1 ,
V_13 - strlen ( V_43 ) ) ;
strncpy ( V_42 , V_43 , V_13 ) ;
V_42 [ V_13 ] = 0 ;
} else
break;
}
return V_42 ;
}
static int F_22 ( const char * line )
{
char V_1 [ V_13 + 1 ] ;
char * V_47 = NULL ;
char V_28 [ V_13 + 1 ] ;
unsigned int V_7 ;
int V_8 ;
int V_9 ;
int V_29 = 1 ;
int V_46 = 0 , V_48 = 0 ;
int V_14 = - 1 ;
if ( 5 > sscanf ( line , L_5 F_8 ( V_13 ) L_6 F_8 ( V_13 )
L_19 ,
V_1 , V_28 , & V_7 , & V_8 , & V_9 , & V_46 ) ) {
fprintf ( V_15 , L_20 , line ) ;
goto V_16;
}
if ( V_46 && isgraph ( line [ V_46 ] ) ) {
int V_49 ;
int V_50 ;
V_47 = malloc ( strlen ( line ) ) ;
if ( ! V_47 ) {
fprintf ( V_15 , L_21 , V_48 ) ;
goto V_16;
}
V_48 = strlen ( V_1 ) + 1 ;
memcpy ( V_47 , V_1 , V_48 ) ;
do {
V_50 = 0 ;
if ( sscanf ( line + V_46 , L_5 F_8 ( V_13 ) L_22 ,
V_1 , & V_50 ) < 1 )
break;
V_49 = strlen ( V_1 ) + 1 ;
memcpy ( V_47 + V_48 , V_1 , V_49 ) ;
V_48 += V_49 ;
V_29 ++ ;
V_46 += V_50 ;
} while ( isgraph ( line [ V_46 ] ) );
} else {
V_47 = V_1 ;
}
V_14 = F_16 ( V_47 , F_21 ( V_28 ) ,
V_7 , V_8 , V_9 , V_29 ) ;
V_16:
if ( V_48 ) free ( V_47 ) ;
return V_14 ;
}
static void F_23 ( const char * V_51 )
{
fprintf ( V_15 , L_23
L_24
L_25
L_26
L_27
L_25
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_25
L_35
L_36
L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_25
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_25
L_53
L_54
L_55 ,
V_51 ) ;
}
int main ( int V_52 , char * V_53 [] )
{
T_3 * V_54 ;
char line [ V_55 ] ;
char * args , * type ;
int V_56 = 0 ;
int V_57 = 0 ;
const char * V_58 ;
V_12 = time ( NULL ) ;
while ( 1 ) {
int V_59 = F_24 ( V_52 , V_53 , L_56 ) ;
char * V_60 ;
if ( V_59 == - 1 )
break;
switch ( V_59 ) {
case 't' :
V_12 = strtol ( V_61 , & V_60 , 10 ) ;
if ( ! * V_61 || * V_60 ) {
fprintf ( V_15 , L_57 ,
V_61 ) ;
F_23 ( V_53 [ 0 ] ) ;
exit ( 1 ) ;
}
break;
case 'h' :
case '?' :
F_23 ( V_53 [ 0 ] ) ;
exit ( V_59 == 'h' ? 0 : 1 ) ;
}
}
if ( V_52 - V_62 != 1 ) {
F_23 ( V_53 [ 0 ] ) ;
exit ( 1 ) ;
}
V_58 = V_53 [ V_62 ] ;
if ( ! strcmp ( V_58 , L_58 ) )
V_54 = V_63 ;
else if ( ! ( V_54 = fopen ( V_58 , L_59 ) ) ) {
fprintf ( V_15 , L_60 ,
V_58 , strerror ( V_64 ) ) ;
F_23 ( V_53 [ 0 ] ) ;
exit ( 1 ) ;
}
while ( fgets ( line , V_55 , V_54 ) ) {
int V_65 ;
T_4 V_66 = strlen ( line ) ;
V_57 ++ ;
if ( '#' == * line ) {
continue;
}
if ( ! ( type = strtok ( line , L_61 ) ) ) {
fprintf ( V_15 ,
L_62 ,
V_57 , line ) ;
V_56 = - 1 ;
break;
}
if ( '\n' == * type ) {
continue;
}
if ( V_66 == strlen ( type ) ) {
continue;
}
if ( ! ( args = strtok ( NULL , L_25 ) ) ) {
fprintf ( V_15 ,
L_63 ,
V_57 , line ) ;
V_56 = - 1 ;
}
for ( V_65 = 0 ; V_67 [ V_65 ] . type ; V_65 ++ ) {
int V_14 ;
if ( ! strcmp ( line , V_67 [ V_65 ] . type ) ) {
if ( ( V_14 = V_67 [ V_65 ] . F_25 ( args ) ) ) {
V_56 = V_14 ;
fprintf ( V_15 , L_64 , V_57 ) ;
}
break;
}
}
if ( NULL == V_67 [ V_65 ] . type ) {
fprintf ( V_15 , L_65 ,
V_57 , line ) ;
}
}
if ( V_56 == 0 )
F_5 () ;
exit ( V_56 ) ;
}
