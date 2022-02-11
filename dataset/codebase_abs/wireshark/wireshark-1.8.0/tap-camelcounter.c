static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = ( struct V_2 * ) V_1 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
}
static int F_2 ( void * V_1 ,
T_1 * T_2 V_4 ,
T_3 * T_4 V_4 ,
const void * V_5 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
const struct V_6 * V_7 = V_5 ;
if ( V_7 -> V_8 != 255 )
V_3 -> V_9 [ V_7 -> V_8 ] ++ ;
return 1 ;
}
static void F_3 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_10 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
for( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if( V_3 -> V_9 [ V_10 ] != 0 ) {
printf ( L_4 , F_4 ( V_10 , V_12 , L_5 ) ) ;
printf ( L_6 , V_3 -> V_9 [ V_10 ] ) ;
}
}
printf ( L_3 ) ;
}
static void F_5 ( const char * V_13 , void * T_5 V_4 )
{
struct V_2 * V_14 ;
T_6 * V_15 ;
V_14 = F_6 ( sizeof( struct V_2 ) ) ;
if( ! strncmp ( V_13 , L_7 , 13 ) ) {
V_14 -> V_16 = F_7 ( V_13 + 13 ) ;
} else {
V_14 -> V_16 = NULL ;
}
F_1 ( V_14 ) ;
V_15 = F_8 ( L_8 ,
V_14 ,
V_14 -> V_16 ,
0 ,
NULL ,
F_2 ,
F_3 ) ;
if( V_15 ) {
F_9 ( V_14 -> V_16 ) ;
F_9 ( V_14 ) ;
fprintf ( V_17 , L_9 ,
V_15 -> V_18 ) ;
F_10 ( V_15 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_11 ( void )
{
F_12 ( L_10 , F_5 , NULL ) ;
}
