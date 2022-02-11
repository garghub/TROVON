static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = 1 ;
return 1 ;
}
static void F_2 ( int V_4 )
{
const struct V_5 * V_6 ;
V_6 = F_3 ( V_7 ,
V_4 ) ;
if ( ! V_6 ) {
F_4 ( L_1 ,
V_4 ) ;
return;
}
F_5 ( L_2 , V_4 ) ;
if ( ( V_6 -> V_8 == V_9 ||
V_6 -> V_8 == V_10 ) &&
F_6 () )
return;
if ( V_4 == 0xe025 && ! V_3 )
return;
F_7 ( V_7 , V_6 , 1 , true ) ;
}
static void F_8 ( T_2 V_11 , void * V_12 )
{
struct V_13 V_14 = { V_15 , NULL } ;
union V_16 * V_17 ;
T_3 V_18 ;
T_4 V_19 ;
T_5 * V_20 , * V_21 ;
int V_22 , V_23 ;
V_18 = F_9 ( V_11 , & V_14 ) ;
if ( V_18 != V_24 ) {
F_10 ( L_3 , V_18 ) ;
return;
}
V_17 = (union V_16 * ) V_14 . V_25 ;
if ( ! V_17 ) {
F_10 ( L_4 ) ;
return;
}
if ( V_17 -> type != V_26 ) {
F_10 ( L_5 , V_17 -> type ) ;
F_11 ( V_17 ) ;
return;
}
F_5 ( L_6 ,
V_17 -> V_27 . V_28 , V_17 -> V_27 . V_25 ) ;
V_20 = ( T_5 * ) V_17 -> V_27 . V_25 ;
V_19 = V_17 -> V_27 . V_28 / 2 ;
if ( ! V_29 ) {
if ( V_19 >= 3 && V_20 [ 1 ] == 0x0 )
F_2 ( V_20 [ 2 ] ) ;
else if ( V_19 >= 2 )
F_2 ( V_20 [ 1 ] ) ;
else
F_4 ( L_7 ) ;
F_11 ( V_17 ) ;
return;
}
V_21 = V_20 + V_19 ;
if ( V_30 == 0 && V_20 < V_21 )
if ( V_21 > V_20 + V_20 [ 0 ] + 1 )
V_21 = V_20 + V_20 [ 0 ] + 1 ;
while ( V_20 < V_21 ) {
V_22 = V_20 [ 0 ] ;
if ( V_22 == 0 )
break;
V_22 ++ ;
if ( V_20 + V_22 > V_21 ) {
F_10 ( L_8 ) ;
break;
}
F_5 ( L_9 , V_22 * 2 , V_20 ) ;
switch ( V_20 [ 1 ] ) {
case 0x00 :
for ( V_23 = 2 ; V_23 < V_22 ; ++ V_23 ) {
switch ( V_20 [ V_23 ] ) {
case 0xe043 :
F_5 ( L_10 ) ;
break;
case 0xe044 :
F_5 ( L_11 ) ;
break;
case 0xe045 :
default:
F_4 ( L_12
L_13 , ( int ) V_20 [ V_23 ] ) ;
break;
}
}
break;
case 0x10 :
for ( V_23 = 2 ; V_23 < V_22 ; ++ V_23 )
F_2 ( V_20 [ V_23 ] ) ;
break;
case 0x11 :
for ( V_23 = 2 ; V_23 < V_22 ; ++ V_23 ) {
switch ( V_20 [ V_23 ] ) {
case 0xfff0 :
F_5 ( L_14 ) ;
break;
case 0xfff1 :
F_5 ( L_15 ) ;
break;
case 0x01e1 :
case 0x02ea :
case 0x02eb :
case 0x02ec :
case 0x02f6 :
F_5 ( L_16
L_17 ) ;
break;
default:
F_4 ( L_18
L_13 , ( int ) V_20 [ V_23 ] ) ;
break;
}
}
break;
default:
F_4 ( L_19 ,
( int ) V_20 [ 1 ] ) ;
break;
}
V_20 += V_22 ;
}
F_11 ( V_17 ) ;
}
static bool F_12 ( T_2 V_31 , const struct V_5 * V_32 , int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
if ( V_32 [ V_23 ] . V_33 == V_31 )
return true ;
return false ;
}
static void T_1 F_13 ( const struct V_34 * V_35 ,
void * V_36 )
{
struct V_37 * V_38 = V_36 ;
struct V_39 * V_40 ;
int V_41 , V_23 , V_42 = 0 ;
struct V_5 * V_32 ;
int V_43 ;
if ( V_38 -> V_44 || V_38 -> V_32 )
return;
if ( V_35 -> type != 0xb2 )
return;
V_40 = F_14 ( V_35 , struct V_39 , V_45 ) ;
V_41 = ( V_40 -> V_45 . V_28 -
sizeof( struct V_39 ) ) /
sizeof( struct V_46 ) ;
if ( V_41 < 1 ) {
return;
}
V_32 = F_15 ( V_41 + F_16 ( V_47 ) + 1 ,
sizeof( struct V_5 ) , V_48 ) ;
if ( ! V_32 ) {
V_38 -> V_44 = - V_49 ;
return;
}
for ( V_23 = 0 ; V_23 < V_41 ; V_23 ++ ) {
const struct V_46 * V_50 =
& V_40 -> V_32 [ V_23 ] ;
T_5 V_8 = ( V_50 -> V_8 <
F_16 ( V_51 ) ) ?
V_51 [ V_50 -> V_8 ] :
V_52 ;
if ( V_8 == V_52 ) {
F_4 ( L_20 ,
V_50 -> V_31 , V_50 -> V_8 ) ;
continue;
}
if ( V_8 == V_53 )
V_32 [ V_42 ] . type = V_54 ;
else
V_32 [ V_42 ] . type = V_55 ;
V_32 [ V_42 ] . V_33 = V_50 -> V_31 ;
V_32 [ V_42 ] . V_8 = V_8 ;
V_42 ++ ;
}
V_43 = V_42 ;
for ( V_23 = 0 ; V_23 < F_16 ( V_47 ) ; V_23 ++ ) {
const struct V_5 * V_56 = & V_47 [ V_23 ] ;
if ( ! F_12 ( V_56 -> V_33 , V_32 , V_43 ) ) {
V_32 [ V_42 ] = * V_56 ;
V_42 ++ ;
}
}
V_32 [ V_42 ] . type = V_57 ;
V_38 -> V_32 = V_32 ;
}
static int T_1 F_17 ( void )
{
struct V_37 V_58 = {} ;
int V_44 ;
V_7 = F_18 () ;
if ( ! V_7 )
return - V_49 ;
V_7 -> V_59 = L_21 ;
V_7 -> V_60 = L_22 ;
V_7 -> V_61 . V_62 = V_63 ;
if ( F_19 ( F_13 , & V_58 ) ) {
F_10 ( L_23 ) ;
}
if ( V_58 . V_44 ) {
V_44 = V_58 . V_44 ;
goto V_64;
}
if ( V_58 . V_32 ) {
V_29 = true ;
V_44 = F_20 ( V_7 ,
V_58 . V_32 , NULL ) ;
F_11 ( V_58 . V_32 ) ;
} else {
V_44 = F_20 ( V_7 ,
V_65 , NULL ) ;
}
if ( V_44 )
goto V_64;
V_44 = F_21 ( V_7 ) ;
if ( V_44 )
goto V_66;
return 0 ;
V_66:
F_22 ( V_7 ) ;
V_64:
F_23 ( V_7 ) ;
return V_44 ;
}
static void F_24 ( void )
{
F_22 ( V_7 ) ;
F_25 ( V_7 ) ;
}
static int T_1 F_26 ( void )
{
struct V_13 V_67 = { V_15 , NULL } ;
union V_16 * V_17 ;
T_3 V_18 ;
T_2 * V_27 ;
V_18 = F_27 ( V_68 , 0 , & V_67 ) ;
if ( F_28 ( V_18 ) ) {
F_29 ( L_24 , V_18 ) ;
return V_18 ;
}
V_17 = (union V_16 * ) V_67 . V_25 ;
if ( ! V_17 ) {
F_29 ( L_25 ) ;
return - V_69 ;
}
if ( V_17 -> type != V_26 ) {
F_29 ( L_26 ) ;
F_11 ( V_17 ) ;
return - V_69 ;
}
if ( V_17 -> V_27 . V_28 != 128 ) {
F_29 ( L_27 ,
V_17 -> V_27 . V_28 ) ;
if ( V_17 -> V_27 . V_28 < 16 ) {
F_11 ( V_17 ) ;
return - V_69 ;
}
}
V_27 = ( T_2 * ) V_17 -> V_27 . V_25 ;
if ( V_27 [ 0 ] != 0x4C4C4544 && V_27 [ 1 ] != 0x494D5720 )
F_10 ( L_28 ,
8 , V_27 ) ;
if ( V_27 [ 2 ] != 0 && V_27 [ 2 ] != 1 )
F_10 ( L_29 ,
V_27 [ 2 ] ) ;
if ( V_27 [ 3 ] != 4096 )
F_10 ( L_30 ,
V_27 [ 3 ] ) ;
V_30 = V_27 [ 2 ] ;
F_4 ( L_31 ,
V_30 ) ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_30 ( bool V_70 )
{
struct V_71 * V_27 ;
int V_72 ;
V_27 = F_31 () ;
V_27 -> V_73 [ 0 ] = 0x10000 ;
V_27 -> V_73 [ 1 ] = 0x51534554 ;
V_27 -> V_73 [ 3 ] = V_70 ;
F_32 ( 17 , 3 ) ;
V_72 = V_27 -> V_74 [ 0 ] ;
F_33 () ;
return F_34 ( V_72 ) ;
}
static int T_1 F_35 ( void )
{
int V_44 ;
T_3 V_18 ;
if ( ! F_36 ( V_75 ) ||
! F_36 ( V_68 ) ) {
F_10 ( L_32 ) ;
return - V_76 ;
}
V_44 = F_26 () ;
if ( V_44 )
return V_44 ;
V_44 = F_17 () ;
if ( V_44 )
return V_44 ;
V_18 = F_37 ( V_75 ,
F_8 , NULL ) ;
if ( F_28 ( V_18 ) ) {
F_24 () ;
F_29 ( L_33 , V_18 ) ;
return - V_76 ;
}
F_38 ( V_77 ) ;
if ( V_3 ) {
V_44 = F_30 ( true ) ;
if ( V_44 ) {
F_29 ( L_34 ) ;
F_39 ( V_75 ) ;
F_24 () ;
return V_44 ;
}
}
return 0 ;
}
static void T_6 F_40 ( void )
{
if ( V_3 )
F_30 ( false ) ;
F_39 ( V_75 ) ;
F_24 () ;
}
