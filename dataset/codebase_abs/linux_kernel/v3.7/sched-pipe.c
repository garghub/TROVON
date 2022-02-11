int F_1 ( int V_1 , const char * * V_2 ,
const char * T_1 V_3 )
{
int V_4 [ 2 ] , V_5 [ 2 ] ;
int V_6 = 0 , V_7 ;
struct V_8 V_9 , V_10 , V_11 ;
unsigned long long V_12 = 0 ;
int V_3 V_13 , V_14 ;
T_2 V_15 , V_16 V_3 ;
V_1 = F_2 ( V_1 , V_2 , V_17 ,
V_18 , 0 ) ;
F_3 ( F_4 ( V_4 ) ) ;
F_3 ( F_4 ( V_5 ) ) ;
V_15 = F_5 () ;
assert ( V_15 >= 0 ) ;
F_6 ( & V_9 , NULL ) ;
if ( ! V_15 ) {
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ ) {
V_13 = F_7 ( V_4 [ 0 ] , & V_6 , sizeof( int ) ) ;
V_13 = F_8 ( V_5 [ 1 ] , & V_6 , sizeof( int ) ) ;
}
} else {
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ ) {
V_13 = F_8 ( V_4 [ 1 ] , & V_6 , sizeof( int ) ) ;
V_13 = F_7 ( V_5 [ 0 ] , & V_6 , sizeof( int ) ) ;
}
}
F_6 ( & V_10 , NULL ) ;
F_9 ( & V_10 , & V_9 , & V_11 ) ;
if ( V_15 ) {
V_16 = F_10 ( V_15 , & V_14 , 0 ) ;
assert ( ( V_16 == V_15 ) && F_11 ( V_14 ) ) ;
} else {
exit ( 0 ) ;
}
switch ( V_20 ) {
case V_21 :
printf ( L_1 ,
V_19 ) ;
V_12 = V_11 . V_22 * 1000000 ;
V_12 += V_11 . V_23 ;
printf ( L_2 , L_3 ,
V_11 . V_22 ,
( unsigned long ) ( V_11 . V_23 / 1000 ) ) ;
printf ( L_4 ,
( double ) V_12 / ( double ) V_19 ) ;
printf ( L_5 ,
( int ) ( ( double ) V_19 /
( ( double ) V_12 / ( double ) 1000000 ) ) ) ;
break;
case V_24 :
printf ( L_6 ,
V_11 . V_22 ,
( unsigned long ) ( V_11 . V_23 / 1000 ) ) ;
break;
default:
fprintf ( V_25 , L_7 , V_20 ) ;
exit ( 1 ) ;
break;
}
return 0 ;
}
