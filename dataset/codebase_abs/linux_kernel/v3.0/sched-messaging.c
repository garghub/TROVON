static void F_1 ( const char * V_1 )
{
fprintf ( V_2 , L_1 , V_1 , strerror ( V_3 ) ) ;
exit ( 1 ) ;
}
static void F_2 ( int V_4 [ 2 ] )
{
if ( V_5 ) {
if ( F_3 ( V_4 ) == 0 )
return;
} else {
if ( F_4 ( V_6 , V_7 , 0 , V_4 ) == 0 )
return;
}
F_1 ( V_5 ? L_2 : L_3 ) ;
}
static void F_5 ( int V_8 , int V_9 )
{
char V_10 ;
struct V_11 V_11 = { . V_12 = V_9 , . V_13 = V_14 } ;
if ( F_6 ( V_8 , & V_10 , 1 ) != 1 )
F_1 ( L_4 ) ;
if ( F_7 ( & V_11 , 1 , - 1 ) != 1 )
F_1 ( L_5 ) ;
}
static void * F_8 ( struct V_15 * V_16 )
{
char V_17 [ V_18 ] ;
unsigned int V_19 , V_20 ;
F_5 ( V_16 -> V_8 , V_16 -> V_9 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < V_16 -> V_22 ; V_20 ++ ) {
int V_23 , V_24 = 0 ;
V_25:
V_23 = F_6 ( V_16 -> V_26 [ V_20 ] , V_17 + V_24 ,
sizeof( V_17 ) - V_24 ) ;
if ( V_23 < 0 )
F_1 ( L_6 ) ;
V_24 += V_23 ;
if ( V_24 < V_18 )
goto V_25;
}
}
return NULL ;
}
static void * F_9 ( struct V_27 * V_16 )
{
unsigned int V_19 ;
if ( ! V_28 )
F_10 ( V_16 -> V_29 [ 1 ] ) ;
F_5 ( V_16 -> V_8 , V_16 -> V_9 ) ;
for ( V_19 = 0 ; V_19 < V_16 -> V_30 ; V_19 ++ ) {
char V_17 [ V_18 ] ;
int V_23 , V_24 = 0 ;
V_25:
V_23 = F_11 ( V_16 -> V_29 [ 0 ] , V_17 + V_24 , V_18 - V_24 ) ;
if ( V_23 < 0 )
F_1 ( L_7 ) ;
V_24 += V_23 ;
if ( V_24 < V_18 )
goto V_25;
}
return NULL ;
}
static T_1 F_12 ( void * V_16 , void * (* F_13)( void * ) )
{
T_2 V_31 ;
T_1 V_32 ;
int V_33 ;
if ( ! V_28 ) {
switch ( F_14 () ) {
case - 1 :
F_1 ( L_8 ) ;
break;
case 0 :
(* F_13) ( V_16 ) ;
exit ( 0 ) ;
break;
default:
break;
}
return ( T_1 ) 0 ;
}
if ( F_15 ( & V_31 ) != 0 )
F_1 ( L_9 ) ;
#ifndef F_16
if ( F_17 ( & V_31 , V_34 ) != 0 )
F_1 ( L_10 ) ;
#endif
V_33 = F_18 ( & V_32 , & V_31 , F_13 , V_16 ) ;
if ( V_33 != 0 ) {
fprintf ( V_2 , L_11 ,
strerror ( V_33 ) , V_33 ) ;
exit ( - 1 ) ;
}
return V_32 ;
}
static void F_19 ( T_1 V_35 )
{
int V_36 ;
void * V_37 ;
if ( ! V_28 ) {
F_20 ( & V_36 ) ;
if ( ! F_21 ( V_36 ) )
exit ( 1 ) ;
} else {
F_22 ( V_35 , & V_37 ) ;
}
}
static unsigned int F_23 ( T_1 * V_38 ,
unsigned int V_22 ,
int V_8 ,
int V_9 )
{
unsigned int V_19 ;
struct V_15 * V_39 = malloc ( sizeof( struct V_15 )
+ V_22 * sizeof( int ) ) ;
if ( ! V_39 )
F_1 ( L_12 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
int V_4 [ 2 ] ;
struct V_27 * V_16 = malloc ( sizeof( * V_16 ) ) ;
if ( ! V_16 )
F_1 ( L_12 ) ;
F_2 ( V_4 ) ;
V_16 -> V_30 = V_22 * V_21 ;
V_16 -> V_29 [ 0 ] = V_4 [ 0 ] ;
V_16 -> V_29 [ 1 ] = V_4 [ 1 ] ;
V_16 -> V_8 = V_8 ;
V_16 -> V_9 = V_9 ;
V_38 [ V_19 ] = F_12 ( V_16 , ( void * ) F_9 ) ;
V_39 -> V_26 [ V_19 ] = V_4 [ 1 ] ;
if ( ! V_28 )
F_10 ( V_4 [ 0 ] ) ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_39 -> V_8 = V_8 ;
V_39 -> V_9 = V_9 ;
V_39 -> V_22 = V_22 ;
V_38 [ V_22 + V_19 ] = F_12 ( V_39 , ( void * ) F_8 ) ;
}
if ( ! V_28 )
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_10 ( V_39 -> V_26 [ V_19 ] ) ;
return V_22 * 2 ;
}
int F_24 ( int V_40 , const char * * V_41 ,
const char * T_3 V_42 )
{
unsigned int V_19 , V_43 ;
struct V_44 V_45 , V_46 , V_47 ;
unsigned int V_22 = 20 ;
int V_48 [ 2 ] , V_49 [ 2 ] ;
char V_10 ;
T_1 * V_50 ;
V_40 = F_25 ( V_40 , V_41 , V_51 ,
V_52 , 0 ) ;
V_50 = malloc ( V_22 * 2 * V_53 * sizeof( T_1 ) ) ;
if ( ! V_50 )
F_1 ( L_13 ) ;
F_2 ( V_48 ) ;
F_2 ( V_49 ) ;
V_43 = 0 ;
for ( V_19 = 0 ; V_19 < V_53 ; V_19 ++ )
V_43 += F_23 ( V_50 + V_43 , V_22 ,
V_48 [ 1 ] , V_49 [ 0 ] ) ;
for ( V_19 = 0 ; V_19 < V_43 ; V_19 ++ )
if ( F_11 ( V_48 [ 0 ] , & V_10 , 1 ) != 1 )
F_1 ( L_14 ) ;
F_26 ( & V_45 , NULL ) ;
if ( F_6 ( V_49 [ 1 ] , & V_10 , 1 ) != 1 )
F_1 ( L_15 ) ;
for ( V_19 = 0 ; V_19 < V_43 ; V_19 ++ )
F_19 ( V_50 [ V_19 ] ) ;
F_26 ( & V_46 , NULL ) ;
F_27 ( & V_46 , & V_45 , & V_47 ) ;
switch ( V_54 ) {
case V_55 :
printf ( L_16 ,
V_22 , V_28 ? L_17 : L_18 ) ;
printf ( L_19 ,
V_53 , V_53 * 2 * V_22 ,
V_28 ? L_17 : L_18 ) ;
printf ( L_20 , L_21 ,
V_47 . V_56 ,
( unsigned long ) ( V_47 . V_57 / 1000 ) ) ;
break;
case V_58 :
printf ( L_22 , V_47 . V_56 ,
( unsigned long ) ( V_47 . V_57 / 1000 ) ) ;
break;
default:
fprintf ( V_2 , L_23 , V_54 ) ;
exit ( 1 ) ;
break;
}
return 0 ;
}
