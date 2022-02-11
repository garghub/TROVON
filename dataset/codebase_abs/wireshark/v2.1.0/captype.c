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
int
main ( int V_3 , char * V_4 [] )
{
T_5 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
int V_8 ;
T_7 * V_9 ;
int V_10 ;
int V_11 ;
int V_12 ;
static const struct V_13 V_14 [] = {
{ L_3 , V_15 , NULL , 'h' } ,
{ L_4 , V_15 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
#ifdef F_3
char * V_16 ;
#endif
setlocale ( V_17 , L_5 ) ;
V_5 = F_4 ( NULL , NULL ) ;
V_6 = F_5 ( NULL ) ;
F_6 ( L_6
L_1
L_7
L_1
L_7 ,
F_7 () , V_5 -> V_18 , V_6 -> V_18 ) ;
#ifdef F_8
F_9 ( V_3 , V_4 ) ;
F_10 () ;
#endif
F_11 () ;
F_12 () ;
#ifdef F_3
if ( ( V_16 = F_13 ( V_4 [ 0 ] , main ) ) ) {
F_14 ( L_8 , V_16 ) ;
F_15 ( V_16 ) ;
} else {
F_16 () ;
F_17 ( F_2 , NULL , NULL , NULL ) ;
F_18 () ;
F_19 () ;
}
#endif
while ( ( V_11 = F_20 ( V_3 , V_4 , L_9 , V_14 , NULL ) ) != - 1 ) {
switch ( V_11 ) {
case 'h' :
printf ( L_6
L_10
L_11 ,
F_7 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
F_21 ( L_12 , V_5 , V_6 ) ;
F_22 ( V_5 , TRUE ) ;
F_22 ( V_6 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_1 ( V_19 ) ;
exit ( 1 ) ;
break;
}
}
if ( V_3 < 2 ) {
F_1 ( V_19 ) ;
return 1 ;
}
V_12 = 0 ;
for ( V_10 = 1 ; V_10 < V_3 ; V_10 ++ ) {
V_7 = F_23 ( V_4 [ V_10 ] , V_20 , & V_8 , & V_9 , FALSE ) ;
if( V_7 ) {
printf ( L_13 , V_4 [ V_10 ] , F_24 ( F_25 ( V_7 ) ) ) ;
F_26 ( V_7 ) ;
} else {
if ( V_8 == V_21 )
printf ( L_14 , V_4 [ V_10 ] ) ;
else {
fprintf ( V_19 , L_15 , V_4 [ V_10 ] ,
F_27 ( V_8 ) ) ;
if ( V_9 != NULL ) {
fprintf ( V_19 , L_16 , V_9 ) ;
F_15 ( V_9 ) ;
}
V_12 = 1 ;
}
}
}
return V_12 ;
}
