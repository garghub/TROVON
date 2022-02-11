static void F_1 ( char * V_1 )
{
printf ( L_1 , V_1 ) ;
exit ( 1 ) ;
}
int main ( int V_2 , char * V_3 [] )
{
int V_4 , V_5 , V_6 = 0 ;
int V_7 ;
char * * V_8 , * V_9 , * V_10 ;
T_1 * V_11 ;
if ( V_2 < 3 )
F_1 ( V_3 [ 0 ] ) ;
V_8 = V_3 + 1 ;
if ( V_2 == 4 && strcmp ( V_3 [ 1 ] , L_2 ) == 0 ) {
V_6 = 1 ;
V_8 ++ ;
}
V_9 = * V_8 ++ ;
V_10 = * V_8 ;
V_11 = fopen ( V_9 , L_3 ) ;
if ( ! V_11 ) {
printf ( L_4 , V_9 ) ;
F_1 ( V_3 [ 0 ] ) ;
}
for ( V_4 = 0 ; V_12 [ V_4 ] . V_1 ; V_4 ++ )
fprintf ( V_11 , L_5 , V_12 [ V_4 ] . V_1 ) ;
fprintf ( V_11 , L_6 ) ;
V_7 = sizeof( V_13 ) / sizeof ( char * ) ;
for ( V_4 = 1 ; V_4 < V_7 ; V_4 ++ )
fprintf ( V_11 , L_7 , V_13 [ V_4 ] ) ;
fprintf ( V_11 , L_6 ) ;
for ( V_4 = 0 ; V_12 [ V_4 ] . V_1 ; V_4 ++ ) {
struct V_14 * V_15 = & V_12 [ V_4 ] ;
fprintf ( V_11 , L_5 , V_15 -> V_1 ) ;
fprintf ( V_11 , L_8 ) ;
for ( V_5 = 0 ; V_15 -> V_16 [ V_5 ] ; V_5 ++ )
fprintf ( V_11 , L_9 , V_15 -> V_16 [ V_5 ] ) ;
fprintf ( V_11 , L_10 ) ;
}
fprintf ( V_11 , L_6 ) ;
if ( V_6 ) {
printf ( L_11 ) ;
exit ( 1 ) ;
}
fprintf ( V_11 , L_12 ) ;
fprintf ( V_11 , L_13 ) ;
fprintf ( V_11 , L_14 ) ;
for ( V_4 = 0 ; V_12 [ V_4 ] . V_1 ; V_4 ++ )
fprintf ( V_11 , L_15 ,
V_12 [ V_4 ] . V_1 ) ;
fprintf ( V_11 , L_16 ) ;
fprintf ( V_11 , L_6 ) ;
for ( V_4 = 1 ; V_4 < V_7 ; V_4 ++ )
fprintf ( V_11 , L_17 , V_13 [ V_4 ] ) ;
fprintf ( V_11 , L_6 ) ;
fprintf ( V_11 , L_18 ) ;
fprintf ( V_11 , L_19 ) ;
fprintf ( V_11 , L_20 ) ;
fprintf ( V_11 , L_21 ) ;
fprintf ( V_11 , L_22 ) ;
fprintf ( V_11 , L_23 ) ;
fprintf ( V_11 , L_24 ) ;
fprintf ( V_11 , L_25 ) ;
fprintf ( V_11 , L_26 ) ;
fprintf ( V_11 , L_27 ) ;
fprintf ( V_11 , L_28 ) ;
fprintf ( V_11 , L_29 ) ;
fprintf ( V_11 , L_30 ) ;
fprintf ( V_11 , L_31 ) ;
fprintf ( V_11 , L_32 ) ;
fprintf ( V_11 , L_33 ) ;
fprintf ( V_11 , L_34 ) ;
fprintf ( V_11 , L_35 ) ;
fclose ( V_11 ) ;
V_11 = fopen ( V_10 , L_3 ) ;
if ( ! V_11 ) {
printf ( L_36 , V_10 ) ;
F_1 ( V_3 [ 0 ] ) ;
}
fprintf ( V_11 , L_37 ) ;
fprintf ( V_11 , L_38 ) ;
fclose ( V_11 ) ;
return 0 ;
}
