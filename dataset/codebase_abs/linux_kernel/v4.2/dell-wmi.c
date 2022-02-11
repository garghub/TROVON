static void F_1 ( int V_1 )
{
const struct V_2 * V_3 ;
V_3 = F_2 ( V_4 ,
V_1 ) ;
if ( ! V_3 ) {
F_3 ( L_1 , V_1 ) ;
return;
}
F_4 ( L_2 , V_1 ) ;
if ( ( V_3 -> V_5 == V_6 ||
V_3 -> V_5 == V_7 ) && V_8 )
return;
F_5 ( V_4 , V_3 , 1 , true ) ;
}
static void F_6 ( T_1 V_9 , void * V_10 )
{
struct V_11 V_12 = { V_13 , NULL } ;
union V_14 * V_15 ;
T_2 V_16 ;
T_3 V_17 ;
T_4 * V_18 , * V_19 ;
int V_20 , V_21 ;
V_16 = F_7 ( V_9 , & V_12 ) ;
if ( V_16 != V_22 ) {
F_8 ( L_3 , V_16 ) ;
return;
}
V_15 = (union V_14 * ) V_12 . V_23 ;
if ( ! V_15 ) {
F_8 ( L_4 ) ;
return;
}
if ( V_15 -> type != V_24 ) {
F_8 ( L_5 , V_15 -> type ) ;
F_9 ( V_15 ) ;
return;
}
F_4 ( L_6 ,
V_15 -> V_25 . V_26 , V_15 -> V_25 . V_23 ) ;
V_18 = ( T_4 * ) V_15 -> V_25 . V_23 ;
V_17 = V_15 -> V_25 . V_26 / 2 ;
if ( ! V_27 ) {
if ( V_17 >= 3 && V_18 [ 1 ] == 0x0 )
F_1 ( V_18 [ 2 ] ) ;
else if ( V_17 >= 2 )
F_1 ( V_18 [ 1 ] ) ;
else
F_3 ( L_7 ) ;
F_9 ( V_15 ) ;
return;
}
V_19 = V_18 + V_17 ;
while ( V_18 < V_19 ) {
V_20 = V_18 [ 0 ] ;
if ( V_20 == 0 )
break;
V_20 ++ ;
if ( V_18 + V_20 > V_19 ) {
F_8 ( L_8 ) ;
break;
}
F_4 ( L_9 , V_20 * 2 , V_18 ) ;
switch ( V_18 [ 1 ] ) {
case 0x00 :
for ( V_21 = 2 ; V_21 < V_20 ; ++ V_21 ) {
switch ( V_18 [ V_21 ] ) {
case 0xe043 :
F_4 ( L_10 ) ;
break;
case 0xe044 :
F_4 ( L_11 ) ;
break;
case 0xe045 :
default:
F_3 ( L_12
L_13 , ( int ) V_18 [ V_21 ] ) ;
break;
}
}
break;
case 0x10 :
for ( V_21 = 2 ; V_21 < V_20 ; ++ V_21 )
F_1 ( V_18 [ V_21 ] ) ;
break;
case 0x11 :
for ( V_21 = 2 ; V_21 < V_20 ; ++ V_21 ) {
switch ( V_18 [ V_21 ] ) {
case 0xfff0 :
F_4 ( L_14 ) ;
break;
case 0xfff1 :
F_4 ( L_15 ) ;
break;
case 0x01e1 :
case 0x02ea :
case 0x02eb :
case 0x02ec :
case 0x02f6 :
F_4 ( L_16
L_17 ) ;
break;
default:
F_3 ( L_18
L_13 , ( int ) V_18 [ V_21 ] ) ;
break;
}
}
break;
default:
F_3 ( L_19 ,
( int ) V_18 [ 1 ] ) ;
break;
}
V_18 += V_20 ;
}
F_9 ( V_15 ) ;
}
static const struct V_2 * T_5 F_10 ( void )
{
int V_28 = ( V_29 -> V_30 . V_26 - 4 ) /
sizeof( struct V_31 ) ;
struct V_2 * V_32 ;
int V_21 ;
V_32 = F_11 ( V_28 + 1 , sizeof( struct V_2 ) , V_33 ) ;
if ( ! V_32 )
return NULL ;
for ( V_21 = 0 ; V_21 < V_28 ; V_21 ++ ) {
const struct V_31 * V_34 =
& V_29 -> V_32 [ V_21 ] ;
T_4 V_5 = V_34 -> V_5 < 256 ?
V_35 [ V_34 -> V_5 ] :
V_36 ;
if ( V_5 == V_37 )
V_32 [ V_21 ] . type = V_38 ;
else
V_32 [ V_21 ] . type = V_39 ;
V_32 [ V_21 ] . V_40 = V_34 -> V_41 ;
V_32 [ V_21 ] . V_5 = V_5 ;
}
V_32 [ V_28 ] . type = V_42 ;
return V_32 ;
}
static int T_5 F_12 ( void )
{
int V_43 ;
V_4 = F_13 () ;
if ( ! V_4 )
return - V_44 ;
V_4 -> V_45 = L_20 ;
V_4 -> V_46 = L_21 ;
V_4 -> V_47 . V_48 = V_49 ;
if ( V_27 ) {
const struct V_2 * V_32 = F_10 () ;
if ( ! V_32 ) {
V_43 = - V_44 ;
goto V_50;
}
V_43 = F_14 ( V_4 , V_32 , NULL ) ;
F_9 ( V_32 ) ;
} else {
V_43 = F_14 ( V_4 ,
V_51 , NULL ) ;
}
if ( V_43 )
goto V_50;
V_43 = F_15 ( V_4 ) ;
if ( V_43 )
goto V_52;
return 0 ;
V_52:
F_16 ( V_4 ) ;
V_50:
F_17 ( V_4 ) ;
return V_43 ;
}
static void F_18 ( void )
{
F_16 ( V_4 ) ;
F_19 ( V_4 ) ;
}
static void T_5 F_20 ( const struct V_53 * V_54 , void * V_55 )
{
if ( V_54 -> type == 0xb2 && V_54 -> V_26 > 6 ) {
V_27 = true ;
V_29 =
F_21 ( V_54 , struct V_29 , V_30 ) ;
}
}
static int T_5 F_22 ( void )
{
int V_43 ;
T_2 V_16 ;
if ( ! F_23 ( V_56 ) ) {
F_8 ( L_22 ) ;
return - V_57 ;
}
F_24 ( F_20 , NULL ) ;
V_8 = F_25 () != V_58 ;
V_43 = F_12 () ;
if ( V_43 )
return V_43 ;
V_16 = F_26 ( V_56 ,
F_6 , NULL ) ;
if ( F_27 ( V_16 ) ) {
F_18 () ;
F_28 ( L_23 , V_16 ) ;
return - V_57 ;
}
return 0 ;
}
static void T_6 F_29 ( void )
{
F_30 ( V_56 ) ;
F_18 () ;
}
