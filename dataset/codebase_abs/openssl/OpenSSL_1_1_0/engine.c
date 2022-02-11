static int F_1 ( char * * V_1 , int * V_2 , const char * V_3 )
{
if ( * V_1 == NULL ) {
* V_2 = 256 ;
* V_1 = F_2 ( * V_2 , L_1 ) ;
* * V_1 = '\0' ;
}
if ( strlen ( * V_1 ) + strlen ( V_3 ) >= ( unsigned int ) * V_2 ) {
char * V_4 ;
* V_2 += 256 ;
V_4 = F_3 ( * V_1 , * V_2 ) ;
if ( V_4 == NULL ) {
F_4 ( * V_1 ) ;
* V_1 = NULL ;
return 0 ;
}
* V_1 = V_4 ;
}
if ( * * V_1 != '\0' )
F_5 ( * V_1 , L_2 , * V_2 ) ;
F_5 ( * V_1 , V_3 , * V_2 ) ;
return 1 ;
}
static int F_6 ( T_1 * V_5 , unsigned int V_6 , const char * V_7 )
{
int V_8 = 0 , V_9 = 0 ;
F_7 ( V_5 , L_3 , V_7 , V_7 ) ;
if ( V_6 == 0 ) {
F_7 ( V_5 , L_4 ) ;
return 1 ;
}
if ( V_6 & V_10 ) {
F_7 ( V_5 , L_5 ) ;
}
if ( V_6 & V_11 ) {
F_7 ( V_5 , L_6 ) ;
V_8 = 1 ;
}
if ( V_6 & V_12 ) {
if ( V_8 ) {
F_7 ( V_5 , L_7 ) ;
V_9 = 1 ;
}
F_7 ( V_5 , L_8 ) ;
V_8 = 1 ;
}
if ( V_6 & V_13 ) {
if ( V_8 ) {
F_7 ( V_5 , L_7 ) ;
V_9 = 1 ;
}
F_7 ( V_5 , L_9 ) ;
V_8 = 1 ;
}
V_6 = V_6 & ~ V_11 &
~ V_12 &
~ V_13 & ~ V_10 ;
if ( V_6 ) {
if ( V_8 )
F_7 ( V_5 , L_7 ) ;
F_7 ( V_5 , L_10 , V_6 ) ;
}
if ( V_9 )
F_7 ( V_5 , L_11 ) ;
F_7 ( V_5 , L_12 ) ;
return 1 ;
}
static int F_8 ( T_2 * V_14 , int V_15 , T_1 * V_5 , const char * V_7 )
{
static const int V_16 = 78 ;
int V_17 ;
int V_18 = 0 ;
char * V_19 = NULL ;
char * V_20 = NULL ;
int V_6 ;
int V_21 = 0 ;
F_9 ( V_22 ) * V_23 = NULL ;
if ( ! F_10 ( V_14 , V_24 , 0 , NULL , NULL ) ||
( ( V_17 = F_10 ( V_14 , V_25 ,
0 , NULL , NULL ) ) <= 0 ) ) {
return 1 ;
}
V_23 = F_11 () ;
if ( ! V_23 )
goto V_9;
do {
int V_26 ;
if ( ( V_6 = F_10 ( V_14 , V_27 , V_17 ,
NULL , NULL ) ) < 0 )
goto V_9;
if ( ! ( V_6 & V_10 ) || V_15 >= 4 ) {
if ( ( V_26 = F_10 ( V_14 , V_28 , V_17 ,
NULL , NULL ) ) <= 0 )
goto V_9;
V_19 = F_2 ( V_26 + 1 , L_13 ) ;
if ( F_10 ( V_14 , V_29 , V_17 , V_19 ,
NULL ) <= 0 )
goto V_9;
if ( ( V_26 = F_10 ( V_14 , V_30 , V_17 ,
NULL , NULL ) ) < 0 )
goto V_9;
if ( V_26 > 0 ) {
V_20 = F_2 ( V_26 + 1 , L_14 ) ;
if ( F_10 ( V_14 , V_31 , V_17 , V_20 ,
NULL ) <= 0 )
goto V_9;
}
if ( V_21 == 0 )
V_21 = F_12 ( V_5 , V_7 ) ;
else
V_21 += F_7 ( V_5 , L_2 ) ;
if ( V_15 == 1 ) {
if ( ( V_21 > ( int ) strlen ( V_7 ) ) &&
( V_21 + ( int ) strlen ( V_19 ) > V_16 ) ) {
F_7 ( V_5 , L_12 ) ;
V_21 = F_12 ( V_5 , V_7 ) ;
}
V_21 += F_7 ( V_5 , L_15 , V_19 ) ;
} else {
F_7 ( V_5 , L_16 , V_19 ,
( V_20 == NULL ) ? L_17 : V_20 ) ;
if ( ( V_15 >= 3 ) && ! F_6 ( V_5 , V_6 , V_7 ) )
goto V_9;
V_21 = 0 ;
}
}
F_4 ( V_19 ) ;
V_19 = NULL ;
F_4 ( V_20 ) ;
V_20 = NULL ;
V_17 = F_10 ( V_14 , V_32 , V_17 , NULL , NULL ) ;
} while ( V_17 > 0 );
if ( V_21 > 0 )
F_7 ( V_5 , L_12 ) ;
V_18 = 1 ;
V_9:
F_13 ( V_23 ) ;
F_4 ( V_19 ) ;
F_4 ( V_20 ) ;
return V_18 ;
}
int F_14 ( int V_33 , char * * V_34 )
{
int V_18 = 1 , V_35 ;
int V_15 = 0 , V_36 = 0 , V_37 = 0 , V_38 = 0 ;
T_2 * V_14 ;
F_9 ( V_39 ) * V_40 = F_15 () ;
F_9 ( V_22 ) * V_41 = F_11 () ;
F_9 ( V_22 ) * V_42 = F_11 () ;
T_1 * V_5 ;
const char * V_7 = L_18 ;
T_3 V_43 ;
char * V_44 ;
char * V_45 ;
V_5 = F_16 ( V_46 ) ;
if ( V_40 == NULL || V_41 == NULL || V_42 == NULL )
goto V_47;
V_44 = V_34 [ 0 ] ;
while ( ( V_45 = V_34 [ 1 ] ) != NULL && * V_45 != '-' ) {
F_17 ( V_40 , V_45 ) ;
V_33 -- ;
V_34 ++ ;
}
V_34 [ 0 ] = V_44 ;
F_18 ( V_33 , V_34 , V_48 ) ;
while ( ( V_43 = F_19 () ) != V_49 ) {
switch ( V_43 ) {
case V_49 :
case V_50 :
F_7 ( V_51 , L_19 , V_44 ) ;
goto V_47;
case V_52 :
F_20 ( V_48 ) ;
V_18 = 0 ;
goto V_47;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_35 = ( int ) ( V_43 - V_56 ) + 1 ;
if ( V_15 < V_35 )
V_15 = V_35 ;
break;
case V_57 :
V_36 = 1 ;
break;
case V_58 :
V_38 ++ ;
case V_59 :
V_37 ++ ;
break;
case V_60 :
F_21 ( V_41 , F_22 () ) ;
break;
case V_61 :
F_21 ( V_42 , F_22 () ) ;
break;
}
}
V_33 = F_23 () ;
V_34 = F_24 () ;
for ( ; * V_34 ; V_34 ++ ) {
if ( * * V_34 == '-' ) {
F_7 ( V_51 , L_20 ,
V_44 ) ;
F_7 ( V_51 , L_19 , V_44 ) ;
goto V_47;
}
F_17 ( V_40 , * V_34 ) ;
}
if ( F_25 ( V_40 ) == 0 ) {
for ( V_14 = F_26 () ; V_14 != NULL ; V_14 = F_27 ( V_14 ) ) {
F_17 ( V_40 , F_28 ( V_14 ) ) ;
}
}
V_18 = 0 ;
for ( V_35 = 0 ; V_35 < F_25 ( V_40 ) ; V_35 ++ ) {
const char * V_62 = F_29 ( V_40 , V_35 ) ;
if ( ( V_14 = F_30 ( V_62 ) ) != NULL ) {
const char * V_19 = F_31 ( V_14 ) ;
F_7 ( V_5 , L_21 , V_62 , V_19 ) ;
F_32 ( V_14 , V_41 , V_5 , V_7 ) ;
if ( strcmp ( F_28 ( V_14 ) , V_62 ) != 0 ) {
F_7 ( V_5 , L_22 ,
F_28 ( V_14 ) , F_31 ( V_14 ) ) ;
}
if ( V_36 ) {
int V_63 = 256 ;
char * V_64 = NULL ;
int V_65 , V_66 ;
const int * V_67 ;
T_4 V_68 ;
T_5 V_69 ;
T_6 V_70 ;
if ( F_33 ( V_14 ) != NULL
&& ! F_1 ( & V_64 , & V_63 , L_23 ) )
goto V_47;
if ( F_34 ( V_14 ) != NULL
&& ! F_1 ( & V_64 , & V_63 , L_24 ) )
goto V_47;
if ( F_35 ( V_14 ) != NULL
&& ! F_1 ( & V_64 , & V_63 , L_25 ) )
goto V_47;
if ( F_36 ( V_14 ) != NULL
&& ! F_1 ( & V_64 , & V_63 , L_26 ) )
goto V_47;
V_68 = F_37 ( V_14 ) ;
if ( ! V_68 )
goto V_71;
V_66 = V_68 ( V_14 , NULL , & V_67 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; ++ V_65 )
if ( ! F_1 ( & V_64 , & V_63 , F_38 ( V_67 [ V_65 ] ) ) )
goto V_47;
V_71:
V_69 = F_39 ( V_14 ) ;
if ( ! V_69 )
goto V_72;
V_66 = V_69 ( V_14 , NULL , & V_67 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; ++ V_65 )
if ( ! F_1 ( & V_64 , & V_63 , F_38 ( V_67 [ V_65 ] ) ) )
goto V_47;
V_72:
V_70 = F_40 ( V_14 ) ;
if ( ! V_70 )
goto V_73;
V_66 = V_70 ( V_14 , NULL , & V_67 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; ++ V_65 )
if ( ! F_1 ( & V_64 , & V_63 , F_38 ( V_67 [ V_65 ] ) ) )
goto V_47;
V_73:
if ( V_64 && ( * V_64 != '\0' ) )
F_7 ( V_5 , L_27 , V_64 ) ;
F_4 ( V_64 ) ;
}
if ( V_37 ) {
F_7 ( V_5 , L_15 , V_7 ) ;
if ( F_41 ( V_14 ) ) {
F_7 ( V_5 , L_28 ) ;
F_32 ( V_14 , V_42 , V_5 , V_7 ) ;
F_42 ( V_14 ) ;
} else {
F_7 ( V_5 , L_29 ) ;
if ( V_38 )
F_43 ( stdout ) ;
F_44 () ;
}
}
if ( ( V_15 > 0 ) && ! F_8 ( V_14 , V_15 , V_5 , V_7 ) )
goto V_47;
F_45 ( V_14 ) ;
} else {
F_46 ( V_51 ) ;
if ( ++ V_18 > 127 )
V_18 = 127 ;
}
}
V_47:
F_46 ( V_51 ) ;
F_47 ( V_40 ) ;
F_13 ( V_41 ) ;
F_13 ( V_42 ) ;
F_48 ( V_5 ) ;
return ( V_18 ) ;
}
