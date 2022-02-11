void F_1 ( void )
{
V_1 = true ;
V_2 = false ;
V_3 = 0 ;
}
void F_2 ( void )
{
V_1 = false ;
}
void F_3 ( unsigned long V_4 )
{
V_5 = V_4 ;
}
static int F_4 ( void )
{
if ( V_6 )
return V_6 () ;
return - 1 ;
}
static int F_5 ( const char * V_7 , int V_8 )
{
int V_9 = 0 ;
const char * V_10 = V_7 , * V_11 ;
const char V_12 [] = L_1 ;
if ( V_8 <= 0 )
return V_9 ;
if ( V_1 && V_2 )
return V_8 ;
if ( V_5 ) {
while ( V_1 && ( V_11 = strchr ( V_10 , '\n' ) ) ) {
V_9 += F_6 ( V_10 , V_11 - V_10 + 1 ) ;
V_10 = V_11 + 1 ;
V_3 ++ ;
if ( V_3 >= V_5 ) {
F_6 ( V_12 , strlen ( V_12 ) ) ;
switch ( F_4 () ) {
case 'a' :
V_1 = false ;
break;
case 'q' :
V_2 = true ;
break;
default:
break;
}
V_3 = 0 ;
F_6 ( L_2 , 2 ) ;
if ( V_2 )
return V_8 ;
}
}
}
return V_9 + F_6 ( V_10 , V_8 - ( V_10 - V_7 ) ) ;
}
int F_7 ( int V_13 )
{
char V_14 = V_13 ;
if ( V_13 == '\n' )
F_7 ( '\r' ) ;
return F_5 ( & V_14 , 1 ) == 1 ? V_13 : - 1 ;
}
static int F_8 ( void )
{
int V_13 ;
if ( V_15 == 0 ) {
V_16 = line ;
for (; ; ) {
V_13 = F_4 () ;
if ( V_13 == - 1 || V_13 == 4 )
break;
if ( V_13 == '\r' || V_13 == '\n' ) {
* V_16 ++ = '\n' ;
F_7 ( '\n' ) ;
break;
}
switch ( V_13 ) {
case 0177 :
case '\b' :
if ( V_16 > line ) {
F_7 ( '\b' ) ;
F_7 ( ' ' ) ;
F_7 ( '\b' ) ;
-- V_16 ;
}
break;
case 'U' & 0x1F :
while ( V_16 > line ) {
F_7 ( '\b' ) ;
F_7 ( ' ' ) ;
F_7 ( '\b' ) ;
-- V_16 ;
}
break;
default:
if ( V_16 >= & line [ sizeof( line ) - 1 ] )
F_7 ( '\a' ) ;
else {
F_7 ( V_13 ) ;
* V_16 ++ = V_13 ;
}
}
}
V_15 = V_16 - line ;
V_16 = line ;
}
if ( V_15 == 0 )
return - 1 ;
-- V_15 ;
return * V_16 ++ ;
}
char * F_9 ( char * V_17 , int V_8 )
{
char * V_10 ;
int V_13 ;
for ( V_10 = V_17 ; V_10 < V_17 + V_8 - 1 ; ) {
V_13 = F_8 () ;
if ( V_13 == - 1 ) {
if ( V_10 == V_17 )
return NULL ;
break;
}
* V_10 ++ = V_13 ;
if ( V_13 == '\n' )
break;
}
* V_10 = 0 ;
return V_17 ;
}
void F_10 ( const char * V_18 , ... )
{
T_1 args ;
static char V_19 [ 1024 ] ;
int V_20 , V_21 ;
va_start ( args , V_18 ) ;
V_21 = vsnprintf ( V_19 , sizeof( V_19 ) , V_18 , args ) ;
va_end ( args ) ;
V_20 = F_5 ( V_19 , V_21 ) ;
if ( V_21 && V_20 == 0 ) {
F_11 ( L_3 , V_19 ) ;
}
}
void F_12 ( const char * V_17 )
{
F_5 ( V_17 , strlen ( V_17 ) ) ;
}
