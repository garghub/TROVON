static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 = 0 ;
int V_7 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_7 = V_3 < 32 ? V_5 -> V_8 : V_5 -> V_9 ;
F_3 ( & V_5 -> V_10 ) ;
F_4 ( V_5 -> V_11 , V_7 ,
V_5 -> V_12 [ V_3 < 32 ? 0 : 1 ] ) ;
F_5 ( V_5 -> V_11 , V_7 , & V_6 ) ;
F_6 ( & V_5 -> V_10 ) ;
return ( 1 << ( V_3 & 0x1f ) ) & V_6 ? 1 : 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_6 )
{
struct V_4 * V_5 ;
int V_7 = ( V_3 < 32 ) ? 0 : 1 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_6 )
V_5 -> V_12 [ V_7 ] |= 1 << ( V_3 & 0x1f ) ;
else
V_5 -> V_12 [ V_7 ] &= ~ ( 1 << ( V_3 & 0x1f ) ) ;
F_4 ( V_5 -> V_11 ,
V_7 ? V_5 -> V_9 : V_5 -> V_8 ,
V_5 -> V_12 [ V_7 ] ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_6 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( & V_5 -> V_10 ) ;
F_7 ( V_2 , V_3 , V_6 ) ;
F_6 ( & V_5 -> V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 , int V_6 )
{
struct V_4 * V_5 ;
int V_13 ;
T_1 V_7 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( & V_5 -> V_10 ) ;
V_13 = F_5 ( V_5 -> V_11 , V_3 < 32 ?
V_5 -> V_14 : V_5 -> V_15 , & V_7 ) ;
if ( V_13 )
goto V_16;
V_7 |= 1 << ( V_3 & 0x1f ) ;
V_13 = F_4 ( V_5 -> V_11 , V_3 < 32 ?
V_5 -> V_14 : V_5 -> V_15 , V_7 ) ;
if ( V_13 )
goto V_16;
F_7 ( V_2 , V_3 , V_6 ) ;
V_16:
F_6 ( & V_5 -> V_10 ) ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_9 ( V_2 , V_3 , 1 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
int V_13 ;
struct V_19 * V_20 ;
struct V_4 * V_21 ;
struct V_22 * V_23 ;
V_23 = F_12 ( & V_18 -> V_24 ) ;
if ( ! V_23 ) {
F_13 ( & V_18 -> V_24 , L_1 ) ;
return - V_25 ;
}
V_21 = F_14 ( & V_18 -> V_24 , sizeof( struct V_4 ) ,
V_26 ) ;
if ( ! V_21 )
return - V_27 ;
V_20 = F_15 ( V_18 , V_28 , L_2 ) ;
if ( ! V_20 ) {
F_13 ( & V_18 -> V_24 , L_3 ) ;
return - V_25 ;
}
F_16 ( & V_21 -> V_10 ) ;
V_21 -> V_11 = V_23 -> V_11 ;
V_21 -> V_14 = V_20 -> V_29 ;
V_21 -> V_8 = V_20 -> V_29 + 0x4 ;
V_20 = F_15 ( V_18 , V_28 , L_4 ) ;
if ( ! V_20 ) {
F_13 ( & V_18 -> V_24 , L_5 ) ;
return - V_25 ;
}
V_21 -> V_15 = V_20 -> V_29 ;
V_21 -> V_9 = V_20 -> V_29 + 0x4 ;
V_21 -> V_2 . V_30 = L_6 ;
V_21 -> V_2 . V_31 = V_32 ;
V_21 -> V_2 . V_33 = F_10 ;
V_21 -> V_2 . V_34 = F_9 ;
V_21 -> V_2 . V_35 = F_1 ;
V_21 -> V_2 . V_36 = F_8 ;
V_21 -> V_2 . V_37 = 0 ;
V_21 -> V_2 . V_38 = V_23 -> V_39 ;
F_17 ( V_18 , V_21 ) ;
V_13 = F_5 ( V_21 -> V_11 ,
V_21 -> V_8 ,
& V_21 -> V_12 [ 0 ] ) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 ( V_21 -> V_11 ,
V_21 -> V_9 ,
& V_21 -> V_12 [ 1 ] ) ;
if ( V_13 )
return V_13 ;
F_18 ( & V_18 -> V_24 , L_7 ,
V_21 -> V_2 . V_38 ) ;
return F_19 ( & V_21 -> V_2 ) ;
}
static int F_20 ( struct V_17 * V_18 )
{
struct V_4 * V_21 = F_21 ( V_18 ) ;
F_22 ( & V_21 -> V_2 ) ;
return 0 ;
}
