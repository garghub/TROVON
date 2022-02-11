static void F_1 ( int V_1 )
{
V_2 = 1 ;
}
int F_2 ( int V_3 , char * * V_4 )
{
T_1 * V_5 = NULL ;
T_2 * V_6 = NULL , * V_7 = NULL ;
T_3 * V_8 = NULL ;
int V_9 = - 1 , V_10 = 0 , V_11 = 0 , V_12 = 0 ;
int V_13 = V_14 , V_15 = V_14 , V_16 = 0 , V_17 = 0 ;
int V_18 = 1 , V_19 , V_20 = 0 , V_21 = 0 ;
# ifdef F_3
int V_22 = 0 ;
# endif
char * V_23 = NULL , * V_24 = NULL , * V_25 , * V_26 = NULL ;
T_4 V_27 ;
V_25 = F_4 ( V_3 , V_4 , V_28 ) ;
while ( ( V_27 = F_5 () ) != V_29 ) {
switch ( V_27 ) {
case V_29 :
case V_30 :
V_31:
F_6 ( V_32 , L_1 , V_25 ) ;
goto V_33;
case V_34 :
F_7 ( V_28 ) ;
V_18 = 0 ;
goto V_33;
case V_35 :
if ( ! F_8 ( F_9 () , V_36 , & V_13 ) )
goto V_31;
break;
case V_37 :
V_23 = F_9 () ;
break;
case V_38 :
if ( ! F_8 ( F_9 () , V_36 , & V_15 ) )
goto V_31;
break;
case V_39 :
V_24 = F_9 () ;
break;
case V_40 :
( void ) F_10 ( F_9 () , 0 ) ;
break;
case V_41 :
# ifdef F_3
V_22 = atoi ( F_9 () ) ;
break;
# endif
case V_42 :
V_20 = 1 ;
break;
case V_43 :
V_17 = 1 ;
break;
case V_44 :
V_11 = V_12 = 1 ;
break;
case V_45 :
V_26 = F_9 () ;
V_12 = 1 ;
break;
case V_46 :
V_16 = 1 ;
break;
}
}
V_3 = F_11 () ;
V_4 = F_12 () ;
if ( V_3 == 1 ) {
if ( ! F_13 ( V_4 [ 0 ] , & V_10 ) || V_10 < 0 )
goto V_33;
V_9 = V_10 ;
V_12 = 1 ;
}
V_21 = V_11 ? 1 : 0 ;
V_6 = F_14 ( V_23 , 'r' , V_13 ) ;
if ( V_6 == NULL )
goto V_33;
V_7 = F_15 ( V_24 , V_15 , V_21 ) ;
if ( V_7 == NULL )
goto V_33;
if ( V_12 ) {
F_16 ( NULL , ( V_26 != NULL ) ) ;
if ( V_26 != NULL )
F_6 ( V_32 , L_2 ,
F_17 ( V_26 ) ) ;
}
if ( V_9 > 0 ) {
V_8 = F_18 () ;
if ( V_8 == NULL ) {
F_6 ( V_32 , L_3 ) ;
goto V_33;
}
F_19 ( V_8 , V_47 , V_32 ) ;
assert ( V_12 ) ;
V_5 = F_20 () ;
if ( V_5 == NULL ) {
F_6 ( V_32 , L_4 ) ;
goto V_33;
}
F_6 ( V_32 , L_5 ,
V_10 ) ;
F_6 ( V_32 , L_6 ) ;
# ifdef F_3
if ( V_22 > 0 ) {
struct V_48 V_49 ;
V_49 . V_50 = F_1 ;
V_49 . V_51 = 0 ;
F_6 ( V_32 ,
L_7 ,
V_22 ) ;
if ( V_48 ( V_52 , & V_49 , NULL ) != 0 ) {
F_6 ( V_32 , L_8 ) ;
goto V_33;
}
F_21 ( V_22 ) ;
}
# endif
if ( ! F_22 ( V_5 , V_10 , NULL , 0 , NULL , NULL , V_8 ) ) {
# ifdef F_3
if ( V_2 ) {
F_6 ( V_32 , L_9 ) ;
V_18 = 0 ;
goto V_33;
}
# endif
F_23 ( V_32 ) ;
F_6 ( V_32 , L_10 ) ;
goto V_33;
}
} else if ( V_13 == V_53 )
V_5 = F_24 ( V_6 , NULL ) ;
else
V_5 = F_25 ( V_6 , NULL , NULL , NULL ) ;
if ( V_5 == NULL ) {
F_6 ( V_32 , L_11 ) ;
F_23 ( V_32 ) ;
goto V_33;
}
if ( V_20 ) {
F_26 ( V_7 , V_5 ) ;
}
if ( V_17 ) {
const T_5 * V_54 = NULL , * V_55 = NULL , * V_56 = NULL ;
unsigned char * V_57 ;
int V_58 , V_59 ;
F_27 ( V_5 , & V_54 , & V_55 , & V_56 ) ;
V_58 = F_28 ( V_54 ) ;
V_59 = F_29 ( V_54 ) ;
V_57 = F_30 ( V_58 + 20 , L_12 ) ;
F_6 ( V_60 , L_13 , V_59 ) ;
F_31 ( V_60 , V_54 , L_14 , V_58 , V_57 ) ;
F_31 ( V_60 , V_55 , L_15 , V_58 , V_57 ) ;
F_31 ( V_60 , V_56 , L_16 , V_58 , V_57 ) ;
F_6 ( V_60 , L_17
L_18 ) ;
F_6 ( V_60 , L_19
L_20 ) ;
F_6 ( V_60 , L_21 ,
V_59 , V_59 ) ;
F_6 ( V_60 , L_22 ,
V_59 , V_59 ) ;
F_6 ( V_60 , L_23 ,
V_59 , V_59 ) ;
F_6 ( V_60 , L_24
L_25
L_20
L_26
L_27 ) ;
F_32 ( V_57 ) ;
}
if ( ! V_16 ) {
if ( V_15 == V_53 )
V_19 = F_33 ( V_7 , V_5 ) ;
else
V_19 = F_34 ( V_7 , V_5 ) ;
if ( ! V_19 ) {
F_6 ( V_32 , L_28 ) ;
F_23 ( V_32 ) ;
goto V_33;
}
}
if ( V_11 ) {
T_1 * V_61 ;
assert ( V_12 ) ;
if ( ( V_61 = F_35 ( V_5 ) ) == NULL )
goto V_33;
if ( ! F_36 ( V_61 ) ) {
F_23 ( V_32 ) ;
F_37 ( V_61 ) ;
goto V_33;
}
assert ( V_21 ) ;
if ( V_15 == V_53 )
V_19 = F_38 ( V_7 , V_61 ) ;
else
V_19 = F_39 ( V_7 , V_61 , NULL , NULL , 0 , NULL ,
NULL ) ;
F_37 ( V_61 ) ;
}
if ( V_12 )
F_40 ( NULL ) ;
V_18 = 0 ;
V_33:
F_41 ( V_8 ) ;
F_42 ( V_6 ) ;
F_43 ( V_7 ) ;
F_37 ( V_5 ) ;
return ( V_18 ) ;
}
static int V_47 ( int V_54 , int V_62 , T_3 * V_8 )
{
char V_63 = '*' ;
if ( V_54 == 0 )
V_63 = '.' ;
if ( V_54 == 1 )
V_63 = '+' ;
if ( V_54 == 2 )
V_63 = '*' ;
if ( V_54 == 3 )
V_63 = '\n' ;
F_44 ( F_45 ( V_8 ) , & V_63 , 1 ) ;
( void ) F_46 ( F_45 ( V_8 ) ) ;
# ifdef F_3
if ( V_2 )
return 0 ;
# endif
return 1 ;
}
