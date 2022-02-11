int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
if ( ! V_4 -> V_6 )
F_3 ( V_4 -> V_7 , V_8 ) ;
V_4 -> V_6 ++ ;
F_4 ( & V_4 -> V_5 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
V_4 -> V_6 -- ;
if ( ! V_4 -> V_6 )
F_6 ( V_4 -> V_7 , V_8 ) ;
if ( V_4 -> V_6 < 0 )
V_4 -> V_6 = 0 ;
F_4 ( & V_4 -> V_5 ) ;
}
void F_7 ( struct V_1 * V_2 , int V_9 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_10 ;
F_2 ( & V_4 -> V_5 ) ;
V_10 = F_8 ( V_4 -> V_11 + V_12 ) ;
if ( ( V_2 -> V_13 * 64 * 4 ) / V_9 > V_2 -> V_14 -> V_15 )
V_10 |= 1 << V_2 -> V_14 -> V_16 ;
else
V_10 &= ~ ( 1 << V_2 -> V_14 -> V_16 ) ;
F_9 ( V_10 , V_4 -> V_11 + V_12 ) ;
F_4 ( & V_4 -> V_5 ) ;
}
struct V_1 * F_10 ( struct V_17 * V_7 , int V_18 )
{
struct V_3 * V_4 = V_7 -> V_19 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
if ( V_22 [ V_20 ] . V_18 == V_18 )
return & V_4 -> V_23 [ V_20 ] ;
return F_11 ( - V_24 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
}
int F_13 ( struct V_17 * V_7 , struct V_25 * V_26 , unsigned long V_11 ,
struct V_27 * V_28 )
{
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_14 ( V_26 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_11 = F_15 ( V_26 , V_11 , V_31 ) ;
if ( ! V_4 -> V_11 )
return - V_30 ;
V_4 -> V_26 = V_26 ;
V_4 -> V_7 = V_7 ;
F_16 ( & V_4 -> V_5 ) ;
V_7 -> V_19 = V_4 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_4 -> V_23 [ V_20 ] . V_4 = V_4 ;
V_4 -> V_23 [ V_20 ] . V_7 = V_7 ;
V_4 -> V_23 [ V_20 ] . V_14 = & V_22 [ V_20 ] ;
if ( V_22 [ V_20 ] . V_18 == V_32 ||
V_22 [ V_20 ] . V_18 == V_33 ||
V_22 [ V_20 ] . V_18 == V_34 )
V_4 -> V_23 [ V_20 ] . V_13 = 2 ;
}
F_9 ( 0x00000050 , V_4 -> V_11 + V_35 ) ;
F_9 ( 0x00005654 , V_4 -> V_11 + V_36 ) ;
F_9 ( 0x202020f6 , V_4 -> V_11 + V_37 ) ;
F_9 ( 0x2020f6f6 , V_4 -> V_11 + V_38 ) ;
F_9 ( 0x00000003 , V_4 -> V_11 + V_12 ) ;
return 0 ;
}
void F_17 ( struct V_17 * V_7 )
{
}
