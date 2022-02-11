int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
char * V_5 = NULL , * V_6 = NULL , * V_7 = NULL ;
T_2 * V_8 = NULL ;
int V_9 = V_10 , V_11 = V_12 ;
int V_13 = V_14 , V_15 = V_14 ;
char V_16 = 0 , V_17 = 0 ;
char V_18 = 0 , V_19 = 0 ;
T_3 * V_20 = NULL ;
char * V_21 = NULL ;
int V_22 = - 1 ;
unsigned char * V_23 = NULL , * V_24 = NULL , * V_25 = NULL ;
T_4 V_26 ;
int V_27 = 0 , V_28 = - 1 ;
int V_29 = 1 , V_30 = - 1 ;
V_1 -- ;
V_2 ++ ;
if ( ! V_31 )
V_31 = F_1 ( V_32 , V_33 ) ;
if ( ! F_2 ( V_31 , NULL ) )
goto V_34;
F_3 () ;
F_4 () ;
while ( V_1 >= 1 ) {
if ( ! strcmp ( * V_2 , L_1 ) ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else
V_5 = * ( ++ V_2 ) ;
} else if ( ! strcmp ( * V_2 , L_2 ) ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else
V_6 = * ( ++ V_2 ) ;
} else if ( ! strcmp ( * V_2 , L_3 ) ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else
V_7 = * ( ++ V_2 ) ;
} else if ( ! strcmp ( * V_2 , L_4 ) ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else {
V_20 = F_5 ( & V_22 ,
* ( ++ V_2 ) , V_13 , V_11 ,
V_21 , V_9 , V_8 ) ;
if ( ! V_20 ) {
F_6 ( V_31 , L_5 ) ;
F_7 ( V_31 ) ;
V_16 = 1 ;
}
}
} else if ( ! strcmp ( * V_2 , L_6 ) ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else if ( ! F_8 ( V_31 , V_20 , V_15 , * ( ++ V_2 ) ) )
V_16 = 1 ;
} else if ( ! strcmp ( * V_2 , L_7 ) ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else
V_21 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_8 ) == 0 ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else
V_15 = F_9 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_9 ) == 0 ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else
V_13 = F_9 ( * ( ++ V_2 ) ) ;
}
#ifndef F_10
else if ( ! strcmp ( * V_2 , L_10 ) ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else
V_8 = F_11 ( V_31 , * ( ++ V_2 ) , 0 ) ;
}
#endif
else if ( ! strcmp ( * V_2 , L_11 ) )
V_11 = V_35 ;
else if ( ! strcmp ( * V_2 , L_12 ) )
V_11 = V_36 ;
else if ( ! strcmp ( * V_2 , L_13 ) )
V_19 = 1 ;
else if ( ! strcmp ( * V_2 , L_14 ) )
V_18 = 1 ;
else if ( ! strcmp ( * V_2 , L_15 ) )
V_9 = V_10 ;
else if ( ! strcmp ( * V_2 , L_16 ) )
V_9 = V_37 ;
else if ( ! strcmp ( * V_2 , L_17 ) )
V_9 = V_38 ;
else if ( ! strcmp ( * V_2 , L_18 ) )
V_17 = 1 ;
else if ( ! strcmp ( * V_2 , L_19 ) )
V_9 = V_39 ;
else if ( ! strcmp ( * V_2 , L_20 ) )
V_9 = V_40 ;
else if ( ! strcmp ( * V_2 , L_21 ) )
V_9 = V_41 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 ) {
if ( -- V_1 < 1 )
V_16 = 1 ;
else if ( ! V_20 ) {
F_6 ( V_31 , L_23 ) ;
V_16 = 1 ;
} else if ( F_12 ( V_20 , * ( ++ V_2 ) ) <= 0 ) {
F_6 ( V_31 , L_24 ) ;
F_7 ( V_31 ) ;
goto V_34;
}
} else
V_16 = 1 ;
if ( V_16 ) {
F_13 () ;
goto V_34;
}
V_1 -- ;
V_2 ++ ;
}
if ( ! V_20 ) {
F_13 () ;
goto V_34;
}
if ( V_7 && ( V_9 != V_37 ) ) {
F_6 ( V_31 , L_25 ) ;
goto V_34;
}
if ( ! V_7 && ( V_9 == V_37 ) ) {
F_6 ( V_31 , L_26 ) ;
goto V_34;
}
F_14 ( NULL , V_31 , 0 ) ;
if ( V_9 != V_41 ) {
if ( V_5 ) {
if ( ! ( V_3 = F_15 ( V_5 , L_27 ) ) ) {
F_6 ( V_31 , L_28 ) ;
F_7 ( V_31 ) ;
goto V_34;
}
} else
V_3 = F_1 ( V_42 , V_33 ) ;
}
if ( V_6 ) {
if ( ! ( V_4 = F_15 ( V_6 , L_29 ) ) ) {
F_16 ( V_31 , L_30 ) ;
F_7 ( V_31 ) ;
goto V_34;
}
} else {
V_4 = F_1 ( stdout , V_33 ) ;
#ifdef F_17
{
T_1 * V_43 = F_18 ( F_19 () ) ;
V_4 = F_20 ( V_43 , V_4 ) ;
}
#endif
}
if ( V_7 ) {
T_1 * V_44 = F_15 ( V_7 , L_27 ) ;
if ( ! V_44 ) {
F_16 ( V_31 , L_31 , V_7 ) ;
goto V_34;
}
V_28 = F_21 ( & V_25 , V_22 * 10 , V_44 ) ;
F_22 ( V_44 ) ;
if ( V_28 <= 0 ) {
F_16 ( V_31 , L_32 ) ;
goto V_34;
}
}
if ( V_3 ) {
V_27 = F_21 ( & V_23 , V_22 * 10 , V_3 ) ;
if ( V_27 <= 0 ) {
F_16 ( V_31 , L_33 ) ;
exit ( 1 ) ;
}
if ( V_17 ) {
T_4 V_45 ;
unsigned char V_46 ;
T_4 V_47 = ( T_4 ) V_27 ;
for ( V_45 = 0 ; V_45 < V_47 / 2 ; V_45 ++ ) {
V_46 = V_23 [ V_45 ] ;
V_23 [ V_45 ] = V_23 [ V_47 - 1 - V_45 ] ;
V_23 [ V_47 - 1 - V_45 ] = V_46 ;
}
}
}
if ( V_9 == V_37 ) {
V_30 = F_23 ( V_20 , V_25 , ( T_4 ) V_28 ,
V_23 , ( T_4 ) V_27 ) ;
if ( V_30 == 0 )
F_6 ( V_4 , L_34 ) ;
else if ( V_30 == 1 )
F_6 ( V_4 , L_35 ) ;
if ( V_30 >= 0 )
goto V_34;
} else {
V_30 = F_24 ( V_20 , V_9 , NULL , ( T_4 * ) & V_26 ,
V_23 , ( T_4 ) V_27 ) ;
if ( V_30 > 0 ) {
V_24 = F_25 ( V_26 ) ;
if ( ! V_24 )
V_30 = - 1 ;
else
V_30 = F_24 ( V_20 , V_9 ,
V_24 , ( T_4 * ) & V_26 ,
V_23 , ( T_4 ) V_27 ) ;
}
}
if ( V_30 <= 0 ) {
F_16 ( V_31 , L_36 ) ;
F_7 ( V_31 ) ;
goto V_34;
}
V_29 = 0 ;
if ( V_19 ) {
if ( ! F_26 ( V_4 , V_24 , V_26 , 1 , - 1 ) )
F_7 ( V_31 ) ;
} else if ( V_18 )
F_27 ( V_4 , ( char * ) V_24 , V_26 ) ;
else
F_28 ( V_4 , V_24 , V_26 ) ;
V_34:
if ( V_20 )
F_29 ( V_20 ) ;
F_22 ( V_3 ) ;
F_30 ( V_4 ) ;
if ( V_23 )
F_31 ( V_23 ) ;
if ( V_24 )
F_31 ( V_24 ) ;
if ( V_25 )
F_31 ( V_25 ) ;
return V_29 ;
}
static void F_13 ()
{
F_16 ( V_31 , L_37 ) ;
F_16 ( V_31 , L_38 ) ;
F_16 ( V_31 , L_39 ) ;
F_16 ( V_31 ,
L_40 ) ;
F_16 ( V_31 , L_41 ) ;
F_16 ( V_31 , L_42 ) ;
F_16 ( V_31 , L_43 ) ;
F_16 ( V_31 ,
L_44 ) ;
F_16 ( V_31 , L_45 ) ;
F_16 ( V_31 , L_46 ) ;
F_16 ( V_31 , L_47 ) ;
F_16 ( V_31 ,
L_48 ) ;
F_16 ( V_31 , L_49 ) ;
F_16 ( V_31 , L_50 ) ;
F_16 ( V_31 , L_51 ) ;
F_16 ( V_31 , L_52 ) ;
#ifndef F_10
F_16 ( V_31 ,
L_53 ) ;
#endif
F_16 ( V_31 , L_54 ) ;
}
static T_3 * F_5 ( int * V_48 ,
char * V_49 , int V_13 , int V_11 ,
char * V_21 , int V_9 , T_2 * V_8 )
{
T_5 * V_50 = NULL ;
T_3 * V_20 = NULL ;
char * V_51 = NULL ;
int V_30 = - 1 ;
T_6 * V_52 ;
if ( ( ( V_9 == V_10 ) || ( V_9 == V_40 )
|| ( V_9 == V_41 ) )
&& ( V_11 != V_12 ) ) {
F_16 ( V_31 , L_55 ) ;
goto V_34;
}
if ( ! F_32 ( V_31 , V_21 , NULL , & V_51 , NULL ) ) {
F_16 ( V_31 , L_56 ) ;
goto V_34;
}
switch ( V_11 ) {
case V_12 :
V_50 = F_33 ( V_31 , V_49 , V_13 , 0 ,
V_51 , V_8 , L_57 ) ;
break;
case V_35 :
V_50 = F_34 ( V_31 , V_49 , V_13 , 0 ,
NULL , V_8 , L_58 ) ;
break;
case V_36 :
V_52 = F_35 ( V_31 , V_49 , V_13 , NULL , V_8 , L_59 ) ;
if ( V_52 ) {
V_50 = F_36 ( V_52 ) ;
F_37 ( V_52 ) ;
}
break;
}
* V_48 = F_38 ( V_50 ) ;
if ( ! V_50 )
goto V_34;
V_20 = F_39 ( V_50 , V_8 ) ;
F_40 ( V_50 ) ;
if ( ! V_20 )
goto V_34;
switch ( V_9 ) {
case V_10 :
V_30 = F_41 ( V_20 ) ;
break;
case V_37 :
V_30 = F_42 ( V_20 ) ;
break;
case V_38 :
V_30 = F_43 ( V_20 ) ;
break;
case V_39 :
V_30 = F_44 ( V_20 ) ;
break;
case V_40 :
V_30 = F_45 ( V_20 ) ;
break;
case V_41 :
V_30 = F_46 ( V_20 ) ;
break;
}
if ( V_30 <= 0 ) {
F_29 ( V_20 ) ;
V_20 = NULL ;
}
V_34:
if ( V_51 )
F_31 ( V_51 ) ;
return V_20 ;
}
static int F_8 ( T_1 * V_53 , T_3 * V_20 , int V_15 ,
const char * V_54 )
{
T_5 * V_55 = NULL ;
int V_29 ;
if ( ! V_20 ) {
F_6 ( V_53 , L_60 ) ;
return 0 ;
}
V_55 = F_34 ( V_31 , V_54 , V_15 , 0 , NULL , NULL , L_61 ) ;
if ( ! V_55 ) {
F_16 ( V_31 , L_62 , V_54 ) ;
F_7 ( V_53 ) ;
return 0 ;
}
V_29 = F_47 ( V_20 , V_55 ) ;
F_40 ( V_55 ) ;
if ( V_29 <= 0 )
F_7 ( V_53 ) ;
return V_29 ;
}
static int F_24 ( T_3 * V_20 , int V_9 ,
unsigned char * V_4 , T_4 * V_56 ,
unsigned char * V_3 , T_4 V_57 )
{
int V_30 = 0 ;
switch ( V_9 ) {
case V_38 :
V_30 = F_48 ( V_20 , V_4 , V_56 , V_3 , V_57 ) ;
break;
case V_10 :
V_30 = F_49 ( V_20 , V_4 , V_56 , V_3 , V_57 ) ;
break;
case V_39 :
V_30 = F_50 ( V_20 , V_4 , V_56 , V_3 , V_57 ) ;
break;
case V_40 :
V_30 = F_51 ( V_20 , V_4 , V_56 , V_3 , V_57 ) ;
break;
case V_41 :
V_30 = F_52 ( V_20 , V_4 , V_56 ) ;
break;
}
return V_30 ;
}
