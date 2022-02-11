static T_1
F_1 ( char * V_1 )
{
T_1 V_2 = V_3 ;
#ifdef F_2
T_2 V_4 ;
int V_5 ;
V_5 = F_3 ( F_4 ( 1 , 1 ) , & V_4 ) ;
if ( V_5 != 0 ) {
F_5 ( L_1 , V_5 ) ;
return V_3 ;
}
#endif
#ifdef F_6
if ( ! strncmp ( V_1 , L_2 , 5 ) )
{
struct V_6 V_7 ;
T_3 V_8 ;
V_1 += 5 ;
if ( strlen ( V_1 ) + 1 > sizeof( V_7 . V_9 ) )
return V_3 ;
V_2 = F_7 ( V_10 , V_11 , 0 ) ;
if ( V_2 == V_3 )
return V_3 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_12 = V_10 ;
F_8 ( V_7 . V_9 , V_1 , sizeof( V_7 . V_9 ) ) ;
V_8 = ( T_3 ) ( F_9 ( struct V_6 , V_9 ) + strlen ( V_7 . V_9 ) ) ;
if ( V_7 . V_9 [ 0 ] == '@' )
V_7 . V_9 [ 0 ] = '\0' ;
if ( F_10 ( V_2 , (struct V_13 * ) & V_7 , V_8 ) )
{
F_11 ( V_2 ) ;
return V_3 ;
}
}
else
#endif
#ifdef F_12
if ( ! strncmp ( V_1 , L_3 , 4 ) )
{
struct V_14 V_15 ;
int V_16 = 1 ;
char * V_17 ;
T_4 V_18 ;
V_1 += 4 ;
V_17 = strchr ( V_1 , ':' ) ;
if ( ! V_17 )
return V_3 ;
* V_17 = '\0' ;
if ( F_13 ( V_17 + 1 , NULL , & V_18 ) == FALSE )
return V_3 ;
#ifdef F_2
V_2 = F_14 ( V_19 , V_11 , 0 , NULL , 0 , 0 ) ;
#else
V_2 = F_7 ( V_19 , V_11 , 0 ) ;
#endif
if ( V_2 == V_3 )
return V_3 ;
V_15 . V_20 = V_19 ;
V_15 . V_21 . V_22 = F_15 ( V_1 ) ;
V_15 . V_23 = F_16 ( V_18 ) ;
* V_17 = ':' ;
F_17 ( V_2 , V_24 , V_25 , ( void * ) & V_16 , sizeof( V_16 ) ) ;
if ( F_10 ( V_2 , (struct V_13 * ) & V_15 , sizeof( struct V_14 ) ) )
{
F_11 ( V_2 ) ;
return V_3 ;
}
}
else
#endif
{
return V_3 ;
}
if ( F_18 ( V_2 , V_26 ) )
{
F_11 ( V_2 ) ;
return V_3 ;
}
return V_2 ;
}
int
F_19 ( int V_27 , char * * V_28 )
{
#ifndef F_2
T_5 V_29 ;
#endif
T_1 V_2 ;
if ( V_27 != 2 )
{
fprintf ( V_30 , L_4 , V_28 [ 0 ] ) ;
fprintf ( V_30 , L_5 ) ;
fprintf ( V_30 , L_6 ) ;
#ifdef F_6
fprintf ( V_30 , L_7 ) ;
#endif
#ifdef F_12
fprintf ( V_30 , L_8 ) ;
#endif
fprintf ( V_30 , L_5 ) ;
return - 1 ;
}
#ifndef F_2
signal ( V_31 , V_32 ) ;
#endif
if ( ! strcmp ( V_28 [ 1 ] , L_9 ) )
{
V_33 = 1 ;
}
else
{
V_2 = F_1 ( V_28 [ 1 ] ) ;
if ( V_2 == V_3 )
return - 1 ;
V_34 = V_2 ;
}
#ifndef F_2
V_29 = F_20 () ;
if ( V_29 == - 1 )
fprintf ( V_30 , L_10 , F_21 ( V_35 ) ) ;
if ( V_29 != 0 )
{
exit ( 0 ) ;
}
#endif
return 0 ;
}
int
F_22 ( void )
{
if ( V_33 )
{
return F_23 () ;
}
while ( 1 )
{
#ifndef F_2
T_5 V_29 ;
#else
T_6 V_36 ;
T_7 V_37 ;
char * V_38 ;
T_8 * V_39 ;
#endif
T_1 V_2 ;
V_2 = F_24 ( V_34 , NULL , NULL ) ;
if ( V_2 == V_3 )
{
fprintf ( V_30 , L_11 , F_21 ( V_35 ) ) ;
continue;
}
#ifndef F_2
V_29 = F_20 () ;
if ( V_29 == 0 )
{
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , 1 ) ;
F_26 ( V_2 ) ;
exit ( F_23 () ) ;
}
if ( V_29 == - 1 )
{
fprintf ( V_30 , L_12 , F_21 ( V_35 ) ) ;
}
#else
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_40 = sizeof( V_37 ) ;
V_37 . V_41 = V_42 | V_43 ;
V_37 . V_44 = ( V_45 ) V_2 ;
V_37 . V_46 = ( V_45 ) V_2 ;
V_37 . V_47 = F_27 ( V_48 ) ;
V_38 = F_28 ( L_13 , F_29 () , L_14 ) ;
V_39 = F_30 ( L_15 , - 1 , NULL , NULL , NULL ) ;
if ( ! F_31 ( F_32 ( V_38 ) , V_39 , NULL , NULL , TRUE , 0 , NULL , NULL , & V_37 , & V_36 ) )
{
fprintf ( V_30 , L_16 , V_38 ) ;
}
else
{
F_33 ( V_36 . V_49 ) ;
}
F_34 ( V_38 ) ;
F_34 ( V_39 ) ;
#endif
F_11 ( V_2 ) ;
}
return 0 ;
}
