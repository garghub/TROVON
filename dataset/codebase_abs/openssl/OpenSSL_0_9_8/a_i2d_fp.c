int F_1 ( T_1 * V_1 , T_2 * V_2 , void * V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_6 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_2 , V_8 ) ;
V_5 = F_6 ( V_1 , V_4 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_6 ( T_1 * V_1 , T_3 * V_2 , unsigned char * V_3 )
{
char * V_4 ;
unsigned char * V_9 ;
int V_10 , V_11 = 0 , V_12 , V_5 = 1 ;
V_12 = V_1 ( V_3 , NULL ) ;
V_4 = ( char * ) F_8 ( V_12 ) ;
if ( V_4 == NULL )
{
F_4 ( V_13 , V_14 ) ;
return ( 0 ) ;
}
V_9 = ( unsigned char * ) V_4 ;
V_1 ( V_3 , & V_9 ) ;
for (; ; )
{
V_10 = F_9 ( V_2 , & ( V_4 [ V_11 ] ) , V_12 ) ;
if ( V_10 == V_12 ) break;
if ( V_10 <= 0 )
{
V_5 = 0 ;
break;
}
V_11 += V_10 ;
V_12 -= V_10 ;
}
F_10 ( V_4 ) ;
return ( V_5 ) ;
}
int F_11 ( const T_4 * V_15 , T_2 * V_2 , void * V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_16 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_2 , V_8 ) ;
V_5 = F_12 ( V_15 , V_4 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_12 ( const T_4 * V_15 , T_3 * V_2 , void * V_3 )
{
unsigned char * V_4 = NULL ;
int V_10 , V_11 = 0 , V_12 , V_5 = 1 ;
V_12 = F_13 ( V_3 , & V_4 , V_15 ) ;
if ( V_4 == NULL )
{
F_4 ( V_17 , V_14 ) ;
return ( 0 ) ;
}
for (; ; )
{
V_10 = F_9 ( V_2 , & ( V_4 [ V_11 ] ) , V_12 ) ;
if ( V_10 == V_12 ) break;
if ( V_10 <= 0 )
{
V_5 = 0 ;
break;
}
V_11 += V_10 ;
V_12 -= V_10 ;
}
F_10 ( V_4 ) ;
return ( V_5 ) ;
}
