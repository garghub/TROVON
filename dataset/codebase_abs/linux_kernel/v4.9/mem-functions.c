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
return ( double ) V_8 -> V_9 + ( double ) V_8 -> V_10 / ( double ) V_11 ;
}
static void F_10 ( struct V_12 * V_13 , int V_14 , T_2 V_15 , double V_16 )
{
const struct V_17 * V_18 = & V_13 -> V_19 [ V_14 ] ;
double V_20 = 0.0 ;
T_1 V_21 = 0 ;
printf ( L_2 , V_18 -> V_22 , V_18 -> V_23 ) ;
if ( V_24 == V_25 )
printf ( L_3 , V_26 ) ;
if ( V_27 ) {
V_21 = V_13 -> V_28 ( V_18 , V_15 ) ;
} else {
V_20 = V_13 -> V_29 ( V_18 , V_15 ) ;
}
switch ( V_24 ) {
case V_25 :
if ( V_27 ) {
printf ( L_4 , ( double ) V_21 / V_16 ) ;
} else {
F_11 ( V_20 ) ;
}
break;
case V_30 :
if ( V_27 ) {
printf ( L_5 , ( double ) V_21 / V_16 ) ;
} else {
printf ( L_5 , V_20 ) ;
}
break;
default:
F_8 ( 1 ) ;
break;
}
}
static int F_12 ( int V_31 , const char * * V_32 , struct V_12 * V_13 )
{
int V_33 ;
T_2 V_15 ;
double V_16 ;
V_31 = F_13 ( V_31 , V_32 , V_34 , V_13 -> V_35 , 0 ) ;
if ( V_27 ) {
V_33 = F_1 () ;
if ( V_33 < 0 ) {
fprintf ( V_36 , L_6 ) ;
return V_33 ;
}
}
V_15 = ( T_2 ) F_14 ( ( char * ) V_26 ) ;
V_16 = ( double ) V_15 * V_37 ;
if ( ( V_38 ) V_15 <= 0 ) {
fprintf ( V_36 , L_7 , V_26 ) ;
return 1 ;
}
if ( ! strncmp ( V_39 , L_8 , 3 ) ) {
for ( V_33 = 0 ; V_13 -> V_19 [ V_33 ] . V_22 ; V_33 ++ )
F_10 ( V_13 , V_33 , V_15 , V_16 ) ;
return 0 ;
}
for ( V_33 = 0 ; V_13 -> V_19 [ V_33 ] . V_22 ; V_33 ++ ) {
if ( ! strcmp ( V_13 -> V_19 [ V_33 ] . V_22 , V_39 ) )
break;
}
if ( ! V_13 -> V_19 [ V_33 ] . V_22 ) {
if ( strcmp ( V_39 , L_9 ) && strcmp ( V_39 , L_10 ) )
printf ( L_11 , V_39 ) ;
printf ( L_12 ) ;
for ( V_33 = 0 ; V_13 -> V_19 [ V_33 ] . V_22 ; V_33 ++ ) {
printf ( L_13 ,
V_13 -> V_19 [ V_33 ] . V_22 , V_13 -> V_19 [ V_33 ] . V_23 ) ;
}
return 1 ;
}
F_10 ( V_13 , V_33 , V_15 , V_16 ) ;
return 0 ;
}
static void F_15 ( void * * V_40 , void * * V_41 , T_2 V_15 )
{
* V_40 = F_16 ( V_15 ) ;
if ( ! * V_40 )
F_17 ( L_14 ) ;
* V_41 = F_16 ( V_15 ) ;
if ( ! * V_41 )
F_17 ( L_14 ) ;
memset ( * V_41 , 0 , V_15 ) ;
}
static T_1 F_18 ( const struct V_17 * V_18 , T_2 V_15 )
{
T_1 V_42 = 0ULL , V_43 = 0ULL ;
void * V_41 = NULL , * V_40 = NULL ;
T_3 V_44 = V_18 -> V_44 . memcpy ;
int V_33 ;
F_15 ( & V_40 , & V_41 , V_15 ) ;
V_44 ( V_40 , V_41 , V_15 ) ;
V_42 = F_6 () ;
for ( V_33 = 0 ; V_33 < V_37 ; ++ V_33 )
V_44 ( V_40 , V_41 , V_15 ) ;
V_43 = F_6 () ;
free ( V_41 ) ;
free ( V_40 ) ;
return V_43 - V_42 ;
}
static double F_19 ( const struct V_17 * V_18 , T_2 V_15 )
{
struct V_7 V_45 , V_46 , V_47 ;
T_3 V_44 = V_18 -> V_44 . memcpy ;
void * V_41 = NULL , * V_40 = NULL ;
int V_33 ;
F_15 ( & V_40 , & V_41 , V_15 ) ;
V_44 ( V_40 , V_41 , V_15 ) ;
F_8 ( F_20 ( & V_45 , NULL ) ) ;
for ( V_33 = 0 ; V_33 < V_37 ; ++ V_33 )
V_44 ( V_40 , V_41 , V_15 ) ;
F_8 ( F_20 ( & V_46 , NULL ) ) ;
F_21 ( & V_46 , & V_45 , & V_47 ) ;
free ( V_41 ) ;
free ( V_40 ) ;
return ( double ) ( ( ( double ) V_15 * V_37 ) / F_9 ( & V_47 ) ) ;
}
int F_22 ( int V_31 , const char * * V_32 , const char * T_4 V_48 )
{
struct V_12 V_13 = {
. V_19 = V_49 ,
. V_28 = F_18 ,
. V_29 = F_19 ,
. V_35 = V_50 ,
} ;
return F_12 ( V_31 , V_32 , & V_13 ) ;
}
static void F_23 ( void * * V_40 , T_2 V_15 )
{
* V_40 = F_16 ( V_15 ) ;
if ( ! * V_40 )
F_17 ( L_14 ) ;
}
static T_1 F_24 ( const struct V_17 * V_18 , T_2 V_15 )
{
T_1 V_42 = 0ULL , V_43 = 0ULL ;
T_5 V_44 = V_18 -> V_44 . memset ;
void * V_40 = NULL ;
int V_33 ;
F_23 ( & V_40 , V_15 ) ;
V_44 ( V_40 , - 1 , V_15 ) ;
V_42 = F_6 () ;
for ( V_33 = 0 ; V_33 < V_37 ; ++ V_33 )
V_44 ( V_40 , V_33 , V_15 ) ;
V_43 = F_6 () ;
free ( V_40 ) ;
return V_43 - V_42 ;
}
static double F_25 ( const struct V_17 * V_18 , T_2 V_15 )
{
struct V_7 V_45 , V_46 , V_47 ;
T_5 V_44 = V_18 -> V_44 . memset ;
void * V_40 = NULL ;
int V_33 ;
F_23 ( & V_40 , V_15 ) ;
V_44 ( V_40 , - 1 , V_15 ) ;
F_8 ( F_20 ( & V_45 , NULL ) ) ;
for ( V_33 = 0 ; V_33 < V_37 ; ++ V_33 )
V_44 ( V_40 , V_33 , V_15 ) ;
F_8 ( F_20 ( & V_46 , NULL ) ) ;
F_21 ( & V_46 , & V_45 , & V_47 ) ;
free ( V_40 ) ;
return ( double ) ( ( ( double ) V_15 * V_37 ) / F_9 ( & V_47 ) ) ;
}
int F_26 ( int V_31 , const char * * V_32 , const char * T_4 V_48 )
{
struct V_12 V_13 = {
. V_19 = V_51 ,
. V_28 = F_24 ,
. V_29 = F_25 ,
. V_35 = V_52 ,
} ;
return F_12 ( V_31 , V_32 , & V_13 ) ;
}
