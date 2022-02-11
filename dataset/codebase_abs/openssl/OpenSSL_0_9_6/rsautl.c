int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
char * V_5 = NULL , * V_6 = NULL ;
char * V_7 = NULL ;
char V_8 = V_9 , V_10 = V_11 ;
int V_12 = V_13 ;
char V_14 = 0 , V_15 = 0 , V_16 = 0 ;
char V_17 = 0 , V_18 = 0 ;
T_2 * V_19 ;
T_3 * V_20 = NULL ;
T_4 * V_21 = NULL ;
unsigned char * V_22 = NULL , * V_23 = NULL , V_24 ;
int V_25 , V_26 = 0 ;
int V_27 ;
int V_28 = 1 ;
V_1 -- ;
V_2 ++ ;
if( ! V_29 ) V_29 = F_1 ( V_30 , V_31 ) ;
F_2 () ;
F_3 () ;
V_24 = V_32 ;
while( V_1 >= 1 )
{
if ( ! strcmp ( * V_2 , L_1 ) ) {
if ( -- V_1 < 1 ) V_15 = 1 ;
V_5 = * ( ++ V_2 ) ;
} else if ( ! strcmp ( * V_2 , L_2 ) ) {
if ( -- V_1 < 1 ) V_15 = 1 ;
V_6 = * ( ++ V_2 ) ;
} else if( ! strcmp ( * V_2 , L_3 ) ) {
if ( -- V_1 < 1 ) V_15 = 1 ;
V_7 = * ( ++ V_2 ) ;
} else if( ! strcmp ( * V_2 , L_4 ) ) {
V_10 = V_33 ;
} else if( ! strcmp ( * V_2 , L_5 ) ) {
V_10 = V_34 ;
}
else if( ! strcmp ( * V_2 , L_6 ) ) V_18 = 1 ;
else if( ! strcmp ( * V_2 , L_7 ) ) V_17 = 1 ;
else if( ! strcmp ( * V_2 , L_8 ) ) V_24 = V_35 ;
else if( ! strcmp ( * V_2 , L_9 ) ) V_24 = V_36 ;
else if( ! strcmp ( * V_2 , L_10 ) ) V_24 = V_37 ;
else if( ! strcmp ( * V_2 , L_11 ) ) V_24 = V_32 ;
else if( ! strcmp ( * V_2 , L_12 ) ) {
V_8 = V_38 ;
V_14 = 1 ;
} else if( ! strcmp ( * V_2 , L_13 ) ) V_8 = V_9 ;
else if( ! strcmp ( * V_2 , L_14 ) ) V_16 = 1 ;
else if( ! strcmp ( * V_2 , L_15 ) ) V_8 = V_39 ;
else if( ! strcmp ( * V_2 , L_16 ) ) {
V_8 = V_40 ;
V_14 = 1 ;
} else V_15 = 1 ;
if( V_15 ) {
F_4 () ;
goto V_41;
}
V_1 -- ;
V_2 ++ ;
}
if( V_14 && ( V_10 != V_11 ) ) {
F_5 ( V_29 , L_17 ) ;
goto V_41;
}
F_6 ( NULL , V_29 , 0 ) ;
switch( V_10 ) {
case V_11 :
V_20 = F_7 ( V_29 , V_7 , V_12 , NULL ) ;
break;
case V_33 :
V_20 = F_8 ( V_29 , V_7 , V_12 ) ;
break;
case V_34 :
V_19 = F_9 ( V_29 , V_7 , V_12 ) ;
if( V_19 ) {
V_20 = F_10 ( V_19 ) ;
F_11 ( V_19 ) ;
}
break;
}
if( ! V_20 ) {
F_5 ( V_29 , L_18 ) ;
return 1 ;
}
V_21 = F_12 ( V_20 ) ;
F_13 ( V_20 ) ;
if( ! V_21 ) {
F_5 ( V_29 , L_19 ) ;
F_14 ( V_29 ) ;
goto V_41;
}
if( V_5 ) {
if( ! ( V_3 = F_15 ( V_5 , L_20 ) ) ) {
F_5 ( V_29 , L_21 ) ;
F_14 ( V_29 ) ;
goto V_41;
}
} else V_3 = F_1 ( V_42 , V_31 ) ;
if( V_6 ) {
if( ! ( V_4 = F_15 ( V_6 , L_22 ) ) ) {
F_5 ( V_29 , L_23 ) ;
F_14 ( V_29 ) ;
goto V_41;
}
} else {
V_4 = F_1 ( stdout , V_31 ) ;
#ifdef F_16
{
T_1 * V_43 = F_17 ( F_18 () ) ;
V_4 = F_19 ( V_43 , V_4 ) ;
}
#endif
}
V_27 = F_20 ( V_21 ) ;
V_22 = F_21 ( V_27 * 2 ) ;
V_23 = F_21 ( V_27 ) ;
V_25 = F_22 ( V_3 , V_22 , V_27 * 2 ) ;
if( V_25 <= 0 ) {
F_5 ( V_29 , L_24 ) ;
exit ( 1 ) ;
}
if( V_16 ) {
int V_44 ;
unsigned char V_45 ;
for( V_44 = 0 ; V_44 < V_25 / 2 ; V_44 ++ ) {
V_45 = V_22 [ V_44 ] ;
V_22 [ V_44 ] = V_22 [ V_25 - 1 - V_44 ] ;
V_22 [ V_25 - 1 - V_44 ] = V_45 ;
}
}
switch( V_8 ) {
case V_9 :
V_26 = F_23 ( V_25 , V_22 , V_23 , V_21 , V_24 ) ;
break;
case V_38 :
V_26 = F_24 ( V_25 , V_22 , V_23 , V_21 , V_24 ) ;
break;
case V_39 :
V_26 = F_25 ( V_25 , V_22 , V_23 , V_21 , V_24 ) ;
break;
case V_40 :
V_26 = F_26 ( V_25 , V_22 , V_23 , V_21 , V_24 ) ;
break;
}
if( V_26 <= 0 ) {
F_5 ( V_29 , L_25 ) ;
F_14 ( V_29 ) ;
goto V_41;
}
V_28 = 0 ;
if( V_18 ) {
if( ! F_27 ( V_4 , V_23 , V_26 , 1 , - 1 ) ) {
F_14 ( V_29 ) ;
}
} else if( V_17 ) F_28 ( V_4 , ( char * ) V_23 , V_26 ) ;
else F_29 ( V_4 , V_23 , V_26 ) ;
V_41:
F_30 ( V_21 ) ;
F_31 ( V_3 ) ;
F_32 ( V_4 ) ;
if( V_22 ) F_33 ( V_22 ) ;
if( V_23 ) F_33 ( V_23 ) ;
return V_28 ;
}
static void F_4 ()
{
F_5 ( V_29 , L_26 ) ;
F_5 ( V_29 , L_27 ) ;
F_5 ( V_29 , L_28 ) ;
F_5 ( V_29 , L_29 ) ;
F_5 ( V_29 , L_30 ) ;
F_5 ( V_29 , L_31 ) ;
F_5 ( V_29 , L_32 ) ;
F_5 ( V_29 , L_33 ) ;
F_5 ( V_29 , L_34 ) ;
F_5 ( V_29 , L_35 ) ;
F_5 ( V_29 , L_36 ) ;
F_5 ( V_29 , L_37 ) ;
F_5 ( V_29 , L_38 ) ;
F_5 ( V_29 , L_39 ) ;
F_5 ( V_29 , L_40 ) ;
}
