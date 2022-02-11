static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = 0 , V_7 = 0 ;
struct V_8 V_9 ;
unsigned int V_10 ;
if ( V_4 -> V_11 > 64 || V_4 -> V_12 > 64 )
return - V_13 ;
F_2 ( & V_9 , & V_4 -> V_14 . V_15 , V_4 -> V_11 ) ;
if ( ! F_3 ( & V_9 , & V_4 -> V_14 . V_15 ) )
return - V_13 ;
F_2 ( & V_9 , & V_4 -> V_16 . V_15 , V_4 -> V_12 ) ;
if ( ! F_3 ( & V_9 , & V_4 -> V_16 . V_15 ) )
return - V_13 ;
for ( V_10 = 0 ; V_10 < F_4 ( V_4 -> V_14 . V_15 . V_17 ) ; V_10 ++ ) {
V_6 = F_5 ( V_6 ,
( V_18 T_1 ) V_4 -> V_14 . V_15 . V_17 [ V_10 ] ) ;
V_7 = F_5 ( V_7 ,
( V_18 T_1 ) V_4 -> V_16 . V_15 . V_17 [ V_10 ] ) ;
}
V_4 -> V_19 = ~ F_6 ( F_7 ( V_6 , V_7 ) ) ;
return 0 ;
}
static bool F_8 ( const struct V_3 * V_4 ,
struct V_8 * V_20 )
{
unsigned int V_21 ;
unsigned int V_10 , V_22 ;
T_2 V_23 ;
T_3 V_24 ;
V_21 = F_9 ( V_4 -> V_11 , V_4 -> V_12 ) ;
for ( V_10 = 0 ; V_10 < V_21 ; V_10 += 32 ) {
if ( V_21 - V_10 >= 32 )
V_23 = 0 ;
else
V_23 = F_10 ( ~ ( ( 1 << ( V_21 - V_10 ) ) - 1 ) ) ;
V_22 = V_10 / 32 ;
V_20 -> V_25 [ V_22 ] &= V_23 ;
V_20 -> V_25 [ V_22 ] |= ~ V_23 & V_4 -> V_16 . V_15 . V_25 [ V_22 ] ;
}
if ( V_21 <= 48 )
V_22 = 3 ;
else {
for ( V_22 = 4 ; V_22 < F_4 ( V_20 -> V_17 ) ; V_22 ++ ) {
if ( ( V_18 T_3 ) V_20 -> V_17 [ V_22 ] !=
V_26 )
break;
}
if ( V_22 == F_4 ( V_20 -> V_17 ) )
return false ;
}
V_24 = ~ F_6 ( F_5 ( F_11 ( ( V_18 T_3 ) V_20 -> V_17 [ V_22 ] ) ,
F_11 ( V_4 -> V_19 ) ) ) ;
if ( V_24 == V_26 )
V_24 = 0 ;
* ( V_18 T_3 * ) & V_20 -> V_17 [ V_22 ] = V_24 ;
return true ;
}
static unsigned int
F_12 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_8 ( V_4 , & F_13 ( V_28 ) -> V_30 ) ) {
F_14 ( V_28 , V_31 , V_32 ,
F_15 ( struct V_33 , V_30 ) ) ;
return V_34 ;
}
return V_35 ;
}
static unsigned int
F_16 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_8 ( V_4 , & F_13 ( V_28 ) -> V_36 ) ) {
F_14 ( V_28 , V_31 , V_32 ,
F_15 ( struct V_33 , V_36 ) ) ;
return V_34 ;
}
return V_35 ;
}
static int T_4 F_17 ( void )
{
return F_18 ( V_37 ,
F_4 ( V_37 ) ) ;
}
static void T_5 F_19 ( void )
{
F_20 ( V_37 ,
F_4 ( V_37 ) ) ;
}
