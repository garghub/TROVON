static void
F_1 ( T_1 * V_1 , T_1 * V_2 )
{
printf ( L_1
L_2
L_3
L_2
L_3
L_2
L_3 ,
F_2 () , F_3 () ,
V_1 -> V_3 , V_2 -> V_3 ) ;
}
static void
F_4 ( T_2 * V_4 )
{
fprintf ( V_4 , L_2 ) ;
fprintf ( V_4 , L_4 ) ;
}
static void
F_5 ( const char * T_3 V_5 , T_4 T_5 V_5 )
{
return;
}
static void
F_6 ( T_1 * V_3 )
{
F_7 ( V_3 , L_5 ) ;
#ifdef F_8
F_7 ( V_3 , L_6 ) ;
#ifdef F_9
F_7 ( V_3 , F_9 ) ;
#else
F_7 ( V_3 , L_7 ) ;
#endif
#else
F_7 ( V_3 , L_8 ) ;
#endif
}
static void
F_10 ( T_1 * V_3 )
{
#if F_11 ( F_8 ) && ! F_11 ( V_6 )
F_12 ( V_3 , L_9 , F_13 () ) ;
#endif
}
int
main ( int V_7 , char * V_8 [] )
{
T_1 * V_1 ;
T_1 * V_2 ;
T_6 * V_9 ;
int V_10 ;
T_7 * V_11 ;
int V_12 ;
int V_13 ;
int V_14 ;
static const struct V_15 V_16 [] = {
{ ( char * ) L_10 , V_17 , NULL , 'h' } ,
{ ( char * ) L_11 , V_17 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
#ifdef F_14
char * V_18 ;
#endif
V_1 = F_15 ( L_12 ) ;
F_16 ( V_1 , NULL , F_6 ) ;
V_2 = F_15 ( L_13 ) ;
F_17 ( V_2 , F_10 ) ;
F_18 ( L_1
L_2
L_3
L_2
L_3 ,
F_2 () , V_1 -> V_3 , V_2 -> V_3 ) ;
#ifdef V_6
F_19 ( V_7 , V_8 ) ;
F_20 () ;
#endif
F_21 () ;
F_22 () ;
#ifdef F_14
if ( ( V_18 = F_23 ( V_8 [ 0 ] , main ) ) ) {
F_24 ( L_14 , V_18 ) ;
F_25 ( V_18 ) ;
} else {
F_26 () ;
F_27 ( F_5 , NULL , NULL , NULL ) ;
F_28 () ;
F_29 () ;
}
#endif
while ( ( V_13 = F_30 ( V_7 , V_8 , L_15 , V_16 , NULL ) ) != - 1 ) {
switch ( V_13 ) {
case 'h' :
printf ( L_1
L_16
L_17 ,
F_2 () ) ;
F_4 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
F_1 ( V_1 , V_2 ) ;
F_31 ( V_1 , TRUE ) ;
F_31 ( V_2 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_4 ( V_19 ) ;
exit ( 1 ) ;
break;
}
}
setlocale ( V_20 , L_18 ) ;
if ( V_7 < 2 ) {
F_4 ( V_19 ) ;
return 1 ;
}
V_14 = 0 ;
for ( V_12 = 1 ; V_12 < V_7 ; V_12 ++ ) {
V_9 = F_32 ( V_8 [ V_12 ] , V_21 , & V_10 , & V_11 , FALSE ) ;
if( V_9 ) {
printf ( L_19 , V_8 [ V_12 ] , F_33 ( F_34 ( V_9 ) ) ) ;
F_35 ( V_9 ) ;
} else {
if ( V_10 == V_22 )
printf ( L_20 , V_8 [ V_12 ] ) ;
else {
fprintf ( V_19 , L_21 , V_8 [ V_12 ] ,
F_36 ( V_10 ) ) ;
switch ( V_10 ) {
case V_23 :
case V_24 :
case V_25 :
fprintf ( V_19 , L_22 , V_11 ) ;
F_25 ( V_11 ) ;
break;
}
V_14 = 1 ;
}
}
}
return V_14 ;
}
