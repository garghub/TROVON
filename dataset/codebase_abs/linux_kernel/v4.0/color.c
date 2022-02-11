int F_1 ( const char * V_1 , const char * V_2 , int V_3 )
{
if ( V_2 ) {
if ( ! strcasecmp ( V_2 , L_1 ) )
return 0 ;
if ( ! strcasecmp ( V_2 , L_2 ) )
return 1 ;
if ( ! strcasecmp ( V_2 , L_3 ) )
goto V_4;
}
if ( ! F_2 ( V_1 , V_2 ) )
return 0 ;
V_4:
if ( V_3 < 0 )
V_3 = F_3 ( 1 ) ;
if ( V_3 || ( F_4 () && V_5 ) ) {
char * V_6 = getenv ( L_4 ) ;
if ( V_6 && strcmp ( V_6 , L_5 ) )
return 1 ;
}
return 0 ;
}
int F_5 ( const char * V_1 , const char * V_2 , void * V_7 )
{
if ( ! strcmp ( V_1 , L_6 ) ) {
V_8 = F_1 ( V_1 , V_2 , - 1 ) ;
return 0 ;
}
return F_6 ( V_1 , V_2 , V_7 ) ;
}
static int F_7 ( char * V_9 , T_1 V_10 , const char * V_11 ,
const char * V_12 , T_2 args , const char * V_13 )
{
int V_14 = 0 ;
if ( V_8 < 0 ) {
if ( F_3 ( 1 ) || F_4 () )
V_8 = 1 ;
else
V_8 = 0 ;
}
if ( V_8 && * V_11 )
V_14 += F_8 ( V_9 , V_10 , L_7 , V_11 ) ;
V_14 += F_9 ( V_9 + V_14 , V_10 - V_14 , V_12 , args ) ;
if ( V_8 && * V_11 )
V_14 += F_8 ( V_9 + V_14 , V_10 - V_14 , L_7 , V_15 ) ;
if ( V_13 )
V_14 += F_8 ( V_9 + V_14 , V_10 - V_14 , L_7 , V_13 ) ;
return V_14 ;
}
static int F_10 ( T_3 * V_16 , const char * V_11 , const char * V_12 ,
T_2 args , const char * V_13 )
{
int V_14 = 0 ;
if ( V_8 < 0 ) {
if ( F_3 ( fileno ( V_16 ) ) || F_4 () )
V_8 = 1 ;
else
V_8 = 0 ;
}
if ( V_8 && * V_11 )
V_14 += fprintf ( V_16 , L_7 , V_11 ) ;
V_14 += vfprintf ( V_16 , V_12 , args ) ;
if ( V_8 && * V_11 )
V_14 += fprintf ( V_16 , L_7 , V_15 ) ;
if ( V_13 )
V_14 += fprintf ( V_16 , L_7 , V_13 ) ;
return V_14 ;
}
int F_11 ( char * V_9 , T_1 V_10 , const char * V_11 ,
const char * V_12 , T_2 args )
{
return F_7 ( V_9 , V_10 , V_11 , V_12 , args , NULL ) ;
}
int F_12 ( T_3 * V_16 , const char * V_11 , const char * V_12 , T_2 args )
{
return F_10 ( V_16 , V_11 , V_12 , args , NULL ) ;
}
int F_13 ( char * V_9 , T_1 V_10 , const char * V_11 ,
const char * V_12 , ... )
{
T_2 args ;
int V_14 ;
va_start ( args , V_12 ) ;
V_14 = F_11 ( V_9 , V_10 , V_11 , V_12 , args ) ;
va_end ( args ) ;
return V_14 ;
}
int F_14 ( T_3 * V_16 , const char * V_11 , const char * V_12 , ... )
{
T_2 args ;
int V_14 ;
va_start ( args , V_12 ) ;
V_14 = F_12 ( V_16 , V_11 , V_12 , args ) ;
va_end ( args ) ;
return V_14 ;
}
int F_15 ( T_3 * V_16 , const char * V_11 , const char * V_12 , ... )
{
T_2 args ;
int V_14 ;
va_start ( args , V_12 ) ;
V_14 = F_10 ( V_16 , V_11 , V_12 , args , L_8 ) ;
va_end ( args ) ;
return V_14 ;
}
int F_16 ( T_3 * V_16 , const char * V_11 ,
T_1 V_17 , const char * V_18 )
{
if ( ! * V_11 )
return fwrite ( V_18 , V_17 , 1 , V_16 ) != 1 ;
while ( V_17 ) {
char * V_19 = memchr ( V_18 , '\n' , V_17 ) ;
if ( V_19 != V_18 && ( fputs ( V_11 , V_16 ) < 0 ||
fwrite ( V_18 , V_19 ? ( T_1 ) ( V_19 - V_18 ) : V_17 , 1 , V_16 ) != 1 ||
fputs ( V_15 , V_16 ) < 0 ) )
return - 1 ;
if ( ! V_19 )
return 0 ;
if ( fputc ( '\n' , V_16 ) < 0 )
return - 1 ;
V_17 -= V_19 + 1 - V_18 ;
V_18 = V_19 + 1 ;
}
return 0 ;
}
const char * F_17 ( double V_20 )
{
const char * V_11 = V_21 ;
if ( fabs ( V_20 ) >= V_22 )
V_11 = V_23 ;
else {
if ( fabs ( V_20 ) > V_24 )
V_11 = V_25 ;
}
return V_11 ;
}
int F_18 ( T_3 * V_16 , const char * V_12 , double V_20 )
{
int V_14 ;
const char * V_11 ;
V_11 = F_17 ( V_20 ) ;
V_14 = F_14 ( V_16 , V_11 , V_12 , V_20 ) ;
return V_14 ;
}
int F_19 ( char * V_9 , T_1 V_10 , const char * V_12 , double V_2 )
{
const char * V_11 = F_17 ( V_2 ) ;
return F_13 ( V_9 , V_10 , V_11 , V_12 , V_2 ) ;
}
int F_20 ( char * V_9 , T_1 V_10 , const char * V_12 , ... )
{
T_2 args ;
double V_20 ;
va_start ( args , V_12 ) ;
V_20 = va_arg ( args , double ) ;
va_end ( args ) ;
return F_19 ( V_9 , V_10 , V_12 , V_20 ) ;
}
int F_21 ( char * V_9 , T_1 V_10 , const char * V_12 , ... )
{
T_2 args ;
int V_26 ;
double V_20 ;
const char * V_11 ;
va_start ( args , V_12 ) ;
V_26 = va_arg ( args , int ) ;
V_20 = va_arg ( args , double ) ;
va_end ( args ) ;
V_11 = F_17 ( V_20 ) ;
return F_13 ( V_9 , V_10 , V_11 , V_12 , V_26 , V_20 ) ;
}
