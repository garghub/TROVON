int F_1 ( const char * V_1 , long V_2 )
{
T_1 unsigned char V_3 [ V_4 ] ;
struct V_5 V_6 ;
int V_7 , V_8 = 0 , V_9 ;
T_2 * V_10 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_7 = V_5 ( V_1 , & V_6 ) ;
F_2 ( & V_6 , sizeof( V_6 ) ) ;
V_8 += sizeof( V_6 ) ;
if ( V_7 < 0 ) return ( 0 ) ;
if ( V_2 <= 0 ) return ( V_8 ) ;
V_10 = fopen ( V_1 , L_1 ) ;
if ( V_10 == NULL ) goto V_11;
for (; ; )
{
V_9 = ( V_2 < V_4 ) ? ( int ) V_2 : V_4 ;
V_7 = fread ( V_3 , 1 , V_9 , V_10 ) ;
if ( V_7 <= 0 ) break;
F_2 ( V_3 , V_9 ) ;
V_8 += V_7 ;
V_2 -= V_9 ;
if ( V_2 <= 0 ) break;
}
fclose ( V_10 ) ;
memset ( V_3 , 0 , V_4 ) ;
V_11:
return ( V_8 ) ;
}
int F_3 ( const char * V_1 )
{
unsigned char V_3 [ V_4 ] ;
int V_7 , V_8 = 0 ;
T_2 * V_12 ;
int V_9 ;
V_12 = fopen ( V_1 , L_2 ) ;
if ( V_12 == NULL && V_13 == V_14 )
{
V_13 = 0 ;
V_12 = fopen ( V_1 , L_3 ) ;
}
if ( V_12 == NULL ) goto V_11;
F_4 ( V_1 , 0600 ) ;
V_9 = V_15 ;
for (; ; )
{
V_7 = ( V_9 > V_4 ) ? V_4 : V_9 ;
V_9 -= V_4 ;
F_5 ( V_3 , V_7 ) ;
V_7 = fwrite ( V_3 , 1 , V_7 , V_12 ) ;
if ( V_7 <= 0 )
{
V_8 = 0 ;
break;
}
V_8 += V_7 ;
if ( V_9 <= 0 ) break;
}
fclose ( V_12 ) ;
memset ( V_3 , 0 , V_4 ) ;
V_11:
return ( V_8 ) ;
}
char * F_6 ( char * V_3 , int V_16 )
{
char * V_17 ;
char * V_8 = NULL ;
V_17 = getenv ( L_4 ) ;
if ( V_17 != NULL )
{
strncpy ( V_3 , V_17 , V_16 - 1 ) ;
V_3 [ V_16 - 1 ] = '\0' ;
V_8 = V_3 ;
}
else
{
V_17 = getenv ( L_5 ) ;
if ( V_17 == NULL ) return ( V_18 ) ;
if ( ( ( int ) ( strlen ( V_17 ) + strlen ( V_18 ) + 2 ) ) > V_16 )
return ( V_18 ) ;
strcpy ( V_3 , V_17 ) ;
#ifndef F_7
strcat ( V_3 , L_6 ) ;
#endif
strcat ( V_3 , V_18 ) ;
V_8 = V_3 ;
}
return ( V_8 ) ;
}
