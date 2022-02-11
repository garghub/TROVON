static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_2 * V_3 = ( T_2 * ) V_2 -> V_4 ;
T_2 * V_5 = NULL ;
T_3 V_6 ;
if( ! V_3 )
return;
for( V_5 = V_3 ; V_5 ; V_5 = V_5 -> V_7 )
for( V_6 = 0 ; V_6 < 256 ; V_6 ++ )
V_5 -> V_8 [ V_6 ] = 0 ;
V_2 -> V_9 = 0 ;
}
static T_2 *
F_2 ( const struct V_10 * V_11 )
{
T_2 * V_12 ;
T_3 V_6 ;
if( ! V_11 )
return NULL ;
if ( ! ( V_12 = F_3 ( sizeof( T_2 ) ) ) )
return NULL ;
F_4 ( & V_12 -> V_13 , & V_11 -> V_14 ) ;
F_4 ( & V_12 -> V_15 , & V_11 -> V_16 ) ;
V_12 -> V_17 = V_11 -> V_17 ;
V_12 -> V_18 = V_11 -> V_18 ;
V_12 -> V_7 = NULL ;
for( V_6 = 0 ; V_6 < 256 ; V_6 ++ )
V_12 -> V_8 [ V_6 ] = 0 ;
return V_12 ;
}
static int
F_5 ( void * V_1 , T_4 * T_5 V_19 , T_6 * T_7 V_19 , const void * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_1 ;
T_2 * V_5 = NULL , * V_22 = NULL ;
const struct V_10 * V_11 = ( const struct V_10 * ) V_20 ;
T_8 V_23 ;
T_9 V_6 ;
if ( ! V_21 )
return ( 0 ) ;
V_21 -> V_9 ++ ;
if( ! V_21 -> V_4 ) {
V_21 -> V_4 = F_2 ( V_11 ) ;
V_22 = V_21 -> V_4 ;
} else {
for( V_5 = V_21 -> V_4 ; V_5 ; V_5 = V_5 -> V_7 )
{
if( ( ! F_6 ( & V_5 -> V_13 , & V_11 -> V_14 ) ) &&
( ! F_6 ( & V_5 -> V_15 , & V_11 -> V_16 ) ) &&
( V_5 -> V_17 == V_11 -> V_17 ) &&
( V_5 -> V_18 == V_11 -> V_18 ) )
{
V_22 = V_5 ;
break;
}
}
if( ! V_22 ) {
if ( ( V_22 = F_2 ( V_11 ) ) ) {
V_22 -> V_7 = V_21 -> V_4 ;
V_21 -> V_4 = V_22 ;
}
}
}
if( ! V_22 )
return ( 0 ) ;
if ( V_11 -> V_24 > 0 ) {
V_6 = F_7 ( V_11 -> V_25 [ 0 ] ) ;
if ( ( V_6 == V_26 ) ||
( V_6 == V_27 ) ) {
V_22 -> V_8 [ V_6 ] ++ ;
} else {
for( V_23 = 0 ; V_23 < V_11 -> V_24 ; V_23 ++ )
V_22 -> V_8 [ F_7 ( V_11 -> V_25 [ V_23 ] ) ] ++ ;
}
}
return ( 1 ) ;
}
static void
F_8 ( void * V_1 )
{
T_1 * V_21 = ( T_1 * ) V_1 ;
T_2 * V_3 = V_21 -> V_4 , * V_5 ;
printf ( L_1 ) ;
printf ( L_2 , V_21 -> V_9 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_3 ) ;
for( V_5 = V_3 ; V_5 ; V_5 = V_5 -> V_7 ) {
printf ( L_5 ,
F_9 ( & V_5 -> V_13 ) , V_5 -> V_17 ,
F_9 ( & V_5 -> V_15 ) , V_5 -> V_18 ,
V_5 -> V_8 [ V_28 ] ,
V_5 -> V_8 [ V_29 ] ,
V_5 -> V_8 [ V_30 ] ,
V_5 -> V_8 [ V_31 ] ,
V_5 -> V_8 [ V_26 ] ,
V_5 -> V_8 [ V_27 ] ,
V_5 -> V_8 [ V_32 ] ,
V_5 -> V_8 [ V_33 ] ,
V_5 -> V_8 [ V_34 ] ,
V_5 -> V_8 [ V_35 ] ) ;
}
printf ( L_3 ) ;
}
static void
F_10 ( const char * V_36 , void * T_10 V_19 )
{
T_1 * V_21 ;
T_11 * V_37 ;
V_21 = ( T_1 * ) F_3 ( sizeof( T_1 ) ) ;
if( ! strncmp ( V_36 , L_6 , 11 ) ) {
V_21 -> V_38 = F_11 ( V_36 + 11 ) ;
} else {
V_21 -> V_38 = NULL ;
}
V_21 -> V_4 = NULL ;
V_21 -> V_9 = 0 ;
F_1 ( V_21 ) ;
V_37 = F_12 ( L_7 , V_21 , V_21 -> V_38 , 0 , NULL , F_5 , F_8 ) ;
if( V_37 ) {
F_13 ( V_21 -> V_38 ) ;
F_13 ( V_21 ) ;
fprintf ( V_39 , L_8 ,
V_37 -> V_40 ) ;
F_14 ( V_37 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_15 ( void )
{
F_16 ( L_9 , F_10 , NULL ) ;
}
