int F_1 ( const char * V_1 , long V_2 )
{
T_1 unsigned char V_3 [ V_4 ] ;
struct V_5 V_6 ;
int V_7 , V_8 = 0 , V_9 ;
T_2 * V_10 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_7 = V_5 ( V_1 , & V_6 ) ;
F_2 ( & V_6 , sizeof( V_6 ) , 0.0 ) ;
if ( V_7 < 0 ) return ( 0 ) ;
if ( V_2 == 0 ) return ( V_8 ) ;
V_10 = fopen ( V_1 , L_1 ) ;
if ( V_10 == NULL ) goto V_11;
#if F_3 ( V_12 ) && F_3 ( V_13 )
if ( V_6 . V_14 & ( V_12 | V_13 ) ) {
V_2 = ( V_2 == - 1 ) ? 2048 : V_2 ;
setvbuf ( V_10 , NULL , V_15 , 0 ) ;
}
#endif
for (; ; )
{
if ( V_2 > 0 )
V_9 = ( V_2 < V_4 ) ? ( int ) V_2 : V_4 ;
else
V_9 = V_4 ;
V_7 = fread ( V_3 , 1 , V_9 , V_10 ) ;
if ( V_7 <= 0 ) break;
F_2 ( V_3 , V_9 , ( double ) V_7 ) ;
V_8 += V_7 ;
if ( V_2 > 0 )
{
V_2 -= V_9 ;
if ( V_2 <= 0 ) break;
}
}
fclose ( V_10 ) ;
F_4 ( V_3 , V_4 ) ;
V_11:
return ( V_8 ) ;
}
int F_5 ( const char * V_1 )
{
unsigned char V_3 [ V_4 ] ;
int V_7 , V_8 = 0 , V_16 = 0 ;
T_2 * V_17 = NULL ;
int V_9 ;
struct V_5 V_6 ;
V_7 = V_5 ( V_1 , & V_6 ) ;
if ( V_7 != - 1 ) {
#if F_3 ( V_12 ) && F_3 ( V_13 )
if ( V_6 . V_14 & ( V_12 | V_13 ) ) {
return ( 1 ) ;
}
#endif
}
#if F_3 ( V_18 ) && ! F_3 ( V_19 )
{
int V_20 = F_6 ( V_1 , V_18 , 0600 ) ;
if ( V_20 != - 1 )
V_17 = fdopen ( V_20 , L_2 ) ;
}
#endif
if ( V_17 == NULL )
V_17 = fopen ( V_1 , L_2 ) ;
if ( V_17 == NULL ) goto V_11;
#ifndef F_7
F_8 ( V_1 , 0600 ) ;
#endif
V_9 = V_21 ;
for (; ; )
{
V_7 = ( V_9 > V_4 ) ? V_4 : V_9 ;
V_9 -= V_4 ;
if ( F_9 ( V_3 , V_7 ) <= 0 )
V_16 = 1 ;
V_7 = fwrite ( V_3 , 1 , V_7 , V_17 ) ;
if ( V_7 <= 0 )
{
V_8 = 0 ;
break;
}
V_8 += V_7 ;
if ( V_9 <= 0 ) break;
}
#ifdef F_10
{
char * V_22 ;
V_22 = F_11 ( strlen ( V_1 ) + 4 ) ;
if ( V_22 )
{
strcpy ( V_22 , V_1 ) ;
strcat ( V_22 , L_3 ) ;
while( F_12 ( V_22 ) == 0 )
;
rename ( V_1 , L_4 ) ;
}
}
#endif
fclose ( V_17 ) ;
F_4 ( V_3 , V_4 ) ;
V_11:
return ( V_16 ? - 1 : V_8 ) ;
}
const char * F_13 ( char * V_3 , T_3 V_23 )
{
char * V_24 = NULL ;
int V_25 = 0 ;
#ifdef F_14
struct V_5 V_6 ;
#endif
if ( F_15 () == 0 )
V_24 = getenv ( L_5 ) ;
if ( V_24 != NULL && * V_24 && strlen ( V_24 ) + 1 < V_23 )
{
if ( F_16 ( V_3 , V_24 , V_23 ) >= V_23 )
return NULL ;
}
else
{
if ( F_15 () == 0 )
V_24 = getenv ( L_6 ) ;
#ifdef F_17
if ( V_24 == NULL )
{
V_24 = F_17 ;
}
#endif
if ( V_24 && * V_24 && strlen ( V_24 ) + strlen ( V_26 ) + 2 < V_23 )
{
F_16 ( V_3 , V_24 , V_23 ) ;
#ifndef F_10
F_18 ( V_3 , L_7 , V_23 ) ;
#endif
F_18 ( V_3 , V_26 , V_23 ) ;
V_25 = 1 ;
}
else
V_3 [ 0 ] = '\0' ;
}
#ifdef F_14
if ( ! V_25 )
if ( F_16 ( V_3 , L_8 , V_23 ) >= V_23 ) {
return ( NULL ) ;
}
if ( V_5 ( V_3 , & V_6 ) == - 1 )
if ( F_16 ( V_3 , L_8 , V_23 ) >= V_23 ) {
return ( NULL ) ;
}
#endif
return ( V_3 ) ;
}
