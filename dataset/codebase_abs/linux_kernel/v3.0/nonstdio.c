int F_1 ( int V_1 )
{
char V_2 = V_1 ;
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
return F_2 ( & V_2 , 1 ) == 1 ? V_1 : - 1 ;
}
int F_3 ( const char * V_3 , unsigned long V_4 )
{
int V_1 ;
unsigned long V_5 ;
V_4 *= V_6 ? V_6 : 25000000 ;
V_5 = F_4 () ;
do {
V_7 = line ;
for (; ; ) {
V_1 = F_5 () ;
if ( V_1 == - 1 ) {
if ( F_4 () - V_5 > V_4 )
return 0 ;
continue;
}
if ( V_1 == '\n' )
break;
if ( V_1 != '\r' && V_7 < & line [ sizeof( line ) - 1 ] )
* V_7 ++ = V_1 ;
}
* V_7 = 0 ;
} while ( strstr ( line , V_3 ) == NULL );
return 1 ;
}
int F_6 ( void )
{
int V_1 ;
if ( V_8 == 0 ) {
V_7 = line ;
for (; ; ) {
V_1 = F_7 () ;
if ( V_1 == - 1 || V_1 == 4 )
break;
if ( V_1 == '\r' || V_1 == '\n' ) {
* V_7 ++ = '\n' ;
F_1 ( '\n' ) ;
break;
}
switch ( V_1 ) {
case 0177 :
case '\b' :
if ( V_7 > line ) {
F_1 ( '\b' ) ;
F_1 ( ' ' ) ;
F_1 ( '\b' ) ;
-- V_7 ;
}
break;
case 'U' & 0x1F :
while ( V_7 > line ) {
F_1 ( '\b' ) ;
F_1 ( ' ' ) ;
F_1 ( '\b' ) ;
-- V_7 ;
}
break;
default:
if ( V_7 >= & line [ sizeof( line ) - 1 ] )
F_1 ( '\a' ) ;
else {
F_1 ( V_1 ) ;
* V_7 ++ = V_1 ;
}
}
}
V_8 = V_7 - line ;
V_7 = line ;
}
if ( V_8 == 0 )
return - 1 ;
-- V_8 ;
return * V_7 ++ ;
}
char * F_8 ( char * V_3 , int V_9 )
{
char * V_10 ;
int V_1 ;
for ( V_10 = V_3 ; V_10 < V_3 + V_9 - 1 ; ) {
V_1 = F_6 () ;
if ( V_1 == - 1 ) {
if ( V_10 == V_3 )
return NULL ;
break;
}
* V_10 ++ = V_1 ;
if ( V_1 == '\n' )
break;
}
* V_10 = 0 ;
return V_3 ;
}
void F_9 ( const char * V_11 , ... )
{
T_1 args ;
int V_12 ;
static char V_13 [ 1024 ] ;
va_start ( args , V_11 ) ;
V_12 = vsnprintf ( V_13 , sizeof( V_13 ) , V_11 , args ) ;
va_end ( args ) ;
F_2 ( V_13 , V_12 ) ;
}
void F_10 ( const char * V_3 )
{
F_2 ( V_3 , strlen ( V_3 ) ) ;
}
