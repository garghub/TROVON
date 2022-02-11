int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 ;
T_2 * V_6 = NULL , * V_7 = NULL ;
int V_8 , V_9 ;
char * V_10 , * V_11 , * V_12 ;
int V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 ;
int V_17 = 1 ;
#ifndef F_1
char * V_18 = NULL ;
#endif
F_2 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_19 , V_20 , V_21 | V_22 ) ;
if ( ! F_6 ( V_19 , NULL ) )
goto V_23;
V_10 = NULL ;
V_11 = NULL ;
V_8 = V_24 ;
V_9 = V_24 ;
V_12 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 ) {
if ( strcmp ( * V_2 , L_1 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_8 = F_7 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_2 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_9 = F_7 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_3 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_10 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_11 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_13 = 1 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_9 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_25;
V_18 = * ( ++ V_2 ) ;
}
#endif
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
F_8 ( V_19 , L_11 , V_12 ) ;
F_8 ( V_19 , L_12 ) ;
F_8 ( V_19 , L_13 ) ;
F_8 ( V_19 , L_14 ) ;
F_8 ( V_19 , L_15 ) ;
F_8 ( V_19 , L_16 ) ;
F_8 ( V_19 ,
L_17 ) ;
F_8 ( V_19 ,
L_18 ) ;
F_8 ( V_19 , L_19 ) ;
#ifndef F_1
F_8 ( V_19 ,
L_20 ) ;
#endif
V_17 = 1 ;
goto V_23;
}
F_9 () ;
#ifndef F_1
F_10 ( V_19 , V_18 , 0 ) ;
#endif
V_6 = F_3 ( F_4 () ) ;
V_7 = F_3 ( F_4 () ) ;
if ( ( V_6 == NULL ) || ( V_7 == NULL ) ) {
F_11 ( V_19 ) ;
goto V_23;
}
if ( V_10 == NULL )
F_5 ( V_6 , V_26 , V_21 ) ;
else {
if ( F_12 ( V_6 , V_10 ) <= 0 )
if ( V_6 == NULL ) {
perror ( V_10 ) ;
goto V_23;
}
}
if ( V_8 == V_27 )
V_3 = F_13 ( V_6 , NULL ) ;
else if ( V_8 == V_24 )
V_3 = F_14 ( V_6 , NULL , NULL , NULL ) ;
else {
F_8 ( V_19 , L_21 ) ;
goto V_23;
}
if ( V_3 == NULL ) {
F_8 ( V_19 , L_22 ) ;
F_11 ( V_19 ) ;
goto V_23;
}
if ( V_11 == NULL ) {
F_5 ( V_7 , stdout , V_21 ) ;
#ifdef F_15
{
T_2 * V_28 = F_3 ( F_16 () ) ;
V_7 = F_17 ( V_28 , V_7 ) ;
}
#endif
} else {
if ( F_18 ( V_7 , V_11 ) <= 0 ) {
perror ( V_11 ) ;
goto V_23;
}
}
if ( V_16 )
F_19 ( V_7 , V_3 , 0 , NULL ) ;
if ( V_13 ) {
F_20 ( V_29 ) * V_30 = NULL ;
F_20 ( V_31 ) * V_32 = NULL ;
V_4 = F_21 ( V_3 -> type ) ;
switch ( V_4 ) {
case V_33 :
V_30 = V_3 -> V_34 . V_35 -> V_36 ;
V_32 = V_3 -> V_34 . V_35 -> V_37 ;
break;
case V_38 :
V_30 = V_3 -> V_34 . V_39 -> V_36 ;
V_32 = V_3 -> V_34 . V_39 -> V_37 ;
break;
default:
break;
}
if ( V_30 != NULL ) {
V_29 * V_40 ;
for ( V_4 = 0 ; V_4 < F_22 ( V_30 ) ; V_4 ++ ) {
V_40 = F_23 ( V_30 , V_4 ) ;
if ( V_14 )
F_24 ( V_7 , V_40 ) ;
else
F_25 ( V_7 , V_40 ) ;
if ( ! V_15 )
F_26 ( V_7 , V_40 ) ;
F_27 ( V_7 , L_23 ) ;
}
}
if ( V_32 != NULL ) {
V_31 * V_37 ;
for ( V_4 = 0 ; V_4 < F_28 ( V_32 ) ; V_4 ++ ) {
V_37 = F_29 ( V_32 , V_4 ) ;
F_30 ( V_7 , V_37 ) ;
if ( ! V_15 )
F_31 ( V_7 , V_37 ) ;
F_27 ( V_7 , L_23 ) ;
}
}
V_17 = 0 ;
goto V_23;
}
if ( ! V_15 ) {
if ( V_9 == V_27 )
V_4 = F_32 ( V_7 , V_3 ) ;
else if ( V_9 == V_24 )
V_4 = F_33 ( V_7 , V_3 ) ;
else {
F_8 ( V_19 , L_24 ) ;
goto V_23;
}
if ( ! V_4 ) {
F_8 ( V_19 , L_25 ) ;
F_11 ( V_19 ) ;
goto V_23;
}
}
V_17 = 0 ;
V_23:
if ( V_3 != NULL )
F_34 ( V_3 ) ;
if ( V_6 != NULL )
F_35 ( V_6 ) ;
if ( V_7 != NULL )
F_36 ( V_7 ) ;
F_37 () ;
F_38 ( V_17 ) ;
}
