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
unsigned int V_8 = F_3 () ;
struct V_9 V_10 = {} , V_11 ;
long V_12 [ V_8 ] ;
char V_13 [ V_14 ] ;
long V_15 ;
long V_16 [ V_17 ] = {} ;
int V_18 = - 1 ;
long V_19 = 0 ;
int V_5 , V_20 ;
while ( F_4 ( V_6 , & V_10 , & V_11 ) == 0 ) {
if ( memcmp ( & V_11 , V_7 , V_21 ) ) {
V_10 = V_11 ;
continue;
}
F_5 ( V_6 , & V_11 , V_12 ) ;
V_15 = 0 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
V_15 += V_12 [ V_5 ] ;
V_20 = V_11 . V_22 ;
V_16 [ V_20 ] = V_15 ;
if ( V_15 && V_20 > V_18 )
V_18 = V_20 ;
if ( V_15 > V_19 )
V_19 = V_15 ;
V_10 = V_11 ;
}
printf ( L_1 ) ;
printf ( L_2 ) ;
for ( V_5 = 1 ; V_5 <= V_18 + 1 ; V_5 ++ ) {
F_1 ( V_13 , V_16 [ V_5 - 1 ] , V_19 , V_14 ) ;
printf ( L_3 ,
( 1l << V_5 ) >> 1 , ( 1l << V_5 ) - 1 , V_16 [ V_5 - 1 ] ,
V_14 , V_13 ) ;
}
}
static void F_6 ( int V_6 )
{
struct V_9 V_10 = {} , V_11 ;
static struct V_7 V_23 [ 1024 ] ;
int V_24 = 0 ;
int V_5 ;
while ( F_4 ( V_6 , & V_10 , & V_11 ) == 0 ) {
int V_25 = 0 ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ )
if ( memcmp ( & V_23 [ V_5 ] , & V_11 , V_21 ) == 0 )
V_25 = 1 ;
if ( ! V_25 )
memcpy ( & V_23 [ V_24 ++ ] , & V_11 , V_21 ) ;
V_10 = V_11 ;
}
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
printf ( L_4 ,
( V_26 ) V_23 [ V_5 ] . V_27 ,
V_23 [ V_5 ] . V_28 ,
( V_26 ) V_23 [ V_5 ] . V_29 ) ;
F_2 ( V_6 , & V_23 [ V_5 ] ) ;
}
}
static void F_7 ( int V_30 )
{
F_6 ( V_31 [ 1 ] ) ;
exit ( 0 ) ;
}
int main ( int V_32 , char * * V_33 )
{
struct V_34 V_35 = { 1024 * 1024 , V_36 } ;
char V_37 [ 256 ] ;
long V_10 , V_11 , V_15 ;
T_1 * V_38 ;
int V_5 ;
snprintf ( V_37 , sizeof( V_37 ) , L_5 , V_33 [ 0 ] ) ;
if ( F_8 ( V_39 , & V_35 ) ) {
perror ( L_6 ) ;
return 1 ;
}
signal ( V_40 , F_7 ) ;
signal ( V_41 , F_7 ) ;
V_38 = F_9 ( L_7 , L_8 ) ;
( void ) V_38 ;
V_38 = F_9 ( L_9 , L_8 ) ;
( void ) V_38 ;
if ( F_10 ( V_37 ) ) {
printf ( L_10 , V_42 ) ;
return 1 ;
}
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
V_10 = 0 ;
while ( F_4 ( V_31 [ 0 ] , & V_10 , & V_11 ) == 0 ) {
F_5 ( V_31 [ 0 ] , & V_11 , & V_15 ) ;
printf ( L_11 , V_11 , V_15 ) ;
V_10 = V_11 ;
}
if ( V_10 )
printf ( L_12 ) ;
F_11 ( 1 ) ;
}
F_6 ( V_31 [ 1 ] ) ;
return 0 ;
}
