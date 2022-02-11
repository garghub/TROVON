static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = 1 ;
return 1 ;
}
static void F_2 ( struct V_4 * V_5 , int type , int V_6 )
{
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 ) ;
const struct V_10 * V_11 ;
V_11 = F_4 ( V_8 -> V_12 ,
( type << 16 ) | V_6 ) ;
if ( ! V_11 ) {
F_5 ( L_1 ,
type , V_6 ) ;
return;
}
F_6 ( L_2 , type , V_6 ) ;
if ( ( V_11 -> V_13 == V_14 ||
V_11 -> V_13 == V_15 ) &&
F_7 () )
return;
if ( type == 0x0000 && V_6 == 0xe025 && ! V_3 )
return;
if ( V_11 -> V_13 == V_16 )
F_8 (
V_17 , NULL ) ;
F_9 ( V_8 -> V_12 , V_11 , 1 , true ) ;
}
static void F_10 ( struct V_4 * V_5 ,
union V_18 * V_19 )
{
T_2 * V_20 , * V_21 ;
T_3 V_22 ;
int V_23 , V_24 ;
if ( V_19 -> type != V_25 ) {
F_11 ( L_3 , V_19 -> type ) ;
return;
}
F_6 ( L_4 ,
V_19 -> V_26 . V_27 , V_19 -> V_26 . V_28 ) ;
V_20 = ( T_2 * ) V_19 -> V_26 . V_28 ;
V_22 = V_19 -> V_26 . V_27 / 2 ;
V_21 = V_20 + V_22 ;
if ( V_29 == 0 && V_20 < V_21 )
if ( V_21 > V_20 + V_20 [ 0 ] + 1 )
V_21 = V_20 + V_20 [ 0 ] + 1 ;
while ( V_20 < V_21 ) {
V_23 = V_20 [ 0 ] ;
if ( V_23 == 0 )
break;
V_23 ++ ;
if ( V_20 + V_23 > V_21 ) {
F_11 ( L_5 ) ;
break;
}
F_6 ( L_6 , V_23 * 2 , V_20 ) ;
switch ( V_20 [ 1 ] ) {
case 0x0000 :
if ( V_23 > 2 )
F_2 ( V_5 , 0x0000 ,
V_20 [ 2 ] ) ;
break;
case 0x0010 :
case 0x0011 :
for ( V_24 = 2 ; V_24 < V_23 ; ++ V_24 )
F_2 ( V_5 , V_20 [ 1 ] ,
V_20 [ V_24 ] ) ;
break;
default:
F_5 ( L_7 ,
( int ) V_20 [ 1 ] ) ;
break;
}
V_20 += V_23 ;
}
}
static bool F_12 ( T_4 V_30 , const struct V_10 * V_31 , int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ )
if ( V_31 [ V_24 ] . V_6 == V_30 )
return true ;
return false ;
}
static void F_13 ( const struct V_32 * V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_37 * V_38 ;
int V_39 , V_24 , V_40 = 0 ;
struct V_10 * V_31 ;
if ( V_36 -> V_41 || V_36 -> V_31 )
return;
if ( V_33 -> type != 0xb2 )
return;
V_38 = F_14 ( V_33 , struct V_37 , V_42 ) ;
V_39 = ( V_38 -> V_42 . V_27 -
sizeof( struct V_37 ) ) /
sizeof( struct V_43 ) ;
if ( V_39 < 1 ) {
return;
}
V_31 = F_15 ( V_39 , sizeof( struct V_10 ) , V_44 ) ;
if ( ! V_31 ) {
V_36 -> V_41 = - V_45 ;
return;
}
for ( V_24 = 0 ; V_24 < V_39 ; V_24 ++ ) {
const struct V_43 * V_46 =
& V_38 -> V_31 [ V_24 ] ;
T_2 V_13 = ( V_46 -> V_13 <
F_16 ( V_47 ) ) ?
V_47 [ V_46 -> V_13 ] :
V_48 ;
if ( V_13 == V_48 ) {
F_5 ( L_8 ,
V_46 -> V_30 , V_46 -> V_13 ) ;
continue;
}
if ( V_13 == V_16 )
V_31 [ V_40 ] . type = V_49 ;
else
V_31 [ V_40 ] . type = V_50 ;
V_31 [ V_40 ] . V_6 = V_46 -> V_30 ;
V_31 [ V_40 ] . V_13 = V_13 ;
V_40 ++ ;
}
V_36 -> V_31 = V_31 ;
V_36 -> V_51 = V_40 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 ) ;
struct V_35 V_52 = {} ;
struct V_10 * V_31 ;
int V_41 , V_24 , V_40 = 0 ;
V_8 -> V_12 = F_18 () ;
if ( ! V_8 -> V_12 )
return - V_45 ;
V_8 -> V_12 -> V_53 = L_9 ;
V_8 -> V_12 -> V_54 . V_55 = V_56 ;
V_8 -> V_12 -> V_9 . V_57 = & V_5 -> V_9 ;
if ( F_19 ( F_13 , & V_52 ) ) {
F_11 ( L_10 ) ;
}
if ( V_52 . V_41 ) {
V_41 = V_52 . V_41 ;
goto V_58;
}
V_31 = F_15 ( V_52 . V_51 +
F_16 ( V_59 ) +
F_16 ( V_60 ) +
F_16 ( V_61 ) +
1 ,
sizeof( struct V_10 ) , V_44 ) ;
if ( ! V_31 ) {
F_20 ( V_52 . V_31 ) ;
V_41 = - V_45 ;
goto V_58;
}
for ( V_24 = 0 ; V_24 < V_52 . V_51 ; V_24 ++ ) {
V_31 [ V_40 ] = V_52 . V_31 [ V_24 ] ;
V_31 [ V_40 ] . V_6 |= ( 0x0010 << 16 ) ;
V_40 ++ ;
}
F_20 ( V_52 . V_31 ) ;
for ( V_24 = 0 ; V_24 < F_16 ( V_60 ) ; V_24 ++ ) {
const struct V_10 * V_62 = & V_60 [ V_24 ] ;
if ( V_52 . V_51 &&
F_12 ( V_62 -> V_6 | ( 0x0010 << 16 ) ,
V_31 , V_52 . V_51 )
)
continue;
V_31 [ V_40 ] = * V_62 ;
V_31 [ V_40 ] . V_6 |= ( 0x0010 << 16 ) ;
V_40 ++ ;
}
for ( V_24 = 0 ; V_24 < F_16 ( V_61 ) ; V_24 ++ ) {
V_31 [ V_40 ] = V_61 [ V_24 ] ;
V_31 [ V_40 ] . V_6 |= ( 0x0011 << 16 ) ;
V_40 ++ ;
}
for ( V_24 = 0 ; V_24 < F_16 ( V_59 ) ; V_24 ++ ) {
V_31 [ V_40 ] = V_59 [ V_24 ] ;
V_40 ++ ;
}
V_31 [ V_40 ] . type = V_63 ;
V_41 = F_21 ( V_8 -> V_12 , V_31 , NULL ) ;
F_20 ( V_31 ) ;
if ( V_41 )
goto V_58;
V_41 = F_22 ( V_8 -> V_12 ) ;
if ( V_41 )
goto V_58;
return 0 ;
V_58:
F_23 ( V_8 -> V_12 ) ;
return V_41 ;
}
static void F_24 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 ) ;
F_25 ( V_8 -> V_12 ) ;
}
static int F_26 ( void )
{
struct V_64 V_65 = { V_66 , NULL } ;
union V_18 * V_19 ;
T_5 V_67 ;
T_4 * V_26 ;
V_67 = F_27 ( V_68 , 0 , & V_65 ) ;
if ( F_28 ( V_67 ) ) {
F_29 ( L_11 , V_67 ) ;
return V_67 ;
}
V_19 = (union V_18 * ) V_65 . V_28 ;
if ( ! V_19 ) {
F_29 ( L_12 ) ;
return - V_69 ;
}
if ( V_19 -> type != V_25 ) {
F_29 ( L_13 ) ;
F_20 ( V_19 ) ;
return - V_69 ;
}
if ( V_19 -> V_26 . V_27 != 128 ) {
F_29 ( L_14 ,
V_19 -> V_26 . V_27 ) ;
if ( V_19 -> V_26 . V_27 < 16 ) {
F_20 ( V_19 ) ;
return - V_69 ;
}
}
V_26 = ( T_4 * ) V_19 -> V_26 . V_28 ;
if ( V_26 [ 0 ] != 0x4C4C4544 && V_26 [ 1 ] != 0x494D5720 )
F_11 ( L_15 ,
8 , V_26 ) ;
if ( V_26 [ 2 ] != 0 && V_26 [ 2 ] != 1 )
F_11 ( L_16 ,
V_26 [ 2 ] ) ;
if ( V_26 [ 3 ] != 4096 )
F_11 ( L_17 ,
V_26 [ 3 ] ) ;
V_29 = V_26 [ 2 ] ;
F_5 ( L_18 ,
V_29 ) ;
F_20 ( V_19 ) ;
return 0 ;
}
static int F_30 ( bool V_70 )
{
struct V_71 * V_26 ;
int V_72 ;
V_26 = F_31 () ;
V_26 -> V_73 [ 0 ] = 0x10000 ;
V_26 -> V_73 [ 1 ] = 0x51534554 ;
V_26 -> V_73 [ 3 ] = V_70 ;
F_32 ( 17 , 3 ) ;
V_72 = V_26 -> V_74 [ 0 ] ;
F_33 () ;
return F_34 ( V_72 ) ;
}
static int F_35 ( struct V_4 * V_5 )
{
int V_41 ;
struct V_7 * V_8 = F_36 (
& V_5 -> V_9 , sizeof( struct V_7 ) , V_44 ) ;
V_41 = F_26 () ;
if ( V_41 )
return V_41 ;
F_37 ( & V_5 -> V_9 , V_8 ) ;
return F_17 ( V_5 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
F_24 ( V_5 ) ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_41 ;
F_40 ( V_75 ) ;
if ( V_3 ) {
V_41 = F_30 ( true ) ;
if ( V_41 ) {
F_29 ( L_19 ) ;
return V_41 ;
}
}
return F_41 ( & V_76 ) ;
}
static void T_6 F_42 ( void )
{
if ( V_3 )
F_30 ( false ) ;
F_43 ( & V_76 ) ;
}
