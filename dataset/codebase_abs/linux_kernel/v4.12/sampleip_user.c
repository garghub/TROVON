static void F_1 ( void )
{
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
}
static int F_2 ( int * V_1 , int V_2 )
{
int V_3 ;
struct V_4 V_5 = {
. type = V_6 ,
. V_2 = 1 ,
. V_7 = V_2 ,
. V_8 = V_9 ,
. V_10 = 1 ,
} ;
for ( V_3 = 0 ; V_3 < V_11 ; V_3 ++ ) {
V_1 [ V_3 ] = F_3 ( & V_5 , - 1 , V_3 ,
- 1 , 0 ) ;
if ( V_1 [ V_3 ] < 0 ) {
fprintf ( V_12 , L_4 ) ;
return 1 ;
}
assert ( F_4 ( V_1 [ V_3 ] , V_13 ,
V_14 [ 0 ] ) == 0 ) ;
assert ( F_4 ( V_1 [ V_3 ] , V_15 , 0 ) == 0 ) ;
}
return 0 ;
}
static void F_5 ( int * V_1 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_11 ; V_3 ++ )
F_6 ( V_1 [ V_3 ] ) ;
}
static int F_7 ( const void * V_16 , const void * V_17 )
{
return ( (struct V_18 * ) V_16 ) -> V_19 - ( (struct V_18 * ) V_17 ) -> V_19 ;
}
static void F_8 ( int V_20 )
{
struct V_21 * V_22 ;
T_1 V_23 , V_24 ;
T_2 V_25 ;
int V_3 , V_26 ;
printf ( L_5 , L_6 , L_7 , L_8 ) ;
V_23 = 0 , V_3 = 0 ;
while ( F_9 ( V_20 , & V_23 , & V_24 ) == 0 ) {
F_10 ( V_20 , & V_24 , & V_25 ) ;
V_27 [ V_3 ] . V_28 = V_24 ;
V_27 [ V_3 ++ ] . V_19 = V_25 ;
V_23 = V_24 ;
}
V_26 = V_3 ;
qsort ( V_27 , V_26 , sizeof( struct V_18 ) , F_7 ) ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
if ( V_27 [ V_3 ] . V_28 > V_29 ) {
V_22 = F_11 ( V_27 [ V_3 ] . V_28 ) ;
printf ( L_9 , V_27 [ V_3 ] . V_28 , V_22 -> V_30 ,
V_27 [ V_3 ] . V_19 ) ;
} else {
printf ( L_9 , V_27 [ V_3 ] . V_28 , L_10 ,
V_27 [ V_3 ] . V_19 ) ;
}
}
if ( V_26 == V_31 ) {
printf ( L_11 , V_26 ) ;
printf ( L_12 ) ;
}
}
static void F_12 ( int V_32 )
{
printf ( L_13 ) ;
F_8 ( V_33 [ 0 ] ) ;
exit ( 0 ) ;
}
int main ( int V_34 , char * * V_35 )
{
char V_36 [ 256 ] ;
int * V_1 , V_37 , V_2 = V_38 , V_39 = V_40 ;
while ( ( V_37 = F_13 ( V_34 , V_35 , L_14 ) ) != - 1 ) {
switch ( V_37 ) {
case 'F' :
V_2 = atoi ( V_41 ) ;
break;
case 'h' :
default:
F_1 () ;
return 0 ;
}
}
if ( V_34 - V_42 == 1 )
V_39 = atoi ( V_35 [ V_42 ] ) ;
if ( V_2 == 0 || V_39 == 0 ) {
F_1 () ;
return 1 ;
}
if ( F_14 () ) {
fprintf ( V_12 , L_15 ) ;
return 2 ;
}
V_11 = F_15 ( V_43 ) ;
V_1 = malloc ( V_11 * sizeof( int ) ) ;
if ( V_1 == NULL ) {
fprintf ( V_12 , L_16 ) ;
return 1 ;
}
snprintf ( V_36 , sizeof( V_36 ) , L_17 , V_35 [ 0 ] ) ;
if ( F_16 ( V_36 ) ) {
fprintf ( V_12 , L_18 ,
V_44 ) ;
if ( strcmp ( V_45 , L_19 ) == 0 )
fprintf ( V_12 , L_20 ) ;
else
fprintf ( V_12 , L_21 , V_45 ) ;
return 1 ;
}
signal ( V_46 , F_12 ) ;
signal ( V_47 , F_12 ) ;
printf ( L_22 ,
V_2 , V_39 ) ;
if ( F_2 ( V_1 , V_2 ) != 0 )
return 1 ;
F_17 ( V_39 ) ;
F_5 ( V_1 ) ;
free ( V_1 ) ;
F_8 ( V_33 [ 0 ] ) ;
return 0 ;
}
