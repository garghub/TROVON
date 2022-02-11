static void
F_1 ( T_1 * V_1 )
{
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_2 ) ;
}
static void
F_2 ( const char * T_2 V_2 , T_3 T_4 V_2 )
{
return;
}
static void
F_3 ( T_5 * V_3 )
{
F_4 ( V_3 , L_3 ) ;
#ifdef F_5
F_4 ( V_3 , L_4 ) ;
#ifdef F_6
F_4 ( V_3 , F_6 ) ;
#else
F_4 ( V_3 , L_5 ) ;
#endif
#else
F_4 ( V_3 , L_6 ) ;
#endif
}
static void
F_7 ( T_5 * V_3 )
{
#if F_8 ( F_5 ) && ! F_8 ( V_4 )
F_9 ( V_3 , L_7 , F_10 () ) ;
#endif
}
int
main ( int V_5 , char * V_6 [] )
{
T_5 * V_7 ;
T_5 * V_8 ;
T_6 * V_9 ;
int V_10 ;
T_7 * V_11 ;
int V_12 ;
int V_13 ;
int V_14 ;
F_11 (cast-qual)
static const struct V_15 V_16 [] = {
{ ( char * ) L_8 , V_17 , NULL , 'h' } ,
{ ( char * ) L_9 , V_17 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_12 (cast-qual)
#ifdef F_13
char * V_18 ;
#endif
setlocale ( V_19 , L_10 ) ;
V_7 = F_14 ( NULL , F_3 ) ;
V_8 = F_15 ( F_7 ) ;
F_16 ( L_11
L_1
L_12
L_1
L_12 ,
F_17 () , V_7 -> V_3 , V_8 -> V_3 ) ;
#ifdef V_4
F_18 ( V_5 , V_6 ) ;
F_19 () ;
#endif
F_20 () ;
F_21 () ;
#ifdef F_13
if ( ( V_18 = F_22 ( V_6 [ 0 ] , ( void * )main ) ) ) {
F_23 ( L_13 , V_18 ) ;
F_24 ( V_18 ) ;
} else {
F_25 () ;
F_26 ( F_2 , NULL , NULL , NULL ) ;
F_27 () ;
F_28 () ;
}
#endif
while ( ( V_13 = F_29 ( V_5 , V_6 , L_14 , V_16 , NULL ) ) != - 1 ) {
switch ( V_13 ) {
case 'h' :
printf ( L_11
L_15
L_16 ,
F_17 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
F_30 ( L_17 , V_7 , V_8 ) ;
F_31 ( V_7 , TRUE ) ;
F_31 ( V_8 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_1 ( V_20 ) ;
exit ( 1 ) ;
break;
}
}
if ( V_5 < 2 ) {
F_1 ( V_20 ) ;
return 1 ;
}
V_14 = 0 ;
for ( V_12 = 1 ; V_12 < V_5 ; V_12 ++ ) {
V_9 = F_32 ( V_6 [ V_12 ] , V_21 , & V_10 , & V_11 , FALSE ) ;
if( V_9 ) {
printf ( L_18 , V_6 [ V_12 ] , F_33 ( F_34 ( V_9 ) ) ) ;
F_35 ( V_9 ) ;
} else {
if ( V_10 == V_22 )
printf ( L_19 , V_6 [ V_12 ] ) ;
else {
fprintf ( V_20 , L_20 , V_6 [ V_12 ] ,
F_36 ( V_10 ) ) ;
if ( V_11 != NULL ) {
fprintf ( V_20 , L_21 , V_11 ) ;
F_24 ( V_11 ) ;
}
V_14 = 1 ;
}
}
}
return V_14 ;
}
