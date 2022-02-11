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
return F_10 ( V_16 , V_12 -> V_19 ) ;
}
static inline bool
F_11 ( const struct V_20 * V_21 )
{
T_3 V_22 = V_21 -> V_23 [ 0 ] ;
return ( ( V_22 & F_12 ( 0xFF000000 ) ) == F_12 ( 0xFF000000 ) ) ;
}
static inline bool
F_13 ( const struct V_24 * V_25 , T_4 V_26 )
{
bool V_27 = false ;
switch( V_26 ) {
case V_28 :
V_27 = F_14 ( F_15 ( V_25 ) -> V_29 ) ;
break;
case V_30 :
V_27 =
F_11 ( & F_16 ( V_25 ) -> V_29 ) ;
break;
default:
F_9 ( 1 ) ;
break;
}
return V_27 ;
}
static bool
F_17 ( const struct V_24 * V_25 , struct V_31 * V_32 )
{
struct V_24 * V_33 = (struct V_24 * ) V_25 ;
const struct V_11 * V_12 = V_32 -> V_34 ;
const struct V_1 * V_2 ;
enum V_35 V_36 ;
unsigned long V_16 ;
if ( ! F_13 ( V_25 , F_18 ( V_32 ) ) &&
V_25 -> V_37 == V_38 ) {
V_33 -> V_37 = V_39 ;
}
V_2 = F_19 ( V_25 , & V_36 ) ;
if ( V_2 == NULL )
return false ;
if ( V_2 -> V_40 )
V_16 = F_7 ( V_2 -> V_40 , V_12 ) ;
else
V_16 = F_7 ( V_2 , V_12 ) ;
return ! ! ( ( 1 << V_16 ) & V_12 -> V_41 ) ^
! ! ( V_12 -> V_42 & V_43 ) ;
}
static int F_20 ( const struct V_44 * V_32 )
{
struct V_11 * V_12 = V_32 -> V_34 ;
if ( V_12 -> V_19 > V_45 ) {
F_21 ( L_1
L_2 ,
V_12 -> V_19 , V_45 ) ;
return - V_46 ;
}
if ( V_12 -> V_41 >= ( 1ULL << V_12 -> V_19 ) ) {
F_21 ( L_3
L_4 ) ;
return - V_47 ;
}
return 0 ;
}
static int T_5 F_22 ( void )
{
return F_23 ( & V_48 ) ;
}
static void T_6 F_24 ( void )
{
F_25 ( & V_48 ) ;
}
