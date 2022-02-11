static void * F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
int V_4 = 0 , V_5 ;
int V_6 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( ! V_3 -> V_8 ) {
V_6 = F_2 ( V_3 -> V_9 , & V_4 , sizeof( int ) ) ;
F_3 ( V_6 != sizeof( int ) ) ;
V_6 = F_4 ( V_3 -> V_10 , & V_4 , sizeof( int ) ) ;
F_3 ( V_6 != sizeof( int ) ) ;
} else {
V_6 = F_4 ( V_3 -> V_10 , & V_4 , sizeof( int ) ) ;
F_3 ( V_6 != sizeof( int ) ) ;
V_6 = F_2 ( V_3 -> V_9 , & V_4 , sizeof( int ) ) ;
F_3 ( V_6 != sizeof( int ) ) ;
}
}
return NULL ;
}
int F_5 ( int V_11 , const char * * V_12 , const char * T_1 V_13 )
{
struct V_2 V_14 [ 2 ] , * V_3 ;
int V_15 [ 2 ] , V_16 [ 2 ] ;
struct V_17 V_18 , V_19 , V_20 ;
unsigned long long V_21 = 0 ;
int V_22 = 2 ;
int V_23 ;
int V_13 V_6 , V_24 ;
T_2 V_25 , V_26 V_13 ;
V_11 = F_6 ( V_11 , V_12 , V_27 , V_28 , 0 ) ;
F_3 ( F_7 ( V_15 ) ) ;
F_3 ( F_7 ( V_16 ) ) ;
F_8 ( & V_18 , NULL ) ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_3 = V_14 + V_23 ;
V_3 -> V_8 = V_23 ;
if ( V_23 == 0 ) {
V_3 -> V_9 = V_15 [ 0 ] ;
V_3 -> V_10 = V_16 [ 1 ] ;
} else {
V_3 -> V_10 = V_15 [ 1 ] ;
V_3 -> V_9 = V_16 [ 0 ] ;
}
}
if ( V_29 ) {
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_3 = V_14 + V_23 ;
V_6 = F_9 ( & V_3 -> V_30 , NULL , F_1 , V_3 ) ;
F_3 ( V_6 ) ;
}
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_3 = V_14 + V_23 ;
V_6 = F_10 ( V_3 -> V_30 , NULL ) ;
F_3 ( V_6 ) ;
}
} else {
V_25 = F_11 () ;
assert ( V_25 >= 0 ) ;
if ( ! V_25 ) {
F_1 ( V_14 + 0 ) ;
exit ( 0 ) ;
} else {
F_1 ( V_14 + 1 ) ;
}
V_26 = F_12 ( V_25 , & V_24 , 0 ) ;
assert ( ( V_26 == V_25 ) && F_13 ( V_24 ) ) ;
}
F_8 ( & V_19 , NULL ) ;
F_14 ( & V_19 , & V_18 , & V_20 ) ;
switch ( V_31 ) {
case V_32 :
printf ( L_1 ,
V_7 , V_29 ? L_2 : L_3 ) ;
V_21 = V_20 . V_33 * 1000000 ;
V_21 += V_20 . V_34 ;
printf ( L_4 , L_5 ,
V_20 . V_33 ,
( unsigned long ) ( V_20 . V_34 / 1000 ) ) ;
printf ( L_6 ,
( double ) V_21 / ( double ) V_7 ) ;
printf ( L_7 ,
( int ) ( ( double ) V_7 /
( ( double ) V_21 / ( double ) 1000000 ) ) ) ;
break;
case V_35 :
printf ( L_8 ,
V_20 . V_33 ,
( unsigned long ) ( V_20 . V_34 / 1000 ) ) ;
break;
default:
fprintf ( V_36 , L_9 , V_31 ) ;
exit ( 1 ) ;
break;
}
return 0 ;
}
