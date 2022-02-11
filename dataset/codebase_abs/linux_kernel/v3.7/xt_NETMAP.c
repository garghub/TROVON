static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_5 V_8 ;
struct V_9 * V_10 ;
enum V_11 V_12 ;
union V_13 V_14 , V_15 ;
unsigned int V_16 ;
V_10 = F_2 ( V_2 , & V_12 ) ;
for ( V_16 = 0 ; V_16 < F_3 ( V_6 -> V_17 . V_18 ) ; V_16 ++ )
V_15 . V_18 [ V_16 ] = ~ ( V_6 -> V_17 . V_18 [ V_16 ] ^
V_6 -> V_19 . V_18 [ V_16 ] ) ;
if ( V_4 -> V_20 == V_21 ||
V_4 -> V_20 == V_22 )
V_14 . V_23 = F_4 ( V_2 ) -> V_24 ;
else
V_14 . V_23 = F_4 ( V_2 ) -> V_25 ;
for ( V_16 = 0 ; V_16 < F_3 ( V_14 . V_18 ) ; V_16 ++ ) {
V_14 . V_18 [ V_16 ] &= ~ V_15 . V_18 [ V_16 ] ;
V_14 . V_18 [ V_16 ] |= V_6 -> V_17 . V_18 [ V_16 ] &
V_15 . V_18 [ V_16 ] ;
}
V_8 . V_26 = V_6 -> V_26 | V_27 ;
V_8 . V_17 = V_14 ;
V_8 . V_19 = V_14 ;
V_8 . V_28 = V_6 -> V_28 ;
V_8 . V_29 = V_6 -> V_29 ;
return F_5 ( V_10 , & V_8 , F_6 ( V_4 -> V_20 ) ) ;
}
static int F_7 ( const struct V_30 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! ( V_6 -> V_26 & V_27 ) )
return - V_31 ;
return 0 ;
}
static unsigned int
F_8 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_9 * V_10 ;
enum V_11 V_12 ;
T_1 V_32 , V_15 ;
const struct V_33 * V_34 = V_4 -> V_7 ;
struct V_5 V_8 ;
F_9 ( V_4 -> V_20 == V_21 ||
V_4 -> V_20 == V_35 ||
V_4 -> V_20 == V_22 ||
V_4 -> V_20 == V_36 ) ;
V_10 = F_2 ( V_2 , & V_12 ) ;
V_15 = ~ ( V_34 -> V_6 [ 0 ] . V_37 ^ V_34 -> V_6 [ 0 ] . V_38 ) ;
if ( V_4 -> V_20 == V_21 ||
V_4 -> V_20 == V_22 )
V_32 = F_10 ( V_2 ) -> V_24 & ~ V_15 ;
else
V_32 = F_10 ( V_2 ) -> V_25 & ~ V_15 ;
V_32 |= V_34 -> V_6 [ 0 ] . V_37 & V_15 ;
memset ( & V_8 . V_17 , 0 , sizeof( V_8 . V_17 ) ) ;
memset ( & V_8 . V_19 , 0 , sizeof( V_8 . V_19 ) ) ;
V_8 . V_26 = V_34 -> V_6 [ 0 ] . V_26 | V_27 ;
V_8 . V_17 . V_39 = V_32 ;
V_8 . V_19 . V_39 = V_32 ;
V_8 . V_28 = V_34 -> V_6 [ 0 ] . V_40 ;
V_8 . V_29 = V_34 -> V_6 [ 0 ] . V_41 ;
return F_5 ( V_10 , & V_8 , F_6 ( V_4 -> V_20 ) ) ;
}
static int F_11 ( const struct V_30 * V_4 )
{
const struct V_33 * V_34 = V_4 -> V_7 ;
if ( ! ( V_34 -> V_6 [ 0 ] . V_26 & V_27 ) ) {
F_12 ( L_1 ) ;
return - V_31 ;
}
if ( V_34 -> V_42 != 1 ) {
F_12 ( L_2 , V_34 -> V_42 ) ;
return - V_31 ;
}
return 0 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( V_43 , F_3 ( V_43 ) ) ;
}
static void F_15 ( void )
{
F_16 ( V_43 , F_3 ( V_43 ) ) ;
}
