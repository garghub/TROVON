T_1 F_1 ( void )
{
T_1 V_1 ;
V_1 =
F_2 ( L_1 ,
sizeof( struct V_2 ) ,
V_3 ,
& V_4 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
V_1 =
F_2 ( L_2 , sizeof( union V_5 ) ,
V_6 ,
& V_7 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
V_1 =
F_2 ( L_3 ,
sizeof( struct V_8 ) ,
V_9 ,
& V_10 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
V_1 =
F_2 ( L_4 ,
sizeof( struct V_11 ) ,
V_12 ,
& V_13 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
V_1 =
F_2 ( L_5 ,
sizeof( union V_14 ) ,
V_15 ,
& V_16 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
#ifdef F_4
V_1 = F_5 ( L_6 , 0 , & V_17 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
V_1 =
F_5 ( L_1 ,
sizeof( struct V_2 ) ,
& V_18 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
#endif
return ( V_19 ) ;
}
T_1 F_6 ( void )
{
#ifdef F_4
char V_20 [ 7 ] ;
if ( V_21 ) {
F_7 ( V_20 , L_7 ) ;
( void ) F_8 ( V_20 ) ;
}
#endif
( void ) F_9 ( V_4 ) ;
V_4 = NULL ;
( void ) F_9 ( V_7 ) ;
V_7 = NULL ;
( void ) F_9 ( V_16 ) ;
V_16 = NULL ;
( void ) F_9 ( V_10 ) ;
V_10 = NULL ;
( void ) F_9 ( V_13 ) ;
V_13 = NULL ;
#ifdef F_4
F_10 ( V_22 , NULL ) ;
F_11 ( V_17 ) ;
V_17 = NULL ;
F_11 ( V_18 ) ;
V_18 = NULL ;
#endif
return ( V_19 ) ;
}
T_1 F_12 ( struct V_23 * V_20 )
{
if ( ! V_20 ) {
return ( V_24 ) ;
}
if ( ( V_20 -> V_25 == V_26 ) ||
( V_20 -> V_25 == V_27 ) ||
( V_20 -> V_25 == V_28 ) ) {
return ( V_19 ) ;
}
if ( ! V_20 -> V_29 ) {
return ( V_24 ) ;
}
return ( V_19 ) ;
}
T_1
F_13 ( struct V_23 * V_20 ,
T_2 V_30 )
{
T_2 V_31 ;
if ( ! V_20 || ! V_30 ) {
return ( V_24 ) ;
}
V_31 = V_20 -> V_25 ;
V_20 -> V_25 = V_30 ;
switch ( V_31 ) {
case V_26 :
return ( V_32 ) ;
case V_27 :
V_20 -> V_29 = F_14 ( V_30 ) ;
break;
case V_28 :
V_20 -> V_29 = F_15 ( V_30 ) ;
break;
default:
if ( V_31 < V_30 ) {
return ( V_32 ) ;
}
break;
}
if ( ! V_20 -> V_29 ) {
return ( V_33 ) ;
}
F_16 ( V_20 -> V_29 , 0 , V_30 ) ;
return ( V_19 ) ;
}
void * F_17 ( T_2 V_34 ,
T_3 V_35 , const char * V_36 , T_3 line )
{
void * V_37 ;
F_18 ( V_38 , V_34 ) ;
if ( ! V_34 ) {
F_19 ( ( V_36 , line ,
L_8 ) ) ;
V_34 = 1 ;
}
V_37 = F_14 ( V_34 ) ;
if ( ! V_37 ) {
F_19 ( ( V_36 , line ,
L_9 , ( T_3 ) V_34 ) ) ;
F_20 ( NULL ) ;
}
F_20 ( V_37 ) ;
}
void * F_21 ( T_2 V_34 ,
T_3 V_35 , const char * V_36 , T_3 line )
{
void * V_37 ;
F_22 () ;
V_37 = F_17 ( V_34 , V_35 , V_36 , line ) ;
if ( V_37 ) {
F_16 ( V_37 , 0 , V_34 ) ;
}
return ( V_37 ) ;
}
