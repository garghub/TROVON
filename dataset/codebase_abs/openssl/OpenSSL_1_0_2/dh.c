int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 , V_6 = 0 ;
T_2 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 , V_11 = 0 , V_12 = 0 , V_13 = 0 , V_14 = 1 ;
char * V_15 , * V_16 , * V_17 ;
# ifndef F_1
char * V_18 ;
# endif
F_2 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_19 , V_20 , V_21 | V_22 ) ;
if ( ! F_6 ( V_19 , NULL ) )
goto V_23;
# ifndef F_1
V_18 = NULL ;
# endif
V_15 = NULL ;
V_16 = NULL ;
V_9 = V_24 ;
V_10 = V_24 ;
V_17 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 ) {
if ( strcmp ( * V_2 , L_1 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_9 = F_7 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_2 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_10 = F_7 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_3 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_15 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_16 = * ( ++ V_2 ) ;
}
# ifndef F_1
else if ( strcmp ( * V_2 , L_5 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_18 = * ( ++ V_2 ) ;
}
# endif
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_11 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_12 = 1 ;
else {
F_8 ( V_19 , L_10 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 ) {
V_25:
F_8 ( V_19 , L_11 , V_17 ) ;
F_8 ( V_19 , L_12 ) ;
F_8 ( V_19 , L_13 ) ;
F_8 ( V_19 ,
L_14 ) ;
F_8 ( V_19 , L_15 ) ;
F_8 ( V_19 , L_16 ) ;
F_8 ( V_19 , L_17 ) ;
F_8 ( V_19 ,
L_18 ) ;
F_8 ( V_19 , L_19 ) ;
F_8 ( V_19 , L_20 ) ;
# ifndef F_1
F_8 ( V_19 ,
L_21 ) ;
# endif
goto V_23;
}
F_9 () ;
# ifndef F_1
F_10 ( V_19 , V_18 , 0 ) ;
# endif
V_7 = F_3 ( F_4 () ) ;
V_8 = F_3 ( F_4 () ) ;
if ( ( V_7 == NULL ) || ( V_8 == NULL ) ) {
F_11 ( V_19 ) ;
goto V_23;
}
if ( V_15 == NULL )
F_5 ( V_7 , V_26 , V_21 ) ;
else {
if ( F_12 ( V_7 , V_15 ) <= 0 ) {
perror ( V_15 ) ;
goto V_23;
}
}
if ( V_16 == NULL ) {
F_5 ( V_8 , stdout , V_21 ) ;
# ifdef F_13
{
T_2 * V_27 = F_3 ( F_14 () ) ;
V_8 = F_15 ( V_27 , V_8 ) ;
}
# endif
} else {
if ( F_16 ( V_8 , V_16 ) <= 0 ) {
perror ( V_16 ) ;
goto V_23;
}
}
if ( V_9 == V_28 )
V_3 = F_17 ( V_7 , NULL ) ;
else if ( V_9 == V_24 )
V_3 = F_18 ( V_7 , NULL , NULL , NULL ) ;
else {
F_8 ( V_19 , L_22 ) ;
goto V_23;
}
if ( V_3 == NULL ) {
F_8 ( V_19 , L_23 ) ;
F_11 ( V_19 ) ;
goto V_23;
}
if ( V_6 ) {
F_19 ( V_8 , V_3 ) ;
# ifdef undef
printf ( L_24 ) ;
F_20 ( stdout , V_3 -> V_29 ) ;
printf ( L_25 ) ;
F_20 ( stdout , V_3 -> V_30 ) ;
printf ( L_26 ) ;
if ( V_3 -> V_31 != 0 )
printf ( L_27 , V_3 -> V_31 ) ;
# endif
}
if ( V_11 ) {
if ( ! F_21 ( V_3 , & V_4 ) ) {
F_11 ( V_19 ) ;
goto V_23;
}
if ( V_4 & V_32 )
printf ( L_28 ) ;
if ( V_4 & V_33 )
printf ( L_29 ) ;
if ( V_4 & V_34 )
printf ( L_30 ) ;
if ( V_4 & V_35 )
printf ( L_31 ) ;
if ( V_4 == 0 )
printf ( L_32 ) ;
}
if ( V_13 ) {
unsigned char * V_36 ;
int V_37 , V_38 , V_39 ;
V_37 = F_22 ( V_3 -> V_29 ) ;
V_39 = F_23 ( V_3 -> V_29 ) ;
V_36 = ( unsigned char * ) F_24 ( V_37 ) ;
if ( V_36 == NULL ) {
perror ( L_33 ) ;
goto V_23;
}
V_38 = F_25 ( V_3 -> V_29 , V_36 ) ;
printf ( L_34 , V_39 ) ;
for ( V_4 = 0 ; V_4 < V_38 ; V_4 ++ ) {
if ( ( V_4 % 12 ) == 0 )
printf ( L_35 ) ;
printf ( L_36 , V_36 [ V_4 ] ) ;
}
printf ( L_37 ) ;
V_38 = F_25 ( V_3 -> V_30 , V_36 ) ;
printf ( L_38 , V_39 ) ;
for ( V_4 = 0 ; V_4 < V_38 ; V_4 ++ ) {
if ( ( V_4 % 12 ) == 0 )
printf ( L_35 ) ;
printf ( L_36 , V_36 [ V_4 ] ) ;
}
printf ( L_39 ) ;
printf ( L_40 , V_39 ) ;
printf ( L_41 ) ;
printf ( L_42 ) ;
printf ( L_43 ,
V_39 , V_39 ) ;
printf ( L_44 ,
V_39 , V_39 ) ;
printf ( L_45 ) ;
printf ( L_46 ) ;
printf ( L_47 ) ;
F_26 ( V_36 ) ;
}
if ( ! V_12 ) {
if ( V_10 == V_28 )
V_4 = F_27 ( V_8 , V_3 ) ;
else if ( V_10 == V_24 )
V_4 = F_28 ( V_8 , V_3 ) ;
else {
F_8 ( V_19 , L_48 ) ;
goto V_23;
}
if ( ! V_4 ) {
F_8 ( V_19 , L_49 ) ;
F_11 ( V_19 ) ;
goto V_23;
}
}
V_14 = 0 ;
V_23:
if ( V_7 != NULL )
F_29 ( V_7 ) ;
if ( V_8 != NULL )
F_30 ( V_8 ) ;
if ( V_3 != NULL )
F_31 ( V_3 ) ;
F_32 () ;
F_33 ( V_14 ) ;
}
