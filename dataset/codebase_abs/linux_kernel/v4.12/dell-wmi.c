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
if ( V_6 -> V_8 == V_11 )
F_7 (
V_12 , NULL ) ;
F_8 ( V_7 , V_6 , 1 , true ) ;
}
static void F_9 ( T_2 V_13 , void * V_14 )
{
struct V_15 V_16 = { V_17 , NULL } ;
union V_18 * V_19 ;
T_3 V_20 ;
T_4 V_21 ;
T_5 * V_22 , * V_23 ;
int V_24 , V_25 ;
V_20 = F_10 ( V_13 , & V_16 ) ;
if ( V_20 != V_26 ) {
F_11 ( L_3 , V_20 ) ;
return;
}
V_19 = (union V_18 * ) V_16 . V_27 ;
if ( ! V_19 ) {
F_11 ( L_4 ) ;
return;
}
if ( V_19 -> type != V_28 ) {
F_11 ( L_5 , V_19 -> type ) ;
F_12 ( V_19 ) ;
return;
}
F_5 ( L_6 ,
V_19 -> V_29 . V_30 , V_19 -> V_29 . V_27 ) ;
V_22 = ( T_5 * ) V_19 -> V_29 . V_27 ;
V_21 = V_19 -> V_29 . V_30 / 2 ;
V_23 = V_22 + V_21 ;
if ( V_31 == 0 && V_22 < V_23 )
if ( V_23 > V_22 + V_22 [ 0 ] + 1 )
V_23 = V_22 + V_22 [ 0 ] + 1 ;
while ( V_22 < V_23 ) {
V_24 = V_22 [ 0 ] ;
if ( V_24 == 0 )
break;
V_24 ++ ;
if ( V_22 + V_24 > V_23 ) {
F_11 ( L_7 ) ;
break;
}
F_5 ( L_8 , V_24 * 2 , V_22 ) ;
switch ( V_22 [ 1 ] ) {
case 0x0000 :
if ( V_24 > 2 )
F_2 ( 0x0000 , V_22 [ 2 ] ) ;
break;
case 0x0010 :
case 0x0011 :
for ( V_25 = 2 ; V_25 < V_24 ; ++ V_25 )
F_2 ( V_22 [ 1 ] ,
V_22 [ V_25 ] ) ;
break;
default:
F_4 ( L_9 ,
( int ) V_22 [ 1 ] ) ;
break;
}
V_22 += V_24 ;
}
F_12 ( V_19 ) ;
}
static bool F_13 ( T_2 V_32 , const struct V_5 * V_33 , int V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ )
if ( V_33 [ V_25 ] . V_4 == V_32 )
return true ;
return false ;
}
static void T_1 F_14 ( const struct V_34 * V_35 ,
void * V_36 )
{
struct V_37 * V_38 = V_36 ;
struct V_39 * V_40 ;
int V_41 , V_25 , V_42 = 0 ;
struct V_5 * V_33 ;
if ( V_38 -> V_43 || V_38 -> V_33 )
return;
if ( V_35 -> type != 0xb2 )
return;
V_40 = F_15 ( V_35 , struct V_39 , V_44 ) ;
V_41 = ( V_40 -> V_44 . V_30 -
sizeof( struct V_39 ) ) /
sizeof( struct V_45 ) ;
if ( V_41 < 1 ) {
return;
}
V_33 = F_16 ( V_41 , sizeof( struct V_5 ) , V_46 ) ;
if ( ! V_33 ) {
V_38 -> V_43 = - V_47 ;
return;
}
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ ) {
const struct V_45 * V_48 =
& V_40 -> V_33 [ V_25 ] ;
T_5 V_8 = ( V_48 -> V_8 <
F_17 ( V_49 ) ) ?
V_49 [ V_48 -> V_8 ] :
V_50 ;
if ( V_8 == V_50 ) {
F_4 ( L_10 ,
V_48 -> V_32 , V_48 -> V_8 ) ;
continue;
}
if ( V_8 == V_11 )
V_33 [ V_42 ] . type = V_51 ;
else
V_33 [ V_42 ] . type = V_52 ;
V_33 [ V_42 ] . V_4 = V_48 -> V_32 ;
V_33 [ V_42 ] . V_8 = V_8 ;
V_42 ++ ;
}
V_38 -> V_33 = V_33 ;
V_38 -> V_53 = V_42 ;
}
static int T_1 F_18 ( void )
{
struct V_37 V_54 = {} ;
struct V_5 * V_33 ;
int V_43 , V_25 , V_42 = 0 ;
V_7 = F_19 () ;
if ( ! V_7 )
return - V_47 ;
V_7 -> V_55 = L_11 ;
V_7 -> V_56 = L_12 ;
V_7 -> V_57 . V_58 = V_59 ;
if ( F_20 ( F_14 , & V_54 ) ) {
F_11 ( L_13 ) ;
}
if ( V_54 . V_43 ) {
V_43 = V_54 . V_43 ;
goto V_60;
}
V_33 = F_16 ( V_54 . V_53 +
F_17 ( V_61 ) +
F_17 ( V_62 ) +
F_17 ( V_63 ) +
1 ,
sizeof( struct V_5 ) , V_46 ) ;
if ( ! V_33 ) {
F_12 ( V_54 . V_33 ) ;
V_43 = - V_47 ;
goto V_60;
}
for ( V_25 = 0 ; V_25 < V_54 . V_53 ; V_25 ++ ) {
V_33 [ V_42 ] = V_54 . V_33 [ V_25 ] ;
V_33 [ V_42 ] . V_4 |= ( 0x0010 << 16 ) ;
V_42 ++ ;
}
F_12 ( V_54 . V_33 ) ;
for ( V_25 = 0 ; V_25 < F_17 ( V_62 ) ; V_25 ++ ) {
const struct V_5 * V_64 = & V_62 [ V_25 ] ;
if ( V_54 . V_53 &&
F_13 ( V_64 -> V_4 | ( 0x0010 << 16 ) ,
V_33 , V_54 . V_53 )
)
continue;
V_33 [ V_42 ] = * V_64 ;
V_33 [ V_42 ] . V_4 |= ( 0x0010 << 16 ) ;
V_42 ++ ;
}
for ( V_25 = 0 ; V_25 < F_17 ( V_63 ) ; V_25 ++ ) {
V_33 [ V_42 ] = V_63 [ V_25 ] ;
V_33 [ V_42 ] . V_4 |= ( 0x0011 << 16 ) ;
V_42 ++ ;
}
for ( V_25 = 0 ; V_25 < F_17 ( V_61 ) ; V_25 ++ ) {
V_33 [ V_42 ] = V_61 [ V_25 ] ;
V_42 ++ ;
}
V_33 [ V_42 ] . type = V_65 ;
V_43 = F_21 ( V_7 , V_33 , NULL ) ;
F_12 ( V_33 ) ;
if ( V_43 )
goto V_60;
V_43 = F_22 ( V_7 ) ;
if ( V_43 )
goto V_60;
return 0 ;
V_60:
F_23 ( V_7 ) ;
return V_43 ;
}
static int T_1 F_24 ( void )
{
struct V_15 V_66 = { V_17 , NULL } ;
union V_18 * V_19 ;
T_3 V_20 ;
T_2 * V_29 ;
V_20 = F_25 ( V_67 , 0 , & V_66 ) ;
if ( F_26 ( V_20 ) ) {
F_27 ( L_14 , V_20 ) ;
return V_20 ;
}
V_19 = (union V_18 * ) V_66 . V_27 ;
if ( ! V_19 ) {
F_27 ( L_15 ) ;
return - V_68 ;
}
if ( V_19 -> type != V_28 ) {
F_27 ( L_16 ) ;
F_12 ( V_19 ) ;
return - V_68 ;
}
if ( V_19 -> V_29 . V_30 != 128 ) {
F_27 ( L_17 ,
V_19 -> V_29 . V_30 ) ;
if ( V_19 -> V_29 . V_30 < 16 ) {
F_12 ( V_19 ) ;
return - V_68 ;
}
}
V_29 = ( T_2 * ) V_19 -> V_29 . V_27 ;
if ( V_29 [ 0 ] != 0x4C4C4544 && V_29 [ 1 ] != 0x494D5720 )
F_11 ( L_18 ,
8 , V_29 ) ;
if ( V_29 [ 2 ] != 0 && V_29 [ 2 ] != 1 )
F_11 ( L_19 ,
V_29 [ 2 ] ) ;
if ( V_29 [ 3 ] != 4096 )
F_11 ( L_20 ,
V_29 [ 3 ] ) ;
V_31 = V_29 [ 2 ] ;
F_4 ( L_21 ,
V_31 ) ;
F_12 ( V_19 ) ;
return 0 ;
}
static int F_28 ( bool V_69 )
{
struct V_70 * V_29 ;
int V_71 ;
V_29 = F_29 () ;
V_29 -> V_72 [ 0 ] = 0x10000 ;
V_29 -> V_72 [ 1 ] = 0x51534554 ;
V_29 -> V_72 [ 3 ] = V_69 ;
F_30 ( 17 , 3 ) ;
V_71 = V_29 -> V_73 [ 0 ] ;
F_31 () ;
return F_32 ( V_71 ) ;
}
static int T_1 F_33 ( void )
{
int V_43 ;
T_3 V_20 ;
if ( ! F_34 ( V_74 ) ||
! F_34 ( V_67 ) ) {
F_11 ( L_22 ) ;
return - V_75 ;
}
V_43 = F_24 () ;
if ( V_43 )
return V_43 ;
V_43 = F_18 () ;
if ( V_43 )
return V_43 ;
V_20 = F_35 ( V_74 ,
F_9 , NULL ) ;
if ( F_26 ( V_20 ) ) {
F_36 ( V_7 ) ;
F_27 ( L_23 , V_20 ) ;
return - V_75 ;
}
F_37 ( V_76 ) ;
if ( V_3 ) {
V_43 = F_28 ( true ) ;
if ( V_43 ) {
F_27 ( L_24 ) ;
F_38 ( V_74 ) ;
F_36 ( V_7 ) ;
return V_43 ;
}
}
return 0 ;
}
static void T_6 F_39 ( void )
{
if ( V_3 )
F_28 ( false ) ;
F_38 ( V_74 ) ;
F_36 ( V_7 ) ;
}
