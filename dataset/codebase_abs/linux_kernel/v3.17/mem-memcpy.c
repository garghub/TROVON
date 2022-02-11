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
static void F_10 ( void * * V_11 , void * * V_12 , T_2 V_13 )
{
* V_11 = F_11 ( V_13 ) ;
if ( ! * V_11 )
F_5 ( L_2 ) ;
* V_12 = F_11 ( V_13 ) ;
if ( ! * V_12 )
F_5 ( L_2 ) ;
memset ( * V_12 , 0 , V_13 ) ;
}
static T_1 F_12 ( T_3 V_14 , T_2 V_15 , bool V_16 )
{
T_1 V_17 = 0ULL , V_18 = 0ULL ;
void * V_12 = NULL , * V_11 = NULL ;
int V_19 ;
F_10 ( & V_12 , & V_11 , V_15 ) ;
if ( V_16 )
V_14 ( V_11 , V_12 , V_15 ) ;
V_17 = F_7 () ;
for ( V_19 = 0 ; V_19 < V_20 ; ++ V_19 )
V_14 ( V_11 , V_12 , V_15 ) ;
V_18 = F_7 () ;
free ( V_12 ) ;
free ( V_11 ) ;
return V_18 - V_17 ;
}
static double F_13 ( T_3 V_14 , T_2 V_15 , bool V_16 )
{
struct V_7 V_21 , V_22 , V_23 ;
void * V_12 = NULL , * V_11 = NULL ;
int V_19 ;
F_10 ( & V_12 , & V_11 , V_15 ) ;
if ( V_16 )
V_14 ( V_11 , V_12 , V_15 ) ;
F_6 ( F_14 ( & V_21 , NULL ) ) ;
for ( V_19 = 0 ; V_19 < V_20 ; ++ V_19 )
V_14 ( V_11 , V_12 , V_15 ) ;
F_6 ( F_14 ( & V_22 , NULL ) ) ;
F_15 ( & V_22 , & V_21 , & V_23 ) ;
free ( V_12 ) ;
free ( V_11 ) ;
return ( double ) ( ( double ) V_15 / F_9 ( & V_23 ) ) ;
}
int F_16 ( int V_24 , const char * * V_25 ,
const char * T_4 V_26 )
{
int V_19 ;
T_2 V_15 ;
double V_27 [ 2 ] ;
T_1 V_28 [ 2 ] ;
V_24 = F_17 ( V_24 , V_25 , V_29 ,
V_30 , 0 ) ;
if ( V_31 && V_32 ) {
fprintf ( V_33 , L_3 ) ;
return 1 ;
}
if ( V_34 )
F_1 () ;
V_15 = ( T_2 ) F_18 ( ( char * ) V_35 ) ;
V_28 [ 0 ] = V_28 [ 1 ] = 0ULL ;
V_27 [ 0 ] = V_27 [ 1 ] = 0.0 ;
if ( ( V_36 ) V_15 <= 0 ) {
fprintf ( V_33 , L_4 , V_35 ) ;
return 1 ;
}
if ( V_32 && V_31 )
V_32 = V_31 = false ;
for ( V_19 = 0 ; V_37 [ V_19 ] . V_38 ; V_19 ++ ) {
if ( ! strcmp ( V_37 [ V_19 ] . V_38 , V_39 ) )
break;
}
if ( ! V_37 [ V_19 ] . V_38 ) {
printf ( L_5 , V_39 ) ;
printf ( L_6 ) ;
for ( V_19 = 0 ; V_37 [ V_19 ] . V_38 ; V_19 ++ ) {
printf ( L_7 ,
V_37 [ V_19 ] . V_38 , V_37 [ V_19 ] . V_40 ) ;
}
return 1 ;
}
if ( V_41 == V_42 )
printf ( L_8 , V_35 ) ;
if ( ! V_32 && ! V_31 ) {
if ( V_34 ) {
V_28 [ 0 ] =
F_12 ( V_37 [ V_19 ] . V_14 , V_15 , false ) ;
V_28 [ 1 ] =
F_12 ( V_37 [ V_19 ] . V_14 , V_15 , true ) ;
} else {
V_27 [ 0 ] =
F_13 ( V_37 [ V_19 ] . V_14 ,
V_15 , false ) ;
V_27 [ 1 ] =
F_13 ( V_37 [ V_19 ] . V_14 ,
V_15 , true ) ;
}
} else {
if ( V_34 ) {
V_28 [ V_43 ] =
F_12 ( V_37 [ V_19 ] . V_14 ,
V_15 , V_32 ) ;
} else {
V_27 [ V_43 ] =
F_13 ( V_37 [ V_19 ] . V_14 ,
V_15 , V_32 ) ;
}
}
switch ( V_41 ) {
case V_42 :
if ( ! V_32 && ! V_31 ) {
if ( V_34 ) {
printf ( L_9 ,
( double ) V_28 [ 0 ]
/ ( double ) V_15 ) ;
printf ( L_10 ,
( double ) V_28 [ 1 ]
/ ( double ) V_15 ) ;
} else {
F_19 ( V_27 [ 0 ] ) ;
printf ( L_11 ) ;
F_19 ( V_27 [ 1 ] ) ;
printf ( L_12 ) ;
}
} else {
if ( V_34 ) {
printf ( L_13 ,
( double ) V_28 [ V_43 ]
/ ( double ) V_15 ) ;
} else
F_19 ( V_27 [ V_43 ] ) ;
printf ( L_14 , V_32 ? L_15 : L_16 ) ;
}
break;
case V_44 :
if ( ! V_32 && ! V_31 ) {
if ( V_34 ) {
printf ( L_17 ,
( double ) V_28 [ 0 ] / ( double ) V_15 ,
( double ) V_28 [ 1 ] / ( double ) V_15 ) ;
} else {
printf ( L_17 ,
V_27 [ 0 ] , V_27 [ 1 ] ) ;
}
} else {
if ( V_34 ) {
printf ( L_18 , ( double ) V_28 [ V_43 ]
/ ( double ) V_15 ) ;
} else
printf ( L_18 , V_27 [ V_43 ] ) ;
}
break;
default:
F_5 ( L_19 , V_41 ) ;
break;
}
return 0 ;
}
