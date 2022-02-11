int main ( int V_1 , char * V_2 [] )
{
printf ( L_1 ) ;
return ( 0 ) ;
}
int main ( int V_1 , char * * V_2 )
{
unsigned char V_3 [ V_4 ] ;
int V_5 ;
T_1 V_6 ;
fprintf ( stdout , L_2 ) ;
F_1 ( L_3 , 3 , V_3 , NULL , F_2 () , NULL ) ;
if ( memcmp ( V_3 , V_7 , sizeof( V_7 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_8 , L_4 ) ;
return 1 ;
} else
fprintf ( stdout , L_5 ) ;
fflush ( stdout ) ;
F_1 ( L_6 L_7 L_8 L_9
L_10 L_11 L_12 , 56 , V_3 , NULL , F_2 () ,
NULL ) ;
if ( memcmp ( V_3 , V_9 , sizeof( V_9 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_8 , L_13 ) ;
return 1 ;
} else
fprintf ( stdout , L_5 ) ;
fflush ( stdout ) ;
F_3 ( & V_6 ) ;
F_4 ( & V_6 , F_2 () , NULL ) ;
for ( V_5 = 0 ; V_5 < 1000000 ; V_5 += 160 )
F_5 ( & V_6 , L_14 L_14 L_14 L_14
L_14 L_14 L_14 L_14
L_14 L_14 L_14 L_14
L_14 L_14 L_14 L_14
L_14 L_14 L_14 L_14 ,
( 1000000 - V_5 ) < 160 ? 1000000 - V_5 : 160 ) ;
F_6 ( & V_6 , V_3 , NULL ) ;
F_7 ( & V_6 ) ;
if ( memcmp ( V_3 , V_10 , sizeof( V_10 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_8 , L_15 ) ;
return 1 ;
} else
fprintf ( stdout , L_5 ) ;
fflush ( stdout ) ;
fprintf ( stdout , L_16 ) ;
fflush ( stdout ) ;
fprintf ( stdout , L_17 ) ;
F_1 ( L_3 , 3 , V_3 , NULL , F_8 () , NULL ) ;
if ( memcmp ( V_3 , V_11 , sizeof( V_11 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_8 , L_4 ) ;
return 1 ;
} else
fprintf ( stdout , L_5 ) ;
fflush ( stdout ) ;
F_1 ( L_6 L_7 L_8 L_9
L_10 L_11 L_12 , 56 , V_3 , NULL , F_8 () ,
NULL ) ;
if ( memcmp ( V_3 , V_12 , sizeof( V_12 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_8 , L_13 ) ;
return 1 ;
} else
fprintf ( stdout , L_5 ) ;
fflush ( stdout ) ;
F_3 ( & V_6 ) ;
F_4 ( & V_6 , F_8 () , NULL ) ;
for ( V_5 = 0 ; V_5 < 1000000 ; V_5 += 64 )
F_5 ( & V_6 , L_14 L_14 L_14 L_14
L_14 L_14 L_14 L_14 ,
( 1000000 - V_5 ) < 64 ? 1000000 - V_5 : 64 ) ;
F_6 ( & V_6 , V_3 , NULL ) ;
F_7 ( & V_6 ) ;
if ( memcmp ( V_3 , V_13 , sizeof( V_13 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_8 , L_15 ) ;
return 1 ;
} else
fprintf ( stdout , L_5 ) ;
fflush ( stdout ) ;
fprintf ( stdout , L_16 ) ;
fflush ( stdout ) ;
return 0 ;
}
