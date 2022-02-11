int F_1 ( T_1 * V_1 , unsigned char * * V_2 , int (* F_2)() )
{
int V_3 , V_4 , V_5 [ 6 ] ;
T_2 * V_6 ;
unsigned char V_7 [ 256 ] , * V_8 ;
unsigned char V_9 [ V_10 ] ;
T_3 V_11 ;
T_4 * V_12 = NULL ;
T_5 V_13 , V_14 ;
F_3 ( V_1 ) ;
if ( V_1 == NULL ) return ( 0 ) ;
#ifdef F_4
V_15 = V_15 ;
#endif
V_13 . V_16 = V_14 . V_16 = NULL ;
if ( ( V_6 = F_5 () ) == NULL ) goto V_17;
if ( ! F_6 ( V_6 -> V_18 , 0 ) ) goto V_17;
if ( V_6 -> V_19 -> V_20 != NULL )
F_7 ( V_6 -> V_19 -> V_20 ) ;
V_6 -> V_19 -> V_20 = F_8 ( V_21 ) ;
if ( ( V_6 -> V_19 -> V_22 = F_9 () ) == NULL ) goto V_17;
V_6 -> V_19 -> V_22 -> type = V_23 ;
V_5 [ 0 ] = F_10 ( V_1 , NULL ) ;
V_6 -> V_24 -> V_25 = V_5 [ 0 ] ;
V_14 . V_25 = F_11 ( V_6 , NULL ) ;
V_5 [ 1 ] = F_12 ( & V_14 , NULL ) ;
if ( ( V_12 = F_13 () ) == NULL ) goto V_17;
if ( V_12 -> V_20 != NULL )
F_7 ( V_12 -> V_20 ) ;
V_12 -> V_20 = F_8 ( V_26 ) ;
if ( ( V_12 -> V_22 = F_9 () ) == NULL ) goto V_17;
V_12 -> V_22 -> type = V_23 ;
V_5 [ 2 ] = F_14 ( V_12 , NULL ) ;
V_5 [ 3 ] = F_15 ( 1 , V_5 [ 2 ] + V_5 [ 1 ] , V_27 ) ;
#ifndef F_16
V_13 . V_16 = ( unsigned char * ) L_1 ;
#endif
V_13 . V_25 = 11 ;
V_5 [ 4 ] = F_12 ( & V_13 , NULL ) ;
V_5 [ 5 ] = F_15 ( 1 , V_5 [ 4 ] + V_5 [ 3 ] , V_27 ) ;
if ( V_2 == NULL )
{
if ( V_6 != NULL ) F_17 ( V_6 ) ;
if ( V_12 != NULL ) F_18 ( V_12 ) ;
return ( V_5 [ 5 ] ) ;
}
if ( V_6 -> V_24 -> V_16 != NULL )
Free ( ( char * ) V_6 -> V_24 -> V_16 ) ;
if ( ( V_6 -> V_24 -> V_16 = ( unsigned char * ) Malloc ( V_5 [ 0 ] ) ) == NULL )
{
F_19 ( V_28 , V_29 ) ;
goto V_17;
}
V_8 = V_6 -> V_24 -> V_16 ;
F_10 ( V_1 , & V_8 ) ;
if ( ( V_14 . V_16 = ( unsigned char * ) Malloc ( V_14 . V_25 ) ) == NULL )
{
F_19 ( V_28 , V_29 ) ;
goto V_17;
}
V_8 = V_14 . V_16 ;
F_11 ( V_6 , & V_8 ) ;
if ( F_2 == NULL )
F_2 = V_30 ;
V_3 = F_2 ( V_7 , 256 , L_2 , 1 ) ;
if ( V_3 != 0 )
{
F_19 ( V_28 , V_31 ) ;
goto V_17;
}
F_20 ( F_21 () , F_22 () , NULL , V_7 ,
strlen ( ( char * ) V_7 ) , 1 , V_9 , NULL ) ;
memset ( V_7 , 0 , 256 ) ;
F_23 ( & V_11 ) ;
F_24 ( & V_11 , F_21 () , V_9 , NULL ) ;
F_25 ( & V_11 , V_14 . V_16 , & V_3 , V_14 . V_16 , V_14 . V_25 ) ;
F_26 ( & V_11 , & ( V_14 . V_16 [ V_3 ] ) , & V_4 ) ;
F_27 ( & V_11 ) ;
V_32 = * V_2 ;
F_28 ( & V_32 , 1 , V_5 [ 4 ] + V_5 [ 3 ] , V_27 , V_33 ) ;
F_12 ( & V_13 , & V_32 ) ;
F_28 ( & V_32 , 1 , V_5 [ 2 ] + V_5 [ 1 ] , V_27 , V_33 ) ;
F_14 ( V_12 , & V_32 ) ;
F_12 ( & V_14 , & V_32 ) ;
V_34 = V_5 [ 5 ] ;
V_17:
if ( V_14 . V_16 != NULL ) Free ( V_14 . V_16 ) ;
if ( V_12 != NULL ) F_18 ( V_12 ) ;
if ( V_6 != NULL ) F_17 ( V_6 ) ;
V_15 = V_15 ;
return ( V_34 ) ;
}
T_1 * F_29 ( T_1 * * V_1 , unsigned char * * V_2 , long V_25 , int (* F_2)() )
{
T_1 * V_34 = NULL ;
T_5 * V_13 = NULL ;
T_6 V_35 ;
V_35 . V_2 = V_2 ;
V_35 . error = V_36 ;
F_30 () ;
F_31 () ;
F_32 ( V_13 , V_37 ) ;
if ( ( V_13 -> V_25 != 11 ) || ( strncmp ( L_1 ,
( char * ) V_13 -> V_16 , V_13 -> V_25 ) != 0 ) )
{
F_19 ( V_38 , V_39 ) ;
F_33 ( V_13 ) ;
goto V_17;
}
F_33 ( V_13 ) ;
V_35 . V_40 = V_35 . V_32 ;
if ( ( V_34 = F_34 ( V_1 , & V_35 . V_32 , V_35 . V_41 , F_2 ) ) == NULL ) goto V_17;
V_35 . V_41 -= ( V_35 . V_32 - V_35 . V_40 ) ;
F_35 ( V_1 , V_42 , V_38 ) ;
}
T_1 * F_34 ( T_1 * * V_1 , unsigned char * * V_2 , long V_25 ,
int (* F_2)() )
{
T_2 * V_6 = NULL ;
T_1 * V_34 = NULL ;
int V_3 , V_4 ;
unsigned char V_7 [ 256 ] , * V_8 ;
unsigned char V_9 [ V_10 ] ;
T_3 V_11 ;
T_4 * V_12 = NULL ;
T_5 * V_13 = NULL ;
T_6 V_35 ;
V_35 . error = V_43 ;
V_35 . V_2 = V_2 ;
F_30 () ;
F_31 () ;
F_32 ( V_12 , V_44 ) ;
if ( F_36 ( V_12 -> V_20 ) != V_26 )
{
F_19 ( V_45 , V_46 ) ;
goto V_17;
}
F_32 ( V_13 , V_37 ) ;
if ( F_2 == NULL )
F_2 = V_30 ;
V_3 = F_2 ( V_7 , 256 , L_2 , 0 ) ;
if ( V_3 != 0 )
{
F_19 ( V_45 , V_31 ) ;
goto V_17;
}
F_20 ( F_21 () , F_22 () , NULL , V_7 ,
strlen ( ( char * ) V_7 ) , 1 , V_9 , NULL ) ;
memset ( V_7 , 0 , 256 ) ;
F_23 ( & V_11 ) ;
F_37 ( & V_11 , F_21 () , V_9 , NULL ) ;
F_38 ( & V_11 , V_13 -> V_16 , & V_3 , V_13 -> V_16 , V_13 -> V_25 ) ;
F_39 ( & V_11 , & ( V_13 -> V_16 [ V_3 ] ) , & V_4 ) ;
F_27 ( & V_11 ) ;
V_13 -> V_25 = V_3 + V_4 ;
V_8 = V_13 -> V_16 ;
if ( ( V_6 = F_40 ( NULL , & V_8 , V_13 -> V_25 ) ) == NULL )
{
F_19 ( V_45 , V_47 ) ;
goto V_17;
}
V_8 = V_6 -> V_24 -> V_16 ;
if ( ( V_34 = F_41 ( V_1 , & V_8 , V_6 -> V_24 -> V_25 ) ) == NULL )
{
F_19 ( V_45 , V_48 ) ;
goto V_17;
}
if ( ! F_42 ( & V_35 ) ) goto V_17;
* V_2 = V_35 . V_32 ;
V_17:
if ( V_6 != NULL ) F_17 ( V_6 ) ;
if ( V_13 != NULL ) F_33 ( V_13 ) ;
if ( V_12 != NULL ) F_18 ( V_12 ) ;
return ( V_34 ) ;
}
static int F_11 ( T_2 * V_1 , unsigned char * * V_2 )
{
F_3 ( V_1 ) ;
F_43 ( V_1 -> V_18 , V_49 ) ;
F_43 ( V_1 -> V_19 , F_14 ) ;
F_43 ( V_1 -> V_24 , F_12 ) ;
F_44 () ;
F_45 ( V_1 -> V_18 , V_49 ) ;
F_45 ( V_1 -> V_19 , F_14 ) ;
F_45 ( V_1 -> V_24 , F_12 ) ;
F_46 () ;
}
static T_2 * F_40 ( T_2 * * V_1 , unsigned char * * V_2 ,
long V_25 )
{
F_47 ( V_1 , T_2 * , F_5 ) ;
F_30 () ;
F_31 () ;
F_32 ( V_34 -> V_18 , V_50 ) ;
F_32 ( V_34 -> V_19 , V_44 ) ;
F_32 ( V_34 -> V_24 , V_37 ) ;
F_35 ( V_1 , F_17 , V_51 ) ;
}
static T_2 * F_5 ( void )
{
T_2 * V_34 = NULL ;
T_6 V_35 ;
F_48 ( V_34 , T_2 ) ;
F_49 ( V_34 -> V_18 , V_52 ) ;
F_49 ( V_34 -> V_19 , F_13 ) ;
F_49 ( V_34 -> V_24 , V_53 ) ;
return ( V_34 ) ;
F_50 ( V_54 ) ;
}
static void F_17 ( T_2 * V_1 )
{
if ( V_1 == NULL ) return;
F_51 ( V_1 -> V_18 ) ;
F_18 ( V_1 -> V_19 ) ;
F_52 ( V_1 -> V_24 ) ;
Free ( ( char * ) V_1 ) ;
}
