int
F_1 ( int * V_1 , char * V_2 ,
char * V_3 , int V_4 )
{
int V_5 = 128 ;
if ( ! F_2 ( V_6 ) )
return ( - V_7 ) ;
if ( V_4 > 0 &&
V_5 > V_4 )
V_5 = V_4 ;
* V_1 = F_3 ( V_2 , V_5 - 1 ) + 1 ;
if ( V_3 != NULL ) {
if ( V_4 < 4 )
return ( - V_8 ) ;
if ( F_4 ( V_3 , V_2 , * V_1 ) )
return ( - V_9 ) ;
if ( V_2 [ * V_1 - 1 ] != 0 )
F_4 ( V_3 + * V_1 - 4 , L_1 , 4 ) ;
}
return ( 0 ) ;
}
int
F_5 ( int V_10 , int V_11 )
{
T_1 * V_12 ;
int V_13 ;
int V_14 ;
if ( ! F_2 ( V_6 ) )
return ( - V_7 ) ;
if ( ! V_10 ) {
F_6 ( 0 , 0 , 0 , 0 ) ;
V_15 = 0 ;
F_7 () ;
F_8 ( 10 ) ;
}
for ( V_13 = 0 ; V_13 < F_9 () ; V_13 ++ ) {
V_12 = V_16 [ V_13 ] . V_17 ;
if ( V_12 == NULL )
return ( - V_18 ) ;
if ( ! V_11 )
continue;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
memset ( V_12 -> V_20 , 0 , V_21 ) ;
V_12 = F_10 ( V_12 -> V_22 . V_23 ,
T_1 , V_22 ) ;
}
}
if ( V_10 ) {
V_15 = 1 ;
F_7 () ;
F_6 ( 0 , 0 , 0 , 0 ) ;
}
return ( 0 ) ;
}
int
F_11 ( T_2 * V_24 , int * V_25 , int * V_26 ,
void * V_3 , int V_4 )
{
const int V_27 = V_21 / sizeof( V_28 ) ;
const int V_29 = V_27 * sizeof( V_28 ) ;
T_1 * V_12 ;
int V_13 ;
int V_14 ;
if ( ! F_2 ( V_6 ) )
return ( - V_7 ) ;
* V_25 = F_9 () ;
* V_26 = F_9 () * V_19 *
V_29 ;
* V_24 = F_12 () ;
if ( V_3 == NULL )
return ( 0 ) ;
for ( V_13 = 0 ; V_13 < F_9 () ; V_13 ++ ) {
V_12 = V_16 [ V_13 ] . V_17 ;
if ( V_12 == NULL )
return ( - V_18 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
if ( F_4 ( V_3 , V_12 -> V_20 ,
V_29 ) )
return ( - V_9 ) ;
V_3 = ( ( char * ) V_3 ) + V_29 ;
V_12 = F_10 ( V_12 -> V_22 . V_23 ,
T_1 , V_22 ) ;
}
}
return ( 0 ) ;
}
int
F_13 ()
{
int V_13 ;
int V_14 ;
for ( V_13 = 0 ; V_13 < F_9 () ; V_13 ++ )
if ( V_16 [ V_13 ] . V_17 != NULL )
return ( - V_30 ) ;
F_14 ( ! V_15 ) ;
memset ( V_16 , 0 , sizeof ( V_16 ) ) ;
V_19 =
V_31 / ( F_9 () * V_21 ) ;
for ( V_13 = 0 ; V_13 < F_9 () ; V_13 ++ )
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
struct V_32 * V_32 = F_15 ( V_33 ) ;
T_1 * V_34 ;
if ( V_32 == NULL ) {
F_16 ( L_2 ) ;
F_17 () ;
return ( - V_35 ) ;
}
F_18 ( V_34 , sizeof ( * V_34 ) ) ;
if ( V_34 == NULL ) {
F_16 ( L_3 ) ;
F_19 ( V_32 ) ;
F_17 () ;
return ( - V_35 ) ;
}
V_34 -> V_36 = V_32 ;
V_34 -> V_20 = F_20 ( V_32 ) ;
memset ( V_34 -> V_20 , 0 , V_21 ) ;
if ( V_14 == 0 ) {
F_21 ( & V_34 -> V_22 ) ;
V_16 [ V_13 ] . V_17 = V_34 ;
} else {
F_22 ( & V_34 -> V_22 ,
& V_16 [ V_13 ] . V_17 -> V_22 ) ;
}
}
V_15 = 1 ;
F_7 () ;
F_6 ( 0 , 0 , 0 , 0 ) ;
return ( 0 ) ;
}
void
F_17 ()
{
int V_13 ;
F_5 ( 0 , 0 ) ;
for ( V_13 = 0 ; V_13 < F_9 () ; V_13 ++ )
while ( V_16 [ V_13 ] . V_17 != NULL ) {
T_1 * V_34 = V_16 [ V_13 ] . V_17 ;
if ( F_23 ( & V_34 -> V_22 ) ) {
V_16 [ V_13 ] . V_17 = NULL ;
} else {
V_16 [ V_13 ] . V_17 =
F_10 ( V_34 -> V_22 . V_23 ,
T_1 , V_22 ) ;
F_24 ( & V_34 -> V_22 ) ;
}
F_19 ( V_34 -> V_36 ) ;
F_25 ( V_34 , sizeof ( * V_34 ) ) ;
}
}
