static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
T_1 V_7 ;
T_2 V_8 ;
V_6 = & V_2 -> V_9 ;
if ( ( V_2 -> V_10 & V_11 ) &&
F_2 ( V_2 , V_11 , V_6 -> V_12 != V_4 -> V_12 ) )
return false ;
if ( V_2 -> V_10 & V_13 ) {
V_7 = F_3 ( V_4 -> V_14 ) ;
if ( F_2 ( V_2 , V_13 ,
V_7 < V_6 -> V_15 || V_7 > V_6 -> V_16 ) )
return false ;
}
if ( V_2 -> V_10 & V_17 ) {
if ( F_2 ( V_2 , V_17 ,
! F_4 ( & V_4 -> V_14 [ 2 ] ,
V_6 -> V_18 ,
V_6 -> V_19 ) ) )
return false ;
}
if ( V_2 -> V_10 & V_20 ) {
V_8 = F_5 ( V_4 -> V_21 ) ;
if ( F_2 ( V_2 , V_20 ,
V_8 < V_6 -> V_22 || V_8 > V_6 -> V_23 ) )
return false ;
}
if ( V_2 -> V_10 & V_24 ) {
V_7 = F_3 ( V_4 -> V_25 ) ;
if ( F_2 ( V_2 , V_24 ,
V_7 < V_6 -> V_26 || V_7 > V_6 -> V_27 ) )
return false ;
}
if ( V_2 -> V_10 & V_28 ) {
if ( F_2 ( V_2 , V_28 ,
! F_4 ( & V_4 -> V_25 [ 2 ] ,
V_6 -> V_29 ,
V_6 -> V_30 ) ) )
return false ;
}
if ( V_2 -> V_10 & V_31 ) {
V_7 = F_3 ( V_4 -> V_32 ) ;
if ( F_2 ( V_2 , V_31 ,
V_7 < V_6 -> V_33 || V_7 > V_6 -> V_34 ) )
return false ;
}
if ( V_2 -> V_10 & V_35 ) {
V_7 = F_3 ( V_4 -> V_36 ) ;
if ( F_2 ( V_2 , V_35 ,
V_7 < V_6 -> V_37 || V_7 > V_6 -> V_38 ) )
return false ;
}
if ( V_2 -> V_10 & V_39 ) {
V_7 = F_3 ( V_4 -> V_40 ) ;
if ( F_2 ( V_2 , V_39 ,
V_7 < V_6 -> V_41 || V_7 > V_6 -> V_42 ) )
return false ;
}
if ( V_2 -> V_10 & V_43 ) {
V_7 = F_3 ( V_4 -> V_44 ) ;
if ( F_2 ( V_2 , V_43 ,
V_7 < V_6 -> V_45 || V_7 > V_6 -> V_46 ) )
return false ;
}
if ( V_2 -> V_10 & V_47 ) {
V_7 = F_3 ( V_4 -> V_48 ) ;
if ( F_2 ( V_2 , V_47 ,
V_7 < V_6 -> V_49 || V_7 > V_6 -> V_50 ) )
return false ;
}
return true ;
}
static bool
F_6 ( const struct V_51 * V_52 , struct V_53 * V_54 )
{
const struct V_1 * V_2 = V_54 -> V_55 ;
const struct V_56 * V_57 ;
struct V_56 V_58 ;
const T_3 V_59 [ 6 ] = { 0x42 , 0x42 , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_57 = F_7 ( V_52 , 0 , sizeof( V_58 ) , & V_58 ) ;
if ( V_57 == NULL )
return false ;
if ( memcmp ( V_57 , V_59 , sizeof( V_59 ) ) )
return false ;
if ( ( V_2 -> V_10 & V_60 ) &&
F_2 ( V_2 , V_60 , V_2 -> type != V_57 -> type ) )
return false ;
if ( V_57 -> type == V_61 &&
V_2 -> V_10 & V_62 ) {
const struct V_3 * V_63 ;
struct V_3 V_64 ;
V_63 = F_7 ( V_52 , sizeof( V_58 ) ,
sizeof( V_64 ) , & V_64 ) ;
if ( V_63 == NULL )
return false ;
return F_1 ( V_2 , V_63 ) ;
}
return true ;
}
static int F_8 ( const struct V_65 * V_54 )
{
const struct V_1 * V_2 = V_54 -> V_55 ;
const T_3 V_66 [ 6 ] = { 0x01 , 0x80 , 0xc2 , 0x00 , 0x00 , 0x00 } ;
const T_3 V_67 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
const struct V_68 * V_69 = V_54 -> V_70 ;
if ( V_2 -> V_10 & ~ V_71 || V_2 -> V_72 & ~ V_71 ||
! ( V_2 -> V_10 & V_71 ) )
return - V_73 ;
if ( ! V_54 -> V_74 &&
( ! F_9 ( V_69 -> V_75 , V_66 ) ||
! F_9 ( V_69 -> V_76 , V_67 ) ||
! ( V_69 -> V_10 & V_77 ) ) )
return - V_73 ;
return 0 ;
}
static int T_4 F_10 ( void )
{
return F_11 ( & V_78 ) ;
}
static void T_5 F_12 ( void )
{
F_13 ( & V_78 ) ;
}
