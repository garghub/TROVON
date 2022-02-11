int F_1 ( T_1 * V_1 , unsigned char * * V_2 , int (* F_2)() )
{
return F_3 ( V_1 , V_2 , F_2 , 0 ) ;
}
int F_3 ( T_1 * V_1 , unsigned char * * V_2 , int (* F_2)() , int V_3 )
{
int V_4 , V_5 , V_6 [ 6 ] ;
T_2 * V_7 ;
unsigned char V_8 [ 256 ] , * V_9 ;
unsigned char V_10 [ V_11 ] ;
T_3 V_12 ;
T_4 * V_13 = NULL ;
T_5 V_14 , V_15 ;
F_4 ( V_1 ) ;
if ( V_1 == NULL ) return ( 0 ) ;
#ifdef F_5
V_16 = V_16 ;
#endif
V_14 . V_17 = V_15 . V_17 = NULL ;
if ( ( V_7 = F_6 () ) == NULL ) goto V_18;
if ( ! F_7 ( V_7 -> V_19 , 0 ) ) goto V_18;
if ( V_7 -> V_20 -> V_21 != NULL )
F_8 ( V_7 -> V_20 -> V_21 ) ;
V_7 -> V_20 -> V_21 = F_9 ( V_22 ) ;
if ( ( V_7 -> V_20 -> V_23 = F_10 () ) == NULL ) goto V_18;
V_7 -> V_20 -> V_23 -> type = V_24 ;
V_6 [ 0 ] = F_11 ( V_1 , NULL ) ;
V_7 -> V_25 -> V_26 = V_6 [ 0 ] ;
V_15 . V_26 = F_12 ( V_7 , NULL ) ;
V_6 [ 1 ] = F_13 ( & V_15 , NULL ) ;
if ( ( V_13 = F_14 () ) == NULL ) goto V_18;
if ( V_13 -> V_21 != NULL )
F_8 ( V_13 -> V_21 ) ;
V_13 -> V_21 = F_9 ( V_27 ) ;
if ( ( V_13 -> V_23 = F_10 () ) == NULL ) goto V_18;
V_13 -> V_23 -> type = V_24 ;
V_6 [ 2 ] = F_15 ( V_13 , NULL ) ;
V_6 [ 3 ] = F_16 ( 1 , V_6 [ 2 ] + V_6 [ 1 ] , V_28 ) ;
#ifndef F_17
V_14 . V_17 = ( unsigned char * ) L_1 ;
#endif
V_14 . V_26 = 11 ;
V_6 [ 4 ] = F_13 ( & V_14 , NULL ) ;
V_6 [ 5 ] = F_16 ( 1 , V_6 [ 4 ] + V_6 [ 3 ] , V_28 ) ;
if ( V_2 == NULL )
{
if ( V_7 != NULL ) F_18 ( V_7 ) ;
if ( V_13 != NULL ) F_19 ( V_13 ) ;
return ( V_6 [ 5 ] ) ;
}
if ( V_7 -> V_25 -> V_17 != NULL )
F_20 ( V_7 -> V_25 -> V_17 ) ;
if ( ( V_7 -> V_25 -> V_17 = ( unsigned char * ) F_21 ( V_6 [ 0 ] ) ) == NULL )
{
F_22 ( V_29 , V_30 ) ;
goto V_18;
}
V_9 = V_7 -> V_25 -> V_17 ;
F_11 ( V_1 , & V_9 ) ;
if ( ( V_15 . V_17 = ( unsigned char * ) F_21 ( V_15 . V_26 ) ) == NULL )
{
F_22 ( V_29 , V_30 ) ;
goto V_18;
}
V_9 = V_15 . V_17 ;
F_12 ( V_7 , & V_9 ) ;
if ( F_2 == NULL )
F_2 = V_31 ;
V_4 = F_2 ( V_8 , 256 , L_2 , 1 ) ;
if ( V_4 != 0 )
{
F_22 ( V_29 , V_32 ) ;
goto V_18;
}
V_4 = strlen ( ( char * ) V_8 ) ;
if( V_3 ) {
T_6 V_33 ;
F_23 ( & V_33 , F_24 () ) ;
F_25 ( & V_33 , V_8 , V_4 ) ;
F_26 ( & V_33 , V_8 , NULL ) ;
memcpy ( V_8 + 16 , L_3 , 10 ) ;
V_4 = 26 ;
}
F_27 ( F_28 () , F_24 () , NULL , V_8 , V_4 , 1 , V_10 , NULL ) ;
memset ( V_8 , 0 , 256 ) ;
F_29 ( & V_12 ) ;
F_30 ( & V_12 , F_28 () , V_10 , NULL ) ;
F_31 ( & V_12 , V_15 . V_17 , & V_4 , V_15 . V_17 , V_15 . V_26 ) ;
F_32 ( & V_12 , & ( V_15 . V_17 [ V_4 ] ) , & V_5 ) ;
F_33 ( & V_12 ) ;
V_34 = * V_2 ;
F_34 ( & V_34 , 1 , V_6 [ 4 ] + V_6 [ 3 ] , V_28 , V_35 ) ;
F_13 ( & V_14 , & V_34 ) ;
F_34 ( & V_34 , 1 , V_6 [ 2 ] + V_6 [ 1 ] , V_28 , V_35 ) ;
F_15 ( V_13 , & V_34 ) ;
F_13 ( & V_15 , & V_34 ) ;
V_36 = V_6 [ 5 ] ;
V_18:
if ( V_15 . V_17 != NULL ) F_20 ( V_15 . V_17 ) ;
if ( V_13 != NULL ) F_19 ( V_13 ) ;
if ( V_7 != NULL ) F_18 ( V_7 ) ;
V_16 = V_16 ;
return ( V_36 ) ;
}
T_1 * F_35 ( T_1 * * V_1 , unsigned char * * V_2 , long V_26 , int (* F_2)() )
{
return F_36 ( V_1 , V_2 , V_26 , F_2 , 0 ) ;
}
T_1 * F_36 ( T_1 * * V_1 , unsigned char * * V_2 , long V_26 , int (* F_2)() , int V_3 )
{
T_1 * V_36 = NULL ;
T_5 * V_14 = NULL ;
T_7 V_37 ;
V_37 . V_2 = V_2 ;
V_37 . error = V_38 ;
F_37 () ;
F_38 () ;
F_39 ( V_14 , V_39 ) ;
if ( ( V_14 -> V_26 != 11 ) || ( strncmp ( L_1 ,
( char * ) V_14 -> V_17 , V_14 -> V_26 ) != 0 ) )
{
F_22 ( V_40 , V_41 ) ;
F_40 ( V_14 ) ;
goto V_18;
}
F_40 ( V_14 ) ;
V_37 . V_42 = V_37 . V_34 ;
if ( ( V_36 = F_41 ( V_1 , & V_37 . V_34 , V_37 . V_43 , F_2 , V_3 ) ) == NULL ) goto V_18;
V_37 . V_43 = 0 ;
F_42 ( V_1 , V_44 , V_40 ) ;
}
T_1 * F_43 ( T_1 * * V_1 , unsigned char * * V_2 , long V_26 ,
int (* F_2)() )
{
return F_41 ( V_1 , V_2 , V_26 , F_2 , 0 ) ;
}
T_1 * F_41 ( T_1 * * V_1 , unsigned char * * V_2 , long V_26 ,
int (* F_2)() , int V_3 )
{
T_2 * V_7 = NULL ;
T_1 * V_36 = NULL ;
int V_4 , V_5 ;
unsigned char V_8 [ 256 ] , * V_9 ;
unsigned char V_10 [ V_11 ] ;
T_3 V_12 ;
T_4 * V_13 = NULL ;
T_5 * V_14 = NULL ;
T_7 V_37 ;
V_37 . error = V_45 ;
V_37 . V_2 = V_2 ;
F_37 () ;
F_38 () ;
F_39 ( V_13 , V_46 ) ;
if ( F_44 ( V_13 -> V_21 ) != V_27 )
{
F_22 ( V_47 , V_48 ) ;
goto V_18;
}
F_39 ( V_14 , V_39 ) ;
if ( F_2 == NULL )
F_2 = V_31 ;
V_4 = F_2 ( V_8 , 256 , L_2 , 0 ) ;
if ( V_4 != 0 )
{
F_22 ( V_47 , V_32 ) ;
goto V_18;
}
V_4 = strlen ( ( char * ) V_8 ) ;
if( V_3 ) {
T_6 V_33 ;
F_23 ( & V_33 , F_24 () ) ;
F_25 ( & V_33 , V_8 , V_4 ) ;
F_26 ( & V_33 , V_8 , NULL ) ;
memcpy ( V_8 + 16 , L_3 , 10 ) ;
V_4 = 26 ;
}
F_27 ( F_28 () , F_24 () , NULL , V_8 , V_4 , 1 , V_10 , NULL ) ;
memset ( V_8 , 0 , 256 ) ;
F_29 ( & V_12 ) ;
F_45 ( & V_12 , F_28 () , V_10 , NULL ) ;
F_46 ( & V_12 , V_14 -> V_17 , & V_4 , V_14 -> V_17 , V_14 -> V_26 ) ;
F_47 ( & V_12 , & ( V_14 -> V_17 [ V_4 ] ) , & V_5 ) ;
F_33 ( & V_12 ) ;
V_14 -> V_26 = V_4 + V_5 ;
V_9 = V_14 -> V_17 ;
if ( ( V_7 = F_48 ( NULL , & V_9 , V_14 -> V_26 ) ) == NULL )
{
F_22 ( V_47 , V_49 ) ;
goto V_18;
}
V_9 = V_7 -> V_25 -> V_17 ;
if ( ( V_36 = F_49 ( V_1 , & V_9 , V_7 -> V_25 -> V_26 ) ) == NULL )
{
F_22 ( V_47 , V_50 ) ;
goto V_18;
}
if ( ! F_50 ( & V_37 ) ) goto V_18;
* V_2 = V_37 . V_34 ;
V_18:
if ( V_7 != NULL ) F_18 ( V_7 ) ;
if ( V_14 != NULL ) F_40 ( V_14 ) ;
if ( V_13 != NULL ) F_19 ( V_13 ) ;
return ( V_36 ) ;
}
static int F_12 ( T_2 * V_1 , unsigned char * * V_2 )
{
F_4 ( V_1 ) ;
F_51 ( V_1 -> V_19 , V_51 ) ;
F_51 ( V_1 -> V_20 , F_15 ) ;
F_51 ( V_1 -> V_25 , F_13 ) ;
F_52 () ;
F_53 ( V_1 -> V_19 , V_51 ) ;
F_53 ( V_1 -> V_20 , F_15 ) ;
F_53 ( V_1 -> V_25 , F_13 ) ;
F_54 () ;
}
static T_2 * F_48 ( T_2 * * V_1 , unsigned char * * V_2 ,
long V_26 )
{
F_55 ( V_1 , T_2 * , F_6 ) ;
F_37 () ;
F_38 () ;
F_39 ( V_36 -> V_19 , V_52 ) ;
F_39 ( V_36 -> V_20 , V_46 ) ;
F_39 ( V_36 -> V_25 , V_39 ) ;
F_42 ( V_1 , F_18 , V_53 ) ;
}
static T_2 * F_6 ( void )
{
T_2 * V_36 = NULL ;
T_7 V_37 ;
F_56 ( V_36 , T_2 ) ;
F_57 ( V_36 -> V_19 , V_54 ) ;
F_57 ( V_36 -> V_20 , F_14 ) ;
F_57 ( V_36 -> V_25 , V_55 ) ;
return ( V_36 ) ;
F_58 ( V_56 ) ;
}
static void F_18 ( T_2 * V_1 )
{
if ( V_1 == NULL ) return;
F_59 ( V_1 -> V_19 ) ;
F_19 ( V_1 -> V_20 ) ;
F_60 ( V_1 -> V_25 ) ;
F_20 ( V_1 ) ;
}
