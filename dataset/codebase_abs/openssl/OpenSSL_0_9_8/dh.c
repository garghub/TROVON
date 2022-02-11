int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
T_2 * V_4 = NULL ;
int V_5 , V_6 = 0 , V_7 = 0 ;
T_3 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 , V_15 = 1 ;
char * V_16 , * V_17 , * V_18 ;
#ifndef F_1
char * V_19 ;
#endif
F_2 () ;
if ( V_20 == NULL )
if ( ( V_20 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_20 , V_21 , V_22 | V_23 ) ;
if ( ! F_6 ( V_20 , NULL ) )
goto V_24;
#ifndef F_1
V_19 = NULL ;
#endif
V_16 = NULL ;
V_17 = NULL ;
V_10 = V_25 ;
V_11 = V_25 ;
V_18 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_10 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_11 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_17 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_19 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_7 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_13 = 1 ;
else
{
F_8 ( V_20 , L_10 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_26:
F_8 ( V_20 , L_11 , V_18 ) ;
F_8 ( V_20 , L_12 ) ;
F_8 ( V_20 , L_13 ) ;
F_8 ( V_20 , L_14 ) ;
F_8 ( V_20 , L_15 ) ;
F_8 ( V_20 , L_16 ) ;
F_8 ( V_20 , L_17 ) ;
F_8 ( V_20 , L_18 ) ;
F_8 ( V_20 , L_19 ) ;
F_8 ( V_20 , L_20 ) ;
#ifndef F_1
F_8 ( V_20 , L_21 ) ;
#endif
goto V_24;
}
F_9 () ;
#ifndef F_1
V_3 = F_10 ( V_20 , V_19 , 0 ) ;
#endif
V_8 = F_3 ( F_4 () ) ;
V_9 = F_3 ( F_4 () ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
F_11 ( V_20 ) ;
goto V_24;
}
if ( V_16 == NULL )
F_5 ( V_8 , V_27 , V_22 ) ;
else
{
if ( F_12 ( V_8 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_24;
}
}
if ( V_17 == NULL )
{
F_5 ( V_9 , stdout , V_22 ) ;
#ifdef F_13
{
T_3 * V_28 = F_3 ( F_14 () ) ;
V_9 = F_15 ( V_28 , V_9 ) ;
}
#endif
}
else
{
if ( F_16 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_24;
}
}
if ( V_10 == V_29 )
V_4 = F_17 ( V_8 , NULL ) ;
else if ( V_10 == V_25 )
V_4 = F_18 ( V_8 , NULL , NULL , NULL ) ;
else
{
F_8 ( V_20 , L_22 ) ;
goto V_24;
}
if ( V_4 == NULL )
{
F_8 ( V_20 , L_23 ) ;
F_11 ( V_20 ) ;
goto V_24;
}
if ( V_7 )
{
F_19 ( V_9 , V_4 ) ;
#ifdef undef
printf ( L_24 ) ;
F_20 ( stdout , V_4 -> V_30 ) ;
printf ( L_25 ) ;
F_20 ( stdout , V_4 -> V_31 ) ;
printf ( L_26 ) ;
if ( V_4 -> V_32 != 0 )
printf ( L_27 , V_4 -> V_32 ) ;
#endif
}
if ( V_12 )
{
if ( ! F_21 ( V_4 , & V_5 ) )
{
F_11 ( V_20 ) ;
goto V_24;
}
if ( V_5 & V_33 )
printf ( L_28 ) ;
if ( V_5 & V_34 )
printf ( L_29 ) ;
if ( V_5 & V_35 )
printf ( L_30 ) ;
if ( V_5 & V_36 )
printf ( L_31 ) ;
if ( V_5 == 0 )
printf ( L_32 ) ;
}
if ( V_14 )
{
unsigned char * V_37 ;
int V_38 , V_39 , V_40 ;
V_38 = F_22 ( V_4 -> V_30 ) ;
V_40 = F_23 ( V_4 -> V_30 ) ;
V_37 = ( unsigned char * ) F_24 ( V_38 ) ;
if ( V_37 == NULL )
{
perror ( L_33 ) ;
goto V_24;
}
V_39 = F_25 ( V_4 -> V_30 , V_37 ) ;
printf ( L_34 , V_40 ) ;
for ( V_5 = 0 ; V_5 < V_39 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_35 ) ;
printf ( L_36 , V_37 [ V_5 ] ) ;
}
printf ( L_37 ) ;
V_39 = F_25 ( V_4 -> V_31 , V_37 ) ;
printf ( L_38 , V_40 ) ;
for ( V_5 = 0 ; V_5 < V_39 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_35 ) ;
printf ( L_36 , V_37 [ V_5 ] ) ;
}
printf ( L_39 ) ;
printf ( L_40 , V_40 ) ;
printf ( L_41 ) ;
printf ( L_42 ) ;
printf ( L_43 ,
V_40 , V_40 ) ;
printf ( L_44 ,
V_40 , V_40 ) ;
printf ( L_45 ) ;
printf ( L_46 ) ;
printf ( L_47 ) ;
F_26 ( V_37 ) ;
}
if ( ! V_13 )
{
if ( V_11 == V_29 )
V_5 = F_27 ( V_9 , V_4 ) ;
else if ( V_11 == V_25 )
V_5 = F_28 ( V_9 , V_4 ) ;
else {
F_8 ( V_20 , L_48 ) ;
goto V_24;
}
if ( ! V_5 )
{
F_8 ( V_20 , L_49 ) ;
F_11 ( V_20 ) ;
goto V_24;
}
}
V_15 = 0 ;
V_24:
if ( V_8 != NULL ) F_29 ( V_8 ) ;
if ( V_9 != NULL ) F_30 ( V_9 ) ;
if ( V_4 != NULL ) F_31 ( V_4 ) ;
F_32 () ;
F_33 ( V_15 ) ;
}
