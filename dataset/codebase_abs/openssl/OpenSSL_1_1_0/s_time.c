static double F_1 ( int V_1 )
{
return F_2 ( V_1 , 1 ) ;
}
int F_3 ( int V_2 , char * * V_3 )
{
char V_4 [ 1024 * 8 ] ;
T_1 * V_5 = NULL ;
T_2 * V_6 = NULL ;
const T_3 * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL , * V_10 = NULL , * V_11 = NULL ;
char * V_12 = V_13 , * V_14 = NULL , * V_15 = NULL , * V_16 ;
double V_17 = 0.0 ;
int V_18 = 0 , V_19 = 0 ;
int V_20 = V_21 , V_22 = 0 , V_23 = 3 , V_24 = 1 , V_25 , V_26 = 0 ;
long V_27 = 0 , V_28 = 0 ;
T_4 V_29 ;
int V_30 = 0 , V_31 , V_32 ;
T_5 V_33 ;
V_7 = F_4 () ;
V_16 = F_5 ( V_2 , V_3 , V_34 ) ;
while ( ( V_29 = F_6 () ) != V_35 ) {
switch ( V_29 ) {
case V_35 :
case V_36 :
V_37:
F_7 ( V_38 , L_1 , V_16 ) ;
goto V_39;
case V_40 :
F_8 ( V_34 ) ;
V_24 = 0 ;
goto V_39;
case V_41 :
V_12 = F_9 () ;
break;
case V_42 :
V_23 = 2 ;
break;
case V_43 :
V_23 = 1 ;
break;
case V_44 :
if ( ! F_10 ( F_9 () , & V_45 . V_46 ) )
goto V_37;
F_7 ( V_38 , L_2 ,
V_16 , V_45 . V_46 ) ;
break;
case V_47 :
V_14 = F_9 () ;
break;
case V_48 :
V_15 = F_9 () ;
break;
case V_49 :
V_8 = F_9 () ;
break;
case V_50 :
V_9 = F_9 () ;
break;
case V_51 :
V_18 = 1 ;
break;
case V_52 :
V_19 = 1 ;
break;
case V_53 :
V_10 = F_9 () ;
break;
case V_54 :
V_26 = 1 ;
break;
case V_55 :
if ( ! F_10 ( F_9 () , & V_20 ) )
goto V_37;
break;
case V_56 :
V_11 = F_9 () ;
V_33 = strlen ( V_11 ) + sizeof( V_57 ) - 2 ;
if ( V_33 > sizeof( V_4 ) ) {
F_7 ( V_38 , L_3 , V_16 ) ;
goto V_39;
}
break;
case V_58 :
V_30 = V_59 ;
break;
}
}
V_2 = F_11 () ;
if ( V_2 != 0 )
goto V_37;
if ( V_10 == NULL )
V_10 = getenv ( L_4 ) ;
if ( V_10 == NULL ) {
F_7 ( V_38 , L_5 ) ;
goto V_39;
}
if ( ( V_6 = F_12 ( V_7 ) ) == NULL )
goto V_39;
F_13 ( V_6 , 1 ) ;
if ( F_14 ( V_6 , V_30 ) == 0 )
goto V_39;
if ( V_26 )
F_15 ( V_6 , V_60 ) ;
if ( ! F_16 ( V_6 , V_10 ) )
goto V_39;
if ( ! F_17 ( V_6 , V_14 , V_15 ) )
goto V_39;
if ( ! F_18 ( V_6 , V_9 , V_8 , V_19 , V_18 ) ) {
F_19 ( V_38 ) ;
goto V_39;
}
if ( ! ( V_23 & 1 ) )
goto V_61;
printf ( L_6 , V_20 ) ;
V_27 = 0 ;
V_28 = ( long ) time ( NULL ) + V_20 ;
F_1 ( V_62 ) ;
for (; ; ) {
if ( V_28 < ( long ) time ( NULL ) )
break;
if ( ( V_5 = F_20 ( NULL , V_12 , V_6 ) ) == NULL )
goto V_39;
if ( V_11 != NULL ) {
V_32 = F_21 ( V_4 , sizeof V_4 ,
V_57 , V_11 ) ;
if ( F_22 ( V_5 , V_4 , V_32 ) <= 0 )
goto V_39;
while ( ( V_25 = F_23 ( V_5 , V_4 , sizeof( V_4 ) ) ) > 0 )
V_27 += V_25 ;
}
#ifdef F_24
F_25 ( V_5 , V_63 | V_64 ) ;
#else
F_26 ( V_5 ) ;
#endif
F_27 ( F_28 ( V_5 ) ) ;
V_22 += 1 ;
if ( F_29 ( V_5 ) )
V_31 = 'r' ;
else {
V_31 = F_30 ( V_5 ) ;
if ( V_31 == V_65 )
V_31 = 't' ;
else if ( V_31 == V_59 )
V_31 = '3' ;
else
V_31 = '*' ;
}
fputc ( V_31 , stdout ) ;
fflush ( stdout ) ;
F_31 ( V_5 ) ;
V_5 = NULL ;
}
V_17 += F_1 ( V_66 ) ;
V_25 = ( int ) ( ( long ) time ( NULL ) - V_28 + V_20 ) ;
printf
( L_7 ,
V_22 , V_17 , ( ( double ) V_22 / V_17 ) , V_27 ) ;
printf
( L_8 ,
V_22 , ( long ) time ( NULL ) - V_28 + V_20 , V_27 / V_22 ) ;
V_61:
if ( ! ( V_23 & 2 ) )
goto V_39;
printf ( L_9 ) ;
if ( ( V_5 = F_20 ( NULL , V_12 , V_6 ) ) == NULL ) {
F_7 ( V_38 , L_10 ) ;
goto V_39;
}
if ( V_11 != NULL ) {
V_32 = F_21 ( V_4 , sizeof V_4 ,
V_57 , V_11 ) ;
if ( F_22 ( V_5 , V_4 , V_32 ) <= 0 )
goto V_39;
while ( F_23 ( V_5 , V_4 , sizeof( V_4 ) ) > 0 )
continue;
}
#ifdef F_24
F_25 ( V_5 , V_63 | V_64 ) ;
#else
F_26 ( V_5 ) ;
#endif
F_27 ( F_28 ( V_5 ) ) ;
V_22 = 0 ;
V_17 = 0.0 ;
V_28 = ( long ) time ( NULL ) + V_20 ;
printf ( L_11 ) ;
V_27 = 0 ;
F_1 ( V_62 ) ;
for (; ; ) {
if ( V_28 < ( long ) time ( NULL ) )
break;
if ( ( F_20 ( V_5 , V_12 , V_6 ) ) == NULL )
goto V_39;
if ( V_11 ) {
F_21 ( V_4 , sizeof V_4 , L_12 ,
V_11 ) ;
if ( F_22 ( V_5 , V_4 , strlen ( V_4 ) ) <= 0 )
goto V_39;
while ( ( V_25 = F_23 ( V_5 , V_4 , sizeof( V_4 ) ) ) > 0 )
V_27 += V_25 ;
}
#ifdef F_24
F_25 ( V_5 , V_63 | V_64 ) ;
#else
F_26 ( V_5 ) ;
#endif
F_27 ( F_28 ( V_5 ) ) ;
V_22 += 1 ;
if ( F_29 ( V_5 ) )
V_31 = 'r' ;
else {
V_31 = F_30 ( V_5 ) ;
if ( V_31 == V_65 )
V_31 = 't' ;
else if ( V_31 == V_59 )
V_31 = '3' ;
else
V_31 = '*' ;
}
fputc ( V_31 , stdout ) ;
fflush ( stdout ) ;
}
V_17 += F_1 ( V_66 ) ;
printf
( L_7 ,
V_22 , V_17 , ( ( double ) V_22 / V_17 ) , V_27 ) ;
printf
( L_8 ,
V_22 , ( long ) time ( NULL ) - V_28 + V_20 , V_27 / V_22 ) ;
V_24 = 0 ;
V_39:
F_31 ( V_5 ) ;
F_32 ( V_6 ) ;
return ( V_24 ) ;
}
static T_1 * F_20 ( T_1 * V_5 , const char * V_12 , T_2 * V_6 )
{
T_6 * V_67 ;
T_1 * V_68 ;
int V_69 , V_25 ;
T_7 V_70 ;
if ( ( V_67 = F_33 ( F_34 () ) ) == NULL )
return ( NULL ) ;
F_35 ( V_67 , V_12 ) ;
if ( V_5 == NULL )
V_68 = F_36 ( V_6 ) ;
else {
V_68 = V_5 ;
F_37 ( V_68 ) ;
}
F_38 ( V_68 , V_67 , V_67 ) ;
for (; ; ) {
V_25 = F_39 ( V_68 ) ;
if ( F_40 ( V_25 ) ) {
F_7 ( V_38 , L_13 ) ;
V_25 = F_28 ( V_68 ) ;
V_69 = V_25 + 1 ;
F_41 ( & V_70 ) ;
F_42 ( V_25 , & V_70 ) ;
F_43 ( V_69 , ( void * ) & V_70 , NULL , NULL , NULL ) ;
continue;
}
break;
}
if ( V_25 <= 0 ) {
F_7 ( V_38 , L_14 ) ;
if ( V_45 . error != V_71 )
F_7 ( V_38 , L_15 ,
F_44 ( V_45 . error ) ) ;
else
F_19 ( V_38 ) ;
if ( V_5 == NULL )
F_31 ( V_68 ) ;
return NULL ;
}
return V_68 ;
}
