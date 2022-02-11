static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = 1 ;
return 1 ;
}
static void F_2 ( int type , int V_4 )
{
const struct V_5 * V_6 ;
V_6 = F_3 ( V_7 ,
( type << 16 ) | V_4 ) ;
if ( ! V_6 ) {
F_4 ( L_1 ,
type , V_4 ) ;
return;
}
F_5 ( L_2 , type , V_4 ) ;
if ( ( V_6 -> V_8 == V_9 ||
V_6 -> V_8 == V_10 ) &&
F_6 () )
return;
if ( type == 0x0000 && V_4 == 0xe025 && ! V_3 )
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
V_21 = V_20 + V_19 ;
if ( V_29 == 0 && V_20 < V_21 )
if ( V_21 > V_20 + V_20 [ 0 ] + 1 )
V_21 = V_20 + V_20 [ 0 ] + 1 ;
while ( V_20 < V_21 ) {
V_22 = V_20 [ 0 ] ;
if ( V_22 == 0 )
break;
V_22 ++ ;
if ( V_20 + V_22 > V_21 ) {
F_10 ( L_7 ) ;
break;
}
F_5 ( L_8 , V_22 * 2 , V_20 ) ;
switch ( V_20 [ 1 ] ) {
case 0x0000 :
if ( V_22 > 2 )
F_2 ( 0x0000 , V_20 [ 2 ] ) ;
break;
case 0x0010 :
case 0x0011 :
for ( V_23 = 2 ; V_23 < V_22 ; ++ V_23 )
F_2 ( V_20 [ 1 ] ,
V_20 [ V_23 ] ) ;
break;
default:
F_4 ( L_9 ,
( int ) V_20 [ 1 ] ) ;
break;
}
V_20 += V_22 ;
}
F_11 ( V_17 ) ;
}
static bool F_12 ( T_2 V_30 , const struct V_5 * V_31 , int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
if ( V_31 [ V_23 ] . V_4 == V_30 )
return true ;
return false ;
}
static void T_1 F_13 ( const struct V_32 * V_33 ,
void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_37 * V_38 ;
int V_39 , V_23 , V_40 = 0 ;
struct V_5 * V_31 ;
if ( V_36 -> V_41 || V_36 -> V_31 )
return;
if ( V_33 -> type != 0xb2 )
return;
V_38 = F_14 ( V_33 , struct V_37 , V_42 ) ;
V_39 = ( V_38 -> V_42 . V_28 -
sizeof( struct V_37 ) ) /
sizeof( struct V_43 ) ;
if ( V_39 < 1 ) {
return;
}
V_31 = F_15 ( V_39 , sizeof( struct V_5 ) , V_44 ) ;
if ( ! V_31 ) {
V_36 -> V_41 = - V_45 ;
return;
}
for ( V_23 = 0 ; V_23 < V_39 ; V_23 ++ ) {
const struct V_43 * V_46 =
& V_38 -> V_31 [ V_23 ] ;
T_5 V_8 = ( V_46 -> V_8 <
F_16 ( V_47 ) ) ?
V_47 [ V_46 -> V_8 ] :
V_48 ;
if ( V_8 == V_48 ) {
F_4 ( L_10 ,
V_46 -> V_30 , V_46 -> V_8 ) ;
continue;
}
if ( V_8 == V_49 )
V_31 [ V_40 ] . type = V_50 ;
else
V_31 [ V_40 ] . type = V_51 ;
V_31 [ V_40 ] . V_4 = V_46 -> V_30 ;
V_31 [ V_40 ] . V_8 = V_8 ;
V_40 ++ ;
}
V_36 -> V_31 = V_31 ;
V_36 -> V_52 = V_40 ;
}
static int T_1 F_17 ( void )
{
struct V_35 V_53 = {} ;
struct V_5 * V_31 ;
int V_41 , V_23 , V_40 = 0 ;
V_7 = F_18 () ;
if ( ! V_7 )
return - V_45 ;
V_7 -> V_54 = L_11 ;
V_7 -> V_55 = L_12 ;
V_7 -> V_56 . V_57 = V_58 ;
if ( F_19 ( F_13 , & V_53 ) ) {
F_10 ( L_13 ) ;
}
if ( V_53 . V_41 ) {
V_41 = V_53 . V_41 ;
goto V_59;
}
V_31 = F_15 ( V_53 . V_52 +
F_16 ( V_60 ) +
F_16 ( V_61 ) +
F_16 ( V_62 ) +
1 ,
sizeof( struct V_5 ) , V_44 ) ;
if ( ! V_31 ) {
F_11 ( V_53 . V_31 ) ;
V_41 = - V_45 ;
goto V_59;
}
for ( V_23 = 0 ; V_23 < V_53 . V_52 ; V_23 ++ ) {
V_31 [ V_40 ] = V_53 . V_31 [ V_23 ] ;
V_31 [ V_40 ] . V_4 |= ( 0x0010 << 16 ) ;
V_40 ++ ;
}
F_11 ( V_53 . V_31 ) ;
for ( V_23 = 0 ; V_23 < F_16 ( V_61 ) ; V_23 ++ ) {
const struct V_5 * V_63 = & V_61 [ V_23 ] ;
if ( V_53 . V_52 &&
F_12 ( V_63 -> V_4 | ( 0x0010 << 16 ) ,
V_31 , V_53 . V_52 )
)
continue;
V_31 [ V_40 ] = * V_63 ;
V_31 [ V_40 ] . V_4 |= ( 0x0010 << 16 ) ;
V_40 ++ ;
}
for ( V_23 = 0 ; V_23 < F_16 ( V_62 ) ; V_23 ++ ) {
V_31 [ V_40 ] = V_62 [ V_23 ] ;
V_31 [ V_40 ] . V_4 |= ( 0x0011 << 16 ) ;
V_40 ++ ;
}
for ( V_23 = 0 ; V_23 < F_16 ( V_60 ) ; V_23 ++ ) {
V_31 [ V_40 ] = V_60 [ V_23 ] ;
V_40 ++ ;
}
V_31 [ V_40 ] . type = V_64 ;
V_41 = F_20 ( V_7 , V_31 , NULL ) ;
F_11 ( V_31 ) ;
if ( V_41 )
goto V_59;
V_41 = F_21 ( V_7 ) ;
if ( V_41 )
goto V_65;
return 0 ;
V_65:
F_22 ( V_7 ) ;
V_59:
F_23 ( V_7 ) ;
return V_41 ;
}
static void F_24 ( void )
{
F_22 ( V_7 ) ;
F_25 ( V_7 ) ;
}
static int T_1 F_26 ( void )
{
struct V_13 V_66 = { V_15 , NULL } ;
union V_16 * V_17 ;
T_3 V_18 ;
T_2 * V_27 ;
V_18 = F_27 ( V_67 , 0 , & V_66 ) ;
if ( F_28 ( V_18 ) ) {
F_29 ( L_14 , V_18 ) ;
return V_18 ;
}
V_17 = (union V_16 * ) V_66 . V_25 ;
if ( ! V_17 ) {
F_29 ( L_15 ) ;
return - V_68 ;
}
if ( V_17 -> type != V_26 ) {
F_29 ( L_16 ) ;
F_11 ( V_17 ) ;
return - V_68 ;
}
if ( V_17 -> V_27 . V_28 != 128 ) {
F_29 ( L_17 ,
V_17 -> V_27 . V_28 ) ;
if ( V_17 -> V_27 . V_28 < 16 ) {
F_11 ( V_17 ) ;
return - V_68 ;
}
}
V_27 = ( T_2 * ) V_17 -> V_27 . V_25 ;
if ( V_27 [ 0 ] != 0x4C4C4544 && V_27 [ 1 ] != 0x494D5720 )
F_10 ( L_18 ,
8 , V_27 ) ;
if ( V_27 [ 2 ] != 0 && V_27 [ 2 ] != 1 )
F_10 ( L_19 ,
V_27 [ 2 ] ) ;
if ( V_27 [ 3 ] != 4096 )
F_10 ( L_20 ,
V_27 [ 3 ] ) ;
V_29 = V_27 [ 2 ] ;
F_4 ( L_21 ,
V_29 ) ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_30 ( bool V_69 )
{
struct V_70 * V_27 ;
int V_71 ;
V_27 = F_31 () ;
V_27 -> V_72 [ 0 ] = 0x10000 ;
V_27 -> V_72 [ 1 ] = 0x51534554 ;
V_27 -> V_72 [ 3 ] = V_69 ;
F_32 ( 17 , 3 ) ;
V_71 = V_27 -> V_73 [ 0 ] ;
F_33 () ;
return F_34 ( V_71 ) ;
}
static int T_1 F_35 ( void )
{
int V_41 ;
T_3 V_18 ;
if ( ! F_36 ( V_74 ) ||
! F_36 ( V_67 ) ) {
F_10 ( L_22 ) ;
return - V_75 ;
}
V_41 = F_26 () ;
if ( V_41 )
return V_41 ;
V_41 = F_17 () ;
if ( V_41 )
return V_41 ;
V_18 = F_37 ( V_74 ,
F_8 , NULL ) ;
if ( F_28 ( V_18 ) ) {
F_24 () ;
F_29 ( L_23 , V_18 ) ;
return - V_75 ;
}
F_38 ( V_76 ) ;
if ( V_3 ) {
V_41 = F_30 ( true ) ;
if ( V_41 ) {
F_29 ( L_24 ) ;
F_39 ( V_74 ) ;
F_24 () ;
return V_41 ;
}
}
return 0 ;
}
static void T_6 F_40 ( void )
{
if ( V_3 )
F_30 ( false ) ;
F_39 ( V_74 ) ;
F_24 () ;
}
