static int F_1 ( const char * V_1 , int V_2 )
{
static const char * const V_3 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 ,
L_6 , L_7 , L_8 , L_9
} ;
char * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < ( int ) F_2 ( V_3 ) ; V_5 ++ ) {
const char * V_6 = V_3 [ V_5 ] ;
if ( ! strncasecmp ( V_1 , V_6 , V_2 ) && ! V_6 [ V_2 ] )
return V_5 - 1 ;
}
V_5 = strtol ( V_1 , & V_4 , 10 ) ;
if ( V_4 - V_1 == V_2 && V_5 >= - 1 && V_5 <= 255 )
return V_5 ;
return - 2 ;
}
static int F_3 ( const char * V_1 , int V_2 )
{
static const int V_7 [] = { 1 , 2 , 4 , 5 , 7 } ;
static const char * const V_8 [] = {
L_10 , L_11 , L_12 , L_13 , L_14
} ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_8 ) ; V_5 ++ ) {
const char * V_6 = V_8 [ V_5 ] ;
if ( ! strncasecmp ( V_1 , V_6 , V_2 ) && ! V_6 [ V_2 ] )
return V_7 [ V_5 ] ;
}
return - 1 ;
}
void F_4 ( const char * V_9 , const char * V_10 , char * V_11 )
{
F_5 ( V_9 , strlen ( V_9 ) , V_10 , V_11 ) ;
}
void F_5 ( const char * V_9 , int V_12 , const char * V_10 ,
char * V_11 )
{
const char * V_13 = V_9 ;
int V_2 = V_12 ;
int V_14 = - 1 ;
int V_15 = - 2 ;
int V_16 = - 2 ;
if ( ! strncasecmp ( V_9 , L_15 , V_2 ) ) {
strcpy ( V_11 , V_17 ) ;
return;
}
while ( V_2 > 0 ) {
const char * V_18 = V_13 ;
int V_19 , V_20 = 0 ;
while ( V_2 > 0 && ! isspace ( V_18 [ V_20 ] ) ) {
V_20 ++ ;
V_2 -- ;
}
V_13 = V_18 + V_20 ;
while ( V_2 > 0 && isspace ( * V_13 ) ) {
V_13 ++ ;
V_2 -- ;
}
V_19 = F_1 ( V_18 , V_20 ) ;
if ( V_19 >= - 1 ) {
if ( V_15 == - 2 ) {
V_15 = V_19 ;
continue;
}
if ( V_16 == - 2 ) {
V_16 = V_19 ;
continue;
}
goto V_21;
}
V_19 = F_3 ( V_18 , V_20 ) ;
if ( V_19 < 0 || V_14 != - 1 )
goto V_21;
V_14 = V_19 ;
}
if ( V_14 >= 0 || V_15 >= 0 || V_16 >= 0 ) {
int V_22 = 0 ;
* V_11 ++ = '\033' ;
* V_11 ++ = '[' ;
if ( V_14 >= 0 ) {
* V_11 ++ = '0' + V_14 ;
V_22 ++ ;
}
if ( V_15 >= 0 ) {
if ( V_22 ++ )
* V_11 ++ = ';' ;
if ( V_15 < 8 ) {
* V_11 ++ = '3' ;
* V_11 ++ = '0' + V_15 ;
} else {
V_11 += sprintf ( V_11 , L_16 , V_15 ) ;
}
}
if ( V_16 >= 0 ) {
if ( V_22 ++ )
* V_11 ++ = ';' ;
if ( V_16 < 8 ) {
* V_11 ++ = '4' ;
* V_11 ++ = '0' + V_16 ;
} else {
V_11 += sprintf ( V_11 , L_17 , V_16 ) ;
}
}
* V_11 ++ = 'm' ;
}
* V_11 = 0 ;
return;
V_21:
F_6 ( L_18 , V_12 , V_9 , V_10 ) ;
}
int F_7 ( const char * V_10 , const char * V_9 , int V_23 )
{
if ( V_9 ) {
if ( ! strcasecmp ( V_9 , L_19 ) )
return 0 ;
if ( ! strcasecmp ( V_9 , L_20 ) )
return 1 ;
if ( ! strcasecmp ( V_9 , L_21 ) )
goto V_24;
}
if ( ! F_8 ( V_10 , V_9 ) )
return 0 ;
V_24:
if ( V_23 < 0 )
V_23 = F_9 ( 1 ) ;
if ( V_23 || ( F_10 () && V_25 ) ) {
char * V_26 = getenv ( L_22 ) ;
if ( V_26 && strcmp ( V_26 , L_23 ) )
return 1 ;
}
return 0 ;
}
int F_11 ( const char * V_10 , const char * V_9 , void * V_27 )
{
if ( ! strcmp ( V_10 , L_24 ) ) {
V_28 = F_7 ( V_10 , V_9 , - 1 ) ;
return 0 ;
}
return F_12 ( V_10 , V_9 , V_27 ) ;
}
static int F_13 ( char * V_29 , T_1 V_30 , const char * V_31 ,
const char * V_32 , T_2 args , const char * V_33 )
{
int V_34 = 0 ;
if ( V_28 < 0 ) {
if ( F_9 ( 1 ) || F_10 () )
V_28 = 1 ;
else
V_28 = 0 ;
}
if ( V_28 && * V_31 )
V_34 += F_14 ( V_29 , V_30 , L_25 , V_31 ) ;
V_34 += F_15 ( V_29 + V_34 , V_30 - V_34 , V_32 , args ) ;
if ( V_28 && * V_31 )
V_34 += F_14 ( V_29 + V_34 , V_30 - V_34 , L_25 , V_17 ) ;
if ( V_33 )
V_34 += F_14 ( V_29 + V_34 , V_30 - V_34 , L_25 , V_33 ) ;
return V_34 ;
}
static int F_16 ( T_3 * V_35 , const char * V_31 , const char * V_32 ,
T_2 args , const char * V_33 )
{
int V_34 = 0 ;
if ( V_28 < 0 ) {
if ( F_9 ( fileno ( V_35 ) ) || F_10 () )
V_28 = 1 ;
else
V_28 = 0 ;
}
if ( V_28 && * V_31 )
V_34 += fprintf ( V_35 , L_25 , V_31 ) ;
V_34 += vfprintf ( V_35 , V_32 , args ) ;
if ( V_28 && * V_31 )
V_34 += fprintf ( V_35 , L_25 , V_17 ) ;
if ( V_33 )
V_34 += fprintf ( V_35 , L_25 , V_33 ) ;
return V_34 ;
}
int F_17 ( char * V_29 , T_1 V_30 , const char * V_31 ,
const char * V_32 , T_2 args )
{
return F_13 ( V_29 , V_30 , V_31 , V_32 , args , NULL ) ;
}
int F_18 ( T_3 * V_35 , const char * V_31 , const char * V_32 , T_2 args )
{
return F_16 ( V_35 , V_31 , V_32 , args , NULL ) ;
}
int F_19 ( char * V_29 , T_1 V_30 , const char * V_31 ,
const char * V_32 , ... )
{
T_2 args ;
int V_34 ;
va_start ( args , V_32 ) ;
V_34 = F_17 ( V_29 , V_30 , V_31 , V_32 , args ) ;
va_end ( args ) ;
return V_34 ;
}
int F_20 ( T_3 * V_35 , const char * V_31 , const char * V_32 , ... )
{
T_2 args ;
int V_34 ;
va_start ( args , V_32 ) ;
V_34 = F_18 ( V_35 , V_31 , V_32 , args ) ;
va_end ( args ) ;
return V_34 ;
}
int F_21 ( T_3 * V_35 , const char * V_31 , const char * V_32 , ... )
{
T_2 args ;
int V_34 ;
va_start ( args , V_32 ) ;
V_34 = F_16 ( V_35 , V_31 , V_32 , args , L_26 ) ;
va_end ( args ) ;
return V_34 ;
}
int F_22 ( T_3 * V_35 , const char * V_31 ,
T_1 V_36 , const char * V_37 )
{
if ( ! * V_31 )
return fwrite ( V_37 , V_36 , 1 , V_35 ) != 1 ;
while ( V_36 ) {
char * V_38 = memchr ( V_37 , '\n' , V_36 ) ;
if ( V_38 != V_37 && ( fputs ( V_31 , V_35 ) < 0 ||
fwrite ( V_37 , V_38 ? ( T_1 ) ( V_38 - V_37 ) : V_36 , 1 , V_35 ) != 1 ||
fputs ( V_17 , V_35 ) < 0 ) )
return - 1 ;
if ( ! V_38 )
return 0 ;
if ( fputc ( '\n' , V_35 ) < 0 )
return - 1 ;
V_36 -= V_38 + 1 - V_37 ;
V_37 = V_38 + 1 ;
}
return 0 ;
}
const char * F_23 ( double V_39 )
{
const char * V_31 = V_40 ;
if ( fabs ( V_39 ) >= V_41 )
V_31 = V_42 ;
else {
if ( fabs ( V_39 ) > V_43 )
V_31 = V_44 ;
}
return V_31 ;
}
int F_24 ( T_3 * V_35 , const char * V_32 , double V_39 )
{
int V_34 ;
const char * V_31 ;
V_31 = F_23 ( V_39 ) ;
V_34 = F_20 ( V_35 , V_31 , V_32 , V_39 ) ;
return V_34 ;
}
int F_25 ( char * V_29 , T_1 V_30 , const char * V_32 , double V_9 )
{
const char * V_31 = F_23 ( V_9 ) ;
return F_19 ( V_29 , V_30 , V_31 , V_32 , V_9 ) ;
}
int F_26 ( char * V_29 , T_1 V_30 , const char * V_32 , ... )
{
T_2 args ;
double V_39 ;
va_start ( args , V_32 ) ;
V_39 = va_arg ( args , double ) ;
va_end ( args ) ;
return F_25 ( V_29 , V_30 , V_32 , V_39 ) ;
}
