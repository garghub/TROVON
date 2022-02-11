void * F_1 ( T_1 V_1 )
{
void * V_2 ;
F_2 () ;
V_2 = F_3 ( V_1 ) ;
if ( V_2 ) {
memset ( V_2 , 0 , V_1 ) ;
}
return ( V_2 ) ;
}
T_2 F_4 ( void )
{
T_2 V_3 ;
V_3 =
F_5 ( L_1 ,
sizeof( struct V_4 ) ,
V_5 ,
& V_6 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_5 ( L_2 , sizeof( union V_7 ) ,
V_8 ,
& V_9 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_5 ( L_3 ,
sizeof( struct V_10 ) ,
V_11 ,
& V_12 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_5 ( L_4 ,
sizeof( struct V_13 ) ,
V_14 ,
& V_15 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_5 ( L_5 ,
sizeof( union V_16 ) ,
V_17 ,
& V_18 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
#ifdef F_7
V_3 =
F_5 ( L_6 ,
sizeof( struct V_19 ) ,
V_20 ,
& V_21 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_5 ( L_7 ,
sizeof( struct V_22 ) ,
V_20 ,
& V_23 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_5 ( L_8 , sizeof( struct V_24 ) ,
V_20 ,
& V_25 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
#endif
#ifdef F_8
V_3 = F_9 ( L_9 , 0 , & V_26 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_9 ( L_1 ,
sizeof( struct V_4 ) ,
& V_27 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
#endif
return ( V_28 ) ;
}
T_2 F_10 ( void )
{
#ifdef F_8
char V_29 [ 7 ] ;
if ( V_30 ) {
strcpy ( V_29 , L_10 ) ;
( void ) F_11 ( V_29 ) ;
}
#endif
( void ) F_12 ( V_6 ) ;
V_6 = NULL ;
( void ) F_12 ( V_9 ) ;
V_9 = NULL ;
( void ) F_12 ( V_18 ) ;
V_18 = NULL ;
( void ) F_12 ( V_12 ) ;
V_12 = NULL ;
( void ) F_12 ( V_15 ) ;
V_15 = NULL ;
#ifdef F_7
( void ) F_12 ( V_21 ) ;
V_21 = NULL ;
( void ) F_12 ( V_23 ) ;
V_23 = NULL ;
( void ) F_12 ( V_25 ) ;
V_25 = NULL ;
#endif
#ifdef F_8
F_13 ( V_31 , NULL ) ;
F_14 ( V_26 ) ;
V_26 = NULL ;
F_14 ( V_27 ) ;
V_27 = NULL ;
#endif
return ( V_28 ) ;
}
T_2 F_15 ( struct V_32 * V_29 )
{
if ( ! V_29 ) {
return ( V_33 ) ;
}
if ( ( V_29 -> V_34 == V_35 ) ||
( V_29 -> V_34 == V_36 ) ||
( V_29 -> V_34 == V_37 ) ) {
return ( V_28 ) ;
}
if ( ! V_29 -> V_38 ) {
return ( V_33 ) ;
}
return ( V_28 ) ;
}
T_2
F_16 ( struct V_32 * V_29 , T_1 V_39 )
{
T_1 V_40 ;
if ( ! V_29 || ! V_39 ) {
return ( V_33 ) ;
}
V_40 = V_29 -> V_34 ;
V_29 -> V_34 = V_39 ;
switch ( V_40 ) {
case V_35 :
return ( V_41 ) ;
case V_36 :
V_29 -> V_38 = F_3 ( V_39 ) ;
break;
case V_37 :
V_29 -> V_38 = F_17 ( V_39 ) ;
break;
default:
if ( V_40 < V_39 ) {
return ( V_41 ) ;
}
break;
}
if ( ! V_29 -> V_38 ) {
return ( V_42 ) ;
}
memset ( V_29 -> V_38 , 0 , V_39 ) ;
return ( V_28 ) ;
}
