int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
unsigned char * V_3 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_4 == NULL ) ) return ( 0 ) ;
if ( V_2 == NULL )
return ( F_2 ( 0 , V_1 -> V_5 , V_6 ) ) ;
V_3 = * V_2 ;
F_3 ( & V_3 , 0 , V_1 -> V_5 , V_6 , V_7 ) ;
memcpy ( V_3 , V_1 -> V_4 , V_1 -> V_5 ) ;
V_3 += V_1 -> V_5 ;
* V_2 = V_3 ;
return ( V_1 -> V_5 ) ;
}
int F_4 ( unsigned char * V_8 , int V_9 , const char * V_10 , int V_11 )
{
int V_12 , V_13 , V_14 = 0 , V_15 ;
char V_16 [ 24 ] ;
const char * V_3 ;
unsigned long V_17 ;
if ( V_11 == 0 )
return ( 0 ) ;
else if ( V_11 == - 1 )
V_11 = strlen ( V_10 ) ;
V_3 = V_10 ;
V_15 = * ( V_3 ++ ) ;
V_11 -- ;
if ( ( V_15 >= '0' ) && ( V_15 <= '2' ) )
{
V_13 = ( V_15 - '0' ) * 40 ;
}
else
{
F_5 ( V_18 , V_19 ) ;
goto V_20;
}
if ( V_11 <= 0 )
{
F_5 ( V_18 , V_21 ) ;
goto V_20;
}
V_15 = * ( V_3 ++ ) ;
V_11 -- ;
for (; ; )
{
if ( V_11 <= 0 ) break;
if ( ( V_15 != '.' ) && ( V_15 != ' ' ) )
{
F_5 ( V_18 , V_22 ) ;
goto V_20;
}
V_17 = 0 ;
for (; ; )
{
if ( V_11 <= 0 ) break;
V_11 -- ;
V_15 = * ( V_3 ++ ) ;
if ( ( V_15 == ' ' ) || ( V_15 == '.' ) )
break;
if ( ( V_15 < '0' ) || ( V_15 > '9' ) )
{
F_5 ( V_18 , V_23 ) ;
goto V_20;
}
V_17 = V_17 * 10L + ( long ) ( V_15 - '0' ) ;
}
if ( V_14 == 0 )
{
if ( ( V_13 < 2 ) && ( V_17 >= 40 ) )
{
F_5 ( V_18 , V_24 ) ;
goto V_20;
}
V_17 += ( long ) V_13 ;
}
V_12 = 0 ;
for (; ; )
{
V_16 [ V_12 ++ ] = ( unsigned char ) V_17 & 0x7f ;
V_17 >>= 7L ;
if ( V_17 == 0L ) break;
}
if ( V_8 != NULL )
{
if ( V_14 + V_12 > V_9 )
{
F_5 ( V_18 , V_25 ) ;
goto V_20;
}
while ( -- V_12 > 0 )
V_8 [ V_14 ++ ] = V_16 [ V_12 ] | 0x80 ;
V_8 [ V_14 ++ ] = V_16 [ 0 ] ;
}
else
V_14 += V_12 ;
}
return ( V_14 ) ;
V_20:
return ( 0 ) ;
}
int F_6 ( char * V_10 , int V_26 , T_1 * V_1 )
{
return F_7 ( V_10 , V_26 , V_1 , 0 ) ;
}
int F_8 ( T_2 * V_27 , T_1 * V_1 )
{
char V_10 [ 80 ] ;
int V_12 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_4 == NULL ) )
return ( F_9 ( V_27 , L_1 , 4 ) ) ;
V_12 = F_6 ( V_10 , 80 , V_1 ) ;
if ( V_12 > 80 ) V_12 = 80 ;
F_9 ( V_27 , V_10 , V_12 ) ;
return ( V_12 ) ;
}
T_1 * F_10 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_5 )
{
T_1 * V_28 = NULL ;
unsigned char * V_3 ;
long V_14 ;
int V_29 , V_30 ;
int V_31 , V_12 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) ||
! ( ( * V_1 ) -> V_32 & V_33 ) )
{
if ( ( V_28 = F_11 () ) == NULL ) return ( NULL ) ;
}
else V_28 = ( * V_1 ) ;
V_3 = * V_2 ;
V_31 = F_12 ( & V_3 , & V_14 , & V_29 , & V_30 , V_5 ) ;
if ( V_31 & 0x80 )
{
V_12 = V_34 ;
goto V_20;
}
if ( V_29 != V_6 )
{
V_12 = V_35 ;
goto V_20;
}
if ( ( V_28 -> V_4 == NULL ) || ( V_28 -> V_5 < V_14 ) )
{
if ( V_28 -> V_4 != NULL ) Free ( ( char * ) V_28 -> V_4 ) ;
V_28 -> V_4 = ( unsigned char * ) Malloc ( ( int ) V_14 ) ;
V_28 -> V_32 |= V_36 ;
if ( V_28 -> V_4 == NULL )
{ V_12 = V_37 ; goto V_20; }
}
memcpy ( V_28 -> V_4 , V_3 , ( int ) V_14 ) ;
V_28 -> V_5 = ( int ) V_14 ;
V_28 -> V_38 = NULL ;
V_28 -> V_39 = NULL ;
V_3 += V_14 ;
if ( V_1 != NULL ) ( * V_1 ) = V_28 ;
* V_2 = V_3 ;
return ( V_28 ) ;
V_20:
F_5 ( V_40 , V_12 ) ;
if ( ( V_28 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_28 ) ) )
F_13 ( V_28 ) ;
return ( NULL ) ;
}
T_1 * F_11 ( void )
{
T_1 * V_28 ;
V_28 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_28 == NULL )
{
F_5 ( V_41 , V_37 ) ;
return ( NULL ) ;
}
V_28 -> V_5 = 0 ;
V_28 -> V_4 = NULL ;
V_28 -> V_42 = 0 ;
V_28 -> V_38 = NULL ;
V_28 -> V_39 = NULL ;
V_28 -> V_32 = V_33 ;
return ( V_28 ) ;
}
void F_13 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
if ( V_1 -> V_32 & V_43 )
{
#ifndef F_14
if ( V_1 -> V_38 != NULL ) Free ( ( void * ) V_1 -> V_38 ) ;
if ( V_1 -> V_39 != NULL ) Free ( ( void * ) V_1 -> V_39 ) ;
#endif
V_1 -> V_38 = V_1 -> V_39 = NULL ;
}
if ( V_1 -> V_32 & V_36 )
{
if ( V_1 -> V_4 != NULL ) Free ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = 0 ;
}
if ( V_1 -> V_32 & V_33 )
Free ( V_1 ) ;
}
T_1 * F_15 ( int V_42 , unsigned char * V_4 , int V_14 ,
char * V_38 , char * V_39 )
{
T_1 V_44 ;
V_44 . V_38 = V_38 ;
V_44 . V_39 = V_39 ;
V_44 . V_4 = V_4 ;
V_44 . V_42 = V_42 ;
V_44 . V_5 = V_14 ;
V_44 . V_32 = V_33 | V_43 |
V_36 ;
return ( F_16 ( & V_44 ) ) ;
}
