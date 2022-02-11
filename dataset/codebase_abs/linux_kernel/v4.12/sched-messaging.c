static void F_1 ( int V_1 [ 2 ] )
{
if ( V_2 ) {
if ( F_2 ( V_1 ) == 0 )
return;
} else {
if ( F_3 ( V_3 , V_4 , 0 , V_1 ) == 0 )
return;
}
F_4 ( V_5 , V_2 ? L_1 : L_2 ) ;
}
static void F_5 ( int V_6 , int V_7 )
{
char V_8 ;
struct V_9 V_9 = { . V_10 = V_7 , . V_11 = V_12 } ;
if ( F_6 ( V_6 , & V_8 , 1 ) != 1 )
F_4 ( V_5 , L_3 ) ;
if ( F_7 ( & V_9 , 1 , - 1 ) != 1 )
F_4 ( V_5 , L_4 ) ;
}
static void * F_8 ( struct V_13 * V_14 )
{
char V_15 [ V_16 ] ;
unsigned int V_17 , V_18 ;
F_5 ( V_14 -> V_6 , V_14 -> V_7 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
for ( V_18 = 0 ; V_18 < V_14 -> V_20 ; V_18 ++ ) {
int V_21 , V_22 = 0 ;
V_23:
V_21 = F_6 ( V_14 -> V_24 [ V_18 ] , V_15 + V_22 ,
sizeof( V_15 ) - V_22 ) ;
if ( V_21 < 0 )
F_4 ( V_5 , L_5 ) ;
V_22 += V_21 ;
if ( V_22 < V_16 )
goto V_23;
}
}
return NULL ;
}
static void * F_9 ( struct V_25 * V_14 )
{
unsigned int V_17 ;
if ( ! V_26 )
F_10 ( V_14 -> V_27 [ 1 ] ) ;
F_5 ( V_14 -> V_6 , V_14 -> V_7 ) ;
for ( V_17 = 0 ; V_17 < V_14 -> V_28 ; V_17 ++ ) {
char V_15 [ V_16 ] ;
int V_21 , V_22 = 0 ;
V_23:
V_21 = F_11 ( V_14 -> V_27 [ 0 ] , V_15 + V_22 , V_16 - V_22 ) ;
if ( V_21 < 0 )
F_4 ( V_5 , L_6 ) ;
V_22 += V_21 ;
if ( V_22 < V_16 )
goto V_23;
}
return NULL ;
}
static T_1 F_12 ( void * V_14 , void * (* F_13)( void * ) )
{
T_2 V_29 ;
T_1 V_30 ;
int V_21 ;
if ( ! V_26 ) {
switch ( F_14 () ) {
case - 1 :
F_4 ( V_5 , L_7 ) ;
break;
case 0 :
(* F_13) ( V_14 ) ;
exit ( 0 ) ;
break;
default:
break;
}
return ( T_1 ) 0 ;
}
if ( F_15 ( & V_29 ) != 0 )
F_4 ( V_5 , L_8 ) ;
#ifndef F_16
if ( F_17 ( & V_29 , V_31 ) != 0 )
F_4 ( V_5 , L_9 ) ;
#endif
V_21 = F_18 ( & V_30 , & V_29 , F_13 , V_14 ) ;
if ( V_21 != 0 )
F_4 ( V_5 , L_10 ) ;
return V_30 ;
}
static void F_19 ( T_1 V_32 )
{
int V_33 ;
void * V_34 ;
if ( ! V_26 ) {
F_20 ( & V_33 ) ;
if ( ! F_21 ( V_33 ) )
exit ( 1 ) ;
} else {
F_22 ( V_32 , & V_34 ) ;
}
}
static unsigned int F_23 ( T_1 * V_35 ,
unsigned int V_20 ,
int V_6 ,
int V_7 )
{
unsigned int V_17 ;
struct V_13 * V_36 = malloc ( sizeof( struct V_13 )
+ V_20 * sizeof( int ) ) ;
if ( ! V_36 )
F_4 ( V_5 , L_11 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
int V_1 [ 2 ] ;
struct V_25 * V_14 = malloc ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
F_4 ( V_5 , L_11 ) ;
F_1 ( V_1 ) ;
V_14 -> V_28 = V_20 * V_19 ;
V_14 -> V_27 [ 0 ] = V_1 [ 0 ] ;
V_14 -> V_27 [ 1 ] = V_1 [ 1 ] ;
V_14 -> V_6 = V_6 ;
V_14 -> V_7 = V_7 ;
V_35 [ V_17 ] = F_12 ( V_14 , ( void * ) F_9 ) ;
V_36 -> V_24 [ V_17 ] = V_1 [ 1 ] ;
if ( ! V_26 )
F_10 ( V_1 [ 0 ] ) ;
}
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
V_36 -> V_6 = V_6 ;
V_36 -> V_7 = V_7 ;
V_36 -> V_20 = V_20 ;
V_35 [ V_20 + V_17 ] = F_12 ( V_36 , ( void * ) F_8 ) ;
}
if ( ! V_26 )
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ )
F_10 ( V_36 -> V_24 [ V_17 ] ) ;
return V_20 * 2 ;
}
int F_24 ( int V_37 , const char * * V_38 )
{
unsigned int V_17 , V_39 ;
struct V_40 V_41 , V_42 , V_43 ;
unsigned int V_20 = 20 ;
int V_44 [ 2 ] , V_45 [ 2 ] ;
char V_8 ;
T_1 * V_46 ;
V_37 = F_25 ( V_37 , V_38 , V_47 ,
V_48 , 0 ) ;
V_46 = malloc ( V_20 * 2 * V_49 * sizeof( T_1 ) ) ;
if ( ! V_46 )
F_4 ( V_5 , L_12 ) ;
F_1 ( V_44 ) ;
F_1 ( V_45 ) ;
V_39 = 0 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_39 += F_23 ( V_46 + V_39 , V_20 ,
V_44 [ 1 ] , V_45 [ 0 ] ) ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ )
if ( F_11 ( V_44 [ 0 ] , & V_8 , 1 ) != 1 )
F_4 ( V_5 , L_13 ) ;
F_26 ( & V_41 , NULL ) ;
if ( F_6 ( V_45 [ 1 ] , & V_8 , 1 ) != 1 )
F_4 ( V_5 , L_14 ) ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ )
F_19 ( V_46 [ V_17 ] ) ;
F_26 ( & V_42 , NULL ) ;
F_27 ( & V_42 , & V_41 , & V_43 ) ;
switch ( V_50 ) {
case V_51 :
printf ( L_15 ,
V_20 , V_26 ? L_16 : L_17 ) ;
printf ( L_18 ,
V_49 , V_49 * 2 * V_20 ,
V_26 ? L_16 : L_17 ) ;
printf ( L_19 , L_20 ,
V_43 . V_52 ,
( unsigned long ) ( V_43 . V_53 / V_54 ) ) ;
break;
case V_55 :
printf ( L_21 , V_43 . V_52 ,
( unsigned long ) ( V_43 . V_53 / V_54 ) ) ;
break;
default:
fprintf ( V_56 , L_22 , V_50 ) ;
exit ( 1 ) ;
break;
}
free ( V_46 ) ;
return 0 ;
}
