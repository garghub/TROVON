static T_1 F_1 ( T_1 V_1 )
{
return ( V_2 T_1 ) ( 0xffff - ( V_2 V_3 ) V_1 ) ;
}
static T_1 F_2 ( T_1 V_1 , T_1 V_4 )
{
V_3 V_5 ;
V_5 = ( V_2 V_3 ) V_1 + ( V_2 V_3 ) V_4 ;
V_5 += ( V_2 V_3 ) V_1 < ( V_2 V_3 ) V_4 ;
return ( V_2 T_1 ) V_5 ;
}
static T_1 F_3 ( T_1 V_1 , T_1 V_4 )
{
return F_2 ( V_1 , F_1 ( V_4 ) ) ;
}
static int F_4 ( const struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = 0 , V_12 = 0 ;
unsigned int V_13 ;
if ( V_9 -> V_14 > 64 || V_9 -> V_15 > 64 )
return - V_16 ;
for ( V_13 = 0 ; V_13 < F_5 ( V_9 -> V_17 . V_18 . V_19 ) ; V_13 ++ ) {
V_11 = F_2 ( V_11 ,
( V_2 T_1 ) V_9 -> V_17 . V_18 . V_19 [ V_13 ] ) ;
V_12 = F_2 ( V_12 ,
( V_2 T_1 ) V_9 -> V_20 . V_18 . V_19 [ V_13 ] ) ;
}
V_9 -> V_21 = F_3 ( V_11 , V_12 ) ;
return 0 ;
}
static bool F_6 ( const struct V_8 * V_9 ,
struct V_22 * V_23 )
{
unsigned int V_24 ;
unsigned int V_13 , V_25 ;
T_2 V_26 ;
T_1 V_5 ;
V_24 = F_7 ( V_9 -> V_14 , V_9 -> V_15 ) ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 += 32 ) {
if ( V_24 - V_13 >= 32 )
V_26 = 0 ;
else
V_26 = F_8 ( ~ ( ( 1 << ( V_24 - V_13 ) ) - 1 ) ) ;
V_25 = V_13 / 32 ;
V_23 -> V_27 [ V_25 ] &= V_26 ;
V_23 -> V_27 [ V_25 ] |= V_9 -> V_20 . V_18 . V_27 [ V_25 ] ;
}
if ( V_24 <= 48 )
V_25 = 3 ;
else {
for ( V_25 = 4 ; V_25 < F_5 ( V_23 -> V_19 ) ; V_25 ++ ) {
if ( ( V_2 T_1 ) V_23 -> V_19 [ V_25 ] !=
V_28 )
break;
}
if ( V_25 == F_5 ( V_23 -> V_19 ) )
return false ;
}
V_5 = F_2 ( ( V_2 T_1 ) V_23 -> V_19 [ V_25 ] ,
V_9 -> V_21 ) ;
if ( V_5 == V_28 )
V_5 = 0 ;
* ( V_2 T_1 * ) & V_23 -> V_19 [ V_25 ] = V_5 ;
return true ;
}
static unsigned int
F_9 ( struct V_29 * V_30 , const struct V_31 * V_7 )
{
const struct V_8 * V_9 = V_7 -> V_10 ;
if ( ! F_6 ( V_9 , & F_10 ( V_30 ) -> V_32 ) ) {
F_11 ( V_30 , V_33 , V_34 ,
F_12 ( struct V_35 , V_32 ) ) ;
return V_36 ;
}
return V_37 ;
}
static unsigned int
F_13 ( struct V_29 * V_30 , const struct V_31 * V_7 )
{
const struct V_8 * V_9 = V_7 -> V_10 ;
if ( ! F_6 ( V_9 , & F_10 ( V_30 ) -> V_38 ) ) {
F_11 ( V_30 , V_33 , V_34 ,
F_12 ( struct V_35 , V_38 ) ) ;
return V_36 ;
}
return V_37 ;
}
static int T_3 F_14 ( void )
{
return F_15 ( V_39 ,
F_5 ( V_39 ) ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( V_39 ,
F_5 ( V_39 ) ) ;
}
