static int F_1 ( void )
{
V_1 = F_2 ( & V_2 , F_3 () , - 1 , - 1 , F_4 () ) ;
if ( V_1 < 0 && V_3 == V_4 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
return V_1 ;
}
static T_1 F_6 ( void )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_7 ( V_1 , & V_6 , sizeof( T_1 ) ) ;
F_8 ( V_5 != sizeof( T_1 ) ) ;
return V_6 ;
}
static double F_9 ( struct V_7 * V_8 )
{
return ( double ) V_8 -> V_9 + ( double ) V_8 -> V_10 / ( double ) 1000000 ;
}
static void F_10 ( struct V_11 * V_12 , int V_13 , T_2 V_14 , double V_15 )
{
const struct V_16 * V_17 = & V_12 -> V_18 [ V_13 ] ;
double V_19 = 0.0 ;
T_1 V_20 = 0 ;
printf ( L_2 , V_17 -> V_21 , V_17 -> V_22 ) ;
if ( V_23 == V_24 )
printf ( L_3 , V_25 ) ;
if ( V_26 ) {
V_20 = V_12 -> V_27 ( V_17 , V_14 ) ;
} else {
V_19 = V_12 -> V_28 ( V_17 , V_14 ) ;
}
switch ( V_23 ) {
case V_24 :
if ( V_26 ) {
printf ( L_4 , ( double ) V_20 / V_15 ) ;
} else {
F_11 ( V_19 ) ;
}
break;
case V_29 :
if ( V_26 ) {
printf ( L_5 , ( double ) V_20 / V_15 ) ;
} else {
printf ( L_5 , V_19 ) ;
}
break;
default:
F_8 ( 1 ) ;
break;
}
}
static int F_12 ( int V_30 , const char * * V_31 , struct V_11 * V_12 )
{
int V_32 ;
T_2 V_14 ;
double V_15 ;
V_30 = F_13 ( V_30 , V_31 , V_33 , V_12 -> V_34 , 0 ) ;
if ( V_26 ) {
V_32 = F_1 () ;
if ( V_32 < 0 ) {
fprintf ( V_35 , L_6 ) ;
return V_32 ;
}
}
V_14 = ( T_2 ) F_14 ( ( char * ) V_25 ) ;
V_15 = ( double ) V_14 * V_36 ;
if ( ( V_37 ) V_14 <= 0 ) {
fprintf ( V_35 , L_7 , V_25 ) ;
return 1 ;
}
if ( ! strncmp ( V_38 , L_8 , 3 ) ) {
for ( V_32 = 0 ; V_12 -> V_18 [ V_32 ] . V_21 ; V_32 ++ )
F_10 ( V_12 , V_32 , V_14 , V_15 ) ;
return 0 ;
}
for ( V_32 = 0 ; V_12 -> V_18 [ V_32 ] . V_21 ; V_32 ++ ) {
if ( ! strcmp ( V_12 -> V_18 [ V_32 ] . V_21 , V_38 ) )
break;
}
if ( ! V_12 -> V_18 [ V_32 ] . V_21 ) {
if ( strcmp ( V_38 , L_9 ) && strcmp ( V_38 , L_10 ) )
printf ( L_11 , V_38 ) ;
printf ( L_12 ) ;
for ( V_32 = 0 ; V_12 -> V_18 [ V_32 ] . V_21 ; V_32 ++ ) {
printf ( L_13 ,
V_12 -> V_18 [ V_32 ] . V_21 , V_12 -> V_18 [ V_32 ] . V_22 ) ;
}
return 1 ;
}
F_10 ( V_12 , V_32 , V_14 , V_15 ) ;
return 0 ;
}
static void F_15 ( void * * V_39 , void * * V_40 , T_2 V_14 )
{
* V_39 = F_16 ( V_14 ) ;
if ( ! * V_39 )
F_17 ( L_14 ) ;
* V_40 = F_16 ( V_14 ) ;
if ( ! * V_40 )
F_17 ( L_14 ) ;
memset ( * V_40 , 0 , V_14 ) ;
}
static T_1 F_18 ( const struct V_16 * V_17 , T_2 V_14 )
{
T_1 V_41 = 0ULL , V_42 = 0ULL ;
void * V_40 = NULL , * V_39 = NULL ;
T_3 V_43 = V_17 -> V_43 . memcpy ;
int V_32 ;
F_15 ( & V_39 , & V_40 , V_14 ) ;
V_43 ( V_39 , V_40 , V_14 ) ;
V_41 = F_6 () ;
for ( V_32 = 0 ; V_32 < V_36 ; ++ V_32 )
V_43 ( V_39 , V_40 , V_14 ) ;
V_42 = F_6 () ;
free ( V_40 ) ;
free ( V_39 ) ;
return V_42 - V_41 ;
}
static double F_19 ( const struct V_16 * V_17 , T_2 V_14 )
{
struct V_7 V_44 , V_45 , V_46 ;
T_3 V_43 = V_17 -> V_43 . memcpy ;
void * V_40 = NULL , * V_39 = NULL ;
int V_32 ;
F_15 ( & V_39 , & V_40 , V_14 ) ;
V_43 ( V_39 , V_40 , V_14 ) ;
F_8 ( F_20 ( & V_44 , NULL ) ) ;
for ( V_32 = 0 ; V_32 < V_36 ; ++ V_32 )
V_43 ( V_39 , V_40 , V_14 ) ;
F_8 ( F_20 ( & V_45 , NULL ) ) ;
F_21 ( & V_45 , & V_44 , & V_46 ) ;
free ( V_40 ) ;
free ( V_39 ) ;
return ( double ) ( ( ( double ) V_14 * V_36 ) / F_9 ( & V_46 ) ) ;
}
int F_22 ( int V_30 , const char * * V_31 , const char * T_4 V_47 )
{
struct V_11 V_12 = {
. V_18 = V_48 ,
. V_27 = F_18 ,
. V_28 = F_19 ,
. V_34 = V_49 ,
} ;
return F_12 ( V_30 , V_31 , & V_12 ) ;
}
static void F_23 ( void * * V_39 , T_2 V_14 )
{
* V_39 = F_16 ( V_14 ) ;
if ( ! * V_39 )
F_17 ( L_14 ) ;
}
static T_1 F_24 ( const struct V_16 * V_17 , T_2 V_14 )
{
T_1 V_41 = 0ULL , V_42 = 0ULL ;
T_5 V_43 = V_17 -> V_43 . memset ;
void * V_39 = NULL ;
int V_32 ;
F_23 ( & V_39 , V_14 ) ;
V_43 ( V_39 , - 1 , V_14 ) ;
V_41 = F_6 () ;
for ( V_32 = 0 ; V_32 < V_36 ; ++ V_32 )
V_43 ( V_39 , V_32 , V_14 ) ;
V_42 = F_6 () ;
free ( V_39 ) ;
return V_42 - V_41 ;
}
static double F_25 ( const struct V_16 * V_17 , T_2 V_14 )
{
struct V_7 V_44 , V_45 , V_46 ;
T_5 V_43 = V_17 -> V_43 . memset ;
void * V_39 = NULL ;
int V_32 ;
F_23 ( & V_39 , V_14 ) ;
V_43 ( V_39 , - 1 , V_14 ) ;
F_8 ( F_20 ( & V_44 , NULL ) ) ;
for ( V_32 = 0 ; V_32 < V_36 ; ++ V_32 )
V_43 ( V_39 , V_32 , V_14 ) ;
F_8 ( F_20 ( & V_45 , NULL ) ) ;
F_21 ( & V_45 , & V_44 , & V_46 ) ;
free ( V_39 ) ;
return ( double ) ( ( ( double ) V_14 * V_36 ) / F_9 ( & V_46 ) ) ;
}
int F_26 ( int V_30 , const char * * V_31 , const char * T_4 V_47 )
{
struct V_11 V_12 = {
. V_18 = V_50 ,
. V_27 = F_24 ,
. V_28 = F_25 ,
. V_34 = V_51 ,
} ;
return F_12 ( V_30 , V_31 , & V_12 ) ;
}
