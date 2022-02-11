T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
{
F_3 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
V_1 -> V_4 = 0 ;
V_1 -> V_5 = 0 ;
V_1 -> V_6 = NULL ;
return ( V_1 ) ;
}
void F_4 ( T_1 * V_7 )
{
if( V_7 == NULL )
return;
if ( V_7 -> V_6 != NULL )
{
memset ( V_7 -> V_6 , 0 , ( unsigned int ) V_7 -> V_5 ) ;
F_5 ( V_7 -> V_6 ) ;
}
F_5 ( V_7 ) ;
}
int F_6 ( T_1 * V_8 , T_2 V_9 )
{
char * V_1 ;
T_2 V_10 ;
if ( V_8 -> V_4 >= V_9 )
{
V_8 -> V_4 = V_9 ;
return ( V_9 ) ;
}
if ( V_8 -> V_5 >= V_9 )
{
memset ( & V_8 -> V_6 [ V_8 -> V_4 ] , 0 , V_9 - V_8 -> V_4 ) ;
V_8 -> V_4 = V_9 ;
return ( V_9 ) ;
}
V_10 = ( V_9 + 3 ) / 3 * 4 ;
if ( V_8 -> V_6 == NULL )
V_1 = F_2 ( V_10 ) ;
else
V_1 = F_7 ( V_8 -> V_6 , V_10 ) ;
if ( V_1 == NULL )
{
F_3 ( V_11 , V_3 ) ;
V_9 = 0 ;
}
else
{
V_8 -> V_6 = V_1 ;
V_8 -> V_5 = V_10 ;
memset ( & V_8 -> V_6 [ V_8 -> V_4 ] , 0 , V_9 - V_8 -> V_4 ) ;
V_8 -> V_4 = V_9 ;
}
return ( V_9 ) ;
}
int F_8 ( T_1 * V_8 , T_2 V_9 )
{
char * V_1 ;
T_2 V_10 ;
if ( V_8 -> V_4 >= V_9 )
{
memset ( & V_8 -> V_6 [ V_9 ] , 0 , V_8 -> V_4 - V_9 ) ;
V_8 -> V_4 = V_9 ;
return ( V_9 ) ;
}
if ( V_8 -> V_5 >= V_9 )
{
memset ( & V_8 -> V_6 [ V_8 -> V_4 ] , 0 , V_9 - V_8 -> V_4 ) ;
V_8 -> V_4 = V_9 ;
return ( V_9 ) ;
}
V_10 = ( V_9 + 3 ) / 3 * 4 ;
if ( V_8 -> V_6 == NULL )
V_1 = F_2 ( V_10 ) ;
else
V_1 = F_9 ( V_8 -> V_6 , V_8 -> V_5 , V_10 ) ;
if ( V_1 == NULL )
{
F_3 ( V_12 , V_3 ) ;
V_9 = 0 ;
}
else
{
V_8 -> V_6 = V_1 ;
V_8 -> V_5 = V_10 ;
memset ( & V_8 -> V_6 [ V_8 -> V_4 ] , 0 , V_9 - V_8 -> V_4 ) ;
V_8 -> V_4 = V_9 ;
}
return ( V_9 ) ;
}
void F_10 ( unsigned char * V_13 , unsigned char * V_14 , T_2 V_15 )
{
T_2 V_16 ;
if ( V_14 )
{
V_13 += V_15 - 1 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
* V_14 ++ = * V_13 -- ;
}
else
{
unsigned char * V_17 ;
char V_18 ;
V_17 = V_13 + V_15 - 1 ;
for ( V_16 = 0 ; V_16 < V_15 / 2 ; V_16 ++ )
{
V_18 = * V_17 ;
* V_17 -- = * V_13 ;
* V_13 ++ = V_18 ;
}
}
}
