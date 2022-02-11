static void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
exit ( 1 ) ;
}
static char * F_2 ( const char * V_2 )
{
char * V_3 = F_3 ( V_2 ) ;
char * V_4 ;
if ( ! V_3 ) {
fprintf ( V_5 , L_2 , V_1 ) ;
exit ( 3 ) ;
}
for ( V_4 = V_3 ; * V_4 ; V_4 ++ )
* V_4 = toupper ( * V_4 ) ;
return V_3 ;
}
int main ( int V_6 , char * V_7 [] )
{
int V_8 , V_9 , V_10 ;
int V_11 ;
T_1 * V_12 ;
const char * V_13 = L_3 ;
char * V_14 ;
V_1 = V_7 [ 0 ] ;
if ( V_6 < 3 )
F_1 () ;
V_12 = fopen ( V_7 [ 1 ] , L_4 ) ;
if ( ! V_12 ) {
fprintf ( V_5 , L_5 ,
V_7 [ 1 ] , strerror ( V_15 ) ) ;
exit ( 2 ) ;
}
for ( V_8 = 0 ; V_16 [ V_8 ] . V_17 ; V_8 ++ ) {
struct V_18 * V_19 = & V_16 [ V_8 ] ;
V_19 -> V_17 = F_2 ( V_19 -> V_17 ) ;
for ( V_9 = 0 ; V_19 -> V_20 [ V_9 ] ; V_9 ++ )
V_19 -> V_20 [ V_9 ] = F_2 ( V_19 -> V_20 [ V_9 ] ) ;
}
V_11 = sizeof( V_21 ) / sizeof ( char * ) ;
for ( V_8 = 1 ; V_8 < V_11 ; V_8 ++ )
V_21 [ V_8 ] = F_2 ( V_21 [ V_8 ] ) ;
fprintf ( V_12 , L_6 ) ;
fprintf ( V_12 , L_7 ) ;
for ( V_8 = 0 ; V_16 [ V_8 ] . V_17 ; V_8 ++ ) {
struct V_18 * V_19 = & V_16 [ V_8 ] ;
fprintf ( V_12 , L_8 , V_19 -> V_17 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( 1 , 40 - strlen ( V_19 -> V_17 ) ) ; V_9 ++ )
fprintf ( V_12 , L_9 ) ;
fprintf ( V_12 , L_10 , V_8 + 1 ) ;
}
fprintf ( V_12 , L_11 ) ;
for ( V_8 = 1 ; V_8 < V_11 ; V_8 ++ ) {
const char * V_2 = V_21 [ V_8 ] ;
fprintf ( V_12 , L_12 , V_2 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( 1 , 40 - strlen ( V_2 ) ) ; V_9 ++ )
fprintf ( V_12 , L_9 ) ;
fprintf ( V_12 , L_10 , V_8 ) ;
}
fprintf ( V_12 , L_13 , V_8 - 1 ) ;
fprintf ( V_12 , L_14 ) ;
fprintf ( V_12 , L_15 ) ;
fprintf ( V_12 , L_16 ) ;
fprintf ( V_12 , L_17 ) ;
for ( V_8 = 0 ; V_16 [ V_8 ] . V_17 ; V_8 ++ ) {
struct V_18 * V_19 = & V_16 [ V_8 ] ;
V_14 = strstr ( V_19 -> V_17 , V_13 ) ;
if ( V_14 && strcmp ( V_14 , V_13 ) == 0 )
fprintf ( V_12 , L_18 , V_19 -> V_17 ) ;
}
fprintf ( V_12 , L_19 ) ;
fprintf ( V_12 , L_20 ) ;
fprintf ( V_12 , L_21 ) ;
fprintf ( V_12 , L_20 ) ;
fprintf ( V_12 , L_22 ) ;
fprintf ( V_12 , L_23 ) ;
fprintf ( V_12 , L_24 ) ;
fprintf ( V_12 , L_25 ) ;
fclose ( V_12 ) ;
V_12 = fopen ( V_7 [ 2 ] , L_4 ) ;
if ( ! V_12 ) {
fprintf ( V_5 , L_5 ,
V_7 [ 2 ] , strerror ( V_15 ) ) ;
exit ( 4 ) ;
}
fprintf ( V_12 , L_6 ) ;
fprintf ( V_12 , L_26 ) ;
for ( V_8 = 0 ; V_16 [ V_8 ] . V_17 ; V_8 ++ ) {
struct V_18 * V_19 = & V_16 [ V_8 ] ;
for ( V_9 = 0 ; V_19 -> V_20 [ V_9 ] ; V_9 ++ ) {
fprintf ( V_12 , L_27 , V_19 -> V_17 ,
V_19 -> V_20 [ V_9 ] ) ;
for ( V_10 = 0 ; V_10 < F_4 ( 1 , 40 - strlen ( V_19 -> V_17 ) - strlen ( V_19 -> V_20 [ V_9 ] ) ) ; V_10 ++ )
fprintf ( V_12 , L_9 ) ;
fprintf ( V_12 , L_28 , ( 1 << V_9 ) ) ;
}
}
fprintf ( V_12 , L_25 ) ;
fclose ( V_12 ) ;
exit ( 0 ) ;
}
