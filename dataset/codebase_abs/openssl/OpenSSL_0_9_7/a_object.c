int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
unsigned char * V_3 ;
int V_4 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_5 == NULL ) ) return ( 0 ) ;
V_4 = F_2 ( 0 , V_1 -> V_6 , V_7 ) ;
if ( V_2 == NULL ) return V_4 ;
V_3 = * V_2 ;
F_3 ( & V_3 , 0 , V_1 -> V_6 , V_7 , V_8 ) ;
memcpy ( V_3 , V_1 -> V_5 , V_1 -> V_6 ) ;
V_3 += V_1 -> V_6 ;
* V_2 = V_3 ;
return ( V_4 ) ;
}
int F_4 ( unsigned char * V_9 , int V_10 , const char * V_11 , int V_12 )
{
int V_13 , V_14 , V_15 = 0 , V_16 ;
char V_17 [ 24 ] ;
const char * V_3 ;
unsigned long V_18 ;
if ( V_12 == 0 )
return ( 0 ) ;
else if ( V_12 == - 1 )
V_12 = strlen ( V_11 ) ;
V_3 = V_11 ;
V_16 = * ( V_3 ++ ) ;
V_12 -- ;
if ( ( V_16 >= '0' ) && ( V_16 <= '2' ) )
{
V_14 = ( V_16 - '0' ) * 40 ;
}
else
{
F_5 ( V_19 , V_20 ) ;
goto V_21;
}
if ( V_12 <= 0 )
{
F_5 ( V_19 , V_22 ) ;
goto V_21;
}
V_16 = * ( V_3 ++ ) ;
V_12 -- ;
for (; ; )
{
if ( V_12 <= 0 ) break;
if ( ( V_16 != '.' ) && ( V_16 != ' ' ) )
{
F_5 ( V_19 , V_23 ) ;
goto V_21;
}
V_18 = 0 ;
for (; ; )
{
if ( V_12 <= 0 ) break;
V_12 -- ;
V_16 = * ( V_3 ++ ) ;
if ( ( V_16 == ' ' ) || ( V_16 == '.' ) )
break;
if ( ( V_16 < '0' ) || ( V_16 > '9' ) )
{
F_5 ( V_19 , V_24 ) ;
goto V_21;
}
V_18 = V_18 * 10L + ( long ) ( V_16 - '0' ) ;
}
if ( V_15 == 0 )
{
if ( ( V_14 < 2 ) && ( V_18 >= 40 ) )
{
F_5 ( V_19 , V_25 ) ;
goto V_21;
}
V_18 += ( long ) V_14 ;
}
V_13 = 0 ;
for (; ; )
{
V_17 [ V_13 ++ ] = ( unsigned char ) V_18 & 0x7f ;
V_18 >>= 7L ;
if ( V_18 == 0L ) break;
}
if ( V_9 != NULL )
{
if ( V_15 + V_13 > V_10 )
{
F_5 ( V_19 , V_26 ) ;
goto V_21;
}
while ( -- V_13 > 0 )
V_9 [ V_15 ++ ] = V_17 [ V_13 ] | 0x80 ;
V_9 [ V_15 ++ ] = V_17 [ 0 ] ;
}
else
V_15 += V_13 ;
}
return ( V_15 ) ;
V_21:
return ( 0 ) ;
}
int F_6 ( char * V_11 , int V_27 , T_1 * V_1 )
{
return F_7 ( V_11 , V_27 , V_1 , 0 ) ;
}
int F_8 ( T_2 * V_28 , T_1 * V_1 )
{
char V_11 [ 80 ] ;
int V_13 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_5 == NULL ) )
return ( F_9 ( V_28 , L_1 , 4 ) ) ;
V_13 = F_6 ( V_11 , sizeof V_11 , V_1 ) ;
if ( V_13 > sizeof V_11 ) V_13 = sizeof V_11 ;
F_9 ( V_28 , V_11 , V_13 ) ;
return ( V_13 ) ;
}
T_1 * F_10 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_6 )
{
unsigned char * V_3 ;
long V_15 ;
int V_29 , V_30 ;
int V_31 , V_13 ;
T_1 * V_32 = NULL ;
V_3 = * V_2 ;
V_31 = F_11 ( & V_3 , & V_15 , & V_29 , & V_30 , V_6 ) ;
if ( V_31 & 0x80 )
{
V_13 = V_33 ;
goto V_21;
}
if ( V_29 != V_7 )
{
V_13 = V_34 ;
goto V_21;
}
V_32 = F_12 ( V_1 , & V_3 , V_15 ) ;
if( V_32 ) * V_2 = V_3 ;
return V_32 ;
V_21:
F_5 ( V_35 , V_13 ) ;
if ( ( V_32 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_32 ) ) )
F_13 ( V_32 ) ;
return ( NULL ) ;
}
T_1 * F_12 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_15 )
{
T_1 * V_32 = NULL ;
unsigned char * V_3 ;
int V_13 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) ||
! ( ( * V_1 ) -> V_36 & V_37 ) )
{
if ( ( V_32 = F_14 () ) == NULL ) return ( NULL ) ;
}
else V_32 = ( * V_1 ) ;
V_3 = * V_2 ;
if ( ( V_32 -> V_5 == NULL ) || ( V_32 -> V_6 < V_15 ) )
{
if ( V_32 -> V_5 != NULL ) F_15 ( V_32 -> V_5 ) ;
V_32 -> V_5 = ( unsigned char * ) F_16 ( V_15 ? ( int ) V_15 : 1 ) ;
V_32 -> V_36 |= V_38 ;
if ( V_32 -> V_5 == NULL )
{ V_13 = V_39 ; goto V_21; }
}
memcpy ( V_32 -> V_5 , V_3 , ( int ) V_15 ) ;
V_32 -> V_6 = ( int ) V_15 ;
V_32 -> V_40 = NULL ;
V_32 -> V_41 = NULL ;
V_3 += V_15 ;
if ( V_1 != NULL ) ( * V_1 ) = V_32 ;
* V_2 = V_3 ;
return ( V_32 ) ;
V_21:
F_5 ( V_35 , V_13 ) ;
if ( ( V_32 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_32 ) ) )
F_13 ( V_32 ) ;
return ( NULL ) ;
}
T_1 * F_14 ( void )
{
T_1 * V_32 ;
V_32 = ( T_1 * ) F_16 ( sizeof( T_1 ) ) ;
if ( V_32 == NULL )
{
F_5 ( V_42 , V_39 ) ;
return ( NULL ) ;
}
V_32 -> V_6 = 0 ;
V_32 -> V_5 = NULL ;
V_32 -> V_43 = 0 ;
V_32 -> V_40 = NULL ;
V_32 -> V_41 = NULL ;
V_32 -> V_36 = V_37 ;
return ( V_32 ) ;
}
void F_13 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
if ( V_1 -> V_36 & V_44 )
{
#ifndef F_17
if ( V_1 -> V_40 != NULL ) F_15 ( ( void * ) V_1 -> V_40 ) ;
if ( V_1 -> V_41 != NULL ) F_15 ( ( void * ) V_1 -> V_41 ) ;
#endif
V_1 -> V_40 = V_1 -> V_41 = NULL ;
}
if ( V_1 -> V_36 & V_38 )
{
if ( V_1 -> V_5 != NULL ) F_15 ( V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
V_1 -> V_6 = 0 ;
}
if ( V_1 -> V_36 & V_37 )
F_15 ( V_1 ) ;
}
T_1 * F_18 ( int V_43 , unsigned char * V_5 , int V_15 ,
const char * V_40 , const char * V_41 )
{
T_1 V_45 ;
V_45 . V_40 = V_40 ;
V_45 . V_41 = V_41 ;
V_45 . V_5 = V_5 ;
V_45 . V_43 = V_43 ;
V_45 . V_6 = V_15 ;
V_45 . V_36 = V_37 | V_44 |
V_38 ;
return ( F_19 ( & V_45 ) ) ;
}
