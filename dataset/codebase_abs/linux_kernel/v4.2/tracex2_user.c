static void F_1 ( char * V_1 , long V_2 , long V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < ( V_4 * V_2 / V_3 ) - 1 && V_5 < V_4 - 1 ; V_5 ++ )
V_1 [ V_5 ] = '*' ;
if ( V_2 > V_3 )
V_1 [ V_5 - 1 ] = '+' ;
V_1 [ V_5 ] = '\0' ;
}
static void F_2 ( int V_6 , void * V_7 )
{
struct V_8 V_9 = {} , V_10 ;
char V_11 [ V_12 ] ;
long V_13 ;
long V_14 [ V_15 ] = {} ;
int V_16 = - 1 ;
long V_17 = 0 ;
int V_5 , V_18 ;
while ( F_3 ( V_6 , & V_9 , & V_10 ) == 0 ) {
if ( memcmp ( & V_10 , V_7 , V_19 ) ) {
V_9 = V_10 ;
continue;
}
F_4 ( V_6 , & V_10 , & V_13 ) ;
V_18 = V_10 . V_20 ;
V_14 [ V_18 ] = V_13 ;
if ( V_13 && V_18 > V_16 )
V_16 = V_18 ;
if ( V_13 > V_17 )
V_17 = V_13 ;
V_9 = V_10 ;
}
printf ( L_1 ) ;
printf ( L_2 ) ;
for ( V_5 = 1 ; V_5 <= V_16 + 1 ; V_5 ++ ) {
F_1 ( V_11 , V_14 [ V_5 - 1 ] , V_17 , V_12 ) ;
printf ( L_3 ,
( 1l << V_5 ) >> 1 , ( 1l << V_5 ) - 1 , V_14 [ V_5 - 1 ] ,
V_12 , V_11 ) ;
}
}
static void F_5 ( int V_6 )
{
struct V_8 V_9 = {} , V_10 ;
static struct V_7 V_21 [ 1024 ] ;
int V_22 = 0 ;
int V_5 ;
while ( F_3 ( V_6 , & V_9 , & V_10 ) == 0 ) {
int V_23 = 0 ;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ )
if ( memcmp ( & V_21 [ V_5 ] , & V_10 , V_19 ) == 0 )
V_23 = 1 ;
if ( ! V_23 )
memcpy ( & V_21 [ V_22 ++ ] , & V_10 , V_19 ) ;
V_9 = V_10 ;
}
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ ) {
printf ( L_4 ,
( V_24 ) V_21 [ V_5 ] . V_25 ,
V_21 [ V_5 ] . V_26 ,
( V_24 ) V_21 [ V_5 ] . V_27 ) ;
F_2 ( V_6 , & V_21 [ V_5 ] ) ;
}
}
static void F_6 ( int V_28 )
{
F_5 ( V_29 [ 1 ] ) ;
exit ( 0 ) ;
}
int main ( int V_30 , char * * V_31 )
{
char V_32 [ 256 ] ;
long V_9 , V_10 , V_13 ;
T_1 * V_33 ;
int V_5 ;
snprintf ( V_32 , sizeof( V_32 ) , L_5 , V_31 [ 0 ] ) ;
signal ( V_34 , F_6 ) ;
V_33 = F_7 ( L_6 , L_7 ) ;
( void ) V_33 ;
V_33 = F_7 ( L_8 , L_7 ) ;
( void ) V_33 ;
if ( F_8 ( V_32 ) ) {
printf ( L_9 , V_35 ) ;
return 1 ;
}
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
V_9 = 0 ;
while ( F_3 ( V_29 [ 0 ] , & V_9 , & V_10 ) == 0 ) {
F_4 ( V_29 [ 0 ] , & V_10 , & V_13 ) ;
printf ( L_10 , V_10 , V_13 ) ;
V_9 = V_10 ;
}
if ( V_9 )
printf ( L_11 ) ;
F_9 ( 1 ) ;
}
F_5 ( V_29 [ 1 ] ) ;
return 0 ;
}
