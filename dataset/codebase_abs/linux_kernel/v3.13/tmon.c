void F_1 ()
{
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
exit ( 0 ) ;
}
void F_2 ()
{
printf ( L_10 , V_1 ) ;
exit ( V_2 ) ;
}
static void F_3 ( void )
{
F_4 ( V_3 , L_11 ) ;
fflush ( stdout ) ;
F_5 () ;
if ( V_4 )
fclose ( V_4 ) ;
if ( V_5 ) {
F_6 ( & V_6 ) ;
F_7 ( V_5 ) ;
F_8 ( & V_6 ) ;
F_9 ( & V_6 ) ;
}
F_10 () ;
F_11 ( 0 ) ;
F_12 ( V_7 , FALSE ) ;
F_13 () ;
F_14 () ;
F_15 () ;
F_16 () ;
F_17 () ;
exit ( 1 ) ;
}
static void F_18 ( int V_8 )
{
F_4 ( V_3 , L_12 , V_8 ) ;
F_5 () ;
switch ( V_8 ) {
case V_9 :
printf ( L_13 ) ;
fflush ( stdout ) ;
break;
case V_10 :
printf ( L_14 ) ;
fflush ( stdout ) ;
break;
case V_11 :
printf ( L_15 ) ;
fflush ( stdout ) ;
break;
default:
break;
}
V_12 = true ;
}
static void F_19 ( void )
{
if ( V_13 )
F_20 ( F_21 ( V_14 ) ) ;
else
F_20 ( F_21 ( V_15 ) ) ;
F_22 ( L_16 , V_16 | V_17 | V_18 , V_19 ) ;
F_4 ( V_20 , L_17 , F_23 () ) ;
}
static void F_24 ( void )
{
int V_21 ;
if ( ! V_22 )
return;
V_4 = fopen ( V_23 , L_18 ) ;
if ( ! V_4 ) {
F_4 ( V_15 , L_19 , V_23 ) ;
return;
}
fprintf ( V_4 , L_20 ) ;
for ( V_21 = 0 ; V_21 < V_24 . V_25 ; V_21 ++ ) {
char V_26 [ 33 ] ;
int V_27 ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
for ( V_27 = 0 ; V_27 < 32 ; V_27 ++ )
V_26 [ V_27 ] = ( V_24 . V_28 [ V_21 ] . V_29 & 1 << V_27 ) ?
'1' : '0' ;
fprintf ( V_4 , L_21 ,
V_24 . V_28 [ V_21 ] . type ,
V_24 . V_28 [ V_21 ] . V_30 ,
V_26 ) ;
for ( V_27 = 0 ; V_27 < V_24 . V_28 [ V_21 ] . V_31 ; V_27 ++ ) {
fprintf ( V_4 , L_22 , V_27 ,
V_32 [ V_24 . V_28 [ V_21 ] . V_33 [ V_27 ] . type ] ,
V_24 . V_28 [ V_21 ] . V_33 [ V_27 ] . V_34 ) ;
}
}
for ( V_21 = 0 ; V_21 < V_24 . V_35 ; V_21 ++ )
fprintf ( V_4 , L_23 ,
V_21 , V_24 . V_36 [ V_21 ] . type ) ;
fprintf ( V_4 , L_24 ) ;
fprintf ( V_4 , L_25 ) ;
for ( V_21 = 0 ; V_21 < V_24 . V_25 ; V_21 ++ ) {
fprintf ( V_4 , L_26 , V_24 . V_28 [ V_21 ] . type ,
V_24 . V_28 [ V_21 ] . V_30 ) ;
}
for ( V_21 = 0 ; V_21 < V_24 . V_35 ; V_21 ++ )
fprintf ( V_4 , L_27 , V_24 . V_36 [ V_21 ] . type ,
V_24 . V_36 [ V_21 ] . V_30 ) ;
fprintf ( V_4 , L_28 ) ;
}
int main ( int V_37 , char * * V_38 )
{
int V_39 = 0 ;
int V_40 = 0 , V_41 ;
double V_42 = 0.0 ;
int V_43 ;
if ( F_25 () != 0 ) {
printf ( L_29 ) ;
exit ( V_44 ) ;
}
while ( ( V_41 = F_26 ( V_37 , V_38 , L_30 , V_45 , & V_40 ) ) != - 1 ) {
switch ( V_41 ) {
case 'c' :
V_46 = 0 ;
strncpy ( V_47 , V_48 , V_49 ) ;
break;
case 'd' :
F_27 () ;
printf ( L_31 ) ;
break;
case 't' :
V_50 = strtod ( V_48 , NULL ) ;
if ( V_50 < 1 )
V_50 = 1 ;
break;
case 'l' :
printf ( L_32 ) ;
V_22 = 1 ;
break;
case 'h' :
F_1 () ;
break;
case 'v' :
F_2 () ;
break;
case 'g' :
V_13 = 1 ;
break;
case 'z' :
V_51 = strtod ( V_48 , NULL ) ;
break;
default:
break;
}
}
if ( F_28 ( & V_6 , NULL ) != 0 ) {
fprintf ( V_52 , L_33 ) ;
return 1 ;
}
F_19 () ;
if ( signal ( V_11 , F_18 ) == V_53 )
F_4 ( V_14 , L_34 ) ;
if ( signal ( V_9 , F_18 ) == V_53 )
F_4 ( V_14 , L_34 ) ;
if ( F_29 () ) {
F_9 ( & V_6 ) ;
F_10 () ;
return - 1 ;
}
F_30 () ;
F_31 () ;
signal ( V_54 , V_55 ) ;
F_32 () ;
F_33 () ;
F_34 () ;
F_35 () ;
F_36 () ;
F_24 () ;
F_37 () ;
F_38 ( V_7 , TRUE ) ;
V_39 = F_39 ( & V_5 , NULL , & V_56 , NULL ) ;
if ( V_39 != 0 ) {
printf ( L_35 , strerror ( V_39 ) ) ;
F_3 () ;
exit ( V_44 ) ;
}
V_43 = F_40 ( V_51 ) ;
if ( V_43 < 0 ) {
V_51 = V_24 . V_28 [ 0 ] . V_30 ;
F_4 ( V_15 , L_36 ,
V_51 ) ;
}
while ( 1 ) {
F_41 ( V_50 ) ;
F_32 () ;
F_33 () ;
F_35 () ;
if ( ! V_57 ) {
F_36 () ;
F_34 () ;
}
V_58 ++ ;
V_59 += V_50 ;
F_42 ( V_60 [ 0 ] . V_34 [ V_43 ] / 1000 ,
& V_42 ) ;
V_60 [ 0 ] . V_61 = V_42 ;
if ( ! V_57 )
F_43 () ;
if ( V_12 )
break;
}
F_3 () ;
return 0 ;
}
static void F_27 ()
{
V_62 = 1 ;
T_1 V_63 , V_64 = F_44 () ;
if ( V_64 < 0 ) {
exit ( V_44 ) ;
} else if ( V_64 > 0 )
exit ( V_2 ) ;
F_45 () ;
F_46 ( 0 ) ;
V_63 = F_47 () ;
if ( V_63 < 0 )
exit ( V_44 ) ;
if ( ( F_48 ( L_37 ) ) < 0 )
exit ( V_44 ) ;
F_41 ( 10 ) ;
F_49 ( V_65 ) ;
F_49 ( V_66 ) ;
F_49 ( V_67 ) ;
}
