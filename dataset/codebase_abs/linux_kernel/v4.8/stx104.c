static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
if ( V_7 != V_10 )
return - V_11 ;
* V_5 = V_9 -> V_12 [ V_4 -> V_13 ] ;
return V_14 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int V_5 , int V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const unsigned V_15 = 2 * V_4 -> V_13 ;
if ( V_7 != V_10 )
return - V_11 ;
V_9 -> V_12 [ V_4 -> V_13 ] = V_5 ;
F_4 ( V_5 , V_9 -> V_16 + 4 + V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_17 * V_18 ,
unsigned int V_19 )
{
if ( V_19 < 4 )
return 1 ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 ,
unsigned int V_19 )
{
if ( V_19 >= 4 )
return - V_11 ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
unsigned int V_19 , int V_20 )
{
if ( V_19 < 4 )
return - V_11 ;
V_18 -> V_21 ( V_18 , V_19 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 , unsigned int V_19 )
{
struct V_22 * const V_23 = F_9 ( V_18 ) ;
if ( V_19 >= 4 )
return - V_11 ;
return ! ! ( F_10 ( V_23 -> V_16 ) & F_11 ( V_19 ) ) ;
}
static void F_12 ( struct V_17 * V_18 , unsigned int V_19 ,
int V_20 )
{
struct V_22 * const V_23 = F_9 ( V_18 ) ;
const unsigned int V_7 = F_11 ( V_19 ) >> 4 ;
unsigned long V_24 ;
if ( V_19 < 4 )
return;
F_13 ( & V_23 -> V_25 , V_24 ) ;
if ( V_20 )
V_23 -> V_26 |= V_7 ;
else
V_23 -> V_26 &= ~ V_7 ;
F_14 ( V_23 -> V_26 , V_23 -> V_16 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
}
static int F_16 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_22 * V_23 ;
struct V_30 * V_31 ;
int V_32 ;
V_2 = F_17 ( V_28 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_33 ;
V_23 = F_18 ( V_28 , sizeof( * V_23 ) , V_34 ) ;
if ( ! V_23 )
return - V_33 ;
V_31 = F_18 ( V_28 , sizeof( * V_31 ) , V_34 ) ;
if ( ! V_31 )
return - V_33 ;
if ( ! F_19 ( V_28 , V_16 [ V_29 ] , V_35 ,
F_20 ( V_28 ) ) ) {
F_21 ( V_28 , L_1 ,
V_16 [ V_29 ] , V_16 [ V_29 ] + V_35 ) ;
return - V_36 ;
}
V_2 -> V_37 = & V_38 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = F_20 ( V_28 ) ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_16 = V_16 [ V_29 ] ;
F_4 ( 0 , V_16 [ V_29 ] + 4 ) ;
F_4 ( 0 , V_16 [ V_29 ] + 6 ) ;
V_23 -> V_18 . V_46 = F_20 ( V_28 ) ;
V_23 -> V_18 . V_47 = V_28 ;
V_23 -> V_18 . V_48 = V_49 ;
V_23 -> V_18 . V_16 = - 1 ;
V_23 -> V_18 . V_50 = 8 ;
V_23 -> V_18 . V_51 = F_5 ;
V_23 -> V_18 . V_52 = F_6 ;
V_23 -> V_18 . V_53 = F_7 ;
V_23 -> V_18 . V_54 = F_8 ;
V_23 -> V_18 . V_21 = F_12 ;
V_23 -> V_16 = V_16 [ V_29 ] + 3 ;
V_23 -> V_26 = 0x0 ;
F_22 ( & V_23 -> V_25 ) ;
V_31 -> V_2 = V_2 ;
V_31 -> V_18 = & V_23 -> V_18 ;
F_23 ( V_28 , V_31 ) ;
V_32 = F_24 ( & V_23 -> V_18 , V_23 ) ;
if ( V_32 ) {
F_21 ( V_28 , L_2 , V_32 ) ;
return V_32 ;
}
V_32 = F_25 ( V_2 ) ;
if ( V_32 ) {
F_21 ( V_28 , L_3 , V_32 ) ;
F_26 ( & V_23 -> V_18 ) ;
return V_32 ;
}
return 0 ;
}
static int F_27 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_30 * const V_31 = F_28 ( V_28 ) ;
F_29 ( V_31 -> V_2 ) ;
F_26 ( V_31 -> V_18 ) ;
return 0 ;
}
