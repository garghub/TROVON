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
int V_6 ;
V_4 = 0 ;
V_5 = 0 ;
V_6 = 0 ;
while ( * V_1 ) {
unsigned int V_7 ;
if ( '0' <= * V_1 && * V_1 <= '9' )
V_7 = * V_1 - '0' ;
else if ( 'a' <= F_2 ( * V_1 ) && F_2 ( * V_1 ) <= 'f' )
V_7 = F_2 ( * V_1 ) - 'a' + 10 ;
else
break;
if ( V_7 >= V_2 )
break;
if ( F_4 ( V_4 & ( ~ 0ull << 60 ) ) ) {
if ( V_4 > F_5 ( V_8 - V_7 , V_2 ) )
V_6 = 1 ;
}
V_4 = V_4 * V_2 + V_7 ;
V_5 ++ ;
V_1 ++ ;
}
* V_3 = V_4 ;
if ( V_6 )
V_5 |= V_9 ;
return V_5 ;
}
static int F_6 ( const char * V_1 , unsigned int V_2 , unsigned long long * V_4 )
{
unsigned long long V_10 ;
unsigned int V_5 ;
V_1 = F_1 ( V_1 , & V_2 ) ;
V_5 = F_3 ( V_1 , V_2 , & V_10 ) ;
if ( V_5 & V_9 )
return - V_11 ;
if ( V_5 == 0 )
return - V_12 ;
V_1 += V_5 ;
if ( * V_1 == '\n' )
V_1 ++ ;
if ( * V_1 )
return - V_12 ;
* V_4 = V_10 ;
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
unsigned long long V_13 ;
int V_5 ;
if ( V_1 [ 0 ] == '-' ) {
V_5 = F_6 ( V_1 + 1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( long long ) - V_13 > 0 )
return - V_11 ;
* V_4 = - V_13 ;
} else {
V_5 = F_7 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( long long ) V_13 < 0 )
return - V_11 ;
* V_4 = V_13 ;
}
return 0 ;
}
int F_9 ( const char * V_1 , unsigned int V_2 , unsigned long * V_4 )
{
unsigned long long V_13 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( unsigned long long ) ( unsigned long ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
int F_10 ( const char * V_1 , unsigned int V_2 , long * V_4 )
{
long long V_13 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( long long ) ( long ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
int F_11 ( const char * V_1 , unsigned int V_2 , unsigned int * V_4 )
{
unsigned long long V_13 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( unsigned long long ) ( unsigned int ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
int F_12 ( const char * V_1 , unsigned int V_2 , int * V_4 )
{
long long V_13 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( long long ) ( int ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
int F_13 ( const char * V_1 , unsigned int V_2 , T_1 * V_4 )
{
unsigned long long V_13 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( unsigned long long ) ( T_1 ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
int F_14 ( const char * V_1 , unsigned int V_2 , T_2 * V_4 )
{
long long V_13 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( long long ) ( T_2 ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
int F_15 ( const char * V_1 , unsigned int V_2 , T_3 * V_4 )
{
unsigned long long V_13 ;
int V_5 ;
V_5 = F_7 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( unsigned long long ) ( T_3 ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
int F_16 ( const char * V_1 , unsigned int V_2 , T_4 * V_4 )
{
long long V_13 ;
int V_5 ;
V_5 = F_8 ( V_1 , V_2 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 != ( long long ) ( T_4 ) V_13 )
return - V_11 ;
* V_4 = V_13 ;
return 0 ;
}
