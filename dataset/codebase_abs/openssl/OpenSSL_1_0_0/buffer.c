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
char * F_10 ( const char * V_8 )
{
if ( V_8 == NULL ) return ( NULL ) ;
return F_11 ( V_8 , strlen ( V_8 ) ) ;
}
char * F_11 ( const char * V_8 , T_2 V_13 )
{
char * V_1 ;
if ( V_8 == NULL ) return ( NULL ) ;
V_1 = F_2 ( V_13 + 1 ) ;
if ( V_1 == NULL )
{
F_3 ( V_14 , V_3 ) ;
return ( NULL ) ;
}
F_12 ( V_1 , V_8 , V_13 + 1 ) ;
return ( V_1 ) ;
}
void * F_13 ( const void * V_6 , T_2 V_13 )
{
void * V_1 ;
if ( V_6 == NULL ) return ( NULL ) ;
V_1 = F_2 ( V_13 ) ;
if ( V_1 == NULL )
{
F_3 ( V_15 , V_3 ) ;
return ( NULL ) ;
}
return memcpy ( V_1 , V_6 , V_13 ) ;
}
T_2 F_12 ( char * V_16 , const char * V_17 , T_2 V_18 )
{
T_2 V_19 = 0 ;
for(; V_18 > 1 && * V_17 ; V_18 -- )
{
* V_16 ++ = * V_17 ++ ;
V_19 ++ ;
}
if ( V_18 )
* V_16 = '\0' ;
return V_19 + strlen ( V_17 ) ;
}
T_2 F_14 ( char * V_16 , const char * V_17 , T_2 V_18 )
{
T_2 V_19 = 0 ;
for(; V_18 > 0 && * V_16 ; V_18 -- , V_16 ++ )
V_19 ++ ;
return V_19 + F_12 ( V_16 , V_17 , V_18 ) ;
}
void F_15 ( unsigned char * V_20 , unsigned char * V_21 , T_2 V_18 )
{
T_2 V_22 ;
if ( V_21 )
{
V_20 += V_18 - 1 ;
for ( V_22 = 0 ; V_22 < V_18 ; V_22 ++ )
* V_21 ++ = * V_20 -- ;
}
else
{
unsigned char * V_23 ;
char V_24 ;
V_23 = V_20 + V_18 - 1 ;
for ( V_22 = 0 ; V_22 < V_18 / 2 ; V_22 ++ )
{
V_24 = * V_23 ;
* V_23 -- = * V_20 ;
* V_20 ++ = V_24 ;
}
}
}
