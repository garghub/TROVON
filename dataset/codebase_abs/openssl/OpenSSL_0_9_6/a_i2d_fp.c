int F_1 ( int (* F_2)() , T_1 * V_1 , unsigned char * V_2 )
{
T_2 * V_3 ;
int V_4 ;
if ( ( V_3 = F_3 ( F_4 () ) ) == NULL )
{
F_5 ( V_5 , V_6 ) ;
return ( 0 ) ;
}
F_6 ( V_3 , V_1 , V_7 ) ;
V_4 = F_7 ( F_2 , V_3 , V_2 ) ;
F_8 ( V_3 ) ;
return ( V_4 ) ;
}
int F_7 ( int (* F_2)() , T_2 * V_1 , unsigned char * V_2 )
{
char * V_3 ;
unsigned char * V_8 ;
int V_9 , V_10 = 0 , V_11 , V_4 = 1 ;
V_11 = F_2 ( V_2 , NULL ) ;
V_3 = ( char * ) F_9 ( V_11 ) ;
if ( V_3 == NULL )
{
F_5 ( V_12 , V_13 ) ;
return ( 0 ) ;
}
V_8 = ( unsigned char * ) V_3 ;
F_2 ( V_2 , & V_8 ) ;
for (; ; )
{
V_9 = F_10 ( V_1 , & ( V_3 [ V_10 ] ) , V_11 ) ;
if ( V_9 == V_11 ) break;
if ( V_9 <= 0 )
{
V_4 = 0 ;
break;
}
V_10 += V_9 ;
V_11 -= V_9 ;
}
F_11 ( V_3 ) ;
return ( V_4 ) ;
}
