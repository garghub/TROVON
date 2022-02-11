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
unsigned int V_11 = F_3 ( V_12 ) ;
long V_13 [ V_11 ] ;
char V_14 [ V_15 ] ;
long V_16 ;
long V_17 [ V_18 ] = {} ;
int V_19 = - 1 ;
long V_20 = 0 ;
int V_5 , V_21 ;
while ( F_4 ( V_6 , & V_9 , & V_10 ) == 0 ) {
if ( memcmp ( & V_10 , V_7 , V_22 ) ) {
V_9 = V_10 ;
continue;
}
F_5 ( V_6 , & V_10 , V_13 ) ;
V_16 = 0 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ )
V_16 += V_13 [ V_5 ] ;
V_21 = V_10 . V_23 ;
V_17 [ V_21 ] = V_16 ;
if ( V_16 && V_21 > V_19 )
V_19 = V_21 ;
if ( V_16 > V_20 )
V_20 = V_16 ;
V_9 = V_10 ;
}
printf ( L_1 ) ;
printf ( L_2 ) ;
for ( V_5 = 1 ; V_5 <= V_19 + 1 ; V_5 ++ ) {
F_1 ( V_14 , V_17 [ V_5 - 1 ] , V_20 , V_15 ) ;
printf ( L_3 ,
( 1l << V_5 ) >> 1 , ( 1l << V_5 ) - 1 , V_17 [ V_5 - 1 ] ,
V_15 , V_14 ) ;
}
}
static void F_6 ( int V_6 )
{
struct V_8 V_9 = {} , V_10 ;
static struct V_7 V_24 [ 1024 ] ;
int V_25 = 0 ;
int V_5 ;
while ( F_4 ( V_6 , & V_9 , & V_10 ) == 0 ) {
int V_26 = 0 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( memcmp ( & V_24 [ V_5 ] , & V_10 , V_22 ) == 0 )
V_26 = 1 ;
if ( ! V_26 )
memcpy ( & V_24 [ V_25 ++ ] , & V_10 , V_22 ) ;
V_9 = V_10 ;
}
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
printf ( L_4 ,
( V_27 ) V_24 [ V_5 ] . V_28 ,
V_24 [ V_5 ] . V_29 ,
( V_27 ) V_24 [ V_5 ] . V_30 ) ;
F_2 ( V_6 , & V_24 [ V_5 ] ) ;
}
}
static void F_7 ( int V_31 )
{
F_6 ( V_32 [ 1 ] ) ;
exit ( 0 ) ;
}
int main ( int V_33 , char * * V_34 )
{
char V_35 [ 256 ] ;
long V_9 , V_10 , V_16 ;
T_1 * V_36 ;
int V_5 ;
snprintf ( V_35 , sizeof( V_35 ) , L_5 , V_34 [ 0 ] ) ;
signal ( V_37 , F_7 ) ;
V_36 = F_8 ( L_6 , L_7 ) ;
( void ) V_36 ;
V_36 = F_8 ( L_8 , L_7 ) ;
( void ) V_36 ;
if ( F_9 ( V_35 ) ) {
printf ( L_9 , V_38 ) ;
return 1 ;
}
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
V_9 = 0 ;
while ( F_4 ( V_32 [ 0 ] , & V_9 , & V_10 ) == 0 ) {
F_5 ( V_32 [ 0 ] , & V_10 , & V_16 ) ;
printf ( L_10 , V_10 , V_16 ) ;
V_9 = V_10 ;
}
if ( V_9 )
printf ( L_11 ) ;
F_10 ( 1 ) ;
}
F_6 ( V_32 [ 1 ] ) ;
return 0 ;
}
