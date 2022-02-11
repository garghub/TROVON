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
int V_17 = V_7 -> V_16 . V_18 / 2 ;
if ( V_17 >= 2 && V_19 && V_15 [ 1 ] != 0x10 ) {
F_3 ( L_2 ,
V_15 [ 1 ] ) ;
F_4 ( V_7 ) ;
return;
}
if ( V_17 >= 3 && ( V_19 || V_15 [ 1 ] == 0x0 ) )
V_14 = ( int ) V_15 [ 2 ] ;
else if ( V_17 >= 2 )
V_14 = ( int ) V_15 [ 1 ] & 0xffff ;
else {
F_3 ( L_3 ) ;
F_4 ( V_7 ) ;
return;
}
V_13 = F_5 ( V_20 ,
V_14 ) ;
if ( ! V_13 ) {
F_3 ( L_4 , V_14 ) ;
} else if ( ( V_13 -> V_21 == V_22 ||
V_13 -> V_21 == V_23 ) && V_24 ) {
;
} else {
F_6 ( V_20 , V_13 ,
1 , true ) ;
}
}
F_4 ( V_7 ) ;
}
static const struct V_12 * T_4 F_7 ( void )
{
int V_25 = ( V_26 -> V_27 . V_18 - 4 ) /
sizeof( struct V_28 ) ;
struct V_12 * V_29 ;
int V_30 ;
V_29 = F_8 ( V_25 + 1 , sizeof( struct V_12 ) , V_31 ) ;
if ( ! V_29 )
return NULL ;
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ ) {
const struct V_28 * V_32 =
& V_26 -> V_29 [ V_30 ] ;
V_29 [ V_30 ] . type = V_33 ;
V_29 [ V_30 ] . V_34 = V_32 -> V_35 ;
V_29 [ V_30 ] . V_21 = V_32 -> V_21 < 256 ?
V_36 [ V_32 -> V_21 ] :
V_37 ;
}
V_29 [ V_25 ] . type = V_38 ;
return V_29 ;
}
static int T_4 F_9 ( void )
{
int V_39 ;
V_20 = F_10 () ;
if ( ! V_20 )
return - V_40 ;
V_20 -> V_41 = L_5 ;
V_20 -> V_42 = L_6 ;
V_20 -> V_43 . V_44 = V_45 ;
if ( V_19 ) {
const struct V_12 * V_29 = F_7 () ;
if ( ! V_29 ) {
V_39 = - V_40 ;
goto V_46;
}
V_39 = F_11 ( V_20 , V_29 , NULL ) ;
F_4 ( V_29 ) ;
} else {
V_39 = F_11 ( V_20 ,
V_47 , NULL ) ;
}
if ( V_39 )
goto V_46;
V_39 = F_12 ( V_20 ) ;
if ( V_39 )
goto V_48;
return 0 ;
V_48:
F_13 ( V_20 ) ;
V_46:
F_14 ( V_20 ) ;
return V_39 ;
}
static void F_15 ( void )
{
F_13 ( V_20 ) ;
F_16 ( V_20 ) ;
}
static void T_4 F_17 ( const struct V_49 * V_50 , void * V_51 )
{
if ( V_50 -> type == 0xb2 && V_50 -> V_18 > 6 ) {
V_19 = true ;
V_26 =
F_18 ( V_50 , struct V_26 , V_27 ) ;
}
}
static int T_4 F_19 ( void )
{
int V_39 ;
T_2 V_8 ;
if ( ! F_20 ( V_52 ) ) {
F_21 ( L_7 ) ;
return - V_53 ;
}
F_22 ( F_17 , NULL ) ;
V_24 = F_23 () ;
V_39 = F_9 () ;
if ( V_39 )
return V_39 ;
V_8 = F_24 ( V_52 ,
F_1 , NULL ) ;
if ( F_25 ( V_8 ) ) {
F_15 () ;
F_26 ( L_8 , V_8 ) ;
return - V_53 ;
}
return 0 ;
}
static void T_5 F_27 ( void )
{
F_28 ( V_52 ) ;
F_15 () ;
}
