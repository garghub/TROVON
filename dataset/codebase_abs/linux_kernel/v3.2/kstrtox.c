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
unsigned int V_4 ;
int V_5 ;
* V_3 = 0 ;
V_4 = 0 ;
V_5 = 0 ;
while ( * V_1 ) {
unsigned int V_6 ;
if ( '0' <= * V_1 && * V_1 <= '9' )
V_6 = * V_1 - '0' ;
else if ( 'a' <= F_2 ( * V_1 ) && F_2 ( * V_1 ) <= 'f' )
V_6 = F_2 ( * V_1 ) - 'a' + 10 ;
else
break;
if ( V_6 >= V_2 )
break;
if ( * V_3 > F_4 ( V_7 - V_6 , V_2 ) )
V_5 = 1 ;
* V_3 = * V_3 * V_2 + V_6 ;
V_4 ++ ;
V_1 ++ ;
}
if ( V_5 )
V_4 |= V_8 ;
return V_4 ;
}
static int F_5 ( const char * V_1 , unsigned int V_2 , unsigned long long * V_3 )
{
unsigned long long V_9 ;
unsigned int V_4 ;
V_1 = F_1 ( V_1 , & V_2 ) ;
V_4 = F_3 ( V_1 , V_2 , & V_9 ) ;
if ( V_4 & V_8 )
return - V_10 ;
V_4 &= ~ V_8 ;
if ( V_4 == 0 )
return - V_11 ;
V_1 += V_4 ;
if ( * V_1 == '\n' )
V_1 ++ ;
if ( * V_1 )
return - V_11 ;
* V_3 = V_9 ;
return 0 ;
}
int F_6 ( const char * V_1 , unsigned int V_2 , unsigned long long * V_3 )
{
if ( V_1 [ 0 ] == '+' )
V_1 ++ ;
return F_5 ( V_1 , V_2 , V_3 ) ;
}
int F_7 ( const char * V_1 , unsigned int V_2 , long long * V_3 )
{
unsigned long long V_12 ;
int V_4 ;
if ( V_1 [ 0 ] == '-' ) {
V_4 = F_5 ( V_1 + 1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( long long ) ( - V_12 ) >= 0 )
return - V_10 ;
* V_3 = - V_12 ;
} else {
V_4 = F_6 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( long long ) V_12 < 0 )
return - V_10 ;
* V_3 = V_12 ;
}
return 0 ;
}
int F_8 ( const char * V_1 , unsigned int V_2 , unsigned long * V_3 )
{
unsigned long long V_12 ;
int V_4 ;
V_4 = F_6 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( unsigned long long ) ( unsigned long ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
int F_9 ( const char * V_1 , unsigned int V_2 , long * V_3 )
{
long long V_12 ;
int V_4 ;
V_4 = F_7 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( long long ) ( long ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
int F_10 ( const char * V_1 , unsigned int V_2 , unsigned int * V_3 )
{
unsigned long long V_12 ;
int V_4 ;
V_4 = F_6 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( unsigned long long ) ( unsigned int ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
int F_11 ( const char * V_1 , unsigned int V_2 , int * V_3 )
{
long long V_12 ;
int V_4 ;
V_4 = F_7 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( long long ) ( int ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
int F_12 ( const char * V_1 , unsigned int V_2 , T_1 * V_3 )
{
unsigned long long V_12 ;
int V_4 ;
V_4 = F_6 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( unsigned long long ) ( T_1 ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
int F_13 ( const char * V_1 , unsigned int V_2 , T_2 * V_3 )
{
long long V_12 ;
int V_4 ;
V_4 = F_7 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( long long ) ( T_2 ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
int F_14 ( const char * V_1 , unsigned int V_2 , T_3 * V_3 )
{
unsigned long long V_12 ;
int V_4 ;
V_4 = F_6 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( unsigned long long ) ( T_3 ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
int F_15 ( const char * V_1 , unsigned int V_2 , T_4 * V_3 )
{
long long V_12 ;
int V_4 ;
V_4 = F_7 ( V_1 , V_2 , & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_12 != ( long long ) ( T_4 ) V_12 )
return - V_10 ;
* V_3 = V_12 ;
return 0 ;
}
