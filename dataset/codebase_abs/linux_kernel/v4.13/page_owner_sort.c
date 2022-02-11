int F_1 ( char * V_1 , int V_2 , T_1 * V_3 )
{
char * V_4 = V_1 , * const V_5 = V_1 + V_2 ;
while ( V_5 - V_4 > 1 && fgets ( V_4 , V_5 - V_4 , V_3 ) ) {
if ( * V_4 == '\n' )
return V_4 - V_1 ;
V_4 += strlen ( V_4 ) ;
}
return - 1 ;
}
static int F_2 ( const void * V_6 , const void * V_7 )
{
const struct V_8 * V_9 = V_6 , * V_10 = V_7 ;
return strcmp ( V_9 -> V_11 , V_10 -> V_11 ) ;
}
static int F_3 ( const void * V_6 , const void * V_7 )
{
const struct V_8 * V_9 = V_6 , * V_10 = V_7 ;
return V_10 -> V_12 - V_9 -> V_12 ;
}
static void F_4 ( char * V_1 , int V_13 )
{
if ( V_14 != 0 &&
V_13 == V_15 [ V_14 - 1 ] . V_13 &&
memcmp ( V_1 , V_15 [ V_14 - 1 ] . V_11 , V_13 ) == 0 ) {
V_15 [ V_14 - 1 ] . V_12 ++ ;
return;
}
if ( V_14 == V_16 ) {
printf ( L_1 ) ;
exit ( 1 ) ;
}
V_15 [ V_14 ] . V_11 = malloc ( V_13 + 1 ) ;
V_15 [ V_14 ] . V_13 = V_13 ;
V_15 [ V_14 ] . V_12 = 1 ;
memcpy ( V_15 [ V_14 ] . V_11 , V_1 , V_13 ) ;
V_15 [ V_14 ] . V_11 [ V_13 ] = 0 ;
V_14 ++ ;
if ( V_14 % 1000 == 0 ) {
printf ( L_2 , V_14 ) ;
fflush ( stdout ) ;
}
}
int main ( int V_17 , char * * V_18 )
{
T_1 * V_3 , * V_19 ;
char * V_1 ;
int V_20 , V_21 , V_22 ;
struct V_8 * V_23 ;
struct V_24 V_25 ;
if ( V_17 < 3 ) {
printf ( L_3 ) ;
perror ( L_4 ) ;
exit ( 1 ) ;
}
V_3 = fopen ( V_18 [ 1 ] , L_5 ) ;
V_19 = fopen ( V_18 [ 2 ] , L_6 ) ;
if ( ! V_3 || ! V_19 ) {
printf ( L_3 ) ;
perror ( L_4 ) ;
exit ( 1 ) ;
}
F_5 ( fileno ( V_3 ) , & V_25 ) ;
V_16 = V_25 . V_26 / 100 ;
V_15 = malloc ( V_16 * sizeof( * V_15 ) ) ;
V_1 = malloc ( V_27 ) ;
if ( ! V_15 || ! V_1 ) {
printf ( L_7 ) ;
exit ( 1 ) ;
}
for ( ; ; ) {
V_20 = F_1 ( V_1 , V_27 , V_3 ) ;
if ( V_20 < 0 )
break;
F_4 ( V_1 , V_20 ) ;
}
printf ( L_8 , V_14 ) ;
printf ( L_9 ) ;
qsort ( V_15 , V_14 , sizeof( V_15 [ 0 ] ) , F_2 ) ;
V_23 = malloc ( sizeof( * V_15 ) * V_14 ) ;
printf ( L_10 ) ;
for ( V_21 = V_22 = 0 ; V_21 < V_14 ; V_21 ++ ) {
if ( V_22 == 0 ||
strcmp ( V_23 [ V_22 - 1 ] . V_11 , V_15 [ V_21 ] . V_11 ) != 0 ) {
V_23 [ V_22 ++ ] = V_15 [ V_21 ] ;
} else {
V_23 [ V_22 - 1 ] . V_12 += V_15 [ V_21 ] . V_12 ;
}
}
qsort ( V_23 , V_22 , sizeof( V_15 [ 0 ] ) , F_3 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ )
fprintf ( V_19 , L_11 , V_23 [ V_21 ] . V_12 , V_23 [ V_21 ] . V_11 ) ;
return 0 ;
}
