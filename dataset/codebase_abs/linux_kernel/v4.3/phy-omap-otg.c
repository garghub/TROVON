static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 &= ~ V_7 ;
V_4 |= V_3 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_8 && V_2 -> V_9 )
F_1 ( V_2 , V_10 | V_11 ) ;
else if ( V_2 -> V_9 )
F_1 ( V_2 , V_12 ) ;
else if ( ! V_2 -> V_8 )
F_1 ( V_2 , V_10 | V_13 ) ;
}
static int F_5 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
struct V_1 * V_2 = F_6 ( V_15 , struct V_1 , V_18 ) ;
V_2 -> V_8 = V_16 ;
F_4 ( V_2 ) ;
return V_19 ;
}
static int F_7 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
struct V_1 * V_2 = F_6 ( V_15 , struct V_1 ,
V_20 ) ;
V_2 -> V_9 = V_16 ;
F_4 ( V_2 ) ;
return V_19 ;
}
static int F_8 ( struct V_21 * V_22 )
{
const struct V_23 * V_24 = V_22 -> V_25 . V_26 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
int V_29 ;
T_1 V_30 ;
if ( ! V_24 || ! V_24 -> V_28 )
return - V_31 ;
V_28 = F_9 ( V_24 -> V_28 ) ;
if ( ! V_28 )
return - V_32 ;
V_2 -> V_28 = V_28 ;
V_2 = F_10 ( & V_22 -> V_25 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_5 = F_11 ( & V_22 -> V_25 , & V_22 -> V_35 [ 0 ] ) ;
if ( F_12 ( V_2 -> V_5 ) )
return F_13 ( V_2 -> V_5 ) ;
V_2 -> V_18 . V_36 = F_5 ;
V_2 -> V_20 . V_36 = F_7 ;
V_29 = F_14 ( V_28 , V_37 , & V_2 -> V_18 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_14 ( V_28 , V_38 , & V_2 -> V_20 ) ;
if ( V_29 ) {
F_15 ( V_28 , V_37 ,
& V_2 -> V_18 ) ;
return V_29 ;
}
V_2 -> V_8 = F_16 ( V_28 , V_37 ) ;
V_2 -> V_9 = F_16 ( V_28 , V_38 ) ;
F_4 ( V_2 ) ;
V_30 = F_2 ( V_2 -> V_5 ) ;
F_17 ( & V_22 -> V_25 ,
L_1 ,
( V_30 >> 4 ) & 0xf , V_30 & 0xf , V_24 -> V_28 , V_2 -> V_8 ,
V_2 -> V_9 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_27 * V_39 = V_2 -> V_28 ;
F_15 ( V_39 , V_37 , & V_2 -> V_18 ) ;
F_15 ( V_39 , V_38 , & V_2 -> V_20 ) ;
return 0 ;
}
