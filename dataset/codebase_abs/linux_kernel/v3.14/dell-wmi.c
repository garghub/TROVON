static void F_1 ( T_1 V_1 , void * V_2 )
{
struct V_3 V_4 = { V_5 , NULL } ;
union V_6 * V_7 ;
T_2 V_8 ;
V_8 = F_2 ( V_1 , & V_4 ) ;
if ( V_8 != V_9 ) {
F_3 ( L_1 , V_8 ) ;
return;
}
V_7 = (union V_6 * ) V_4 . V_10 ;
if ( V_7 && V_7 -> type == V_11 ) {
const struct V_12 * V_13 ;
int V_14 ;
T_3 * V_15 = ( T_3 * ) V_7 -> V_16 . V_10 ;
if ( V_17 && ( V_15 [ 1 ] != 0x10 ) ) {
F_3 ( L_2 ,
V_15 [ 1 ] ) ;
F_4 ( V_7 ) ;
return;
}
if ( V_17 || V_15 [ 1 ] == 0x0 )
V_14 = ( int ) V_15 [ 2 ] ;
else
V_14 = ( int ) V_15 [ 1 ] & 0xffff ;
V_13 = F_5 ( V_18 ,
V_14 ) ;
if ( ! V_13 ) {
F_3 ( L_3 , V_14 ) ;
} else if ( ( V_13 -> V_19 == V_20 ||
V_13 -> V_19 == V_21 ) && V_22 ) {
;
} else {
F_6 ( V_18 , V_13 ,
1 , true ) ;
}
}
F_4 ( V_7 ) ;
}
static const struct V_12 * T_4 F_7 ( void )
{
int V_23 = ( V_24 -> V_25 . V_26 - 4 ) /
sizeof( struct V_27 ) ;
struct V_12 * V_28 ;
int V_29 ;
V_28 = F_8 ( V_23 + 1 , sizeof( struct V_12 ) , V_30 ) ;
if ( ! V_28 )
return NULL ;
for ( V_29 = 0 ; V_29 < V_23 ; V_29 ++ ) {
const struct V_27 * V_31 =
& V_24 -> V_28 [ V_29 ] ;
V_28 [ V_29 ] . type = V_32 ;
V_28 [ V_29 ] . V_33 = V_31 -> V_34 ;
V_28 [ V_29 ] . V_19 = V_31 -> V_19 < 256 ?
V_35 [ V_31 -> V_19 ] :
V_36 ;
}
V_28 [ V_23 ] . type = V_37 ;
return V_28 ;
}
static int T_4 F_9 ( void )
{
int V_38 ;
V_18 = F_10 () ;
if ( ! V_18 )
return - V_39 ;
V_18 -> V_40 = L_4 ;
V_18 -> V_41 = L_5 ;
V_18 -> V_42 . V_43 = V_44 ;
if ( V_17 ) {
const struct V_12 * V_28 = F_7 () ;
if ( ! V_28 ) {
V_38 = - V_39 ;
goto V_45;
}
V_38 = F_11 ( V_18 , V_28 , NULL ) ;
F_4 ( V_28 ) ;
} else {
V_38 = F_11 ( V_18 ,
V_46 , NULL ) ;
}
if ( V_38 )
goto V_45;
V_38 = F_12 ( V_18 ) ;
if ( V_38 )
goto V_47;
return 0 ;
V_47:
F_13 ( V_18 ) ;
V_45:
F_14 ( V_18 ) ;
return V_38 ;
}
static void F_15 ( void )
{
F_13 ( V_18 ) ;
F_16 ( V_18 ) ;
}
static void T_4 F_17 ( const struct V_48 * V_49 , void * V_50 )
{
if ( V_49 -> type == 0xb2 && V_49 -> V_26 > 6 ) {
V_17 = true ;
V_24 =
F_18 ( V_49 , struct V_24 , V_25 ) ;
}
}
static int T_4 F_19 ( void )
{
int V_38 ;
T_2 V_8 ;
if ( ! F_20 ( V_51 ) ) {
F_21 ( L_6 ) ;
return - V_52 ;
}
F_22 ( F_17 , NULL ) ;
V_22 = F_23 () ;
V_38 = F_9 () ;
if ( V_38 )
return V_38 ;
V_8 = F_24 ( V_51 ,
F_1 , NULL ) ;
if ( F_25 ( V_8 ) ) {
F_15 () ;
F_26 ( L_7 , V_8 ) ;
return - V_52 ;
}
return 0 ;
}
static void T_5 F_27 ( void )
{
F_28 ( V_51 ) ;
F_15 () ;
}
