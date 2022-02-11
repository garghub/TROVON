static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
V_2 -> V_5 . V_6 [ V_7 ] = ( F_2 () & ~ V_8 )
| ( V_2 -> V_9 & V_8 ) ;
}
static bool F_3 ( struct V_1 * V_2 ,
const struct V_10 * V_11 ,
const struct V_3 * V_4 )
{
if ( V_11 -> V_12 )
return F_4 ( V_2 , V_11 ) ;
* F_5 ( V_2 , V_11 -> V_13 ) = V_2 -> V_5 . V_6 [ V_14 ] ;
return true ;
}
static bool F_6 ( struct V_1 * V_2 ,
const struct V_10 * V_11 ,
const struct V_3 * V_4 )
{
if ( V_11 -> V_12 )
return F_7 ( V_2 , V_11 ) ;
return F_8 ( V_2 , V_11 ) ;
}
static bool F_9 ( struct V_1 * V_2 ,
const struct V_10 * V_11 ,
const struct V_3 * V_4 )
{
if ( V_11 -> V_12 )
return F_4 ( V_2 , V_11 ) ;
* F_5 ( V_2 , V_11 -> V_13 ) = V_2 -> V_5 . V_6 [ V_15 ] ;
return true ;
}
static void F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_1 V_16 , V_17 ;
asm volatile("mrc p15, 1, %0, c9, c0, 2\n" : "=r" (l2ctlr));
V_16 &= ~ ( 3 << 24 ) ;
V_17 = F_11 ( & V_2 -> V_18 -> V_19 ) - 1 ;
V_16 |= ( V_17 & 3 ) << 24 ;
V_2 -> V_5 . V_6 [ V_15 ] = V_16 ;
}
static void F_12 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_1 V_20 ;
asm volatile("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
if ( F_11 ( & V_2 -> V_18 -> V_19 ) > 1 )
V_20 |= 1U << 6 ;
else
V_20 &= ~ ( 1U << 6 ) ;
V_2 -> V_5 . V_6 [ V_14 ] = V_20 ;
}
static bool F_13 ( struct V_1 * V_2 ,
const struct V_10 * V_11 ,
const struct V_3 * V_4 )
{
if ( V_11 -> V_12 )
return F_4 ( V_2 , V_11 ) ;
* F_5 ( V_2 , V_11 -> V_13 ) = 0 ;
return true ;
}
static int T_2 F_14 ( void )
{
unsigned int V_21 ;
for ( V_21 = 1 ; V_21 < F_15 ( V_22 ) ; V_21 ++ )
F_16 ( F_17 ( & V_22 [ V_21 - 1 ] ,
& V_22 [ V_21 ] ) >= 0 ) ;
F_18 ( & V_23 ) ;
return 0 ;
}
