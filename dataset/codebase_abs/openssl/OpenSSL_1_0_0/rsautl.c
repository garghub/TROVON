int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL , * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL ;
#ifndef F_1
char * V_8 = NULL ;
#endif
char * V_9 = NULL ;
char V_10 = V_11 , V_12 = V_13 ;
int V_14 = V_15 ;
char V_16 = 0 , V_17 = 0 , V_18 = 0 ;
char V_19 = 0 , V_20 = 0 ;
T_3 * V_21 ;
T_4 * V_22 = NULL ;
T_5 * V_23 = NULL ;
unsigned char * V_24 = NULL , * V_25 = NULL , V_26 ;
char * V_27 = NULL , * V_28 = NULL ;
int V_29 , V_30 = 0 ;
int V_31 ;
int V_32 = 1 ;
V_1 -- ;
V_2 ++ ;
if( ! V_33 ) V_33 = F_2 ( V_34 , V_35 ) ;
if ( ! F_3 ( V_33 , NULL ) )
goto V_36;
F_4 () ;
F_5 () ;
V_26 = V_37 ;
while( V_1 >= 1 )
{
if ( ! strcmp ( * V_2 , L_1 ) ) {
if ( -- V_1 < 1 )
V_17 = 1 ;
else
V_6 = * ( ++ V_2 ) ;
} else if ( ! strcmp ( * V_2 , L_2 ) ) {
if ( -- V_1 < 1 )
V_17 = 1 ;
else
V_7 = * ( ++ V_2 ) ;
} else if( ! strcmp ( * V_2 , L_3 ) ) {
if ( -- V_1 < 1 )
V_17 = 1 ;
else
V_9 = * ( ++ V_2 ) ;
} else if ( ! strcmp ( * V_2 , L_4 ) ) {
if ( -- V_1 < 1 )
V_17 = 1 ;
else
V_27 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_5 ) == 0 ) {
if ( -- V_1 < 1 )
V_17 = 1 ;
else
V_14 = F_6 ( * ( ++ V_2 ) ) ;
#ifndef F_1
} else if( ! strcmp ( * V_2 , L_6 ) ) {
if ( -- V_1 < 1 )
V_17 = 1 ;
else
V_8 = * ( ++ V_2 ) ;
#endif
} else if( ! strcmp ( * V_2 , L_7 ) ) {
V_12 = V_38 ;
} else if( ! strcmp ( * V_2 , L_8 ) ) {
V_12 = V_39 ;
}
else if( ! strcmp ( * V_2 , L_9 ) ) V_20 = 1 ;
else if( ! strcmp ( * V_2 , L_10 ) ) V_19 = 1 ;
else if( ! strcmp ( * V_2 , L_11 ) ) V_26 = V_40 ;
else if( ! strcmp ( * V_2 , L_12 ) ) V_26 = V_41 ;
else if( ! strcmp ( * V_2 , L_13 ) ) V_26 = V_42 ;
else if( ! strcmp ( * V_2 , L_14 ) ) V_26 = V_37 ;
else if( ! strcmp ( * V_2 , L_15 ) ) V_26 = V_43 ;
else if( ! strcmp ( * V_2 , L_16 ) ) {
V_10 = V_44 ;
V_16 = 1 ;
} else if( ! strcmp ( * V_2 , L_17 ) ) V_10 = V_11 ;
else if( ! strcmp ( * V_2 , L_18 ) ) V_18 = 1 ;
else if( ! strcmp ( * V_2 , L_19 ) ) V_10 = V_45 ;
else if( ! strcmp ( * V_2 , L_20 ) ) {
V_10 = V_46 ;
V_16 = 1 ;
} else V_17 = 1 ;
if( V_17 ) {
F_7 () ;
goto V_36;
}
V_1 -- ;
V_2 ++ ;
}
if( V_16 && ( V_12 != V_13 ) ) {
F_8 ( V_33 , L_21 ) ;
goto V_36;
}
#ifndef F_1
V_3 = F_9 ( V_33 , V_8 , 0 ) ;
#endif
if( ! F_10 ( V_33 , V_27 , NULL , & V_28 , NULL ) ) {
F_8 ( V_33 , L_22 ) ;
goto V_36;
}
F_11 ( NULL , V_33 , 0 ) ;
switch( V_12 ) {
case V_13 :
V_22 = F_12 ( V_33 , V_9 , V_14 , 0 ,
V_28 , V_3 , L_23 ) ;
break;
case V_38 :
V_22 = F_13 ( V_33 , V_9 , V_14 , 0 ,
NULL , V_3 , L_24 ) ;
break;
case V_39 :
V_21 = F_14 ( V_33 , V_9 , V_14 ,
NULL , V_3 , L_25 ) ;
if( V_21 ) {
V_22 = F_15 ( V_21 ) ;
F_16 ( V_21 ) ;
}
break;
}
if( ! V_22 ) {
return 1 ;
}
V_23 = F_17 ( V_22 ) ;
F_18 ( V_22 ) ;
if( ! V_23 ) {
F_8 ( V_33 , L_26 ) ;
F_19 ( V_33 ) ;
goto V_36;
}
if( V_6 ) {
if( ! ( V_4 = F_20 ( V_6 , L_27 ) ) ) {
F_8 ( V_33 , L_28 ) ;
F_19 ( V_33 ) ;
goto V_36;
}
} else V_4 = F_2 ( V_47 , V_35 ) ;
if( V_7 ) {
if( ! ( V_5 = F_20 ( V_7 , L_29 ) ) ) {
F_8 ( V_33 , L_30 ) ;
F_19 ( V_33 ) ;
goto V_36;
}
} else {
V_5 = F_2 ( stdout , V_35 ) ;
#ifdef F_21
{
T_2 * V_48 = F_22 ( F_23 () ) ;
V_5 = F_24 ( V_48 , V_5 ) ;
}
#endif
}
V_31 = F_25 ( V_23 ) ;
V_24 = F_26 ( V_31 * 2 ) ;
V_25 = F_26 ( V_31 ) ;
V_29 = F_27 ( V_4 , V_24 , V_31 * 2 ) ;
if( V_29 <= 0 ) {
F_8 ( V_33 , L_31 ) ;
exit ( 1 ) ;
}
if( V_18 ) {
int V_49 ;
unsigned char V_50 ;
for( V_49 = 0 ; V_49 < V_29 / 2 ; V_49 ++ ) {
V_50 = V_24 [ V_49 ] ;
V_24 [ V_49 ] = V_24 [ V_29 - 1 - V_49 ] ;
V_24 [ V_29 - 1 - V_49 ] = V_50 ;
}
}
switch( V_10 ) {
case V_11 :
V_30 = F_28 ( V_29 , V_24 , V_25 , V_23 , V_26 ) ;
break;
case V_44 :
V_30 = F_29 ( V_29 , V_24 , V_25 , V_23 , V_26 ) ;
break;
case V_45 :
V_30 = F_30 ( V_29 , V_24 , V_25 , V_23 , V_26 ) ;
break;
case V_46 :
V_30 = F_31 ( V_29 , V_24 , V_25 , V_23 , V_26 ) ;
break;
}
if( V_30 <= 0 ) {
F_8 ( V_33 , L_32 ) ;
F_19 ( V_33 ) ;
goto V_36;
}
V_32 = 0 ;
if( V_20 ) {
if( ! F_32 ( V_5 , V_25 , V_30 , 1 , - 1 ) ) {
F_19 ( V_33 ) ;
}
} else if( V_19 ) F_33 ( V_5 , ( char * ) V_25 , V_30 ) ;
else F_34 ( V_5 , V_25 , V_30 ) ;
V_36:
F_35 ( V_23 ) ;
F_36 ( V_4 ) ;
F_37 ( V_5 ) ;
if( V_24 ) F_38 ( V_24 ) ;
if( V_25 ) F_38 ( V_25 ) ;
if( V_28 ) F_38 ( V_28 ) ;
return V_32 ;
}
static void F_7 ()
{
F_8 ( V_33 , L_33 ) ;
F_8 ( V_33 , L_34 ) ;
F_8 ( V_33 , L_35 ) ;
F_8 ( V_33 , L_36 ) ;
F_8 ( V_33 , L_37 ) ;
F_8 ( V_33 , L_38 ) ;
F_8 ( V_33 , L_39 ) ;
F_8 ( V_33 , L_40 ) ;
F_8 ( V_33 , L_41 ) ;
F_8 ( V_33 , L_42 ) ;
F_8 ( V_33 , L_43 ) ;
F_8 ( V_33 , L_44 ) ;
F_8 ( V_33 , L_45 ) ;
F_8 ( V_33 , L_46 ) ;
F_8 ( V_33 , L_47 ) ;
F_8 ( V_33 , L_48 ) ;
#ifndef F_1
F_8 ( V_33 , L_49 ) ;
F_8 ( V_33 , L_50 ) ;
#endif
}
