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
if ( V_3 || F_4 () ) {
char * V_5 = getenv ( L_4 ) ;
if ( V_5 && strcmp ( V_5 , L_5 ) )
return 1 ;
}
return 0 ;
}
int F_5 ( const char * V_1 , const char * V_2 , void * V_6 )
{
if ( ! strcmp ( V_1 , L_6 ) ) {
V_7 = F_1 ( V_1 , V_2 , - 1 ) ;
return 0 ;
}
return F_6 ( V_1 , V_2 , V_6 ) ;
}
static int F_7 ( char * V_8 , T_1 V_9 , const char * V_10 ,
const char * V_11 , T_2 args , const char * V_12 )
{
int V_13 = 0 ;
if ( V_7 < 0 ) {
if ( F_3 ( 1 ) || F_4 () )
V_7 = 1 ;
else
V_7 = 0 ;
}
if ( V_7 && * V_10 )
V_13 += F_8 ( V_8 , V_9 , L_7 , V_10 ) ;
V_13 += F_9 ( V_8 + V_13 , V_9 - V_13 , V_11 , args ) ;
if ( V_7 && * V_10 )
V_13 += F_8 ( V_8 + V_13 , V_9 - V_13 , L_7 , V_14 ) ;
if ( V_12 )
V_13 += F_8 ( V_8 + V_13 , V_9 - V_13 , L_7 , V_12 ) ;
return V_13 ;
}
static int F_10 ( T_3 * V_15 , const char * V_10 , const char * V_11 ,
T_2 args )
{
int V_13 = 0 ;
if ( V_7 < 0 ) {
if ( F_3 ( fileno ( V_15 ) ) || F_4 () )
V_7 = 1 ;
else
V_7 = 0 ;
}
if ( V_7 && * V_10 )
fprintf ( V_15 , L_7 , V_10 ) ;
V_13 += vfprintf ( V_15 , V_11 , args ) ;
if ( V_7 && * V_10 )
fprintf ( V_15 , L_7 , V_14 ) ;
return V_13 ;
}
int F_11 ( char * V_8 , T_1 V_9 , const char * V_10 ,
const char * V_11 , T_2 args )
{
return F_7 ( V_8 , V_9 , V_10 , V_11 , args , NULL ) ;
}
int F_12 ( T_3 * V_15 , const char * V_10 , const char * V_11 , T_2 args )
{
return F_10 ( V_15 , V_10 , V_11 , args ) ;
}
int F_13 ( char * V_8 , T_1 V_9 , const char * V_10 ,
const char * V_11 , ... )
{
T_2 args ;
int V_13 ;
va_start ( args , V_11 ) ;
V_13 = F_11 ( V_8 , V_9 , V_10 , V_11 , args ) ;
va_end ( args ) ;
return V_13 ;
}
int F_14 ( T_3 * V_15 , const char * V_10 , const char * V_11 , ... )
{
T_2 args ;
int V_13 ;
va_start ( args , V_11 ) ;
V_13 = F_12 ( V_15 , V_10 , V_11 , args ) ;
va_end ( args ) ;
return V_13 ;
}
int F_15 ( T_3 * V_15 , const char * V_10 ,
T_1 V_16 , const char * V_17 )
{
if ( ! * V_10 )
return fwrite ( V_17 , V_16 , 1 , V_15 ) != 1 ;
while ( V_16 ) {
char * V_18 = memchr ( V_17 , '\n' , V_16 ) ;
if ( V_18 != V_17 && ( fputs ( V_10 , V_15 ) < 0 ||
fwrite ( V_17 , V_18 ? ( T_1 ) ( V_18 - V_17 ) : V_16 , 1 , V_15 ) != 1 ||
fputs ( V_14 , V_15 ) < 0 ) )
return - 1 ;
if ( ! V_18 )
return 0 ;
if ( fputc ( '\n' , V_15 ) < 0 )
return - 1 ;
V_16 -= V_18 + 1 - V_17 ;
V_17 = V_18 + 1 ;
}
return 0 ;
}
const char * F_16 ( double V_19 )
{
const char * V_10 = V_20 ;
if ( fabs ( V_19 ) >= V_21 )
V_10 = V_22 ;
else {
if ( fabs ( V_19 ) > V_23 )
V_10 = V_24 ;
}
return V_10 ;
}
int F_17 ( T_3 * V_15 , const char * V_11 , double V_19 )
{
int V_13 ;
const char * V_10 ;
V_10 = F_16 ( V_19 ) ;
V_13 = F_14 ( V_15 , V_10 , V_11 , V_19 ) ;
return V_13 ;
}
int F_18 ( char * V_8 , T_1 V_9 , const char * V_11 , double V_2 )
{
const char * V_10 = F_16 ( V_2 ) ;
return F_13 ( V_8 , V_9 , V_10 , V_11 , V_2 ) ;
}
int F_19 ( char * V_8 , T_1 V_9 , const char * V_11 , ... )
{
T_2 args ;
double V_19 ;
va_start ( args , V_11 ) ;
V_19 = va_arg ( args , double ) ;
va_end ( args ) ;
return F_18 ( V_8 , V_9 , V_11 , V_19 ) ;
}
int F_20 ( char * V_8 , T_1 V_9 , const char * V_11 , ... )
{
T_2 args ;
int V_25 ;
double V_19 ;
const char * V_10 ;
va_start ( args , V_11 ) ;
V_25 = va_arg ( args , int ) ;
V_19 = va_arg ( args , double ) ;
va_end ( args ) ;
V_10 = F_16 ( V_19 ) ;
return F_13 ( V_8 , V_9 , V_10 , V_11 , V_25 , V_19 ) ;
}
