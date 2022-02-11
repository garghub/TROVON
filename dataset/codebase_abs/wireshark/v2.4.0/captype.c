static void
F_1 ( T_1 * V_1 )
{
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_2 ) ;
}
static void
F_2 ( const char * V_2 , T_2 V_3 )
{
fprintf ( V_4 , L_3 ) ;
vfprintf ( V_4 , V_2 , V_3 ) ;
fprintf ( V_4 , L_1 ) ;
}
static void
F_3 ( const char * V_2 , T_2 V_3 )
{
vfprintf ( V_4 , V_2 , V_3 ) ;
fprintf ( V_4 , L_1 ) ;
}
int
main ( int V_5 , char * V_6 [] )
{
T_3 * V_7 ;
T_3 * V_8 ;
char * V_9 ;
T_4 * V_10 ;
int V_11 ;
T_5 * V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
static const struct V_16 V_17 [] = {
{ L_4 , V_18 , NULL , 'h' } ,
{ L_5 , V_18 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
setlocale ( V_19 , L_6 ) ;
F_4 ( F_2 , F_3 ) ;
V_7 = F_5 ( NULL , NULL ) ;
V_8 = F_6 ( NULL ) ;
F_7 ( L_7
L_1
L_8
L_1
L_8 ,
F_8 () , V_7 -> V_20 , V_8 -> V_20 ) ;
F_9 ( V_7 , TRUE ) ;
F_9 ( V_8 , TRUE ) ;
#ifdef F_10
F_11 ( V_5 , V_6 ) ;
F_12 () ;
#endif
F_13 () ;
V_9 = F_14 ( V_6 [ 0 ] , main ) ;
if ( V_9 != NULL ) {
fprintf ( V_4 ,
L_9 ,
V_9 ) ;
F_15 ( V_9 ) ;
}
F_16 () ;
#ifdef F_17
F_18 ( F_2 , F_2 ,
NULL , NULL , NULL ) ;
F_19 ( V_21 ) ;
F_20 () ;
#endif
while ( ( V_14 = F_21 ( V_5 , V_6 , L_10 , V_17 , NULL ) ) != - 1 ) {
switch ( V_14 ) {
case 'h' :
printf ( L_7
L_11
L_12 ,
F_8 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
V_7 = F_5 ( NULL , NULL ) ;
V_8 = F_6 ( NULL ) ;
F_22 ( L_13 , V_7 , V_8 ) ;
F_9 ( V_7 , TRUE ) ;
F_9 ( V_8 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_1 ( V_4 ) ;
exit ( 1 ) ;
break;
}
}
if ( V_5 < 2 ) {
F_1 ( V_4 ) ;
return 1 ;
}
V_15 = 0 ;
for ( V_13 = 1 ; V_13 < V_5 ; V_13 ++ ) {
V_10 = F_23 ( V_6 [ V_13 ] , V_22 , & V_11 , & V_12 , FALSE ) ;
if( V_10 ) {
printf ( L_14 , V_6 [ V_13 ] , F_24 ( F_25 ( V_10 ) ) ) ;
F_26 ( V_10 ) ;
} else {
if ( V_11 == V_23 )
printf ( L_15 , V_6 [ V_13 ] ) ;
else {
F_27 ( L_16 , V_6 [ V_13 ] , V_11 , V_12 ) ;
V_15 = 2 ;
}
}
}
F_28 () ;
F_29 () ;
#ifdef F_17
F_30 () ;
#endif
return V_15 ;
}
