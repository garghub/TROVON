static void F_1 ( void )
{
unsigned int V_1 ;
T_1 V_2 [ 6 ] ;
V_2 [ 0 ] = V_3 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_4 ) ; V_1 ++ )
V_2 [ V_1 + 1 ] = V_4 [ V_1 ] ;
if ( F_3 ( V_5 , V_2 , 6 ) != 6 )
F_4 ( & V_5 -> V_6 , L_1 ) ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 =
(struct V_11 * ) V_8 -> V_13 ;
unsigned int V_14 = V_12 -> V_14 ;
unsigned int V_15 = V_12 -> V_15 ;
unsigned int V_16 = V_12 -> V_17 ;
unsigned int V_18 = V_12 -> V_18 ;
V_10 -> V_19 . integer . V_19 [ 0 ] = ( V_4 [ V_14 ] >> V_15 ) & V_16 ;
if ( V_18 )
V_10 -> V_19 . integer . V_19 [ 0 ] =
V_16 - V_10 -> V_19 . integer . V_19 [ 0 ] ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 =
(struct V_11 * ) V_8 -> V_13 ;
unsigned int V_14 = V_12 -> V_14 ;
unsigned int V_15 = V_12 -> V_15 ;
unsigned int V_16 = V_12 -> V_17 ;
unsigned int V_18 = V_12 -> V_18 ;
unsigned int V_20 = ( V_10 -> V_19 . integer . V_19 [ 0 ] & V_16 ) ;
if ( V_18 )
V_20 = V_16 - V_20 ;
if ( ( ( V_4 [ V_14 ] >> V_15 ) & V_16 ) == V_20 )
return 0 ;
V_4 [ V_14 ] &= ~ ( V_16 << V_15 ) ;
V_4 [ V_14 ] |= V_20 << V_15 ;
F_1 () ;
return 1 ;
}
static int F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 =
(struct V_11 * ) V_8 -> V_13 ;
unsigned int V_14 = V_12 -> V_14 ;
unsigned int V_21 = V_12 -> V_22 ;
unsigned int V_15 = V_12 -> V_15 ;
unsigned int V_16 = V_12 -> V_17 ;
V_10 -> V_19 . integer . V_19 [ 0 ] = ( V_4 [ V_14 ] >> V_15 ) & V_16 ;
V_10 -> V_19 . integer . V_19 [ 1 ] = ( V_4 [ V_21 ] >> V_15 ) & V_16 ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 =
(struct V_11 * ) V_8 -> V_13 ;
unsigned int V_14 = V_12 -> V_14 ;
unsigned int V_21 = V_12 -> V_22 ;
unsigned int V_15 = V_12 -> V_15 ;
unsigned int V_16 = V_12 -> V_17 ;
unsigned int V_20 = ( V_10 -> V_19 . integer . V_19 [ 0 ] & V_16 ) ;
unsigned int V_23 = ( V_10 -> V_19 . integer . V_19 [ 1 ] & V_16 ) ;
unsigned int V_24 = 0 ;
if ( ( ( V_4 [ V_14 ] >> V_15 ) & V_16 ) != V_20 )
V_24 = 1 ;
if ( ( ( V_4 [ V_21 ] >> V_15 ) & V_16 ) != V_23 )
V_24 = 1 ;
if ( V_24 ) {
V_4 [ V_14 ] &= ~ ( V_16 << V_15 ) ;
V_4 [ V_14 ] |= V_20 << V_15 ;
V_4 [ V_21 ] &= ~ ( V_16 << V_15 ) ;
V_4 [ V_21 ] |= V_23 << V_15 ;
F_1 () ;
}
return V_24 ;
}
static int F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_1 V_19 = V_4 [ V_25 ] & V_26 ;
if ( V_19 )
V_19 -= 1 ;
V_10 -> V_19 . integer . V_19 [ 0 ] = V_19 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_1 V_19 = V_10 -> V_19 . integer . V_19 [ 0 ] ;
V_19 += 1 ;
if ( ( V_4 [ V_25 ] & V_26 ) == V_19 )
return 0 ;
V_4 [ V_25 ] &= ~ V_26 ;
V_4 [ V_25 ] |= V_19 ;
F_1 () ;
return 1 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_1 V_19 = ( V_4 [ V_25 ] & V_27 ) ;
V_19 = V_19 >> V_28 ;
V_10 -> V_19 . integer . V_19 [ 0 ] = V_19 ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_1 V_19 = V_10 -> V_19 . integer . V_19 [ 0 ] ;
V_19 = V_19 << V_28 ;
if ( ( V_4 [ V_25 ] & V_27 ) == V_19 )
return 0 ;
V_4 [ V_25 ] &= ~ V_27 ;
V_4 [ V_25 ] |= V_19 ;
F_1 () ;
return 1 ;
}
int F_13 ( struct V_29 * V_30 )
{
return F_14 ( V_30 , V_31 ,
F_2 ( V_31 ) ) ;
}
static int T_2 F_15 ( struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
V_5 = V_33 ;
F_1 () ;
return 0 ;
}
static T_3 int F_16 ( struct V_32 * V_33 )
{
V_5 = NULL ;
return 0 ;
}
static int T_4 F_17 ( void )
{
return F_18 ( & V_36 ) ;
}
static void T_5 F_19 ( void )
{
F_20 ( & V_36 ) ;
}
