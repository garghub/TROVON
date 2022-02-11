static void F_1 ( int V_1 )
{
F_2 ( V_2 , - 1 , V_3 ) ;
if ( V_4 )
F_2 ( V_5 , - 1 , V_3 ) ;
exit ( 0 ) ;
}
static void F_3 ( int V_6 , int V_7 )
{
unsigned int V_8 = F_4 () ;
T_1 V_9 [ V_8 ] , V_10 [ V_8 ] ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
while ( 1 ) {
T_1 V_11 = 0 ;
T_2 V_12 = 0 ;
int V_13 ;
F_5 ( V_6 ) ;
assert ( F_6 ( V_14 [ 1 ] , & V_12 , V_9 ) == 0 ) ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ )
V_11 += ( V_9 [ V_13 ] - V_10 [ V_13 ] ) ;
if ( V_11 )
printf ( L_1 ,
V_7 , V_11 / V_6 ) ;
memcpy ( V_10 , V_9 , sizeof( V_9 ) ) ;
}
}
static void F_7 ( const char * V_15 )
{
fprintf ( V_16 ,
L_2
L_3
L_4
L_5 ,
V_15 ) ;
}
int main ( int V_17 , char * * V_18 )
{
const char * V_19 = L_6 ;
char V_20 [ 256 ] ;
int V_21 , V_22 , V_12 = 0 ;
while ( ( V_22 = F_8 ( V_17 , V_18 , V_19 ) ) != - 1 ) {
switch ( V_22 ) {
case 'S' :
V_3 |= V_23 ;
break;
case 'N' :
V_3 |= V_24 ;
break;
default:
F_7 ( F_9 ( V_18 [ 0 ] ) ) ;
return 1 ;
}
}
if ( V_25 == V_17 ) {
printf ( L_7 , V_18 [ 0 ] ) ;
return 1 ;
}
V_2 = strtoul ( V_18 [ V_25 ] , NULL , 0 ) ;
V_5 = strtoul ( V_18 [ V_25 + 1 ] , NULL , 0 ) ;
printf ( L_8 , V_2 , V_5 ) ;
snprintf ( V_20 , sizeof( V_20 ) , L_9 , V_18 [ 0 ] ) ;
if ( F_10 ( V_20 ) ) {
printf ( L_10 , V_26 ) ;
return 1 ;
}
if ( ! V_27 [ 0 ] ) {
printf ( L_11 , strerror ( V_28 ) ) ;
return 1 ;
}
if ( F_2 ( V_2 , V_27 [ 0 ] , V_3 ) < 0 ) {
printf ( L_12 , V_2 ) ;
return 1 ;
}
if ( F_2 ( V_5 , V_27 [ 1 ] ,
( V_3 | V_29 ) ) < 0 ) {
printf ( L_13 , V_5 ) ;
V_4 = false ;
}
signal ( V_30 , F_1 ) ;
signal ( V_31 , F_1 ) ;
V_21 = F_11 ( V_14 [ 0 ] , & V_12 , & V_5 , 0 ) ;
if ( V_21 ) {
perror ( L_14 ) ;
goto V_32;
}
F_3 ( 2 , V_5 ) ;
V_32:
return 0 ;
}
