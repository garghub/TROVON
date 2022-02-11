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
F_4 ( L_16 ) ;
F_3 ( L_17 , L_18 ) ;
F_3 ( L_19 , L_20 ) ;
F_3 ( L_21 , L_22 ) ;
F_3 ( L_23 , L_24 ) ;
F_3 ( L_25 , L_26 ) ;
F_3 ( L_27 , L_28 ) ;
F_4 ( L_29
L_30
L_31 ) ;
}
static int F_5 ( char * V_1 , T_1 V_2 )
{
V_3 [ V_4 ] . V_1 = V_1 ;
V_3 [ V_4 ] . V_2 = V_2 ;
V_4 ++ ;
if ( V_4 > V_5 ) {
fprintf ( V_6 , L_32 ,
V_5 ) ;
return ( - 1 ) ;
}
return ( 0 ) ;
}
static int F_6 ( int V_7 , char * * V_8 )
{
int V_9 ;
T_2 V_10 ;
while ( ( V_9 =
F_7 ( V_7 , V_8 , V_11 ) ) != V_12 )
switch ( V_9 ) {
case 'b' :
V_13 = TRUE ;
continue;
case 'c' :
if ( ! strcmp ( V_14 , L_33 ) ) {
V_15 = TRUE ;
} else if ( ! strcmp ( V_14 , L_34 ) ) {
V_15 = FALSE ;
} else {
fprintf ( V_6 ,
L_35 ,
V_14 ) ;
return ( - 1 ) ;
}
continue;
case 'h' :
case '?' :
F_1 () ;
return ( 1 ) ;
case 'o' :
if ( F_8 ( V_14 ) ) {
return ( - 1 ) ;
}
continue;
case 'r' :
V_10 =
F_9 ( V_14 ,
V_16 ,
& V_17 ) ;
if ( F_10 ( V_10 ) ) {
fprintf ( V_6 ,
L_36 ,
V_14 ) ;
return ( - 1 ) ;
}
continue;
case 's' :
V_18 = TRUE ;
continue;
case 'x' :
if ( ! V_19 ) {
V_19 = TRUE ;
} else {
V_20 = TRUE ;
}
continue;
case 'v' :
F_11 ( F_12 ( V_21 ) ) ;
return ( 1 ) ;
case 'z' :
V_22 = TRUE ;
fprintf ( V_6 , F_12 ( V_21 ) ) ;
continue;
case 'a' :
if ( F_5
( V_14 , V_23 ) ) {
return ( - 1 ) ;
}
break;
case 'f' :
if ( F_5
( V_14 , V_24 ) ) {
return ( - 1 ) ;
}
break;
case 'n' :
if ( F_5
( V_14 , V_25 ) ) {
return ( - 1 ) ;
}
break;
default:
F_1 () ;
return ( - 1 ) ;
}
if ( V_4 == 0 ) {
if ( F_5 ( NULL , V_26 ) ) {
return ( - 1 ) ;
}
}
return ( 0 ) ;
}
