int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( NULL , 0 ) ;
F_3 ( V_1 , V_3 ,
V_4 , ( char * ) V_2 ) ;
return ( 1 ) ;
}
T_2 * F_4 ( T_1 * V_1 )
{
T_3 * V_5 ;
V_5 = F_5 ( V_1 , V_3 ) ;
if ( V_5 -> type == V_4 )
return V_5 -> V_6 . V_7 ;
return NULL ;
}
void F_6 ( T_1 * V_1 , char * V_8 )
{
T_4 * V_9 ;
if ( V_10 == - 1 )
V_10 =
F_7 ( L_1 , L_2 , L_3 ) ;
V_9 = F_8 () ;
F_9 ( V_9 , ( unsigned char * ) V_8 , strlen ( V_8 ) ) ;
F_3 ( V_1 , V_10 ,
V_11 , ( char * ) V_9 ) ;
}
int F_10 ( T_1 * V_1 , char * V_12 , int V_13 )
{
T_3 * V_5 ;
T_4 * V_9 ;
int V_14 ;
if ( V_10 == - 1 )
V_10 =
F_7 ( L_1 , L_2 , L_3 ) ;
V_5 = F_5 ( V_1 , V_10 ) ;
if ( V_5 != NULL )
{
if ( V_5 -> type == V_11 )
{
V_9 = V_5 -> V_6 . V_15 ;
V_14 = V_9 -> V_16 ;
if ( ( V_14 + 1 ) > V_13 )
V_14 = V_13 - 1 ;
memcpy ( V_12 , V_9 -> V_17 , V_14 ) ;
return ( V_14 ) ;
}
}
return ( 0 ) ;
}
int F_11 ( T_1 * V_1 , char * V_18 , char * V_19 )
{
unsigned char * V_20 ;
T_4 * V_21 , * V_22 ;
T_5 * V_23 ;
unsigned char * V_17 ;
int V_14 , V_24 ;
if ( V_25 == - 1 )
V_25 =
F_7 ( L_4 , L_2 , L_3 ) ;
V_21 = F_8 () ;
V_22 = F_8 () ;
F_9 ( V_21 , ( unsigned char * ) V_18 , strlen ( V_18 ) ) ;
F_9 ( V_22 , ( unsigned char * ) V_18 , strlen ( V_18 ) ) ;
V_14 = F_12 ( V_21 , NULL ) ;
V_14 += F_12 ( V_22 , NULL ) ;
V_24 = F_13 ( 1 , V_14 , V_26 ) ;
V_17 = malloc ( V_24 ) ;
V_20 = V_17 ;
F_14 ( & V_20 , 1 , V_14 , V_26 , V_27 ) ;
F_12 ( V_21 , & V_20 ) ;
F_12 ( V_22 , & V_20 ) ;
V_23 = F_15 () ;
F_16 ( V_23 , V_17 , V_24 ) ;
free ( V_17 ) ;
F_17 ( V_21 ) ;
F_17 ( V_22 ) ;
F_3 ( V_1 , V_25 ,
V_26 , ( char * ) V_23 ) ;
return ( 1 ) ;
}
int F_18 ( T_1 * V_1 , char * * V_18 , char * * V_19 )
{
T_3 * V_5 ;
if ( V_25 == - 1 )
V_25 =
F_7 ( L_4 , L_2 , L_3 ) ;
V_5 = F_5 ( V_1 , V_25 ) ;
if ( V_5 && ( V_5 -> type == V_26 ) )
{
T_6 V_28 ;
T_5 * V_29 ;
long V_16 ;
T_4 * V_21 , * V_22 ;
V_29 = V_5 -> V_6 . V_30 ;
V_28 . V_20 = F_19 ( V_29 ) ;
V_28 . V_31 = V_28 . V_20 + F_20 ( V_29 ) ;
if ( ! F_21 ( & V_28 , & V_16 ) ) goto V_32;
V_28 . V_33 = V_28 . V_20 ;
if ( ( V_21 = F_22 ( NULL , & V_28 . V_20 , V_28 . V_34 ) ) == NULL )
goto V_32;
V_28 . V_34 -= ( V_28 . V_20 - V_28 . V_33 ) ;
V_28 . V_33 = V_28 . V_20 ;
if ( ( V_22 = F_22 ( NULL , & V_28 . V_20 , V_28 . V_34 ) ) == NULL )
goto V_32;
V_28 . V_34 -= ( V_28 . V_20 - V_28 . V_33 ) ;
if ( ! F_23 ( & V_28 ) ) goto V_32;
* V_18 = malloc ( V_21 -> V_16 + 1 ) ;
* V_19 = malloc ( V_22 -> V_16 + 1 ) ;
memcpy ( * V_18 , V_21 -> V_17 , V_21 -> V_16 ) ;
memcpy ( * V_19 , V_22 -> V_17 , V_22 -> V_16 ) ;
( * V_18 ) [ V_21 -> V_16 ] = '\0' ;
( * V_19 ) [ V_22 -> V_16 ] = '\0' ;
F_17 ( V_21 ) ;
F_17 ( V_22 ) ;
return ( 1 ) ;
}
V_32:
return ( 0 ) ;
}
T_7 * F_24 ( void )
{
T_2 * V_2 ;
T_7 * V_35 ;
V_2 = F_2 ( NULL , 0 ) ;
V_35 = F_25 ( V_3 ,
V_4 , ( char * ) V_2 ) ;
return ( V_35 ) ;
}
T_7 * F_26 ( char * V_8 )
{
T_4 * V_9 ;
T_7 * V_35 ;
if ( V_10 == - 1 )
V_10 =
F_7 ( L_1 , L_2 , L_3 ) ;
V_9 = F_8 () ;
F_9 ( V_9 , ( unsigned char * ) V_8 , strlen ( V_8 ) ) ;
V_35 = F_25 ( V_10 ,
V_11 , ( char * ) V_9 ) ;
return ( V_35 ) ;
}
T_7 * F_27 ( T_1 * V_1 , char * V_18 , char * V_19 )
{
unsigned char * V_20 ;
T_4 * V_21 , * V_22 ;
T_5 * V_23 ;
T_7 * V_35 ;
unsigned char * V_17 ;
int V_14 , V_24 ;
if ( V_25 == - 1 )
V_25 =
F_7 ( L_4 , L_2 , L_3 ) ;
V_21 = F_8 () ;
V_22 = F_8 () ;
F_9 ( V_21 , ( unsigned char * ) V_18 , strlen ( V_18 ) ) ;
F_9 ( V_22 , ( unsigned char * ) V_18 , strlen ( V_18 ) ) ;
V_14 = F_12 ( V_21 , NULL ) ;
V_14 += F_12 ( V_22 , NULL ) ;
V_24 = F_13 ( 1 , V_14 , V_26 ) ;
V_17 = malloc ( V_24 ) ;
V_20 = V_17 ;
F_14 ( & V_20 , 1 , V_14 , V_26 , V_27 ) ;
F_12 ( V_21 , & V_20 ) ;
F_12 ( V_22 , & V_20 ) ;
V_23 = F_15 () ;
F_16 ( V_23 , V_17 , V_24 ) ;
free ( V_17 ) ;
F_17 ( V_21 ) ;
F_17 ( V_22 ) ;
V_35 = F_25 ( V_25 ,
V_26 , ( char * ) V_23 ) ;
return ( V_35 ) ;
}
