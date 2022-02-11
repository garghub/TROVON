static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = F_2 ( V_6 , V_3 | V_9 ) ;
if ( V_8 < 0 )
return - V_10 ;
* V_4 = ( T_1 ) V_8 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_11 )
{
T_1 V_12 [ 2 ] = { V_3 , V_11 } ;
struct V_5 * V_6 = V_2 -> V_7 ;
return F_4 ( V_6 , V_12 , sizeof( V_12 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_8 ;
V_8 = V_2 -> V_13 ( V_2 , V_14 , & V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
V_3 |= V_15 | V_16 | V_17 | V_18 ;
return V_2 -> V_19 ( V_2 , V_14 , V_3 ) ;
}
static int T_2 F_6 ( struct V_5 * V_6 )
{
int V_8 ;
V_6 -> V_20 = 8 ;
V_6 -> V_21 = V_22 ;
V_8 = F_7 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
V_23 . V_7 = V_6 ;
V_23 . V_24 = F_5 ;
V_23 . V_13 = F_1 ;
V_23 . V_19 = F_3 ;
V_23 . V_25 = V_6 -> V_25 ;
V_23 . V_26 = V_27 ;
V_23 . V_28 = V_6 -> V_29 . V_30 ;
#ifdef F_8
if ( F_9 ( V_31 , & V_6 -> V_29 ) ) {
V_23 . V_32 = V_6 -> V_29 . V_32 ;
V_8 = F_10 ( & V_23 ) ;
if ( V_8 )
return V_8 ;
}
#endif
F_11 ( V_6 , & V_23 ) ;
return F_12 ( & V_23 ) ;
}
static int T_3 F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
return F_17 ( & V_23 ) ;
}
static int F_18 ( struct V_33 * V_29 )
{
struct V_5 * V_6 = F_19 ( V_29 ) ;
struct V_1 * V_2 = F_14 ( V_6 ) ;
if ( ! V_2 -> V_28 || ! V_2 -> V_28 -> V_34 )
F_16 ( & V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_33 * V_29 )
{
struct V_5 * V_6 = F_19 ( V_29 ) ;
struct V_1 * V_2 = F_14 ( V_6 ) ;
if ( ! V_2 -> V_28 || ! V_2 -> V_28 -> V_34 )
F_21 ( V_2 ) ;
return 0 ;
}
