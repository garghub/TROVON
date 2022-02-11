int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * * args , * V_4 = NULL ;
char * V_5 = NULL ;
T_2 * V_6 = NULL , * V_7 = NULL ;
const T_3 * V_8 = NULL ;
int V_9 ;
int V_10 = 0 ;
T_4 * V_11 = NULL ;
T_5 * V_12 = NULL ;
char * V_13 = NULL ;
int V_14 = 0 ;
int V_15 = 1 , V_16 ;
int V_17 = 0 ;
if ( V_18 == NULL )
V_18 = F_1 ( V_19 , V_20 ) ;
if ( ! F_2 ( V_18 , NULL ) )
goto V_21;
V_9 = V_22 ;
F_3 () ;
F_4 () ;
args = V_2 + 1 ;
while ( ! V_14 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_9 = F_5 ( * args ) ;
} else
V_14 = 1 ;
} else if ( ! strcmp ( * args , L_2 ) ) {
if ( ! args [ 1 ] )
goto V_23;
V_5 = * ( ++ args ) ;
}
#ifndef F_6
else if ( strcmp ( * args , L_3 ) == 0 ) {
if ( ! args [ 1 ] )
goto V_23;
V_3 = F_7 ( V_18 , * ( ++ args ) , 0 ) ;
}
#endif
else if ( ! strcmp ( * args , L_4 ) ) {
if ( ! args [ 1 ] )
goto V_23;
args ++ ;
if ( V_17 == 1 )
goto V_23;
if ( ! F_8 ( V_18 , & V_12 , * args , V_3 ) )
goto V_21;
} else if ( ! strcmp ( * args , L_5 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else
V_14 = 1 ;
} else if ( strcmp ( * args , L_6 ) == 0 ) {
if ( ! args [ 1 ] )
goto V_23;
if ( ! F_9 ( V_18 , & V_12 , * ( ++ args ) , V_3 , V_17 ) )
goto V_21;
} else if ( strcmp ( * args , L_7 ) == 0 ) {
if ( ! args [ 1 ] )
goto V_23;
if ( ! V_12 ) {
F_10 ( V_18 , L_8 ) ;
goto V_23;
} else if ( F_11 ( V_12 , * ( ++ args ) ) <= 0 ) {
F_10 ( V_18 , L_9 ) ;
F_12 ( V_18 ) ;
goto V_21;
}
} else if ( strcmp ( * args , L_10 ) == 0 ) {
if ( V_12 )
goto V_23;
V_17 = 1 ;
} else if ( strcmp ( * args , L_11 ) == 0 )
V_10 = 1 ;
else {
V_8 = F_13 ( * args + 1 ) ;
if ( ! V_8 ) {
F_14 ( V_18 , L_12 , * args + 1 ) ;
V_14 = 1 ;
}
if ( V_17 == 1 )
V_14 = 1 ;
}
args ++ ;
}
if ( ! V_12 )
V_14 = 1 ;
if ( V_14 ) {
V_23:
F_14 ( V_18 , L_13 ) ;
F_14 ( V_18 , L_14 ) ;
F_14 ( V_18 , L_15 ) ;
F_14 ( V_18 ,
L_16 ) ;
F_14 ( V_18 ,
L_17 ) ;
F_14 ( V_18 ,
L_18 ) ;
#ifndef F_6
F_14 ( V_18 ,
L_19 ) ;
#endif
F_14 ( V_18 , L_20 ) ;
F_14 ( V_18 , L_21 ) ;
F_14 ( V_18 ,
L_22
L_23 ) ;
F_14 ( V_18 ,
L_24 ) ;
F_14 ( V_18 , L_25 ) ;
F_14 ( V_18 ,
L_26 ) ;
goto V_21;
}
if ( ! F_15 ( V_18 , V_5 , NULL , & V_13 , NULL ) ) {
F_10 ( V_18 , L_27 ) ;
goto V_21;
}
if ( V_4 ) {
if ( ! ( V_7 = F_16 ( V_4 , L_28 ) ) ) {
F_14 ( V_18 , L_29 , V_4 ) ;
goto V_21;
}
} else {
V_7 = F_1 ( stdout , V_20 ) ;
#ifdef F_17
{
T_2 * V_24 = F_18 ( F_19 () ) ;
V_7 = F_20 ( V_24 , V_7 ) ;
}
#endif
}
F_21 ( V_12 , V_25 ) ;
F_22 ( V_12 , V_18 ) ;
if ( V_17 ) {
if ( F_23 ( V_12 , & V_11 ) <= 0 ) {
F_10 ( V_18 , L_30 ) ;
F_12 ( V_18 ) ;
goto V_21;
}
} else {
if ( F_24 ( V_12 , & V_11 ) <= 0 ) {
F_10 ( V_18 , L_31 ) ;
F_12 ( V_18 ) ;
goto V_21;
}
}
if ( V_17 )
V_16 = F_25 ( V_7 , V_11 ) ;
else if ( V_9 == V_22 )
V_16 = F_26 ( V_7 , V_11 , V_8 , NULL , 0 , NULL , V_13 ) ;
else if ( V_9 == V_26 )
V_16 = F_27 ( V_7 , V_11 ) ;
else {
F_14 ( V_18 , L_32 ) ;
goto V_21;
}
if ( V_16 <= 0 ) {
F_10 ( V_18 , L_33 ) ;
F_12 ( V_18 ) ;
}
if ( V_10 ) {
if ( V_17 )
V_16 = F_28 ( V_7 , V_11 , 0 , NULL ) ;
else
V_16 = F_29 ( V_7 , V_11 , 0 , NULL ) ;
if ( V_16 <= 0 ) {
F_10 ( V_18 , L_34 ) ;
F_12 ( V_18 ) ;
}
}
V_15 = 0 ;
V_21:
if ( V_11 )
F_30 ( V_11 ) ;
if ( V_12 )
F_31 ( V_12 ) ;
if ( V_7 )
F_32 ( V_7 ) ;
F_33 ( V_6 ) ;
if ( V_13 )
F_34 ( V_13 ) ;
return V_15 ;
}
static int F_8 ( T_2 * V_27 , T_5 * * V_28 ,
const char * V_29 , T_1 * V_3 )
{
T_2 * V_30 ;
T_4 * V_11 = NULL ;
T_5 * V_12 = NULL ;
if ( * V_28 ) {
F_10 ( V_27 , L_35 ) ;
return 0 ;
}
V_30 = F_16 ( V_29 , L_36 ) ;
if ( ! V_30 ) {
F_14 ( V_27 , L_37 , V_29 ) ;
return 0 ;
}
V_11 = F_35 ( V_30 , NULL ) ;
F_33 ( V_30 ) ;
if ( ! V_11 ) {
F_14 ( V_18 , L_38 , V_29 ) ;
return 0 ;
}
V_12 = F_36 ( V_11 , V_3 ) ;
if ( ! V_12 )
goto V_27;
if ( F_37 ( V_12 ) <= 0 )
goto V_27;
F_30 ( V_11 ) ;
* V_28 = V_12 ;
return 1 ;
V_27:
F_10 ( V_27 , L_39 ) ;
F_12 ( V_27 ) ;
if ( V_12 )
F_31 ( V_12 ) ;
if ( V_11 )
F_30 ( V_11 ) ;
return 0 ;
}
int F_9 ( T_2 * V_27 , T_5 * * V_28 ,
const char * V_31 , T_1 * V_3 , int V_17 )
{
T_5 * V_12 = NULL ;
const T_6 * V_32 ;
T_1 * V_33 = NULL ;
int V_34 ;
if ( * V_28 ) {
F_10 ( V_27 , L_40 ) ;
return 0 ;
}
V_32 = F_38 ( & V_33 , V_31 , - 1 ) ;
#ifndef F_6
if ( ! V_32 && V_3 )
V_32 = F_39 ( V_3 , V_31 , - 1 ) ;
#endif
if ( ! V_32 ) {
F_14 ( V_18 , L_41 , V_31 ) ;
return 0 ;
}
F_40 () ;
F_41 ( & V_34 , NULL , NULL , NULL , NULL , V_32 ) ;
#ifndef F_6
if ( V_33 )
F_42 ( V_33 ) ;
#endif
V_12 = F_43 ( V_34 , V_3 ) ;
if ( ! V_12 )
goto V_27;
if ( V_17 ) {
if ( F_44 ( V_12 ) <= 0 )
goto V_27;
} else {
if ( F_37 ( V_12 ) <= 0 )
goto V_27;
}
* V_28 = V_12 ;
return 1 ;
V_27:
F_14 ( V_27 , L_42 , V_31 ) ;
F_12 ( V_27 ) ;
if ( V_12 )
F_31 ( V_12 ) ;
return 0 ;
}
static int V_25 ( T_5 * V_12 )
{
char V_35 = '*' ;
T_2 * V_36 = F_45 ( V_12 ) ;
int V_37 ;
V_37 = F_46 ( V_12 , 0 ) ;
if ( V_37 == 0 )
V_35 = '.' ;
if ( V_37 == 1 )
V_35 = '+' ;
if ( V_37 == 2 )
V_35 = '*' ;
if ( V_37 == 3 )
V_35 = '\n' ;
F_47 ( V_36 , & V_35 , 1 ) ;
( void ) F_48 ( V_36 ) ;
#ifdef F_49
V_37 = V_38 ;
#endif
return 1 ;
}
