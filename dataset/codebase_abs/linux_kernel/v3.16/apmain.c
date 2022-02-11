static void F_1 ( void )
{
F_2 ( L_1 ) ;
F_3 ( L_2 , L_3 ) ;
F_3 ( L_4 , L_5 ) ;
F_3 ( L_6 , L_7 ) ;
F_3 ( L_8 , L_9 ) ;
F_3 ( L_10 , L_11 ) ;
F_3 ( L_12 , L_13 ) ;
F_3 ( L_14 , L_15 ) ;
F_3 ( L_16 , L_17 ) ;
printf ( L_18 ) ;
F_3 ( L_19 , L_20 ) ;
F_3 ( L_21 , L_22 ) ;
F_3 ( L_23 , L_24 ) ;
F_3 ( L_25 , L_26 ) ;
F_3 ( L_27 , L_28 ) ;
printf ( L_29
L_30
L_31 ) ;
}
static void F_4 ( char * V_1 , T_1 V_2 )
{
V_3 [ V_4 ] . V_1 = V_1 ;
V_3 [ V_4 ] . V_2 = V_2 ;
V_4 ++ ;
if ( V_4 > V_5 ) {
fprintf ( V_6 , L_32 ,
V_5 ) ;
exit ( - 1 ) ;
}
}
static int F_5 ( int V_7 , char * * V_8 )
{
int V_9 ;
T_2 V_10 ;
while ( ( V_9 = F_6 ( V_7 , V_8 , V_11 ) ) != V_12 )
switch ( V_9 ) {
case 'b' :
V_13 = TRUE ;
continue;
case 'c' :
V_14 = TRUE ;
continue;
case 'h' :
case '?' :
F_1 () ;
exit ( 0 ) ;
case 'o' :
if ( F_7 ( V_15 ) ) {
exit ( - 1 ) ;
}
continue;
case 'r' :
V_10 =
F_8 ( V_15 , 0 ,
& V_16 ) ;
if ( F_9 ( V_10 ) ) {
fprintf ( V_6 ,
L_33 ,
V_15 ) ;
exit ( - 1 ) ;
}
continue;
case 's' :
V_17 = TRUE ;
continue;
case 'x' :
if ( ! V_18 ) {
V_18 = TRUE ;
} else {
V_19 = TRUE ;
}
continue;
case 'v' :
printf ( F_10 ( V_20 ) ) ;
exit ( 0 ) ;
case 'z' :
V_21 = TRUE ;
fprintf ( V_6 , F_10 ( V_20 ) ) ;
continue;
case 'a' :
F_4 ( V_15 ,
V_22 ) ;
break;
case 'f' :
F_4 ( V_15 ,
V_23 ) ;
break;
case 'n' :
F_4 ( V_15 ,
V_24 ) ;
break;
default:
F_1 () ;
exit ( - 1 ) ;
}
if ( V_4 == 0 ) {
F_4 ( NULL , V_25 ) ;
}
return ( 0 ) ;
}
int T_3 main ( int V_7 , char * V_8 [] )
{
int V_10 = 0 ;
struct V_26 * V_27 ;
T_1 V_28 ;
T_1 V_29 ;
F_11 () ;
if ( F_5 ( V_7 , V_8 ) ) {
return ( - 1 ) ;
}
for ( V_29 = 0 ; V_29 < V_4 ; V_29 ++ ) {
V_27 = & V_3 [ V_29 ] ;
switch ( V_27 -> V_2 ) {
case V_25 :
V_10 = F_12 () ;
break;
case V_22 :
V_10 = F_13 ( V_27 -> V_1 ) ;
break;
case V_24 :
V_10 = F_14 ( V_27 -> V_1 ) ;
break;
case V_23 :
V_10 = F_15 ( V_27 -> V_1 ) ;
break;
default:
fprintf ( V_6 ,
L_34 ,
V_27 -> V_2 ) ;
return ( - 1 ) ;
}
if ( V_10 ) {
return ( V_10 ) ;
}
}
if ( V_30 ) {
if ( V_21 ) {
V_28 = F_16 ( V_30 ) ;
fprintf ( V_6 ,
L_35 ,
V_31 , V_28 , V_28 ) ;
}
fclose ( V_30 ) ;
}
return ( V_10 ) ;
}
