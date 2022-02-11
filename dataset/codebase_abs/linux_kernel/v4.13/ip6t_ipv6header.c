static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_8 ;
int V_9 ;
T_1 V_10 ;
unsigned int V_11 ;
V_10 = F_2 ( V_2 ) -> V_10 ;
V_11 = sizeof( struct V_12 ) ;
V_9 = V_2 -> V_9 - V_11 ;
V_8 = 0 ;
while ( F_3 ( V_10 ) ) {
const struct V_13 * V_14 ;
struct V_13 V_15 ;
int V_16 ;
if ( V_10 == V_17 ) {
V_8 |= V_18 ;
break;
}
if ( V_9 < ( int ) sizeof( struct V_13 ) )
return false ;
if ( V_10 == V_19 ) {
V_8 |= V_20 ;
break;
}
V_14 = F_4 ( V_2 , V_11 , sizeof( V_15 ) , & V_15 ) ;
F_5 ( V_14 == NULL ) ;
if ( V_10 == V_21 )
V_16 = 8 ;
else if ( V_10 == V_22 )
V_16 = ( V_14 -> V_16 + 2 ) << 2 ;
else
V_16 = F_6 ( V_14 ) ;
switch ( V_10 ) {
case V_23 :
V_8 |= V_24 ;
break;
case V_25 :
V_8 |= V_26 ;
break;
case V_21 :
V_8 |= V_27 ;
break;
case V_22 :
V_8 |= V_28 ;
break;
case V_29 :
V_8 |= V_30 ;
break;
default:
return false ;
}
V_10 = V_14 -> V_10 ;
V_9 -= V_16 ;
V_11 += V_16 ;
if ( V_11 > V_2 -> V_9 )
break;
}
if ( V_10 != V_17 && V_10 != V_19 )
V_8 |= V_31 ;
if ( V_6 -> V_32 )
return ! ( ( V_8 ^ V_6 -> V_33 ^ V_6 -> V_34 )
& V_6 -> V_33 ) ;
else {
if ( V_6 -> V_34 )
return V_8 != V_6 -> V_33 ;
else
return V_8 == V_6 -> V_33 ;
}
}
static int F_7 ( const struct V_35 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( ! V_6 -> V_32 ) && V_6 -> V_34 != 0x00 &&
V_6 -> V_34 != 0xFF )
return - V_36 ;
return 0 ;
}
static int T_2 F_8 ( void )
{
return F_9 ( & V_37 ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_37 ) ;
}
