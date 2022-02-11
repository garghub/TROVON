static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 -> V_2 . V_7 ) ;
struct V_8 V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 = 0 ;
V_11 = F_5 ( V_4 -> V_14 * sizeof( struct V_10 ) ,
V_15 ) ;
if ( ! V_11 )
return - V_16 ;
F_6 ( & V_9 ) ;
for ( V_12 = V_4 -> V_14 - 1 ; V_12 >= 0 ; V_12 -- ) {
V_11 [ V_12 ] . V_17 = V_4 -> V_18 + V_12 ;
V_11 [ V_12 ] . V_19 = sizeof( V_20 ) ;
F_7 ( V_11 + V_12 , & V_9 ) ;
}
V_13 = F_8 ( V_6 , & V_9 ) ;
F_9 ( V_11 ) ;
return V_13 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_21 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_20 V_22 = V_21 / 8 ;
V_20 V_23 = V_21 % 8 ;
int V_13 ;
F_11 ( & V_4 -> V_24 ) ;
V_13 = ( V_4 -> V_18 [ V_22 ] >> V_23 ) & 0x1 ;
F_12 ( & V_4 -> V_24 ) ;
return V_13 ;
}
static void F_13 ( struct V_2 * V_3 ,
unsigned V_21 , int V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_20 V_22 = V_21 / 8 ;
V_20 V_23 = V_21 % 8 ;
F_11 ( & V_4 -> V_24 ) ;
if ( V_25 )
V_4 -> V_18 [ V_22 ] |= ( 1 << V_23 ) ;
else
V_4 -> V_18 [ V_22 ] &= ~ ( 1 << V_23 ) ;
F_3 ( V_4 ) ;
F_12 ( & V_4 -> V_24 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned V_21 , int V_25 )
{
F_13 ( V_3 , V_21 , V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
int V_13 ;
V_6 -> V_26 = 8 ;
V_13 = F_16 ( V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 = F_17 ( & V_6 -> V_7 , sizeof( * V_4 ) , V_15 ) ;
if ( ! V_4 )
return - V_16 ;
F_18 ( V_6 , V_4 ) ;
V_4 -> V_2 . V_27 = V_6 -> V_28 ;
V_4 -> V_2 . V_29 = F_14 ;
V_4 -> V_2 . V_30 = F_10 ;
V_4 -> V_2 . V_31 = F_13 ;
V_4 -> V_2 . V_32 = - 1 ;
if ( F_19 ( V_6 -> V_7 . V_33 , L_1 ,
& V_4 -> V_14 ) ) {
F_20 ( & V_6 -> V_7 ,
L_2 ) ;
return - V_34 ;
}
V_4 -> V_2 . V_35 = V_36 * V_4 -> V_14 ;
V_4 -> V_18 = F_17 ( & V_6 -> V_7 , V_4 -> V_14 , V_15 ) ;
if ( ! V_4 -> V_18 )
return - V_16 ;
V_4 -> V_2 . V_37 = true ;
V_4 -> V_2 . V_7 = & V_6 -> V_7 ;
V_4 -> V_2 . V_38 = V_39 ;
F_21 ( & V_4 -> V_24 ) ;
V_13 = F_3 ( V_4 ) ;
if ( V_13 ) {
F_20 ( & V_6 -> V_7 , L_3 , V_13 ) ;
goto V_40;
}
V_13 = F_22 ( & V_4 -> V_2 ) ;
if ( ! V_13 )
return 0 ;
V_40:
F_23 ( & V_4 -> V_24 ) ;
return V_13 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = F_25 ( V_6 ) ;
F_26 ( & V_4 -> V_2 ) ;
F_23 ( & V_4 -> V_24 ) ;
return 0 ;
}
