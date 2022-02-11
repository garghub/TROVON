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
# ifdef F_1
{
char * V_7 ;
if ( ( V_7 = getenv ( L_2 ) ) )
V_8 = strtoul ( V_7 , NULL , 0 ) ;
}
# endif
fprintf ( stdout , L_3 ) ;
F_2 ( L_4 , 3 , V_3 , NULL , F_3 () , NULL ) ;
if ( memcmp ( V_3 , V_9 , sizeof( V_9 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_10 , L_5 ) ;
return 1 ;
} else
fprintf ( stdout , L_6 ) ;
fflush ( stdout ) ;
F_2 ( L_7 L_8 L_9 L_10
L_11 L_12 L_13 L_14
L_15 L_16 L_17 L_18
L_19 L_20 , 112 , V_3 , NULL , F_3 () , NULL ) ;
if ( memcmp ( V_3 , V_11 , sizeof( V_11 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_10 , L_21 ) ;
return 1 ;
} else
fprintf ( stdout , L_6 ) ;
fflush ( stdout ) ;
F_4 ( & V_6 ) ;
F_5 ( & V_6 , F_3 () , NULL ) ;
for ( V_5 = 0 ; V_5 < 1000000 ; V_5 += 288 )
F_6 ( & V_6 , L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22 ,
( 1000000 - V_5 ) < 288 ? 1000000 - V_5 : 288 ) ;
F_7 ( & V_6 , V_3 , NULL ) ;
F_8 ( & V_6 ) ;
if ( memcmp ( V_3 , V_12 , sizeof( V_12 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_10 , L_23 ) ;
return 1 ;
} else
fprintf ( stdout , L_6 ) ;
fflush ( stdout ) ;
fprintf ( stdout , L_24 ) ;
fflush ( stdout ) ;
fprintf ( stdout , L_25 ) ;
F_2 ( L_4 , 3 , V_3 , NULL , F_9 () , NULL ) ;
if ( memcmp ( V_3 , V_13 , sizeof( V_13 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_10 , L_5 ) ;
return 1 ;
} else
fprintf ( stdout , L_6 ) ;
fflush ( stdout ) ;
F_2 ( L_7 L_8 L_9 L_10
L_11 L_12 L_13 L_14
L_15 L_16 L_17 L_18
L_19 L_20 , 112 , V_3 , NULL , F_9 () , NULL ) ;
if ( memcmp ( V_3 , V_14 , sizeof( V_14 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_10 , L_21 ) ;
return 1 ;
} else
fprintf ( stdout , L_6 ) ;
fflush ( stdout ) ;
F_4 ( & V_6 ) ;
F_5 ( & V_6 , F_9 () , NULL ) ;
for ( V_5 = 0 ; V_5 < 1000000 ; V_5 += 64 )
F_6 ( & V_6 , L_22 L_22 L_22 L_22
L_22 L_22 L_22 L_22 ,
( 1000000 - V_5 ) < 64 ? 1000000 - V_5 : 64 ) ;
F_7 ( & V_6 , V_3 , NULL ) ;
F_8 ( & V_6 ) ;
if ( memcmp ( V_3 , V_15 , sizeof( V_15 ) ) ) {
fflush ( stdout ) ;
fprintf ( V_10 , L_23 ) ;
return 1 ;
} else
fprintf ( stdout , L_6 ) ;
fflush ( stdout ) ;
fprintf ( stdout , L_24 ) ;
fflush ( stdout ) ;
return 0 ;
}
