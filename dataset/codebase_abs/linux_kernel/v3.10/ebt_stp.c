static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
T_1 V_7 ;
T_2 V_8 ;
int V_9 , V_10 ;
V_6 = & V_2 -> V_11 ;
if ( ( V_2 -> V_12 & V_13 ) &&
F_2 ( V_6 -> V_14 != V_4 -> V_14 , V_13 ) )
return false ;
if ( V_2 -> V_12 & V_15 ) {
V_7 = F_3 ( V_4 -> V_16 ) ;
if ( F_2 ( V_7 < V_6 -> V_17 ||
V_7 > V_6 -> V_18 , V_15 ) )
return false ;
}
if ( V_2 -> V_12 & V_19 ) {
V_9 = 0 ;
for ( V_10 = 0 ; V_10 < 6 ; V_10 ++ )
V_9 |= ( V_4 -> V_16 [ 2 + V_10 ] ^ V_6 -> V_20 [ V_10 ] ) &
V_6 -> V_21 [ V_10 ] ;
if ( F_2 ( V_9 != 0 , V_19 ) )
return false ;
}
if ( V_2 -> V_12 & V_22 ) {
V_8 = F_4 ( V_4 -> V_23 ) ;
if ( F_2 ( V_8 < V_6 -> V_24 ||
V_8 > V_6 -> V_25 , V_22 ) )
return false ;
}
if ( V_2 -> V_12 & V_26 ) {
V_7 = F_3 ( V_4 -> V_27 ) ;
if ( F_2 ( V_7 < V_6 -> V_28 ||
V_7 > V_6 -> V_29 , V_26 ) )
return false ;
}
if ( V_2 -> V_12 & V_30 ) {
V_9 = 0 ;
for ( V_10 = 0 ; V_10 < 6 ; V_10 ++ )
V_9 |= ( V_4 -> V_27 [ 2 + V_10 ] ^ V_6 -> V_31 [ V_10 ] ) &
V_6 -> V_32 [ V_10 ] ;
if ( F_2 ( V_9 != 0 , V_30 ) )
return false ;
}
if ( V_2 -> V_12 & V_33 ) {
V_7 = F_3 ( V_4 -> V_34 ) ;
if ( F_2 ( V_7 < V_6 -> V_35 ||
V_7 > V_6 -> V_36 , V_33 ) )
return false ;
}
if ( V_2 -> V_12 & V_37 ) {
V_7 = F_3 ( V_4 -> V_38 ) ;
if ( F_2 ( V_7 < V_6 -> V_39 ||
V_7 > V_6 -> V_40 , V_37 ) )
return false ;
}
if ( V_2 -> V_12 & V_41 ) {
V_7 = F_3 ( V_4 -> V_42 ) ;
if ( F_2 ( V_7 < V_6 -> V_43 ||
V_7 > V_6 -> V_44 , V_41 ) )
return false ;
}
if ( V_2 -> V_12 & V_45 ) {
V_7 = F_3 ( V_4 -> V_46 ) ;
if ( F_2 ( V_7 < V_6 -> V_47 ||
V_7 > V_6 -> V_48 , V_45 ) )
return false ;
}
if ( V_2 -> V_12 & V_49 ) {
V_7 = F_3 ( V_4 -> V_50 ) ;
if ( F_2 ( V_7 < V_6 -> V_51 ||
V_7 > V_6 -> V_52 , V_49 ) )
return false ;
}
return true ;
}
static bool
F_5 ( const struct V_53 * V_54 , struct V_55 * V_56 )
{
const struct V_1 * V_2 = V_56 -> V_57 ;
const struct V_58 * V_59 ;
struct V_58 V_60 ;
const T_3 V_61 [ 6 ] = { 0x42 , 0x42 , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_59 = F_6 ( V_54 , 0 , sizeof( V_60 ) , & V_60 ) ;
if ( V_59 == NULL )
return false ;
if ( memcmp ( V_59 , V_61 , sizeof( V_61 ) ) )
return false ;
if ( V_2 -> V_12 & V_62 &&
F_2 ( V_2 -> type != V_59 -> type , V_62 ) )
return false ;
if ( V_59 -> type == V_63 &&
V_2 -> V_12 & V_64 ) {
const struct V_3 * V_65 ;
struct V_3 V_66 ;
V_65 = F_6 ( V_54 , sizeof( V_60 ) ,
sizeof( V_66 ) , & V_66 ) ;
if ( V_65 == NULL )
return false ;
return F_1 ( V_2 , V_65 ) ;
}
return true ;
}
static int F_7 ( const struct V_67 * V_56 )
{
const struct V_1 * V_2 = V_56 -> V_57 ;
const T_3 V_68 [ 6 ] = { 0x01 , 0x80 , 0xc2 , 0x00 , 0x00 , 0x00 } ;
const T_3 V_69 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
const struct V_70 * V_71 = V_56 -> V_72 ;
if ( V_2 -> V_12 & ~ V_73 || V_2 -> V_74 & ~ V_73 ||
! ( V_2 -> V_12 & V_73 ) )
return - V_75 ;
if ( ! F_8 ( V_71 -> V_76 , V_68 ) ||
! F_8 ( V_71 -> V_77 , V_69 ) || ! ( V_71 -> V_12 & V_78 ) )
return - V_75 ;
return 0 ;
}
static int T_4 F_9 ( void )
{
return F_10 ( & V_79 ) ;
}
static void T_5 F_11 ( void )
{
F_12 ( & V_79 ) ;
}
