int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL , * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL ;
char * V_8 = NULL ;
char * V_9 = NULL ;
char V_10 = V_11 , V_12 = V_13 ;
int V_14 = V_15 ;
char V_16 = 0 , V_17 = 0 , V_18 = 0 ;
char V_19 = 0 , V_20 = 0 ;
T_3 * V_21 ;
T_4 * V_22 = NULL ;
T_5 * V_23 = NULL ;
unsigned char * V_24 = NULL , * V_25 = NULL , V_26 ;
int V_27 , V_28 = 0 ;
int V_29 ;
int V_30 = 1 ;
V_1 -- ;
V_2 ++ ;
if( ! V_31 ) V_31 = F_1 ( V_32 , V_33 ) ;
if ( ! F_2 ( V_31 , NULL ) )
goto V_34;
F_3 () ;
F_4 () ;
V_26 = V_35 ;
while( V_1 >= 1 )
{
if ( ! strcmp ( * V_2 , L_1 ) ) {
if ( -- V_1 < 1 ) V_17 = 1 ;
V_6 = * ( ++ V_2 ) ;
} else if ( ! strcmp ( * V_2 , L_2 ) ) {
if ( -- V_1 < 1 ) V_17 = 1 ;
V_7 = * ( ++ V_2 ) ;
} else if( ! strcmp ( * V_2 , L_3 ) ) {
if ( -- V_1 < 1 ) V_17 = 1 ;
V_9 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
if ( -- V_1 < 1 ) V_17 = 1 ;
V_14 = F_5 ( * ( ++ V_2 ) ) ;
} else if( ! strcmp ( * V_2 , L_5 ) ) {
if ( -- V_1 < 1 ) V_17 = 1 ;
V_8 = * ( ++ V_2 ) ;
} else if( ! strcmp ( * V_2 , L_6 ) ) {
V_12 = V_36 ;
} else if( ! strcmp ( * V_2 , L_7 ) ) {
V_12 = V_37 ;
}
else if( ! strcmp ( * V_2 , L_8 ) ) V_20 = 1 ;
else if( ! strcmp ( * V_2 , L_9 ) ) V_19 = 1 ;
else if( ! strcmp ( * V_2 , L_10 ) ) V_26 = V_38 ;
else if( ! strcmp ( * V_2 , L_11 ) ) V_26 = V_39 ;
else if( ! strcmp ( * V_2 , L_12 ) ) V_26 = V_40 ;
else if( ! strcmp ( * V_2 , L_13 ) ) V_26 = V_35 ;
else if( ! strcmp ( * V_2 , L_14 ) ) {
V_10 = V_41 ;
V_16 = 1 ;
} else if( ! strcmp ( * V_2 , L_15 ) ) V_10 = V_11 ;
else if( ! strcmp ( * V_2 , L_16 ) ) V_18 = 1 ;
else if( ! strcmp ( * V_2 , L_17 ) ) V_10 = V_42 ;
else if( ! strcmp ( * V_2 , L_18 ) ) {
V_10 = V_43 ;
V_16 = 1 ;
} else V_17 = 1 ;
if( V_17 ) {
F_6 () ;
goto V_34;
}
V_1 -- ;
V_2 ++ ;
}
if( V_16 && ( V_12 != V_13 ) ) {
F_7 ( V_31 , L_19 ) ;
goto V_34;
}
V_3 = F_8 ( V_31 , V_8 , 0 ) ;
F_9 ( NULL , V_31 , 0 ) ;
switch( V_12 ) {
case V_13 :
V_22 = F_10 ( V_31 , V_9 , V_14 , 0 ,
NULL , V_3 , L_20 ) ;
break;
case V_36 :
V_22 = F_11 ( V_31 , V_9 , V_14 , 0 ,
NULL , V_3 , L_21 ) ;
break;
case V_37 :
V_21 = F_12 ( V_31 , V_9 , V_14 ,
NULL , V_3 , L_22 ) ;
if( V_21 ) {
V_22 = F_13 ( V_21 ) ;
F_14 ( V_21 ) ;
}
break;
}
if( ! V_22 ) {
return 1 ;
}
V_23 = F_15 ( V_22 ) ;
F_16 ( V_22 ) ;
if( ! V_23 ) {
F_7 ( V_31 , L_23 ) ;
F_17 ( V_31 ) ;
goto V_34;
}
if( V_6 ) {
if( ! ( V_4 = F_18 ( V_6 , L_24 ) ) ) {
F_7 ( V_31 , L_25 ) ;
F_17 ( V_31 ) ;
goto V_34;
}
} else V_4 = F_1 ( V_44 , V_33 ) ;
if( V_7 ) {
if( ! ( V_5 = F_18 ( V_7 , L_26 ) ) ) {
F_7 ( V_31 , L_27 ) ;
F_17 ( V_31 ) ;
goto V_34;
}
} else {
V_5 = F_1 ( stdout , V_33 ) ;
#ifdef F_19
{
T_2 * V_45 = F_20 ( F_21 () ) ;
V_5 = F_22 ( V_45 , V_5 ) ;
}
#endif
}
V_29 = F_23 ( V_23 ) ;
V_24 = F_24 ( V_29 * 2 ) ;
V_25 = F_24 ( V_29 ) ;
V_27 = F_25 ( V_4 , V_24 , V_29 * 2 ) ;
if( V_27 <= 0 ) {
F_7 ( V_31 , L_28 ) ;
exit ( 1 ) ;
}
if( V_18 ) {
int V_46 ;
unsigned char V_47 ;
for( V_46 = 0 ; V_46 < V_27 / 2 ; V_46 ++ ) {
V_47 = V_24 [ V_46 ] ;
V_24 [ V_46 ] = V_24 [ V_27 - 1 - V_46 ] ;
V_24 [ V_27 - 1 - V_46 ] = V_47 ;
}
}
switch( V_10 ) {
case V_11 :
V_28 = F_26 ( V_27 , V_24 , V_25 , V_23 , V_26 ) ;
break;
case V_41 :
V_28 = F_27 ( V_27 , V_24 , V_25 , V_23 , V_26 ) ;
break;
case V_42 :
V_28 = F_28 ( V_27 , V_24 , V_25 , V_23 , V_26 ) ;
break;
case V_43 :
V_28 = F_29 ( V_27 , V_24 , V_25 , V_23 , V_26 ) ;
break;
}
if( V_28 <= 0 ) {
F_7 ( V_31 , L_29 ) ;
F_17 ( V_31 ) ;
goto V_34;
}
V_30 = 0 ;
if( V_20 ) {
if( ! F_30 ( V_5 , V_25 , V_28 , 1 , - 1 ) ) {
F_17 ( V_31 ) ;
}
} else if( V_19 ) F_31 ( V_5 , ( char * ) V_25 , V_28 ) ;
else F_32 ( V_5 , V_25 , V_28 ) ;
V_34:
F_33 ( V_23 ) ;
F_34 ( V_4 ) ;
F_35 ( V_5 ) ;
if( V_24 ) F_36 ( V_24 ) ;
if( V_25 ) F_36 ( V_25 ) ;
return V_30 ;
}
static void F_6 ()
{
F_7 ( V_31 , L_30 ) ;
F_7 ( V_31 , L_31 ) ;
F_7 ( V_31 , L_32 ) ;
F_7 ( V_31 , L_33 ) ;
F_7 ( V_31 , L_34 ) ;
F_7 ( V_31 , L_35 ) ;
F_7 ( V_31 , L_36 ) ;
F_7 ( V_31 , L_37 ) ;
F_7 ( V_31 , L_38 ) ;
F_7 ( V_31 , L_39 ) ;
F_7 ( V_31 , L_40 ) ;
F_7 ( V_31 , L_41 ) ;
F_7 ( V_31 , L_42 ) ;
F_7 ( V_31 , L_43 ) ;
F_7 ( V_31 , L_44 ) ;
F_7 ( V_31 , L_45 ) ;
F_7 ( V_31 , L_46 ) ;
}
