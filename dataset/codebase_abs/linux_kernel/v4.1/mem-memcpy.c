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
static void F_10 ( struct V_11 * V_12 , int V_13 , T_2 V_14 , double V_15 )
{
const struct V_16 * V_17 = & V_12 -> V_18 [ V_13 ] ;
double V_19 [ 2 ] ;
T_1 V_20 [ 2 ] ;
V_20 [ 0 ] = V_20 [ 1 ] = 0ULL ;
V_19 [ 0 ] = V_19 [ 1 ] = 0.0 ;
printf ( L_2 , V_17 -> V_21 , V_17 -> V_22 ) ;
if ( V_23 == V_24 )
printf ( L_3 , V_25 ) ;
if ( ! V_26 && ! V_27 ) {
if ( V_28 ) {
V_20 [ 0 ] = V_12 -> V_29 ( V_17 , V_14 , false ) ;
V_20 [ 1 ] = V_12 -> V_29 ( V_17 , V_14 , true ) ;
} else {
V_19 [ 0 ] = V_12 -> V_30 ( V_17 , V_14 , false ) ;
V_19 [ 1 ] = V_12 -> V_30 ( V_17 , V_14 , true ) ;
}
} else {
if ( V_28 )
V_20 [ V_31 ] = V_12 -> V_29 ( V_17 , V_14 , V_26 ) ;
else
V_19 [ V_31 ] = V_12 -> V_30 ( V_17 , V_14 , V_26 ) ;
}
switch ( V_23 ) {
case V_24 :
if ( ! V_26 && ! V_27 ) {
if ( V_28 ) {
printf ( L_4 ,
( double ) V_20 [ 0 ]
/ V_15 ) ;
printf ( L_5 ,
( double ) V_20 [ 1 ]
/ V_15 ) ;
} else {
F_11 ( V_19 [ 0 ] ) ;
printf ( L_6 ) ;
F_11 ( V_19 [ 1 ] ) ;
printf ( L_7 ) ;
}
} else {
if ( V_28 ) {
printf ( L_8 ,
( double ) V_20 [ V_31 ]
/ V_15 ) ;
} else
F_11 ( V_19 [ V_31 ] ) ;
printf ( L_9 , V_26 ? L_10 : L_11 ) ;
}
break;
case V_32 :
if ( ! V_26 && ! V_27 ) {
if ( V_28 ) {
printf ( L_12 ,
( double ) V_20 [ 0 ] / V_15 ,
( double ) V_20 [ 1 ] / V_15 ) ;
} else {
printf ( L_12 ,
V_19 [ 0 ] , V_19 [ 1 ] ) ;
}
} else {
if ( V_28 ) {
printf ( L_13 , ( double ) V_20 [ V_31 ]
/ V_15 ) ;
} else
printf ( L_13 , V_19 [ V_31 ] ) ;
}
break;
default:
F_5 ( L_14 , V_23 ) ;
break;
}
}
static int F_12 ( int V_33 , const char * * V_34 ,
const char * T_3 V_35 ,
struct V_11 * V_12 )
{
int V_36 ;
T_2 V_14 ;
double V_15 ;
V_33 = F_13 ( V_33 , V_34 , V_37 ,
V_12 -> V_38 , 0 ) ;
if ( V_27 && V_26 ) {
fprintf ( V_39 , L_15 ) ;
return 1 ;
}
if ( V_28 )
F_1 () ;
V_14 = ( T_2 ) F_14 ( ( char * ) V_25 ) ;
V_15 = ( double ) V_14 * V_40 ;
if ( ( V_41 ) V_14 <= 0 ) {
fprintf ( V_39 , L_16 , V_25 ) ;
return 1 ;
}
if ( V_26 && V_27 )
V_26 = V_27 = false ;
if ( ! strncmp ( V_16 , L_17 , 3 ) ) {
for ( V_36 = 0 ; V_12 -> V_18 [ V_36 ] . V_21 ; V_36 ++ )
F_10 ( V_12 , V_36 , V_14 , V_15 ) ;
return 0 ;
}
for ( V_36 = 0 ; V_12 -> V_18 [ V_36 ] . V_21 ; V_36 ++ ) {
if ( ! strcmp ( V_12 -> V_18 [ V_36 ] . V_21 , V_16 ) )
break;
}
if ( ! V_12 -> V_18 [ V_36 ] . V_21 ) {
printf ( L_18 , V_16 ) ;
printf ( L_19 ) ;
for ( V_36 = 0 ; V_12 -> V_18 [ V_36 ] . V_21 ; V_36 ++ ) {
printf ( L_20 ,
V_12 -> V_18 [ V_36 ] . V_21 , V_12 -> V_18 [ V_36 ] . V_22 ) ;
}
return 1 ;
}
F_10 ( V_12 , V_36 , V_14 , V_15 ) ;
return 0 ;
}
static void F_15 ( void * * V_42 , void * * V_43 , T_2 V_44 )
{
* V_42 = F_16 ( V_44 ) ;
if ( ! * V_42 )
F_5 ( L_21 ) ;
* V_43 = F_16 ( V_44 ) ;
if ( ! * V_43 )
F_5 ( L_21 ) ;
memset ( * V_43 , 0 , V_44 ) ;
}
static T_1 F_17 ( const struct V_16 * V_17 , T_2 V_14 , bool V_45 )
{
T_1 V_46 = 0ULL , V_47 = 0ULL ;
void * V_43 = NULL , * V_42 = NULL ;
T_4 V_48 = V_17 -> V_48 . memcpy ;
int V_36 ;
F_15 ( & V_42 , & V_43 , V_14 ) ;
if ( V_45 )
V_48 ( V_42 , V_43 , V_14 ) ;
V_46 = F_7 () ;
for ( V_36 = 0 ; V_36 < V_40 ; ++ V_36 )
V_48 ( V_42 , V_43 , V_14 ) ;
V_47 = F_7 () ;
free ( V_43 ) ;
free ( V_42 ) ;
return V_47 - V_46 ;
}
static double F_18 ( const struct V_16 * V_17 , T_2 V_14 ,
bool V_45 )
{
struct V_7 V_49 , V_50 , V_51 ;
T_4 V_48 = V_17 -> V_48 . memcpy ;
void * V_43 = NULL , * V_42 = NULL ;
int V_36 ;
F_15 ( & V_42 , & V_43 , V_14 ) ;
if ( V_45 )
V_48 ( V_42 , V_43 , V_14 ) ;
F_6 ( F_19 ( & V_49 , NULL ) ) ;
for ( V_36 = 0 ; V_36 < V_40 ; ++ V_36 )
V_48 ( V_42 , V_43 , V_14 ) ;
F_6 ( F_19 ( & V_50 , NULL ) ) ;
F_20 ( & V_50 , & V_49 , & V_51 ) ;
free ( V_43 ) ;
free ( V_42 ) ;
return ( double ) ( ( ( double ) V_14 * V_40 ) / F_9 ( & V_51 ) ) ;
}
int F_21 ( int V_33 , const char * * V_34 ,
const char * T_3 V_35 )
{
struct V_11 V_12 = {
. V_18 = V_52 ,
. V_29 = F_17 ,
. V_30 = F_18 ,
. V_38 = V_53 ,
} ;
return F_12 ( V_33 , V_34 , T_3 , & V_12 ) ;
}
static void F_22 ( void * * V_42 , T_2 V_44 )
{
* V_42 = F_16 ( V_44 ) ;
if ( ! * V_42 )
F_5 ( L_21 ) ;
}
static T_1 F_23 ( const struct V_16 * V_17 , T_2 V_14 , bool V_45 )
{
T_1 V_46 = 0ULL , V_47 = 0ULL ;
T_5 V_48 = V_17 -> V_48 . memset ;
void * V_42 = NULL ;
int V_36 ;
F_22 ( & V_42 , V_14 ) ;
if ( V_45 )
V_48 ( V_42 , - 1 , V_14 ) ;
V_46 = F_7 () ;
for ( V_36 = 0 ; V_36 < V_40 ; ++ V_36 )
V_48 ( V_42 , V_36 , V_14 ) ;
V_47 = F_7 () ;
free ( V_42 ) ;
return V_47 - V_46 ;
}
static double F_24 ( const struct V_16 * V_17 , T_2 V_14 ,
bool V_45 )
{
struct V_7 V_49 , V_50 , V_51 ;
T_5 V_48 = V_17 -> V_48 . memset ;
void * V_42 = NULL ;
int V_36 ;
F_22 ( & V_42 , V_14 ) ;
if ( V_45 )
V_48 ( V_42 , - 1 , V_14 ) ;
F_6 ( F_19 ( & V_49 , NULL ) ) ;
for ( V_36 = 0 ; V_36 < V_40 ; ++ V_36 )
V_48 ( V_42 , V_36 , V_14 ) ;
F_6 ( F_19 ( & V_50 , NULL ) ) ;
F_20 ( & V_50 , & V_49 , & V_51 ) ;
free ( V_42 ) ;
return ( double ) ( ( ( double ) V_14 * V_40 ) / F_9 ( & V_51 ) ) ;
}
int F_25 ( int V_33 , const char * * V_34 ,
const char * T_3 V_35 )
{
struct V_11 V_12 = {
. V_18 = V_54 ,
. V_29 = F_23 ,
. V_30 = F_24 ,
. V_38 = V_55 ,
} ;
return F_12 ( V_33 , V_34 , T_3 , & V_12 ) ;
}
