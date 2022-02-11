static void
F_1 ( const char * T_1 V_1 , T_2 T_3 V_1 )
{
return;
}
static void
F_2 ( T_4 V_2 )
{
T_5 * V_3 ;
char * * V_4 ;
char * * V_5 ;
unsigned V_6 = 0 ;
if ( ! V_2 ) {
V_3 = stdout ;
}
else {
V_3 = V_7 ;
}
fprintf ( V_3 , L_1 ) ;
fprintf ( V_3 , L_2 ) ;
fprintf ( V_3 , L_3 ) ;
fprintf ( V_3 , L_4 ) ;
fprintf ( V_3 , L_5 ) ;
fprintf ( V_3 , L_6 ) ;
F_3 ( & V_4 , & V_5 ) ;
while ( V_4 [ V_6 ] && V_5 [ V_6 ] ) {
fprintf ( V_3 , L_7 , V_4 [ V_6 ] , V_5 [ V_6 ] ) ;
V_6 ++ ;
}
F_4 ( V_4 ) ;
F_4 ( V_5 ) ;
fprintf ( V_3 , L_8 ) ;
exit ( V_2 ? 1 : 0 ) ;
}
int
main ( int V_8 , char * * V_9 )
{
int V_10 ;
int V_11 = - 1 ;
char * V_12 = NULL ;
int V_13 = 5000 ;
int V_14 = 1000 ;
T_6 * V_15 ;
T_7 * type = NULL ;
int V_16 = FALSE ;
T_8 * V_17 ;
static const struct V_18 V_19 [] = {
{ L_9 , V_20 , NULL , 'h' } ,
{ 0 , 0 , 0 , 0 }
} ;
#ifdef F_5
char * V_21 ;
#endif
F_6 () ;
F_7 () ;
#ifdef F_8
F_9 ( V_8 , V_9 ) ;
F_10 () ;
#endif
#ifdef F_5
if ( ( V_21 = F_11 ( V_9 [ 0 ] , main ) ) ) {
F_12 ( L_10 , V_21 ) ;
F_13 ( V_21 ) ;
} else {
F_14 () ;
F_15 ( F_1 , NULL , NULL , NULL ) ;
F_16 () ;
F_17 () ;
}
#endif
while ( ( V_10 = F_18 ( V_8 , V_9 , L_11 , V_19 , NULL ) ) != - 1 ) {
switch ( V_10 ) {
case 'b' :
V_13 = atoi ( V_22 ) ;
if ( V_13 > 65536 ) {
fprintf ( V_7 , L_12 ) ;
return 1 ;
}
break;
case 'c' :
V_14 = atoi ( V_22 ) ;
break;
case 't' :
type = F_19 ( V_22 ) ;
break;
case 'h' :
F_2 ( FALSE ) ;
break;
case 'r' :
V_16 = TRUE ;
break;
default:
F_2 ( TRUE ) ;
break;
}
}
if ( V_8 > V_23 ) {
V_12 = V_9 [ V_23 ] ;
}
else {
F_2 ( TRUE ) ;
}
if ( ! V_16 ) {
V_11 = F_20 ( type ) ;
F_13 ( type ) ;
V_15 = F_21 ( V_11 ) ;
if ( ! V_15 )
return 1 ;
F_22 ( V_15 , V_12 , V_13 ) ;
F_23 ( V_15 , V_14 ) ;
} else {
if ( type ) {
fprintf ( V_7 , L_13 ) ;
return 2 ;
}
V_11 = F_20 ( NULL ) ;
V_15 = F_21 ( V_11 ) ;
if ( ! V_15 )
return 1 ;
F_22 ( V_15 , V_12 , V_13 ) ;
while ( V_14 -- > 0 ) {
F_23 ( V_15 , 1 ) ;
V_11 = F_20 ( NULL ) ;
V_17 = V_15 -> V_24 ;
V_15 = F_21 ( V_11 ) ;
if ( ! V_15 )
return 1 ;
V_15 -> V_24 = V_17 ;
}
}
if ( ! F_24 ( V_15 ) )
return 2 ;
return 0 ;
}
