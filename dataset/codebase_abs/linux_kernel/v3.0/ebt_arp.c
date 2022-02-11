static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
struct V_8 V_10 ;
V_9 = F_2 ( V_2 , 0 , sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL )
return false ;
if ( V_6 -> V_11 & V_12 && F_3 ( V_6 -> V_13 !=
V_9 -> V_14 , V_12 ) )
return false ;
if ( V_6 -> V_11 & V_15 && F_3 ( V_6 -> V_16 !=
V_9 -> V_17 , V_15 ) )
return false ;
if ( V_6 -> V_11 & V_18 && F_3 ( V_6 -> V_19 !=
V_9 -> V_20 , V_18 ) )
return false ;
if ( V_6 -> V_11 & ( V_21 | V_22 | V_23 ) ) {
const T_1 * V_24 , * V_25 ;
T_1 V_26 , V_27 ;
if ( V_9 -> V_28 != sizeof( T_1 ) || V_9 -> V_20 != F_4 ( V_29 ) )
return false ;
V_24 = F_2 ( V_2 , sizeof( struct V_8 ) +
V_9 -> V_30 , sizeof( V_26 ) ,
& V_26 ) ;
if ( V_24 == NULL )
return false ;
V_25 = F_2 ( V_2 , sizeof( struct V_8 ) +
2 * V_9 -> V_30 + sizeof( V_26 ) ,
sizeof( V_27 ) , & V_27 ) ;
if ( V_25 == NULL )
return false ;
if ( V_6 -> V_11 & V_21 &&
F_3 ( V_6 -> V_26 != ( * V_24 & V_6 -> V_31 ) , V_21 ) )
return false ;
if ( V_6 -> V_11 & V_22 &&
F_3 ( V_6 -> V_27 != ( * V_25 & V_6 -> V_32 ) , V_22 ) )
return false ;
if ( V_6 -> V_11 & V_23 &&
F_3 ( * V_25 != * V_24 , V_23 ) )
return false ;
}
if ( V_6 -> V_11 & ( V_33 | V_34 ) ) {
const unsigned char * V_35 ;
unsigned char V_36 [ V_37 ] ;
T_2 V_38 , V_39 ;
if ( V_9 -> V_30 != V_37 || V_9 -> V_17 != F_4 ( V_40 ) )
return false ;
if ( V_6 -> V_11 & V_33 ) {
V_35 = F_2 ( V_2 , sizeof( struct V_8 ) ,
sizeof( V_36 ) , & V_36 ) ;
if ( V_35 == NULL )
return false ;
V_38 = 0 ;
for ( V_39 = 0 ; V_39 < 6 ; V_39 ++ )
V_38 |= ( V_35 [ V_39 ] ^ V_6 -> V_41 [ V_39 ] ) &
V_6 -> V_42 [ V_39 ] ;
if ( F_3 ( V_38 != 0 , V_33 ) )
return false ;
}
if ( V_6 -> V_11 & V_34 ) {
V_35 = F_2 ( V_2 , sizeof( struct V_8 ) +
V_9 -> V_30 + V_9 -> V_28 ,
sizeof( V_36 ) , & V_36 ) ;
if ( V_35 == NULL )
return false ;
V_38 = 0 ;
for ( V_39 = 0 ; V_39 < 6 ; V_39 ++ )
V_38 |= ( V_35 [ V_39 ] ^ V_6 -> V_43 [ V_39 ] ) &
V_6 -> V_44 [ V_39 ] ;
if ( F_3 ( V_38 != 0 , V_34 ) )
return false ;
}
}
return true ;
}
static int F_5 ( const struct V_45 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_46 * V_47 = V_4 -> V_48 ;
if ( ( V_47 -> V_49 != F_4 ( V_50 ) &&
V_47 -> V_49 != F_4 ( V_51 ) ) ||
V_47 -> V_52 & V_53 )
return - V_54 ;
if ( V_6 -> V_11 & ~ V_55 || V_6 -> V_52 & ~ V_55 )
return - V_54 ;
return 0 ;
}
static int T_3 F_6 ( void )
{
return F_7 ( & V_56 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_56 ) ;
}
