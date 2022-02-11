static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return ( V_3 T_1 ) V_2 -> V_4 [ V_5 ] . V_6 . V_7 . V_8 . V_9 ;
}
static inline const T_1 * F_2 ( const struct V_1 * V_2 )
{
return ( V_3 T_1 * ) V_2 -> V_4 [ V_5 ] . V_6 . V_7 . V_8 . V_10 ;
}
static inline T_2
F_3 ( T_2 V_9 , const struct V_11 * V_12 )
{
return F_4 ( V_9 , V_12 -> V_13 ) ;
}
static inline T_2
F_5 ( const void * V_9 , const struct V_11 * V_12 )
{
return F_6 ( V_9 , V_14 / sizeof( V_15 ) , V_12 -> V_13 ) ;
}
static inline T_2
F_7 ( const struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
T_2 V_16 = 0 ;
switch( F_8 ( V_2 ) ) {
case V_17 :
V_16 = F_3 ( F_1 ( V_2 ) , V_12 ) ;
break;
case V_18 :
V_16 = F_5 ( F_2 ( V_2 ) , V_12 ) ;
break;
default:
F_9 ( 1 ) ;
break;
}
return ( ( ( V_19 ) V_16 * V_12 -> V_20 ) >> 32 ) ;
}
static inline bool
F_10 ( const struct V_21 * V_22 )
{
T_3 V_23 = V_22 -> V_24 [ 0 ] ;
return ( ( V_23 & F_11 ( 0xFF000000 ) ) == F_11 ( 0xFF000000 ) ) ;
}
static inline bool
F_12 ( const struct V_25 * V_26 , T_4 V_27 )
{
bool V_28 = false ;
switch( V_27 ) {
case V_29 :
V_28 = F_13 ( F_14 ( V_26 ) -> V_30 ) ;
break;
case V_31 :
V_28 =
F_10 ( & F_15 ( V_26 ) -> V_30 ) ;
break;
default:
F_9 ( 1 ) ;
break;
}
return V_28 ;
}
static bool
F_16 ( const struct V_25 * V_26 , struct V_32 * V_33 )
{
struct V_25 * V_34 = (struct V_25 * ) V_26 ;
const struct V_11 * V_12 = V_33 -> V_35 ;
const struct V_1 * V_2 ;
enum V_36 V_37 ;
unsigned long V_16 ;
if ( ! F_12 ( V_26 , V_33 -> V_27 ) &&
V_26 -> V_38 == V_39 ) {
V_34 -> V_38 = V_40 ;
}
V_2 = F_17 ( V_26 , & V_37 ) ;
if ( V_2 == NULL )
return false ;
if ( F_18 ( V_2 ) )
return false ;
if ( V_2 -> V_41 )
V_16 = F_7 ( V_2 -> V_41 , V_12 ) ;
else
V_16 = F_7 ( V_2 , V_12 ) ;
return ! ! ( ( 1 << V_16 ) & V_12 -> V_42 ) ^
! ! ( V_12 -> V_43 & V_44 ) ;
}
static int F_19 ( const struct V_45 * V_33 )
{
struct V_11 * V_12 = V_33 -> V_35 ;
if ( V_12 -> V_20 > V_46 ) {
F_20 ( L_1
L_2 ,
V_12 -> V_20 , V_46 ) ;
return - V_47 ;
}
if ( V_12 -> V_42 >= ( 1ULL << V_12 -> V_20 ) ) {
F_20 ( L_3
L_4 ) ;
return - V_48 ;
}
return 0 ;
}
static int T_5 F_21 ( void )
{
return F_22 ( & V_49 ) ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_49 ) ;
}
