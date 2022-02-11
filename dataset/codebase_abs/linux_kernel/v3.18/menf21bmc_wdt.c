static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 == 0x02 )
V_2 -> V_6 . V_7 |= V_8 ;
else if ( V_3 == 0x05 )
V_2 -> V_6 . V_7 |= V_9 ;
else if ( V_3 == 0x06 )
V_2 -> V_6 . V_7 |= V_10 ;
else if ( V_3 == 0x0A )
V_2 -> V_6 . V_7 |= V_11 ;
return 0 ;
}
static int F_3 ( struct V_12 * V_6 )
{
struct V_1 * V_13 = F_4 ( V_6 ) ;
return F_5 ( V_13 -> V_4 , V_14 ) ;
}
static int F_6 ( struct V_12 * V_6 )
{
struct V_1 * V_13 = F_4 ( V_6 ) ;
return F_7 ( V_13 -> V_4 ,
V_15 , V_16 ) ;
}
static int
F_8 ( struct V_12 * V_6 , unsigned int V_17 )
{
int V_18 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
V_18 = F_9 ( V_13 -> V_4 ,
V_19 , V_17 * 10 ) ;
if ( V_18 < 0 )
return V_18 ;
V_6 -> V_17 = V_17 ;
return 0 ;
}
static int F_10 ( struct V_12 * V_6 )
{
struct V_1 * V_13 = F_4 ( V_6 ) ;
return F_5 ( V_13 -> V_4 , V_20 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
int V_18 , V_23 ;
struct V_1 * V_13 ;
struct V_4 * V_4 = F_12 ( V_22 -> V_24 . V_25 ) ;
V_13 = F_13 ( & V_22 -> V_24 ,
sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_13 )
return - V_27 ;
V_13 -> V_6 . V_28 = & V_29 ;
V_13 -> V_6 . V_30 = & V_31 ;
V_13 -> V_6 . V_32 = V_33 ;
V_13 -> V_6 . V_34 = V_35 ;
V_13 -> V_4 = V_4 ;
V_23 = F_14 ( V_13 -> V_4 ,
V_19 ) ;
if ( V_23 < 0 ) {
F_15 ( & V_22 -> V_24 , L_1 ) ;
return V_23 ;
}
F_16 ( & V_13 -> V_6 , V_23 / 10 , & V_22 -> V_24 ) ;
F_17 ( & V_13 -> V_6 , V_36 ) ;
F_18 ( & V_13 -> V_6 , V_13 ) ;
F_19 ( V_22 , V_13 ) ;
V_18 = F_1 ( V_13 ) ;
if ( V_18 < 0 ) {
F_15 ( & V_22 -> V_24 , L_2 ) ;
return V_18 ;
}
V_18 = F_20 ( & V_13 -> V_6 ) ;
if ( V_18 ) {
F_15 ( & V_22 -> V_24 , L_3 ) ;
return V_18 ;
}
F_21 ( & V_22 -> V_24 , L_4 ) ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 )
{
struct V_1 * V_13 = F_23 ( V_22 ) ;
F_24 ( & V_22 -> V_24 ,
L_5 ) ;
F_25 ( & V_13 -> V_6 ) ;
return 0 ;
}
static void F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_13 = F_23 ( V_22 ) ;
F_9 ( V_13 -> V_4 ,
V_15 , V_16 ) ;
}
