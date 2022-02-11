static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
struct V_8 V_10 ;
V_9 = F_2 ( V_2 , 0 , sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL )
return false ;
if ( ( V_6 -> V_11 & V_12 ) &&
F_3 ( V_6 , V_12 , V_6 -> V_13 != V_9 -> V_14 ) )
return false ;
if ( ( V_6 -> V_11 & V_15 ) &&
F_3 ( V_6 , V_15 , V_6 -> V_16 != V_9 -> V_17 ) )
return false ;
if ( ( V_6 -> V_11 & V_18 ) &&
F_3 ( V_6 , V_18 , V_6 -> V_19 != V_9 -> V_20 ) )
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
if ( ( V_6 -> V_11 & V_21 ) &&
F_3 ( V_6 , V_21 ,
V_6 -> V_26 != ( * V_24 & V_6 -> V_31 ) ) )
return false ;
if ( ( V_6 -> V_11 & V_22 ) &&
F_3 ( V_6 , V_22 ,
V_6 -> V_27 != ( * V_25 & V_6 -> V_32 ) ) )
return false ;
if ( ( V_6 -> V_11 & V_23 ) &&
F_3 ( V_6 , V_23 , * V_25 != * V_24 ) )
return false ;
}
if ( V_6 -> V_11 & ( V_33 | V_34 ) ) {
const unsigned char * V_35 ;
unsigned char V_36 [ V_37 ] ;
if ( V_9 -> V_30 != V_37 || V_9 -> V_17 != F_4 ( V_38 ) )
return false ;
if ( V_6 -> V_11 & V_33 ) {
V_35 = F_2 ( V_2 , sizeof( struct V_8 ) ,
sizeof( V_36 ) , & V_36 ) ;
if ( V_35 == NULL )
return false ;
if ( F_3 ( V_6 , V_33 ,
! F_5 ( V_35 , V_6 -> V_39 ,
V_6 -> V_40 ) ) )
return false ;
}
if ( V_6 -> V_11 & V_34 ) {
V_35 = F_2 ( V_2 , sizeof( struct V_8 ) +
V_9 -> V_30 + V_9 -> V_28 ,
sizeof( V_36 ) , & V_36 ) ;
if ( V_35 == NULL )
return false ;
if ( F_3 ( V_6 , V_34 ,
! F_5 ( V_35 , V_6 -> V_41 ,
V_6 -> V_42 ) ) )
return false ;
}
}
return true ;
}
static int F_6 ( const struct V_43 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_44 * V_45 = V_4 -> V_46 ;
if ( ( V_45 -> V_47 != F_4 ( V_48 ) &&
V_45 -> V_47 != F_4 ( V_49 ) ) ||
V_45 -> V_50 & V_51 )
return - V_52 ;
if ( V_6 -> V_11 & ~ V_53 || V_6 -> V_50 & ~ V_53 )
return - V_52 ;
return 0 ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_54 ) ;
}
static void T_3 F_9 ( void )
{
F_10 ( & V_54 ) ;
}
