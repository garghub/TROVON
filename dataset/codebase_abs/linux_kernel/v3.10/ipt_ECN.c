static inline bool
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & V_8 ) != ( V_4 -> V_9 & V_8 ) ) {
T_1 V_10 ;
if ( ! F_3 ( V_2 , sizeof( struct V_5 ) ) )
return false ;
V_6 = F_2 ( V_2 ) ;
V_10 = V_6 -> V_7 ;
V_6 -> V_7 &= ~ V_8 ;
V_6 -> V_7 |= ( V_4 -> V_9 & V_8 ) ;
F_4 ( & V_6 -> V_11 , F_5 ( V_10 ) , F_5 ( V_6 -> V_7 ) ) ;
}
return true ;
}
static inline bool
F_6 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_12 V_13 , * V_14 ;
T_2 V_15 ;
V_14 = F_7 ( V_2 , F_8 ( V_2 ) , sizeof( V_13 ) , & V_13 ) ;
if ( ! V_14 )
return false ;
if ( ( ! ( V_4 -> V_16 & V_17 ) ||
V_14 -> V_18 == V_4 -> V_19 . V_20 . V_18 ) &&
( ! ( V_4 -> V_16 & V_21 ) ||
V_14 -> V_22 == V_4 -> V_19 . V_20 . V_22 ) )
return true ;
if ( ! F_3 ( V_2 , F_8 ( V_2 ) + sizeof( * V_14 ) ) )
return false ;
V_14 = ( void * ) F_2 ( V_2 ) + F_8 ( V_2 ) ;
V_15 = ( ( T_2 * ) V_14 ) [ 6 ] ;
if ( V_4 -> V_16 & V_17 )
V_14 -> V_18 = V_4 -> V_19 . V_20 . V_18 ;
if ( V_4 -> V_16 & V_21 )
V_14 -> V_22 = V_4 -> V_19 . V_20 . V_22 ;
F_9 ( & V_14 -> V_11 , V_2 ,
V_15 , ( ( T_2 * ) V_14 ) [ 6 ] , 0 ) ;
return true ;
}
static unsigned int
F_10 ( struct V_1 * V_2 , const struct V_23 * V_24 )
{
const struct V_3 * V_4 = V_24 -> V_25 ;
if ( V_4 -> V_16 & V_26 )
if ( ! F_1 ( V_2 , V_4 ) )
return V_27 ;
if ( V_4 -> V_16 & ( V_17 | V_21 ) &&
F_2 ( V_2 ) -> V_28 == V_29 )
if ( ! F_6 ( V_2 , V_4 ) )
return V_27 ;
return V_30 ;
}
static int F_11 ( const struct V_31 * V_24 )
{
const struct V_3 * V_4 = V_24 -> V_25 ;
const struct V_32 * V_33 = V_24 -> V_34 ;
if ( V_4 -> V_16 & V_35 ) {
F_12 ( L_1 , V_4 -> V_16 ) ;
return - V_36 ;
}
if ( V_4 -> V_9 & ~ V_8 ) {
F_12 ( L_2 , V_4 -> V_9 ) ;
return - V_36 ;
}
if ( ( V_4 -> V_16 & ( V_17 | V_21 ) ) &&
( V_33 -> V_37 . V_19 != V_29 || ( V_33 -> V_37 . V_38 & V_39 ) ) ) {
F_12 ( L_3 ) ;
return - V_36 ;
}
return 0 ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_40 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_40 ) ;
}
