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
V_3 = F_8 ( L_6 , 0 , & V_19 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 =
F_8 ( L_1 ,
sizeof( struct V_4 ) ,
& V_20 ) ;
if ( F_6 ( V_3 ) ) {
return ( V_3 ) ;
}
#endif
return ( V_21 ) ;
}
T_2 F_9 ( void )
{
#ifdef F_7
char V_22 [ 7 ] ;
if ( V_23 ) {
strcpy ( V_22 , L_7 ) ;
( void ) F_10 ( V_22 ) ;
}
#endif
( void ) F_11 ( V_6 ) ;
V_6 = NULL ;
( void ) F_11 ( V_9 ) ;
V_9 = NULL ;
( void ) F_11 ( V_18 ) ;
V_18 = NULL ;
( void ) F_11 ( V_12 ) ;
V_12 = NULL ;
( void ) F_11 ( V_15 ) ;
V_15 = NULL ;
#ifdef F_7
F_12 ( V_24 , NULL ) ;
F_13 ( V_19 ) ;
V_19 = NULL ;
F_13 ( V_20 ) ;
V_20 = NULL ;
#endif
return ( V_21 ) ;
}
T_2 F_14 ( struct V_25 * V_22 )
{
if ( ! V_22 ) {
return ( V_26 ) ;
}
if ( ( V_22 -> V_27 == V_28 ) ||
( V_22 -> V_27 == V_29 ) ||
( V_22 -> V_27 == V_30 ) ) {
return ( V_21 ) ;
}
if ( ! V_22 -> V_31 ) {
return ( V_26 ) ;
}
return ( V_21 ) ;
}
T_2
F_15 ( struct V_25 * V_22 ,
T_1 V_32 )
{
T_1 V_33 ;
if ( ! V_22 || ! V_32 ) {
return ( V_26 ) ;
}
V_33 = V_22 -> V_27 ;
V_22 -> V_27 = V_32 ;
switch ( V_33 ) {
case V_28 :
return ( V_34 ) ;
case V_29 :
V_22 -> V_31 = F_3 ( V_32 ) ;
break;
case V_30 :
V_22 -> V_31 = F_16 ( V_32 ) ;
break;
default:
if ( V_33 < V_32 ) {
return ( V_34 ) ;
}
break;
}
if ( ! V_22 -> V_31 ) {
return ( V_35 ) ;
}
memset ( V_22 -> V_31 , 0 , V_32 ) ;
return ( V_21 ) ;
}
