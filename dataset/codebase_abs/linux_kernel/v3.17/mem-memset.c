static void F_1 ( void )
{
V_1 = F_2 ( & V_2 , F_3 () , - 1 , - 1 ,
F_4 () ) ;
if ( V_1 < 0 && V_3 == V_4 )
F_5 ( L_1 ) ;
else
F_6 ( V_1 < 0 ) ;
}
static T_1 F_7 ( void )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_8 ( V_1 , & V_6 , sizeof( T_1 ) ) ;
F_6 ( V_5 != sizeof( T_1 ) ) ;
return V_6 ;
}
static double F_9 ( struct V_7 * V_8 )
{
return ( double ) V_8 -> V_9 +
( double ) V_8 -> V_10 / ( double ) 1000000 ;
}
static void F_10 ( void * * V_11 , T_2 V_12 )
{
* V_11 = F_11 ( V_12 ) ;
if ( ! * V_11 )
F_5 ( L_2 ) ;
}
static T_1 F_12 ( T_3 V_13 , T_2 V_14 , bool V_15 )
{
T_1 V_16 = 0ULL , V_17 = 0ULL ;
void * V_11 = NULL ;
int V_18 ;
F_10 ( & V_11 , V_14 ) ;
if ( V_15 )
V_13 ( V_11 , - 1 , V_14 ) ;
V_16 = F_7 () ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 )
V_13 ( V_11 , V_18 , V_14 ) ;
V_17 = F_7 () ;
free ( V_11 ) ;
return V_17 - V_16 ;
}
static double F_13 ( T_3 V_13 , T_2 V_14 , bool V_15 )
{
struct V_7 V_20 , V_21 , V_22 ;
void * V_11 = NULL ;
int V_18 ;
F_10 ( & V_11 , V_14 ) ;
if ( V_15 )
V_13 ( V_11 , - 1 , V_14 ) ;
F_6 ( F_14 ( & V_20 , NULL ) ) ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 )
V_13 ( V_11 , V_18 , V_14 ) ;
F_6 ( F_14 ( & V_21 , NULL ) ) ;
F_15 ( & V_21 , & V_20 , & V_22 ) ;
free ( V_11 ) ;
return ( double ) ( ( double ) V_14 / F_9 ( & V_22 ) ) ;
}
int F_16 ( int V_23 , const char * * V_24 ,
const char * T_4 V_25 )
{
int V_18 ;
T_2 V_14 ;
double V_26 [ 2 ] ;
T_1 V_27 [ 2 ] ;
V_23 = F_17 ( V_23 , V_24 , V_28 ,
V_29 , 0 ) ;
if ( V_30 && V_31 ) {
fprintf ( V_32 , L_3 ) ;
return 1 ;
}
if ( V_33 )
F_1 () ;
V_14 = ( T_2 ) F_18 ( ( char * ) V_34 ) ;
V_27 [ 0 ] = V_27 [ 1 ] = 0ULL ;
V_26 [ 0 ] = V_26 [ 1 ] = 0.0 ;
if ( ( V_35 ) V_14 <= 0 ) {
fprintf ( V_32 , L_4 , V_34 ) ;
return 1 ;
}
if ( V_31 && V_30 )
V_31 = V_30 = false ;
for ( V_18 = 0 ; V_36 [ V_18 ] . V_37 ; V_18 ++ ) {
if ( ! strcmp ( V_36 [ V_18 ] . V_37 , V_38 ) )
break;
}
if ( ! V_36 [ V_18 ] . V_37 ) {
printf ( L_5 , V_38 ) ;
printf ( L_6 ) ;
for ( V_18 = 0 ; V_36 [ V_18 ] . V_37 ; V_18 ++ ) {
printf ( L_7 ,
V_36 [ V_18 ] . V_37 , V_36 [ V_18 ] . V_39 ) ;
}
return 1 ;
}
if ( V_40 == V_41 )
printf ( L_8 , V_34 ) ;
if ( ! V_31 && ! V_30 ) {
if ( V_33 ) {
V_27 [ 0 ] =
F_12 ( V_36 [ V_18 ] . V_13 , V_14 , false ) ;
V_27 [ 1 ] =
F_12 ( V_36 [ V_18 ] . V_13 , V_14 , true ) ;
} else {
V_26 [ 0 ] =
F_13 ( V_36 [ V_18 ] . V_13 ,
V_14 , false ) ;
V_26 [ 1 ] =
F_13 ( V_36 [ V_18 ] . V_13 ,
V_14 , true ) ;
}
} else {
if ( V_33 ) {
V_27 [ V_42 ] =
F_12 ( V_36 [ V_18 ] . V_13 ,
V_14 , V_31 ) ;
} else {
V_26 [ V_42 ] =
F_13 ( V_36 [ V_18 ] . V_13 ,
V_14 , V_31 ) ;
}
}
switch ( V_40 ) {
case V_41 :
if ( ! V_31 && ! V_30 ) {
if ( V_33 ) {
printf ( L_9 ,
( double ) V_27 [ 0 ]
/ ( double ) V_14 ) ;
printf ( L_10 ,
( double ) V_27 [ 1 ]
/ ( double ) V_14 ) ;
} else {
F_19 ( V_26 [ 0 ] ) ;
printf ( L_11 ) ;
F_19 ( V_26 [ 1 ] ) ;
printf ( L_12 ) ;
}
} else {
if ( V_33 ) {
printf ( L_13 ,
( double ) V_27 [ V_42 ]
/ ( double ) V_14 ) ;
} else
F_19 ( V_26 [ V_42 ] ) ;
printf ( L_14 , V_31 ? L_15 : L_16 ) ;
}
break;
case V_43 :
if ( ! V_31 && ! V_30 ) {
if ( V_33 ) {
printf ( L_17 ,
( double ) V_27 [ 0 ] / ( double ) V_14 ,
( double ) V_27 [ 1 ] / ( double ) V_14 ) ;
} else {
printf ( L_17 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
}
} else {
if ( V_33 ) {
printf ( L_18 , ( double ) V_27 [ V_42 ]
/ ( double ) V_14 ) ;
} else
printf ( L_18 , V_26 [ V_42 ] ) ;
}
break;
default:
F_5 ( L_19 , V_40 ) ;
break;
}
return 0 ;
}
