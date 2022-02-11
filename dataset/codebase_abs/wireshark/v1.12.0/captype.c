static void
F_1 ( void )
{
fprintf ( V_1 , L_1
#ifdef F_2
L_2 F_2 L_3 V_2 L_4
#endif
L_5 , V_3 ) ;
fprintf ( V_1 , L_6 ) ;
fprintf ( V_1 , L_7 ) ;
fprintf ( V_1 , L_5 ) ;
fprintf ( V_1 , L_8 ) ;
}
static void
F_3 ( const char * T_1 V_4 , T_2 T_3 V_4 )
{
return;
}
int
main ( int V_5 , char * V_6 [] )
{
T_4 * V_7 ;
int V_8 ;
T_5 * V_9 ;
int V_10 ;
int V_11 ;
#ifdef F_4
char * V_12 ;
#endif
#ifdef F_5
F_6 ( V_5 , V_6 ) ;
F_7 () ;
#endif
F_8 () ;
F_9 () ;
#ifdef F_4
if ( ( V_12 = F_10 ( V_6 [ 0 ] , main ) ) ) {
F_11 ( L_9 , V_12 ) ;
F_12 ( V_12 ) ;
} else {
F_13 () ;
F_14 ( F_3 , NULL , NULL , NULL ) ;
F_15 () ;
F_16 () ;
}
#endif
setlocale ( V_13 , L_10 ) ;
if ( V_5 < 2 ) {
F_1 () ;
return 1 ;
}
V_11 = 0 ;
for ( V_10 = 1 ; V_10 < V_5 ; V_10 ++ ) {
V_7 = F_17 ( V_6 [ V_10 ] , V_14 , & V_8 , & V_9 , FALSE ) ;
if( V_7 ) {
printf ( L_11 , V_6 [ V_10 ] , F_18 ( F_19 ( V_7 ) ) ) ;
F_20 ( V_7 ) ;
} else {
if ( V_8 == V_15 )
printf ( L_12 , V_6 [ V_10 ] ) ;
else {
fprintf ( V_1 , L_13 , V_6 [ V_10 ] ,
F_21 ( V_8 ) ) ;
switch ( V_8 ) {
case V_16 :
case V_17 :
case V_18 :
fprintf ( V_1 , L_14 , V_9 ) ;
F_12 ( V_9 ) ;
break;
}
V_11 = 1 ;
}
}
}
return V_11 ;
}
