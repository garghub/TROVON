static int F_1 ( const void * V_1 , int V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
static int F_3 ( void )
{
if ( V_3 )
return V_3 () ;
return - 1 ;
}
int F_4 ( int V_4 )
{
char V_5 = V_4 ;
if ( V_4 == '\n' )
F_4 ( '\r' ) ;
return F_1 ( & V_5 , 1 ) == 1 ? V_4 : - 1 ;
}
static int F_5 ( void )
{
int V_4 ;
if ( V_6 == 0 ) {
V_7 = line ;
for (; ; ) {
V_4 = F_3 () ;
if ( V_4 == - 1 || V_4 == 4 )
break;
if ( V_4 == '\r' || V_4 == '\n' ) {
* V_7 ++ = '\n' ;
F_4 ( '\n' ) ;
break;
}
switch ( V_4 ) {
case 0177 :
case '\b' :
if ( V_7 > line ) {
F_4 ( '\b' ) ;
F_4 ( ' ' ) ;
F_4 ( '\b' ) ;
-- V_7 ;
}
break;
case 'U' & 0x1F :
while ( V_7 > line ) {
F_4 ( '\b' ) ;
F_4 ( ' ' ) ;
F_4 ( '\b' ) ;
-- V_7 ;
}
break;
default:
if ( V_7 >= & line [ sizeof( line ) - 1 ] )
F_4 ( '\a' ) ;
else {
F_4 ( V_4 ) ;
* V_7 ++ = V_4 ;
}
}
}
V_6 = V_7 - line ;
V_7 = line ;
}
if ( V_6 == 0 )
return - 1 ;
-- V_6 ;
return * V_7 ++ ;
}
char * F_6 ( char * V_8 , int V_2 )
{
char * V_9 ;
int V_4 ;
for ( V_9 = V_8 ; V_9 < V_8 + V_2 - 1 ; ) {
V_4 = F_5 () ;
if ( V_4 == - 1 ) {
if ( V_9 == V_8 )
return NULL ;
break;
}
* V_9 ++ = V_4 ;
if ( V_4 == '\n' )
break;
}
* V_9 = 0 ;
return V_8 ;
}
void F_7 ( const char * V_10 , ... )
{
T_1 args ;
static char V_11 [ 1024 ] ;
int V_12 , V_13 ;
va_start ( args , V_10 ) ;
V_13 = vsnprintf ( V_11 , sizeof( V_11 ) , V_10 , args ) ;
va_end ( args ) ;
V_12 = F_1 ( V_11 , V_13 ) ;
if ( V_13 && V_12 == 0 ) {
F_8 ( V_11 ) ;
}
}
void F_9 ( const char * V_8 )
{
F_1 ( V_8 , strlen ( V_8 ) ) ;
}
