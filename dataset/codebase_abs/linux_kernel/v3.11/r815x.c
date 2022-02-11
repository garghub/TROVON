static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
T_2 V_5 = V_3 & 2 ;
T_3 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_3 &= ~ 3 ;
V_4 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_9 , V_10 ,
V_3 , V_11 , V_6 , sizeof( * V_6 ) , 500 ) ;
if ( V_4 < 0 )
goto V_12;
V_4 = F_5 ( * V_6 ) ;
V_4 >>= ( V_5 * 8 ) ;
V_4 &= 0xffff ;
V_12:
F_6 ( V_6 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_4 V_13 )
{
T_3 * V_6 ;
T_4 V_14 = 0xffff ;
T_1 V_15 = V_16 ;
T_2 V_5 = V_3 & 2 ;
int V_4 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_13 &= V_14 ;
if ( V_5 ) {
V_15 <<= V_5 ;
V_14 <<= ( V_5 * 8 ) ;
V_13 <<= ( V_5 * 8 ) ;
V_3 &= ~ 3 ;
}
V_4 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_9 , V_10 ,
V_3 , V_11 , V_6 , sizeof( * V_6 ) , 500 ) ;
if ( V_4 < 0 )
goto V_17;
V_13 |= F_5 ( * V_6 ) & ~ V_14 ;
* V_6 = F_8 ( V_13 ) ;
V_4 = F_3 ( V_2 , F_9 ( V_2 , 0 ) ,
V_18 , V_19 ,
V_3 , V_11 | V_15 , V_6 , sizeof( * V_6 ) ,
500 ) ;
V_17:
F_6 ( V_6 ) ;
return V_4 ;
}
static int F_10 ( struct V_20 * V_21 , T_1 V_22 )
{
T_1 V_23 , V_24 ;
int V_4 ;
V_23 = V_22 & 0xf000 ;
V_4 = F_7 ( V_21 -> V_2 , V_25 , V_23 ) ;
if ( V_4 < 0 )
goto V_26;
V_24 = ( V_22 & 0x0fff ) | 0xb000 ;
V_4 = F_1 ( V_21 -> V_2 , V_24 ) ;
V_26:
return V_4 ;
}
static int F_11 ( struct V_20 * V_21 , T_1 V_22 , T_1 V_13 )
{
T_1 V_23 , V_24 ;
int V_4 ;
V_23 = V_22 & 0xf000 ;
V_4 = F_7 ( V_21 -> V_2 , V_25 , V_23 ) ;
if ( V_4 < 0 )
goto V_27;
V_24 = ( V_22 & 0x0fff ) | 0xb000 ;
V_4 = F_7 ( V_21 -> V_2 , V_24 , V_13 ) ;
V_27:
return V_4 ;
}
static int F_12 ( struct V_28 * V_29 , int V_30 , int V_31 )
{
struct V_20 * V_21 = F_13 ( V_29 ) ;
int V_4 ;
if ( V_30 != V_32 )
return - V_33 ;
if ( F_14 ( V_21 -> V_34 ) < 0 )
return - V_35 ;
V_4 = F_10 ( V_21 , V_36 + V_31 * 2 ) ;
F_15 ( V_21 -> V_34 ) ;
return V_4 ;
}
static
void F_16 ( struct V_28 * V_29 , int V_30 , int V_31 , int V_37 )
{
struct V_20 * V_21 = F_13 ( V_29 ) ;
if ( V_30 != V_32 )
return;
if ( F_14 ( V_21 -> V_34 ) < 0 )
return;
F_11 ( V_21 , V_36 + V_31 * 2 , V_37 ) ;
F_15 ( V_21 -> V_34 ) ;
}
static int F_17 ( struct V_20 * V_21 , struct V_38 * V_34 )
{
int V_39 ;
V_39 = F_18 ( V_21 , V_34 ) ;
if ( V_39 < 0 )
return V_39 ;
V_21 -> V_40 . V_21 = V_21 -> V_41 ;
V_21 -> V_40 . V_42 = F_12 ;
V_21 -> V_40 . V_43 = F_16 ;
V_21 -> V_40 . V_44 = 0x3f ;
V_21 -> V_40 . V_45 = 0x1f ;
V_21 -> V_40 . V_30 = V_32 ;
V_21 -> V_40 . V_46 = 1 ;
return V_39 ;
}
static int F_19 ( struct V_20 * V_21 , struct V_38 * V_34 )
{
int V_39 ;
V_39 = F_18 ( V_21 , V_34 ) ;
if ( V_39 < 0 )
return V_39 ;
V_21 -> V_40 . V_21 = V_21 -> V_41 ;
V_21 -> V_40 . V_42 = F_12 ;
V_21 -> V_40 . V_43 = F_16 ;
V_21 -> V_40 . V_44 = 0x3f ;
V_21 -> V_40 . V_45 = 0x1f ;
V_21 -> V_40 . V_30 = V_32 ;
V_21 -> V_40 . V_46 = 0 ;
return V_39 ;
}
