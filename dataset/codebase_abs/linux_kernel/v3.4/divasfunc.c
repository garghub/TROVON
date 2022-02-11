static void F_1 ( unsigned char * V_1 , ... )
{
}
void F_2 ( T_1 V_2 , char * V_3 )
{
int V_4 = 0 ;
if ( ( V_4 = ( ( V_2 -> V_5 & 0xff000000 ) >> 24 ) ) ) {
sprintf ( V_3 , L_1 ,
V_2 -> V_5 & 0x00ffffff , V_4 + 1 ) ;
} else {
sprintf ( V_3 , L_2 , V_2 -> V_5 ) ;
}
}
void F_3 ( int V_6 )
{
T_2 V_7 ;
T_3 V_8 ;
if ( V_6 && ( ( V_6 - 1 ) < V_9 ) &&
V_10 [ V_6 - 1 ] && V_11 [ V_6 - 1 ] ) {
V_7 . type = V_10 [ V_6 - 1 ] -> V_12 . V_13 ;
V_7 . V_14 = V_11 [ V_6 - 1 ] ;
V_7 . V_15 = V_10 [ V_6 - 1 ] -> V_12 . V_16 ;
V_7 . V_17 = V_10 [ V_6 - 1 ] -> V_12 . V_18 ;
F_4 ((L_3, card,
d.channels))
F_5 ( V_10 [ V_6 - 1 ] -> V_19 ,
V_10 [ V_6 - 1 ] -> V_12 . V_19 ,
sizeof( V_10 [ V_6 - 1 ] -> V_19 ) ) ;
V_8 . V_20 . V_21 . V_22 = 0 ;
V_8 . V_23 . V_21 . V_24 = V_25 ;
V_8 . V_23 . V_26 . V_27 = ( void * ) & V_7 ;
V_28 . V_14 ( ( V_29 * ) & V_8 ) ;
if ( V_8 . V_23 . V_21 . V_24 != 0xff ) {
F_6 ((L_4, card))
}
V_10 [ V_6 - 1 ] -> V_30 = NULL ;
}
}
void F_7 ( int V_6 )
{
T_3 V_8 ;
T_4 * V_31 = & V_10 [ V_6 - 1 ] -> V_31 ;
V_10 [ V_6 - 1 ] -> V_30 = NULL ;
F_4 ((L_5, card))
V_8 . V_20 . V_21 . V_22 = 0 ;
V_8 . V_20 . V_21 . V_24 = V_32 ;
V_8 . V_20 . V_26 . V_33 =
( V_34 ) V_11 [ V_6 - 1 ] ;
V_28 . V_14 ( ( V_29 * ) & V_8 ) ;
memset ( & ( V_31 -> V_35 ) , 0x00 , 256 ) ;
}
static void F_8 ( void )
{
F_9 ( L_6 , V_36 , ( V_37 ) ? V_37 : V_38 ) ;
F_10 ((L_7,
DIVA_BUILD, diva_xdi_common_code_build))
}
static void F_11 ( void )
{
F_12 () ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_40 = F_1 ;
}
static void * F_13 ( void * V_41 , T_2 * V_42 ,
int V_43 )
{
if ( V_42 -> type == V_44 ) {
F_6 ( ( L_8 ) ) ;
return ( NULL ) ;
}
if ( V_42 -> type == V_45 ) {
if ( V_43 ) {
F_11 () ;
} else {
memcpy ( & V_39 , V_42 , sizeof( V_39 ) ) ;
V_40 = ( V_46 ) V_39 . V_14 ;
F_8 () ;
}
}
return ( NULL ) ;
}
static int T_5 F_14 ( void )
{
int V_1 = 0 ;
int V_47 = 0 ;
T_3 V_8 ;
T_2 V_48 [ V_49 ] ;
F_15 ( V_48 , sizeof( V_48 ) ) ;
for ( V_1 = 0 ; V_1 < V_49 ; V_1 ++ ) {
if ( V_48 [ V_1 ] . type == V_44 ) {
V_47 = 1 ;
memcpy ( & V_28 , & V_48 [ V_1 ] , sizeof( V_28 ) ) ;
V_8 . V_50 . V_21 . V_22 = 0 ;
V_8 . V_50 . V_21 . V_24 =
V_51 ;
V_8 . V_50 . V_26 . V_52 = ( void * ) F_13 ;
V_8 . V_50 . V_26 . V_41 = NULL ;
V_28 . V_14 ( ( V_29 * ) & V_8 ) ;
if ( V_8 . V_50 . V_21 . V_24 != 0xff ) {
F_11 () ;
return ( 0 ) ;
}
V_53 = V_8 . V_50 . V_26 . V_54 ;
} else if ( V_48 [ V_1 ] . type == V_45 ) {
memcpy ( & V_39 , & V_48 [ V_1 ] , sizeof( V_28 ) ) ;
V_40 = ( V_46 ) V_39 . V_14 ;
F_8 () ;
}
}
if ( ! V_47 ) {
F_11 () ;
}
return ( V_47 ) ;
}
static void F_16 ( void )
{
T_3 V_8 ;
F_11 () ;
V_8 . V_50 . V_21 . V_22 = 0 ;
V_8 . V_50 . V_21 . V_24 = V_55 ;
V_8 . V_50 . V_26 . V_54 = V_53 ;
V_28 . V_14 ( ( V_29 * ) & V_8 ) ;
}
int T_5 F_17 ( int V_56 )
{
char * V_57 ;
V_37 = V_56 ;
if ( ! F_14 () ) {
F_6 ((L_9))
return ( 0 ) ;
}
V_57 = V_58 ;
F_18 () ;
return ( 1 ) ;
}
void F_19 ( void )
{
F_20 () ;
F_16 () ;
}
