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
static int F_10 ( int V_11 , const char * * V_12 ,
const char * T_2 V_13 ,
struct V_14 * V_15 )
{
int V_16 ;
T_3 V_17 ;
double V_18 ;
double V_19 [ 2 ] ;
T_1 V_20 [ 2 ] ;
V_11 = F_11 ( V_11 , V_12 , V_21 ,
V_15 -> V_22 , 0 ) ;
if ( V_23 && V_24 ) {
fprintf ( V_25 , L_2 ) ;
return 1 ;
}
if ( V_26 )
F_1 () ;
V_17 = ( T_3 ) F_12 ( ( char * ) V_27 ) ;
V_18 = ( double ) V_17 * V_28 ;
V_20 [ 0 ] = V_20 [ 1 ] = 0ULL ;
V_19 [ 0 ] = V_19 [ 1 ] = 0.0 ;
if ( ( V_29 ) V_17 <= 0 ) {
fprintf ( V_25 , L_3 , V_27 ) ;
return 1 ;
}
if ( V_24 && V_23 )
V_24 = V_23 = false ;
for ( V_16 = 0 ; V_15 -> V_30 [ V_16 ] . V_31 ; V_16 ++ ) {
if ( ! strcmp ( V_15 -> V_30 [ V_16 ] . V_31 , V_32 ) )
break;
}
if ( ! V_15 -> V_30 [ V_16 ] . V_31 ) {
printf ( L_4 , V_32 ) ;
printf ( L_5 ) ;
for ( V_16 = 0 ; V_15 -> V_30 [ V_16 ] . V_31 ; V_16 ++ ) {
printf ( L_6 ,
V_15 -> V_30 [ V_16 ] . V_31 , V_15 -> V_30 [ V_16 ] . V_33 ) ;
}
return 1 ;
}
if ( V_34 == V_35 )
printf ( L_7 , V_27 ) ;
if ( ! V_24 && ! V_23 ) {
if ( V_26 ) {
V_20 [ 0 ] =
V_15 -> V_36 ( & V_15 -> V_30 [ V_16 ] , V_17 , false ) ;
V_20 [ 1 ] =
V_15 -> V_36 ( & V_15 -> V_30 [ V_16 ] , V_17 , true ) ;
} else {
V_19 [ 0 ] =
V_15 -> V_37 ( & V_15 -> V_30 [ V_16 ] ,
V_17 , false ) ;
V_19 [ 1 ] =
V_15 -> V_37 ( & V_15 -> V_30 [ V_16 ] ,
V_17 , true ) ;
}
} else {
if ( V_26 ) {
V_20 [ V_38 ] =
V_15 -> V_36 ( & V_15 -> V_30 [ V_16 ] ,
V_17 , V_24 ) ;
} else {
V_19 [ V_38 ] =
V_15 -> V_37 ( & V_15 -> V_30 [ V_16 ] ,
V_17 , V_24 ) ;
}
}
switch ( V_34 ) {
case V_35 :
if ( ! V_24 && ! V_23 ) {
if ( V_26 ) {
printf ( L_8 ,
( double ) V_20 [ 0 ]
/ V_18 ) ;
printf ( L_9 ,
( double ) V_20 [ 1 ]
/ V_18 ) ;
} else {
F_13 ( V_19 [ 0 ] ) ;
printf ( L_10 ) ;
F_13 ( V_19 [ 1 ] ) ;
printf ( L_11 ) ;
}
} else {
if ( V_26 ) {
printf ( L_12 ,
( double ) V_20 [ V_38 ]
/ V_18 ) ;
} else
F_13 ( V_19 [ V_38 ] ) ;
printf ( L_13 , V_24 ? L_14 : L_15 ) ;
}
break;
case V_39 :
if ( ! V_24 && ! V_23 ) {
if ( V_26 ) {
printf ( L_16 ,
( double ) V_20 [ 0 ] / V_18 ,
( double ) V_20 [ 1 ] / V_18 ) ;
} else {
printf ( L_16 ,
V_19 [ 0 ] , V_19 [ 1 ] ) ;
}
} else {
if ( V_26 ) {
printf ( L_17 , ( double ) V_20 [ V_38 ]
/ V_18 ) ;
} else
printf ( L_17 , V_19 [ V_38 ] ) ;
}
break;
default:
F_5 ( L_18 , V_34 ) ;
break;
}
return 0 ;
}
static void F_14 ( void * * V_40 , void * * V_41 , T_3 V_42 )
{
* V_40 = F_15 ( V_42 ) ;
if ( ! * V_40 )
F_5 ( L_19 ) ;
* V_41 = F_15 ( V_42 ) ;
if ( ! * V_41 )
F_5 ( L_19 ) ;
memset ( * V_41 , 0 , V_42 ) ;
}
static T_1 F_16 ( const struct V_32 * V_43 , T_3 V_17 , bool V_44 )
{
T_1 V_45 = 0ULL , V_46 = 0ULL ;
void * V_41 = NULL , * V_40 = NULL ;
T_4 V_47 = V_43 -> V_47 . memcpy ;
int V_16 ;
F_14 ( & V_40 , & V_41 , V_17 ) ;
if ( V_44 )
V_47 ( V_40 , V_41 , V_17 ) ;
V_45 = F_7 () ;
for ( V_16 = 0 ; V_16 < V_28 ; ++ V_16 )
V_47 ( V_40 , V_41 , V_17 ) ;
V_46 = F_7 () ;
free ( V_41 ) ;
free ( V_40 ) ;
return V_46 - V_45 ;
}
static double F_17 ( const struct V_32 * V_43 , T_3 V_17 ,
bool V_44 )
{
struct V_7 V_48 , V_49 , V_50 ;
T_4 V_47 = V_43 -> V_47 . memcpy ;
void * V_41 = NULL , * V_40 = NULL ;
int V_16 ;
F_14 ( & V_40 , & V_41 , V_17 ) ;
if ( V_44 )
V_47 ( V_40 , V_41 , V_17 ) ;
F_6 ( F_18 ( & V_48 , NULL ) ) ;
for ( V_16 = 0 ; V_16 < V_28 ; ++ V_16 )
V_47 ( V_40 , V_41 , V_17 ) ;
F_6 ( F_18 ( & V_49 , NULL ) ) ;
F_19 ( & V_49 , & V_48 , & V_50 ) ;
free ( V_41 ) ;
free ( V_40 ) ;
return ( double ) ( ( ( double ) V_17 * V_28 ) / F_9 ( & V_50 ) ) ;
}
int F_20 ( int V_11 , const char * * V_12 ,
const char * T_2 V_13 )
{
struct V_14 V_15 = {
. V_30 = V_51 ,
. V_36 = F_16 ,
. V_37 = F_17 ,
. V_22 = V_52 ,
} ;
return F_10 ( V_11 , V_12 , T_2 , & V_15 ) ;
}
static void F_21 ( void * * V_40 , T_3 V_42 )
{
* V_40 = F_15 ( V_42 ) ;
if ( ! * V_40 )
F_5 ( L_19 ) ;
}
static T_1 F_22 ( const struct V_32 * V_43 , T_3 V_17 , bool V_44 )
{
T_1 V_45 = 0ULL , V_46 = 0ULL ;
T_5 V_47 = V_43 -> V_47 . memset ;
void * V_40 = NULL ;
int V_16 ;
F_21 ( & V_40 , V_17 ) ;
if ( V_44 )
V_47 ( V_40 , - 1 , V_17 ) ;
V_45 = F_7 () ;
for ( V_16 = 0 ; V_16 < V_28 ; ++ V_16 )
V_47 ( V_40 , V_16 , V_17 ) ;
V_46 = F_7 () ;
free ( V_40 ) ;
return V_46 - V_45 ;
}
static double F_23 ( const struct V_32 * V_43 , T_3 V_17 ,
bool V_44 )
{
struct V_7 V_48 , V_49 , V_50 ;
T_5 V_47 = V_43 -> V_47 . memset ;
void * V_40 = NULL ;
int V_16 ;
F_21 ( & V_40 , V_17 ) ;
if ( V_44 )
V_47 ( V_40 , - 1 , V_17 ) ;
F_6 ( F_18 ( & V_48 , NULL ) ) ;
for ( V_16 = 0 ; V_16 < V_28 ; ++ V_16 )
V_47 ( V_40 , V_16 , V_17 ) ;
F_6 ( F_18 ( & V_49 , NULL ) ) ;
F_19 ( & V_49 , & V_48 , & V_50 ) ;
free ( V_40 ) ;
return ( double ) ( ( ( double ) V_17 * V_28 ) / F_9 ( & V_50 ) ) ;
}
int F_24 ( int V_11 , const char * * V_12 ,
const char * T_2 V_13 )
{
struct V_14 V_15 = {
. V_30 = V_53 ,
. V_36 = F_22 ,
. V_37 = F_23 ,
. V_22 = V_54 ,
} ;
return F_10 ( V_11 , V_12 , T_2 , & V_15 ) ;
}
