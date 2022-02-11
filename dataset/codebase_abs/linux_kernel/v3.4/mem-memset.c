static void F_1 ( void )
{
V_1 = F_2 ( & V_2 , F_3 () , - 1 , - 1 , 0 ) ;
if ( V_1 < 0 && V_3 == V_4 )
F_4 ( L_1 ) ;
else
F_5 ( V_1 < 0 ) ;
}
static T_1 F_6 ( void )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_7 ( V_1 , & V_6 , sizeof( T_1 ) ) ;
F_5 ( V_5 != sizeof( T_1 ) ) ;
return V_6 ;
}
static double F_8 ( struct V_7 * V_8 )
{
return ( double ) V_8 -> V_9 +
( double ) V_8 -> V_10 / ( double ) 1000000 ;
}
static void F_9 ( void * * V_11 , T_2 V_12 )
{
* V_11 = F_10 ( V_12 ) ;
if ( ! V_11 )
F_4 ( L_2 ) ;
}
static T_1 F_11 ( T_3 V_13 , T_2 V_14 , bool V_15 )
{
T_1 V_16 = 0ULL , V_17 = 0ULL ;
void * V_11 = NULL ;
int V_18 ;
F_9 ( & V_11 , V_14 ) ;
if ( V_15 )
V_13 ( V_11 , - 1 , V_14 ) ;
V_16 = F_6 () ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 )
V_13 ( V_11 , V_18 , V_14 ) ;
V_17 = F_6 () ;
free ( V_11 ) ;
return V_17 - V_16 ;
}
static double F_12 ( T_3 V_13 , T_2 V_14 , bool V_15 )
{
struct V_7 V_20 , V_21 , V_22 ;
void * V_11 = NULL ;
int V_18 ;
F_9 ( & V_11 , V_14 ) ;
if ( V_15 )
V_13 ( V_11 , - 1 , V_14 ) ;
F_5 ( F_13 ( & V_20 , NULL ) ) ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 )
V_13 ( V_11 , V_18 , V_14 ) ;
F_5 ( F_13 ( & V_21 , NULL ) ) ;
F_14 ( & V_21 , & V_20 , & V_22 ) ;
free ( V_11 ) ;
return ( double ) ( ( double ) V_14 / F_8 ( & V_22 ) ) ;
}
int F_15 ( int V_23 , const char * * V_24 ,
const char * T_4 V_25 )
{
int V_18 ;
T_2 V_14 ;
double V_26 [ 2 ] ;
T_1 V_27 [ 2 ] ;
V_23 = F_16 ( V_23 , V_24 , V_28 ,
V_29 , 0 ) ;
if ( V_30 )
F_1 () ;
V_14 = ( T_2 ) F_17 ( ( char * ) V_31 ) ;
V_27 [ 0 ] = V_27 [ 1 ] = 0ULL ;
V_26 [ 0 ] = V_26 [ 1 ] = 0.0 ;
if ( ( V_32 ) V_14 <= 0 ) {
fprintf ( V_33 , L_3 , V_31 ) ;
return 1 ;
}
if ( V_34 && V_35 )
V_34 = V_35 = false ;
for ( V_18 = 0 ; V_36 [ V_18 ] . V_37 ; V_18 ++ ) {
if ( ! strcmp ( V_36 [ V_18 ] . V_37 , V_38 ) )
break;
}
if ( ! V_36 [ V_18 ] . V_37 ) {
printf ( L_4 , V_38 ) ;
printf ( L_5 ) ;
for ( V_18 = 0 ; V_36 [ V_18 ] . V_37 ; V_18 ++ ) {
printf ( L_6 ,
V_36 [ V_18 ] . V_37 , V_36 [ V_18 ] . V_39 ) ;
}
return 1 ;
}
if ( V_40 == V_41 )
printf ( L_7 , V_31 ) ;
if ( ! V_34 && ! V_35 ) {
if ( V_30 ) {
V_27 [ 0 ] =
F_11 ( V_36 [ V_18 ] . V_13 , V_14 , false ) ;
V_27 [ 1 ] =
F_11 ( V_36 [ V_18 ] . V_13 , V_14 , true ) ;
} else {
V_26 [ 0 ] =
F_12 ( V_36 [ V_18 ] . V_13 ,
V_14 , false ) ;
V_26 [ 1 ] =
F_12 ( V_36 [ V_18 ] . V_13 ,
V_14 , true ) ;
}
} else {
if ( V_30 ) {
V_27 [ V_42 ] =
F_11 ( V_36 [ V_18 ] . V_13 ,
V_14 , V_34 ) ;
} else {
V_26 [ V_42 ] =
F_12 ( V_36 [ V_18 ] . V_13 ,
V_14 , V_34 ) ;
}
}
switch ( V_40 ) {
case V_41 :
if ( ! V_34 && ! V_35 ) {
if ( V_30 ) {
printf ( L_8 ,
( double ) V_27 [ 0 ]
/ ( double ) V_14 ) ;
printf ( L_9 ,
( double ) V_27 [ 1 ]
/ ( double ) V_14 ) ;
} else {
F_18 ( V_26 [ 0 ] ) ;
printf ( L_10 ) ;
F_18 ( V_26 [ 1 ] ) ;
printf ( L_11 ) ;
}
} else {
if ( V_30 ) {
printf ( L_12 ,
( double ) V_27 [ V_42 ]
/ ( double ) V_14 ) ;
} else
F_18 ( V_26 [ V_42 ] ) ;
printf ( L_13 , V_34 ? L_14 : L_15 ) ;
}
break;
case V_43 :
if ( ! V_34 && ! V_35 ) {
if ( V_30 ) {
printf ( L_16 ,
( double ) V_27 [ 0 ] / ( double ) V_14 ,
( double ) V_27 [ 1 ] / ( double ) V_14 ) ;
} else {
printf ( L_16 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
}
} else {
if ( V_30 ) {
printf ( L_17 , ( double ) V_27 [ V_42 ]
/ ( double ) V_14 ) ;
} else
printf ( L_17 , V_26 [ V_42 ] ) ;
}
break;
default:
F_4 ( L_18 , V_40 ) ;
break;
}
return 0 ;
}
