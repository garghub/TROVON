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
int V_12 , V_27 = 0 , V_28 = 0 , V_14 , V_29 ;
unsigned long V_17 ;
unsigned char * V_3 ;
const char * V_30 ;
char V_31 [ 32 ] ;
if ( V_26 <= 0 ) return ( 0 ) ;
if ( ( V_1 == NULL ) || ( V_1 -> V_4 == NULL ) )
{
V_10 [ 0 ] = '\0' ;
return ( 0 ) ;
}
V_29 = F_7 ( V_1 ) ;
if ( V_29 == V_32 )
{
V_14 = V_1 -> V_5 ;
V_3 = V_1 -> V_4 ;
V_27 = 0 ;
V_17 = 0 ;
while ( V_27 < V_1 -> V_5 )
{
V_17 |= ( V_3 [ V_27 ] & 0x7f ) ;
if ( ! ( V_3 [ V_27 ] & 0x80 ) ) break;
V_17 <<= 7L ;
V_27 ++ ;
}
V_27 ++ ;
V_12 = ( int ) ( V_17 / 40 ) ;
if ( V_12 > 2 ) V_12 = 2 ;
V_17 -= ( long ) ( V_12 * 40 ) ;
sprintf ( V_31 , L_1 , V_12 , V_17 ) ;
V_12 = strlen ( V_31 ) ;
strncpy ( V_10 , V_31 , V_26 ) ;
V_26 -= V_12 ;
V_10 += V_12 ;
V_28 += V_12 ;
V_17 = 0 ;
for (; V_27 < V_14 ; V_27 ++ )
{
V_17 |= V_3 [ V_27 ] & 0x7f ;
if ( ! ( V_3 [ V_27 ] & 0x80 ) )
{
sprintf ( V_31 , L_2 , V_17 ) ;
V_12 = strlen ( V_31 ) ;
if ( V_26 > 0 )
strncpy ( V_10 , V_31 , V_26 ) ;
V_26 -= V_12 ;
V_10 += V_12 ;
V_28 += V_12 ;
V_17 = 0 ;
}
V_17 <<= 7L ;
}
}
else
{
V_30 = F_8 ( V_29 ) ;
if ( V_30 == NULL )
V_30 = F_9 ( V_29 ) ;
strncpy ( V_10 , V_30 , V_26 ) ;
V_28 = strlen ( V_30 ) ;
}
V_10 [ V_26 - 1 ] = '\0' ;
return ( V_28 ) ;
}
int F_10 ( T_2 * V_33 , T_1 * V_1 )
{
char V_10 [ 80 ] ;
int V_12 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_4 == NULL ) )
return ( F_11 ( V_33 , L_3 , 4 ) ) ;
V_12 = F_6 ( V_10 , 80 , V_1 ) ;
if ( V_12 > 80 ) V_12 = 80 ;
F_11 ( V_33 , V_10 , V_12 ) ;
return ( V_12 ) ;
}
T_1 * F_12 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_5 )
{
T_1 * V_34 = NULL ;
unsigned char * V_3 ;
long V_14 ;
int V_35 , V_36 ;
int V_37 , V_12 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) ||
! ( ( * V_1 ) -> V_38 & V_39 ) )
{
if ( ( V_34 = F_13 () ) == NULL ) return ( NULL ) ;
}
else V_34 = ( * V_1 ) ;
V_3 = * V_2 ;
V_37 = F_14 ( & V_3 , & V_14 , & V_35 , & V_36 , V_5 ) ;
if ( V_37 & 0x80 )
{
V_12 = V_40 ;
goto V_20;
}
if ( V_35 != V_6 )
{
V_12 = V_41 ;
goto V_20;
}
if ( ( V_34 -> V_4 == NULL ) || ( V_34 -> V_5 < V_14 ) )
{
if ( V_34 -> V_4 != NULL ) Free ( ( char * ) V_34 -> V_4 ) ;
V_34 -> V_4 = ( unsigned char * ) Malloc ( ( int ) V_14 ) ;
V_34 -> V_38 |= V_42 ;
if ( V_34 -> V_4 == NULL )
{ V_12 = V_43 ; goto V_20; }
}
memcpy ( V_34 -> V_4 , V_3 , ( int ) V_14 ) ;
V_34 -> V_5 = ( int ) V_14 ;
V_34 -> V_44 = NULL ;
V_34 -> V_45 = NULL ;
V_3 += V_14 ;
if ( V_1 != NULL ) ( * V_1 ) = V_34 ;
* V_2 = V_3 ;
return ( V_34 ) ;
V_20:
F_5 ( V_46 , V_12 ) ;
if ( ( V_34 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_34 ) ) )
F_15 ( V_34 ) ;
return ( NULL ) ;
}
T_1 * F_13 ( void )
{
T_1 * V_34 ;
V_34 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_34 == NULL )
{
F_5 ( V_47 , V_43 ) ;
return ( NULL ) ;
}
V_34 -> V_5 = 0 ;
V_34 -> V_4 = NULL ;
V_34 -> V_29 = 0 ;
V_34 -> V_44 = NULL ;
V_34 -> V_45 = NULL ;
V_34 -> V_38 = V_39 ;
return ( V_34 ) ;
}
void F_15 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
if ( V_1 -> V_38 & V_48 )
{
#ifndef F_16
if ( V_1 -> V_44 != NULL ) Free ( ( void * ) V_1 -> V_44 ) ;
if ( V_1 -> V_45 != NULL ) Free ( ( void * ) V_1 -> V_45 ) ;
#endif
V_1 -> V_44 = V_1 -> V_45 = NULL ;
}
if ( V_1 -> V_38 & V_42 )
{
if ( V_1 -> V_4 != NULL ) Free ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = 0 ;
}
if ( V_1 -> V_38 & V_39 )
Free ( V_1 ) ;
}
T_1 * F_17 ( int V_29 , unsigned char * V_4 , int V_14 ,
char * V_44 , char * V_45 )
{
T_1 V_49 ;
V_49 . V_44 = V_44 ;
V_49 . V_45 = V_45 ;
V_49 . V_4 = V_4 ;
V_49 . V_29 = V_29 ;
V_49 . V_5 = V_14 ;
V_49 . V_38 = V_39 | V_48 |
V_42 ;
return ( F_18 ( & V_49 ) ) ;
}
