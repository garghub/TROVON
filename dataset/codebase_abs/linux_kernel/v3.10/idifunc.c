static void F_1 ( unsigned char * V_1 , ... )
{
}
static void F_2 ( void )
{
F_3 () ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_3 = F_1 ;
}
static T_1 * F_4 ( T_2 * V_4 )
{
T_1 * V_5 ;
struct V_6 * V_7 ;
T_3 V_8 ;
F_5 ( & V_9 , & V_8 , L_1 ) ;
F_6 (tmp, &cards) {
V_5 = F_7 ( V_7 , T_1 , V_10 ) ;
if ( V_5 -> V_4 . V_11 == V_4 -> V_11 ) {
F_8 ( & V_9 , & V_8 ,
L_1 ) ;
return ( V_5 ) ;
}
}
F_8 ( & V_9 , & V_8 , L_1 ) ;
return ( ( T_1 * ) NULL ) ;
}
static void F_9 ( T_2 * V_4 )
{
int V_12 = 0 ;
T_1 * V_5 = NULL ;
T_4 V_13 ;
T_3 V_8 ;
if ( ! ( V_5 = F_10 ( 0 , sizeof( T_1 ) ) ) ) {
F_11 ( ( L_2 ) ) ;
return;
}
memcpy ( & V_5 -> V_4 , V_4 , sizeof( T_2 ) ) ;
V_13 . V_14 . V_15 = 0 ;
V_13 . V_14 . V_16 =
V_17 ;
V_5 -> V_4 . V_11 ( ( V_18 * ) & V_13 ) ;
V_12 =
V_13 . V_14 . V_19 . V_20 ;
V_5 -> V_21 = V_12 ;
if ( ! ( F_12 ( V_4 , V_12 ) ) ) {
F_5 ( & V_9 , & V_8 , L_3 ) ;
F_13 ( & V_5 -> V_10 , & V_22 ) ;
F_8 ( & V_9 , & V_8 , L_3 ) ;
} else {
F_11 ( ( L_4 ,
V_12 ) ) ;
F_14 ( 0 , V_5 ) ;
}
}
static void F_15 ( T_2 * V_4 )
{
T_3 V_8 ;
T_1 * V_5 = NULL ;
if ( ! ( V_5 = F_4 ( V_4 ) ) ) {
F_11 ( ( L_5 ) ) ;
return;
}
F_16 ( V_5 -> V_21 ) ;
F_5 ( & V_9 , & V_8 , L_6 ) ;
F_17 ( & V_5 -> V_10 ) ;
F_8 ( & V_9 , & V_8 , L_6 ) ;
F_18 ( ( L_7 , V_5 -> V_21 ) ) ;
F_14 ( 0 , V_5 ) ;
}
static void T_5 F_19 ( void )
{
T_1 * V_5 ;
T_3 V_8 ;
V_23:
F_5 ( & V_9 , & V_8 , L_8 ) ;
if ( ! F_20 ( & V_22 ) ) {
V_5 = F_7 ( V_22 . V_24 , T_1 , V_10 ) ;
F_17 ( & V_5 -> V_10 ) ;
F_8 ( & V_9 , & V_8 , L_8 ) ;
F_16 ( V_5 -> V_21 ) ;
F_14 ( 0 , V_5 ) ;
goto V_23;
}
F_8 ( & V_9 , & V_8 , L_8 ) ;
}
static void * F_21 ( void * V_25 , T_2 * V_26 ,
int V_27 )
{
if ( V_26 -> type == V_28 ) {
F_11 ( ( L_9 ) ) ;
return ( NULL ) ;
} else if ( V_26 -> type == V_29 ) {
if ( V_27 ) {
F_2 () ;
} else {
memcpy ( & V_2 , V_26 , sizeof( V_2 ) ) ;
V_3 = ( V_30 ) V_2 . V_11 ;
F_22 ( L_10 , V_31 , V_32 ) ;
}
} else if ( ( V_26 -> type > 0 ) && ( V_26 -> type < 16 ) ) {
if ( V_27 ) {
F_15 ( V_26 ) ;
} else {
F_9 ( V_26 ) ;
}
}
return ( NULL ) ;
}
static int T_6 F_23 ( void )
{
int V_1 = 0 ;
int V_33 = 0 ;
T_4 V_34 ;
T_2 V_35 [ V_36 ] ;
F_24 ( V_35 , sizeof( V_35 ) ) ;
for ( V_1 = 0 ; V_1 < V_36 ; V_1 ++ ) {
if ( V_35 [ V_1 ] . type == V_28 ) {
V_33 = 1 ;
memcpy ( & V_37 , & V_35 [ V_1 ] , sizeof( V_37 ) ) ;
V_34 . V_38 . V_39 . V_15 = 0 ;
V_34 . V_38 . V_39 . V_16 =
V_40 ;
V_34 . V_38 . V_19 . V_41 = ( void * ) F_21 ;
V_34 . V_38 . V_19 . V_25 = NULL ;
V_37 . V_11 ( ( V_18 * ) & V_34 ) ;
if ( V_34 . V_38 . V_39 . V_16 != 0xff ) {
F_2 () ;
return ( 0 ) ;
}
V_42 = V_34 . V_38 . V_19 . V_43 ;
} else if ( V_35 [ V_1 ] . type == V_29 ) {
memcpy ( & V_2 , & V_35 [ V_1 ] , sizeof( V_37 ) ) ;
V_3 = ( V_30 ) V_2 . V_11 ;
F_22 ( L_10 , V_31 , V_32 ) ;
} else if ( ( V_35 [ V_1 ] . type > 0 )
&& ( V_35 [ V_1 ] . type < 16 ) ) {
F_9 ( & V_35 [ V_1 ] ) ;
}
}
if ( ! V_33 ) {
F_2 () ;
}
return ( V_33 ) ;
}
static void T_5 F_25 ( void )
{
T_4 V_34 ;
F_2 () ;
V_34 . V_38 . V_39 . V_15 = 0 ;
V_34 . V_38 . V_39 . V_16 = V_44 ;
V_34 . V_38 . V_19 . V_43 = V_42 ;
V_37 . V_11 ( ( V_18 * ) & V_34 ) ;
}
int T_6 F_26 ( void )
{
F_27 ( & V_9 , L_11 ) ;
if ( F_28 () ) {
F_11 ( ( L_12 ) ) ;
return ( 0 ) ;
}
if ( ! F_23 () ) {
F_29 () ;
F_11 ( ( L_13 ) ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
void T_5 F_30 ( void )
{
F_29 () ;
F_25 () ;
F_19 () ;
}
