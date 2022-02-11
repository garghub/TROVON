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
struct V_22 V_23 ;
if ( ! V_24 )
return;
V_4 = fopen ( V_25 , L_18 ) ;
if ( ! V_4 ) {
F_4 ( V_15 , L_19 , V_25 ) ;
return;
}
if ( F_25 ( V_25 , & V_23 ) < 0 ) {
F_4 ( V_15 , L_20 , V_25 ) ;
fclose ( V_4 ) ;
V_4 = NULL ;
return;
}
if ( F_26 ( V_23 . V_26 ) ) {
F_4 ( V_15 , L_21 ) ;
fclose ( V_4 ) ;
V_4 = NULL ;
return;
}
if ( V_23 . V_27 != F_23 () ) {
F_4 ( V_15 , L_22 ) ;
fclose ( V_4 ) ;
V_4 = NULL ;
return;
}
fprintf ( V_4 , L_23 ) ;
for ( V_21 = 0 ; V_21 < V_28 . V_29 ; V_21 ++ ) {
char V_30 [ 33 ] ;
int V_31 ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
for ( V_31 = 0 ; V_31 < 32 ; V_31 ++ )
V_30 [ V_31 ] = ( V_28 . V_32 [ V_21 ] . V_33 & 1 << V_31 ) ?
'1' : '0' ;
fprintf ( V_4 , L_24 ,
V_28 . V_32 [ V_21 ] . type ,
V_28 . V_32 [ V_21 ] . V_34 ,
V_30 ) ;
for ( V_31 = 0 ; V_31 < V_28 . V_32 [ V_21 ] . V_35 ; V_31 ++ ) {
fprintf ( V_4 , L_25 , V_31 ,
V_36 [ V_28 . V_32 [ V_21 ] . V_37 [ V_31 ] . type ] ,
V_28 . V_32 [ V_21 ] . V_37 [ V_31 ] . V_38 ) ;
}
}
for ( V_21 = 0 ; V_21 < V_28 . V_39 ; V_21 ++ )
fprintf ( V_4 , L_26 ,
V_21 , V_28 . V_40 [ V_21 ] . type ) ;
fprintf ( V_4 , L_27 ) ;
fprintf ( V_4 , L_28 ) ;
for ( V_21 = 0 ; V_21 < V_28 . V_29 ; V_21 ++ ) {
fprintf ( V_4 , L_29 , V_28 . V_32 [ V_21 ] . type ,
V_28 . V_32 [ V_21 ] . V_34 ) ;
}
for ( V_21 = 0 ; V_21 < V_28 . V_39 ; V_21 ++ )
fprintf ( V_4 , L_30 , V_28 . V_40 [ V_21 ] . type ,
V_28 . V_40 [ V_21 ] . V_34 ) ;
fprintf ( V_4 , L_31 ) ;
}
int main ( int V_41 , char * * V_42 )
{
int V_43 = 0 ;
int V_44 = 0 , V_45 ;
double V_46 = 0.0 ;
int V_47 ;
if ( F_27 () != 0 ) {
printf ( L_32 ) ;
exit ( V_48 ) ;
}
while ( ( V_45 = F_28 ( V_41 , V_42 , L_33 , V_49 , & V_44 ) ) != - 1 ) {
switch ( V_45 ) {
case 'c' :
V_50 = 0 ;
strncpy ( V_51 , V_52 , V_53 ) ;
break;
case 'd' :
F_29 () ;
printf ( L_34 ) ;
break;
case 't' :
V_54 = strtod ( V_52 , NULL ) ;
if ( V_54 < 1 )
V_54 = 1 ;
break;
case 'l' :
printf ( L_35 ) ;
V_24 = 1 ;
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
V_55 = strtod ( V_52 , NULL ) ;
break;
default:
break;
}
}
if ( F_30 ( & V_6 , NULL ) != 0 ) {
fprintf ( V_56 , L_36 ) ;
return 1 ;
}
F_19 () ;
if ( signal ( V_11 , F_18 ) == V_57 )
F_4 ( V_14 , L_37 ) ;
if ( signal ( V_9 , F_18 ) == V_57 )
F_4 ( V_14 , L_37 ) ;
if ( F_31 () ) {
F_9 ( & V_6 ) ;
F_10 () ;
return - 1 ;
}
F_32 () ;
F_33 () ;
signal ( V_58 , V_59 ) ;
F_34 () ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
F_24 () ;
F_39 () ;
F_40 ( V_7 , TRUE ) ;
V_43 = F_41 ( & V_5 , NULL , & V_60 , NULL ) ;
if ( V_43 != 0 ) {
printf ( L_38 , strerror ( V_43 ) ) ;
F_3 () ;
exit ( V_48 ) ;
}
V_47 = F_42 ( V_55 ) ;
if ( V_47 < 0 ) {
V_55 = V_28 . V_32 [ 0 ] . V_34 ;
F_4 ( V_15 , L_39 ,
V_55 ) ;
}
while ( 1 ) {
F_43 ( V_54 ) ;
F_34 () ;
F_35 () ;
F_37 () ;
if ( ! V_61 ) {
F_38 () ;
F_36 () ;
}
V_62 ++ ;
V_63 += V_54 ;
F_44 ( V_64 [ 0 ] . V_38 [ V_47 ] / 1000 ,
& V_46 ) ;
V_64 [ 0 ] . V_65 = V_46 ;
if ( ! V_61 )
F_45 () ;
if ( V_12 )
break;
}
F_3 () ;
return 0 ;
}
static void F_29 ()
{
V_66 = 1 ;
T_1 V_67 , V_68 = F_46 () ;
if ( V_68 < 0 ) {
exit ( V_48 ) ;
} else if ( V_68 > 0 )
exit ( V_2 ) ;
F_47 () ;
F_48 ( V_69 | V_70 ) ;
V_67 = F_49 () ;
if ( V_67 < 0 )
exit ( V_48 ) ;
if ( ( F_50 ( L_40 ) ) < 0 )
exit ( V_48 ) ;
F_43 ( 10 ) ;
F_51 ( V_71 ) ;
F_51 ( V_72 ) ;
F_51 ( V_73 ) ;
}
