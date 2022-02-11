int F_1 ( const T_1 * V_1 , unsigned char * * V_2 )
{
unsigned char * V_3 ;
int V_4 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_5 == NULL ) )
return ( 0 ) ;
V_4 = F_2 ( 0 , V_1 -> V_6 , V_7 ) ;
if ( V_2 == NULL || V_4 == - 1 )
return V_4 ;
V_3 = * V_2 ;
F_3 ( & V_3 , 0 , V_1 -> V_6 , V_7 , V_8 ) ;
memcpy ( V_3 , V_1 -> V_5 , V_1 -> V_6 ) ;
V_3 += V_1 -> V_6 ;
* V_2 = V_3 ;
return ( V_4 ) ;
}
int F_4 ( unsigned char * V_9 , int V_10 , const char * V_11 , int V_12 )
{
int V_13 , V_14 , V_15 = 0 , V_16 , V_17 ;
char V_18 [ 24 ] , * V_19 = V_18 ;
int V_20 = sizeof V_18 ;
const char * V_3 ;
unsigned long V_21 ;
T_2 * V_22 = NULL ;
if ( V_12 == 0 )
return ( 0 ) ;
else if ( V_12 == - 1 )
V_12 = strlen ( V_11 ) ;
V_3 = V_11 ;
V_16 = * ( V_3 ++ ) ;
V_12 -- ;
if ( ( V_16 >= '0' ) && ( V_16 <= '2' ) ) {
V_14 = V_16 - '0' ;
} else {
F_5 ( V_23 , V_24 ) ;
goto V_25;
}
if ( V_12 <= 0 ) {
F_5 ( V_23 , V_26 ) ;
goto V_25;
}
V_16 = * ( V_3 ++ ) ;
V_12 -- ;
for (; ; ) {
if ( V_12 <= 0 )
break;
if ( ( V_16 != '.' ) && ( V_16 != ' ' ) ) {
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
V_21 = 0 ;
V_17 = 0 ;
for (; ; ) {
if ( V_12 <= 0 )
break;
V_12 -- ;
V_16 = * ( V_3 ++ ) ;
if ( ( V_16 == ' ' ) || ( V_16 == '.' ) )
break;
if ( ( V_16 < '0' ) || ( V_16 > '9' ) ) {
F_5 ( V_23 , V_28 ) ;
goto V_25;
}
if ( ! V_17 && V_21 >= ( ( V_29 - 80 ) / 10L ) ) {
V_17 = 1 ;
if ( V_22 == NULL )
V_22 = F_6 () ;
if ( V_22 == NULL || ! F_7 ( V_22 , V_21 ) )
goto V_25;
}
if ( V_17 ) {
if ( ! F_8 ( V_22 , 10L )
|| ! F_9 ( V_22 , V_16 - '0' ) )
goto V_25;
} else
V_21 = V_21 * 10L + ( long ) ( V_16 - '0' ) ;
}
if ( V_15 == 0 ) {
if ( ( V_14 < 2 ) && ( V_21 >= 40 ) ) {
F_5 ( V_23 ,
V_30 ) ;
goto V_25;
}
if ( V_17 ) {
if ( ! F_9 ( V_22 , V_14 * 40 ) )
goto V_25;
} else
V_21 += ( long ) V_14 * 40 ;
}
V_13 = 0 ;
if ( V_17 ) {
int V_31 ;
V_31 = F_10 ( V_22 ) ;
V_31 = ( V_31 + 6 ) / 7 ;
if ( V_31 > V_20 ) {
if ( V_19 != V_18 )
F_11 ( V_19 ) ;
V_20 = V_31 + 32 ;
V_19 = F_12 ( V_20 ) ;
if ( V_19 == NULL )
goto V_25;
}
while ( V_31 -- ) {
T_3 V_32 = F_13 ( V_22 , 0x80L ) ;
if ( V_32 == ( T_3 ) - 1 )
goto V_25;
V_19 [ V_13 ++ ] = ( unsigned char ) V_32 ;
}
} else {
for (; ; ) {
V_19 [ V_13 ++ ] = ( unsigned char ) V_21 & 0x7f ;
V_21 >>= 7L ;
if ( V_21 == 0L )
break;
}
}
if ( V_9 != NULL ) {
if ( V_15 + V_13 > V_10 ) {
F_5 ( V_23 , V_33 ) ;
goto V_25;
}
while ( -- V_13 > 0 )
V_9 [ V_15 ++ ] = V_19 [ V_13 ] | 0x80 ;
V_9 [ V_15 ++ ] = V_19 [ 0 ] ;
} else
V_15 += V_13 ;
}
if ( V_19 != V_18 )
F_11 ( V_19 ) ;
F_14 ( V_22 ) ;
return ( V_15 ) ;
V_25:
if ( V_19 != V_18 )
F_11 ( V_19 ) ;
F_14 ( V_22 ) ;
return ( 0 ) ;
}
int F_15 ( char * V_11 , int V_34 , const T_1 * V_1 )
{
return F_16 ( V_11 , V_34 , V_1 , 0 ) ;
}
int F_17 ( T_4 * V_35 , const T_1 * V_1 )
{
char V_11 [ 80 ] , * V_3 = V_11 ;
int V_13 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_5 == NULL ) )
return ( F_18 ( V_35 , L_1 , 4 ) ) ;
V_13 = F_15 ( V_11 , sizeof V_11 , V_1 ) ;
if ( V_13 > ( int ) ( sizeof( V_11 ) - 1 ) ) {
V_3 = F_12 ( V_13 + 1 ) ;
if ( V_3 == NULL )
return - 1 ;
F_15 ( V_3 , V_13 + 1 , V_1 ) ;
}
if ( V_13 <= 0 ) {
V_13 = F_18 ( V_35 , L_2 , 9 ) ;
V_13 += F_19 ( V_35 , ( const char * ) V_1 -> V_5 , V_1 -> V_6 ) ;
return V_13 ;
}
F_18 ( V_35 , V_3 , V_13 ) ;
if ( V_3 != V_11 )
F_11 ( V_3 ) ;
return ( V_13 ) ;
}
T_1 * F_20 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_6 )
{
const unsigned char * V_3 ;
long V_15 ;
int V_36 , V_37 ;
int V_38 , V_13 ;
T_1 * V_39 = NULL ;
V_3 = * V_2 ;
V_38 = F_21 ( & V_3 , & V_15 , & V_36 , & V_37 , V_6 ) ;
if ( V_38 & 0x80 ) {
V_13 = V_40 ;
goto V_25;
}
if ( V_36 != V_7 ) {
V_13 = V_41 ;
goto V_25;
}
V_39 = F_22 ( V_1 , & V_3 , V_15 ) ;
if ( V_39 )
* V_2 = V_3 ;
return V_39 ;
V_25:
F_5 ( V_42 , V_13 ) ;
return ( NULL ) ;
}
T_1 * F_22 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_15 )
{
T_1 * V_39 = NULL , V_43 ;
const unsigned char * V_3 ;
unsigned char * V_5 ;
int V_13 , V_6 ;
if ( V_15 <= 0 || V_15 > V_44 || V_2 == NULL || ( V_3 = * V_2 ) == NULL ||
V_3 [ V_15 - 1 ] & 0x80 ) {
F_5 ( V_45 , V_46 ) ;
return NULL ;
}
V_6 = ( int ) V_15 ;
V_43 . V_47 = V_48 ;
V_43 . V_5 = V_3 ;
V_43 . V_6 = V_6 ;
V_43 . V_49 = 0 ;
V_13 = F_23 ( & V_43 ) ;
if ( V_13 != V_48 ) {
V_39 = F_24 ( V_13 ) ;
if ( V_1 ) {
F_25 ( * V_1 ) ;
* V_1 = V_39 ;
}
* V_2 += V_15 ;
return V_39 ;
}
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ , V_3 ++ ) {
if ( * V_3 == 0x80 && ( ! V_13 || ! ( V_3 [ - 1 ] & 0x80 ) ) ) {
F_5 ( V_45 , V_46 ) ;
return NULL ;
}
}
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) ||
! ( ( * V_1 ) -> V_49 & V_50 ) ) {
if ( ( V_39 = F_26 () ) == NULL )
return ( NULL ) ;
} else
V_39 = ( * V_1 ) ;
V_3 = * V_2 ;
V_5 = ( unsigned char * ) V_39 -> V_5 ;
V_39 -> V_5 = NULL ;
if ( ( V_5 == NULL ) || ( V_39 -> V_6 < V_6 ) ) {
V_39 -> V_6 = 0 ;
F_11 ( V_5 ) ;
V_5 = F_12 ( V_6 ) ;
if ( V_5 == NULL ) {
V_13 = V_51 ;
goto V_25;
}
V_39 -> V_49 |= V_52 ;
}
memcpy ( V_5 , V_3 , V_6 ) ;
V_39 -> V_5 = V_5 ;
V_39 -> V_6 = V_6 ;
V_39 -> V_53 = NULL ;
V_39 -> V_54 = NULL ;
V_3 += V_6 ;
if ( V_1 != NULL )
( * V_1 ) = V_39 ;
* V_2 = V_3 ;
return ( V_39 ) ;
V_25:
F_5 ( V_45 , V_13 ) ;
if ( ( V_1 == NULL ) || ( * V_1 != V_39 ) )
F_25 ( V_39 ) ;
return ( NULL ) ;
}
T_1 * F_26 ( void )
{
T_1 * V_39 ;
V_39 = F_27 ( sizeof( * V_39 ) ) ;
if ( V_39 == NULL ) {
F_5 ( V_55 , V_51 ) ;
return ( NULL ) ;
}
V_39 -> V_49 = V_50 ;
return ( V_39 ) ;
}
void F_25 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
if ( V_1 -> V_49 & V_56 ) {
#ifndef F_28
F_11 ( ( void * ) V_1 -> V_53 ) ;
F_11 ( ( void * ) V_1 -> V_54 ) ;
#endif
V_1 -> V_53 = V_1 -> V_54 = NULL ;
}
if ( V_1 -> V_49 & V_52 ) {
F_11 ( ( void * ) V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
V_1 -> V_6 = 0 ;
}
if ( V_1 -> V_49 & V_50 )
F_11 ( V_1 ) ;
}
T_1 * F_29 ( int V_47 , unsigned char * V_5 , int V_15 ,
const char * V_53 , const char * V_54 )
{
T_1 V_57 ;
V_57 . V_53 = V_53 ;
V_57 . V_54 = V_54 ;
V_57 . V_5 = V_5 ;
V_57 . V_47 = V_47 ;
V_57 . V_6 = V_15 ;
V_57 . V_49 = V_50 | V_56 |
V_52 ;
return ( F_30 ( & V_57 ) ) ;
}
