static void F_1 ( int V_1 , const char * V_2 , ... ) {
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
vfprintf ( V_4 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
exit ( V_1 ) ;
}
static void F_2 ( int V_5 , const char * V_2 , ... ) {
T_1 V_3 ;
if ( V_5 <= V_6 ) {
va_start ( V_3 , V_2 ) ;
vfprintf ( V_4 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
fflush ( V_4 ) ;
}
}
static void F_3 ( int V_1 ) {
const char * V_7 = L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
;
F_1 ( V_1 , V_7 ) ;
}
static void F_4 ( T_2 * V_8 , const struct V_9 * V_10 , const T_2 * V_11 ) {
char V_12 [ V_13 ] ;
F_2 ( 2 , L_12 , V_14 ) ;
if ( V_14 ) {
F_2 ( 2 , L_13 ) ;
V_15 = 0 ;
} else {
if ( F_5 ( V_16 , & V_17 ) < 0 ) {
F_1 ( 23 , L_14 , F_6 ( V_16 ) ) ;
}
F_2 ( 2 , L_15 ) ;
if ( F_7 ( V_16 , 1 , V_12 ) < 0 ) {
F_1 ( 24 , L_16 , V_12 ) ;
}
F_2 ( 2 , L_17 ) ;
V_14 = 1 ;
}
}
static void F_8 ( T_2 * V_18 , const struct V_9 * V_10 , const T_2 * V_11 ) {
F_2 ( 4 , L_18 , V_14 ) ;
if ( V_14 ) {
V_19 ++ ;
F_9 ( V_18 , V_10 , V_11 ) ;
}
}
static void F_10 ( int V_20 ) {
V_15 = 0 ;
}
int main ( int V_21 , char * * V_22 ) {
char V_12 [ V_13 ] ;
char * V_23 = NULL ;
char * V_24 = NULL ;
T_3 V_25 = 65536 ;
char * V_26 = NULL ;
char * V_27 = NULL ;
char * V_28 = NULL ;
int V_29 = 0 ;
int V_30 = 0 ;
struct V_31 V_32 ;
struct V_31 V_33 ;
T_4 * V_34 = NULL ;
T_5 * V_18 = NULL ;
int V_35 ;
while ( ( V_35 = F_11 ( V_21 , V_22 , L_19 ) ) != - 1 ) {
switch ( V_35 ) {
case 'i' :
if ( V_23 ) F_1 ( 1 , L_20 ) ;
V_23 = F_12 ( V_36 ) ;
break;
case 'w' :
if ( V_24 ) F_1 ( 3 , L_21 ) ;
V_24 = F_12 ( V_36 ) ;
break;
case 's' :
V_25 = strtoul ( V_36 , NULL , 10 ) ;
if ( V_25 == 0 )
F_1 ( 4 , L_22 ) ;
break;
case 'b' :
if ( V_26 ) F_1 ( 5 , L_23 ) ;
V_26 = F_12 ( V_36 ) ;
break;
case 'e' :
if ( V_27 ) F_1 ( 6 , L_24 ) ;
V_27 = F_12 ( V_36 ) ;
break;
case 'f' :
if ( V_28 ) F_1 ( 7 , L_25 ) ;
V_28 = F_12 ( V_36 ) ;
break;
case 'p' :
V_29 = 1 ;
break;
case 'q' :
V_30 = 1 ;
break;
case 'd' :
V_6 ++ ;
break;
case 'h' :
default:
F_3 ( 0 ) ;
break;
}
}
F_2 ( 1 , L_26
L_27 ,
V_23 ? V_23 : L_28 ,
V_25 ,
V_29 ,
V_24 ? V_24 : L_29 ,
V_28 ? V_28 : L_30 ,
V_26 ? V_26 : L_29 ,
V_27 ? V_27 : L_29 ,
V_6 ) ;
if ( ! ( V_26 && V_27 && V_24 ) ) {
F_3 ( 10 ) ;
}
if ( ! V_23 ) {
V_23 = F_13 ( V_12 ) ;
if ( ! V_23 ) {
F_1 ( 11 , L_31 , V_12 ) ;
}
}
#ifdef F_14
if ( ! ( V_34 = F_15 ( V_23 , V_25 , V_29 , 1 , NULL , V_12 ) ) ) {
#else
if ( ! ( V_34 = F_16 ( V_23 , V_25 , V_29 , 1 , V_12 ) ) ) {
#endif
F_1 ( 12 , L_32 , V_23 , V_12 ) ;
}
F_2 ( 1 , L_33 , V_23 , V_25 , V_29 ) ;
if ( F_17 ( V_16 , & V_32 , V_26 , 1 , 0 ) < 0 ) {
F_1 ( 13 , L_34 , F_6 ( V_16 ) ) ;
}
F_2 ( 2 , L_35 , V_26 ) ;
if ( F_17 ( V_16 , & V_17 , V_27 , 1 , 0 ) < 0 ) {
F_1 ( 14 , L_36 , F_6 ( V_16 ) ) ;
}
F_2 ( 2 , L_37 , V_27 ) ;
#ifdef F_14
if ( ! ( V_34 = F_15 ( V_23 , V_25 , V_29 , 1 , NULL , V_12 ) ) ) {
#else
if ( ! ( V_34 = F_16 ( V_23 , V_25 , V_29 , 1 , V_12 ) ) ) {
#endif
F_1 ( 15 , L_38 , V_23 , V_12 ) ;
}
F_2 ( 1 , L_39 , V_23 , V_25 , V_29 ) ;
if ( V_28 ) {
if ( F_17 ( V_34 , & V_33 , V_28 , 1 , 0 ) < 0 ) {
F_1 ( 16 , L_40 , F_6 ( V_34 ) ) ;
}
if ( F_5 ( V_34 , & V_33 ) < 0 ) {
F_1 ( 17 , L_41 , F_6 ( V_34 ) ) ;
}
F_2 ( 2 , L_42 , V_28 ) ;
}
if ( F_5 ( V_16 , & V_32 ) < 0 ) {
F_1 ( 18 , L_43 , F_6 ( V_16 ) ) ;
}
F_2 ( 2 , L_44 ) ;
if ( F_7 ( V_16 , 0 , V_12 ) < 0 ) {
F_1 ( 19 , L_45 , V_12 ) ;
}
F_2 ( 2 , L_46 ) ;
if ( F_7 ( V_34 , 1 , V_12 ) < 0 ) {
F_1 ( 20 , L_47 , V_12 ) ;
}
F_2 ( 2 , L_48 ) ;
if ( ! ( V_18 = F_18 ( V_16 , V_24 ) ) ) {
F_1 ( 21 , L_49 , V_24 , F_6 ( V_16 ) ) ;
}
F_2 ( 2 , L_50 , V_24 ) ;
signal ( V_37 , F_10 ) ;
#ifdef F_19
signal ( F_19 , F_10 ) ;
#endif
#ifdef F_20
signal ( F_20 , F_10 ) ;
#endif
#ifdef F_21
signal ( F_21 , F_10 ) ;
#endif
V_15 = 1 ;
V_14 = 0 ;
do {
if ( F_22 ( V_16 , - 1 , F_4 , NULL ) < 0 ) {
F_1 ( 22 , L_51 , F_6 ( V_16 ) ) ;
}
if ( F_22 ( V_34 , - 1 , F_8 , ( void * ) V_18 ) < 0 ) {
F_1 ( 23 , L_52 , F_6 ( V_34 ) ) ;
}
} while( V_15 );
if ( ! V_30 ) {
printf ( L_53 , V_19 ) ;
}
F_2 ( 1 , L_54 ) ;
F_23 ( V_18 ) ;
F_24 ( V_16 ) ;
F_24 ( V_34 ) ;
return 0 ;
}
