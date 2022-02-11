T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 != - 1 )
return V_3 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
unsigned int V_4 ;
const void * V_5 = F_3 ( V_2 , L_2 , & V_4 ) ;
V_3 = F_4 ( V_2 , V_5 ) ;
F_5 ( V_2 ) ;
} ;
return V_3 ;
}
T_2 F_6 ( void )
{
return ( T_2 ) ( F_7 ( F_1 () , 0x10000 ) ) ;
}
static int T_3 F_8 ( void )
{
struct V_1 * V_6 ;
unsigned int V_7 = 0 ;
struct V_8 * V_9 ;
struct V_10 V_11 ;
int V_12 ;
F_9 (np, L_3 , L_4 ) {
struct V_10 V_13 [ 2 ] ;
struct V_1 * V_14 , * V_15 ;
T_4 V_16 ;
const unsigned int * V_17 ;
const void * V_18 ;
const T_5 * V_19 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_12 = F_10 ( V_6 , 0 , & V_13 [ 0 ] ) ;
F_11 ( L_5 ,
V_20 , V_13 [ 0 ] . V_21 , & V_13 [ 0 ] ) ;
if ( V_12 )
goto V_22;
V_13 [ 1 ] . V_21 = L_6 ;
V_13 [ 1 ] . V_23 = F_12 ( V_6 , 0 ) ;
V_13 [ 1 ] . V_24 = F_12 ( V_6 , 0 ) ;
V_13 [ 1 ] . V_25 = V_26 ;
F_11 ( L_5 ,
V_20 , V_13 [ 1 ] . V_21 , & V_13 [ 1 ] ) ;
V_9 =
F_13 ( L_7 , V_7 ++ , & V_13 [ 0 ] ,
1 ) ;
if ( F_14 ( V_9 ) ) {
V_12 = F_15 ( V_9 ) ;
goto V_22;
}
V_18 = F_16 ( V_6 ) ;
if ( V_18 )
memcpy ( V_16 . V_18 , V_18 , 6 ) ;
V_19 = F_3 ( V_6 , L_8 , NULL ) ;
V_15 = F_17 ( * V_19 ) ;
V_12 = F_10 ( V_15 , 0 , & V_11 ) ;
F_5 ( V_15 ) ;
if ( V_12 )
goto V_27;
V_19 = F_3 ( V_6 , L_9 , NULL ) ;
V_14 = F_17 ( * V_19 ) ;
if ( V_14 == NULL ) {
V_12 = - V_28 ;
goto V_27;
}
V_17 = F_3 ( V_14 , L_2 , NULL ) ;
V_16 . V_29 = V_13 [ 0 ] . V_23 ;
V_16 . V_30 = V_11 . V_23 ;
V_16 . V_14 = * V_17 ;
V_16 . V_31 = F_12 ( V_6 , 0 ) ;
if ( F_3 ( V_14 , L_10 , NULL ) )
V_16 . V_32 = V_33 ;
F_5 ( V_14 ) ;
V_12 =
F_18 ( V_9 , & V_16 ,
sizeof( T_4 ) ) ;
if ( V_12 )
goto V_27;
}
return 0 ;
V_27:
F_19 ( V_9 ) ;
V_22:
F_5 ( V_6 ) ;
return V_12 ;
}
