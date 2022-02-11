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
F_6 ( L_32 ,
V_5 ) ;
return ( - 1 ) ;
}
return ( 0 ) ;
}
static int F_7 ( int V_6 , char * * V_7 )
{
int V_8 ;
T_2 V_9 ;
while ( ( V_8 =
F_8 ( V_6 , V_7 , V_10 ) ) != V_11 )
switch ( V_8 ) {
case 'b' :
V_12 = TRUE ;
continue;
case 'c' :
if ( ! strcmp ( V_13 , L_33 ) ) {
V_14 = TRUE ;
} else if ( ! strcmp ( V_13 , L_34 ) ) {
V_14 = FALSE ;
} else {
F_6
( L_35 ,
V_13 ) ;
return ( - 1 ) ;
}
continue;
case 'h' :
case '?' :
F_1 () ;
return ( 1 ) ;
case 'o' :
if ( F_9 ( V_13 ) ) {
return ( - 1 ) ;
}
continue;
case 'r' :
V_9 =
F_10 ( V_13 , 0 ,
& V_15 ) ;
if ( F_11 ( V_9 ) ) {
F_6
( L_36 ,
V_13 ) ;
return ( - 1 ) ;
}
continue;
case 's' :
V_16 = TRUE ;
continue;
case 'x' :
if ( ! V_17 ) {
V_17 = TRUE ;
} else {
V_18 = TRUE ;
}
continue;
case 'v' :
F_12 ( F_13 ( V_19 ) ) ;
return ( 1 ) ;
case 'z' :
V_20 = TRUE ;
F_6 ( F_13 ( V_19 ) ) ;
continue;
case 'a' :
if ( F_5
( V_13 , V_21 ) ) {
return ( - 1 ) ;
}
break;
case 'f' :
if ( F_5
( V_13 , V_22 ) ) {
return ( - 1 ) ;
}
break;
case 'n' :
if ( F_5
( V_13 , V_23 ) ) {
return ( - 1 ) ;
}
break;
default:
F_1 () ;
return ( - 1 ) ;
}
if ( V_4 == 0 ) {
if ( F_5 ( NULL , V_24 ) ) {
return ( - 1 ) ;
}
}
return ( 0 ) ;
}
