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
if ( F_4 ( V_4 ) == V_20 ||
F_4 ( V_4 ) == V_21 )
V_14 . V_22 = F_5 ( V_2 ) -> V_23 ;
else
V_14 . V_22 = F_5 ( V_2 ) -> V_24 ;
for ( V_16 = 0 ; V_16 < F_3 ( V_14 . V_18 ) ; V_16 ++ ) {
V_14 . V_18 [ V_16 ] &= ~ V_15 . V_18 [ V_16 ] ;
V_14 . V_18 [ V_16 ] |= V_6 -> V_17 . V_18 [ V_16 ] &
V_15 . V_18 [ V_16 ] ;
}
V_8 . V_25 = V_6 -> V_25 | V_26 ;
V_8 . V_17 = V_14 ;
V_8 . V_19 = V_14 ;
V_8 . V_27 = V_6 -> V_27 ;
V_8 . V_28 = V_6 -> V_28 ;
return F_6 ( V_10 , & V_8 , F_7 ( F_4 ( V_4 ) ) ) ;
}
static int F_8 ( const struct V_29 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! ( V_6 -> V_25 & V_26 ) )
return - V_30 ;
return F_9 ( V_4 -> V_31 , V_4 -> V_32 ) ;
}
static void F_10 ( const struct V_33 * V_4 )
{
F_11 ( V_4 -> V_31 , V_4 -> V_32 ) ;
}
static unsigned int
F_12 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_9 * V_10 ;
enum V_11 V_12 ;
T_1 V_34 , V_15 ;
const struct V_35 * V_36 = V_4 -> V_7 ;
struct V_5 V_8 ;
F_13 ( F_4 ( V_4 ) == V_20 ||
F_4 ( V_4 ) == V_37 ||
F_4 ( V_4 ) == V_21 ||
F_4 ( V_4 ) == V_38 ) ;
V_10 = F_2 ( V_2 , & V_12 ) ;
V_15 = ~ ( V_36 -> V_6 [ 0 ] . V_39 ^ V_36 -> V_6 [ 0 ] . V_40 ) ;
if ( F_4 ( V_4 ) == V_20 ||
F_4 ( V_4 ) == V_21 )
V_34 = F_14 ( V_2 ) -> V_23 & ~ V_15 ;
else
V_34 = F_14 ( V_2 ) -> V_24 & ~ V_15 ;
V_34 |= V_36 -> V_6 [ 0 ] . V_39 & V_15 ;
memset ( & V_8 . V_17 , 0 , sizeof( V_8 . V_17 ) ) ;
memset ( & V_8 . V_19 , 0 , sizeof( V_8 . V_19 ) ) ;
V_8 . V_25 = V_36 -> V_6 [ 0 ] . V_25 | V_26 ;
V_8 . V_17 . V_41 = V_34 ;
V_8 . V_19 . V_41 = V_34 ;
V_8 . V_27 = V_36 -> V_6 [ 0 ] . V_42 ;
V_8 . V_28 = V_36 -> V_6 [ 0 ] . V_43 ;
return F_6 ( V_10 , & V_8 , F_7 ( F_4 ( V_4 ) ) ) ;
}
static int F_15 ( const struct V_29 * V_4 )
{
const struct V_35 * V_36 = V_4 -> V_7 ;
if ( ! ( V_36 -> V_6 [ 0 ] . V_25 & V_26 ) ) {
F_16 ( L_1 ) ;
return - V_30 ;
}
if ( V_36 -> V_44 != 1 ) {
F_16 ( L_2 , V_36 -> V_44 ) ;
return - V_30 ;
}
return F_9 ( V_4 -> V_31 , V_4 -> V_32 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( V_45 , F_3 ( V_45 ) ) ;
}
static void F_19 ( void )
{
F_20 ( V_45 , F_3 ( V_45 ) ) ;
}
