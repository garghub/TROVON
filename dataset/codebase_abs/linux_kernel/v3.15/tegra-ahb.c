static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , void * V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_9 * V_10 = V_8 ;
return ( V_2 -> V_7 -> V_11 == V_10 ) ? 1 : 0 ;
}
int F_7 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
T_1 V_12 ;
struct V_1 * V_2 ;
V_7 = F_8 ( & V_13 . V_14 , NULL , V_10 ,
F_5 ) ;
if ( ! V_7 )
return - V_15 ;
V_2 = F_6 ( V_7 ) ;
V_12 = F_1 ( V_2 , V_16 ) ;
V_12 |= V_17 ;
F_3 ( V_2 , V_12 , V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_18 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_19 ) ; V_18 ++ )
V_2 -> V_20 [ V_18 ] = F_1 ( V_2 , V_19 [ V_18 ] ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
int V_18 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_19 ) ; V_18 ++ )
F_3 ( V_2 , V_2 -> V_20 [ V_18 ] , V_19 [ V_18 ] ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_21 ) ;
V_12 |= V_22 | V_23 | V_24 ;
F_3 ( V_2 , V_12 , V_21 ) ;
V_12 = F_1 ( V_2 , V_25 ) ;
V_12 |= V_23 ;
F_3 ( V_2 , V_12 , V_25 ) ;
V_12 = F_1 ( V_2 , V_26 ) ;
V_12 |= V_23 ;
F_3 ( V_2 , V_12 , V_26 ) ;
V_12 = F_1 ( V_2 , V_27 ) ;
V_12 |= V_23 ;
F_3 ( V_2 , V_12 , V_27 ) ;
V_12 = F_1 ( V_2 , V_28 ) ;
V_12 |= V_29 |
V_30 |
V_31 |
F_13 ( 7 ) ;
F_3 ( V_2 , V_12 , V_28 ) ;
V_12 = F_1 ( V_2 , V_32 ) ;
V_12 &= ~ F_14 ( ~ 0 ) ;
V_12 |= V_33 |
V_34 |
F_15 ( 0xc ) |
F_16 ( 0x1000 ) ;
F_3 ( V_2 , V_12 , V_32 ) ;
V_12 = F_1 ( V_2 , V_35 ) ;
V_12 &= ~ F_14 ( ~ 0 ) ;
V_12 |= V_33 |
V_36 |
F_15 ( 0xc ) |
F_16 ( 0x1000 ) ;
F_3 ( V_2 , V_12 , V_35 ) ;
V_12 = F_1 ( V_2 , V_37 ) ;
V_12 &= ~ F_14 ( ~ 0 ) ;
V_12 |= V_33 |
V_38 |
F_15 ( 0xc ) |
F_16 ( 0x1000 ) ;
F_3 ( V_2 , V_12 , V_37 ) ;
V_12 = F_1 ( V_2 , V_39 ) ;
V_12 &= ~ F_14 ( ~ 0 ) ;
V_12 |= V_33 |
V_40 |
F_15 ( 0xc ) |
F_16 ( 0x1000 ) ;
F_3 ( V_2 , V_12 , V_39 ) ;
}
static int F_17 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_1 * V_2 ;
T_2 V_45 ;
V_45 = sizeof( * V_2 ) + sizeof( T_1 ) * F_10 ( V_19 ) ;
V_2 = F_18 ( & V_42 -> V_7 , V_45 , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_44 = F_19 ( V_42 , V_48 , 0 ) ;
V_2 -> V_4 = F_20 ( & V_42 -> V_7 , V_44 ) ;
if ( F_21 ( V_2 -> V_4 ) )
return F_22 ( V_2 -> V_4 ) ;
V_2 -> V_7 = & V_42 -> V_7 ;
F_23 ( V_42 , V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
