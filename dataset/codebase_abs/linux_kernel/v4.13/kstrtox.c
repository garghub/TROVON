const char * F_1 ( const char * V_1 , unsigned int * V_2 )
{
if ( * V_2 == 0 ) {
if ( V_1 [ 0 ] == '0' ) {
if ( F_2 ( V_1 [ 1 ] ) == 'x' && isxdigit ( V_1 [ 2 ] ) )
* V_2 = 16 ;
else
* V_2 = 8 ;
} else
* V_2 = 10 ;
}
if ( * V_2 == 16 && V_1 [ 0 ] == '0' && F_2 ( V_1 [ 1 ] ) == 'x' )
V_1 += 2 ;
return V_1 ;
}
unsigned int F_3 ( const char * V_1 , unsigned int V_2 , unsigned long long * V_3 )
{
unsigned long long V_4 ;
unsigned int V_5 ;
V_4 = 0 ;
V_5 = 0 ;
while ( 1 ) {
unsigned int V_6 = * V_1 ;
unsigned int V_7 = V_6 | 0x20 ;
unsigned int V_8 ;
if ( '0' <= V_6 && V_6 <= '9' )
V_8 = V_6 - '0' ;
else if ( 'a' <= V_7 && V_7 <= 'f' )
V_8 = V_7 - 'a' + 10 ;
else
break;
if ( V_8 >= V_2 )
break;
if ( F_4 ( V_4 & ( ~ 0ull << 60 ) ) ) {
if ( V_4 > F_5 ( V_9 - V_8 , V_2 ) )
V_5 |= V_10 ;
}
V_4 = V_4 * V_2 + V_8 ;
V_5 ++ ;
V_1 ++ ;
}
* V_3 = V_4 ;
return V_5 ;
}
static int F_6 ( const char * V_1 , unsigned int V_2 , unsigned long long * V_4 )
{
unsigned long long V_11 ;
unsigned int V_5 ;
V_1 = F_1 ( V_1 , & V_2 ) ;
V_5 = F_3 ( V_1 , V_2 , & V_11 ) ;
if ( V_5 & V_10 )
return - V_12 ;
if ( V_5 == 0 )
return - V_13 ;
V_1 += V_5 ;
if ( * V_1 == '\n' )
V_1 ++ ;
if ( * V_1 )
return - V_13 ;
* V_4 = V_11 ;
return 0 ;
}
int F_7 ( const char * V_1 , unsigned int V_2 , unsigned long long * V_4 )
{
if ( V_1 [ 0 ] == '+' )
V_1 ++ ;
return F_6 ( V_1 , V_2 , V_4 ) ;
}
int F_8 ( const char * V_1 , unsigned int V_2 , long long * V_4 )
{
unsigned long long V_14 ;
int V_5 ;
if ( V_1 [ 0 ] == '-' ) {
V_5 = F_6 ( V_1 + 1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( long long ) - V_14 > 0 )
return - V_12 ;
* V_4 = - V_14 ;
} else {
V_5 = F_7 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( long long ) V_14 < 0 )
return - V_12 ;
* V_4 = V_14 ;
}
return 0 ;
}
int F_9 ( const char * V_1 , unsigned int V_2 , unsigned long * V_4 )
{
unsigned long long V_14 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( unsigned long long ) ( unsigned long ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_10 ( const char * V_1 , unsigned int V_2 , long * V_4 )
{
long long V_14 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( long long ) ( long ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_11 ( const char * V_1 , unsigned int V_2 , unsigned int * V_4 )
{
unsigned long long V_14 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( unsigned long long ) ( unsigned int ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_12 ( const char * V_1 , unsigned int V_2 , int * V_4 )
{
long long V_14 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( long long ) ( int ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_13 ( const char * V_1 , unsigned int V_2 , T_1 * V_4 )
{
unsigned long long V_14 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( unsigned long long ) ( T_1 ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_14 ( const char * V_1 , unsigned int V_2 , T_2 * V_4 )
{
long long V_14 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( long long ) ( T_2 ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_15 ( const char * V_1 , unsigned int V_2 , T_3 * V_4 )
{
unsigned long long V_14 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( unsigned long long ) ( T_3 ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_16 ( const char * V_1 , unsigned int V_2 , T_4 * V_4 )
{
long long V_14 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_14 != ( long long ) ( T_4 ) V_14 )
return - V_12 ;
* V_4 = V_14 ;
return 0 ;
}
int F_17 ( const char * V_1 , bool * V_4 )
{
if ( ! V_1 )
return - V_13 ;
switch ( V_1 [ 0 ] ) {
case 'y' :
case 'Y' :
case '1' :
* V_4 = true ;
return 0 ;
case 'n' :
case 'N' :
case '0' :
* V_4 = false ;
return 0 ;
case 'o' :
case 'O' :
switch ( V_1 [ 1 ] ) {
case 'n' :
case 'N' :
* V_4 = true ;
return 0 ;
case 'f' :
case 'F' :
* V_4 = false ;
return 0 ;
default:
break;
}
default:
break;
}
return - V_13 ;
}
int F_18 ( const char T_5 * V_1 , T_6 V_15 , bool * V_4 )
{
char V_16 [ 4 ] ;
V_15 = F_19 ( V_15 , sizeof( V_16 ) - 1 ) ;
if ( F_20 ( V_16 , V_1 , V_15 ) )
return - V_17 ;
V_16 [ V_15 ] = '\0' ;
return F_17 ( V_16 , V_4 ) ;
}
