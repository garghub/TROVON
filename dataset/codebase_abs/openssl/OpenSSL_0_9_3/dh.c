int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 , V_6 = 0 ;
T_2 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 , V_11 = 0 , V_12 = 0 , V_13 = 0 , V_14 = 1 ;
char * V_15 , * V_16 , * V_17 ;
F_1 () ;
if ( V_18 == NULL )
if ( ( V_18 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_18 , V_19 , V_20 | V_21 ) ;
V_15 = NULL ;
V_16 = NULL ;
V_9 = V_22 ;
V_10 = V_22 ;
V_17 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_9 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_11 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_12 = 1 ;
else
{
F_6 ( V_18 , L_9 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
V_23:
F_6 ( V_18 , L_10 , V_17 ) ;
F_6 ( V_18 , L_11 ) ;
F_6 ( V_18 , L_12 ) ;
F_6 ( V_18 , L_13 ) ;
F_6 ( V_18 , L_14 ) ;
F_6 ( V_18 , L_15 ) ;
F_6 ( V_18 , L_16 ) ;
F_6 ( V_18 , L_17 ) ;
F_6 ( V_18 , L_18 ) ;
F_6 ( V_18 , L_19 ) ;
goto V_24;
}
F_7 () ;
V_7 = F_2 ( F_3 () ) ;
V_8 = F_2 ( F_3 () ) ;
if ( ( V_7 == NULL ) || ( V_8 == NULL ) )
{
F_8 ( V_18 ) ;
goto V_24;
}
if ( V_15 == NULL )
F_4 ( V_7 , V_25 , V_20 ) ;
else
{
if ( F_9 ( V_7 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_24;
}
}
if ( V_16 == NULL )
F_4 ( V_8 , stdout , V_20 ) ;
else
{
if ( F_10 ( V_8 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_24;
}
}
if ( V_9 == V_26 )
V_3 = F_11 ( V_7 , NULL ) ;
else if ( V_9 == V_22 )
V_3 = F_12 ( V_7 , NULL , NULL ) ;
else
{
F_6 ( V_18 , L_20 ) ;
goto V_24;
}
if ( V_3 == NULL )
{
F_6 ( V_18 , L_21 ) ;
F_8 ( V_18 ) ;
goto V_24;
}
if ( V_6 )
{
F_13 ( V_8 , V_3 ) ;
#ifdef undef
printf ( L_22 ) ;
F_14 ( stdout , V_3 -> V_27 ) ;
printf ( L_23 ) ;
F_14 ( stdout , V_3 -> V_28 ) ;
printf ( L_24 ) ;
if ( V_3 -> V_29 != 0 )
printf ( L_25 , V_3 -> V_29 ) ;
#endif
}
if ( V_11 )
{
if ( ! F_15 ( V_3 , & V_4 ) )
{
F_8 ( V_18 ) ;
goto V_24;
}
if ( V_4 & V_30 )
printf ( L_26 ) ;
if ( V_4 & V_31 )
printf ( L_27 ) ;
if ( V_4 & V_32 )
printf ( L_28 ) ;
if ( V_4 & V_33 )
printf ( L_29 ) ;
if ( V_4 == 0 )
printf ( L_30 ) ;
}
if ( V_13 )
{
unsigned char * V_34 ;
int V_35 , V_36 , V_37 ;
V_35 = F_16 ( V_3 -> V_27 ) ;
V_37 = F_17 ( V_3 -> V_27 ) ;
V_34 = ( unsigned char * ) Malloc ( V_35 ) ;
if ( V_34 == NULL )
{
perror ( L_31 ) ;
goto V_24;
}
V_36 = F_18 ( V_3 -> V_27 , V_34 ) ;
printf ( L_32 , V_37 ) ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_33 ) ;
printf ( L_34 , V_34 [ V_4 ] ) ;
}
printf ( L_35 ) ;
V_36 = F_18 ( V_3 -> V_28 , V_34 ) ;
printf ( L_36 , V_37 ) ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_33 ) ;
printf ( L_34 , V_34 [ V_4 ] ) ;
}
printf ( L_37 ) ;
printf ( L_38 , V_37 ) ;
printf ( L_39 ) ;
printf ( L_40 ) ;
printf ( L_41 ,
V_37 , V_37 ) ;
printf ( L_42 ,
V_37 , V_37 ) ;
printf ( L_43 ) ;
printf ( L_44 ) ;
printf ( L_45 ) ;
}
if ( ! V_12 )
{
if ( V_10 == V_26 )
V_4 = F_19 ( V_8 , V_3 ) ;
else if ( V_10 == V_22 )
V_4 = F_20 ( V_8 , V_3 ) ;
else {
F_6 ( V_18 , L_46 ) ;
goto V_24;
}
if ( ! V_4 )
{
F_6 ( V_18 , L_47 ) ;
F_8 ( V_18 ) ;
goto V_24;
}
}
V_14 = 0 ;
V_24:
if ( V_7 != NULL ) F_21 ( V_7 ) ;
if ( V_8 != NULL ) F_21 ( V_8 ) ;
if ( V_3 != NULL ) F_22 ( V_3 ) ;
EXIT ( V_14 ) ;
}
