static void F_1 ( int V_1 )
{
const struct V_2 * V_3 ;
V_3 = F_2 ( V_4 ,
V_1 ) ;
if ( ! V_3 ) {
F_3 ( L_1 ,
V_1 ) ;
return;
}
F_4 ( L_2 , V_1 ) ;
if ( ( V_3 -> V_5 == V_6 ||
V_3 -> V_5 == V_7 ) &&
F_5 () )
return;
F_6 ( V_4 , V_3 , 1 , true ) ;
}
static void F_7 ( T_1 V_8 , void * V_9 )
{
struct V_10 V_11 = { V_12 , NULL } ;
union V_13 * V_14 ;
T_2 V_15 ;
T_3 V_16 ;
T_4 * V_17 , * V_18 ;
int V_19 , V_20 ;
V_15 = F_8 ( V_8 , & V_11 ) ;
if ( V_15 != V_21 ) {
F_9 ( L_3 , V_15 ) ;
return;
}
V_14 = (union V_13 * ) V_11 . V_22 ;
if ( ! V_14 ) {
F_9 ( L_4 ) ;
return;
}
if ( V_14 -> type != V_23 ) {
F_9 ( L_5 , V_14 -> type ) ;
F_10 ( V_14 ) ;
return;
}
F_4 ( L_6 ,
V_14 -> V_24 . V_25 , V_14 -> V_24 . V_22 ) ;
V_17 = ( T_4 * ) V_14 -> V_24 . V_22 ;
V_16 = V_14 -> V_24 . V_25 / 2 ;
if ( ! V_26 ) {
if ( V_16 >= 3 && V_17 [ 1 ] == 0x0 )
F_1 ( V_17 [ 2 ] ) ;
else if ( V_16 >= 2 )
F_1 ( V_17 [ 1 ] ) ;
else
F_3 ( L_7 ) ;
F_10 ( V_14 ) ;
return;
}
V_18 = V_17 + V_16 ;
if ( V_27 == 0 && V_17 < V_18 )
if ( V_18 > V_17 + V_17 [ 0 ] + 1 )
V_18 = V_17 + V_17 [ 0 ] + 1 ;
while ( V_17 < V_18 ) {
V_19 = V_17 [ 0 ] ;
if ( V_19 == 0 )
break;
V_19 ++ ;
if ( V_17 + V_19 > V_18 ) {
F_9 ( L_8 ) ;
break;
}
F_4 ( L_9 , V_19 * 2 , V_17 ) ;
switch ( V_17 [ 1 ] ) {
case 0x00 :
for ( V_20 = 2 ; V_20 < V_19 ; ++ V_20 ) {
switch ( V_17 [ V_20 ] ) {
case 0xe043 :
F_4 ( L_10 ) ;
break;
case 0xe044 :
F_4 ( L_11 ) ;
break;
case 0xe045 :
default:
F_3 ( L_12
L_13 , ( int ) V_17 [ V_20 ] ) ;
break;
}
}
break;
case 0x10 :
for ( V_20 = 2 ; V_20 < V_19 ; ++ V_20 )
F_1 ( V_17 [ V_20 ] ) ;
break;
case 0x11 :
for ( V_20 = 2 ; V_20 < V_19 ; ++ V_20 ) {
switch ( V_17 [ V_20 ] ) {
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
L_13 , ( int ) V_17 [ V_20 ] ) ;
break;
}
}
break;
default:
F_3 ( L_19 ,
( int ) V_17 [ 1 ] ) ;
break;
}
V_17 += V_19 ;
}
F_10 ( V_14 ) ;
}
static const struct V_2 * T_5 F_11 ( void )
{
int V_28 = ( V_29 -> V_30 . V_25 - 4 ) /
sizeof( struct V_31 ) ;
struct V_2 * V_32 ;
int V_20 ;
V_32 = F_12 ( V_28 + 1 , sizeof( struct V_2 ) , V_33 ) ;
if ( ! V_32 )
return NULL ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
const struct V_31 * V_34 =
& V_29 -> V_32 [ V_20 ] ;
T_4 V_5 = ( V_34 -> V_5 <
F_13 ( V_35 ) ) ?
V_35 [ V_34 -> V_5 ] :
V_36 ;
if ( V_5 == V_36 ) {
F_3 ( L_20 ,
V_34 -> V_37 , V_34 -> V_5 ) ;
continue;
}
if ( V_5 == V_38 )
V_32 [ V_20 ] . type = V_39 ;
else
V_32 [ V_20 ] . type = V_40 ;
V_32 [ V_20 ] . V_41 = V_34 -> V_37 ;
V_32 [ V_20 ] . V_5 = V_5 ;
}
V_32 [ V_28 ] . type = V_42 ;
return V_32 ;
}
static int T_5 F_14 ( void )
{
int V_43 ;
V_4 = F_15 () ;
if ( ! V_4 )
return - V_44 ;
V_4 -> V_45 = L_21 ;
V_4 -> V_46 = L_22 ;
V_4 -> V_47 . V_48 = V_49 ;
if ( V_26 ) {
const struct V_2 * V_32 = F_11 () ;
if ( ! V_32 ) {
V_43 = - V_44 ;
goto V_50;
}
V_43 = F_16 ( V_4 , V_32 , NULL ) ;
F_10 ( V_32 ) ;
} else {
V_43 = F_16 ( V_4 ,
V_51 , NULL ) ;
}
if ( V_43 )
goto V_50;
V_43 = F_17 ( V_4 ) ;
if ( V_43 )
goto V_52;
return 0 ;
V_52:
F_18 ( V_4 ) ;
V_50:
F_19 ( V_4 ) ;
return V_43 ;
}
static void F_20 ( void )
{
F_18 ( V_4 ) ;
F_21 ( V_4 ) ;
}
static void T_5 F_22 ( const struct V_53 * V_54 , void * V_55 )
{
if ( V_54 -> type == 0xb2 && V_54 -> V_25 > 6 ) {
V_26 = true ;
V_29 =
F_23 ( V_54 , struct V_29 , V_30 ) ;
}
}
static int T_5 F_24 ( void )
{
struct V_10 V_56 = { V_12 , NULL } ;
union V_13 * V_14 ;
T_2 V_15 ;
T_1 * V_24 ;
V_15 = F_25 ( V_57 , 0 , & V_56 ) ;
if ( F_26 ( V_15 ) ) {
F_27 ( L_23 , V_15 ) ;
return V_15 ;
}
V_14 = (union V_13 * ) V_56 . V_22 ;
if ( ! V_14 ) {
F_27 ( L_24 ) ;
return - V_58 ;
}
if ( V_14 -> type != V_23 ) {
F_27 ( L_25 ) ;
F_10 ( V_14 ) ;
return - V_58 ;
}
if ( V_14 -> V_24 . V_25 != 128 ) {
F_27 ( L_26 ,
V_14 -> V_24 . V_25 ) ;
if ( V_14 -> V_24 . V_25 < 16 ) {
F_10 ( V_14 ) ;
return - V_58 ;
}
}
V_24 = ( T_1 * ) V_14 -> V_24 . V_22 ;
if ( V_24 [ 0 ] != 0x4C4C4544 && V_24 [ 1 ] != 0x494D5720 )
F_9 ( L_27 ,
8 , V_24 ) ;
if ( V_24 [ 2 ] != 0 && V_24 [ 2 ] != 1 )
F_9 ( L_28 ,
V_24 [ 2 ] ) ;
if ( V_24 [ 3 ] != 4096 )
F_9 ( L_29 ,
V_24 [ 3 ] ) ;
V_27 = V_24 [ 2 ] ;
F_3 ( L_30 ,
V_27 ) ;
F_10 ( V_14 ) ;
return 0 ;
}
static int T_5 F_28 ( void )
{
int V_43 ;
T_2 V_15 ;
if ( ! F_29 ( V_59 ) ||
! F_29 ( V_57 ) ) {
F_9 ( L_31 ) ;
return - V_60 ;
}
V_43 = F_24 () ;
if ( V_43 )
return V_43 ;
F_30 ( F_22 , NULL ) ;
V_43 = F_14 () ;
if ( V_43 )
return V_43 ;
V_15 = F_31 ( V_59 ,
F_7 , NULL ) ;
if ( F_26 ( V_15 ) ) {
F_20 () ;
F_27 ( L_32 , V_15 ) ;
return - V_60 ;
}
return 0 ;
}
static void T_6 F_32 ( void )
{
F_33 ( V_59 ) ;
F_20 () ;
}
