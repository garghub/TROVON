int F_1 ( const char * V_1 , long V_2 )
{
T_1 unsigned char V_3 [ V_4 ] ;
struct V_5 V_6 ;
int V_7 , V_8 = 0 , V_9 ;
T_2 * V_10 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_7 = V_5 ( V_1 , & V_6 ) ;
F_2 ( & V_6 , sizeof( V_6 ) , 0 ) ;
if ( V_7 < 0 ) return ( 0 ) ;
if ( V_2 == 0 ) return ( V_8 ) ;
V_10 = fopen ( V_1 , L_1 ) ;
if ( V_10 == NULL ) goto V_11;
for (; ; )
{
if ( V_2 > 0 )
V_9 = ( V_2 < V_4 ) ? ( int ) V_2 : V_4 ;
else
V_9 = V_4 ;
V_7 = fread ( V_3 , 1 , V_9 , V_10 ) ;
if ( V_7 <= 0 ) break;
F_2 ( V_3 , V_9 , V_7 ) ;
V_8 += V_7 ;
if ( V_2 > 0 )
{
V_2 -= V_9 ;
if ( V_2 == 0 ) break;
}
}
fclose ( V_10 ) ;
memset ( V_3 , 0 , V_4 ) ;
V_11:
return ( V_8 ) ;
}
int F_3 ( const char * V_1 )
{
unsigned char V_3 [ V_4 ] ;
int V_7 , V_8 = 0 , V_11 = 0 ;
T_2 * V_12 = NULL ;
int V_9 ;
#ifdef F_4
#if 0
out=fopen(file,"rb+");
if (out == NULL && errno != ENOENT)
goto err;
#endif
#endif
if ( V_12 == NULL )
{
#if V_13 V_14 && V_13 V_15
int V_16 = F_5 ( V_1 , V_14 | V_15 , 0600 ) ;
if ( V_16 != - 1 )
V_12 = fdopen ( V_16 , L_2 ) ;
#else
V_12 = fopen ( V_1 , L_2 ) ;
#endif
}
if ( V_12 == NULL ) goto V_11;
#ifndef F_6
F_7 ( V_1 , 0600 ) ;
#endif
V_9 = V_17 ;
for (; ; )
{
V_7 = ( V_9 > V_4 ) ? V_4 : V_9 ;
V_9 -= V_4 ;
if ( F_8 ( V_3 , V_7 ) <= 0 )
V_11 = 1 ;
V_7 = fwrite ( V_3 , 1 , V_7 , V_12 ) ;
if ( V_7 <= 0 )
{
V_8 = 0 ;
break;
}
V_8 += V_7 ;
if ( V_9 <= 0 ) break;
}
#ifdef F_4
#if 0
if (ret > 0)
ftruncate(fileno(out), ret);
#else
{
char * V_18 ;
V_18 = Malloc ( strlen ( V_1 ) + 4 ) ;
if ( V_18 )
{
strcpy ( V_18 , V_1 ) ;
strcat ( V_18 , L_3 ) ;
while( F_9 ( V_18 ) == 0 )
;
rename ( V_1 , L_4 ) ;
}
}
#endif
#endif
fclose ( V_12 ) ;
memset ( V_3 , 0 , V_4 ) ;
V_11:
return ( V_11 ? - 1 : V_8 ) ;
}
const char * F_10 ( char * V_3 , int V_19 )
{
char * V_20 ;
char * V_8 = NULL ;
V_20 = getenv ( L_5 ) ;
if ( V_20 != NULL )
{
strncpy ( V_3 , V_20 , V_19 - 1 ) ;
V_3 [ V_19 - 1 ] = '\0' ;
V_8 = V_3 ;
}
else
{
V_20 = getenv ( L_6 ) ;
if ( V_20 == NULL ) return ( V_21 ) ;
if ( ( ( int ) ( strlen ( V_20 ) + strlen ( V_21 ) + 2 ) ) > V_19 )
return ( V_21 ) ;
strcpy ( V_3 , V_20 ) ;
#ifndef F_4
strcat ( V_3 , L_7 ) ;
#endif
strcat ( V_3 , V_21 ) ;
V_8 = V_3 ;
}
return ( V_8 ) ;
}
