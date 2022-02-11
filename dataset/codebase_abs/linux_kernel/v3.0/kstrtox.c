static inline char F_1 ( const char V_1 )
{
return V_1 | 0x20 ;
}
static int F_2 ( const char * V_2 , unsigned int V_3 , unsigned long long * V_4 )
{
unsigned long long V_5 ;
int V_6 ;
if ( V_3 == 0 ) {
if ( V_2 [ 0 ] == '0' ) {
if ( F_1 ( V_2 [ 1 ] ) == 'x' && isxdigit ( V_2 [ 2 ] ) )
V_3 = 16 ;
else
V_3 = 8 ;
} else
V_3 = 10 ;
}
if ( V_3 == 16 && V_2 [ 0 ] == '0' && F_1 ( V_2 [ 1 ] ) == 'x' )
V_2 += 2 ;
V_5 = 0 ;
V_6 = 0 ;
while ( * V_2 ) {
unsigned int V_7 ;
if ( '0' <= * V_2 && * V_2 <= '9' )
V_7 = * V_2 - '0' ;
else if ( 'a' <= F_1 ( * V_2 ) && F_1 ( * V_2 ) <= 'f' )
V_7 = F_1 ( * V_2 ) - 'a' + 10 ;
else if ( * V_2 == '\n' && * ( V_2 + 1 ) == '\0' )
break;
else
return - V_8 ;
if ( V_7 >= V_3 )
return - V_8 ;
if ( V_5 > F_3 ( V_9 - V_7 , V_3 ) )
return - V_10 ;
V_5 = V_5 * V_3 + V_7 ;
V_6 = 1 ;
V_2 ++ ;
}
if ( ! V_6 )
return - V_8 ;
* V_4 = V_5 ;
return 0 ;
}
int F_4 ( const char * V_2 , unsigned int V_3 , unsigned long long * V_4 )
{
if ( V_2 [ 0 ] == '+' )
V_2 ++ ;
return F_2 ( V_2 , V_3 , V_4 ) ;
}
int F_5 ( const char * V_2 , unsigned int V_3 , long long * V_4 )
{
unsigned long long V_11 ;
int V_12 ;
if ( V_2 [ 0 ] == '-' ) {
V_12 = F_2 ( V_2 + 1 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( long long ) ( - V_11 ) >= 0 )
return - V_10 ;
* V_4 = - V_11 ;
} else {
V_12 = F_4 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( long long ) V_11 < 0 )
return - V_10 ;
* V_4 = V_11 ;
}
return 0 ;
}
int F_6 ( const char * V_2 , unsigned int V_3 , unsigned long * V_4 )
{
unsigned long long V_11 ;
int V_12 ;
V_12 = F_4 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( unsigned long long ) ( unsigned long ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
int F_7 ( const char * V_2 , unsigned int V_3 , long * V_4 )
{
long long V_11 ;
int V_12 ;
V_12 = F_5 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( long long ) ( long ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
int F_8 ( const char * V_2 , unsigned int V_3 , unsigned int * V_4 )
{
unsigned long long V_11 ;
int V_12 ;
V_12 = F_4 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( unsigned long long ) ( unsigned int ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
int F_9 ( const char * V_2 , unsigned int V_3 , int * V_4 )
{
long long V_11 ;
int V_12 ;
V_12 = F_5 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( long long ) ( int ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
int F_10 ( const char * V_2 , unsigned int V_3 , T_1 * V_4 )
{
unsigned long long V_11 ;
int V_12 ;
V_12 = F_4 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( unsigned long long ) ( T_1 ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
int F_11 ( const char * V_2 , unsigned int V_3 , T_2 * V_4 )
{
long long V_11 ;
int V_12 ;
V_12 = F_5 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( long long ) ( T_2 ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
int F_12 ( const char * V_2 , unsigned int V_3 , T_3 * V_4 )
{
unsigned long long V_11 ;
int V_12 ;
V_12 = F_4 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( unsigned long long ) ( T_3 ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
int F_13 ( const char * V_2 , unsigned int V_3 , T_4 * V_4 )
{
long long V_11 ;
int V_12 ;
V_12 = F_5 ( V_2 , V_3 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != ( long long ) ( T_4 ) V_11 )
return - V_10 ;
* V_4 = V_11 ;
return 0 ;
}
