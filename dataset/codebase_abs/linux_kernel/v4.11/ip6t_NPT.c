static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 V_7 ;
T_1 V_8 , V_9 ;
if ( V_4 -> V_10 > 64 || V_4 -> V_11 > 64 )
return - V_12 ;
F_2 ( & V_7 , & V_4 -> V_13 . V_14 , V_4 -> V_10 ) ;
if ( ! F_3 ( & V_7 , & V_4 -> V_13 . V_14 ) )
return - V_12 ;
F_2 ( & V_7 , & V_4 -> V_15 . V_14 , V_4 -> V_11 ) ;
if ( ! F_3 ( & V_7 , & V_4 -> V_15 . V_14 ) )
return - V_12 ;
V_8 = F_4 ( & V_4 -> V_13 . V_14 , sizeof( V_4 -> V_13 . V_14 ) , 0 ) ;
V_9 = F_4 ( & V_4 -> V_15 . V_14 , sizeof( V_4 -> V_15 . V_14 ) , 0 ) ;
V_4 -> V_16 = ~ F_5 ( F_6 ( V_8 , V_9 ) ) ;
return 0 ;
}
static bool F_7 ( const struct V_3 * V_4 ,
struct V_6 * V_17 )
{
unsigned int V_18 ;
unsigned int V_19 , V_20 ;
T_2 V_21 ;
T_3 V_22 ;
V_18 = F_8 ( V_4 -> V_10 , V_4 -> V_11 ) ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 += 32 ) {
if ( V_18 - V_19 >= 32 )
V_21 = 0 ;
else
V_21 = F_9 ( ( 1 << ( V_19 - V_18 + 32 ) ) - 1 ) ;
V_20 = V_19 / 32 ;
V_17 -> V_23 [ V_20 ] &= V_21 ;
V_17 -> V_23 [ V_20 ] |= ~ V_21 & V_4 -> V_15 . V_14 . V_23 [ V_20 ] ;
}
if ( V_18 <= 48 )
V_20 = 3 ;
else {
for ( V_20 = 4 ; V_20 < F_10 ( V_17 -> V_24 ) ; V_20 ++ ) {
if ( ( V_25 T_3 ) V_17 -> V_24 [ V_20 ] !=
V_26 )
break;
}
if ( V_20 == F_10 ( V_17 -> V_24 ) )
return false ;
}
V_22 = ~ F_5 ( F_11 ( F_12 ( ( V_25 T_3 ) V_17 -> V_24 [ V_20 ] ) ,
F_12 ( V_4 -> V_16 ) ) ) ;
if ( V_22 == V_26 )
V_22 = 0 ;
* ( V_25 T_3 * ) & V_17 -> V_24 [ V_20 ] = V_22 ;
return true ;
}
static unsigned int
F_13 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_7 ( V_4 , & F_14 ( V_28 ) -> V_30 ) ) {
F_15 ( V_28 , V_31 , V_32 ,
F_16 ( struct V_33 , V_30 ) ) ;
return V_34 ;
}
return V_35 ;
}
static unsigned int
F_17 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_7 ( V_4 , & F_14 ( V_28 ) -> V_36 ) ) {
F_15 ( V_28 , V_31 , V_32 ,
F_16 ( struct V_33 , V_36 ) ) ;
return V_34 ;
}
return V_35 ;
}
static int T_4 F_18 ( void )
{
return F_19 ( V_37 ,
F_10 ( V_37 ) ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( V_37 ,
F_10 ( V_37 ) ) ;
}
