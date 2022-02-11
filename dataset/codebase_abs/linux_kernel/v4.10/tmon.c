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
printf ( L_10 ) ;
exit ( 0 ) ;
}
void F_2 ()
{
printf ( L_11 , V_1 ) ;
exit ( V_2 ) ;
}
static void F_3 ( void )
{
F_4 ( V_3 , L_12 ) ;
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
F_4 ( V_3 , L_13 , V_8 ) ;
F_5 () ;
switch ( V_8 ) {
case V_9 :
printf ( L_14 ) ;
fflush ( stdout ) ;
break;
case V_10 :
printf ( L_15 ) ;
fflush ( stdout ) ;
break;
case V_11 :
printf ( L_16 ) ;
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
F_22 ( L_17 , V_16 | V_17 | V_18 , V_19 ) ;
F_4 ( V_20 , L_18 , F_23 () ) ;
}
static void F_24 ( void )
{
int V_21 ;
struct V_22 V_23 ;
if ( ! V_24 )
return;
V_4 = fopen ( V_25 , L_19 ) ;
if ( ! V_4 ) {
F_4 ( V_15 , L_20 , V_25 ) ;
return;
}
if ( F_25 ( V_25 , & V_23 ) < 0 ) {
F_4 ( V_15 , L_21 , V_25 ) ;
fclose ( V_4 ) ;
V_4 = NULL ;
return;
}
if ( F_26 ( V_23 . V_26 ) ) {
F_4 ( V_15 , L_22 ) ;
fclose ( V_4 ) ;
V_4 = NULL ;
return;
}
if ( V_23 . V_27 != F_23 () ) {
F_4 ( V_15 , L_23 ) ;
fclose ( V_4 ) ;
V_4 = NULL ;
return;
}
fprintf ( V_4 , L_24 ) ;
for ( V_21 = 0 ; V_21 < V_28 . V_29 ; V_21 ++ ) {
char V_30 [ 33 ] ;
int V_31 ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
for ( V_31 = 0 ; V_31 < 32 ; V_31 ++ )
V_30 [ V_31 ] = ( V_28 . V_32 [ V_21 ] . V_33 & 1 << V_31 ) ?
'1' : '0' ;
fprintf ( V_4 , L_25 ,
V_28 . V_32 [ V_21 ] . type ,
V_28 . V_32 [ V_21 ] . V_34 ,
V_30 ) ;
for ( V_31 = 0 ; V_31 < V_28 . V_32 [ V_21 ] . V_35 ; V_31 ++ ) {
fprintf ( V_4 , L_26 , V_31 ,
V_36 [ V_28 . V_32 [ V_21 ] . V_37 [ V_31 ] . type ] ,
V_28 . V_32 [ V_21 ] . V_37 [ V_31 ] . V_38 ) ;
}
}
for ( V_21 = 0 ; V_21 < V_28 . V_39 ; V_21 ++ )
fprintf ( V_4 , L_27 ,
V_21 , V_28 . V_40 [ V_21 ] . type ) ;
fprintf ( V_4 , L_28 ) ;
fprintf ( V_4 , L_29 ) ;
for ( V_21 = 0 ; V_21 < V_28 . V_29 ; V_21 ++ ) {
fprintf ( V_4 , L_30 , V_28 . V_32 [ V_21 ] . type ,
V_28 . V_32 [ V_21 ] . V_34 ) ;
}
for ( V_21 = 0 ; V_21 < V_28 . V_39 ; V_21 ++ )
fprintf ( V_4 , L_31 , V_28 . V_40 [ V_21 ] . type ,
V_28 . V_40 [ V_21 ] . V_34 ) ;
fprintf ( V_4 , L_32 ) ;
}
int main ( int V_41 , char * * V_42 )
{
int V_43 = 0 ;
int V_44 = 0 , V_45 ;
double V_46 = 0.0 , V_38 ;
int V_47 ;
if ( F_27 () != 0 ) {
printf ( L_33 ) ;
exit ( V_48 ) ;
}
while ( ( V_45 = F_28 ( V_41 , V_42 , L_34 , V_49 , & V_44 ) ) != - 1 ) {
switch ( V_45 ) {
case 'c' :
V_50 = 0 ;
strncpy ( V_51 , V_52 , V_53 ) ;
break;
case 'd' :
F_29 () ;
printf ( L_35 ) ;
break;
case 't' :
V_54 = strtod ( V_52 , NULL ) ;
if ( V_54 < 1 )
V_54 = 1 ;
break;
case 'T' :
V_38 = strtod ( V_52 , NULL ) ;
if ( V_38 < 0 ) {
fprintf ( V_55 , L_36 ) ;
return 1 ;
}
V_56 = V_38 ;
break;
case 'l' :
printf ( L_37 ) ;
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
V_57 = strtod ( V_52 , NULL ) ;
break;
default:
break;
}
}
if ( F_30 ( & V_6 , NULL ) != 0 ) {
fprintf ( V_55 , L_38 ) ;
return 1 ;
}
F_19 () ;
if ( signal ( V_11 , F_18 ) == V_58 )
F_4 ( V_14 , L_39 ) ;
if ( signal ( V_9 , F_18 ) == V_58 )
F_4 ( V_14 , L_39 ) ;
if ( F_31 () ) {
F_9 ( & V_6 ) ;
F_10 () ;
return - 1 ;
}
F_32 () ;
F_33 () ;
signal ( V_59 , V_60 ) ;
F_34 () ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
F_24 () ;
F_39 () ;
F_40 ( V_7 , TRUE ) ;
V_43 = F_41 ( & V_5 , NULL , & V_61 , NULL ) ;
if ( V_43 != 0 ) {
printf ( L_40 , strerror ( V_43 ) ) ;
F_3 () ;
exit ( V_48 ) ;
}
V_47 = F_42 ( V_57 ) ;
if ( V_47 < 0 ) {
V_57 = V_28 . V_32 [ 0 ] . V_34 ;
F_4 ( V_15 , L_41 ,
V_57 ) ;
}
while ( 1 ) {
F_43 ( V_54 ) ;
F_34 () ;
F_35 () ;
F_37 () ;
if ( ! V_62 ) {
F_38 () ;
F_36 () ;
}
V_63 ++ ;
V_64 += V_54 ;
F_44 ( V_65 [ 0 ] . V_38 [ V_47 ] / 1000 ,
& V_46 ) ;
V_65 [ 0 ] . V_66 = V_46 ;
if ( ! V_62 )
F_45 () ;
if ( V_12 )
break;
}
F_3 () ;
return 0 ;
}
static void F_29 ()
{
V_67 = 1 ;
T_1 V_68 , V_69 = F_46 () ;
if ( V_69 < 0 ) {
exit ( V_48 ) ;
} else if ( V_69 > 0 )
exit ( V_2 ) ;
F_47 () ;
F_48 ( V_70 | V_71 ) ;
V_68 = F_49 () ;
if ( V_68 < 0 )
exit ( V_48 ) ;
if ( ( F_50 ( L_42 ) ) < 0 )
exit ( V_48 ) ;
F_43 ( 10 ) ;
F_51 ( V_72 ) ;
F_51 ( V_73 ) ;
F_51 ( V_74 ) ;
}
