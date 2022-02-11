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
static void F_5 ( struct V_3 * V_4 )
{
unsigned long V_9 = V_10 + F_6 ( 1000 ) ;
while ( ( F_7 ( V_4 -> V_11 + V_12 ) & 0x02fff000 ) != 0x02fff000 ) {
if ( F_8 ( V_10 , V_9 ) ) {
F_9 ( V_4 -> V_13 ,
L_1 ) ;
break;
}
F_10 () ;
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
V_4 -> V_6 -- ;
if ( ! V_4 -> V_6 ) {
F_5 ( V_4 ) ;
F_12 ( V_4 -> V_7 , V_8 ) ;
}
if ( V_4 -> V_6 < 0 )
V_4 -> V_6 = 0 ;
F_4 ( & V_4 -> V_5 ) ;
}
void F_13 ( struct V_1 * V_2 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 ;
F_2 ( & V_4 -> V_5 ) ;
V_15 = F_7 ( V_4 -> V_11 + V_16 ) ;
if ( ( V_2 -> V_17 * 64 * 4 ) / V_14 > V_2 -> V_18 -> V_19 )
V_15 |= 1 << V_2 -> V_18 -> V_20 ;
else
V_15 &= ~ ( 1 << V_2 -> V_18 -> V_20 ) ;
F_14 ( V_15 , V_4 -> V_11 + V_16 ) ;
F_4 ( & V_4 -> V_5 ) ;
}
struct V_1 * F_15 ( struct V_21 * V_7 , int V_22 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
if ( V_26 [ V_24 ] . V_22 == V_22 )
return & V_4 -> V_27 [ V_24 ] ;
return F_16 ( - V_28 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
}
int F_18 ( struct V_21 * V_7 , struct V_29 * V_13 , unsigned long V_11 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 ;
int V_24 ;
V_4 = F_19 ( V_13 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
V_4 -> V_11 = F_20 ( V_13 , V_11 , V_34 ) ;
if ( ! V_4 -> V_11 )
return - V_33 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_7 = V_7 ;
F_21 ( & V_4 -> V_5 ) ;
V_7 -> V_23 = V_4 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_4 -> V_27 [ V_24 ] . V_4 = V_4 ;
V_4 -> V_27 [ V_24 ] . V_7 = V_7 ;
V_4 -> V_27 [ V_24 ] . V_18 = & V_26 [ V_24 ] ;
if ( V_26 [ V_24 ] . V_22 == V_35 ||
V_26 [ V_24 ] . V_22 == V_36 ||
V_26 [ V_24 ] . V_22 == V_37 )
V_4 -> V_27 [ V_24 ] . V_17 = 2 ;
}
F_14 ( 0x00000050 , V_4 -> V_11 + V_38 ) ;
F_14 ( 0x00005654 , V_4 -> V_11 + V_39 ) ;
F_14 ( 0x202020f6 , V_4 -> V_11 + V_40 ) ;
F_14 ( 0x2020f6f6 , V_4 -> V_11 + V_41 ) ;
F_14 ( 0x00000003 , V_4 -> V_11 + V_16 ) ;
return 0 ;
}
void F_22 ( struct V_21 * V_7 )
{
}
