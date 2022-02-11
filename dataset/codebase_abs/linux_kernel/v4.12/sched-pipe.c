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
int F_5 ( int V_11 , const char * * V_12 )
{
struct V_2 V_13 [ 2 ] , * V_3 ;
int V_14 [ 2 ] , V_15 [ 2 ] ;
struct V_16 V_17 , V_18 , V_19 ;
unsigned long long V_20 = 0 ;
int V_21 = 2 ;
int V_22 ;
int T_1 V_6 , V_23 ;
T_2 V_24 , V_25 T_1 ;
V_11 = F_6 ( V_11 , V_12 , V_26 , V_27 , 0 ) ;
F_3 ( F_7 ( V_14 ) ) ;
F_3 ( F_7 ( V_15 ) ) ;
F_8 ( & V_17 , NULL ) ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_3 = V_13 + V_22 ;
V_3 -> V_8 = V_22 ;
if ( V_22 == 0 ) {
V_3 -> V_9 = V_14 [ 0 ] ;
V_3 -> V_10 = V_15 [ 1 ] ;
} else {
V_3 -> V_10 = V_14 [ 1 ] ;
V_3 -> V_9 = V_15 [ 0 ] ;
}
}
if ( V_28 ) {
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_3 = V_13 + V_22 ;
V_6 = F_9 ( & V_3 -> V_29 , NULL , F_1 , V_3 ) ;
F_3 ( V_6 ) ;
}
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_3 = V_13 + V_22 ;
V_6 = F_10 ( V_3 -> V_29 , NULL ) ;
F_3 ( V_6 ) ;
}
} else {
V_24 = F_11 () ;
assert ( V_24 >= 0 ) ;
if ( ! V_24 ) {
F_1 ( V_13 + 0 ) ;
exit ( 0 ) ;
} else {
F_1 ( V_13 + 1 ) ;
}
V_25 = F_12 ( V_24 , & V_23 , 0 ) ;
assert ( ( V_25 == V_24 ) && F_13 ( V_23 ) ) ;
}
F_8 ( & V_18 , NULL ) ;
F_14 ( & V_18 , & V_17 , & V_19 ) ;
switch ( V_30 ) {
case V_31 :
printf ( L_1 ,
V_7 , V_28 ? L_2 : L_3 ) ;
V_20 = V_19 . V_32 * V_33 ;
V_20 += V_19 . V_34 ;
printf ( L_4 , L_5 ,
V_19 . V_32 ,
( unsigned long ) ( V_19 . V_34 / V_35 ) ) ;
printf ( L_6 ,
( double ) V_20 / ( double ) V_7 ) ;
printf ( L_7 ,
( int ) ( ( double ) V_7 /
( ( double ) V_20 / ( double ) V_33 ) ) ) ;
break;
case V_36 :
printf ( L_8 ,
V_19 . V_32 ,
( unsigned long ) ( V_19 . V_34 / V_35 ) ) ;
break;
default:
fprintf ( V_37 , L_9 , V_30 ) ;
exit ( 1 ) ;
break;
}
return 0 ;
}
